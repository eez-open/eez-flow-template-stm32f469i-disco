#ifdef EEZ_PLATFORM_STM32
#include "main.h"
#include "tim.h"
#include "stm32469i_discovery_lcd.h"
#include "stm32469i_discovery_sdram.h"
#include "stm32469i_discovery_ts.h"
#endif

#include "firmware.h"
#include "eez/conf-internal.h"
#include "eez/core/memory.h"

#define MAX_BRIGHTNESS 20

#ifdef EEZ_PLATFORM_STM32

extern LTDC_HandleTypeDef hltdc_eval;
extern DMA2D_HandleTypeDef hdma2d_eval;

static void OnError_Handler(uint32_t condition);

/**
  * @brief  On Error Handler on condition TRUE.
  * @param  condition : Can be TRUE or FALSE
  * @retval None
  */
static void OnError_Handler(uint32_t condition) {
	if(condition) {
		BSP_LED_On(LED3);
		while(1) { ; } /* Blocking on error */
	}
}

#endif

void LCD_init() {
#ifdef EEZ_PLATFORM_STM32
	uint8_t  lcd_status = LCD_OK;

	lcd_status = BSP_LCD_Init();
	OnError_Handler(lcd_status != LCD_OK);

	BSP_LCD_LayerDefaultInit(0, (uint32_t)eez::VRAM_BUFFER1_START_ADDRESS);
	BSP_LCD_SelectLayer(0);

  	BSP_LCD_Clear(LCD_COLOR_BLACK);

	BSP_TS_Init(DISPLAY_WIDTH, DISPLAY_HEIGHT);
#endif

	updateBrightness();
}

void updateBrightness() {
#ifdef EEZ_PLATFORM_STM32
//	auto brightness = g_lcdBrightness;
//
//	auto phtim = &htim2;
//
//	HAL_TIM_PWM_Start(phtim, TIM_CHANNEL_1);
//	uint32_t max = __HAL_TIM_GET_AUTORELOAD(phtim);
//	__HAL_TIM_SET_COMPARE(phtim, TIM_CHANNEL_1, brightness * max / MAX_BRIGHTNESS);
#endif // EEZ_PLATFORM_STM32
}
