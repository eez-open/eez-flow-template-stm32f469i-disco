var statusElement = document.getElementById("status");
var progressElement = document.getElementById("progress");
var spinnerElement = document.getElementById("spinner");

var stdinBuffer = [];

var terminal = $("#output").terminal(
  function(command) {
    // send command characters one by one, with 10ms interval, otherwise it will block for unknown reason
    const sendChar = () => {
      if (i < command.length) {
        stdinBuffer.push(command.charCodeAt(i));
        i++;
        setTimeout(sendChar, 10); // 10ms
      } else {
        stdinBuffer.push(13);
      }
    }
    let i = 0;
    sendChar();
  },
  {
    greetings: "",
    name: "js_demo",
    prompt: "[[;yellow;]> ]"
  }
);

var Module = {
  preRun: [
    function() {
      var lastCh = null;

      function stdin() {
        var ch = stdinBuffer.shift();
        if (ch !== undefined) {
          lastCh = ch;
        } else {
          // if no input then send 0, null, 0, null, ... to trick emscripten,
          // otherwise it will stop calling this function
          lastCh = lastCh === null ? 0 : null;
        }
        return lastCh;
      }

      FS.init(stdin);
    }
  ],

  postRun: [],

  onRuntimeInitialized: function () {
    console.log("onRuntimeInitialized");
    Module._init();
    Module._startFlow();

    const canvas = document.getElementById("canvas");
    const ctx = canvas.getContext("2d");

    const displayWidth = canvas.width;
    const displayHeight = canvas.height;

    let wheelDeltaY = 0;
    let wheelClicked = 0;
    let pointerEvents = [];

    const tick = () => {
      if (!Module._mainLoop()) {
        // flow is stopped
        return;
      }

      if (pointerEvents.length > 0) {
        for (let i = 0; i < pointerEvents.length; i++) {
            const pointerEvent = pointerEvents[i];
            Module._onPointerEvent(pointerEvent.x, pointerEvent.y, pointerEvent.pressed);
        }
        pointerEvents = [];
      }

      if (wheelDeltaY != 0 || wheelClicked != 0) {
          Modulentime._onMouseWheelEvent(wheelDeltaY, wheelClicked);
          wheelDeltaY = 0;
          wheelClicked = 0;
      }
  
      var buf_addr = Module._getSyncedBuffer();
      if (buf_addr != 0) {
          const screen = new Uint8ClampedArray(Module.HEAPU8.subarray(buf_addr, buf_addr + displayWidth * displayHeight *4));
          var imgData = new ImageData(screen, displayWidth, displayHeight);
          ctx.putImageData(imgData, 0, 0, 0, 0, canvas.width, canvas.height);
      }

      window.requestAnimationFrame(tick);
    };

    window.requestAnimationFrame(tick);

    function sendPointerEvent(event) {
      var bbox = canvas.getBoundingClientRect();
      const x = (event.clientX - bbox.left) * (canvas.width / bbox.width);
      const y = (event.clientY - bbox.top) * (canvas.height / bbox.height);
      const pressed = event.buttons == 1 ? 1 : 0;
      pointerEvents.push({ x, y, pressed });
      event.preventDefault();
      event.stopPropagation();
    }

    canvas.addEventListener("pointerdown", event => {
        if (event.buttons == 4) {
            wasmRuntime.wheelClicked = 1;
        }
        canvas.setPointerCapture(event.pointerId);
        sendPointerEvent(event);
    }, true);

    canvas.addEventListener("pointermove",event => {
      sendPointerEvent(event);
    }, true);

    canvas.addEventListener("pointerup",event => {
      canvas.releasePointerCapture(event.pointerId);
      sendPointerEvent(event);
    }, true);

    canvas.addEventListener("pointercancel",event => {
        canvas.releasePointerCapture(event.pointerId);
        sendPointerEvent(event);
    }, true);

    document.addEventListener("wheel", event => {
      wheelDeltaY += -event.deltaY;
    }, true);    
  },

  print: function(text) {
    if (arguments.length > 1) {
      text = Array.prototype.slice.call(arguments).join(" ");
    }

    console.log(text);

    if (text.startsWith("**ERROR")) {
      terminal.error(text);
    } else {
      terminal.echo(text);
    }
  },

  printErr: function(text) {
    if (arguments.length > 1) {
      text = Array.prototype.slice.call(arguments).join(" ");
    }
    console.error(text);
  },

  setStatus: function(text) {
    if (!Module.setStatus.last)
      Module.setStatus.last = { time: Date.now(), text: "" };
    if (text === Module.setStatus.last.text) return;
    var m = text.match(/([^(]+)\((\d+(\.\d+)?)\/(\d+)\)/);
    var now = Date.now();
    if (m && now - Module.setStatus.last.time < 30) return; // if this is a progress update, skip it if too soon
    Module.setStatus.last.time = now;
    Module.setStatus.last.text = text;
    if (m) {
      text = m[1];
      progressElement.value = parseInt(m[2]) * 100;
      progressElement.max = parseInt(m[4]) * 100;
      progressElement.hidden = false;
      spinnerElement.hidden = false;
    } else {
      progressElement.value = null;
      progressElement.max = null;
      progressElement.hidden = true;
      if (!text) spinnerElement.style.display = "none";
    }
    statusElement.innerHTML = text;
  },

  totalDependencies: 0,

  monitorRunDependencies: function(left) {
    this.totalDependencies = Math.max(this.totalDependencies, left);
    Module.setStatus(
      left
        ? "Preparing... (" +
          (this.totalDependencies - left) +
          "/" +
          this.totalDependencies +
          ")"
        : "All downloads complete."
    );
  }
};

Module.setStatus("Downloading...");

window.onerror = function(event) {
  // TODO: do not warn on ok events like simulating an infinite loop or exitStatus
  Module.setStatus("Exception thrown, see JavaScript console");
  spinnerElement.style.display = "none";
  Module.setStatus = function(text) {
    if (text) Module.printErr("[post-exception status] " + text);
  };
};
