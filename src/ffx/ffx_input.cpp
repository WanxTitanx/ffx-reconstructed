#include "ffx/ffx_input.h"
#include <windows.h>
#include <string.h>

void FFX_Input_Init(FFXInputState *state)
{
    memset(state, 0, sizeof(FFXInputState));
}

void FFX_Input_Poll(FFXInputState *state)
{
    int i;
    int prev;
    int curr;

    for (i = 0; i < 256; i++) {
        prev = state->keys[i];
        curr = (GetAsyncKeyState(i) & 0x8000) != 0 ? 1 : 0;
        state->keys[i] = curr;
        state->keysPressed[i] = (prev == 0 && curr != 0) ? 1 : 0;
    }
}

int FFX_Input_IsKeyDown(FFXInputState *state, int key)
{
    if (key < 0 || key > 255)
        return 0;
    return state->keys[key];
}

int FFX_Input_WasKeyPressed(FFXInputState *state, int key)
{
    if (key < 0 || key > 255)
        return 0;
    return state->keysPressed[key];
}
