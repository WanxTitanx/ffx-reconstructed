#pragma once
#include <windows.h>
#include <XInput.h>

#define FFX_KEY_ESC 0x1B
#define FFX_KEY_UP 0x26
#define FFX_KEY_DOWN 0x28
#define FFX_KEY_LEFT 0x25
#define FFX_KEY_RIGHT 0x27
#define FFX_KEY_RETURN 0x0D
#define FFX_KEY_SPACE 0x20
#define FFX_KEY_F (0x46)
#define FFX_KEY_1 (0x31)
#define FFX_KEY_2 (0x32)

#define FFX_MAX_CONTROLLERS 4
#define FFX_CONTROLLER_DEADZONE 7849  // typical XInput left-stick deadzone

// Mapeia botoes de controle para constantes (acessiveis como "teclas virtuais")
#define FFX_CONTROLLER_KEY_OFFSET 0x1000
#define FFX_CTRL_A         (FFX_CONTROLLER_KEY_OFFSET + 0)
#define FFX_CTRL_B         (FFX_CONTROLLER_KEY_OFFSET + 1)
#define FFX_CTRL_X         (FFX_CONTROLLER_KEY_OFFSET + 2)
#define FFX_CTRL_Y         (FFX_CONTROLLER_KEY_OFFSET + 3)
#define FFX_CTRL_DPAD_UP   (FFX_CONTROLLER_KEY_OFFSET + 4)
#define FFX_CTRL_DPAD_DOWN (FFX_CONTROLLER_KEY_OFFSET + 5)
#define FFX_CTRL_DPAD_LEFT (FFX_CONTROLLER_KEY_OFFSET + 6)
#define FFX_CTRL_DPAD_RIGHT (FFX_CONTROLLER_KEY_OFFSET + 7)
#define FFX_CTRL_START     (FFX_CONTROLLER_KEY_OFFSET + 8)
#define FFX_CTRL_BACK      (FFX_CONTROLLER_KEY_OFFSET + 9)
#define FFX_CTRL_LB        (FFX_CONTROLLER_KEY_OFFSET + 10)
#define FFX_CTRL_RB        (FFX_CONTROLLER_KEY_OFFSET + 11)
#define FFX_CTRL_LT        (FFX_CONTROLLER_KEY_OFFSET + 12)
#define FFX_CTRL_RT        (FFX_CONTROLLER_KEY_OFFSET + 13)
#define FFX_CTRL_LSTICK    (FFX_CONTROLLER_KEY_OFFSET + 14)
#define FFX_CTRL_RSTICK    (FFX_CONTROLLER_KEY_OFFSET + 15)
#define FFX_CTRL_LSTICK_UP    (FFX_CONTROLLER_KEY_OFFSET + 16)
#define FFX_CTRL_LSTICK_DOWN  (FFX_CONTROLLER_KEY_OFFSET + 17)
#define FFX_CTRL_LSTICK_LEFT  (FFX_CONTROLLER_KEY_OFFSET + 18)
#define FFX_CTRL_LSTICK_RIGHT (FFX_CONTROLLER_KEY_OFFSET + 19)

typedef struct FFXControllerState {
    DWORD packetNumber;
    WORD  buttons;
    BYTE  leftTrigger;
    BYTE  rightTrigger;
    SHORT thumbLX;
    SHORT thumbLY;
    SHORT thumbRX;
    SHORT thumbRY;
    int   connected;  // 1 = controller presente
} FFXControllerState;

typedef struct FFXInputState {
    int keys[256];
    int keysPressed[256];
    FFXControllerState controllers[FFX_MAX_CONTROLLERS];
} FFXInputState;

void FFX_Input_Init(FFXInputState *state);
void FFX_Input_Poll(FFXInputState *state);
int  FFX_Input_IsKeyDown(FFXInputState *state, int key);
int  FFX_Input_WasKeyPressed(FFXInputState *state, int key);

// Controller-specific helpers
int  FFX_Input_ControllerConnected(FFXInputState *state, int idx);
int  FFX_Input_ControllerButtonDown(FFXInputState *state, int idx, WORD button);
int  FFX_Input_ControllerButtonPressed(FFXInputState *state, int idx, WORD button);
float FFX_Input_ControllerLeftStickX(FFXInputState *state, int idx);
float FFX_Input_ControllerLeftStickY(FFXInputState *state, int idx);
float FFX_Input_ControllerRightStickX(FFXInputState *state, int idx);
float FFX_Input_ControllerRightStickY(FFXInputState *state, int idx);
float FFX_Input_ControllerTrigger(FFXInputState *state, int idx, int right);
