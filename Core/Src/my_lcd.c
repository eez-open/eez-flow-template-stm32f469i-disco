#include "my_lcd.h"

#include "stm32469i_discovery_lcd.h"
#include "stm32469i_discovery_sdram.h"

#include "image_320x240_argb8888.h"
#include "life_augmented_argb8888.h"

extern LTDC_HandleTypeDef hltdc_eval;
extern DMA2D_HandleTypeDef hdma2d_eval;

#define LAYER0_ADDRESS               (LCD_FB_START_ADDRESS)

static int32_t  front_buffer   = 0;
static int32_t  pend_buffer   = -1;
static uint32_t ImageIndex    = 0;

static const uint32_t * Images[] =
{
  image_320x240_argb8888,
  life_augmented_argb8888,
};

static const uint32_t Buffers[] =
{
  LAYER0_ADDRESS,
  LAYER0_ADDRESS + (800*480*2),
};

static void OnError_Handler(uint32_t condition);
static void LCD_BriefDisplay(void);
static void CopyBuffer(uint32_t *pSrc, uint32_t *pDst, uint16_t x, uint16_t y, uint16_t xsize, uint16_t ysize);
static void CopyImage(uint32_t *pSrc, uint32_t *pDst, uint16_t x, uint16_t y, uint16_t xsize, uint16_t ysize);

void MY_LCD_Init() {
  uint8_t  lcd_status = LCD_OK;

  lcd_status = BSP_LCD_Init();
  OnError_Handler(lcd_status != LCD_OK);

  BSP_LCD_LayerDefaultInit(0, LAYER0_ADDRESS);
  BSP_LCD_SelectLayer(0);

  /* Set LTDC Line Event  */
  HAL_LTDC_ProgramLineEvent(&hltdc_eval, 0);

  /* Display example brief   */
  LCD_BriefDisplay();

  /* Copy Buffer 0 into buffer 1, so only image area to be redrawn later */
  CopyBuffer((uint32_t *)Buffers[0], (uint32_t *)Buffers[1], 0, 0, 800, 480);
}

void MY_LCD_Tick() {
	if(pend_buffer < 0)
	{
	  /* Prepare back buffer */
	  CopyImage((uint32_t *)Images[ImageIndex++], (uint32_t *)Buffers[1- front_buffer], 240, 160, 320, 240);
	  pend_buffer = 1- front_buffer;

	  if(ImageIndex >= 2)
	  {
		ImageIndex = 0;
	  }

	  /* Wait some time before switching to next stage */
	  HAL_Delay(2000);
	}
}

/**
  * @brief  On Error Handler on condition TRUE.
  * @param  condition : Can be TRUE or FALSE
  * @retval None
  */
static void OnError_Handler(uint32_t condition)
{
  if(condition)
  {
    BSP_LED_On(LED3);
    while(1) { ; } /* Blocking on error */
  }
}

/**
  * @brief  Line Event callback.
  * @param  hltdc: pointer to a LTDC_HandleTypeDef structure that contains
  *                the configuration information for the LTDC.
  * @retval None
  */
void HAL_LTDC_LineEventCallback1(LTDC_HandleTypeDef *hltdc)
{
  if(pend_buffer >= 0)
  {
    LTDC_LAYER(hltdc, 0)->CFBAR = ((uint32_t)Buffers[pend_buffer]);
    __HAL_LTDC_RELOAD_IMMEDIATE_CONFIG(hltdc);

    front_buffer = pend_buffer;
    pend_buffer = -1;
  }

  HAL_LTDC_ProgramLineEvent(hltdc, 0);
}

/**
  * @brief  Display Example description.
  * @param  None
  * @retval None
  */
static void LCD_BriefDisplay(void)
{
  BSP_LCD_Clear(LCD_COLOR_WHITE);
  BSP_LCD_SetBackColor(LCD_COLOR_RED);
  BSP_LCD_SetTextColor(LCD_COLOR_RED);
  BSP_LCD_FillRect(0, 0, 800, 112);

  BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
  BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
  BSP_LCD_FillRect(0, 112, 800, 112);

  BSP_LCD_SetBackColor(LCD_COLOR_GREEN);
  BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
  BSP_LCD_FillRect(0, 224, 800, 112);

  BSP_LCD_SetBackColor(LCD_COLOR_CYAN);
  BSP_LCD_SetTextColor(LCD_COLOR_CYAN);
  BSP_LCD_FillRect(0, 336, 400, 144);

  BSP_LCD_SetBackColor(LCD_COLOR_MAGENTA);
  BSP_LCD_SetTextColor(LCD_COLOR_MAGENTA);
  BSP_LCD_FillRect(400, 336, 400, 144);

  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
  //BSP_LCD_DisplayStringAtLine(1, (uint8_t *)"        LCD_DSI_VideoMode_DoubleBuffering");
  BSP_LCD_SetFont(&Font16);
  //BSP_LCD_DisplayStringAtLine(4, (uint8_t *)"This example shows how to display images on LCD DSI using two buffers");
  //BSP_LCD_DisplayStringAtLine(5, (uint8_t *)"one for display and the other for draw     ");

}

/**
  * @brief  Converts a line to an ARGB8888 pixel format.
  * @param  pSrc: Pointer to source buffer
  * @param  pDst: Output color
  * @param  xSize: Buffer width
  * @param  ColorMode: Input color mode
  * @retval None
  */
static void CopyBuffer(uint32_t *pSrc, uint32_t *pDst, uint16_t x, uint16_t y, uint16_t xsize, uint16_t ysize)
{

  uint32_t destination = (uint32_t)pDst + (y * 800 + x) * 2;
  uint32_t source      = (uint32_t)pSrc;

  /*##-1- Configure the DMA2D Mode, Color Mode and output offset #############*/
  hdma2d_eval.Init.Mode         = DMA2D_M2M;
  hdma2d_eval.Init.ColorMode    = DMA2D_OUTPUT_RGB565;
  hdma2d_eval.Init.OutputOffset = 800 - xsize;

  /*##-2- DMA2D Callbacks Configuration ######################################*/
  hdma2d_eval.XferCpltCallback  = NULL;

  /*##-3- Foreground Configuration ###########################################*/
  hdma2d_eval.LayerCfg[1].AlphaMode = DMA2D_NO_MODIF_ALPHA;
  hdma2d_eval.LayerCfg[1].InputAlpha = 0xFF;
  hdma2d_eval.LayerCfg[1].InputColorMode = DMA2D_INPUT_RGB565;
  hdma2d_eval.LayerCfg[1].InputOffset = 0;

  hdma2d_eval.Instance          = DMA2D;

  /* DMA2D Initialization */
  if(HAL_DMA2D_Init(&hdma2d_eval) == HAL_OK)
  {
    if(HAL_DMA2D_ConfigLayer(&hdma2d_eval, 1) == HAL_OK)
    {
      if (HAL_DMA2D_Start(&hdma2d_eval, source, destination, xsize, ysize) == HAL_OK)
      {
        /* Polling For DMA transfer */
        HAL_DMA2D_PollForTransfer(&hdma2d_eval, 100);
      }
    }
  }
}

/**
  * @brief  Converts a line to an ARGB8888 pixel format.
  * @param  pSrc: Pointer to source buffer
  * @param  pDst: Output color
  * @param  xSize: Buffer width
  * @param  ColorMode: Input color mode
  * @retval None
  */
static void CopyImage(uint32_t *pSrc, uint32_t *pDst, uint16_t x, uint16_t y, uint16_t xsize, uint16_t ysize)
{
  uint32_t destination = ((uint32_t)pDst) + (y * 800 + x) * 2;
  uint32_t source      = (uint32_t)pSrc;

  /*##-1- Configure the DMA2D Mode, Color Mode and output offset #############*/
  hdma2d_eval.Init.Mode         = DMA2D_M2M_BLEND;
  hdma2d_eval.Init.ColorMode    = DMA2D_OUTPUT_RGB565;
  hdma2d_eval.Init.OutputOffset = 800 - xsize;

  /*##-2- DMA2D Callbacks Configuration ######################################*/
  hdma2d_eval.XferCpltCallback  = NULL;

  hdma2d_eval.LayerCfg[0].InputOffset = 800 - xsize;
  hdma2d_eval.LayerCfg[0].InputColorMode = DMA2D_INPUT_RGB565;
  hdma2d_eval.LayerCfg[0].AlphaMode = DMA2D_NO_MODIF_ALPHA;
  hdma2d_eval.LayerCfg[0].InputAlpha = 0;

  /*##-3- Foreground Configuration ###########################################*/
  hdma2d_eval.LayerCfg[1].AlphaMode = DMA2D_NO_MODIF_ALPHA;
  hdma2d_eval.LayerCfg[1].InputAlpha = 0xFF;
  hdma2d_eval.LayerCfg[1].InputColorMode = DMA2D_INPUT_ARGB8888;
  hdma2d_eval.LayerCfg[1].InputOffset = 0;

  hdma2d_eval.Instance = DMA2D;

  /* DMA2D Initialization */
  if(HAL_DMA2D_Init(&hdma2d_eval) == HAL_OK)
  {
    if(HAL_DMA2D_ConfigLayer(&hdma2d_eval, 1) == HAL_OK && HAL_DMA2D_ConfigLayer(&hdma2d_eval, 0) == HAL_OK)
    {
      if (HAL_DMA2D_BlendingStart(&hdma2d_eval, source, destination, destination, xsize, ysize) == HAL_OK)
      {
        /* Polling For DMA transfer */
        HAL_DMA2D_PollForTransfer(&hdma2d_eval, 100);
      }
    }
  }
}
