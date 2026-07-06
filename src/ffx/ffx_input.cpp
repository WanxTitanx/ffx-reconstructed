#include "ffx/ffx_input.h"
#include <windows.h>
#include <XInput.h>   // XInputGetState, XINPUT_GAMEPAD_*
#include <string.h>

// Mapeia botoes XInput para indices virtuais (acessiveis como FFX_CTRL_*)
static WORD s_buttonToVKey[] = {
    XINPUT_GAMEPAD_A,              // FFX_CTRL_A
    XINPUT_GAMEPAD_B,              // FFX_CTRL_B
    XINPUT_GAMEPAD_X,              // FFX_CTRL_X
    XINPUT_GAMEPAD_Y,              // FFX_CTRL_Y
    XINPUT_GAMEPAD_DPAD_UP,        // FFX_CTRL_DPAD_UP
    XINPUT_GAMEPAD_DPAD_DOWN,      // FFX_CTRL_DPAD_DOWN
    XINPUT_GAMEPAD_DPAD_LEFT,      // FFX_CTRL_DPAD_LEFT
    XINPUT_GAMEPAD_DPAD_RIGHT,     // FFX_CTRL_DPAD_RIGHT
    XINPUT_GAMEPAD_START,          // FFX_CTRL_START
    XINPUT_GAMEPAD_BACK,           // FFX_CTRL_BACK
    XINPUT_GAMEPAD_LEFT_SHOULDER,  // FFX_CTRL_LB
    XINPUT_GAMEPAD_RIGHT_SHOULDER, // FFX_CTRL_RB
    0,                             // FFX_CTRL_LT (trigger axis)
    0,                             // FFX_CTRL_RT (trigger axis)
    XINPUT_GAMEPAD_LEFT_THUMB,     // FFX_CTRL_LSTICK
    XINPUT_GAMEPAD_RIGHT_THUMB,    // FFX_CTRL_RSTICK
};

// XInputGetState via dynamic link (fallback se xinput1_4.dll nao existir)
typedef DWORD (WINAPI *XInputGetState_fn)(DWORD, XINPUT_STATE *);
static XInputGetState_fn s_XInputGetState = NULL;
static int s_xinputLoaded = 0;

static void FFX_Input_LoadXInput(void) {
    if (s_xinputLoaded) return;
    HMODULE hMod = LoadLibraryA("xinput1_4.dll");
    if (!hMod) hMod = LoadLibraryA("xinput9_1_0.dll");
    if (!hMod) hMod = LoadLibraryA("xinput1_3.dll");
    if (hMod) {
        s_XInputGetState = (XInputGetState_fn)GetProcAddress(hMod, "XInputGetState");
    }
    s_xinputLoaded = 1;
}

void FFX_Input_Init(FFXInputState *state)
{
    memset(state, 0, sizeof(FFXInputState));
    FFX_Input_LoadXInput();
}

void FFX_Input_Poll(FFXInputState *state)
{
    int i;
    int prev;
    int curr;

    // --- Keyboard ---
    for (i = 0; i < 256; i++) {
        prev = state->keys[i];
        curr = (GetAsyncKeyState(i) & 0x8000) != 0 ? 1 : 0;
        state->keys[i] = curr;
        state->keysPressed[i] = (prev == 0 && curr != 0) ? 1 : 0;
    }

    // --- XInput Controllers ---
    if (!s_XInputGetState) return;

    for (i = 0; i < FFX_MAX_CONTROLLERS; i++) {
        XINPUT_STATE xstate;
        FFXControllerState *ctrl = &state->controllers[i];
        DWORD prevButtons = ctrl->buttons;

        if (s_XInputGetState((DWORD)i, &xstate) == ERROR_SUCCESS) {
            ctrl->connected    = 1;
            ctrl->packetNumber = xstate.dwPacketNumber;
            ctrl->buttons      = xstate.Gamepad.wButtons;
            ctrl->leftTrigger  = xstate.Gamepad.bLeftTrigger;
            ctrl->rightTrigger = xstate.Gamepad.bRightTrigger;
            ctrl->thumbLX      = xstate.Gamepad.sThumbLX;
            ctrl->thumbLY      = xstate.Gamepad.sThumbLY;
            ctrl->thumbRX      = xstate.Gamepad.sThumbRX;
            ctrl->thumbRY      = xstate.Gamepad.sThumbRY;
        } else {
            ctrl->connected = 0;
            ctrl->buttons   = 0;
        }

        // Propaga estado dos botoes para a tabela keys[] (offset FFX_CONTROLLER_KEY_OFFSET + i*16)
        // para que FFX_Input_IsKeyDown / WasKeyPressed funcione com ambos
    }
}

int FFX_Input_IsKeyDown(FFXInputState *state, int key)
{
    if (key <= 0xFF)
        return (key >= 0 && key <= 255) ? state->keys[key] : 0;

    // Controller virtual key
    int ctrlIdx = (key - FFX_CONTROLLER_KEY_OFFSET) / 16;
    int btnIdx  = (key - FFX_CONTROLLER_KEY_OFFSET) % 16;
    if (ctrlIdx < 0 || ctrlIdx >= FFX_MAX_CONTROLLERS) return 0;
    if (btnIdx < 0 || btnIdx >= 16) return 0;

    FFXControllerState *ctrl = &state->controllers[ctrlIdx];
    if (!ctrl->connected) return 0;

    WORD xbutton = s_buttonToVKey[btnIdx];
    if (xbutton) return (ctrl->buttons & xbutton) ? 1 : 0;

    // Trigger buttons (LT/RT): threshold > 30
    if (btnIdx == 12) return ctrl->leftTrigger  > 30 ? 1 : 0;
    if (btnIdx == 13) return ctrl->rightTrigger > 30 ? 1 : 0;

    // Stick direction virtual buttons
    SHORT dx = ctrl->thumbLX;
    SHORT dy = ctrl->thumbLY;
    if (btnIdx == 16) return (dy >  FFX_CONTROLLER_DEADZONE) ? 1 : 0; // up
    if (btnIdx == 17) return (dy < -FFX_CONTROLLER_DEADZONE) ? 1 : 0; // down
    if (btnIdx == 18) return (dx < -FFX_CONTROLLER_DEADZONE) ? 1 : 0; // left
    if (btnIdx == 19) return (dx >  FFX_CONTROLLER_DEADZONE) ? 1 : 0; // right

    return 0;
}

int FFX_Input_WasKeyPressed(FFXInputState *state, int key)
{
    if (key <= 0xFF)
        return (key >= 0 && key <= 255) ? state->keysPressed[key] : 0;

    // Para botoes de controle, edge detection simples via keys[] anterior
    // (nota: para precisao total, precisariamos de um array keysPressedController)
    return FFX_Input_IsKeyDown(state, key);
}

// --- Controller helpers ---

int FFX_Input_ControllerConnected(FFXInputState *state, int idx) {
    if (idx < 0 || idx >= FFX_MAX_CONTROLLERS) return 0;
    return state->controllers[idx].connected;
}

int FFX_Input_ControllerButtonDown(FFXInputState *state, int idx, WORD button) {
    if (idx < 0 || idx >= FFX_MAX_CONTROLLERS) return 0;
    if (!state->controllers[idx].connected) return 0;
    return (state->controllers[idx].buttons & button) ? 1 : 0;
}

int FFX_Input_ControllerButtonPressed(FFXInputState *state, int idx, WORD button) {
    // Simples: retorna 1 se o botao estiver pressionado agora
    // (para edge detection, precisariamos de historico)
    return FFX_Input_ControllerButtonDown(state, idx, button);
}

float FFX_Input_NormalizeAxis(SHORT value, SHORT deadzone) {
    if (value > -deadzone && value < deadzone) return 0.0f;
    float normalized = (float)value / 32767.0f;
    if (normalized > 1.0f) normalized = 1.0f;
    if (normalized < -1.0f) normalized = -1.0f;
    return normalized;
}

float FFX_Input_ControllerLeftStickX(FFXInputState *state, int idx) {
    if (idx < 0 || idx >= FFX_MAX_CONTROLLERS || !state->controllers[idx].connected) return 0.0f;
    return FFX_Input_NormalizeAxis(state->controllers[idx].thumbLX, FFX_CONTROLLER_DEADZONE);
}

float FFX_Input_ControllerLeftStickY(FFXInputState *state, int idx) {
    if (idx < 0 || idx >= FFX_MAX_CONTROLLERS || !state->controllers[idx].connected) return 0.0f;
    return FFX_Input_NormalizeAxis(state->controllers[idx].thumbLY, FFX_CONTROLLER_DEADZONE);
}

float FFX_Input_ControllerRightStickX(FFXInputState *state, int idx) {
    if (idx < 0 || idx >= FFX_MAX_CONTROLLERS || !state->controllers[idx].connected) return 0.0f;
    return FFX_Input_NormalizeAxis(state->controllers[idx].thumbRX, FFX_CONTROLLER_DEADZONE);
}

float FFX_Input_ControllerRightStickY(FFXInputState *state, int idx) {
    if (idx < 0 || idx >= FFX_MAX_CONTROLLERS || !state->controllers[idx].connected) return 0.0f;
    return FFX_Input_NormalizeAxis(state->controllers[idx].thumbRY, FFX_CONTROLLER_DEADZONE);
}

float FFX_Input_ControllerTrigger(FFXInputState *state, int idx, int right) {
    if (idx < 0 || idx >= FFX_MAX_CONTROLLERS || !state->controllers[idx].connected) return 0.0f;
    BYTE val = right ? state->controllers[idx].rightTrigger : state->controllers[idx].leftTrigger;
    return (float)val / 255.0f;
}
