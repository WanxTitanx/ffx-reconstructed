# PhyreEngine SDK 3.1.5.0 -- Text, Input & Scaleform (UI) Struct Reference

> Source: `F:\ffx-reconstructed\EnginesExtras\Phyre_Engine\Phyre Engine\Include\`
> Generated: 2026-07-28
> SDK: SCE PhyreEngine Package 3.1.5.0, Copyright (C) 2011 Sony Computer Entertainment Inc.

---

## 1. TEXT SYSTEM (`PText` namespace)

### 1.1 `PUtilityText` -- Text Utility Initialization

**Header:** `Text/PhyreUtilityText.h`
**Inheritance:** `PUtility` (base: `PBase`)

| Member | Type | Visibility | Description |
|--------|------|------------|-------------|
| `s_textShaderShaderPassNamesDictionary[]` | `static const PTokenDictionary` | protected | Shader pass name dictionary |
| `s_renderPasses[PE_TEXT_RENDER_TECHNIQUE_COUNT]` | `static const PRendering::PSceneRenderPassType *[]` | protected | Render pass array per technique |
| `s_utilityText` | `extern PUtilityText` | global | Singleton instance for registration |

**Enum `PTextRenderTechnique`:**

| Value | Name | Description |
|-------|------|-------------|
| 0 | `PE_TEXT_RENDER_TECHNIQUE_ALPHA_BLEND` | Alpha blend technique |
| 1 | `PE_TEXT_RENDER_TECHNIQUE_ALPHA_TEST` | Alpha test technique |
| 2 | `PE_TEXT_RENDER_TECHNIQUE_SDF_HARD_EDGES` | SDF hard edges |
| 3 | `PE_TEXT_RENDER_TECHNIQUE_SDF_SOFT_EDGES` | SDF soft edges |
| 4 | `PE_TEXT_RENDER_TECHNIQUE_SDF_SOFT_EDGES_AND_OUTLINE` | SDF soft edges + outline |
| 5 | `PE_TEXT_RENDER_TECHNIQUE_SDF_SOFT_EDGES_AND_SHADOW` | SDF soft edges + drop shadow |
| 6 | `PE_TEXT_RENDER_TECHNIQUE_SDF_SOFT_EDGES_AND_GLOW` | SDF soft edges + glow |
| 7 | `PE_TEXT_RENDER_TECHNIQUE_COUNT` | Count sentinel |

**Methods:**
- `PUtilityText()` / `virtual ~PUtilityText()`
- `static const PChar *GetRenderPassNameForTechnique(PTextRenderTechnique technique)`
- `static const PRendering::PSceneRenderPassType *GetRenderPassForTechnique(PTextRenderTechnique technique)`

---

### 1.2 `PBitmapFontCharInfo` -- Per-Character Glyph Data

**Header:** `Text/PhyreBitmapFont.h`
**Inheritance:** `PBase`

| Member | Type | Description |
|--------|------|-------------|
| `m_characterCode` | `PInt32` | Unicode character code |
| `m_kernPairs` | `PInt32` | Number of kerning pairs |
| `m_kernOffset` | `PInt32` | Offset into kerning pair table |
| `m_uv[2]` | `float[2]` | Pixel coordinates of top-left of glyph (scaled by tex size + texel center offset) |
| `m_width` | `float` | Width in texels of glyph |
| `m_height` | `float` | Height in texels of glyph |
| `m_offset[2]` | `float[2]` | Offset from origin to top-left of glyph |
| `m_advance[2]` | `float[2]` | Advance from origin to next glyph origin |
| `m_rotated` | `bool` | Whether glyph is rotated (and mirrored) |

**Methods:**
- `bool operator ==(const PBitmapFontCharInfo &rhs) const` -- compares `m_characterCode`

---

### 1.3 `PBitmapFont` -- Font Definition with Bitmap Texture

**Header:** `Text/PhyreBitmapFont.h`
**Inheritance:** `PBase`
**Binding:** `PHYRE_BIND_DECLARE_CLASS_WITHOUT_DEFAULT_CONSTRUCTOR`

| Member | Type | Visibility | Description |
|--------|------|------------|-------------|
| `m_isSDF` | `bool` | protected | Font uses signed distance field |
| `m_fontSize` | `PUInt32` | protected | Font size in pixels |
| `m_lineSpacing` | `float` | protected | Distance between lines (pixels) |
| `m_baselineOffset` | `float` | protected | Pixels from absolute top of line to character base |
| `m_characterInfo` | `PArray<PBitmapFontCharInfo>` | protected | Array of per-character glyph data |
| `m_kerningInfo` | `PArray<PInt32>` | protected | Array of kerning data |
| `m_bitmapFontTexture` | `PReference<const PRendering::PTexture2D>` | protected | Texture containing the font bitmap |

**Methods:**
- `PBitmapFont(const PRendering::PTexture2D &bitmapFontTexture)`
- `PUInt32 getFontSize() const`
- `bool isSDF() const`
- `float getLineSpacing() const`
- `float getBaselineOffset() const`
- `const PRendering::PTexture2D &getBitmapFontTexture() const`
- `const PArray<PBitmapFontCharInfo> &getCharacterInfoArray() const`
- `const PArray<PInt32> &getKerningInfoArray() const`
- `PResult initialize(...)` (PHYRE_TOOL_BUILD only)

---

### 1.4 `PBitmapTextMaterial` -- Text Material Properties

**Header:** `Text/PhyreBitmapFontText.h`
**Inheritance:** `PMemoryBase`

| Member | Type | Visibility | Description |
|--------|------|------------|-------------|
| `m_material` | `PRendering::PMaterial *` | protected | Material used for rendering |
| `m_materialSet` | `PGeometry::PMaterialSet` | protected | Material set for text rendering |
| `m_bitmapFont` | `const PBitmapFont &` | protected | Reference to bitmap font object |
| `m_renderPass` | `const PRendering::PSceneRenderPassType *` | protected | Scene render pass |

**Methods:**
- `PResult initialize(PCluster &cluster, PUtilityText::PTextRenderTechnique technique)`
- `PResult setColor(const Vectormath::Aos::Vector3 &color)`
- `PResult setAlphaThreshold(const float threshold)`
- `PResult setParameter(const PChar *parameterName, const Vectormath::Aos::Vector4 &parameterValue)`

---

### 1.5 `PBitmapTextMaterialSDF` -- SDF Text Material Extension

**Header:** `Text/PhyreBitmapFontText.h`
**Inheritance:** `PBitmapTextMaterial` -> `PMemoryBase`

**Additional methods:**
- `PResult setOutlineColor(const Vectormath::Aos::Vector4 &outlineColor)`
- `PResult setOutlineValues(const Vectormath::Aos::Vector4 &outlineValues)`
- `PResult setShadowColor(const Vectormath::Aos::Vector4 &shadowColor)`
- `PResult setShadowUVOffset(const float u, const float v)`
- `PResult setGlowColor(const Vectormath::Aos::Vector4 &glowColor)`
- `PResult setGlowValues(const float min, const float max)`
- `PResult setSoftEdgeValues(const float min, const float max)`

---

### 1.6 `PBitmapFontText` -- Renderable Text String

**Header:** `Text/PhyreBitmapFontText.h`
**Inheritance:** `PMemoryBase`

| Member | Type | Visibility | Description |
|--------|------|------------|-------------|
| `m_mesh` | `PGeometry::PMesh` | protected | Mesh being rendered |
| `m_meshSegment` | `PGeometry::PMeshSegment` | protected | Mesh segment for the text |
| `m_meshInstance` | `PRendering::PMeshInstance` | protected | Mesh instance being rendered |
| `m_worldMatrix` | `PWorldMatrix` | protected | Mesh instance's world matrix |
| `m_textMaterial` | `PBitmapTextMaterial &` | protected | Reference to text material |
| `m_text` | `PArray<PChar>` | protected | The text string |
| `m_renderer` | `PRendering::PRenderer *` | protected | Renderer instance (for flush on termination) |
| `m_textWidth` | `float` | protected | Total width of text |
| `m_textHeight` | `float` | protected | Total height of text |
| `m_lineSpacingScale` | `float` | protected | Scale factor for line spacing |

**Methods:**
- `float getTextWidth() const`
- `float getTextHeight() const`
- `float getLineSpacingScale() const`
- `const PChar *getText() const`
- `void setMatrix(const PMatrix4 &matrix)`
- `PResult setTextLength(PUInt32 textLength)`
- `PResult setText(const PChar *text)`
- `PResult setLineSpacingScale(const float lineSpacingScale)`
- `PResult renderText(PRendering::PRenderer &renderer)`

---

## 2. INPUT SYSTEM (`PFramework` namespace)

### 2.1 `PInputBase` -- Input Base with Channel Enum

**Header:** `Framework/PhyreFrameworkInput.h`
**Inheritance:** (none -- standalone base)

**Enum `PInputChannel`:** See Section 2.7 below.

---

### 2.2 `PInput` -- Input Manager (Platform-Dispatched)

**Header:** `Framework/PhyreFrameworkInput.h`
**Inheritance:** `PHYRE_PLATFORM_IMPLEMENTATION(PInput)` -- resolves to `PInputWin32` on Windows

**Enum `PInputDeviceType`:**

| Value | Name |
|-------|------|
| 0 | `PE_INPUT_DEVICE_MOUSE` |
| 1 | `PE_INPUT_DEVICE_KEYBOARD` |
| 2 | `PE_INPUT_DEVICE_PAD` |
| 3 | `PE_INPUT_DEVICE_COUNT` |

| Member | Type | Visibility | Description |
|--------|------|------------|-------------|
| `s_devices[PD_MAXIMUM_INPUT_DEVICES]` | `static PInputDevice *[32]` | private | All registered input devices |
| `s_asciiLookup[128]` | `static PUInt8[128]` | private | ASCII to InputChannel mapping table |

**Methods:**
- `static PResult Initialize()`
- `static PResult Update()`
- `static PResult Terminate()`
- `static PInputDevice *GetDevice(PInputDeviceType type, PInt32 instance)`
- `static PInt32 EnumerateDevices(PInputDevice **devices)`
- `static PInputBase::PInputChannel AsciiToChannel(PInt32 ascii)`

**Constants:**

| Define | Value | Description |
|--------|-------|-------------|
| `PD_MAXIMUM_INPUT_DEVICES` | 32 | Max devices |
| `PD_MAXIMUM_NUM_FILTERS` | 256 | Max filters per device |
| `PD_MAXIMUM_NUM_KEYBOARDS` | 7 | Max keyboards |
| `PD_MAXIMUM_NUM_PADS_XINPUT` | 4 | Max XInput pads |
| `PD_MAXIMUM_NUM_PADS_DIRECTINPUT` | 7 | Max DirectInput pads |
| `PD_MAXIMUM_NUM_PADS` | 11+ | XInput + DirectInput (+ CellPad on PS3) |
| `PD_MAXIMUM_NUM_MICE` | 1 | Max mice |

---

### 2.3 `PInputWin32` -- Win32 Input Implementation

**Header:** `Framework/Win32/PhyreFrameworkInputWin32.h`
**Inheritance:** `PInputBase`

| Member | Type | Visibility | Description |
|--------|------|------------|-------------|
| `s_directInput` | `static LPDIRECTINPUT8` | private | DirectInput 8 device pointer |
| `s_reEnumDevices` | `static bool` | private | Re-enumeration flag |

**Methods:**
- `static PResult Initialize()`
- `static PResult Update()`
- `static PResult Terminate()`
- `static void onDeviceConnected()`
- `static void InitMouse(const DIDEVICEINSTANCE *)`
- `static void InitKeyboard(const DIDEVICEINSTANCE *)`
- `static void InitPad(const DIDEVICEINSTANCE *)`
- `static BOOL CALLBACK EnumJoystickObjectsCallback(...)`
- `static BOOL CALLBACK EnumDevicesCallback(...)`
- `static BOOL CALLBACK ReEnumDevicesCallback(...)`
- `static bool IsXInputDevice(const GUID* pGuidProductFromDirectInput)`

**Uses:** DirectInput 8 (`DIRECTINPUT_VERSION 0x0800`), XInput, `<windows.h>`, `<dinput.h>`

---

### 2.4 `PInputDevice` -- Base Input Device

**Header:** `Framework/PhyreFrameworkInputDevice.h`
**Inheritance:** (none -- standalone)

| Member | Type | Visibility | Description |
|--------|------|------------|-------------|
| `m_filters[PD_MAXIMUM_NUM_FILTERS]` | `PInputFilter *[256]` | protected | Bound input filters |
| `m_xAxis[3]` | `PInt32[3]` | protected | X-axis values (0=pad/mouse, 1=pad, 2=accel sensor) |
| `m_yAxis[3]` | `PInt32[3]` | protected | Y-axis values |
| `m_zAxis[3]` | `PInt32[3]` | protected | Z-axis values |
| `m_gyro` | `PInt32` | protected | Gyro sensor value |
| `m_buttons[16]` | `bool[16]` | protected | Button state array |
| `m_keys[256]` | `bool[256]` | protected | Key state array |
| `m_platformData` | `void *` | protected | Platform-specific data |

**Methods:**
- `virtual PInput::PInputDeviceType getDeviceType() const = 0`
- `PInputFilter *bindFilter()`
- `void unbindFilter(PInputFilter *filter)`
- `bool getRawBool(PInput::PInputChannel channel)`
- `float getRawFloat(PInput::PInputChannel channel)`

---

### 2.5 `PInputDeviceMouse` -- Mouse Device

**Header:** `Framework/PhyreFrameworkInputDevice.h`
**Inheritance:** `PInputDevice` + `PMemoryBase`

| Member | Type | Visibility | Description |
|--------|------|------------|-------------|
| `m_isClientRelative` | `bool` | protected | Return client-relative coordinates vs motion vector |

---

### 2.6 `PInputDeviceKeyboard` -- Keyboard Device

**Header:** `Framework/PhyreFrameworkInputDevice.h`
**Inheritance:** `PInputDevice` + `PMemoryBase`

| Member | Type | Visibility | Description |
|--------|------|------------|-------------|
| `m_key[256]` | `PChar[256]` | public | Currently depressed key flags |
| `m_prevKey[256]` | `PChar[256]` | public | Previously depressed key flags |
| `s_keyboardMap[256]` | `static PUInt8[256]` | protected | Keycode mapping (Win32/PS3 only) |

---

### 2.7 `PInputDevicePad` -- Joypad Base Class

**Header:** `Framework/DevicePad/PhyreFrameworkDevicePad.h`
**Inheritance:** `PInputDevice` + `PMemoryBase`

| Member | Type | Visibility | Description |
|--------|------|------------|-------------|
| `m_joypadButton[16]` | `PChar[16]` | public | Currently depressed joypad buttons |
| `m_prevJoypadButton[16]` | `PChar[16]` | public | Previously depressed joypad buttons |
| `s_applicationHasOwnershipOfJoypad` | `static bool` | public | False when XMB visible |
| `m_joypadSticks[4]` | `PInputFilter *[4]` | public | Joystick axis filters |
| `m_joypadSensors[4]` | `PInputFilter *[4]` | public | Acceleration sensor axis filters |
| `m_motorSpeeds[2]` | `float[2]` | public | Vibration motor speeds |
| `m_joypadDeviceCapabilities` | `PUInt32` | protected | Device capability flags |
| `s_highFrequencyRead` | `static bool` | protected | High-frequency read mode |
| `m_deviceInstance` | `DIDEVICEINSTANCE` | protected | Device ID (Win32 only) |

**Methods:**
- `virtual PInput::PInputDeviceType getDeviceType() const` -- returns `PE_INPUT_DEVICE_PAD`
- `void setVibration(PUInt8 motor, float value)`
- `static void SetHighFrequencyRead(bool highFrequencyRead)`
- `DIDEVICEINSTANCE& getDeviceInstance()` (Win32)

---

### 2.8 `PInputDevicePadXInput` -- Xbox/XInput Controller

**Header:** `Framework/DevicePad/PhyreFrameworkDevicePadXInput.h`
**Inheritance:** `PInputDevicePad` -> `PInputDevice` + `PMemoryBase`

| Member | Type | Visibility | Description |
|--------|------|------------|-------------|
| `m_xInputID` | `PUInt32` | protected | XInput ID (0-3) |
| `m_connected` | `bool` | protected | Connection state |
| `m_state` | `XINPUT_STATE` | protected | Current pad state |

---

### 2.9 `PInputDevicePadDirectInput` -- DirectInput Controller

**Header:** `Framework/DevicePad/PhyreFrameworkDevicePadDirectInput.h`
**Inheritance:** `PInputDevicePad` -> `PInputDevice` + `PMemoryBase`

| Member | Type | Visibility | Description |
|--------|------|------------|-------------|
| `m_connected` | `bool` | protected | Connection state |

---

### 2.10 `PInputDevicePadCellPad` -- PS3 CellPad Controller

**Header:** `Framework/DevicePad/PhyreFrameworkDevicePadCellPad.h`
**Inheritance:** `PInputDevicePad` -> `PInputDevice` + `PMemoryBase`
**Condition:** `PHYRE_PLATFORM_PS3` or `PHYRE_USE_LIBPAD_FOR_WINDOWS`

| Member | Type | Visibility | Description |
|--------|------|------------|-------------|
| `s_padIds[6][3]` | `static PInt32[6][3]` | protected | Pad ID mapping table |
| `s_padMappings[6][56]` | `static PInt32[6][56]` | protected | Button mapping table |
| `m_joypadDeviceCapabilities` | `PUInt32` | protected | Device capability flags |

---

### 2.11 `PInputDevicePadSceCtrl` -- PS Vita Controller

**Header:** `Framework/DevicePad/PhyreFrameworkDevicePadSceCtrl.h`
**Inheritance:** `PInputDevicePad` -> `PInputDevice` + `PMemoryBase`

**Additional methods:**
- `static PInt32 StickPosToFrameworkPos(SceUInt8 pos)`

---

### 2.12 `PInputFilter` -- Input Filter (gain/bias/deadzone)

**Header:** `Framework/PhyreFrameworkInputFilter.h`
**Inheritance:** `PMemoryBase`

| Member | Type | Visibility | Description |
|--------|------|------------|-------------|
| `m_boundDevice` | `PInputDevice *` | private | Bound device |
| `m_deviceBinding` | `PInt32` | private | Device binding value |
| `m_channel` | `PInput::PInputChannel` | private | Channel |
| `m_gain` | `float` | private | Gain multiplier |
| `m_bias` | `float` | private | Bias offset |
| `m_deadzone` | `float` | private | Deadzone threshold |
| `m_floatValue` | `float` | private | Processed float value |
| `m_rawValue` | `PInt32` | private | Processed int value |
| `m_boolValue` | `bool` | private | Processed bool value |
| `m_boolTrue` | `bool` | private | True on false->true transition |
| `m_boolFalse` | `bool` | private | True on true->false transition |

**Methods:**
- `void setChannel(PInput::PInputChannel channel)`
- `void setGain(float gain)`
- `void setBias(float bias)`
- `void setDeadzone(float zone)`
- `float getFloatValue() const`
- `PInt32 getRawValue() const`
- `bool getBoolValue() const`
- `bool getBoolTrue() const`
- `bool getBoolFalse() const`

---

### 2.13 `PMouseInfoWin32` -- Win32 Mouse Info

**Header:** `Framework/Win32/PhyreFrameworkInputWin32.h`
**Inheritance:** `PMemoryBase`

| Member | Type | Description |
|--------|------|-------------|
| `m_isWithinClientArea` | `bool` | Mouse cursor inside client area |
| `m_device` | `LPDIRECTINPUTDEVICE8` | DirectInput device pointer |

---

### 2.14 `PPadInfoCellPad` -- CellPad Wrapper

**Header:** `Framework/DevicePad/PhyreFrameworkDevicePadCellPad.h`
**Inheritance:** `PMemoryBase`

| Member | Type | Description |
|--------|------|-------------|
| `m_device` | `PInt32` | Device ID |
| `m_padId` | `PInt32` | Pad ID |

---

### 2.15 Input Channel Enum (`PInputChannel`)

**Header:** `Framework/PhyreFrameworkInputChannels.h`

**Axes (analog):**

| Name | Description |
|------|-------------|
| `InputChannel_XAxis_0` | Mouse/Pad X-Axis 0 |
| `InputChannel_YAxis_0` | Mouse/Pad Y-Axis 0 |
| `InputChannel_ZAxis_0` | Mouse/Pad Z-Axis 0 |
| `InputChannel_XAxis_1` | Pad X-Axis 1 |
| `InputChannel_YAxis_1` | Pad Y-Axis 1 |
| `InputChannel_ZAxis_1` | Pad Z-Axis 1 |
| `InputChannel_XAxis_2` | Pad X-Axis 2 (Acceleration Sensor) |
| `InputChannel_YAxis_2` | Pad Y-Axis 2 (Acceleration Sensor) |
| `InputChannel_ZAxis_2` | Pad Z-Axis 2 (Acceleration Sensor) |
| `InputChannel_Gyro` | Pad Gyro Sensor |

**Buttons (digital, 16 total):**

| Generic | PS3 Name | MS Name | Mouse Name |
|---------|----------|---------|------------|
| Button_0 | Square | X | LeftMB |
| Button_1 | Cross | A | MiddleMB |
| Button_2 | Circle | B | RightMB |
| Button_3 | Triangle | Y | -- |
| Button_4 | L1 | LB | -- |
| Button_5 | R1 | RB | -- |
| Button_6 | L2 | LT | -- |
| Button_7 | R2 | RT | -- |
| Button_8 | Select | Back | -- |
| Button_9 | Start | -- | -- |
| Button_10 | L3 | LS | -- |
| Button_11 | R3 | RS | -- |
| Button_12 | Up | -- | -- |
| Button_13 | Right | -- | -- |
| Button_14 | Down | -- | -- |
| Button_15 | Left | -- | -- |

**Keyboard Keys:** `InputChannel_Key_A` through `InputChannel_Key_Z`, `Key_0` through `Key_9`, function keys `Key_F1`-`Key_F12`, navigation keys, numpad, modifiers.

---

## 3. APPLICATION FRAMEWORK (Input Integration)

### 3.1 `PApplication` -- Base Application Class

**Header:** `Framework/PhyreFrameworkApplication.h`
**Inheritance:** `PBase`

**Joypad enums:**

| Enum | Value | Description |
|------|-------|-------------|
| `JOYPAD_STICK_AXIS_LEFT_X` | 0 | Left stick X |
| `JOYPAD_STICK_AXIS_LEFT_Y` | 1 | Left stick Y |
| `JOYPAD_STICK_AXIS_RIGHT_X` | 2 | Right stick X |
| `JOYPAD_STICK_AXIS_RIGHT_Y` | 3 | Right stick Y |
| `JOYPAD_SENSOR_AXIS_X` | 0 | Acceleration sensor X |
| `JOYPAD_SENSOR_AXIS_Y` | 1 | Acceleration sensor Y |
| `JOYPAD_SENSOR_AXIS_Z` | 2 | Acceleration sensor Z |
| `JOYPAD_SENSOR_AXIS_VELOCITY` | 3 | Angular velocity sensor |

**Input-related members:**

| Member | Type | Visibility | Description |
|--------|------|------------|-------------|
| `m_mouseFilterX` | `PInputFilter *` | protected | Mouse X movement filter |
| `m_mouseFilterY` | `PInputFilter *` | protected | Mouse Y movement filter |
| `m_mouseFilterL` | `PInputFilter *` | protected | Left mouse button filter |
| `m_mouseFilterM` | `PInputFilter *` | protected | Middle mouse button filter |
| `m_mouseFilterR` | `PInputFilter *` | protected | Right mouse button filter |
| `m_joypadSticks[4]` | `PInputFilter *[4]` | protected | Joystick axis filters |
| `m_joypadSensors[4]` | `PInputFilter *[4]` | protected | Acceleration sensor filters |
| `m_joypad[PD_MAXIMUM_NUM_PADS]` | `PInputDevicePad *[]` | protected | All joypad devices |
| `m_keyboard[PD_MAXIMUM_NUM_KEYBOARDS]` | `PInputDeviceKeyboard *[]` | protected | All keyboard devices |
| `m_mouse` | `PInputDeviceMouse *` | protected | First mouse device |
| `m_leftMouse` | `PChar` | protected | Left mouse button depressed |
| `m_rightMouse` | `PChar` | protected | Right mouse button depressed |
| `m_middleMouse` | `PChar` | protected | Middle mouse button depressed |
| `m_stickyLeftMouse` | `PChar` | protected | Sticky left mouse button |
| `m_stickyRightMouse` | `PChar` | protected | Sticky right mouse button |
| `m_stickyMiddleMouse` | `PChar` | protected | Sticky middle mouse button |
| `m_mouseMoved` | `PChar` | protected | Mouse has moved flag |
| `m_mouseX` | `long` | protected | Mouse X position |
| `m_mouseY` | `long` | protected | Mouse Y position |
| `m_mouseOffsetX` | `long` | protected | Mouse X delta |
| `m_mouseOffsetY` | `long` | protected | Mouse Y delta |

**Input helper methods:**
- `bool isKeyDown(const PChar *key)` / `bool isKeyDown(PInput::PInputChannel, PUInt32 keyboardID = 0)`
- `void setKeyDown(PInput::PInputChannel key, bool down, PUInt32 keyboardID = 0)`
- `bool checkAndClearKey(PInput::PInputChannel, PUInt32 keyboardID = 0)`
- `void toggleOnKey(bool &flag, PInput::PInputChannel, PUInt32 keyboardID = 0)`
- `float getJoypadStickPosition(...)` / `bool isJoypadButtonDown(...)`
- `void setJoypadButtonDown(...)` / `bool checkAndClearJoypadButton(...)`

---

## 4. SCALEFORM (Flash/GFx UI SYSTEM -- PhyreEngine's "Iggy" equivalent)

> **Note:** PhyreEngine SDK 3.1.5.0 does NOT include an "Iggy" directory. Iggy is the PS4/PS5-era Scaleform successor. The PS3/Win32 era SDK uses **Scaleform GFx** for Flash-based UI. This section documents the Scaleform integration layer.

### 4.1 `PUtilityScaleform` -- Scaleform Utility Initialization

**Header:** `Scaleform/PhyreScaleform.h`
**Inheritance:** `Phyre::PUtility` -> `PBase`

**Methods:**
- `static void SetActionScript2(Scaleform::GFx::AS2Support *as2Support)`
- `static void SetActionScript3(Scaleform::GFx::AS3Support *as3Support)`
- `static void SetFsCommandHandler(Scaleform::GFx::FSCommandHandler *fsCommandHandler)`
- `static void SetExternalInterface(Scaleform::GFx::ExternalInterface *externalInterface)`
- `static void SetAudio(Scaleform::GFx::AudioBase *audio)`
- `static PScaleformMovie *CreateMovie(PUInt32 width, PUInt32 height, const char *filename)`

| Global | Type | Description |
|--------|------|-------------|
| `s_utilityScaleform` | `extern PUtilityScaleform` | Singleton instance |

---

### 4.2 `PScaleformMovie` -- Flash Movie Instance

**Header:** `Scaleform/PhyreScaleformMovie.h`
**Inheritance:** `PMemoryBase`

| Member | Type | Visibility | Description |
|--------|------|------------|-------------|
| `s_shared` | `static PScaleformMovieSharedComponents *` | protected | Shared components across movies |
| `s_sharedCount` | `static PUInt32` | protected | Shared ref count |
| `m_movieDef` | `Scaleform::GFx::MovieDef *` | protected | Flash movie definition |
| `m_movie` | `Scaleform::GFx::Movie *` | protected | Flash movie view object |
| `m_movieDisplayHandle` | `Scaleform::GFx::MovieDisplayHandle` | protected | Movie display handle |
| `m_width` | `PUInt32` | protected | Render width |
| `m_height` | `PUInt32` | protected | Render height |

**Methods:**
- `PResult init(const char *filename, PUInt32 width, PUInt32 height)`
- `PResult setViewport(PUInt32 left, PUInt32 top, PUInt32 width, PUInt32 height)`
- `PResult advanceTime(float timeDelta)`
- `PResult render(PRendering::PRenderer &renderer)`
- `Scaleform::GFx::MovieDef *getMovieDef() const`
- `Scaleform::GFx::Movie *getMovie() const`
- `static PScaleformMovieSharedComponents *getShared()`

---

### 4.3 `PScaleformMovieSharedComponents` -- Shared Movie Infrastructure

**Header:** `Scaleform/PhyreScaleformMovieSharedComponents.h`
**Inheritance:** `PMemoryBase`

| Member | Type | Visibility | Description |
|--------|------|------------|-------------|
| `s_As2Support` | `static Scaleform::GFx::AS2Support *` | protected | ActionScript 2 support |
| `s_As3Support` | `static Scaleform::GFx::AS3Support *` | protected | ActionScript 3 support |
| `s_fsCommandHandler` | `static Scaleform::GFx::FSCommandHandler *` | protected | FS Command handler |
| `s_externalInterface` | `static Scaleform::GFx::ExternalInterface *` | protected | External interface |
| `s_audio` | `static Scaleform::GFx::AudioBase *` | protected | Audio playback |
| `m_GFxLoader` | `Scaleform::GFx::Loader` | protected | GFx loader |
| `m_imageRegistryContainer` | `PScaleformImageRegistryContainer *` | protected | Image file handler registry |
| `m_playerLog` | `GFxPlayerLog *` | protected | GFx log |
| `m_fileOpener` | `Scaleform::GFx::FileOpener *` | protected | File opener |
| `m_textureManager` | `PScaleformTextureManager *` | protected | Texture manager |
| `m_meshCacheContainer` | `PScaleformMeshCacheContainer *` | protected | Mesh cache container |
| `m_renderBufferManagerContainer` | `PScaleformRenderBufferManagerContainer *` | protected | Render buffer manager |
| `m_hal` | `PScaleformHAL *` | protected | Hardware abstraction layer |
| `m_renderer` | `Scaleform::Render::Renderer2D *` | protected | 2D renderer |

---

### 4.4 `PScaleformHAL` -- Hardware Abstraction Layer (Rendering Backend)

**Header:** `Scaleform/PhyreScaleformHAL.h`
**Inheritance:** `Scaleform::Render::HAL`

| Member | Type | Visibility | Description |
|--------|------|------------|-------------|
| `m_textureManager` | `PScaleformTextureManager &` | protected | Texture manager ref |
| `m_renderBufferManager` | `RenderBufferManager &` | protected | Render buffer manager |
| `m_meshCache` | `PScaleformMeshCache &` | protected | Mesh cache |
| `m_renderQueue` | `Scaleform::Render::RenderQueue` | protected | Render queue |
| `m_renderQueueProcessor` | `Scaleform::Render::RenderQueueProcessor` | protected | Queue processor |
| `m_pHeap` | `Scaleform::MemoryHeap *` | protected | Global heap |
| `m_accumulatedStats` | `Scaleform::Render::HAL::Stats` | protected | Accumulated draw stats |
| `m_renderer` | `PRendering::PRenderer *` | protected | PhyreEngine renderer |
| `m_shaderCluster[12]` | `PCluster[12]` | protected | Loaded shader clusters |
| `m_materialSet[12]` | `PGeometry::PMaterialSet[12]` | protected | Material sets (one per shader) |
| `m_blendModeStack` | `PBlendStackType` | protected | Blend mode stack |
| `m_maskStack` | `PMaskStackType` | protected | Mask stack |
| `m_maskStackTop` | `PUInt32` | protected | Mask stack top index |
| `m_drawingMask` | `bool` | protected | Currently drawing mask |
| `m_maskClearRectangleMesh[4]` | `PGeometry::PMesh[4]` | protected | Mask clear meshes |
| `m_maskClearRectangleMeshInstance[4]` | `PMeshInstance *[4]` | protected | Mask clear mesh instances |
| `m_renderTargetStack` | `PRenderTargetStackType` | protected | Render target stack |
| `m_fillFlags` | `PUInt32` | protected | Fill flags for shader selection |
| `m_vp` | `Scaleform::Render::Viewport` | protected | Current viewport |
| `m_viewRect` | `Scaleform::Render::Rect<int>` | protected | Screen render rectangle |
| `m_viewValid` | `bool` | protected | Viewport validity flag |
| `m_renderMode` | `int` | protected | Force viewport render mode |
| `m_screenHeight` | `PUInt32` | protected | Screen height |
| `m_shaderManager` | `PScaleformShaderManager` | protected | Shader manager |
| `m_staticFShaders2D[FS_Count]` | `PScaleformFragmentShader2D[]` | public | 2D fragment shaders |
| `m_staticFShaders3D[FS_Count]` | `PScaleformFragmentShader3D[]` | public | 3D fragment shaders |
| `m_staticVShaders[VS_Count]` | `PScaleformVertexShader[]` | public | Vertex shaders |
| `m_shaderData` | `PScaleformShaderInterface` | protected | Shader data manager |

---

### 4.5 `PScaleformHALData` -- Render Target HAL Data

**Header:** `Scaleform/PhyreScaleformHAL.h`
**Inheritance:** `Scaleform::Render::RenderBuffer::HALData`

| Member | Type | Description |
|--------|------|-------------|
| `m_depthStencilBuffer` | `Scaleform::Render::DepthStencilBuffer *` | Depth stencil buffer |
| `m_colorRenderTarget` | `PRendering::PRenderTarget *` | Color render target |
| `m_depthRenderTarget` | `PRendering::PRenderTarget *` | Depth render target |
| `m_colorRenderTargetBuffer[sizeof(PRenderTarget)/sizeof(PUInt32)]` | `PUInt32[]` | In-place color RT buffer |
| `m_depthRenderTargetBuffer[sizeof(PRenderTarget)/sizeof(PUInt32)]` | `PUInt32[]` | In-place depth RT buffer |

---

### 4.6 `PScaleformBlendSetup` -- Blend Mode Configuration

**Header:** `Scaleform/PhyreScaleformHAL.h`

| Member | Type | Description |
|--------|------|-------------|
| `m_blendEquation` | `PShaderBlendEquationType` | Blend equation |
| `m_sourceColor` | `PShaderBlendType` | Source color blend factor |
| `m_destColor` | `PShaderBlendType` | Destination color blend factor |
| `m_sourceAlpha` | `PShaderBlendType` | Source alpha blend factor |
| `m_destAlpha` | `PShaderBlendType` | Destination alpha blend factor |

---

### 4.7 `PMaskStackEntry` -- Stacked Mask Entry

**Header:** `Scaleform/PhyreScaleformHAL.h`

| Member | Type | Description |
|--------|------|-------------|
| `m_primitive` | `Scaleform::Render::MaskPrimitive *` | Mask primitive being drawn |
| `m_oldViewportValid` | `bool` | Previous viewport valid flag |
| `m_oldViewRect` | `Scaleform::Render::Rect<int>` | Previous viewport rect |

---

### 4.8 `PRenderTargetStackEntry` -- Render Target Stack Entry

**Header:** `Scaleform/PhyreScaleformHAL.h`

| Member | Type | Description |
|--------|------|-------------|
| `m_renderTarget` | `Scaleform::Render::RenderTarget *` | Scaleform render target |
| `m_oldUserMatrix` | `Scaleform::Render::Matrix2F` | Old user matrix |
| `m_oldViewRect` | `Scaleform::Render::Rect<int>` | Old view rectangle |
| `m_oldViewport` | `Scaleform::Render::Viewport` | Old viewport |

---

### 4.9 `PScaleformTextureManager` -- Texture Management

**Header:** `Scaleform/PhyreScaleformTextureManager.h`
**Inheritance:** `Scaleform::Render::TextureManager`

| Member | Type | Visibility | Description |
|--------|------|------------|-------------|
| `s_textureFormats[]` | `static PScaleformTextureFormat[]` | protected | Available texture formats |
| `m_mappedTexture0` | `PScaleformMappedTexture` | protected | Singular mapped texture (avoids alloc) |
| `m_imageUpdates` | `PScaleformImageUpdateQueue` | protected | Pending image update queue |
| `m_renderer` | `PRendering::PRenderer *` | protected | PhyreEngine renderer |

**Methods:**
- `PScaleformMappedTexture *mapTexture(PScaleformTexture *p, PUInt32 mipLevel, PUInt32 levelCount)`
- `void unmapTexture(PScaleformTexture *ptexture)`
- `static PScaleformTextureManager *CreateTextureManager()`
- `virtual Scaleform::Render::Texture *CreateTexture(...)`
- `virtual Scaleform::Render::DepthStencilSurface *CreateDepthStencilSurface(...)`
- `virtual void UpdateImage(Scaleform::Render::Image *pimage)`
- `void setPhyreRenderer(PRendering::PRenderer &renderer)`

---

### 4.10 `PScaleformTexture` -- Scaleform Texture Wrapper

**Header:** `Scaleform/PhyreScaleformTexture.h`
**Inheritance:** `Scaleform::Render::Texture`

| Member | Type | Description |
|--------|------|-------------|
| `m_manager` | `PScaleformTextureManager *` | Texture manager |
| `m_image` | `Scaleform::Render::ImageBase *` | Source image |
| `m_format` | `const PScaleformTextureFormat *` | Texture format |
| `m_imgSize` | `const Scaleform::Render::ImageSize` | Image/texture size |
| `m_mipLevels` | `PUInt32` | Mip level count |
| `m_use` | `PUInt32` | Usage flags |
| `m_textureCount` | `PUInt32` | Number of texture planes |
| `m_texture[4]` | `PRendering::PTexture2D *[4]` | PhyreEngine texture pointers |
| `m_mappedTexture` | `PScaleformMappedTexture *` | Mapped texture data |

---

### 4.11 `PScaleformMeshCache` -- Mesh Cache

**Header:** `Scaleform/PhyreScaleformMeshCache.h`
**Inheritance:** `Scaleform::Render::MeshCache`

| Member | Type | Visibility | Description |
|--------|------|------------|-------------|
| `m_lruSentinel` | `PScaleformMeshCacheItemLruNode` | protected | LRU cache management node |
| `m_meshCacheListSet` | `Scaleform::Render::MeshCacheListSet` | protected | Mesh cache list set |
| `m_locked` | `bool` | protected | Cache buffer lock state |

**Constants:**
- `SF_RENDER_PHYRE_INSTANCE_MATRICES = 15` -- max batched meshes per draw call

---

### 4.12 `PScaleformMeshCacheContainer` -- RefCounted Mesh Cache Wrapper

**Header:** `Scaleform/PhyreScaleformMeshCache.h`
**Inheritance:** `Scaleform::RefCountBase<PScaleformMeshCacheContainer, Scaleform::StatRender_Mem>`

| Member | Type | Description |
|--------|------|-------------|
| `m_meshCache` | `PScaleformMeshCache` | The mesh cache object |

---

### 4.13 `PScaleformImageRegistryContainer` -- Image Registry Wrapper

**Header:** `Scaleform/PhyreScaleformMovieSharedComponents.h`
**Inheritance:** `Scaleform::RefCountBase<PScaleformImageRegistryContainer, Scaleform::StatRender_Mem>`

| Member | Type | Description |
|--------|------|-------------|
| `m_imageRegistry` | `Scaleform::GFx::ImageFileHandlerRegistry` | Image file handler registry |

---

### 4.14 `PScaleformRenderBufferManagerContainer` -- Render Buffer Manager Wrapper

**Header:** `Scaleform/PhyreScaleformMovieSharedComponents.h`
**Inheritance:** `Scaleform::RefCountBase<PScaleformRenderBufferManagerContainer, Scaleform::StatRender_Mem>`

| Member | Type | Description |
|--------|------|-------------|
| `m_renderBufferManager` | `Scaleform::Render::RBGenericImpl::RenderBufferManager` | Render buffer manager |

---

## 5. INHERITANCE HIERARCHY SUMMARY

### Text System
```
PBase
  PBitmapFontCharInfo
  PBitmapFont

PUtility
  PUtilityText

PMemoryBase
  PBitmapTextMaterial
    PBitmapTextMaterialSDF
  PBitmapFontText
```

### Input System
```
PInputBase
  PInputWin32  (Win32 platform)
  PInputPS3    (PS3 platform)
  PInputPSP2   (Vita platform)

PInputDevice
  PInputDeviceMouse  (+ PMemoryBase)
  PInputDeviceKeyboard  (+ PMemoryBase)
  PInputDevicePad  (+ PMemoryBase)
    PInputDevicePadXInput      (Win32 Xbox)
    PInputDevicePadDirectInput (Win32 generic)
    PInputDevicePadCellPad     (PS3/CellPad)
    PInputDevicePadSceCtrl     (PS Vita)

PMemoryBase
  PInputFilter
  PMouseInfoWin32
  PPadInfoCellPad

PBase
  PApplication (abstract)
```

### Scaleform UI System
```
PUtility
  PUtilityScaleform

PMemoryBase
  PScaleformMovie
  PScaleformMovieSharedComponents

Scaleform::Render::HAL
  PScaleformHAL

Scaleform::Render::TextureManager
  PScaleformTextureManager

Scaleform::Render::Texture
  PScaleformTexture

Scaleform::Render::MeshCache
  PScaleformMeshCache

Scaleform::RefCountBase<>
  PScaleformImageRegistryContainer
  PScaleformRenderBufferManagerContainer
  PScaleformMeshCacheContainer

Scaleform::Render::RenderBuffer::HALData
  PScaleformHALData
```

---

## 6. FFX RELEVANCE NOTES

- **Text rendering:** FFX uses `PBitmapFontText` for all on-screen text (dialogue, menus, damage numbers). The SDF path (`PBitmapTextMaterialSDF`) enables resolution-independent text with outline/shadow/glow effects -- visible in FFX HD PC's HUD.
- **Input:** FFX PC uses DirectInput 8 + XInput via `PInputDevicePadDirectInput` and `PInputDevicePadXInput`. The `PInputFilter` gain/bias/deadzone pipeline maps directly to FFX's joypad deadzone settings. The `DirectInput8Create` hook point is the critical bridge for the dinput8.dll mod.
- **Scaleform UI:** FFX HD PC's menus (Sphere Grid, equipment, save screen) are Flash .swf movies rendered through the Scaleform pipeline. `PScaleformMovie::init()` loads `.swf` files; `PScaleformMovie::render()` draws them. The `FSCommandHandler` and `ExternalInterface` bridge Flash actionscript to C++ game logic.
- **No Iggy:** This SDK (3.1.5.0, PS3/Win32 era) predates Iggy. Iggy is the PS4/PS5 Scaleform successor introduced in later PhyreEngine versions. FFX HD PC (2016 port by Virtuos) uses Scaleform, not Iggy.
