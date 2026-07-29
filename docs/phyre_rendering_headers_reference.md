# PhyreEngine SDK 3.1.5.0 -- Rendering + Physics Headers Reference

**Source:** `EnginesExtras/Phyre_Engine/Phyre Engine/Include/Rendering/` and `Physics/`
**SDK Version:** PhyreEngine Package 3.1.5.0, Copyright (C) 2011 Sony Computer Entertainment Inc.
**Relevance to FFX.exe:** The FFX.exe PC port uses PhyreEngine 3.9.0.0 (a later revision of the same 3.x line). The Rendering subsystem drives all `.ftc` (texture cache), `.mgrp` (model group), `.phyre` (shader/effect), and `.mesh` asset loading. The Physics subsystem is present but FFX.exe primarily uses its own physics for battle/field (no Phyre Physics observed in decomp).
**Platform backends covered:** Generic (cross-platform), GCM (PS3), GXM (Vita), GL (OpenGL), D3D11 (PC/Win), Null (tool/test). **FFX.exe PC uses D3D11.**

---

## Table of Contents

1. [Inheritance Hierarchy](#1-inheritance-hierarchy)
2. [PTexelFormatType -- Texture Format Enumeration](#2-ptexelformattype)
3. [PSamplerState -- Sampler State](#3-psamplerstate)
4. [PTextureCommonBase / PTexture2DBase -- 2D Textures](#4-ptexturecommonbase-ptexture2dbase)
5. [PTextureCubeMapBase -- Cube Map Textures](#5-ptexturecubemapbase)
6. [PTexture3DBase -- 3D Textures](#6-ptexture3dbase)
7. [PTextureFormatBase -- Format Metadata](#7-ptextureformatbase)
8. [PRenderTargetBase -- Render Targets](#8-PRenderTargetBase)
9. [PRenderSurface / PDefaultRenderSurface](#9-PRenderSurface-PDefaultRenderSurface)
10. [PShaderPassParameterLocationTypes](#10-pshaderpassparameterlocationtypes)
11. [PShaderPassStateBase / PShaderPassBase](#11-pshaderpassstatebase-pshaderpassbase)
12. [PShaderParameterCaptureBuffer*](#12-pshaderparametercapturebuffer)
13. [PShaderProgramBase / PShaderVertexProgram / PShaderFragmentProgram](#13-pshaderprogrambase)
14. [PShaderSource / PShaderProgramParamsAndStreams](#14-pshadersource)
15. [PShaderParameterDefinition](#15-pshaderparameterdefinition)
16. [PShaderParameter Capture Buffer Location Classes](#16-pshaderparametercapturebufferlocation)
17. [PShader -- Complete Shader](#17-pshader)
18. [PEffect -- Effect (CgFX)](#18-peffect)
19. [PEffectVariant -- Material Switch Variant](#19-peffectvariant)
20. [PMaterialSwitch / PMaterial](#20-pmaterialswitch-pmaterial)
21. [PParameterBuffer -- Material Parameter Storage](#21-pparameterbuffer)
22. [PSceneRenderPass / PSceneRenderPassType](#22-pscenerenderpass)
23. [PShaderPassInfo / PContextVariantFoldingTable](#23-pshaderpassinfo)
24. [PNodeContext / PNodeContextBuilder](#24-pnodecontext)
25. [PContextSwitch and Derived](#25-pcontextswitch)
26. [PSceneContext / PMeshSegmentContext](#26-pscenecontext-pmeshsegmentcontext)
27. [PMeshInstanceSegmentStreamBinding / PMeshInstanceSegmentContext](#27-pmeshinstancesegmentcontext)
28. [PMeshInstanceRenderContext / PMeshInstanceRenderMaterialContext](#28-pmeshinstancerendercontext)
29. [PMeshInstance](#29-pmeshinstance)
30. [PDynamicMeshInstance](#30-pdynamicmeshinstance)
31. [PMeshInstanceBounds / PBoundsAggregator](#31-pmeshinstancebounds)
32. [PDeferredPushBuffer / PRenderInterfaceGateInfo](#32-pdeferredpushbuffer)
33. [PRenderInterfaceBase / PRenderInterface](#33-prenderinterface)
34. [PRenderMarkerBlock / PRenderInterfaceLock](#34-prendermarkerblock)
35. [PRendererBase / PRendererForJobs / PRenderer](#35-prendererbase)
36. [PRenderer::PRendererGroup](#36-prenderergroup)
37. [PMeshInstanceThreadedRenderState](#37-pmeshinstancethreadedrenderstate)
38. [PRenderTargetConfig](#38-prendertargetconfig)
39. [PRenderRingBuffer / PRenderRingBufferSegmented](#39-prenderringbuffer)
40. [PSceneWideParameters](#40-pscenewideparameters)
41. [PLight / PLightType](#41-plight)
42. [PShadowCaster / PShadowSplit / PShadowCasterType](#42-pshadowcaster)
43. [PShadowRenderer / PForwardShadowRenderer / PDeferredShadowRenderer](#43-pshadowrenderer)
44. [PVisibilityCheck](#44-pvisibilitycheck)
45. [PShaderContextBase / PShaderContext](#45-pshadercontext)
46. [PCgProgramCompilerOption](#46-pcgprogramcompileroption)
47. [Physics -- PPhysicsMaterial](#47-pphysicsmaterial)
48. [Physics -- PPhysicsShapeBase + Derived Shapes](#48-pphysicsshapebase)
49. [Physics -- PPhysicsRigidBodyBase / PPhysicsRigidBody](#49-pphysicsrigidbodybase)
50. [Physics -- PPhysicsModel](#50-pphysicsmodel)
51. [Physics -- PPhysicsWorldBase / PPhysicsWorld](#51-pphysicsworldbase)
52. [Physics -- PPhysicsCharacterControllerBase](#52-pphysicscharactercontrollerbase)
53. [Physics -- PPhysicsCharacterCamera](#53-pphysicscharactercamera)
54. [Physics -- PPhysicsInterface / PPhysicsInterfaceConfiguration](#54-pphysicsinterface)
55. [Physics -- PRaycastResult](#55-praycastresult)
56. [Physics -- Shape Inheritance Map](#56-physics-shape-inheritance-map)

---

## 1. Inheritance Hierarchy

### Rendering Class Tree (Base Classes)

```
PBase
  PSamplerState
    PTextureCommonBase
      PTexture2DBase --> PTexture2D_GCM/GXM/GL/D3D11/Null --> PTexture2D
      PTextureCubeMapBase --> PTextureCubeMap_GCM/GL/D3D11/Null --> PTextureCubeMap
      PTexture3DBase --> PTexture3D_GCM/GL/D3D11/Null --> PTexture3D
  PNamedSemantic<PTextureFormatBase>
    PTextureFormatBase --> PTextureFormat_GCM/GXM/GL/D3D11/Null --> PTextureFormat
  PNamedSemantic<PLightType>
    PLightType
  PNamedSemantic<PShadowCasterType>
    PShadowCasterType
  PNamedSemantic<PContextSwitch>
    PContextSwitch
      PContextSwitchLights
      PContextSwitchLODBlend
      PContextSwitchInstancing
      PContextSwitchShaderLODLevel
  PNamedSemanticDynamic<PSceneRenderPassType>
    PSceneRenderPassType
  PShader
  PShaderPassBase
    PShaderPass_GCM/GXM/GL/D3D11/Null --> PShaderPass
  PShaderPassStateBase
    PShaderPassState_GCM/D3D11/Null --> PShaderPassState
  PShaderProgramBase
    PShaderVertexProgram_GCM/GL/D3D11/Null --> PShaderVertexProgram
    PShaderFragmentProgram_GCM/GL/D3D11/Null --> PShaderFragmentProgram
  PShaderSource
  PShaderParameterDefinition
  PShaderParameterCaptureBufferLocation
    PShaderParameterCaptureBufferLocationSize
    PShaderParameterCaptureBufferLocationType
  PShaderPassParameterLocationTypes
  PShaderParameterCaptureBufferStream
  PEffect
  PEffectVariant
  PMaterialSwitch
  PMaterial
  PParameterBuffer
  PSceneRenderPass
  PShaderPassInfo
  PContextVariantFoldingTable
  PMeshSegmentContext
    PMeshInstanceSegmentContext
  PMeshInstance
  PDynamicMeshInstance
  PMeshInstanceBounds
  PLight
  PShadowCaster
    PShadowSplit
  PShadowRenderer
    PForwardShadowRenderer
    PDeferredShadowRenderer
  PNodeContext
  PRenderTargetBase
    PRenderTarget_GCM/GXM/GL/D3D11/Null --> PRenderTarget

PMemoryBase
  PRenderInterfaceBase
    PRenderInterface_GCM/GXM/GL/D3D11/Null --> PRenderInterface (singleton)
  PRendererBase
    PRendererForJobs
    PRenderer
  PSceneWideParameters (singleton)
```

### Physics Class Tree

```
PBase
  PPhysicsMaterial
  PPhysicsShapeBase (abstract)
    PPhysicsShape (platform)
      PPhysicsBoxBase --> PPhysicsBox
      PPhysicsSphereBase --> PPhysicsSphere
      PPhysicsCylinderBase --> PPhysicsCylinder
        PPhysicsCapsuleBase --> PPhysicsCapsule
      PPhysicsTaperedCylinder --> PPhysicsTaperedCapsule
      PPhysicsPlaneBase --> PPhysicsPlane
      PPhysicsMeshBase --> PPhysicsMesh
  PPhysicsRigidBodyBase (+ PSimpleListElement<PPhysicsRigidBody>)
    PPhysicsRigidBody (platform)
  PPhysicsModel (+ PSimpleListElement<PPhysicsModel>)
  PPhysicsWorldBase
    PPhysicsWorld (platform)
  PPhysicsCharacterControllerBase (+ PSimpleListElement<PPhysicsCharacterControllerBase>)
    PPhysicsCharacterController (platform)
  PPhysicsInterfaceBase (+ PInitializable)
    PPhysicsInterface (platform, singleton)
```

---

## 2. PTexelFormatType

**File:** `PhyreTexelFormat.h`
**Enum:** `Phyre::PRendering::PTexelFormatType`

| Enum Value | Index | Description | Bits/Pixel |
|---|---|---|---|
| `PE_TEXTURE_FORMAT_L8` | 0 | Single 8-bit unsigned luminance | 8 |
| `PE_TEXTURE_FORMAT_A8` | 1 | Single 8-bit unsigned alpha | 8 |
| `PE_TEXTURE_FORMAT_LA8` | 2 | Dual 8-bit (luminance+alpha) | 16 |
| `PE_TEXTURE_FORMAT_RG8` | 3 | Dual 8-bit (red+green) | 16 |
| `PE_TEXTURE_FORMAT_L16` | 4 | Single 16-bit unsigned luminance | 16 |
| `PE_TEXTURE_FORMAT_A16` | 5 | Single 16-bit unsigned alpha | 16 |
| `PE_TEXTURE_FORMAT_LA16` | 6 | Dual 16-bit | 32 |
| `PE_TEXTURE_FORMAT_RG16` | 7 | Dual 16-bit | 32 |
| `PE_TEXTURE_FORMAT_ARGB1555` | 8 | 16-bit ARGB 1:5:5:5 | 16 |
| `PE_TEXTURE_FORMAT_ARGB4444` | 9 | 16-bit ARGB 4:4:4:4 | 16 |
| `PE_TEXTURE_FORMAT_RGB565` | 10 | 16-bit RGB 5:6:5 | 16 |
| `PE_TEXTURE_FORMAT_RGBA8` | 11 | Four 8-bit unsigned | 32 |
| `PE_TEXTURE_FORMAT_ARGB8` | 12 | Four 8-bit unsigned (ARGB order) | 32 |
| `PE_TEXTURE_FORMAT_A2RGB10` | 13 | 32-bit ARGB 2:10:10:10 | 32 |
| `PE_TEXTURE_FORMAT_RGBA16` | 14 | Four 16-bit unsigned | 64 |
| `PE_TEXTURE_FORMAT_DXT1` | 15 | DXT1 compressed | 4 |
| `PE_TEXTURE_FORMAT_DXT3` | 16 | DXT3 compressed | 8 |
| `PE_TEXTURE_FORMAT_DXT5` | 17 | DXT5 compressed | 8 |
| `PE_TEXTURE_FORMAT_PVRT2` | 18 | PVRTC 2bpp | 2 |
| `PE_TEXTURE_FORMAT_PVRT4` | 19 | PVRTC 4bpp | 4 |
| `PE_TEXTURE_FORMAT_PVRTII2` | 20 | PVRTC II 2bpp | 2 |
| `PE_TEXTURE_FORMAT_PVRTII4` | 21 | PVRTC II 4bpp | 4 |
| `PE_TEXTURE_FORMAT_RGBA16F` | 22 | Four 16-bit float | 64 |
| `PE_TEXTURE_FORMAT_RGBA32F` | 23 | Four 32-bit float | 128 |
| `PE_TEXTURE_FORMAT_R16F` | 24 | Single 16-bit float | 16 |
| `PE_TEXTURE_FORMAT_L16F` | 25 | Single 16-bit float (luminance) | 16 |
| `PE_TEXTURE_FORMAT_R32F` | 26 | Single 32-bit float | 32 |
| `PE_TEXTURE_FORMAT_L32F` | 27 | Single 32-bit float (luminance) | 32 |
| `PE_TEXTURE_FORMAT_RG16F` | 28 | Two 16-bit float | 32 |
| `PE_TEXTURE_FORMAT_LA16F` | 29 | Two 16-bit float (luminance+alpha) | 32 |
| `PE_TEXTURE_FORMAT_RG32F` | 30 | Two 32-bit float | 64 |
| `PE_TEXTURE_FORMAT_LA32F` | 31 | Two 32-bit float (luminance+alpha) | 64 |
| `PE_TEXTURE_FORMAT_DEPTH16` | 32 | 16-bit depth | 16 |
| `PE_TEXTURE_FORMAT_DEPTH24` | 33 | 24-bit depth | 24 |
| `PE_TEXTURE_FORMAT_DEPTH24S8` | 34 | 24-bit depth + 8-bit stencil | 32 |
| `PE_TEXTURE_FORMAT_DEPTH32` | 35 | 32-bit depth | 32 |
| `PE_TEXTURE_FORMAT_RGBA8_64` | 36 | 32-bit mem, 64-bit on-chip (GXM) | 32/64 |
| `PE_TEXTURE_FORMAT_ARGB8_64` | 37 | 32-bit mem, 64-bit on-chip (GXM) | 32/64 |
| `PE_TEXTURE_FORMAT_YVU420P2_CSC1` | 38 | Movie playback YUV (GXM) | -- |
| `PE_TEXTURE_FORMAT_UNKNOWN` | 39 | Unknown | -- |
| `PE_TEXTURE_FORMAT_COUNT` | 40 | Total count | -- |

**FTC relevance:** FFX.exe `.ftc` files store texture data. The texel format stored in the FTC header maps 1:1 to these enum values. DXT1/DXT5/RGBA8/ARGB8 are the most common in FFX.

---

## 3. PSamplerState

**File:** `PhyreSamplerState.h`
**Size (32-bit):** ~36 bytes estimated

```
class PSamplerState : public PBase {
protected:
    PEnum<PUInt8, PSamplerStateFilterFormatType> m_minFilter;     // +0  (1 byte)
    PEnum<PUInt8, PSamplerStateFilterFormatType> m_magFilter;     // +1  (1 byte)
    PEnum<PUInt8, PSamplerStateWrapFormatType>   m_wrapS;         // +2  (1 byte)
    PEnum<PUInt8, PSamplerStateWrapFormatType>   m_wrapT;         // +3  (1 byte)
    PEnum<PUInt8, PSamplerStateWrapFormatType>   m_wrapR;         // +4  (1 byte)
    // padding to float alignment
    float  m_lodBias;                                             // +8  (4B)
    float  m_maxAnisotropy;                                       // +12 (4B)
    PUInt32 m_borderColor;                                        // +16 (4B)
    PUInt32 m_baseLevel;                                          // +20 (4B)
    PUInt32 m_maxLevel;                                           // +24 (4B)
    PUInt32 m_flags;                                              // +28 (4B)
};
```

### Enums

**PSamplerStateFilterFormatType:**
| Value | Name | Description |
|---|---|---|
| 0 | `NEAREST` | Point sampling |
| 1 | `LINEAR` | Bilinear |
| 2 | `NEAREST_MIPMAP_NEAREST` | Point + nearest mip |
| 3 | `LINEAR_MIPMAP_NEAREST` | Bilinear + nearest mip |
| 4 | `NEAREST_MIPMAP_LINEAR` | Point + linear mip |
| 5 | `LINEAR_MIPMAP_LINEAR` | Trilinear |

**PSamplerStateWrapFormatType:**
| Value | Name | Description |
|---|---|---|
| 0 | `CLAMP` | Clamp |
| 1 | `REPEAT` | Repeat (default) |
| 2 | `CLAMP_TO_EDGE` | Clamp to edge (cubemap default) |
| 3 | `CLAMP_TO_BORDER` | Clamp to border color |

---

## 4. PTextureCommonBase / PTexture2DBase

### PTextureCommonBase
**File:** `PhyreTexture.h`
**Inherits:** `PSamplerState`
**Size (32-bit):** ~32 bytes (+ PSamplerState ~36B = ~68B total)

```
class PTextureCommonBase : public PSamplerState {
protected:
    PReferenceAssignable<const PTextureFormatBase> m_format;  // +0  (4B, ptr)
    PEnum<PUInt8, PMapState>     m_mapState;                  // +4  (1B)
    PEnum<PUInt8, PTextureMemoryType> m_memoryType;           // +5  (1B)
    // padding
    PUInt32  m_currentBufferIndex;                            // +8  (4B)
    PUInt32  m_mipmapCount;                                   // +12 (4B)
    PInt32   m_textureFlags;                                  // +16 (4B)
    PRenderTargetBase *m_renderTarget;                        // +20 (4B)
};
```

**PTextureFlag:**
| Bit | Name | Description |
|---|---|---|
| 0 | `DISCARD_CONTENTS` | Internally created, don't save contents |
| 1 | `AUTOMIPMAP` | Auto-mip enabled (default) |
| 2-5 | `GAMMA_REMAP_R/G/B/A` | Per-channel gamma correction |
| 6 | `ENABLE_COMPARE` | Shadow map comparison mode |
| 7 | `ENABLE_VERTEX_TEXTURE` | Can be sampled from vertex shader |
| 8 | `IS_RENDER_TARGET` | Texture is a render target |

**PTextureMemoryType:** `VRAM=0`, `MAIN=1`, `DYNAMIC=2`

### PTexture2DBase
**File:** `PhyreTexture2D.h`
**Inherits:** `PTextureCommonBase`

```
class PTexture2DBase : public PTextureCommonBase {
protected:
    PUInt32 m_width;       // +0 after parent (4B)
    PUInt32 m_height;      // +4 (4B)
    // Nested classes:
    //   PMapResult::PMipLevel { void *m_buffer; PUInt32 m_stride; }
    //   PMapResult { PUInt32 m_flags; PMipLevel m_mips[12]; }
};
```

**FTC relevance:** Every 2D texture in `.ftc` stores width, height, mipmapCount, format, and data offset. The `m_width`/`m_height` fields correspond to the texture dimensions stored in the FTC header. `m_mipmapCount` = `log2(max(width, height))`.

---

## 5. PTextureCubeMapBase

**File:** `PhyreTextureCubemap.h`
**Inherits:** `PTextureCommonBase`

```
class PTextureCubeMapBase : public PTextureCommonBase {
protected:
    PUInt32 m_size;  // Width and height of each face (square)
    // Nested: PMapResult::PMipLevel { void *m_buffer[6]; PUInt32 m_stride; }
};
```

**PCubeMapFaceType:** `POSITIVE_X=0`, `NEGATIVE_X=1`, `POSITIVE_Y=2`, `NEGATIVE_Y=3`, `POSITIVE_Z=4`, `NEGATIVE_Z=5`, `COUNT=6`

---

## 6. PTexture3DBase

**File:** `PhyreTexture3D.h`
**Inherits:** `PTextureCommonBase`

```
class PTexture3DBase : public PTextureCommonBase {
protected:
    PUInt32 m_width;
    PUInt32 m_height;
    PUInt32 m_depth;
};
```

---

## 7. PTextureFormatBase

**File:** `PhyreTextureFormat.h`
**Inherits:** `PNamedSemantic<PTextureFormatBase>`

```
class PTextureFormatBase : public PNamedSemantic<PTextureFormatBase> {
protected:
    PTexelFormatType m_format;  // The matching texel format enum
    PUInt32 m_bitDepth;         // Total bits per pixel
    PUInt32 m_flags;            // PTextureFormatFlags bitmask
    static const PTextureFormat *s_formats[PE_TEXTURE_FORMAT_COUNT];
};
```

**PTextureFormatFlags:**
| Bit | Name | Description |
|---|---|---|
| 0 | `IS_DXT` | DXT compressed format |
| 1 | `IS_DEPTH` | Depth format |
| 2 | `IS_FLOAT` | Float format |
| 3 | `SUPPORTS_2D` | Usable as 2D texture |
| 4 | `SUPPORTS_3D` | Usable as 3D texture |
| 5 | `SUPPORTS_CUBEMAP` | Usable as cubemap |
| 6 | `SUPPORTS_RENDERTARGET2D` | Can be 2D render target |
| 7 | `SUPPORTS_RENDERTARGET3D` | Can be 3D render target |
| 8 | `SUPPORTS_RENDERTARGETCUBEMAP` | Can be cubemap render target |
| 9-14 | `HAS_RED/GREEN/BLUE/ALPHA/DEPTH/STENCIL` | Channel presence |

---

## 8. PRenderTargetBase

**File:** `PhyreRenderTarget.h`
**Inherits:** `PBase` (abstract)

```
class PRenderTargetBase : public PBase {
protected:
    union { PTexture2D *m_texture2D; PTexture3D *m_texture3D; PTextureCubeMap *m_textureCubeMap; } m_texture;
    PEnum<PUInt8, PRenderTargetTextureType>     m_textureType;     // 0=2D, 1=3D, 2=Cubemap
    PEnum<PUInt8, PRenderTargetMultisampleAAType> m_msaaType;     // MSAA level
    PInt32 m_renderTargetFlags;  // Bitwise OR of PRenderTargetFlag
};
```

**PRenderTargetMultisampleAAType:** `NONE=0`, `X2=2`, `X4=4`, `X4ROT=5`, `X6=6`, `X8=8`, `X16=16`

---

## 9. PRenderSurface / PDefaultRenderSurface

**File:** `PhyreRenderSurface.h`

```
class PRenderSurface {
protected:
    PRenderTarget *m_renderTarget;                       // +0 (4B)
    PTextureCubeMap::PCubeMapFaceType m_face;            // +4 (4B enum)
    PUInt32 m_mipLevel;                                  // +8 (4B)
    PUInt32 m_surfaceIdentifier;                         // +12 (4B)
};
// Total: ~16 bytes

class PDefaultRenderSurface : public PRenderSurface {
protected:
    PUInt32 m_width;                                     // +16 (4B)
    PUInt32 m_height;                                    // +20 (4B)
    PReferenceAssignable<const PTextureFormat> m_format; // +24 (4B)
};
// Total: ~28 bytes
```

---

## 10. PShaderPassParameterLocationTypes

**File:** `PhyreShaderPass.h`
**Inherits:** `PBase`

```
class PShaderPassParameterLocationTypes : public PBase {
public:
    PUInt16  m_parameterStart[PE_SHADER_PARAMETER_FREQUENCY_COUNT]; // [4] = 8B
    PUInt16  m_parameterCount[PE_SHADER_PARAMETER_FREQUENCY_COUNT]; // [4] = 8B
    PArray<PShaderParameterCaptureBufferLocationType> m_parameterLocations; // ~16B (PArray header)
};
```

---

## 11. PShaderPassStateBase / PShaderPassBase

### PShaderPassStateBase
**File:** `PhyreShaderPass.h`
**Inherits:** `PBase`

```
class PShaderPassStateBase : public PBase {
public:
    PUInt32 m_importantState;  // Bitfield of PShaderPassImportantStateFlags
};
```

### PShaderPassBase
```
class PShaderPassBase : public PBase {
protected:
    PShaderVertexProgram  *m_vertexProgram;          // +0 (4B)
    PShaderFragmentProgram *m_fragmentProgram;       // +4 (4B)
    PShaderPassParameterLocationTypes m_vertexParameterLocation;      // +8 (~32B)
    PShaderPassParameterLocationTypes m_fragmentParameterLocation;    // +40 (~32B)
    PShaderPassParameterLocationTypes m_vertexTexParameterLocation;   // +72 (~32B)
    PShaderPassParameterLocationTypes m_fragmentTexParameterLocation; // +104 (~32B)
    PArray<PShaderParameterCaptureBufferLocation> m_streamLocations;  // +136 (~16B)
};
```

---

## 12. PShaderParameterCaptureBuffer*

**File:** `PhyreShaderProgram.h`

```
class PShaderParameterCaptureBufferStream : public PBase {
public:
    PGeometry::PDataBlock *m_dataBlock;            // +0 (4B)
    const PGeometry::PVertexStream *m_vertexStream; // +4 (4B)
    PUInt32 m_dataBlockBufferIndex;                 // +8 (4B)
};
// Total: ~12 bytes (+ PBase vtable)

class PShaderParameterCaptureBufferTexture {
public:
    const PTextureCommonBase *m_texture;       // +0 (4B)
    PUInt32 m_textureBufferIndex;               // +4 (4B)
};
// Total: 8 bytes (no vtable)

template <class TEXTURE_TYPE>
class PShaderParameterCaptureBufferTextureOfType : public PBase {
public:
    const TEXTURE_TYPE *m_texture;              // +0 (4B)
    PUInt32 m_textureBufferIndex;               // +4 (4B)
};

// Specialized:
class PShaderParameterCaptureBufferTexture2D   : PShaderParameterCaptureBufferTextureOfType<PTexture2D>
class PShaderParameterCaptureBufferTexture3D   : PShaderParameterCaptureBufferTextureOfType<PTexture3D>
class PShaderParameterCaptureBufferTextureCubeMap : PShaderParameterCaptureBufferTextureOfType<PTextureCubeMap>
```

---

## 13. PShaderProgramBase / PShaderVertexProgram / PShaderFragmentProgram

**File:** `PhyreShaderProgram.h`

```
class PShaderProgramBase : public PBase {
    // Empty base -- platform adds actual data
};

// PShaderVertexProgram : PLATFORM_IMPL(PShaderVertexProgram) --> PShaderProgramBase
// PShaderFragmentProgram : PLATFORM_IMPL(PShaderFragmentProgram) --> PShaderProgramBase
```

**PShaderProgramProfileType:** `UNKNOWN=0`, `VERTEX=1`, `FRAGMENT=2`

---

## 14. PShaderSource

**File:** `PhyreShaderProgram.h`
**Inherits:** `PBase`

```
class PShaderSource : public PBase {
protected:
    PReference<const PString> m_code;            // Shader source code (Cg/HLSL)
    PString                   m_entry;           // Entry point name
    PArray<PString>           m_compileOptions;   // Material/context switches
    PUInt32                   m_profile;          // Cg profile enum
};
```

### PShaderProgramParamsAndStreams

```
class PShaderProgramParamsAndStreams {
public:
    PArray<PShaderStreamDefinition>     m_streamDefinitions;      // ~16B
    PArray<PShaderParameterDefinition>  m_parameterDefinitions;   // ~16B
};
```

---

## 15. PShaderParameterDefinition

**File:** `PhyreShaderParameterDefinition.h`
**Inherits:** `PBase`

```
class PShaderParameterDefinition : public PBase {
protected:
    static const PUInt16 c_lightIDShift = 13;
    static const PUInt16 c_lightIDMask = 0x7;

    PUInt16                                      m_arrayElementCount; // +0 (2B)
    PEnum<PUInt8, PShaderParameter>              m_parameterType;    // +2 (1B)
    PEnum<PUInt8, PTypeID>                       m_dataType;         // +3 (1B)
    PString                                      m_name;             // +4 (~8B, PString header)
    PShaderParameterCaptureBufferLocationSize    m_bufferLoc;        // +12 (~4B)
};
```

**PShaderParameterFrequency:**
| Value | Name | Description |
|---|---|---|
| 0 | `SCENE` | Camera, viewport, screen |
| 1 | `MATERIAL` | Per-material (textures, colors) |
| 2 | `NODE` | Per-node (transforms, skin matrices) |
| 3 | `NODE_CONTEXT` | Per-node context (lights, shadows) |

**PShaderParameter** (major values):
- Scene: `EYE_DIRECTION_WORLD_SPACE`, `EYE_POSITION_WORLD_SPACE`, `MATRIX_PROJECTION/VIEW/VIEW_INV/VIEW_INV_TRANSPOSE/VIEW_PROJECTION`, `CAMERA_NEAR/FAR/NEARFAR/FAR_MINUS_NEAR/FAR_MINUS_NEAR_INV/ASPECT_RATIO`, `VIEWPORT_WIDTH/HEIGHT/WIDTH_INV/HEIGHT_INV`, `SCREEN_WIDTH/HEIGHT/WIDTH_INV/HEIGHT_INV`, `GLOBAL_AMBIENT_COLOR`, `DITHER_NOISE_TEXTURE`
- Material: `CONSTANT`, `COLOR`, `TEXTURE2D`, `TEXTURE3D`, `TEXTURECUBE`, `CUSTOM`, `UNKNOWN`
- Node: `EYE_DIRECTION/POSITION_OBJECT_SPACE`, `MATRIX_MODEL/MODEL_VIEW/MODEL_VIEW_PROJECTION` (+ `_INV`/`_INV_TRANSPOSE`/`_TRANSPOSE` variants), `SKIN_BONE_COUNT`, `SKIN_MATRIX_ARRAY`
- Node Context: `LIGHT_COLOR/INTENSITY/COLOR_TIMES_INTENSITY/ATTENUATION/INNER_CONE_ANGLE/OUTER_CONE_ANGLE/COS_*`, `LIGHT_DIRECTION/POSITION` (OBJECT/WORD/CAMERA space), `SHADOW_TRANSFORM0..3/SHADOW_TRANSFORM_ARRAY`, `SHADOW_SPLIT_DISTANCES`, `SHADOW_MAP0..3`, `LOD_BLEND_VALUE`

---

## 16. PShaderParameterCaptureBufferLocation*

**File:** `PhyreShaderParameterDefinition.h`

```
class PShaderParameterCaptureBufferLocation : public PBase {
public:
    PUInt16 m_offset;  // Offset in capture buffer
};

class PShaderParameterCaptureBufferLocationSize : public PShaderParameterCaptureBufferLocation {
public:
    PUInt16 m_size;    // Size (top 3 bits = light ID)
};

class PShaderParameterCaptureBufferLocationType : public PShaderParameterCaptureBufferLocation {
public:
    PEnum<PUInt8, PTypeID> m_type;  // Data type
};
```

---

## 17. PShader

**File:** `PhyreShader.h`
**Inherits:** `PBase`

```
class PShader : public PBase {
protected:
    PUInt32 m_parameterBufferFrequenciesRequired;  // Bitmask of needed frequencies
public:
    PArray<PShaderPass>                    m_passes;                         // ~16B
    PArray<PShaderParameterDefinition>     m_parameterDefinitionsForPasses;  // ~16B
    PArray<PShaderStreamDefinition>        m_streamDefinitionsForPasses;     // ~16B
    PUInt32                                m_parameterBufferSize;            // +48, aligned to 16B
};
```

---

## 18. PEffect

**File:** `PhyreEffect.h`
**Inherits:** `PBase`

```
class PEffect : public PBase {
protected:
    PUInt32                          m_supportedLightMask;           // +0 (4B)
    PUInt32                          m_supportedShadowCasterMask;    // +4 (4B)
    PString                          m_effectFile;                   // +8 (~8B)
    PArray<PEffectVariant *>         m_effectVariants;               // +16 (~16B)
    PArray<const PLightType *>       m_supportedLightTypes;          // +32 (~16B)
    PArray<const PShadowCasterType *> m_supportedShadowCasterTypes;  // +48 (~16B)
    PArray<const PContextSwitch *>   m_contextSwitches;              // +64 (~16B)
    PArray<PNodeContext>             m_contextVariantSwitches;       // +80 (~16B)
    PString                          m_effectSource;                 // +96 (~8B)
    PUInt32                          m_maxLightCount;                // +104 (4B)
    PUInt32                          m_numSupportedShaderLODLevels;  // +108 (4B)
};
```

---

## 19. PEffectVariant

**File:** `PhyreEffectVariant.h`
**Inherits:** `PBase`

```
class PEffectVariant : public PBase {
protected:
    static bool s_instancesLoaded;
    static PUInt32 s_lookupTypeCount;
    PReference<const PEffect> m_effect;                                     // +0 (4B)
public:
    PArray<PMaterialSwitch>             m_switches;                         // +4 (~16B)
    PArray<PSceneRenderPass>            m_sceneRenderPasses;                // +20 (~16B)
    PArray<PSceneRenderPass *>          m_sceneRenderPassLookup;            // +36 (~16B)
    PUInt16                             m_largestShaderPassCount;           // +52 (2B)
    PArray<PShaderParameterDefinition>  m_tweakableShaderParameterDefinitions;   // +54 (~16B)
    PArray<PShaderParameterDefinition>  m_untweakableShaderParameterDefinitions; // +70 (~16B)
    PUInt16                             m_tweakableParameterBufferSize;     // +86 (2B)
    PUInt16                             m_untweakableParameterBufferSize;   // +88 (2B)
};
```

---

## 20. PMaterialSwitch / PMaterial

### PMaterialSwitch
```
class PMaterialSwitch : public PBase {
public:
    PString m_name;   // Switch name (e.g. "NORMAL_MAPPING_ENABLED")
    PString m_value;  // Switch value (e.g. "2" for MAX_TEXTURE_COUNT)
};
```

### PMaterial
```
class PMaterial : public PBase {
public:
    PReferenceAssignable<const PEffectVariant> m_effectVariant;  // +0 (4B)
    PReferenceAssignable<PParameterBuffer>     m_parameterBuffer; // +4 (4B)
    const PSceneRenderPassType *m_remapFrom;                      // +8 (4B)
    const PSceneRenderPassType *m_remapTo;                        // +12 (4B)
};
```

---

## 21. PParameterBuffer

**File:** `PhyreParameterBuffer.h`
**Inherits:** `PBase`

```
class PParameterBuffer : public PBase {
protected:
    PUInt32                                m_parameterBufferSize;            // +0 (4B)
    PReference<const PEffectVariant>       m_effectVariant;                 // +4 (4B)
    PArray<PShaderParameterDefinition>     m_tweakableShaderParameterDefinitions; // +8 (~16B)
};
```

**FTC relevance:** PParameterBuffer is the runtime equivalent of material parameter data stored in `.ftc` entries. Each material references a parameter buffer whose layout is defined by its PEffectVariant.

---

## 22. PSceneRenderPass / PSceneRenderPassType

### PSceneRenderPassType
```
class PSceneRenderPassType : public PNamedSemanticDynamic<PSceneRenderPassType> {
protected:
    PUInt32 m_lookupIndex;  // For fast lookup in effect variants
};
```

**Built-in types:** `Opaque`, `Transparent`, `Shadow`, `ZPrePass`, `DeferredRender`, `NULL`

### PSceneRenderPass
```
class PSceneRenderPass : public PBase {
public:
    PReferenceAssignable<const PSceneRenderPassType> m_passType;       // +0 (4B)
    PArray<PShader>                        m_shaders;                   // +4 (~16B)
    PArray<PShaderPassInfo>                m_entryPoints;               // +20 (~16B)
    PArray<PContextVariantFoldingTable>    m_variantsFoldingTable;      // +36 (~16B)
    PArray<PString>                        m_platforms;                 // +52 (~16B)
    bool                                   m_platformsAreInclude;        // +68 (1B)
};
```

---

## 23. PShaderPassInfo / PContextVariantFoldingTable

```
class PShaderPassInfo : public PBase {
public:
    PString m_vertexEntryPoint;     // e.g. "VP300"
    PString m_vertexProfile;        // e.g. "gp4vp"
    PString m_fragmentEntryPoint;   // e.g. "FP300"
    PString m_fragmentProfile;      // e.g. "gp4fp"
};

class PContextVariantFoldingTable : public PBase {
public:
    PUInt32 m_contextVariantIndex;   // Which variant this maps to
    PUInt32 m_contextVariantVpIndex; // VP variant mapping (for invariant VPs)
    PUInt32 m_contextVariantFpIndex; // FP variant mapping (for invariant FPs)
};
```

---

## 24. PNodeContext / PNodeContextBuilder

**File:** `PhyreNodeContext.h`

```
class PNodeContext : public PBase {
protected:
    PSharray<PUInt32> m_packedSwitches;  // Packed context switch values
};

class PNodeContextBuilder {
protected:
    PNodeContext &m_nodeContext;
    PUInt32 m_packedSwitchesCount;
};
```

---

## 25. PContextSwitch and Derived

**File:** `PhyreContextSwitch.h`

```
class PContextSwitch : public PNamedSemantic<PContextSwitch> {
protected:
    PUInt32 m_packedStateSizeInUInts;
    bool    m_isEnabled;
};

class PContextSwitchLights : public PContextSwitch { /* Light count + type packing */ };
class PContextSwitchLODBlend : public PContextSwitch { /* LOD blend value */ };
class PContextSwitchInstancing : public PContextSwitch { /* Instancing flag */ };
class PContextSwitchShaderLODLevel : public PContextSwitch { /* Shader LOD levels */ };
```

**PContextSwitchLights bit packing:**
- `PE_MAX_BITS_FOR_LIGHT_COUNT = 4`
- `PE_MAX_BITS_PER_LIGHT = 5` (light type ID)
- `PE_MAX_BITS_PER_SHADOW = 5` (shadow caster type ID)

---

## 26. PSceneContext / PMeshSegmentContext

### PSceneContext (not a PBase, POD-like)
```
class PSceneContext {
public:
    Vectormath::Aos::Vector3  m_globalAmbient;  // +0 (16B, SIMD aligned)
    PArray<const PLight *>    m_lights;          // +16 (~16B)
    const PTexture2D         *m_noiseTexture;    // +32 (4B)
};
```

### PMeshSegmentContext
```
class PMeshSegmentContext : public PBase {
public:
    const PLight *m_lights[PD_MAX_MESH_SEGMENT_LIGHT_COUNT];  // +0 (array of ptrs)
    PUInt32       m_lightCount;                                 // Count of active lights
};
```

---

## 27. PMeshInstanceSegmentStreamBinding / PMeshInstanceSegmentContext

### PMeshInstanceSegmentStreamBinding
```
class PMeshInstanceSegmentStreamBinding : public PBase {
    const PGeometry::PRenderDataType *m_renderDataType;  // Stream data type for matching
    PString m_name;          // Shader stream name
    PUInt16 m_nameHash;      // Hash of stream name
    PUInt8  m_index;         // Shader stream index
    PUInt8  m_inputSet;      // Mesh stream input set
};
```

### PMeshInstanceSegmentContext
```
class PMeshInstanceSegmentContext : public PMeshSegmentContext {
public:
    PInt32       m_shaderID;         // Shader index in effect variant
    const PEffectVariant *m_effectVariant;
protected:
    PSharray<const PMeshInstanceSegmentStreamBinding *> m_streamBindings;
};
```

---

## 28. PMeshInstanceRenderContext / PMeshInstanceRenderMaterialContext

### PMeshInstanceRenderMaterialContext
```
class PMeshInstanceRenderMaterialContext {
public:
    const PEffectVariant *m_effectVariant;  // Active effect variant
    const PShader         *m_contextShader;  // Selected context shader
};
```

### PMeshInstanceRenderContext
```
class PMeshInstanceRenderContext {
public:
    // Global
    const PCamera *m_camera;                          // Current camera
    PReferenceAssignable<const PMatrix4> m_cameraGlobalMatrix;
    PReferenceAssignable<const PMatrix4> m_cameraInverseGlobalMatrix;
    // Per mesh instance
    PReferenceAssignable<const PMeshInstance> m_meshInstance;
    const PMatrix4 *m_globalMatrices;                 // All global matrices
    const PGeometry::PMeshSegment *m_instanceMeshSegment; // Instancing source
    // Per mesh segment
    const PGeometry::PMeshSegment *m_meshSegment;     // Current segment
    PUInt32 m_meshSegmentIndex;                       // Segment index
    const PMatrix4 *m_globalMatrix;                   // Current segment matrix
    PMatrix4 m_inverseGlobalMatrix;                   // Inverse of above
    PMeshInstanceRenderMaterialContext m_material;     // Material config
};
```

---

## 29. PMeshInstance

**File:** `PhyreMeshInstance.h`
**Inherits:** `PBase`

```
class PMeshInstance : public PBase {
protected:
    PReferenceAssignable<PGeometry::PMesh>          m_mesh;              // +0 (4B)
    PWorldMatrix                                   *m_localToWorldMatrix; // +4 (4B)
    PArray<PMatrix4>                               m_currentPose;        // +8 (~16B)
    PReferenceAssignable<PGeometry::PMaterialSet>  m_materialSet;       // +24 (4B)
    PDynamicMeshInstance                           *m_dynamicMeshInstance; // +28 (4B)
    PMeshInstanceBounds                            *m_bounds;            // +32 (4B)
    PLOD::PLODLevel                                *m_lodLevel;         // +36 (4B)
    PArray<PMeshInstanceSegmentContext>             m_segmentContext;     // +40 (~16B)
};
```

**MGRP relevance:** Every `.mgrp` model group file contains mesh data that maps to PGeometry::PMesh + PMeshInstance at runtime. The m_materialSet references PMaterial objects whose parameter buffers hold the textures and shader constants. The m_currentPose array holds bone matrices for skinned meshes.

---

## 30. PDynamicMeshInstance

**File:** `PhyreDynamicMeshInstance.h`
**Inherits:** `PBase`

```
class PDynamicMeshInstance : public PBase {
protected:
    PReferenceAssignable<PGeometry::PDynamicMesh> m_dynamicMesh;
};
```

---

## 31. PMeshInstanceBounds / PBoundsAggregator

### PMeshInstanceBounds
**Size:** 16-byte aligned (`PHYRE_STRUCT_POSTALIGN(16)`)

```
class PMeshInstanceBounds : public PBase {
protected:
    float              m_min[3];         // +0  (12B)  Min bounds XYZ
    const PWorldMatrix *m_worldMatrix;   // +12 (4B)  Optional transform
    float              m_size[3];        // +16 (12B)  Size (extends from min)
    PMeshInstance      *m_meshInstance;  // +28 (4B)  Owner mesh (NULL = hidden)
};
// Total: ~32 bytes + vtable
```

### PBoundsAggregator
```
class PBoundsAggregator {
    Vectormath::Aos::Vector3 m_boundsMin;   // Current min extent
    Vectormath::Aos::Vector3 m_boundsMax;   // Current max extent
    PUInt32 m_boundsFound;                   // Number found (0 = empty)
};
```

---

## 32. PDeferredPushBuffer / PRenderInterfaceGateInfo

**File:** `PhyreRenderInterface.h`

```
class PDeferredPushBuffer {
    void *m_commands;                              // Graphics commands
    void *m_indices;                               // Indices to write
    PGeometry::PIndexDataBlock *m_indexDataBlock;  // Index data block
    PUInt32 m_indexSourceOffset;                   // Offset to index data
    PUInt32 m_indexSourceLocation;                 // Location of index data
    PUInt32 m_commandsSize;                        // Command space size
    void *m_devicePtr;                             // Device-specific state pointer
};
// Total: 7 * 4B = 28 bytes

class PRenderInterfaceGateInfo {
    PUInt32 *m_address;  // Gate address
    PUInt32 m_value;     // Value to open gate
};
```

---

## 33. PRenderInterfaceBase / PRenderInterface

### PRenderInterfaceBase
```
class PRenderInterfaceBase : public PMemoryBase {
protected:
    bool    m_allocateSystemMemoryProcessBuffers;  // +0 (1B)
    PUInt32 m_currentState;                        // +4 (4B, aligned)
    PRenderTargetConfig m_renderTargetConfig;      // +8 (~20B)
    PUInt32 m_dynamicVertexBufferSize;             // +28 (4B)
    PUInt32 m_dynamicIndexBufferSize;              // +32 (4B)
    PUInt32 m_dynamicBufferIndex;                  // +36 (4B)
    PUInt32 m_dynamicVertexBufferFillLevel;        // +40 (4B)
    PUInt32 m_dynamicIndexBufferFillLevel;         // +44 (4B)
    static PRenderSurface s_colorRenderSurface;
    static PRenderSurface s_depthStencilRenderSurface;
};
```

### PRenderInterface (Singleton)
Platform-derived. Provides:
- Scene: `beginScene`, `endScene`, `clearScene`, `flip`, `flipEye`
- Draw: `drawArrays`, `drawElements`, `drawRangeElements`, `drawArraysInstanced`, `drawElementsInstanced`
- State: `setViewport`, `setScissor`, `setClearColor`, `setClearDepth`, `setClearStencil`
- Render targets: `setColorTarget`, `setDepthStencilTarget`, `captureTexture`
- Render state: `setBlending`, `setAlpha`, `setDepth`, `setDepthMask`, `setCullFace`, `setPolygonFill`, `setPolygonOffset`, `setColorMask`, `setStencil`, `setDepthBounds`
- Dynamic buffers: `openDynamicBuffer`, `allocateDynamicDataBlocks`, `closeDynamicBuffer`
- Debug: `debugDraw`, `debugTexture`, `markerSet/Push/Pop`

---

## 34. PRenderMarkerBlock / PRenderInterfaceLock

```
class PRenderMarkerBlock {
    PHYRE_RENDERING_PLATFORM_IMPLEMENTATION(PRenderInterface) *m_renderInterface;
    // RAII: pushes marker on construction, pops on destruction
};

class PRenderInterfaceLock : protected PCriticalSectionLock {
    // RAII: acquires render interface exclusive access
    PRenderInterface &getRenderInterface() const;
};
```

---

## 35. PRendererBase / PRendererForJobs / PRenderer

### PRendererBase
```
class PRendererBase : public PMemoryBase {
protected:
    PUInt32 m_currentState;                              // PE_RENDERER_INSIDESCENE
    PUInt32 m_viewportX0, m_viewportY0;
    PUInt32 m_viewportWidth, m_viewportHeight;
    static PShaderUsageStatsManager *s_shaderUsageStats;
    const PSceneContext &m_sceneContext;
    PRenderRingBufferSegmented m_parameterCaptureRingBuffer;   // Param capture FIFO
    PRenderRingBufferSegmented m_renderCommandRingBuffer;      // Render command FIFO
    PSemaphore *m_segmentSemaphore;
    const PSceneRenderPassType *m_sceneRenderPassType;
    PFifoInterval<PInternal::PRenderCommand> m_unflushedCommandExtents;
    const PSceneWideParameters *m_sceneWideParametersDefn;
    const PParameterBuffer *m_sceneWideParameterCaptureBuffer;
    const PCamera *m_currentCamera;
    PMatrix4 m_cameraGlobalMatrix;
    PMatrix4 m_cameraInverseGlobalMatrix;
};
```

### PRenderer
```
class PRenderer : public PRendererBase {
protected:
    PSemaphore m_segmentSemaphoreInternal;
    PRenderTargetConfig m_renderTargetConfig;
public:
    class PRendererGroup {
        PArray<PUInt128>       m_rendererBuffer;   // Aligned storage
        PArray<PRendererForJobs> m_renderers;       // Worker renderers
    };
    // Key methods:
    PResult renderWorld(const PWorld &world, const PCamera &camera, PRendererGroup &group);
    PResult beginScene(PUInt32 clearMask);
    PResult endScene();
    PResult syncRender();
    PResult flip();
    PResult setColorTarget(const PRenderSurface *surface, PUInt32 index = 0);
    PResult setDepthStencilTarget(const PRenderSurface *surface);
};
```

---

## 36. PRenderer::PRendererGroup

```
class PRenderer::PRendererGroup {
public:
    PArray<PUInt128>         m_rendererBuffer;  // Aligned storage for renderers
    PArray<PRendererForJobs> m_renderers;       // Worker renderer instances
    PResult setRendererCount(PUInt32 count, const PSceneContext &sceneContext);
    void terminate();
};
```

---

## 37. PMeshInstanceThreadedRenderState

**File:** `PhyreRenderer.h`

```
class PMeshInstanceThreadedRenderState {
public:
    PMeshInstanceRenderMaterialContext m_materialContext;  // Context shader + effect variant
    PMeshSegmentContext                m_meshSegmentContext; // Light count + pointers
    const PMaterial                   *m_material;          // Material reference
};
```

---

## 38. PRenderTargetConfig

**File:** `PhyreRenderer.h`

```
class PRenderTargetConfig {
public:
    PRenderSurface m_color[4];          // Up to 4 color targets (MRT)
    PRenderSurface m_depthStencil;      // Depth/stencil target
    PUInt8 m_validColor;                // Bitmask of valid color targets
    PUInt8 m_validDepthStencil;         // 1 = depth stencil valid
};
```

---

## 39. PRenderRingBuffer / PRenderRingBufferSegmented

**File:** `PhyreRenderRingBuffer.h`

```
template <typename T>
class PFifoInterval {
public:
    T *m_start;   // Current position
    T *m_end;     // End position
};

class PRenderRingBuffer {
protected:
    PFifoInterval<void> m_extents;
    void *m_currentBufferPosition;
};

class PRenderRingBufferSegmented : public PRenderRingBuffer {
protected:
    const void *m_nextSegmentEnd;
    PUInt32 m_segmentSize;
};
```

---

## 40. PSceneWideParameters

**File:** `PhyreSceneWideParameters.h`
**Inherits:** `PMemoryBase` (singleton)

```
class PSceneWideParameters : public PMemoryBase {
protected:
    static PSceneWideParameters s_singleton;
    PArray<PShaderParameterDefinition> m_parameterDefinitions;  // Scene-wide params
    PUInt16 m_bufferSize;                                        // Buffer size for scene params
};
```

---

## 41. PLight / PLightType

### PLightType
```
class PLightType : public PNamedSemantic<PLightType> {
protected:
    PUInt32 m_mask;      // Bitmask for this light type
    PUInt32 m_maskBitID; // Bit ID in the mask
    static PLightType *s_lightTypes[32];
};
```

**Built-in types:** `PointLight`, `DirectionalLight`, `AmbientLight`, `SpotLight`

### PLight
```
class PLight : public PBase {
protected:
    Vectormath::Aos::Vector4 m_color;              // +0  (16B, RGBA)
    PWorldMatrix             *m_localToWorldMatrix; // +16 (4B)
    PShadowCaster            *m_shadowCaster;       // +20 (4B)
    const PLightType         *m_lightType;          // +24 (4B)
    float m_innerConeAngle;                         // +28 (4B)  radians
    float m_outerConeAngle;                         // +32 (4B)  radians
    float m_intensity;                              // +36 (4B)
    float m_innerRange;                             // +40 (4B)
    float m_outerRange;                             // +44 (4B)  FLT_MAX = infinite
};
```

---

## 42. PShadowCaster / PShadowSplit / PShadowCasterType

### PShadowCasterType
```
class PShadowCasterType : public PNamedSemantic<PShadowCasterType> {
    PUInt32 m_mask, m_maskBitID;
    static PShadowCasterType *s_shadowCasterTypes[32];
};
```

**Built-in:** `NoShadow`, `PCFShadowMap`, `CascadedShadowMap`, `CombinedCascadedShadowMap`

### PShadowSplit
```
class PShadowSplit : public PBase {
public:
    Vectormath::Aos::Matrix4 m_projectionMatrix;       // 64B
    Vectormath::Aos::Matrix4 m_viewProjectionMatrix;    // 64B
    Vectormath::Aos::Matrix4 m_shadowMapMatrix;         // 64B
    PRenderTarget *m_renderTarget;                       // 4B
    float m_farPlane;                                    // 4B
    PShadowViewport m_viewport;                          // {x0,y0,width,height} = 16B
};
```

### PShadowCaster
```
class PShadowCaster : public PBase {
    enum PShadowConstants { PE_SHADOW_CASTER_MAX_SPLITS = 4 };

    const PLight            *m_light;            // Attached light
    const PShadowCasterType *m_shadowCasterType;
    PArray<PShadowSplit>    m_splits;            // Shadow map splits
    PMatrix4x3              m_viewMatrix;        // View matrix for shadow
    float                   m_zbias;             // Z bias
};
```

---

## 43. PShadowRenderer / PForwardShadowRenderer / PDeferredShadowRenderer

```
class PShadowRenderer : public PBase {
protected:
    PArray<PRenderTarget *> m_renderTargets;  // Available shadow map targets
public:
    void setShadowMapCount(PUInt32 count);
    void setShadowMap(PUInt32 idx, PRenderTarget *rt);
    void renderShadowsForCaster(PShadowCaster &, const PCluster &, PRenderer &, ...);
    static PRenderTarget *AllocateShadowRenderTarget(PCluster &, PUInt32 size);
};

class PForwardShadowRenderer : public PShadowRenderer {
    void updateShadowCasters(PCluster &, const PCamera &);
    void renderShadowsForCluster(PCluster &, PRenderer &, ...);
};

class PDeferredShadowRenderer : public PShadowRenderer {
    PUInt32 m_allocatedShadowMapCount;
    void beginUpdate();
    void allocateShadowMapsToShadowCaster(PShadowCaster &, const PCamera &);
};
```

---

## 44. PVisibilityCheck

**File:** `PhyreVisibilityCheck.h`

```
class PVisibilityCheck {
protected:
    const PCamera &m_camera;
    const Vectormath::Aos::Matrix4 &m_viewProjection;
    Vectormath::Aos::Vector4 m_cameraViewZ;
    PInternal::PCheckVisibleBoundsJob *m_firstJob;
    PInternal::PVisibleMeshInstanceBlock *m_resultsBlockList;
    PInternal::PSortedOccluderInstanceBlock *m_sortedOccluderInstances;
    PInternal::PCheckVisibleBoundsJob **m_nextJobPtr;
    PInternal::PVisibleMeshInstanceBlock **m_resultsBlockListNextPtr;
    PInternal::PSortedOccluderInstanceBlock **m_sortedOccluderInstancesNextPtr;
    const Vectormath::Aos::Point3 *m_occluderVisibilityCheckLine;
    const PCamera *m_occluderVisibilityCamera;
    PPreprocessRingBufferBlock *m_selectedOccluderDataBlock;
    const POccluderGeometry::POccluderSelectionData *m_selectedOccluderData;
};
```

---

## 45. PShaderContextBase / PShaderContext

```
class PShaderContextBase {
protected:
    PRenderInterface &m_renderInterface;   // Render interface for shading
    PUInt32 m_nonApplicationState;         // State flags not in application state
};

// PShaderContext : PLATFORM_IMPL(PShaderContext) --> PShaderContextBase
// No dynamic allocation (operator new deleted)
```

---

## 46. PCgProgramCompilerOption

**File:** `PhyreCg.h`

```
class PCgProgramCompilerOption : public PSimpleListElement<PCgProgramCompilerOption> {
protected:
    const PChar *m_string;       // Compiler option string
    bool m_isProfileOption;      // Profile-specific option flag
    bool m_isEnabled;            // Active/inactive (default: true)
    class PCgProgramCompilerOptionList {
        PCgProgramCompilerOption *m_first;
        CGprofile m_profile;
    };
    static PCgProgramCompilerOptionList s_optionLists[];
};
```

---

## 47. PPhysicsMaterial

**File:** `PhyrePhysicsMaterial.h`
**Inherits:** `PBase`

```
class PPhysicsMaterial : public PBase {
protected:
    float m_dynamicFriction;  // +0 (4B)
    float m_staticFriction;   // +4 (4B)
    float m_restitution;      // +8 (4B)  (bounciness)
};
// Total: 12B + vtable(~4B) = ~16 bytes
```

---

## 48. PPhysicsShapeBase + Derived Shapes

### PPhysicsShapeBase (abstract)
```
class PPhysicsShapeBase : public PBase {
protected:
    bool    m_hollow;           // +0 (1B)
    float   m_mass;             // +4 (4B, aligned)
    float   m_density;          // +8 (4B)
    PPhysicsMaterial *m_material; // +12 (4B)
    PMatrix4x3 m_transform;     // +16 (48B, 3x4 matrix)
    Vectormath::Aos::Vector3 m_scale; // +64 (16B, SIMD aligned)
    PPhysicsShapeType m_type;   // +80 (4B enum)
};
```

**PPhysicsShapeType:** `BOX=0`, `CAPSULE=1`, `CYLINDER=2`, `PLANE=3`, `SPHERE=4`, `TAPERED_CAPSULE=5`, `TAPERED_CYLINDER=6`, `MESH=7`, `COUNT=8`

### Derived Shapes

| Shape | Class | Extra Members |
|---|---|---|
| Box | `PPhysicsBoxBase : PPhysicsShape` | `Vector3 m_halfExtents` (16B) |
| Sphere | `PPhysicsSphereBase : PPhysicsShape` | `float m_radius` (4B) |
| Cylinder | `PPhysicsCylinderBase : PPhysicsShape` | `float m_radiusArray[2]` (8B) + `float m_height` (4B) |
| Capsule | `PPhysicsCapsuleBase : PPhysicsCylinder` | Inherits cylinder (no extra) |
| Plane | `PPhysicsPlaneBase : PPhysicsShape` | `Vector4 m_equationCoefficient` (16B) |
| Mesh | `PPhysicsMeshBase : PPhysicsShape` | `PGeometry::PShape *m_shape` (4B) |
| TaperedCylinder | `PPhysicsTaperedCylinder : PPhysicsShape` | `float m_upperRadiusArray[2]` (8B) + `float m_lowerRadiusArray[2]` (8B) + `float m_height` (4B) |
| TaperedCapsule | `PPhysicsTaperedCapsule : PPhysicsTaperedCylinder` | Inherits tapered cylinder (no extra) |

---

## 49. PPhysicsRigidBodyBase / PPhysicsRigidBody

### PPhysicsRigidBodyBase
```
class PPhysicsRigidBodyBase : public PBase, public PSimpleListElement<PPhysicsRigidBody> {
protected:
    float   m_mass;                         // +0 (4B)
    bool    m_dynamic;                      // +4 (1B)
    PMatrix4x3 m_massFrameTransform;        // +8 (48B)
    Vector3 m_initialPosition;              // +56 (16B)
    Quat    m_initialOrientation;           // +72 (16B)
    Vector3 m_inertiaTensor;                // +88 (16B)
    Vector3 m_initialLinearVelocity;        // +104 (16B)
    Vector3 m_initialAngularVelocity;       // +120 (16B)
    PPhysicsMaterial *m_material;           // +136 (4B)
    PScene::PNode *m_targetNode;            // +140 (4B)
    PWorldMatrix *m_targetWorldMatrix;      // +144 (4B)
    PSharray<PPhysicsShape *> m_shapes;     // +148 (~12B)
    float m_linearDamping;                  // +160 (4B)
    float m_angularDamping;                 // +164 (4B)
    PMatrix4 m_inverseGlobalParentMatrix;   // +168 (64B)
    Vector3 m_scale;                        // +232 (16B)
    PPhysicsModel *m_model;                 // +248 (4B)
    void *m_userDataPointer;                // +252 (4B)
    PPhysicsRigidBody *m_nextKinematicRigidBody; // +256 (4B)
    PCollisionGroup m_collisionGroup;       // +260 (4B enum)
};
```

**PRigidBodyType:** `STATIC=0`, `DYNAMIC=1`, `KINEMATIC=2`, `COUNT=3`

**PCollisionGroup:** `DYNAMIC=0`, `STATIC=1`, `CHARACTER=2`, `LAYER0..11=3..14`, `COUNT=15`

---

## 50. PPhysicsModel

**File:** `PhyrePhysicsModel.h`
**Inherits:** `PBase + PSimpleListElement<PPhysicsModel>`

```
class PPhysicsModel : public PBase, public PSimpleListElement<PPhysicsModel> {
public:
    PPhysicsRigidBody *m_rigidBodies;  // Linked list of rigid bodies
    PPhysicsWorld     *m_world;        // Owning world
};
```

---

## 51. PPhysicsWorldBase / PPhysicsWorld

### PPhysicsWorldBase
```
class PPhysicsWorldBase : public PBase {
protected:
    Vector3 m_gravity;                     // +0 (16B)
    float   m_timeStep;                    // +16 (4B)
    Vector3 m_worldMin;                    // +20 (16B, broadphase min)
    Vector3 m_worldMax;                    // +36 (16B, broadphase max)
    PPhysicsStatus m_status;               // +52 (4B enum)
    PUInt32 m_submittedRayCount;           // +56 (4B)
    PUInt32 m_currentRayID;                // +60 (4B)
public:
    PPhysicsModel *m_models;                         // +64 (4B, linked list head)
    PPhysicsCharacterControllerBase *m_characterControllers; // +68 (4B)
    PPhysicsRigidBody *m_kinematicRigidBodies;       // +72 (4B, linked list head)
};
```

**PPhysicsStatus:** `ALL_SYNCED=0`, `SIMULATION_STARTED=1`, `RAYCAST_STARTED=2`

---

## 52. PPhysicsCharacterControllerBase

**File:** `PhyrePhysicsCharacterController.h`
**Inherits:** `PBase + PSimpleListElement<PPhysicsCharacterControllerBase>`

```
class PPhysicsCharacterControllerBase : public PBase, public PSimpleListElement<...> {
protected:
    Point3   mStartPosition;       // +0  (16B)
    Vector3  m_gravity;            // +16 (16B)
    PMatrix4 m_graphicsOffset;     // +32 (64B)
    PMatrix4 m_invGraphicsOffset;  // +96 (64B)
    PScene::PNode *m_targetNode;   // +160 (4B)
    PWorldMatrix *m_targetWorldMatrix; // +164 (4B)
    PPhysicsWorld *m_world;        // +168 (4B)
    float m_rotate;                // +172 (4B)
    float m_right;                 // +176 (4B)
    float m_forward;               // +180 (4B)
    float m_velocity;              // +184 (4B)
    float m_maxSlopeAngle;         // +188 (4B)
    float m_jumpHeight;            // +192 (4B)
    float m_height;                // +196 (4B, default 0.8)
    float m_radius;                // +200 (4B, default 0.6)
    bool  m_jump;                  // +204 (1B)
    bool  m_isOnGround;            // +205 (1B)
};
```

---

## 53. PPhysicsCharacterCamera

**File:** `PhyrePhysicsCharacterCamera.h`

```
class PPhysicsCharacterCamera {
protected:
    static const PUInt32 c_numCollisionTestPoints = 20;
    PPhysicsWorld *m_physicsWorld;
    float m_collisionRadius;
    float m_targetDistance;
    float m_targetHeight;
    float m_contactEpsilon;
    float m_minimumCameraDistance;
    float m_smoothingRate;
    Vector3 m_cameraTargetOffset;
    Vector3 m_cameraPosition;
    Vector3 m_cameraTarget;
    Vector3 m_collisionTestPoints[20];
};
```

---

## 54. PPhysicsInterface / PPhysicsInterfaceConfiguration

### PPhysicsInterfaceConfiguration (POD)
```
class PPhysicsInterfaceConfiguration {
    PUInt32 m_numSPUs;                // 0 by default
    bool    m_usePhyreAllocator;     // false by default
    PUInt32 m_asyncRaycastsPerFrame;  // 16 by default
};
```

### PPhysicsInterface (Singleton)
```
class PPhysicsInterfaceBase : public PInitializable, public PBase {
    PUInt32 m_numSPUs;
    PUInt32 m_asyncRaycastsPerFrame;
};
// PPhysicsInterface : PLATFORM_IMPL --> PPhysicsInterfaceBase
// Static singleton, init/terminate lifecycle
```

---

## 55. PRaycastResult

**File:** `PhyrePhysicsWorld.h`

```
class PRaycastResult {
public:
    Vector4 m_contactPoint;                  // Hit point
    Vector4 m_contactNormal;                 // Hit normal
    PBase   *m_collisionObject;              // Hit rigid body
    const PClassDescriptor *m_collisionObjectClassDescriptor;
};
```

---

## 56. Physics Shape Inheritance Map

```
PPhysicsShapeBase (abstract)
  +-- PPhysicsShape (platform layer)
        +-- PPhysicsBoxBase --> PPhysicsBox
        |     Extra: Vector3 m_halfExtents (16B)
        +-- PPhysicsSphereBase --> PPhysicsSphere
        |     Extra: float m_radius (4B)
        +-- PPhysicsCylinderBase --> PPhysicsCylinder
        |     Extra: float m_radiusArray[2] (8B) + float m_height (4B)
        |     +-- PPhysicsCapsuleBase --> PPhysicsCapsule (no extra)
        +-- PPhysicsTaperedCylinder --> PPhysicsTaperedCapsule
        |     Extra: float m_upperRadiusArray[2] + m_lowerRadiusArray[2] + m_height
        +-- PPhysicsPlaneBase --> PPhysicsPlane
        |     Extra: Vector4 m_equationCoefficient (16B)
        +-- PPhysicsMeshBase --> PPhysicsMesh
              Extra: PGeometry::PShape *m_shape (4B)
```

---

## Key Enums Summary

### Shader Blend Types
`PE_SHADER_BLEND_ZERO`, `ONE`, `SRC_COLOR`, `ONE_MINUS_SRC_COLOR`, `SRC_ALPHA`, `ONE_MINUS_SRC_ALPHA`, `DST_ALPHA`, `ONE_MINUS_DST_ALPHA`, `DST_COLOR`, `ONE_MINUS_DST_COLOR`

### Shader Function Types
`PE_SHADER_FUNC_NEVER`, `LESS`, `EQUAL`, `LESS_EQUAL`, `GREATER`, `NOT_EQUAL`, `GREATER_EQUAL`, `ALWAYS`

### Shader Cull Face
`PE_SHADER_CULL_NONE`, `CULL_FRONT`, `CULL_BACK`

### Shader Stencil Ops
`PE_SHADER_STENCIL_KEEP`, `ZERO`, `REPLACE`, `INCRSAT`, `DECRSAT`, `INVERT`, `INCR`, `DECR`

### Shader Fill Types
`PE_SHADER_FILL_POINT`, `LINE`, `SOLID`

### Shader Blend Equations
`PE_SHADER_BLEND_EQUATION_ADD`, `SUBTRACT`, `REVERSE_SUBTRACT`, `MIN`, `MAX`

---

## FFX.exe Relevance Summary

| PhyreEngine Structure | FFX.exe Binary Usage |
|---|---|
| **PTexture2D / PTextureFormat** | `.ftc` texture cache files -- every texture in FFX is loaded as PTexture2D. Format = PTexelFormatType stored in FTC header. |
| **PMeshInstance / PMaterial** | `.mgrp` model group files contain mesh segments with materials. PMaterial references PEffectVariant for shader selection. |
| **PEffect / PEffectVariant** | Shader effects compiled from CgFX. FFX uses ~200+ effects for battle, field, UI, and cutscenes. |
| **PShader / PShaderPass** | Individual shader passes within effects. Each pass has vertex + fragment programs. |
| **PParameterBuffer** | Material parameter data -- textures, colors, matrices. Each material has its own buffer. |
| **PRenderInterface** | D3D11 backend on PC. Manages render state, draw calls, render targets. Singleton. |
| **PRenderer** | Command-based renderer with ring buffers. Manages scene rendering pipeline. |
| **PRenderTarget** | Offscreen render targets for shadow maps, reflections, post-processing. |
| **PShadowCaster** | Cascaded shadow mapping. Up to 4 splits per light. |
| **PVisibilityCheck** | Frustum + occluder culling. PMeshInstanceBounds used for AABB testing. |
| **PLight** | Point, directional, spot, ambient lights. Used in scene lighting. |
| **PDeferredPushBuffer** | SPU-based deferred rendering (PS3 specific, not used on PC). |
| **PPhysicsShape/RigidBody/World** | Present in SDK but FFX.exe uses its own physics system (observed in FFX_Physics_* funcs). |

**Key insight for FFX reverse engineering:** The PhyreEngine structures define the runtime layout of textures, meshes, materials, and shaders in memory. When analyzing FFX.exe's decompiled functions like `FFX_Render_*`, `FFX_Scene_*`, or `FFX_Texture_*`, the struct definitions above directly correspond to the memory layouts these functions manipulate.
