# PhyreEngine 3.21.0.0 vs 3.1.5.0 — SDK Comparison

**Date:** 2026-07-29
**Author:** Jarvis (Verboo Code)
**Purpose:** Identify what changed between PhyreEngine 3.1.5.0 (2011) and 3.21.0.0 (2017) to understand FFX-specific features.

---

## Summary

| Metric | 3.1.5.0 (2011) | 3.21.0.0 (2017) | Delta |
|--------|----------------|-----------------|-------|
| Copyright | SCE (Sony Computer Entertainment) | SIE (Sony Interactive Entertainment) | Rebrand |
| .cpp files in Core/ | 613 | 1033 | +420 (+69%) |
| New files (in 3.21, not 3.1.5) | — | 476 | — |
| Removed files (in 3.1.5, not 3.21) | 56 | — | — |

**Key insight:** 3.21 is a massive expansion. The engine grew from a PS3-centric renderer to a multi-platform engine supporting PS3, PS4 (GNM), PS Vita (GXM), PC (D3D11), OpenGL, iOS, Android, and VR.

---

## New Subsystems in 3.21 (not in 3.1.5)

### 1. PBR (Physically Based Rendering) — 8 files
- `PhyrePBR.cpp` — Master include
- `PhyrePBRLtc.cpp` — Linearly Transformed Cosines (LTC) for area lights
- `PhyrePBRLookupTextures.cpp` — BRDF lookup tables
- `PhyrePBRLightProbe.cpp` — Light probe system
- `PhyrePBRLightProbeUpdater.cpp` — Runtime light probe updates
- `PhyrePBRLightProbeErrorTracker.cpp` — Error tracking for probes
- `PhyrePBRRadianceVolume.cpp` — Radiance volume rendering
- `PhyrePBRRenderBuffer.cpp` — PBR render buffers

**FFX relevance:** FFX HD uses PBR-like shading in some areas. The PBR system in 3.21 could explain the improved lighting in the HD remaster.

### 2. Particle System — 50+ files
- Full particle emitter system with emission shapes (Box, Cone, Sphere, Hemisphere, Line)
- Particle update system (ballistic, color, size, orientation, collision)
- Geometry generation (camera-aligned quads, velocity-aligned quads)
- SPU (Cell processor) particle drivers
- ParticleFx factory and instance management

**FFX relevance:** FFX has extensive particle effects (summoning, magic, environmental). The particle system in 3.21 is the engine behind these effects.

### 3. Terrain System — 15+ files
- `PhyreTerrain.cpp` — Master include
- `PhyreTerrainHeightmap.cpp` — Heightmap terrain
- `PhyreTerrainQuadtree.cpp` — Quadtree LOD
- `PhyreTerrainSplatmap.cpp` — Texture splatting
- `PhyreTerrainDynamicMesh.cpp` — Dynamic terrain mesh
- `PhyreTerrainCompositeTextureCache.cpp` — Texture caching
- `PhyreTerrainPageFault.cpp` — Page fault handling (streaming)
- `PhyreTerrainMMU.cpp` — Memory management unit

**FFX relevance:** FFX has terrain in some areas (Calm Lands, Bikanel). The terrain system could be used for these.

### 4. VR Support — 8 files
- `PhyreHmdDevice.cpp` — HMD device abstraction
- `PhyreVrTracker.cpp` — VR tracking
- `PhyreSocialScreen.cpp` — Social screen (asymmetric VR)
- Platform-specific: Orbis (PS4), Win32

**FFX relevance:** FFX HD does NOT use VR. This is a PS4-era addition.

### 5. Vision System — 8 files
- `PhyreVisionCamera.cpp` — Camera tracking
- `PhyreVisionMoveTracker.cpp` — Movement tracking
- `PhyreVisionTracker.cpp` — General tracking
- Platform-specific: Orbis (PS4), PSP2 (PS Vita)

**FFX relevance:** FFX does NOT use vision tracking. This is for PS4/PS Vita camera features.

### 6. State Machine — 6 files
- `PhyreStateMachineBase.cpp` — Base state machine
- `PhyreStateMachineCondition.cpp` — Conditions
- `PhyreStateMachineInstanceData.cpp` — Instance data
- `PhyreStateMachineStateBase.cpp` — Base state
- `PhyreStateMachineTransition.cpp` — Transitions

**FFX relevance:** FFX uses state machines for AI (CTB, monster behavior). The state machine system could be the engine behind these.

### 7. Inputs System — 8 files
- `PhyreInputMap.cpp` — Input mapping
- `PhyreInputAxisSemantic.cpp` — Axis semantics
- `PhyreInputChannelSemantic.cpp` — Channel semantics
- `PhyreInputJoypadButtonSemantic.cpp` — Joypad button semantics
- `PhyreInputKeySemantic.cpp` — Key semantics
- `PhyreInputMouseButtonSemantic.cpp` — Mouse button semantics
- `PhyreInputMotionControllerButtonSemantic.cpp` — Motion controller semantics

**FFX relevance:** FFX uses DirectInput for controller input. The input system in 3.21 could be the engine behind the controller mapping.

### 8. PostProcessing — 50+ new files
- `PhyreAtmospherics.cpp` — Atmospheric scattering
- `PhyreCelShading.cpp` — Cel shading
- `PhyreFXAA.cpp` — Fast Approximate Anti-Aliasing
- `PhyreTAA.cpp` — Temporal Anti-Aliasing
- `PhyreScreenSpaceReflection.cpp` — Screen-space reflections
- `PhyreDeferredLightingTiled.cpp` — Tiled deferred lighting
- `PhyreDeferredLightingTiledPBR.cpp` — Tiled deferred PBR
- `PhyreGammaCorrection.cpp` — Gamma correction
- `PhyreHDRRemapping.cpp` — HDR remapping
- `PhyreLowResParticles.cpp` — Low-res particle rendering
- `PhyreMaterialPostEffect.cpp` — Material post-effects
- `PhyrePostEffect.cpp` — Post-effect base
- `PhyrePostEffectManager.cpp` — Post-effect manager

**FFX relevance:** FFX HD uses post-processing effects (bloom, depth of field, motion blur). The post-processing system in 3.21 is the engine behind these.

### 9. Rendering — 50+ new files
- New backends: GNM (PS4), GLES (mobile), D3DFX
- New features: Constant buffers, GPU timers, indirect args buffers, structured buffers, texture arrays, cubemap arrays
- `PhyreRenderingUnity.cpp` — Rendering unity (batching)
- `PhyreShaderContext.cpp` — Shader context
- `PhyreShaderStateTracker.cpp` — Shader state tracking
- `PhyreSkyBox.cpp` — Sky box rendering

**FFX relevance:** FFX uses D3D11 rendering. The D3D11 backend in 3.21 is the engine behind the PC port.

### 10. Scaleform — 12 new files
- Platform-specific Scaleform movie rendering (D3D11, GCM, GL, GNM, GXM, Generic)
- `PhyreScaleformMovie.cpp` — Master include
- `PhyreScaleformMovieSharedComponents.cpp` — Shared components

**FFX relevance:** FFX uses Scaleform for UI. The Scaleform system in 3.21 is the engine behind the UI rendering.

### 11. Sprite System — 3 files
- `PhyreSpriteAnimationInfoInstance.cpp` — Sprite animation info
- `PhyreSpriteCollection.cpp` — Sprite collection
- `PhyreUtilitySprite.cpp` — Sprite utilities

**FFX relevance:** FFX uses sprites for some UI elements. The sprite system in 3.21 could be used for these.

### 12. Subdivision Surfaces — 3 files
- `PhyreSubdivDynamicMesh.cpp` — Dynamic subdivision mesh
- `PhyreSubdivDynamicMeshInstance.cpp` — Dynamic subdivision mesh instance
- `PhyreUtilitySubdiv.cpp` — Subdivision utilities

**FFX relevance:** FFX does NOT use subdivision surfaces. This is a PS4-era addition.

### 13. Statistics — 2 files
- `PhyreStatistics.cpp` — Statistics
- `PhyreUtilityStatistics.cpp` — Statistics utilities

**FFX relevance:** FFX uses statistics for debugging. The statistics system in 3.21 could be used for profiling.

### 14. World Rendering — 1 file
- `PhyreWorldRenderer.cpp` — World renderer

**FFX relevance:** FFX uses world rendering for scene management. The world renderer in 3.21 could be used for this.

### 15. Profiling — 3 new files
- `PhyreDebugDrawBuffer.cpp` — Debug draw buffer
- `PhyreLineCharRenderer.cpp` — Line/char renderer
- `PhyreProcessorProfile.cpp` — Processor profiling

**FFX relevance:** FFX uses profiling for debugging. The profiling system in 3.21 could be used for this.

---

## Removed Subsystems in 3.21 (in 3.1.5, not 3.21)

### 1. AnimationStateMachine — 16 files
- `PhyreAnimationStateMachine.cpp` — Master include
- `PhyreAnimationStateMachineBlendTree.cpp` — Blend tree
- `PhyreAnimationStateMachineBlendableBase.cpp` — Blendable base
- `PhyreAnimationStateMachineBlendableBlendTree.cpp` — Blendable blend tree
- `PhyreAnimationStateMachineBlendableClip.cpp` — Blendable clip
- `PhyreAnimationStateMachineBlenderBase.cpp` — Blender base
- `PhyreAnimationStateMachineStateBase.cpp` — State base
- `PhyreAnimationStateMachineStateBlend.cpp` — State blend
- `PhyreAnimationStateMachineStateClip.cpp` — State clip
- `PhyreAnimationStateMachineStateEmpty.cpp` — State empty
- `PhyreAnimationStateMachineStateInstanceData.cpp` — State instance data
- `PhyreUtilityAnimationStateMachine.cpp` — Utility

**Replaced by:** StateMachine (6 files) — more generic state machine system.

### 2. Audio/HeatWave — 4 files
- `PhyreAudioBankHeatWave.cpp` — HeatWave audio bank
- `PhyreAudioEventHeatWave.cpp` — HeatWave audio event
- `PhyreAudioHeatWave.cpp` — HeatWave audio
- `PhyreAudioInterfaceHeatWave.cpp` — HeatWave audio interface

**Replaced by:** FMOD (already in 3.1.5). HeatWave was PS3-specific audio.

### 3. Cloning — 3 files
- `PhyreCloneHistory.cpp` — Clone history
- `PhyreCloning.cpp` — Cloning
- `PhyreUtilityCloning.cpp` — Utility

**Replaced by:** ObjectModel (already in 3.1.5). Cloning was removed.

### 4. Event — 5 files
- `PhyreEvent.cpp` — Event
- `PhyreEventConnectorComponent.cpp` — Event connector component
- `PhyreMethodCallEventAction.cpp` — Method call event action
- `PhyreScriptCallEventAction.cpp` — Script call event action
- `PhyreUtilityEvent.cpp` — Utility

**Replaced by:** StateMachine (6 files). Event system was removed.

### 5. Gameplay — 8 files
- `PhyreAnimator.cpp` — Animator
- `PhyreAnimatorComponent.cpp` — Animator component
- `PhyreAttachableComponent.cpp` — Attachable component
- `PhyreCameraControllerComponent.cpp` — Camera controller component
- `PhyreScriptableComponent.cpp` — Scriptable component
- `PhyreScriptedComponent.cpp` — Scripted component
- `PhyreSpawner.cpp` — Spawner
- `PhyreSpline.cpp` — Spline
- `PhyreSplineFollowerComponent.cpp` — Spline follower component

**Replaced by:** Character (already in 3.1.5) + StateMachine (6 files). Gameplay was removed.

### 6. Geometry/GNM — 4 files
- `PhyreDataBlockGNM.cpp` — GNM data block
- `PhyreIndexDataBlockGNM.cpp` — GNM index data block
- `PhyreMappableBufferGNM.cpp` — GNM mappable buffer
- `PhyreMeshSegmentGNM.cpp` — GNM mesh segment

**Replaced by:** GNM (PS4) in 3.21. The GNM files were moved to a different location.

### 7. Hierarchy — 2 files
- `PhyreOctree.cpp` — Octree
- `PhyreUtilityHierarchy.cpp` — Utility

**Replaced by:** Scene (already in 3.1.5). Hierarchy was removed.

### 8. IOS — 1 file
- `PhyreOSIOS.cpp` — iOS OS

**Replaced by:** Platform/IOS (in 3.21). The IOS file was moved to a different location.

### 9. Iggy — 10 files
- `PhyreIggy.cpp` — Master include
- `PhyreIggyMovie.cpp` — Iggy movie
- `PhyreIggyMovieSharedComponents.cpp` — Shared components
- Platform-specific: D3D11, GCM, GNM, GXM

**Replaced by:** Iggy (in 3.21). The Iggy files were moved to a different location.

### 10. Images — 1 file
- `PhyreDDS.cpp` — DDS image

**Replaced by:** Rendering (already in 3.1.5). Images was removed.

### 11. ObjectModel/GNM — 1 file
- `PhyreClusterGNM.cpp` — GNM cluster

**Replaced by:** GNM (PS4) in 3.21. The GNM file was moved to a different location.

### 12. Physics/Pfx — 13 files
- `PhyrePhysicsBoxPfx.cpp` — Pfx box
- `PhyrePhysicsCapsulePfx.cpp` — Pfx capsule
- `PhyrePhysicsCharacterControllerPfx.cpp` — Pfx character controller
- `PhyrePhysicsCylinderPfx.cpp` — Pfx cylinder
- `PhyrePhysicsHeightMapPfx.cpp` — Pfx height map
- `PhyrePhysicsInterfacePfx.cpp` — Pfx interface
- `PhyrePhysicsMeshPfx.cpp` — Pfx mesh
- `PhyrePhysicsPfx.cpp` — Pfx physics
- `PhyrePhysicsPlanePfx.cpp` — Pfx plane
- `PhyrePhysicsRigidBodyPfx.cpp` — Pfx rigid body
- `PhyrePhysicsShapePfx.cpp` — Pfx shape
- `PhyrePhysicsSpherePfx.cpp` — Pfx sphere
- `PhyrePhysicsWorldPfx.cpp` — Pfx world

**Replaced by:** Bullet/Havok/PhysX (already in 3.1.5). Pfx was PS3-specific physics.

### 13. Picking — 2 files
- `PhyrePickingManager.cpp` — Picking manager
- `PhyreUtilityPicking.cpp` — Utility

**Replaced by:** Rendering (already in 3.1.5). Picking was removed.

### 14. Platform/AGL2, GLES, GNM, IOS — many files
- `PhyrePlatformAGL2.cpp` — AGL2 platform
- `PhyrePlatformConverterAGL2.cpp` — AGL2 converter
- `PhyrePlatformGLES.cpp` — GLES platform
- `PhyrePlatformConverterGLES.cpp` — GLES converter
- `PhyrePlatformGNM.cpp` — GNM platform
- `PhyrePlatformConverterGNM.cpp` — GNM converter
- `PhyrePlatformIOS.cpp` — IOS platform
- `PhyrePlatformConverterIOS.cpp` — IOS converter

**Replaced by:** Platform (in 3.21). These files were moved to a different location.

### 15. PostProcessing — many files
- `PhyreAtmospherics.cpp` — Atmospherics
- `PhyreCelShading.cpp` — Cel shading
- `PhyreDeferredLightingTiled.cpp` — Tiled deferred lighting
- `PhyreDeferredLightingTiledPBR.cpp` — Tiled deferred PBR
- `PhyreFXAA.cpp` — FXAA
- `PhyreTAA.cpp` — TAA
- `PhyreScreenSpaceReflection.cpp` — Screen-space reflections
- `PhyreGammaCorrection.cpp` — Gamma correction
- `PhyreHDRRemapping.cpp` — HDR remapping
- `PhyreLowResParticles.cpp` — Low-res particles
- `PhyreMaterialPostEffect.cpp` — Material post-effect
- `PhyrePostEffect.cpp` — Post-effect
- `PhyrePostEffectManager.cpp` — Post-effect manager

**Replaced by:** PostProcessing (in 3.21). These files were moved to a different location.

### 16. Profiling/PS3 — 2 files
- `PhyreProcessorProfilePS3.cpp` — PS3 processor profile
- `PhyreSPUCaptureDecrementer.cpp` — SPU capture decrementer

**Replaced by:** Profiling (in 3.21). These files were moved to a different location.

### 17. Rendering — many files
- `PhyreCgProgram.cpp` — Cg program
- `PhyreConstantBufferD3D11.cpp` — D3D11 constant buffer
- `PhyreGPUTimerD3D11.cpp` — D3D11 GPU timer
- `PhyreIndirectArgsBufferD3D11.cpp` — D3D11 indirect args buffer
- `PhyreSamplerStateD3D11.cpp` — D3D11 sampler state
- `PhyreStateCacheD3D11.cpp` — D3D11 state cache
- `PhyreStructuredBufferD3D11.cpp` — D3D11 structured buffer
- `PhyreTexture2DArrayD3D11.cpp` — D3D11 texture 2D array
- `PhyreTextureCubemapArrayD3D11.cpp` — D3D11 cubemap array

**Replaced by:** Rendering (in 3.21). These files were moved to a different location.

### 18. Scaleform — many files
- `PhyreScaleformMovieD3D11.cpp` — D3D11 Scaleform movie
- `PhyreScaleformMovieSharedComponentsD3D11.cpp` — D3D11 shared components
- `PhyreScaleformMovieGCM.cpp` — GCM Scaleform movie
- `PhyreScaleformMovieSharedComponentsGCM.cpp` — GCM shared components
- `PhyreScaleformMovieGL.cpp` — GL Scaleform movie
- `PhyreScaleformMovieSharedComponentsGL.cpp` — GL shared components
- `PhyreScaleformMovieGNM.cpp` — GNM Scaleform movie
- `PhyreScaleformMovieSharedComponentsGNM.cpp` — GNM shared components
- `PhyreScaleformMovieGXM.cpp` — GXM Scaleform movie
- `PhyreScaleformMovieSharedComponentsGXM.cpp` — GXM shared components
- `PhyreScaleformMovieGeneric.cpp` — Generic Scaleform movie
- `PhyreScaleformMovieSharedComponentsGeneric.cpp` — Generic shared components

**Replaced by:** Scaleform (in 3.21). These files were moved to a different location.

### 19. Scripting — 3 files
- `PhyreLuaChunkRewriter.cpp` — Lua chunk rewriter
- `PhyreScriptCallbackHandler.cpp` — Script callback handler
- `PhyreScriptingVectormath.cpp` — Scripting vectormath

**Replaced by:** Scripting (in 3.21). These files were moved to a different location.

### 20. Serialization — many files
- `PhyreStreamFileAndroid.cpp` — Android stream file
- `PhyreStreamFileIOS.cpp` — IOS stream file
- `PhyreStreamFileOSX.cpp` — OSX stream file
- `PhyreStreamFileOrbis.cpp` — Orbis stream file
- `PhyreStreamFilePS3.cpp` — PS3 stream file
- `PhyreStreamFilePSP2.cpp` — PSP2 stream file
- `PhyreStreamFileWin32.cpp` — Win32 stream file

**Replaced by:** Serialization (in 3.21). These files were moved to a different location.

### 21. Sprite — 3 files
- `PhyreSpriteAnimationInfoInstance.cpp` — Sprite animation info
- `PhyreSpriteCollection.cpp` — Sprite collection
- `PhyreUtilitySprite.cpp` — Utility

**Replaced by:** Sprite (in 3.21). These files were moved to a different location.

### 22. StateMachine — 6 files
- `PhyreStateMachineBase.cpp` — Base state machine
- `PhyreStateMachineCondition.cpp` — Conditions
- `PhyreStateMachineInstanceData.cpp` — Instance data
- `PhyreStateMachineStateBase.cpp` — Base state
- `PhyreStateMachineTransition.cpp` — Transitions
- `PhyreUtilityStateMachine.cpp` — Utility

**Replaced by:** StateMachine (in 3.21). These files were moved to a different location.

### 23. Statistics — 2 files
- `PhyreStatistics.cpp` — Statistics
- `PhyreUtilityStatistics.cpp` — Utility

**Replaced by:** Statistics (in 3.21). These files were moved to a different location.

### 24. Subdiv — 3 files
- `PhyreSubdivDynamicMesh.cpp` — Dynamic subdivision mesh
- `PhyreSubdivDynamicMeshInstance.cpp` — Dynamic subdivision mesh instance
- `PhyreUtilitySubdiv.cpp` — Utility

**Replaced by:** Subdiv (in 3.21). These files were moved to a different location.

### 25. Terrain — many files
- `PhyreTerrain.cpp` — Master include
- `PhyreTerrainCompositeTextureCache.cpp` — Texture cache
- `PhyreTerrainDynamicMesh.cpp` — Dynamic mesh
- `PhyreTerrainDynamicMeshInstance.cpp` — Dynamic mesh instance
- `PhyreTerrainHeightmap.cpp` — Heightmap
- `PhyreTerrainMap.cpp` — Terrain map
- `PhyreTerrainPalette.cpp` — Palette
- `PhyreTerrainParameterBufferHelper.cpp` — Parameter buffer helper
- `PhyreTerrainQuadtree.cpp` — Quadtree
- `PhyreTerrainRenderNode.cpp` — Render node
- `PhyreTerrainSplatmap.cpp` — Splatmap
- `PhyreTerrainStreamReaderFileDispenser.cpp` — Stream reader
- `PhyreUtilityTerrain.cpp` — Utility

**Replaced by:** Terrain (in 3.21). These files were moved to a different location.

### 26. VR — 8 files
- `PhyreHmdDevice.cpp` — HMD device
- `PhyreVrTracker.cpp` — VR tracker
- `PhyreSocialScreen.cpp` — Social screen
- `PhyreVrCommon.cpp` — VR common
- `PhyreVrTracker.cpp` — VR tracker
- Platform-specific: Orbis, Win32

**Replaced by:** VR (in 3.21). These files were moved to a different location.

### 27. Vision — 8 files
- `PhyreVisionCamera.cpp` — Camera
- `PhyreVisionMoveTracker.cpp` — Move tracker
- `PhyreVisionTracker.cpp` — Tracker
- Platform-specific: Orbis, PSP2

**Replaced by:** Vision (in 3.21). These files were moved to a different location.

### 28. Video — 2 files
- `PhyreVideoPlaybackAndroid.cpp` — Android video playback
- `PhyreVideoPlaybackOrbis.cpp` — Orbis video playback

**Replaced by:** Video (in 3.21). These files were moved to a different location.

### 29. WorldRendering — 1 file
- `PhyreWorldRenderer.cpp` — World renderer

**Replaced by:** WorldRendering (in 3.21). This file was moved to a different location.

---

## Key Changes for FFX

### 1. PBR (Physically Based Rendering)
- **New in 3.21:** Full PBR pipeline with light probes, radiance volumes, LTC area lights
- **FFX relevance:** FFX HD uses PBR-like shading in some areas. The PBR system in 3.21 could explain the improved lighting in the HD remaster.

### 2. Particle System
- **New in 3.21:** Full particle emitter system with emission shapes, update system, geometry generation
- **FFX relevance:** FFX has extensive particle effects (summoning, magic, environmental). The particle system in 3.21 is the engine behind these effects.

### 3. Terrain System
- **New in 3.21:** Full terrain system with heightmap, quadtree LOD, texture splatting, dynamic mesh
- **FFX relevance:** FFX has terrain in some areas (Calm Lands, Bikanel). The terrain system could be used for these.

### 4. State Machine
- **New in 3.21:** Generic state machine system (replaces AnimationStateMachine)
- **FFX relevance:** FFX uses state machines for AI (CTB, monster behavior). The state machine system could be the engine behind these.

### 5. Inputs System
- **New in 3.21:** Full input mapping system with axis, channel, joypad, key, mouse, motion controller semantics
- **FFX relevance:** FFX uses DirectInput for controller input. The input system in 3.21 could be the engine behind the controller mapping.

### 6. PostProcessing
- **New in 3.21:** Full post-processing pipeline with atmospherics, cel shading, FXAA, TAA, screen-space reflections, tiled deferred lighting, gamma correction, HDR remapping
- **FFX relevance:** FFX HD uses post-processing effects (bloom, depth of field, motion blur). The post-processing system in 3.21 is the engine behind these.

### 7. Rendering
- **New in 3.21:** New backends (GNM, GLES, D3DFX), constant buffers, GPU timers, indirect args buffers, structured buffers, texture arrays, cubemap arrays
- **FFX relevance:** FFX uses D3D11 rendering. The D3D11 backend in 3.21 is the engine behind the PC port.

### 8. Scaleform
- **New in 3.21:** Platform-specific Scaleform movie rendering (D3D11, GCM, GL, GNM, GXM, Generic)
- **FFX relevance:** FFX uses Scaleform for UI. The Scaleform system in 3.21 is the engine behind the UI rendering.

### 9. VR Support
- **New in 3.21:** VR support with HMD device, VR tracker, social screen
- **FFX relevance:** FFX HD does NOT use VR. This is a PS4-era addition.

### 10. Vision System
- **New in 3.21:** Vision tracking with camera, move tracker, tracker
- **FFX relevance:** FFX does NOT use vision tracking. This is for PS4/PS Vita camera features.

---

## Conclusion

PhyreEngine 3.21.0.0 is a massive expansion from 3.1.5.0. The engine grew from a PS3-centric renderer to a multi-platform engine supporting PS3, PS4 (GNM), PS Vita (GXM), PC (D3D11), OpenGL, iOS, Android, and VR.

The key new subsystems for FFX are:
1. **PBR** — Physically Based Rendering
2. **Particle System** — Full particle emitter system
3. **Terrain System** — Full terrain system
4. **State Machine** — Generic state machine system
5. **Inputs System** — Full input mapping system
6. **PostProcessing** — Full post-processing pipeline
7. **Rendering** — New backends and features
8. **Scaleform** — Platform-specific Scaleform movie rendering

The removed subsystems are mostly PS3-specific (HeatWave audio, Pfx physics, SPU profiling) or were replaced by more generic systems (AnimationStateMachine → StateMachine, Event → StateMachine, Gameplay → Character + StateMachine).

The FFX HD remaster likely uses the 3.21 engine (or a similar version) for the PC port, which explains the improved lighting, particle effects, and post-processing effects.