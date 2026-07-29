# PhyreEngine 3.1.5.0 -- PostProcessing / Math / ShadowCaster / OccluderGeometry Reference

> Extracted from SDK headers: `External/PS3SDK`, `Include/PostProcessing/`, `Include/Rendering/`, `Include/OccluderGeometry/`
> `DeveloperExtensions/` and `Include/ShadowCaster/` do not exist in this SDK version. ShadowCaster lives under `Include/Rendering/`.

---

## 1 -- Vectormath Library (`Vectormath::Aos` namespace)

Source: `External/PS3SDK/target/common/include/vectormath/scalar/cpp/vectormath_aos.h`

All classes are 16-byte aligned (GCC: `__attribute__((aligned(16)))`). Non-GCC compilers pad `Vector3` and `Point3` with a 4th float `d` to reach 16 bytes.

### 1.1 Vector3

| Member | Type | Description |
|--------|------|-------------|
| `mX` | `float` | X component |
| `mY` | `float` | Y component |
| `mZ` | `float` | Z component |
| `d` | `float` | Padding (non-GCC only, makes struct 16 bytes) |

**Constructors:**
- `Vector3()` -- no init
- `Vector3(const Vector3&)` -- copy
- `Vector3(float x, float y, float z)` -- from components
- `Vector3(const Point3&)` -- explicit, from point
- `Vector3(float scalar)` -- explicit, broadcast scalar

**Arithmetic operators:** `+`, `-`, `*scalar`, `/scalar`, `+=`, `-=`, `*=`, `/=`, unary `-`

**Key free functions:**

| Function | Signature | Description |
|----------|-----------|-------------|
| `mulPerElem` | `(Vector3, Vector3) -> Vector3` | Component-wise multiply |
| `divPerElem` | `(Vector3, Vector3) -> Vector3` | Component-wise divide |
| `recipPerElem` | `(Vector3) -> Vector3` | Component-wise reciprocal |
| `sqrtPerElem` | `(Vector3) -> Vector3` | Component-wise sqrt |
| `rsqrtPerElem` | `(Vector3) -> Vector3` | Component-wise reciprocal sqrt |
| `absPerElem` | `(Vector3) -> Vector3` | Component-wise abs |
| `copySignPerElem` | `(Vector3, Vector3) -> Vector3` | Copy sign from vec1 to vec0 |
| `maxPerElem` | `(Vector3, Vector3) -> Vector3` | Component-wise max |
| `minPerElem` | `(Vector3, Vector3) -> Vector3` | Component-wise min |
| `maxElem` | `(Vector3) -> float` | Maximum single element |
| `minElem` | `(Vector3) -> float` | Minimum single element |
| `sum` | `(Vector3) -> float` | Sum of all elements |
| `dot` | `(Vector3, Vector3) -> float` | Dot product |
| `lengthSqr` | `(Vector3) -> float` | Squared length |
| `length` | `(Vector3) -> float` | Length |
| `normalize` | `(Vector3) -> Vector3` | Unit vector (undefined near zero) |
| `cross` | `(Vector3, Vector3) -> Vector3` | Cross product |
| `outer` | `(Vector3, Vector3) -> Matrix3` | Outer product |
| `rowMul` | `(Vector3, Matrix3) -> Vector3` | Row-vector pre-multiply by matrix |
| `crossMatrix` | `(Vector3) -> Matrix3` | Skew-symmetric cross-product matrix |
| `crossMatrixMul` | `(Vector3, Matrix3) -> Matrix3` | Cross-product matrix then multiply |
| `lerp` | `(t, Vector3, Vector3) -> Vector3` | Linear interpolation (unclamped) |
| `slerp` | `(t, Vector3, Vector3) -> Vector3` | Spherical linear interpolation (unclamped) |
| `select` | `(Vector3, Vector3, bool) -> Vector3` | Conditional select |
| `loadXYZ` | `(Vector3&, float*) -> void` | Load from 3 floats |
| `storeXYZ` | `(Vector3, float*) -> void` | Store to 3 floats |
| `loadHalfFloats` | `(Vector3&, uint16*) -> void` | Load 3 half-floats |
| `storeHalfFloats` | `(Vector3, uint16*) -> void` | Store 3 half-floats |

**Static constructors:** `xAxis()`, `yAxis()`, `zAxis()`

---

### 1.2 Vector4

| Member | Type | Description |
|--------|------|-------------|
| `mX` | `float` | X component |
| `mY` | `float` | Y component |
| `mZ` | `float` | Z component |
| `mW` | `float` | W component |

16 bytes, naturally aligned.

**Constructors:**
- `Vector4()` -- no init
- `Vector4(const Vector4&)` -- copy
- `Vector4(float x, float y, float z, float w)` -- from components
- `Vector4(const Vector3& xyz, float w)` -- from vec3 + scalar
- `Vector4(const Vector3&)` -- explicit, w=0
- `Vector4(const Point3&)` -- explicit, w=1
- `Vector4(const Quat&)` -- explicit, from quaternion
- `Vector4(float scalar)` -- explicit, broadcast

**Key free functions:** same per-element ops as Vector3 (`mulPerElem`, `divPerElem`, `recipPerElem`, `sqrtPerElem`, `rsqrtPerElem`, `absPerElem`, `copySignPerElem`, `maxPerElem`, `minPerElem`, `maxElem`, `minElem`, `sum`, `dot`, `lengthSqr`, `length`, `normalize`, `outer`, `lerp`, `slerp`, `select`).

Additional: `loadXYZW`, `storeXYZW`, `loadHalfFloats`, `storeHalfFloats`.

**Static constructors:** `xAxis()`, `yAxis()`, `zAxis()`, `wAxis()`

---

### 1.3 Point3

| Member | Type | Description |
|--------|------|-------------|
| `mX` | `float` | X component |
| `mY` | `float` | Y component |
| `mZ` | `float` | Z component |
| `d` | `float` | Padding (non-GCC only) |

**Operators:** `-(Point3) -> Vector3`, `+(Vector3) -> Point3`, `-(Vector3) -> Point3`, `+=`, `-=`

**Key free functions:**

| Function | Signature | Description |
|----------|-----------|-------------|
| `scale` | `(Point3, float) -> Point3` | Uniform scale |
| `scale` | `(Point3, Vector3) -> Point3` | Non-uniform scale |
| `projection` | `(Point3, Vector3) -> float` | Scalar projection onto unit vector |
| `distSqrFromOrigin` | `(Point3) -> float` | Squared distance from origin |
| `distFromOrigin` | `(Point3) -> float` | Distance from origin |
| `distSqr` | `(Point3, Point3) -> float` | Squared distance between points |
| `dist` | `(Point3, Point3) -> float` | Distance between points |
| `lerp` | `(t, Point3, Point3) -> Point3` | Linear interpolation |

Also: `mulPerElem`, `divPerElem`, `recipPerElem`, `sqrtPerElem`, `rsqrtPerElem`, `absPerElem`, `copySignPerElem`, `maxPerElem`, `minPerElem`, `maxElem`, `minElem`, `sum`, `select`, `loadXYZ`, `storeXYZ`, `loadHalfFloats`, `storeHalfFloats`.

---

### 1.4 Quat

| Member | Type | Description |
|--------|------|-------------|
| `mX` | `float` | X (imaginary) |
| `mY` | `float` | Y (imaginary) |
| `mZ` | `float` | Z (imaginary) |
| `mW` | `float` | W (real) |

16 bytes, naturally aligned.

**Constructors:**
- `Quat()` -- no init
- `Quat(const Quat&)` -- copy
- `Quat(float x, float y, float z, float w)` -- from components
- `Quat(const Vector3& xyz, float w)` -- from vec3 + scalar
- `Quat(const Vector4&)` -- explicit, from Vector4
- `Quat(const Matrix3&)` -- explicit, rotation matrix to quaternion
- `Quat(float scalar)` -- explicit, broadcast

**Operators:** `+`, `-`, `*(Quat)` (quaternion multiply), `*scalar`, `/scalar`, `+=`, `-=`, `*=(Quat)`, `*=`, `/=`, unary `-`

**Static constructors:**
- `identity()` -- identity quaternion
- `rotation(Vector3, Vector3)` -- rotation between two unit vectors
- `rotation(float radians, Vector3 unitVec)` -- rotation around axis
- `rotationX(float radians)`, `rotationY(float radians)`, `rotationZ(float radians)`

**Key free functions:**

| Function | Signature | Description |
|----------|-----------|-------------|
| `conj` | `(Quat) -> Quat` | Conjugate |
| `rotate` | `(Quat, Vector3) -> Vector3` | Rotate vector by quaternion |
| `dot` | `(Quat, Quat) -> float` | Dot product |
| `norm` | `(Quat) -> float` | Norm (squared length) |
| `length` | `(Quat) -> float` | Length |
| `normalize` | `(Quat) -> Quat` | Unit quaternion |
| `lerp` | `(t, Quat, Quat) -> Quat` | Linear interpolation |
| `slerp` | `(t, Quat, Quat) -> Quat` | Spherical linear interpolation |
| `squad` | `(t, q0, q1, q2, q3) -> Quat` | Spherical quadrangle interpolation |
| `select` | `(Quat, Quat, bool) -> Quat` | Conditional select |
| `loadXYZW` | `(Quat&, float*) -> void` | Load from 4 floats |
| `storeXYZW` | `(Quat, float*) -> void` | Store to 4 floats |

---

### 1.5 Matrix3

| Member | Type | Description |
|--------|------|-------------|
| `mCol0` | `Vector3` | Column 0 |
| `mCol1` | `Vector3` | Column 1 |
| `mCol2` | `Vector3` | Column 2 |

48 bytes (3x Vector3). Column-major storage.

**Constructors:**
- `Matrix3()` -- no init
- `Matrix3(const Matrix3&)` -- copy
- `Matrix3(Vector3, Vector3, Vector3)` -- from 3 columns
- `Matrix3(const Quat&)` -- explicit, from unit quaternion
- `Matrix3(float scalar)` -- explicit, broadcast

**Operators:** `+`, `-`, unary `-`, `*scalar`, `*(Vector3)` (matrix-vector multiply), `*(Matrix3)`, `+=`, `-=`, `*=`, `*=(Matrix3)`

**Static constructors:**
- `identity()` -- 3x3 identity
- `rotationX(float radians)`, `rotationY(float radians)`, `rotationZ(float radians)`
- `rotationZYX(Vector3 radiansXYZ)` -- Euler rotation (Z-Y-X order)
- `rotation(float radians, Vector3 unitVec)` -- axis-angle
- `rotation(const Quat& unitQuat)` -- from quaternion
- `scale(Vector3 scaleVec)` -- scale matrix

**Key free functions:**

| Function | Signature | Description |
|----------|-----------|-------------|
| `appendScale` | `(Matrix3, Vector3) -> Matrix3` | Post-multiply scale (faster than create+mul) |
| `prependScale` | `(Vector3, Matrix3) -> Matrix3` | Pre-multiply scale |
| `mulPerElem` | `(Matrix3, Matrix3) -> Matrix3` | Component-wise multiply |
| `absPerElem` | `(Matrix3) -> Matrix3` | Component-wise abs |
| `transpose` | `(Matrix3) -> Matrix3` | Transpose |
| `inverse` | `(Matrix3) -> Matrix3` | Inverse (undefined if det ~0) |
| `determinant` | `(Matrix3) -> float` | Determinant |
| `select` | `(Matrix3, Matrix3, bool) -> Matrix3` | Conditional select |

**Column/row access:** `getCol0/1/2`, `setCol0/1/2`, `getCol(int)`, `setCol(int, Vector3)`, `getRow(int)`, `setRow(int, Vector3)`, `getElem(col, row)`, `setElem(col, row, float)`, `operator[](col)`, `setCol/setRow`.

---

### 1.6 Matrix4

| Member | Type | Description |
|--------|------|-------------|
| `mCol0` | `Vector4` | Column 0 |
| `mCol1` | `Vector4` | Column 1 |
| `mCol2` | `Vector4` | Column 2 |
| `mCol3` | `Vector4` | Column 3 |

64 bytes (4x Vector4). Column-major storage.

**Constructors:**
- `Matrix4()` -- no init
- `Matrix4(const Matrix4&)` -- copy
- `Matrix4(Vector4, Vector4, Vector4, Vector4)` -- from 4 columns
- `Matrix4(const Transform3&)` -- explicit, from 3x4 transform
- `Matrix4(const Matrix3&, const Vector3& translateVec)` -- rotation + translation
- `Matrix4(const Quat&, const Vector3& translateVec)` -- quaternion + translation
- `Matrix4(float scalar)` -- explicit, broadcast

**Operators:** `+`, `-`, unary `-`, `*scalar`, `*(Vector4)`, `*(Vector3)`, `*(Point3)`, `*(Matrix4)`, `*(Transform3)`, `+=`, `-=`, `*=`, `*=(Matrix4)`, `*=(Transform3)`

**Static constructors:**
- `identity()` -- 4x4 identity
- `rotationX(float radians)`, `rotationY(float radians)`, `rotationZ(float radians)`
- `rotationZYX(Vector3 radiansXYZ)` -- Euler rotation
- `rotation(float radians, Vector3 unitVec)` -- axis-angle
- `rotation(const Quat& unitQuat)` -- from quaternion
- `scale(Vector3 scaleVec)` -- scale matrix
- `translation(Vector3 translateVec)` -- translation matrix
- `lookAt(Point3 eyePos, Point3 lookAtPos, Vector3 upVec)` -- view matrix
- `perspective(float fovyRadians, float aspect, float zNear, float zFar)` -- perspective projection
- `frustum(float left, float right, float bottom, float top, float zNear, float zFar)` -- frustum projection
- `orthographic(float left, float right, float bottom, float top, float zNear, float zFar)` -- orthographic projection

**Key free functions:**

| Function | Signature | Description |
|----------|-----------|-------------|
| `appendScale` | `(Matrix4, Vector3) -> Matrix4` | Post-multiply scale |
| `prependScale` | `(Vector3, Matrix4) -> Matrix4` | Pre-multiply scale |
| `mulPerElem` | `(Matrix4, Matrix4) -> Matrix4` | Component-wise multiply |
| `absPerElem` | `(Matrix4) -> Matrix4` | Component-wise abs |
| `transpose` | `(Matrix4) -> Matrix4` | Transpose |
| `inverse` | `(Matrix4) -> Matrix4` | General inverse (undefined if det ~0) |
| `affineInverse` | `(Matrix4) -> Matrix4` | Affine inverse (faster, row3 = [0,0,0,1]) |
| `orthoInverse` | `(Matrix4) -> Matrix4` | Orthogonal inverse (faster, upper 3x3 is orthonormal) |
| `determinant` | `(Matrix4) -> float` | Determinant |
| `select` | `(Matrix4, Matrix4, bool) -> Matrix4` | Conditional select |

**Submatrix access:** `getUpper3x3()`, `setUpper3x3(Matrix3)`, `getTranslation()`, `setTranslation(Vector3)`.

---

### 1.7 Transform3 (3x4 transformation matrix)

| Member | Type | Description |
|--------|------|-------------|
| `mCol0` | `Vector3` | Column 0 (right) |
| `mCol1` | `Vector3` | Column 1 (up) |
| `mCol2` | `Vector3` | Column 2 (forward) |
| `mCol3` | `Vector3` | Column 3 (translation) |

48 bytes (4x Vector3). Compact 3x4 matrix (no projective row).

**Constructors:**
- `Transform3()` -- no init
- `Transform3(const Transform3&)` -- copy
- `Transform3(Vector3, Vector3, Vector3, Vector3)` -- from 4 columns
- `Transform3(const Matrix3&, const Vector3&)` -- rotation + translation
- `Transform3(const Quat&, const Vector3&)` -- quaternion + translation
- `Transform3(float scalar)` -- explicit, broadcast

**Operators:** `*(Vector3)` (rotate direction), `*(Point3)` (transform point), `*(Transform3)`, `*=(Transform3)`

**Static constructors:** `identity()`, `rotationX/Y/Z(float)`, `rotationZYX(Vector3)`, `rotation(float, Vector3)`, `rotation(Quat)`, `scale(Vector3)`, `translation(Vector3)`

**Key free functions:** `appendScale`, `prependScale`, `mulPerElem`, `absPerElem`, `inverse`, `orthoInverse`, `select`.

---

## 2 -- PostProcessing Module

All classes in `Phyre::PPostProcessing` namespace. Each platform-specific class uses `PHYRE_RENDERING_PLATFORM_IMPLEMENTATION()` macro pattern (GCM/GXM/GL variants included in platform headers).

### 2.1 PPostProcessUtils (utility, no members)

Static utility class for common post-processing operations.

| Method | Signature | Description |
|--------|-----------|-------------|
| `CreateFullscreenMeshInstance` | `(PCluster&) -> PMeshInstance*` | Full-screen quad for post-process passes |
| `CreateRenderTarget` | `(PCluster&, width, height, PTextureFormat, PTextureMemoryType, MSAA mode, PResult*) -> PRenderTarget*` | Render target factory |
| `CreateTexture` | `(PCluster&, width, height, PTextureFormat, PTextureMemoryType, PResult*) -> PTexture2D*` | Texture factory |
| `CreateSphereMeshInstance` | `(PCluster&, subdivisions) -> PMeshInstance*` | Sphere mesh for deferred lights |
| `CreateConeMeshInstance` | `(PCluster&, subdivisions) -> PMeshInstance*` | Cone mesh for spot lights |
| `ResizeRenderTarget` | `(PRenderTarget*, width, height) -> PResult` | Resize an existing render target |

---

### 2.2 PDeferredLightingBase / PDeferredLighting

The most complex post-processing class. Implements deferred lighting pipeline.

**Constants:**
- `PD_MAX_DEFERRED_LIGHTS = 128`

**Enums:**
- `PDeferredLightType`: `PE_DEFERRED_LIGHT_TYPE_POINT`, `PE_DEFERRED_LIGHT_TYPE_DIRECTIONAL`, `PE_DEFERRED_LIGHT_TYPE_SPOT`
- `PDeferredRenderMode`: `PE_DEFERRED_RENDER_MODE_UNKNOWN`, `PE_DEFERRED_RENDER_MODE_LIGHT_PREPASS`, `PE_DEFERRED_RENDER_MODE_DEFERRED_LIGHTING`, `PE_DEFERRED_RENDER_MODE_DEFERRED_RENDER`

#### PDeferredLightingBase::PLight (nested class)

| Member | Type | Description |
|--------|------|-------------|
| `m_localToWorldMatrix` | `PMatrix4x3` | Light transform |
| `m_color` | `Vector4` | Light color (RGBA) |
| `m_shadowColor` | `Vector4` | Shadow color |
| `m_lightType` | `PDeferredLightType` | Point / Directional / Spot |
| `m_attenuationRadiusInner` | `float` | Inner attenuation distance |
| `m_attenuationRadiusOuter` | `float` | Outer attenuation distance |
| `m_spotAttenuationInner` | `float` | Spot inner attenuation |
| `m_spotAttenuationOuter` | `float` | Spot outer attenuation |
| `m_shadowsEnabled` | `PUInt32` | Shadows enabled flag |
| `m_shadowBufferChannelIndex` | `PUInt32` | Channel in shadow render target |
| `m_shadowAlpha` | `float` | Shadow alpha blend |
| `m_distanceToCamera` | `float` | Distance from light to camera |
| `m_light` | `PLight*` | Engine light reference |

#### PDeferredLightingBase member variables

| Member | Type | Description |
|--------|------|-------------|
| `m_deferredLights[128]` | `PLight[128]` | Deferred light array |
| `m_globalLight` | `PLight` | Global directional light |
| `m_ambientColor` | `Vector4` | Global ambient light color |
| `m_fogColor` | `Vector3` | Fog color |
| `m_fogDistance` | `float` | Fog full-attenuation distance |
| `m_fogNearDistance` | `float` | Fog start distance |
| `m_fogAmount` | `float` | Fog blend amount |
| `m_averageLuminance` | `float` | Current average luminance |
| `m_eyeAdaptionRate` | `float` | Eye adaptation rate |
| `m_eyeAdaptionLuminanceScale` | `float` | Eye adaptation luminance scale |
| `m_numLights` | `PUInt32` | Number of active deferred lights |
| `m_deferredRenderMode` | `PDeferredRenderMode` | Active rendering mode |
| `m_deferredLightingMaterial` | `PMaterial*` | Deferred lighting material |
| `m_fullscreenMeshInstance` | `PMeshInstance*` | Full-screen quad |
| `m_pointLightMeshInstance` | `PMeshInstance*` | Point light volume mesh |
| `m_spotLightMeshInstance` | `PMeshInstance*` | Spot light volume mesh |
| `m_normalDepthBufferParam` | `PShaderParameterDefinition*` | Normal depth buffer param |
| `m_depthBufferParam` | `PShaderParameterDefinition*` | Depth buffer param |
| `m_lightWorldMatrixParam` | `PShaderParameterDefinition*` | Light world matrix param |
| `m_shadowMapParam` | `PShaderParameterDefinition*` | Shadow map param |
| `m_shadowTransformParam` | `PShaderParameterDefinition*` | Shadow transform param |
| `m_shadowAlphaParam` | `PShaderParameterDefinition*` | Shadow alpha param |
| `m_invProjXYParam` | `PShaderParameterDefinition*` | Inverse projection XY param |

**PDeferredLighting (platform implementation):**
- `initializeLightPrePass(cluster, w, h, aaType)` / `initializeDeferredLighting(...)` / `initializeDeferredRender(...)`
- `renderLightPrePass(renderer, camera)` / `renderDeferredLighting(...)` / `renderDeferredRender(...)`
- `beginRenderGBuffers(renderer)` / `endRenderGBuffers(renderer)`
- `getColorBuffer()`, `getNormalDepthBuffer()`, `getShadowBuffer()`, `getDepthBuffer()`, `getOutputBuffer()`

---

### 2.3 PDepthOfFieldBase / PDepthOfField

**Constants:**
- `PE_DOF_MAX_KERNEL_SIZE = 7`
- `PE_NUM_DOWNSAMPLE_RENDER_TARGETS = 3`

**Scene render passes:** `DownsampleColorBuffer`

#### PDepthOfFieldBase member variables

| Member | Type | Description |
|--------|------|-------------|
| `m_focusPlaneDistance` | `float` | Focus plane distance |
| `m_focusRange` | `float` | Focus range |
| `m_focusBlurRange` | `float` | Focus blur range |
| `m_gaussianWeights1d[7]` | `float[7]` | 1D separable gaussian weights |
| `m_gaussianBlurOffsets[7]` | `float[7]` | 1D blur offsets (no center) |
| `m_gaussianBlurOffsets2[7]` | `float[7]` | 1D blur offsets (with center) |
| `m_gausUvs[49]` | `Vector4[49]` | 2D gaussian kernel texture coords |
| `m_gausSampleDistances[49]` | `float[49]` | 2D gaussian sample distances |
| `m_gaussianWeights2d[49]` | `float[49]` | 2D gaussian sample weights |
| `m_gausWeightVec` | `Vector4` | Separable weights as Vector4 |
| `m_gaussianUvsX[7]` | `Vector4[7]` | Horizontal blur UVs |
| `m_gaussianUvsY[7]` | `Vector4[7]` | Vertical blur UVs |
| `m_jitterSamples[49]` | `Vector4[49]` | Jitter blur texture coords |
| `m_jitterSampleWeights[49]` | `Vector4[49]` | Jitter sample weights |
| `m_jitterSampleDistances[49]` | `Vector4[49]` | Jitter sample distances |
| `m_downsampledColorRenderTargets[3]` | `PRenderTarget*[3]` | Downsampled color RTs |
| `m_fullscreenMeshInstance` | `PMeshInstance*` | Full-screen quad |
| `m_dofMaterial` | `PMaterial*` | DOF material |
| `m_colorBufferParam` | `PShaderParameterDefinition*` | Color buffer param |
| `m_downsampleColorBufferParam` | `PShaderParameterDefinition*` | Downsampled color param |
| `m_blurredColorBufferParam` | `PShaderParameterDefinition*` | Blurred color param |
| `m_depthBufferParam` | `PShaderParameterDefinition*` | Depth buffer param |
| `m_focusBufferParam` | `PShaderParameterDefinition*` | Focus buffer param |
| `m_gaussianBlurWeightsParam` | `PShaderParameterDefinition*` | Gaussian weights param |
| `m_gaussianBlurOffsetsParam` | `PShaderParameterDefinition*` | Gaussian offsets param |
| `m_jitterSamplesParam` | `PShaderParameterDefinition*` | Jitter samples param |
| `m_jitterSampleDistancesParam` | `PShaderParameterDefinition*` | Jitter distances param |
| `m_jitterSampleWeightsParam` | `PShaderParameterDefinition*` | Jitter weights param |

**PDepthOfField (platform implementation):**
- `initialize(cluster, screenWidth, screenHeight)`
- `initializeShaders(cluster, effectVariant)`
- `render(renderer, camera, colorBuffer, depthBuffer)`
- `resize(screenWidth, screenHeight)`

---

### 2.4 PMotionBlurBase / PMotionBlur

**Constants:**
- `PE_MOTION_BLUR_MATRIX_PALETTE_SIZE = 16`

**Scene render passes:** `RenderMotionBlur`

#### PMotionBlurBase member variables

| Member | Type | Description |
|--------|------|-------------|
| `m_previousView` | `Matrix4` | Previous frame's view matrix |
| `m_previousProjection` | `Matrix4` | Previous frame's projection matrix |
| `m_screenToPreviousFrameMatrix` | `Matrix4` | Current clip-space to previous clip-space |
| `m_worldTransforms[16]` | `Matrix4[16]` | Current world transforms palette |
| `m_previousWorldTransforms[16]` | `Matrix4[16]` | Previous frame world transforms palette |
| `m_viewToPreviousViewProjectionPalette[16]` | `Matrix4[16]` | View-to-previous-VP palette |
| `m_velocityScale` | `float` | Velocity scale factor |
| `m_velocityRenderTarget` | `PRenderTarget*` | Velocity buffer RT |
| `m_fullscreenMeshInstance` | `PMeshInstance*` | Full-screen quad |
| `m_material` | `PMaterial*` | Motion blur material |
| `m_colorBufferParam` | `PShaderParameterDefinition*` | Color buffer param |
| `m_depthBufferParam` | `PShaderParameterDefinition*` | Depth buffer param |
| `m_velocityBufferParam` | `PShaderParameterDefinition*` | Velocity buffer param |
| `m_velocityScaleParam` | `PShaderParameterDefinition*` | Velocity scale param |
| `m_gaussianBlurWeightsParam` | `PShaderParameterDefinition*` | Gaussian weights param |
| `m_gaussianBlurOffsetsParam` | `PShaderParameterDefinition*` | Gaussian offsets param |
| `m_viewToPreviousViewProjectionParam` | `PShaderParameterDefinition*` | View-to-previous-VP param |
| `m_objectViewToPreviousViewProjectionParam` | `PShaderParameterDefinition*` | Object view-to-previous-VP param |

**PMotionBlur (platform implementation):**
- `initialize(cluster, w, h)`
- `initializeShaders(cluster, effect)`
- `generateVelocityBuffer(renderer, camera, depthBuffer)`
- `renderMotionBlur(renderer, target, camera, colorBuffer, depthBuffer)` -- two overloads, second accepts external velocity buffer
- `renderCameraMotionBlur(renderer, target, camera, colorBuffer, depthBuffer)`
- `resize(w, h)`

---

### 2.5 PScreenSpaceAmbientOcclusionBase / PScreenSpaceAmbientOcclusion

#### PScreenSpaceAmbientOcclusionBase member variables

| Member | Type | Description |
|--------|------|-------------|
| `m_zbias` | `float` | Z bias |
| `m_fogZScale` | `float` | Fog distance scale |
| `m_sampleMaxDistance` | `float` | Maximum sample range |
| `m_haloThreshold` | `float` | Halo reduction threshold |
| `m_zscale` | `float` | Z scale, tuned to scene size |

**PScreenSpaceAmbientOcclusion (platform implementation):**
- `initialize(cluster, w, h)`
- `initializeShaders(cluster, effect)`
- `render(renderer, camera, depthBuffer)`

---

### 2.6 PExponentialShadowBase / PExponentialShadow

#### PExponentialShadowBase member variables

| Member | Type | Description |
|--------|------|-------------|
| `m_exponentialK` | `float` | Exponential shadow map scale factor |

**PExponentialShadow (platform implementation):**
- `initialize(cluster, shadowWidth, shadowHeight)`
- `processShadowBuffer(renderer, shadowDepthBuffer)`

---

### 2.7 PVolumetricLightBase / PVolumetricLight

#### PVolumetricLightBase member variables

| Member | Type | Description |
|--------|------|-------------|
| `m_msaaMode` | `PRenderTargetMultisampleAAType` | MSAA mode |
| `m_maxRange` | `float` | Maximum depth range |
| `m_distanceAttenuationScale` | `float` | Distance attenuation scale |

**PVolumetricLight (platform implementation):** empty public interface (all inherited).

---

### 2.8 PMLAABase / PMLAA

**Scene render passes:** `RenderEdgeDetect`, `RenderEdgeLength0`, `RenderEdgeLength`, `RenderMLAA`, `RenderHorizVertMLAA`, `RenderNoMLAA`

#### PMLAABase member variables

| Member | Type | Description |
|--------|------|-------------|
| `m_edgeDetectBuffer` | `PRenderTarget*` | Edge detection RT |
| `m_edgeLengthBuffers[2]` | `PRenderTarget*[2]` | Edge length ping-pong RTs |
| `m_fullscreenMeshInstance` | `PMeshInstance*` | Full-screen quad |
| `m_material` | `PMaterial*` | MLAA material |
| `m_colorBufferParam` | `PShaderParameterDefinition*` | Color buffer param |
| `m_depthBufferParam` | `PShaderParameterDefinition*` | Depth buffer param |
| `m_edgeDetectBufferParam` | `PShaderParameterDefinition*` | Edge detect buffer param |
| `m_edgeLengthBufferParam` | `PShaderParameterDefinition*` | Edge length buffer 1 param |
| `m_edgeLengthBuffer2Param` | `PShaderParameterDefinition*` | Edge length buffer 2 param |
| `m_pixelOffsetParam` | `PShaderParameterDefinition*` | Pixel offset param |
| `m_thresholdParam` | `PShaderParameterDefinition*` | Threshold param |
| `m_tileUvTransformParam` | `PShaderParameterDefinition*` | Tile UV transform param |

**PMLAA (platform implementation):**
- `initialize(cluster, w, h)`, `initializeShaders(cluster, effect)`
- `renderMLAA(renderer, target, colorBuffer, depthBuffer)`
- `renderMLAAPrePass(renderer, depthBuffer)`
- `resize(w, h)`

---

### 2.9 PGlow

**Constants:** `PE_NUM_GLOW_STAGES = 3`

#### PGlow member variables

| Member | Type | Description |
|--------|------|-------------|
| `m_glowTargetsX[3]` | `PRenderTarget*[3]` | Horizontal blur ping-pong RTs |
| `m_glowTargetsY[3]` | `PRenderTarget*[3]` | Vertical blur ping-pong RTs |
| `m_fullscreenMeshInstance` | `PMeshInstance*` | Full-screen quad |
| `m_material` | `PMaterial*` | Glow material |
| `m_glowAmountScale` | `float` | Glow amount scale |
| `m_glowBufferParam` | `PShaderParameterDefinition*` | Glow buffer param |
| `m_gaussianOutputScaleParam` | `PShaderParameterDefinition*` | Gaussian output scale param |
| `m_gaussianBlurBufferSizeParam` | `PShaderParameterDefinition*` | Gaussian blur buffer size param |

**Methods:** `initialize(cluster, w, h)`, `initializeShaders(cluster, effectVariant)`, `resize(w, h)`, `render(renderer, target, colorBuffer)`

---

### 2.10 PMeshParticleSystemBase / PMeshParticleSystem

**Scene render passes:** `RenderParticles`

#### PMeshVertex (nested class)

| Member | Type | Description |
|--------|------|-------------|
| `m_position` | `Vector3` | Vertex position |
| `m_uv[2]` | `float[2]` | Texture coordinates |
| `m_skinWeights` | `Vector4` | Skinning weights |
| `m_skinIndices` | `PUInt32` | Skinning bone indices |
| `m_color` | `PUInt32` | Vertex color (ARGB packed) |

#### PMeshParticleData (nested class)

**Constants:** `PE_PARTICLE_MESH_MAX_BONES = 64`

| Member | Type | Description |
|--------|------|-------------|
| `m_boneTransforms[64]` | `Matrix4[64]` | Current bone transforms |
| `m_skinTransforms[64]` | `Matrix4[64]` | Skinning transforms |
| `m_previousSkinTransforms[64]` | `Matrix4[64]` | Previous frame skinning transforms |
| `m_positionData` | `PArray<Vector4,16>` | Particle positions |
| `m_uvData` | `PArray<float,16>` | Particle UVs |
| `m_colorData` | `PArray<PUInt32,16>` | Particle colors |
| `m_skinWeightData` | `PArray<Vector4,16>` | Particle skin weights |
| `m_skinIndexData` | `PArray<PUInt32,16>` | Particle skin indices |
| `m_numParticles` | `PUInt32` | Number of particles |
| `m_boneCount` | `PUInt32` | Number of bones |

#### PParticleLight (nested class)

**Constants:** `PE_PARTICLE_LIGHT_COUNT = 4`

| Member | Type | Description |
|--------|------|-------------|
| `m_position` | `Vector3` | Light position |
| `m_direction` | `Vector3` | Light direction |
| `m_color` | `Vector4` | Light color |
| `m_spotAttenuationInner` | `float` | Spot inner attenuation |
| `m_spotAttenuationOuter` | `float` | Spot outer attenuation |
| `m_distanceAttenuationInner` | `float` | Distance inner attenuation |
| `m_distanceAttenuationOuter` | `float` | Distance outer attenuation |

#### PMeshParticleSystemBase member variables

| Member | Type | Description |
|--------|------|-------------|
| `m_meshInstanceParticles` | `PMeshParticleData` | Particle data |
| `m_sourceMeshInstance` | `PMeshInstance*` | Source mesh to particleize |
| `m_particleMeshInstance` | `PMeshInstance*` | Output particle mesh |
| `m_material` | `PMaterial*` | Particle material |
| `m_colorTextureParam` | `PShaderParameterDefinition*` | Color texture param |
| `m_meshColorTextureParam` | `PShaderParameterDefinition*` | Mesh color texture param |
| `m_particleColorParam` | `PShaderParameterDefinition*` | Particle color param |
| `m_meshColorTexture` | `PTexture2D*` | Color texture from mesh |
| `m_particleLights[4]` | `PParticleLight[4]` | Particle lights |
| `m_ambientColor` | `Vector4` | Ambient light color |
| `m_explodeWeight` | `float` | Explosion weight |
| `m_respawnRequired` | `PUInt32` | Respawn flag |
| `m_centerPosition` | `Vector3` | Center position |

---

### 2.11 PDXTBase / PDXT / PDXTCompress

**PDXTBase:** empty base class.

**PDXT (platform):**
- `compressTexture(PTexture2D out, PTexture2D in, renderer)`
- `compressTexture(PTexture3D out, PTexture3D in, renderer)`
- `compressTexture(PTextureCubeMap out, PTextureCubeMap in, renderer)`

**PDXTCompress (CPU fallback, too slow for real-time):**
- `CompressTexture(output, input, alphaThreshold=0.5f, computePrincipleAxis=true)` -- 2D, CubeMap, 3D overloads
- `CompressImageData(outputData, inputData, w, h, stride, format, alphaThreshold, computePrincipleAxis)`
- `CompressVolumeImageData(outputData, inputData, w, h, depth, format, alphaThreshold, computePrincipleAxis)`

---

### 2.12 PUtilityPostProcessing

Initialization/termination wrapper for the post-processing module. Registers itself with the Phyre utility system.

---

## 3 -- ShadowCaster & ShadowRenderer

Source: `Include/Rendering/PhyreShadowCaster.h` and `PhyreShadowRenderer.h`

### 3.1 PShadowCasterType

| Member | Type | Description |
|--------|------|-------------|
| `m_mask` | `PUInt32` | Bitmask for this shadow type |
| `m_maskBitID` | `PUInt32` | ID of the bit in the mask |

**Static:** `s_shadowCasterTypes[32]` -- registry of up to 32 shadow types.

**Built-in types:** `NoShadow`, `PCFShadowMap`, `CascadedShadowMap`, `CombinedCascadedShadowMap`

### 3.2 PShadowCaster

**Constants:** `PE_SHADOW_CASTER_MAX_SPLITS = 4`

#### PShadowViewport (nested)

| Member | Type | Description |
|--------|------|-------------|
| `m_x0` | `PUInt32` | Min X |
| `m_y0` | `PUInt32` | Min Y |
| `m_width` | `PUInt32` | Width |
| `m_height` | `PUInt32` | Height |

#### PShadowSplit (nested, extends PBase)

| Member | Type | Description |
|--------|------|-------------|
| `m_projectionMatrix` | `Matrix4` | Shadow projection |
| `m_viewProjectionMatrix` | `Matrix4` | Shadow view-projection |
| `m_shadowMapMatrix` | `Matrix4` | Shadow map texture matrix |
| `m_renderTarget` | `PRenderTarget*` | Render target for this split |
| `m_farPlane` | `float` | Far distance of split |
| `m_viewport` | `PShadowViewport` | Viewport |

#### PShadowCaster member variables

| Member | Type | Description |
|--------|------|-------------|
| `m_light` | `const PLight*` | Attached light |
| `m_shadowCasterType` | `const PShadowCasterType*` | Shadow type |
| `m_splits` | `PArray<PShadowSplit>` | Shadow splits array |
| `m_viewMatrix` | `PMatrix4x3` | Shadow view matrix |
| `m_zbias` | `float` | Z bias |

**Key methods:** `setLight(light, type, splitCount)`, `updateTransforms(camera)`, `getProjectionMatrix(split)`, `getViewProjectionMatrix(split)`, `getShadowMapMatrix(split)`, `getSplitDistances() -> Vector4`.

### 3.3 PShadowRenderer / PForwardShadowRenderer / PDeferredShadowRenderer

**PShadowRenderer (base):**
- `m_renderTargets` -- `PArray<PRenderTarget*>` shadow map pool
- `renderShadowsForCaster(caster, cluster, renderer, rendererGroup, camera)` -- three overloads (cluster, world, OBL)
- `AllocateShadowRenderTarget(cluster, size) -> PRenderTarget*`

**PForwardShadowRenderer (extends PShadowRenderer):**
- `updateShadowCasters(cluster/world, camera)`
- `renderShadowsForCluster(cluster, renderer, rendererGroup, camera)`
- `renderShadowsForWorld(world, renderer, rendererGroup, camera)`

**PDeferredShadowRenderer (extends PShadowRenderer):**
- `m_allocatedShadowMapCount` -- `PUInt32`
- `beginUpdate()`
- `allocateShadowMapsToShadowCaster(caster, camera)`
- `allocateShadowCastersToPackedShadowMap(casters, count, camera)`
- `renderShadowCastersToPackedShadowMap(casters, count, obl, renderer, rendererGroup, camera)`

---

## 4 -- OccluderGeometry

Source: `Include/OccluderGeometry/*.h`

### 4.1 POccluderGeometryObject (extends PBase, 16-byte aligned)

Packed block of planes, vertices and edges for occlusion testing.

| Member | Type | Description |
|--------|------|-------------|
| `m_planeCount` | `PUInt32` | Number of planes |
| `m_vertexCount` | `PUInt32` | Number of vertices |
| `m_edgeCount` | `PUInt32` | Number of edges |
| `m_pad` | `PUInt32` | Alignment padding |
| `m_minBounds` | `Vector3` | AABB minimum |
| `m_maxBounds` | `Vector3` | AABB maximum |

After the header, packed arrays follow in memory:
1. Plane matrices: `Matrix4[ceil(planeCount/4)]` -- planes grouped 4 per matrix, transposed
2. Vertex positions: `Point3[vertexCount]`
3. Edge-planes: `PUInt8[edgeCount * 2]` -- pairs of plane indices
4. Edge-vertices: `PUInt8[edgeCount * 2]` -- pairs of vertex indices

**Methods:** `getPlanes()`, `getVertices()`, `getEdgePlanes()`, `getEdgeVertices()`, `CreateOccluderGeometryObject(cluster, planeCount, vertexCount, edgeCount)`, `CreateOccluderFromShape(cluster, PShape, tolerance)`.

### 4.2 POccluderGeometryInstance (extends PBase)

| Member | Type | Description |
|--------|------|-------------|
| `m_occluder` | `PReference<const POccluderGeometryObject>` | The occluder geometry |
| `m_localToWorldMatrix` | `PWorldMatrix*` | World placement |

**Methods:** `calculatePlanesForView(camera, matrices, backPlane) -> Matrix4*`.

### 4.3 POccluderSelectionData

Planes-based occluder selection and visibility testing data. Contains the frustum planes extracted from selected occluders.

**Constants:**
- `PHYRE_MAX_OCCLUDERS = 4`
- `PHYRE_MAX_PLANES_PER_OCCLUDER = 3`

| Member | Type | Description |
|--------|------|-------------|
| `m_occluderPlaneCount[4]` | `PUInt32[4]` | Plane count per occluder |
| `m_occluderPlanes[12]` | `Matrix4[12]` | Occluder frustum planes (3 matrices per occluder) |
| `m_occluderBackPlanes[4]` | `Matrix4[4]` | Back planes per occluder |

**Static clip methods:**
- `Clip(planes, planesEnd, backPlane, boundsMin, boundsSize, globalMatrix) -> PUInt32` -- AABB clip
- `Clip(planes, planesEnd, backPlane, spherePosition, sphereRadius) -> PUInt32` -- Sphere clip
- `Clip(planes, planesEnd, backPlane, conePosition, coneDirection, coneLength, coneBaseRadius) -> PUInt32` -- Cone clip

**Inline visibility tests:**
- `testOccludersForVisibility(boundsMin, boundsSize, globalMatrix) -> bool` -- AABB test
- `testOccludersForVisibility(spherePosition, sphereRadius) -> bool` -- Sphere test
- `testOccludersForVisibility(conePosition, coneDirection, coneRadius, coneAngle) -> bool` -- Cone test

Returns `false` = object IS visible (not occluded). Returns `true` = object is occluded.

### 4.4 PSortedOccluder

| Member | Type | Description |
|--------|------|-------------|
| `m_occluder` | `const POccluderGeometryInstance*` | The occluder instance |
| `m_lod` | `float` | LOD/screen coverage value |

Sorted descending by `m_lod` (largest coverage first).

### 4.5 POccluderSelectionDebugData (16-byte aligned)

| Member | Type | Description |
|--------|------|-------------|
| `m_debugEdgeBuffer` | `Vector4*` | Debug edge visualization buffer |
| `m_debugEdgeCount` | `PAtomicType` | Current edge count (atomic) |
| `m_debugMaxEdgeCount` | `PUInt32` | Max edges in buffer |

**Methods:** `addEdge(Point3 e0, Point3 e1, Vector3 planeNormal)`.

### 4.6 POccluderSelection (static utility)

- `SelectOccluders(sortedOccluders, occluders, count, stride, camera, visibilityCheckLine) -> void*`
- `GetPlanesForBestOccluders(selectionData, occluders, count, camera)`
- `SyncSelectOccluders(void* sync)`
- `SetDebugEdgeBuffer(Vector4* edgeBuffer, PUInt32 edgeCount)`
- `s_occluderDebugData` -- static debug data instance

### 4.7 PUtilityOccluderGeometry (extends PUtility)

Initialization utility for the occluder geometry system.

| Member | Type | Description |
|--------|------|-------------|
| `s_cluster` | `PCluster` (static) | Internal cluster |
| `s_occluderCubeReference` | `PAssetReference*` (static) | Reference to default occluder cube asset |

**Methods:** `GetOccluderCubeReference() -> PAssetReference*`.

---

## 5 -- Mapping to FFX.exe Post-Processing

The PhyreEngine post-processing pipeline directly maps to FFX HD rendering:

| PhyreEngine Class | FFX.exe Usage |
|-------------------|---------------|
| `PDeferredLighting` | Main lighting pass -- FFX uses deferred lighting mode with up to 128 lights, fog, eye adaptation |
| `PDepthOfField` | DoF blur in battle arenas (Tidus/Auron limit break camera effects) |
| `PMotionBlur` | Camera motion blur, matrix palette supports 16 animated objects |
| `PExponentialShadow` | Exponential shadow map processing for cascaded shadows |
| `PShadowCaster` | Cascaded shadow maps (4 splits max) for directional lights |
| `PShadowRenderer` | Shadow map rendering pipeline (forward + deferred) |
| `PMLAA` | Morphological anti-aliasing (MLAA, predecessor to SMAA) |
| `PGlow` | Bloom/glow effect with 3-stage downsample/upsample |
| `PScreenSpaceAmbientOcclusion` | SSAO with configurable bias, fog, sample range |
| `PVolumetricLight` | Volumetric light scattering |
| `PMeshParticleSystem` | Mesh-based particle effects (up to 64 bones, 4 lights) |
| `PDXT` | Runtime DXT texture compression |
| `POccluderGeometry*` | Frustum-based occlusion culling (up to 4 occluders, 3 planes each) |

The Vectormath library (`Matrix4`, `Vector4`, `Quat`, `Transform3`) is the backbone of all transform math in FFX.exe -- every bone, camera, light, and projection uses these types. The 3x4 `Transform3` is used for skinning/bone transforms where the projective row is unnecessary.
