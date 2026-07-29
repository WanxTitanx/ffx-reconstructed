# PhyreEngine Getting Started Guide — Release 3.1.5.0

> Source: archive.org stream `PS3_SDK_3_70_PhyreEngine/Phyre_Engine/Phyre Engine/Docs/PhyreEngine_Getting_Started_e_djvu.txt`
> © 2011 Sony Computer Entertainment Inc. All Rights Reserved. SCE Confidential.
> Document serial number: 000000867210

## Release

**PhyreEngine 3.1.5.0** (Out 2011, PS3 SDK 3.70)

## Prerequisites

### All Platforms
- Microsoft Visual Studio 2008 Professional Edition + SP1
- NVIDIA Cg Toolkit (http://developer.nvidia.com/cg-toolkit)

### Windows Only
- Microsoft DirectX SDK

### PlayStation 3 Only
- PlayStation 3 Programmer Tool Runtime Library SDK
- PlayStation 3 Programmer Tool Toolchain

### PlayStation Vita Only
- PlayStation Vita SDK (via SDK Manager)

## Environment Variables

| Variable | Description | Example |
|----------|-------------|---------|
| `SCE_PHYRE` | PhyreEngine install path (auto-set by installer) | `C:\PhyreEngine` |
| `SCE_PS3_ROOT` | PS3 SDK path | `C:\PhyreEngine\External\PS3SDK` |
| `SCE_PSP2_SDK_DIR` | PSVita SDK path | `C:\PhyreEngine\External\PSP2SDK` |
| `CG_BIN_PATH` | NVIDIA Cg bin | `C:\Program Files\NVIDIA Corporation\Cg\bin` |
| `CG_INC_PATH` | NVIDIA Cg include | `C:\Program Files\NVIDIA Corporation\Cg\include` |
| `CG_LIB_PATH` | NVIDIA Cg lib | `C:\Program Files\NVIDIA Corporation\Cg\lib` |
| `DXSDK_DIR` | DirectX SDK | `C:\Program Files\Microsoft DirectX SDK (February 2010)` |

### Optional (audio/physics/UI)
- `SCE_PHYRE_AUDIO_FMOD` — FMOD SDK
- `SCE_PHYRE_PHYSICS_HAVOK_PS3` — Havok PS3
- `SCE_PHYRE_PHYSICS_HAVOK_PSP2` — Havok PSVita
- `SCE_PHYRE_PHYSICS_PHYSX_PS3` — PhysX PS3
- `SCE_PHYRE_PHYSICS_PHYSX_WIN` — PhysX Windows
- `SCE_PHYRE_SCALEFORM` — Scaleform GFx SDK 4.0
- `SCE_PHYRE_HEAPINSPECTOR` — HeapInspector

## Architecture

```
Application
    └── PhyreEngineAPI
        ├── Asset
        ├── Core
        │   ├── ObjectModel
        │   ├── Serialization
        │   ├── DynamicGeometry
        │   ├── OccluderGeometry
        │   ├── PostProcessing
        │   ├── Geometry
        │   ├── LOD
        │   ├── Scene
        │   ├── Text
        │   ├── Gameplay
        │   ├── Navigation
        │   ├── Physics
        │   ├── Profiling
        │   ├── Rendering
        │   └── Scripting
        ├── Online
        └── Framework
            ├── GCM (PS3)
            ├── GL (Windows OpenGL)
            ├── GXM (PSVita)
            └── D3D11 (Windows DirectX 11)
```

## Core Library

Single header: `Phyre.h`. Configurable via `PhyreConfig.h` with `#define` toggles:
- `PHYRE_ENABLE_PHYSICS` — Bullet/Havok/PhysX
- `PHYRE_ENABLE_AUDIO` — FMOD
- `PHYRE_ENABLE_VIDEO_PLAYBACK` — Sail (PS3) / sceAvplayer (PSV)
- `PHYRE_ENABLE_SCALEFORM` — Scaleform 4
- `PHYRE_ENABLE_HEAP_INSPECTOR` — HeapInspector (PS3 only)

## Object Model

Base class: `PBase` with reflection. Class binding via macros:

```cpp
// .h
class TestClassWithByte : public Phyre::PBase {
    PHYRE_BIND_DECLARE_CLASS(TestClassWithByte, Phyre::PBase);
public:
    PUInt8 m_byte;
    TestClassWithByte() : m_byte(0x10) {}
};

// .cpp
PHYRE_BIND_START(TestClassWithByte)
    PHYRE_BIND_CLASS_DATA_MEMBER(m_byte)
PHYRE_BIND_END

// init
TestClassWithByte::Bind();
```

## Physics

Supports Bullet, Havok, PhysX. Rigid bodies grouped into `PPhysicsModel` → added to `PPhysicsWorld`.

3 rigid body types:
1. Static (any triangle mesh)
2. Dynamic (convex sub-shapes)
3. Kinematic (driven by animation)

Simulation step (async):
1. `stepSimulation()` — start
2. `PPhysicsWorld::syncSimulation(float timeStep)` — wait
3. `PPhysicsWorld::updateWorldMatrices()` — sync graphics

Or sync: `PPhysicsWorld::autoStepSimulation(float timeStep)`

## Asset Pipeline

`PhyreAssetProcessor.exe` converts COLLADA → `.phyre` (binary serialized `PCluster`).

```bash
PhyreAssetProcessor.exe -fi=<in file> -platform=<platform> -threads=<n> \
  -targets -merge<merged file> -modcheck={none,source,source+exe}
```

Asset types:
- 3D models → COLLADA (.dae)
- Textures → PNG/BMP/JPG/DDS/TGA
- Fonts → PhyreEngine desc + TTF
- Scripts → text
- Shaders → CGFX
- Levels → PhyreLevel (.plv)

## Tools

| Tool | Type | Purpose |
|------|------|---------|
| PhyreLevelEditor | GUI | Level placement (.plv files) |
| PhyreFontEditor | GUI | Bitmap fonts |
| PhyreAssetProcessor | CLI | COLLADA → .phyre |
| PhyreStripSPUELF | CLI (PS3) | SPU ELF stripping |
| PhyreClassLayout | CLI | Class layout files |
| FixDates | CLI | Sync file timestamps |
| PhyreAssetGather | CLI | Batch asset processing |

## Samples

Animation, Audio, Basic, CreateScene, DynamicMesh, GeometricInstancing,
LevelOfDetail, Navigation, Occluders, Physics, Postprocessing, RenderToTexture,
SpaceStationDemo, StereoscopicRendering, Text, ThirdPersonGameTemplate, Video.

## Versioning

Format: X.Y.Z
- X = major
- Y = minor
- Z = bug correction

## License

Sony Tools & Middleware License. NOT open source. Licensee-only.

## FFX HD Relevance

FFX HD Remaster (2013 PS3, 2014 PSV, 2016 PC) uses PhyreEngine.
- PS3 SDK 3.70 (Out 2011) includes PhyreEngine 3.1.5.0
- FFX.exe has 777+ RTTI strings `Phyre::` (confirmed via IDA `find_regex`)
- Source path in FFX.exe: `r:\hg_code\middleware_w32\phyreengine\` (Mercurial)
- FFX-specific classes: ClassDynamicMesh, DistortionGridDynamicMesh,
  RadialLineDynamicMesh, BrokenScreenPolygonDynamicMesh, ShadowDynamicMesh,
  ClothInstancingDynamicMesh

## References

- [PhyreEngine versions gist (uyjulian)](https://gist.github.com/uyjulian/4c01aa0c5e862e0136e59b1a9b2817f6) — Trails/Tokyo Xanadu versions 3.6.0.0–3.25.0.0
- [PS3 SDK 3.70 on archive.org](https://archive.org/details/ps3-sdk-3.70)
- [PhyreEngine — Wikipedia](https://en.wikipedia.org/wiki/PhyreEngine)
