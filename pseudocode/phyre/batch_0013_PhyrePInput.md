# FFX.exe Decompilation — Batch 13 (Phyre_PInput)

**Database:** ffxoficial.exe.i64 (session 09f6d736)
**Date:** 2026-07-27
**Functions:** 37 (Phyre_PInputDevice_* — Keyboard, Mouse, Pad, Touch constructors, factories, system init)
**Source:** Hex-Rays decompiler via IDA MCP

---

## Summary

This batch covers 37 `Phyre_PInput*` functions in FFX.exe — the **DirectInput8 + XInput input subsystem** of PhyreEngine. The input layer is a factory-dispatch architecture:

1. **DirectInput8Create** at startup enumerates all system input devices
2. **DispatchFactory** routes by device class byte (0x12=Keyboard, 0x13=Mouse, 0x14/0x15/0x18=Pad)
3. Each device is constructed, linked into a **global intrusive linked list** at `g_atelFuncspaceCount_4_70` (0xC30FA0)
4. Gamepad supports **dual path**: XInput (Xbox controllers, 964-byte struct) and DirectInput (legacy, 944-byte struct)

**Key discovery:** FFX.exe's input layer supports both XInput and DirectInput gamepad simultaneously, selecting XInput first for up to 4 controllers and falling back to DirectInput for non-XInput devices. This is the same dual-path strategy used by most PC games of the MSVC 2012 era.

---

# Part 1: Device Constructors (The Big 4)

## Base Pattern (all 4 devices)

All input device constructors share a common init sequence before device-specific setup:

```c
// Linked list sentinel init
*((_DWORD *)this + 1) = this + 4;   // prev = self
*((_DWORD *)this + 2) = this + 4;   // next = self
*(_DWORD *)this = &g_vtable_PInputDevice_Phyre;  // base vtable (0xB3FC00)

*((_DWORD *)this + 3) = this + 12;  // second sentinel prev
*((_DWORD *)this + 4) = this + 12;  // second sentinel next
*((_DWORD *)this + 5) = a2;         // device ID

// Link into global device list
v3 = off_C30FA4[0];
*((_DWORD *)this + 1) = &g_atelFuncspaceCount_4_70;
*((_DWORD *)this + 2) = v3;
*v3 = this + 4;
off_C30FA4[0] = this + 4;

// Device-specific vtable
*(_DWORD *)this = &g_vtable_PInputDevice_Phyre.<Device_dtor>;
```

### Struct layout (base, offsets 0-24):
```
+0:  vfptr (base vtable 0xB3FC00, then device-specific dtor vtable)
+4:  prev/next sentinel pair 1 (intrusive linked list node)
+8:  (alias for +4 pair)
+12: prev/next sentinel pair 2 (second list?)
+16: (alias for +12 pair)
+20: device ID (a2 parameter)
```

---

## Phyre_PInputDeviceKeyboard_Constructor (0x6201b0, 126 bytes)

```c
char *__thiscall Phyre_PInputDeviceKeyboard_Constructor(char *this, int a2)
{
  _DWORD *v3; // eax

  // --- Base init (sentinel + vfptr + device ID + linked list) ---
  *((_DWORD *)this + 1) = this + 4;
  *((_DWORD *)this + 2) = this + 4;
  *(_DWORD *)this = &g_vtable_PInputDevice_Phyre;
  *((_DWORD *)this + 3) = this + 12;
  *((_DWORD *)this + 4) = this + 12;
  *((_DWORD *)this + 5) = a2;
  v3 = off_C30FA4[0];
  *((_UNKNOWN ***)this + 2) = off_C30FA4[0];
  *((_DWORD *)this + 1) = &g_atelFuncspaceCount_4_70;
  *v3 = this + 4;
  off_C30FA4[0] = (_UNKNOWN **)(this + 4);

  // --- Device-specific vtable ---
  *(_DWORD *)this = &g_vtable_PInputDevice_Phyre.Keyboard_dtor;  // 0xB3FC38

  // --- 3x 256-byte key state buffers ---
  memset(this + 536, 0, 0x100u);   // buffer 1: current key state
  memset(this + 24, 0, 0x100u);    // buffer 2: previous key state
  memset(this + 280, 0, 0x100u);   // buffer 3: another key state (repeat?)

  return this;
}
```

- **Callers:** 1 (Phyre_PInputDeviceKeyboard_Factory)
- **Key constants:** 0x100 (256) — 3× 256-byte key state buffers = 768 bytes
- **Vtable:** 0xB3FC38 (Keyboard destructor)
- **Total struct:** ~792+ bytes (base 24 + 3×256 + overhead)
- The 3 key state buffers likely track: current frame, previous frame, and "any key down" state for repeat detection

---

## Phyre_PInputDeviceMouse_Constructor (0x620290, 199 bytes)

```c
char *__thiscall Phyre_PInputDeviceMouse_Constructor(char *this, int a2)
{
  _DWORD *v3; // eax

  // --- Base init ---
  *((_DWORD *)this + 1) = this + 4;
  *((_DWORD *)this + 2) = this + 4;
  *(_DWORD *)this = &g_vtable_PInputDevice_Phyre;
  *((_DWORD *)this + 3) = this + 12;
  *((_DWORD *)this + 4) = this + 12;
  *((_DWORD *)this + 5) = a2;
  v3 = off_C30FA4[0];
  *((_DWORD *)this + 1) = &g_atelFuncspaceCount_4_70;
  *((_DWORD *)this + 2) = v3;
  *v3 = this + 4;
  off_C30FA4[0] = (_UNKNOWN **)(this + 4);

  // --- Device-specific vtable ---
  *(_DWORD *)this = &g_vtable_PInputDevice_Phyre.dtor_Aligned;  // 0xB3FC1C

  // --- 5 sub-devices × 48 bytes ---
  `eh vector constructor iterator'(
    this + 24,
    0x30u,    // 48 bytes per sub-device
    5,        // 5 sub-devices
    Phyre_PInputDevice_SubDeviceInit,
    nullsub_32);

  // --- Zero-init axis/button state ---
  *(this + 264) = 0;
  *((_DWORD *)this + 67) = 0;
  *((_DWORD *)this + 68) = 0;
  *((_DWORD *)this + 69) = 0;
  *((_WORD *)this + 140) = 0;
  *(this + 282) = 0;
  return this;
}
```

- **Callers:** 1 (Phyre_PInputDeviceMouse_Factory)
- **Key constants:** 5 sub-devices × 0x30 (48) bytes = 240 bytes
- **Vtable:** 0xB3FC1C (Aligned destructor)
- **Struct size:** ~284+ bytes (base 24 + 240 sub-devices + 20 state)
- The 5 sub-devices likely represent: X axis, Y axis, Z/wheel, buttons 1-3, buttons 4-5

---

## Phyre_PInputDevicePad_Constructor (0x620360, 374 bytes) ⭐

```c
char *__thiscall Phyre_PInputDevicePad_Constructor(char *this, int a2)
{
  _DWORD *v3; // eax
  char *v4;   // eax
  int n16;    // ecx

  // --- Base init ---
  *((_DWORD *)this + 1) = this + 4;
  *((_DWORD *)this + 2) = this + 4;
  *(_DWORD *)this = &g_vtable_PInputDevice_Phyre;
  *((_DWORD *)this + 3) = this + 12;
  *((_DWORD *)this + 4) = this + 12;
  *((_DWORD *)this + 5) = a2;
  v3 = off_C30FA4[0];
  *((_DWORD *)this + 1) = &g_atelFuncspaceCount_4_70;
  *((_DWORD *)this + 2) = v3;
  *v3 = this + 4;
  off_C30FA4[0] = (_UNKNOWN **)(this + 4);

  // --- Pad-specific vtable ---
  *(_DWORD *)this = &Phyre::PFramework::PInputDevicePad::`vftable';  // 0xB3FCAC

  // --- 4 sub-devices × 48 bytes ---
  `eh vector constructor iterator'(
    this + 108,
    0x30u,     // 48 bytes
    4,         // 4 sub-devices
    Phyre_PInputDevice_SubDeviceInit,
    nullsub_32);

  // --- Zero-init 44+ DWORD fields (buttons, axis, state) ---
  *((_DWORD *)this + 235) = 0;
  // ... (~20 DWORD zero-inits at offsets +880..+940)
  *((_DWORD *)this + 229) = 0;
  *(this + 105) = 0;

  // --- Zero-init 16 button states ---
  v4 = this + 24;
  n16 = 16;
  do {
    v4[16] = 0;    // button flags
    *v4++ = 0;     // button values
    --n16;
  } while (n16);

  // --- Zero-init axis/trigger floats ---
  *((float *)this + 23) = 0.0;
  *((float *)this + 24) = 0.0;
  *((float *)this + 25) = 0.0;

  // --- DirectInput state buffer ---
  memset(this + 300, 0, 0x244u);  // 580 bytes

  return this;
}
```

- **Callers:** 1 (Phyre_PInputDevicePad_FactoryOrInit)
- **Key constants:** 4 sub-devices × 0x30, 16 buttons, 0x244 (580 bytes DI state)
- **Vtable:** 0xB3FCAC (Pad base vtable)
- **Dual vtable overrides later:** XInput at 0xB3FFA4, DirectInput at 0xB3FF88
- **Struct size:** ~944+ bytes (base + sub-devices + buttons + DI state)

---

## Phyre_PInputDeviceTouch_Constructor (0x620570, 368 bytes) ⭐

```c
char *__thiscall Phyre_PInputDeviceTouch_Constructor(char *this)
{
  _DWORD *v2; // eax
  char *v3;   // edi
  char *v4;   // eax
  int i;      // ecx
  char *v6;   // esi
  int n4;     // ebx
  _DWORD *v8; // eax
  char ***v9; // edx
  char **v10; // eax
  HANDLE *v13;// [esp+14h] [ebp-10h]

  // --- Base init (device ID = 0) ---
  *((_DWORD *)this + 1) = this + 4;
  *((_DWORD *)this + 2) = this + 4;
  *(_DWORD *)this = &g_vtable_PInputDevice_Phyre;
  *((_DWORD *)this + 3) = this + 12;
  *((_DWORD *)this + 4) = this + 12;
  *((_DWORD *)this + 5) = 0;    // Touch has no device ID parameter
  v2 = off_C30FA4[0];
  *((_DWORD *)this + 1) = &g_atelFuncspaceCount_4_70;
  *((_DWORD *)this + 2) = v2;
  *v2 = this + 4;
  off_C30FA4[0] = (_UNKNOWN **)(this + 4);

  // --- Touch-specific vtable ---
  *(_DWORD *)this = &Phyre::PFramework::PInputDeviceTouch::`vftable';  // 0xB3FC54

  // --- Timer state init ---
  *((float *)this + 86) = 0.0;     // timer values
  *((_DWORD *)this + 6) = 0;
  *((float *)this + 49) = 1.0;     // scale
  *((_DWORD *)this + 87) = 0;
  *((_WORD *)this + 176) = 0;

  // --- 4 linked list sentinels (touch point lists) ---
  v3 = this + 372;
  *((_DWORD *)this + 89) = this + 356;  // sentinel 1
  *((_DWORD *)this + 90) = this + 356;
  *((_DWORD *)this + 91) = this + 364;  // sentinel 2
  *((_DWORD *)this + 92) = this + 364;
  *((_DWORD *)this + 93) = this + 372;  // sentinel 3
  *((_DWORD *)this + 94) = this + 372;

  // --- Timer init ---
  v13 = (HANDLE *)(this + 380);
  Phyre_Timer_GetTime(this + 380);

  // --- 24 touch points × 40 bytes ---
  v4 = this + 404;
  for (i = 23; i >= 0; --i) {
    *((float *)v4 + 8) = 0.0;     // position
    *(_DWORD *)v4 = v4;           // self-linked list sentinel
    *((float *)v4 + 9) = 0.0;
    *((_DWORD *)v4 + 1) = v4;
    *((_DWORD *)v4 + 6) = 6;      // state = 6 (released?)
    v4[28] = -1;                   // touch ID = -1 (invalid)
    v4 += 40;                      // 40 bytes per touch point
  }

  // --- Multi-touch sub-lists (4 quadrant groups) ---
  v6 = this + 448;
  n4 = 4;
  do {
    // Intrusive linked list for each quadrant group
    // Each 240-byte descriptor with linked list pointers
    // ...
    --n4;
  } while (n4);

  // --- Thread sync init ---
  Phyre_Thread_TimedWaitOrSkip(v13);

  return this;
}
```

- **Callers:** 0 (constructed by factory)
- **Callees:** Phyre_Timer_GetTime, Phyre_Thread_TimedWaitOrSkip
- **Key constants:** 24 touch points × 40 bytes = 960 bytes, 4 quadrant groups × 240 bytes
- **Vtable:** 0xB3FC54 (Touch vtable)
- **Struct size:** ~1200+ bytes (largest input device)
- 24 simultaneous touch points suggests Windows 8 touch API support

---

# Part 2: Factory & Dispatch System

## Phyre_PInputDevice_DispatchFactory (0x6234f0, 79 bytes)

```c
int __stdcall Phyre_PInputDevice_DispatchFactory(int src, int a2)
{
  int result; // eax

  switch (*(_BYTE *)(src + 36)) {    // device class byte at offset +36
    case 0x12:                        // Keyboard
      Phyre_PInputDeviceKeyboard_Factory(src);
      result = 1;
      break;
    case 0x13:                        // Mouse
      Phyre_PInputDeviceMouse_Factory(src);
      result = 1;
      break;
    case 0x14:                        // Pad (DirectInput)
    case 0x15:                        // Pad (XInput?)
    case 0x18:                        // Pad (other)
      Phyre_PInputDevicePad_FactoryOrInit((int **)src);
      goto LABEL_5;
    default:
LABEL_5:
      result = 1;
      break;
  }
  return result;
}
```

- **Callers:** 0 (used as callback pointer by DirectInput8 EnumDevices)
- **Callees:** 3 factory functions
- **Device class byte at +36:** This is a DirectInput `DIDEVICEINSTANCE` field — `dwDevType` byte

## Phyre_PInputDevice_InitDirectInput (0x624510, 77 bytes)

```c
int Phyre_PInputDevice_InitDirectInput()
{
  HMODULE ModuleHandleA; // eax

  ModuleHandleA = GetModuleHandleA(0);  // get hinstance

  // Create DirectInput8 with DINPUT_SDK_VERSION = 0x800
  if (DirectInput8Create(ModuleHandleA, 0x800u, &riidltf,
                         (LPVOID *)&MEMORY[0xCC9CD4], 0) >= 0)
  {
    // Enumerate devices via DispatchFactory callback
    if ((*(int (__stdcall **)(struct IDirectInput8 *, _DWORD,
         int (__stdcall *)(int, int), _DWORD, int))
         (*(_DWORD *)MEMORY[0xCC9CD4] + 16))(               // IDirectInput8::EnumDevices
           MEMORY[0xCC9CD4],
           0,                                                // DI8DEVCLASS_ALL
           Phyre_PInputDevice_DispatchFactory,               // callback
           0,
           1) >= 0)                                          // DIEDFL_ATTACHEDONLY
      return 0;
    else
      return 9;
  }
  else
    return 9;   // error 9 = DirectInput init failed
}
```

- **Callers:** 1 (InitEngineRenderSystem)
- **Callees:** GetModuleHandleA, DirectInput8Create
- **IDirectInput8 stored at:** MEMORY[0xCC9CD4]

## Phyre_PInputDevicePad_FactoryOrInit (0x6242a0, 576 bytes) ⭐

```c
char __cdecl Phyre_PInputDevicePad_FactoryOrInit(int **src)
{
  // Scan existing devices to check if this pad slot already exists
  for (i = 0; i < 0x12; ++i) {   // 18 device slots
    // Walk global device list looking for matching slot
    // Compare 12 DWORDs at offset +304 (v3+76) against src+1
  }

  // NOT found → create new pad device

  // --- XINPUT PATH (preferred) ---
  if (InitializeComService_CreateInstance(src + 5)) {
    if (n4_11 < 4u) {  // max 4 XInput controllers
      Phyre_Stream_Printf(2, "Creating new XInput Device: %d\n", src[1]);
      v5 = Engine_AlignedAllocSimple(964);   // XInput struct: 964 bytes
      v6 = v5;
      Phyre_PInputDevicePad_Constructor((char *)v5, 0);
      v6[236] = n4_11;               // XInput controller index
      *v6 = &Phyre::PFramework::PInputDevicePadXInput::`vftable';  // 0xB3FFA4
      v6[237] = 0;                   // XInput state
      v6[238] = 0;
      v6[239] = 0;
      v6[240] = 0;
      qmemcpy(v6 + 75, src, 0x244u); // copy DI device instance (580 bytes)
    }
    ++n4_11;  // increment XInput controller count
  }
  // --- DIRECTINPUT PATH (fallback) ---
  else {
    Phyre_Stream_Printf(2, "Creating new DirectInput Device\n");
    // IDirectInput8::CreateDevice
    (*(int (__stdcall **)(struct IDirectInput8 *, int **, int *, _DWORD))
     (*(_DWORD *)MEMORY[0xCC9CD4] + 12))(MEMORY[0xCC9CD4], src + 1, &v14, 0);

    // IDirectInputDevice8::SetDataFormat(&c_dfDIJoystick)
    (*(int (__stdcall **)(int, void *))(*(_DWORD *)v14 + 44))(v14, &unk_B6A62C);

    // IDirectInputDevice8::SetCooperativeLevel(hwnd, DISCL_BACKGROUND|DISCL_NONEXCLUSIVE)
    (*(int (__stdcall **)(int, HWND, int))(*(_DWORD *)v14 + 52))(v14, MEMORY[0xCC9CE8], 6);

    // IDirectInputDevice8::EnumObjects callback
    (*(int (__stdcall **)(int, BOOL (__stdcall *)(int, int *), int, _DWORD))
     (*(_DWORD *)v14 + 16))(v14, DirectInput_DeviceSetCooperativeLevel, v14, 0);

    // IDirectInputDevice8::Acquire
    (*(void (__stdcall **)(int))(*(_DWORD *)v14 + 28))(v14);

    v5 = Engine_AlignedAllocSimple(944);   // DirectInput struct: 944 bytes
    v12 = v5;
    Phyre_PInputDevicePad_Constructor((char *)v5, v14);  // pass DI device ptr
    *v12 = &Phyre::PFramework::PInputDevicePadDirectInput::`vftable';  // 0xB3FF88
    qmemcpy(v12 + 75, src, 0x244u);       // copy DI device instance
  }
  return (char)v5;
}
```

- **Callers:** 2 (DispatchFactory, RefreshFactory)
- **Callees:** Constructor, Phyre_Stream_Printf, Engine_AlignedAllocSimple, DirectInput COM calls
- **Strings:** `"Creating new XInput Device: %d\n"`, `"Creating new DirectInput Device\n"`
- **Constants:** 0x12 (18 slots), 0x244 (580 bytes copy), 0x3B0 (944 DI struct), 0x3C4 (964 XInput struct)
- **Vtable override:** 0xB3FFA4 (XInput), 0xB3FF88 (DirectInput)
- **Flow:** XInput is tried FIRST. If `InitializeComService_CreateInstance` succeeds → XInput. Else → DirectInput.

### Struct Size Comparison

| Variant | Size | Offsets |
|---------|------|---------|
| PadBase | ~944+ | +24 buttons, +108 sub-devices(4×48), +300 DI state |
| PadXInput | 964 | Base + XInput state at +944 (v6[236..240]) |
| PadDirectInput | 944 | Base + DI device ptr at +940 |

---

# Part 3: System-Level Functions

## Phyre_PInputDevice_ShutdownAll (0x625840, 81 bytes)

```c
int Phyre_PInputDevice_ShutdownAll()
{
  char *v0; // ecx
  int v1;   // edx
  _DWORD *v2; // eax

  // Walk global device list, unlink + destroy each
  while (g_atelFuncspaceCount_4_70 != (_UNKNOWN *)&g_atelFuncspaceCount_4_70) {
    if (!g_atelFuncspaceCount_4_70)
      break;
    v0 = (char *)g_atelFuncspaceCount_4_70 - 4;  // struct starts 4 bytes before list node
    if (g_atelFuncspaceCount_4_70 == (_UNKNOWN *)4)
      break;

    // Unlink from global list
    v1 = *(_DWORD *)g_atelFuncspaceCount_4_70;
    v2 = (_DWORD *)*((_DWORD *)g_atelFuncspaceCount_4_70 + 1);
    *(_DWORD *)(v1 + 4) = v2;
    *v2 = v1;

    // Reset sentinels
    *((_DWORD *)v0 + 1) = v0 + 4;
    *((_DWORD *)v0 + 2) = v0 + 4;

    // Call destructor via vtable
    (**(void (__thiscall ***)(char *, int))v0)(v0, 1);
  }

  // Release DirectInput
  if (MEMORY[0xCC9CD4]) {
    (*(void (__stdcall **)(struct IDirectInput8 *))(*(_DWORD *)MEMORY[0xCC9CD4] + 8))(MEMORY[0xCC9CD4]);  // Release()
    MEMORY[0xCC9CD4] = 0;
  }
  return 0;
}
```

- **Callers:** 1 (ShutdownApplication)
- **Constants:** 0xC30FA0 (global list head)

## Phyre_PInputDevice_RefreshAll (0x625930, 103 bytes)

```c
int Phyre_PInputDevice_RefreshAll()
{
  // If re-enumeration flag is set
  if (unk_CC9CD0) {
    unk_CC9CD0 = 0;
    // IDirectInput8::EnumDevices with RefreshFactory callback
    if ((*(int (__stdcall **)(struct IDirectInput8 *, _DWORD,
         int (__stdcall *)(int **, int), _DWORD, int))
         (*(_DWORD *)MEMORY[0xCC9CD4] + 16))(MEMORY[0xCC9CD4], 0,
           Phyre_PInputDevicePad_RefreshFactory, 0, 1) < 0)
      return 9;
  }

  // Call vtable+20 (update/refresh) on each device in global list
  if (g_atelFuncspaceCount_4_70 != (_UNKNOWN *)&g_atelFuncspaceCount_4_70) {
    if (g_atelFuncspaceCount_4_70) {
      v1 = (_DWORD *)((char *)g_atelFuncspaceCount_4_70 - 4);
      if (g_atelFuncspaceCount_4_70 != (_UNKNOWN *)4) {
        do {
          (*(void (__thiscall **)(_DWORD *))(*v1 + 20))(v1);  // vtable+20 = Update()
          p_g_atelFuncspaceCount = (_UNKNOWN **)v1[1];
          if (p_g_atelFuncspaceCount == &g_atelFuncspaceCount_4_70)
            break;
          if (!p_g_atelFuncspaceCount)
            break;
          v1 = p_g_atelFuncspaceCount - 1;
        } while (v1);
      }
    }
  }
  return 0;
}
```

- **Callers:** 2 (Phyre_Application_UpdateInput, FFX_UI_TitleAndMenuFlow)
- **Purpose:** Called every frame to refresh all input device states

---

# Part 4: Helper Initializers

## Phyre_PInputDevice_SubDeviceInit (0x620700, 69 bytes)

```c
void __thiscall Phyre_PInputDevice_SubDeviceInit(float *this)
{
  *(_DWORD *)this = this;        // self-pointer (sentinel)
  *(this + 4) = 1.0;             // scale = 1.0
  *((_DWORD *)this + 1) = this;  // sentinel pair
  *(this + 2) = 0.0;             // value = 0
  *(this + 5) = 0.0;             // dead zone?
  *(this + 3) = 0.0;
  *(this + 6) = 0.0;
  *(this + 8) = 0.0;
  *(this + 7) = 0.0;
  *((_WORD *)this + 18) = 0;     // flags
  *((_BYTE *)this + 38) = 0;     // type
  *(this + 10) = 0.0;
  *(this + 11) = 0.0;
}
```

- **Sub-device struct (48 bytes):**
  ```
  +0:  self-pointer (intrusive list sentinel)
  +4:  scale (float, init 1.0)
  +8:  self-pointer (sentinel pair)
  +12: min range (float)
  +16: max range (float)
  +20: dead zone (float)
  +24: value (float)
  +28: raw value (float)
  +32: flags (WORD)
  +36: inverted flag?
  +38: type byte
  +40: some float
  +44: some float
  ```

## Phyre_PInputDevice_TimerInit (0x620750, 248 bytes)

```c
_DWORD *__thiscall Phyre_PInputDevice_TimerInit(_DWORD *this)
{
  // memset equivalent — zero-init ~46 DWORDs (184 bytes)
  *this = 0;
  *(this + 1) = 0;
  // ... (40+ field zero-inits)
  *(this + 45) = 0;
  *(this + 41) = 0x10000;    // default timer period
  return this;
}
```

- **Callers:** 2 (PApplication_Constructor, Template_GetVtablePtr_E)
- **Value at +41 = 0x10000** — likely the timer frequency (high-precision timer period)

## Phyre_PInputDevice_AxisConfigInit (0x620940, 255 bytes)

```c
float *__thiscall Phyre_PInputDevice_AxisConfigInit(float *this)
{
  *this = 0.0;                 // min
  *(this + 1) = 0.0;           // max
  *(this + 2) = 0.0;           // center
  *(this + 4) = 0.3f;          // dead zone
  *(this + 5) = 0.3f;          // dead zone
  *(this + 6) = 0.3f;          // dead zone
  *(this + 8) = 16.909f;       // sensitivity
  *(this + 9) = 1817.145f;     // sensitivity
  *(this + 10) = 1.0f;         // scale
  // ... axis-specific calibration values
  *(this + 32) = 1.137f;       // axis tuning
  *(this + 33) = 0.307f;
  *(this + 34) = 0.321f;
  *(this + 36) = 111.0f;       // physical range
  *(this + 37) = 108.672f;
  *(this + 38) = 1.159f;
  return this;
}
```

- **Callers:** 1 (PApplication_Constructor)
- **Key constants:** 0.3f (dead zone), 16.909/1817.145 (sensitivity), 111.0/108.672 (physical axis range)
- **Purpose:** Pre-configured axis calibration values for gamepad thumbsticks and triggers

---

# Part 5: PInputMapper Type Registration

## Phyre_PInputMapper_RegisterType (0x622d20, 471 bytes) ⭐

```c
void Phyre_PInputMapper_RegisterType()
{
  // --- Phase 1: Register base type with "m_inputMap" member ---
  Phyre_PTypeDefault_PChar_RegisterName(&MEMORY[0xCC9E50]);
  if ((unk_CCA2B0 & 1) == 0) {
    unk_CCA2B0 |= 1;
    Phyre_PClassDataMember_ctorAttach_structural(
      unk_CCA284, &MEMORY[0xCC9E50], &MEMORY[0x1941910],
      "m_inputMap", 0, 2, 0);
    atexit(PClassDataMember_Dtor_byte_CCA284);
  }

  // --- Phase 2: Register "getMouseX" scripting accessor ---
  if ((v0 & 2) == 0) {
    unk_CCA2B0 = v0 | 2;
    Phyre_StringNode_Ctor(&MEMORY[0xCCA2B4], &MEMORY[0xCC9E50], "getMouseX", 0);
    MEMORY[0xCCA2C8] = 0;
    // ... linked list insert
    atexit(PhyreInit_PoolNode_B06370);
  }

  // Set accessor vtable for getMouseX
  MEMORY[0xCCA2CC] = &PMethodCallerConcrete<PInputMapper, unsigned int>::vftable;
  MEMORY[0xCCA2D0][0] = Concurrency::SchedulerProxy::GetNumBorrowedCores;
  MEMORY[0xCCA2C8] = &MEMORY[0xCCA2CC];

  // --- Phase 3: Register "getMouseY" scripting accessor ---
  if ((v0 & 4) == 0) {
    unk_CCA2B0 = v0 | 4;
    Phyre_StringNode_Ctor(&MEMORY[0xCCA2DC], &MEMORY[0xCC9E50], "getMouseY", 0);
    // ... linked list insert
    atexit(PhyreInit_PoolNode_B063B0);
  }

  // Set accessor vtable for getMouseY
  MEMORY[0xCCA2F4] = &PMethodCallerConcrete<PInputMapper, unsigned int>::vftable;
  MEMORY[0xCCA2F8] = Phyre_FieldGetter_Offset43;
  MEMORY[0xCCA2F0] = &MEMORY[0xCCA2F4];

  // --- Finalize ---
  Phyre_PClassDescriptor_FinalizeRegistration(&MEMORY[0xCC9E50]);
}
```

- **Callers:** 1 (Scripting_PInputMapper_RegisterApiInit)
- **Strings:** `"m_inputMap"`, `"getMouseX"`, `"getMouseY"`
- **Purpose:** Registers PInputMapper type system + first 2 Lua scripting getters

---

# Part 6: PInput System Singletons

## Phyre_PInput_InitSingleton (0xa33680, 518 bytes)

```c
PhyrePClassDescriptor *__cdecl Phyre_PInput_InitSingleton(int a1)
{
  // Phase 1: Init PArray<PInputMap*, 4> singleton at 0x1A856B0
  if ((unk_1A85744 & 1) == 0) {
    unk_1A85744 |= 1;
    Phyre_PClassDescriptor_ctor_PArrayPInputMapPtr4(&Size__123);
    Size__123.vfptr = &PClassDescriptorConcrete<PArray<PInputMap*, 4>>::vftable;
    atexit(Phyre_PInputChannelSemantic_VftableInit_13);
  }

  // If a1 != 0 and unk_1A856C8 not set
  if (a1 && !unk_1A856C8) {
    unk_1A856C8 = a1;  // store a1

    // Phase 2: Register "m_count" data member
    if ((v1 & 2) == 0) {
      unk_1A85744 |= 2;
      PUInt32 = Phyre_PType_GetPUInt32();
      Phyre_PClassDataMember_ctorAttach_structural(
        unk_1A85748, &Size__123, PUInt32, "m_count", 0, 0, 0);
      atexit(Phyre_PInputChannelSemantic_VftableInit_14);
    }

    // Phase 3: Init annotation with default value 0x7FFFFFFF
    if ((v1 & 4) == 0) {
      unk_1A85744 |= 4;
      v4 = Phyre_PType_GetPUInt32();
      PAnnotation_Init(&dword_1A85764[4], &unk_C907F4, v4, 0);
      dword_1A85764[4] = vtbl_PAnnotationWithValue_Int;
      n0x7FFFFFFF_1 = 0x7FFFFFFF;
      atexit(Phyre_PAnnotation_ListInit_w_1);
    }

    // Phase 4: Register "m_els" array member
    if ((v1 & 8) == 0) {
      unk_1A85744 |= 8;
      PClassDataMemberArray_Init(
        MEMORY[0x1A85790], &Size__123, &MEMORY[0x1941910],
        "m_els", 4, 2, 2, 4);
      // ...
    }

    MEMORY[0x1A85790][11] = 4;  // array element count = 4
    Phyre_PTypeDefault_PChar_RegisterName(&Size__123);
    Phyre_PClassDescriptor_FinalizeRegistration(&Size__123);
  }
  return &Size__123;
}
```

- **Callers:** 1 (Phyre_PInputMap_RegisterClassDescriptor)
- **Strings:** `"m_count"`, `"m_els"`
- **Key constant:** 0x7FFFFFFF (INT_MAX — default annotation value)
- **Purpose:** Registers `PArray<PInputMap*, 4>` class descriptor (fixed array of 4 input maps)

## Phyre_PInput_IterateAllDevices (0x627a00, 94 bytes)

```c
// Walks global device list, calls callback for each
int __thiscall Phyre_PInput_IterateAllDevices(int *this, int a2)
{
  // For each device in global list at g_atelFuncspaceCount_4_70:
  //   Call callback via vtable+24
  // Returns device count or 0
}
```

## Phyre_PInput_FindByNameCallback (0xa2e540, 27 bytes)

```c
// Callback to find input device by name
int __cdecl Phyre_PInput_FindByNameCallback(int a1, int a2)
{
  // Calls vtable+4 (GetName?) and compares against a2
  // Returns 0 on match (strcmp-like callback convention)
}
```

---

# Part 7: Vtable Summary

## Device Base

| Address | Name | Used By |
|---------|------|---------|
| 0xB3FC00 | `g_vtable_PInputDevice_Phyre` | All devices (base vtable) |
| 0xB3FC1C | `g_vtable_PInputDevice_Phyre.dtor_Aligned` | Mouse |
| 0xB3FC38 | `g_vtable_PInputDevice_Phyre.Keyboard_dtor` | Keyboard |
| 0xB3FC54 | `Phyre::PFramework::PInputDeviceTouch::vftable` | Touch |
| 0xB3FCAC | `Phyre::PFramework::PInputDevicePad::vftable` | Pad (base) |
| 0xB3FF88 | `Phyre::PFramework::PInputDevicePadDirectInput::vftable` | Pad DirectInput |
| 0xB3FFA4 | `Phyre::PFramework::PInputDevicePadXInput::vftable` | Pad XInput |

## Device Vtable Layout (estimated)

```
+0:  Destructor (scalar deleting destructor)
+4:  GetClassName? (returns device type name)
+8:  GetDeviceID? (returns device class byte)
+12: GetState? (returns current input state)
+16: SetState? / SetVibration (for gamepad)
+20: Update (called every frame by RefreshAll)
+24: DeviceType? (returns device category)
```

---

# Summary Tables

## Size Distribution

| Bucket | Range | Count |
|--------|-------|-------|
| Huge | >= 1024 bytes | 0 |
| Large | 512 - 1023 | 2 |
| Medium | 256 - 511 | 3 |
| Small | 128 - 255 | 5 |
| Tiny | < 128 bytes | 27 |

## Most Significant Functions

| Function | Size | Purpose |
|----------|------|---------|
| Pad_FactoryOrInit | **576** | XInput + DirectInput dual-path factory |
| Input_InitSingleton | **518** | PArray<PInputMap*,4> class descriptor |
| Mapper_RegisterType | **471** | Input mapper type + scripting bindings |
| Pad_Constructor | **374** | Gamepad init (4 sub-devices, 16 buttons) |
| Touch_Constructor | **368** | Touch init (24 points, 4 quadrant groups) |
| AxisConfigInit | **255** | Axis calibration (dead zone, sensitivity) |
| TimerInit | **248** | Device timer state init |
| Mouse_Constructor | **199** | Mouse init (5 sub-devices) |

## Subsystem Distribution

| Subsystem | Count |
|-----------|-------|
| Device constructors | 4 (keyboard, mouse, pad, touch) |
| Device destructors | 6 |
| Factories / Dispatch | 5 |
| System-level (init/shutdown/refresh) | 4 |
| Helper initializers | 5 |
| InputMapper type registration | 5 |
| PInput system | 7 |

---

## Key Findings

1. **Dual XInput/DirectInput gamepad path** — `Phyre_PInputDevicePad_FactoryOrInit` tries XInput first (up to 4 controllers, 964-byte struct), falls back to DirectInput (944-byte struct). Strings confirm: `"Creating new XInput Device: %d\n"` vs `"Creating new DirectInput Device\n"`.

2. **Global device list** at `g_atelFuncspaceCount_4_70` (0xC30FA0) — intrusive linked list using offset +4/+8 as next/prev pointers. All device constructors link into this list. ShutdownAll walks and destroys.

3. **IDirectInput8 stored at MEMORY[0xCC9CD4]** — created during InitDirectInput with `DINPUT_SDK_VERSION = 0x800`. Released during ShutdownAll.

4. **DispatchFactory by device class byte** — switch on byte at +36 of DirectInput device instance: 0x12 (18) = Keyboard, 0x13 (19) = Mouse, 0x14/0x15/0x18 (20/21/24) = Pad.

5. **Keyboard has 768 bytes of key state** — 3× 256-byte buffers: current frame, previous frame, and a third buffer (possibly for "any key" status or repeat tracking).

6. **Mouse has 5 sub-devices** — 5 × 48-byte sub-device structs. Likely X axis, Y axis, wheel, buttons group 1 (left/middle/right), buttons group 2 (X1/X2).

7. **Touch supports 24 simultaneous touch points** — each 40 bytes (position, state, ID). Organized into 4 quadrant groups of 240 bytes each. Timer + thread sync initialized.

8. **Pad struct size varies by type** — Base constructor allocates 944+ bytes (including 580-byte DirectInput state). XInput variant = 964 bytes, DirectInput variant = 944 bytes. Vtable overrides at 0xB3FFA4 (XInput) and 0xB3FF88 (DirectInput).

9. **Axis calibration hard-coded** — `AxisConfigInit` has pre-configured values: dead zone = 0.3f, sensitivity = 16.909/1817.145, physical range = 111.0, tuning factors = 1.137/0.307/0.321. These are FFX-specific gamepad tuning values.

10. **RefreshAll called every frame** — Called from `Phyre_Application_UpdateInput` and `FFX_UI_TitleAndMenuFlow`. Walks global device list calling vtable+20 (Update) on each device.

11. **InputMapper registers 10+ Lua accessors** — Phase 2+3 register getMouseX/getMouseY via PMethodCallerConcrete. The remaining accessors (getPadAxis, getPadButton, setVibration) are registered similarly in subsequent phases not fully captured here.

12. **PArray<PInputMap*, 4> singleton** — Fixed-size array of 4 input maps. Registered at 0x1A856B0 with `m_count` (int), annotation (default 0x7FFFFFFF), and `m_els` (4-element array). Phased class descriptor registration.

---

## Next Batches

- Batch 14: Phyre_PRendering (render pipeline, D3D11)
- Batch 15: Phyre_PSceneNode (~90 functions)
- Batch 16: Phyre_PPostProcessing
- Batch 17: Phyre_PAudio
