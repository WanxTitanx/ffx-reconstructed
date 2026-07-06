#pragma once
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

typedef struct FFXInputState {
    int keys[256];
    int keysPressed[256];
} FFXInputState;

void FFX_Input_Init(FFXInputState *state);
void FFX_Input_Poll(FFXInputState *state);
int FFX_Input_IsKeyDown(FFXInputState *state, int key);
int FFX_Input_WasKeyPressed(FFXInputState *state, int key);
