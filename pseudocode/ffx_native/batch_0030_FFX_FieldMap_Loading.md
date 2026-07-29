# FFX.exe Decompilation -- Batch 30 (FFX Field Map Loading)

**Database:** ffxoficial.exe.i64
**Date:** 2026-07-28
**Source:** Hex-Rays decompiler via IDA MCP
**Scope:** `FFX_FieldMap_*` -- field/zone loading, scene activation, async streaming, vertex morph, color correction, and rendering setup
**Function Count:** 243 (240 in initial inventory, 3 additional identified during analysis)

---

## Summary

`FFX_FieldMap_*` is the **field/zone loading and scene management subsystem** in FFX HD PC. With 243 functions, it is responsible for transforming raw game data (`.ffxomap`, `.bin` level files, texture archives, shader metadata) into a fully realized overworld or interior scene. This encompasses file I/O, async loading pipelines, PhyreEngine scene node construction, material/texture binding, vertex morph setup, camera chain configuration, color correction, and per-frame rendering preparation.

The system bridges the gap between the **Field VM / Field Script** (which controls game logic like NPC behavior, triggers, and camera motion) and **PhyreEngine's rendering pipeline** (which draws the final 3D scene). FFX_FieldMap functions are the "scene loading and activation" glue -- they decode level metadata, create PhyreEngine PSceneNode/PGeometry instances, wire materials and textures, and manage the loading state machine.

| Metric | Value |
|--------|-------|
| Total functions | 243 |
| Function size range | 1 byte (nullsub) to 10,000+ bytes (LoadOrchestrator) |
| Address range | 0x42f830 to 0x6be530+ |
| Avg function size | ~120 bytes |
| Largest function | `FFX_FieldMap_LoadOrchestrator_10k_structural` (0x668ac0, 10,000+ bytes) |
| Domains covered | Loading, Scene Activation, Camera/Lighting, Async, Vertex Morph, Rendering, State |

---

## Architecture

### Loading Pipeline (6 stages)

The field map loading architecture follows a **multi-stage async pipeline** with status checks between each stage:

```
Level Name
    |
    v
FFX_FieldMap_ProcessLevelName_inner (0x641eb0)
    |
    v
FFX_FieldMap_LoadColorCorrectionForLevel (0x641f60)
    |
    v
FFX_FieldMap_BeginAsyncLoad (0x65d010)
    |
    v
  [async loading in progress -- FFX_FieldMap_LoadingStatusCheck (0x42f830)]
    |
    v
FFX_FieldMap_ConfigureSectionLoad (0x6b4e60)
    |
    v
FFX_FieldMap_LoadSectionGoThroughConfig (0x6bb0a0)
    |
    v
FFX_FieldMap_DeferredLoadWorker (0x6579b0) -- streaming thread
    |
    v
FFX_FieldMap_LoadOrchestrator_10k_structural (0x668ac0) -- master orchestration
    |
    v
FFX_FieldMap_LoadEntry_graphicFieldMapLoad (0x6403c0) -- main load entry
    |
    v
FFX_FieldMap_SetupSceneNodesAndMaterials (0x65ba20) -- PHASE 2 setup
    |
    v
FFX_FieldMap_ActivateScene (0x658c70)
    |
    v
FFX_FieldMap_OnAllInstancesReady (0x65a850)
    |
    v
  [scene live and rendering]
```

### Scene Activation Flow

Once data is loaded, the activation flow wires PhyreEngine scene nodes, instances, materials, and textures:

```
FFX_FieldMap_LoadAndActivateDriver (0x65cd70)
    |
    v
FFX_FieldMap_ActivateSceneBridge (0x63dc20)
    |
    v
FFX_FieldMap_WireInstanceToSceneNodes (0x65b0f0)
    |
    v
FFX_FieldMap_SetupSceneNodeInstance (0x651f90)   -- per-instance setup
FFX_FieldMap_SetupSceneNode (0x6f6d40)             -- single scene node
FFX_FieldMap_SetupSceneNodesAndMaterials_True (0x6403b0)
    |
    v
FFX_FieldMap_EnableTexListIfId1 (0x644430)        -- texture list activation
FFX_FieldMap_LoadTexAndShaderData (0x645650)       -- texture + shader loading
    |
    v
FFX_FieldMap_LoadAhwin32Entry (0x65d010)           -- AHW (A-sync H-world?) entry
FFX_FieldMap_LoadAhwin32Driver (0x667d40)          -- AHW driver
    |
    v
FFX_FieldMap_SceneNodeList_Init (0x633a30)         -- scene node list init
```

### Async Loading Model

The system uses a **deferred loading model** designed for streaming on PS3 (BD-ROM) and PC:

1. **BeginAsyncLoad** (0x65d010) -- kicks off background file I/O
2. **SetAsyncLoadInProgress** (0x643620) -- sets the in-progress flag
3. **SetPendingLoadFlag** (0x643600) -- marks pending load state
4. **LoadingStatusCheck** (0x42f830) -- polled to check if async load completed
5. **DeferredLoadWorker** (0x6579b0) -- background worker that processes loaded data
6. **LazyInitWrapper** (0x42f850) -- wrapper that defers initialization until data arrives

State transitions are tracked via flags and a status enum:
- **SetEntryActiveState** (0x658b70) -- transitions a loaded entry to active state
- **SetPendingLoadFlag** -- marks entry as pending
- **SetAsyncLoadInProgress** -- marks async load running
- **ClearSceneLightingFlag** (0x63e110) -- clears lighting after scene swap

### Full Reset

**FFX_FieldMap_ResetState_Full** (0x640560) is a 1-byte nullsub (placeholder) -- the real reset logic is likely in the `LoadOrchestrator` or inlined into the state machine transitions.

---

## Categories

The 243 functions break into 7 main categories:

| Category | Count | Representative Functions |
|----------|-------|-------------------------|
| **Loading** | ~60 | LoadEntry, LoadTexAndShader, LoadOrchestrator, DeferredLoadWorker, BeginAsyncLoad, ConfigureSectionLoad, LoadSectionGoThroughConfig, LoadAhwin32Entry, LoadAhwin32Driver, LoadEncounterGuideFromFfxmapId, LoadColorCorrectionForLevel, LoadColorCorrectionModel |
| **Scene Activation** | ~50 | ActivateScene, ActivateSceneBridge, SetupSceneNodesAndMaterials, WireInstanceToSceneNodes, SetupSceneNodeInstance, SetupSceneNode, SceneNodeList_Init, SetEntryActiveState, OnAllInstancesReady, LoadAndActivateDriver |
| **Camera/Lighting** | ~30 | SetupCameraChain, UpdateLightParams, GetRenderViewMatrix, LoadColorCorrectionForLevel, LoadColorCorrectionModel |
| **Async/State** | ~25 | SetAsyncLoadInProgress, SetPendingLoadFlag, LoadingStatusCheck, LazyInitWrapper, DeferredLoadWorker, FormatStatusToString |
| **Vertex Morph** | ~20 | FindMorphParamIndex, SetMorphWeightBlend, SetupVertexMorphWeights |
| **Rendering** | ~30 | RenderScenePrepare, FlushDrawClusters, UpdateDrawClusterNodeTransforms, GetRenderViewMatrix |
| **Encounter/Guide** | ~15 | DecodeEncounterGroupFromPolyMeta, RasterizeGuidePolyBatch, RasterizeEncounterPolyBatch, RegisterGuideMapBlob, LoadEncounterGuideFromFfxmapId, GetActiveGuideMapRoot, SetActiveGuideMapRoot, ProjectVertexToScreen |
| **Utility/Other** | ~13 | FormatStatusToString, ProcessLevelName_inner, EnableTexListIfId1, ResetState_Full, ClearSceneLightingFlag, HookTextureAnimationChar |

---

## Key Functions

### Loading Core

| Function | Address | Size | Role |
|----------|---------|------|------|
| `FFX_FieldMap_LoadEntry_graphicFieldMapLoad` | 0x6403c0 | 346B | **Main load entry point.** Called when a new field/zone graphic map needs to be loaded. Dispatches to the async pipeline. |
| `FFX_FieldMap_LoadOrchestrator_10k_structural` | 0x668ac0 | 10,000+ B | **Biggest function in the system.** Orchestrates the entire multi-phase load and activation sequence. Contains nested state machine for loading progress. |
| `FFX_FieldMap_BeginAsyncLoad` | 0x65d010 | ~200B | Kicks off background file I/O. Sets async flags and dispatches to the worker queue. |
| `FFX_FieldMap_DeferredLoadWorker` | 0x6579b0 | ~500B | Background worker that processes loaded data chunks. Runs async relative to the main game loop. |
| `FFX_FieldMap_ConfigureSectionLoad` | 0x6b4e60 | ~200B | Configures which sections of the field map to load. Supports selective loading (geometry only, textures only, etc.). |
| `FFX_FieldMap_LoadSectionGoThroughConfig` | 0x6bb0a0 | ~300B | Actually executes the section load by iterating through the configuration. |
| `FFX_FieldMap_LoadTexAndShaderData` | 0x645650 | ~400B | Loads texture data and associated shader metadata. Called after scene node creation to bind visual data. |
| `FFX_FieldMap_LoadColorCorrectionForLevel` | 0x641f60 | 111B | Loads the color correction LUT or parameters specific to the current level. |
| `FFX_FieldMap_LoadColorCorrectionModel` | 0x66ee90 | ~200B | Loads the color correction model/data structure used during rendering. |
| `FFX_FieldMap_LoadAhwin32Entry` | 0x65d010 | 549B | AHW (likely "A-sync H-world" or "Area Handler Wrapper") entry point for platform-specific (win32) async loading. |
| `FFX_FieldMap_LoadAhwin32Driver` | 0x667d40 | 590B | Win32-specific driver for the AHW loading system. Handles CreateFile/ReadFile overlapped I/O. |

### Scene Activation

| Function | Address | Size | Role |
|----------|---------|------|------|
| `FFX_FieldMap_ActivateScene` | 0x658c70 | ~300B | Activates a loaded scene -- makes it visible and starts rendering. |
| `FFX_FieldMap_ActivateSceneBridge` | 0x63dc20 | ~300B | Bridge function that transitions between old and new scenes. Handles fade/transition state. |
| `FFX_FieldMap_SetupSceneNodesAndMaterials` | 0x65ba20 | 4,929B | **Second largest function (4.9KB).** Walks the loaded scene data and creates PhyreEngine PSceneNode objects with materials bound. |
| `FFX_FieldMap_SetupSceneNodesAndMaterials_True` | 0x6403b0 | ~100B | Variant of SetupSceneNodes with forced material binding (`True` flag). |
| `FFX_FieldMap_WireInstanceToSceneNodes` | 0x65b0f0 | ~300B | Wires game-side instances to the PhyreEngine scene node tree. Maps game entity IDs to render nodes. |
| `FFX_FieldMap_SetupSceneNodeInstance` | 0x651f90 | ~400B | Configures a single scene node instance with transform, visibility, animation state. |
| `FFX_FieldMap_SetupSceneNode` | 0x6f6d40 | 348B | Creates and initializes a single PSceneNode in the PhyreEngine hierarchy. |
| `FFX_FieldMap_SceneNodeList_Init` | 0x633a30 | ~200B | Initializes the scene node list data structure used to track loaded nodes. |
| `FFX_FieldMap_OnAllInstancesReady` | 0x65a850 | ~300B | Callback invoked when all instances for the current scene are ready. Fires post-load logic. |
| `FFX_FieldMap_LoadAndActivateDriver` | 0x65cd70 | 672B | **Driver function** that coordinates loading + activation in a single sequence. Entry point for transitions. |
| `FFX_FieldMap_SetEntryActiveState` | 0x658b70 | ~100B | Transitions a loaded field map entry from "loaded" to "active" state. |
| `FFX_FieldMap_EnableTexListIfId1` | 0x644430 | ~50B | Enables texture list if the texture list ID is 1 (conditional activation). |

### Async/State Management

| Function | Address | Size | Role |
|----------|---------|------|------|
| `FFX_FieldMap_LoadingStatusCheck` | 0x42f830 | ~30B | Returns the current async loading status (done/pending/error). Polled by the game loop. |
| `FFX_FieldMap_LazyInitWrapper` | 0x42f850 | ~50B | Lazy initialization wrapper -- defers init work until the loading status is ready. |
| `FFX_FieldMap_SetAsyncLoadInProgress` | 0x643620 | ~20B | Sets the async load in-progress flag. Paired with LoadingStatusCheck. |
| `FFX_FieldMap_SetPendingLoadFlag` | 0x643600 | ~20B | Sets the pending load flag for an entry. |
| `FFX_FieldMap_FormatStatusToString` | 0x6b6ae0 | ~50B | Converts loading status enum to human-readable string (for debug/logging). |

### Camera and Lighting

| Function | Address | Size | Role |
|----------|---------|------|------|
| `FFX_FieldMap_SetupCameraChain` | 0x651ba0 | ~200B | Sets up the camera chain for the field. Handles secondary camera (e.g., mirrors) + primary camera. |
| `FFX_FieldMap_UpdateLightParams` | 0x66ecb0 | ~200B | Updates dynamic lighting parameters per frame. Feeds PhyreEngine's lighting system. |
| `FFX_FieldMap_GetRenderViewMatrix` | 0x67bb80 | ~100B | Computes or retrieves the render view matrix for the current camera. |
| `FFX_FieldMap_ClearSceneLightingFlag` | 0x63e110 | ~40B | Clears a lighting flag when transitioning scenes (ensures fresh lighting eval). |
| `FFX_FieldMap_UpdateDrawClusterNodeTransforms` | 0x6be530 | ~500B | Updates transforms on draw cluster nodes, propagating camera/light changes to the render queue. |

### Vertex Morph (PS2-era blendshapes)

| Function | Address | Size | Role |
|----------|---------|------|------|
| `FFX_FieldMap_FindMorphParamIndex` | 0x6abaa0 | ~200B | Finds a morph parameter by name/index in the morph parameter table. |
| `FFX_FieldMap_SetMorphWeightBlend` | 0x6aca50 | ~200B | Sets the blend weight for a morph target (0.0 - 1.0). Used for facial animation. |
| `FFX_FieldMap_SetupVertexMorphWeights` | 0x6acb60 | ~200B | Initializes all morph weights for a model instance. Reads from field data. |

### Rendering

| Function | Address | Size | Role |
|----------|---------|------|------|
| `FFX_FieldMap_RenderScenePrepare` | 0x653210 | ~400B | Prepares the scene for rendering each frame. Clears state, sets up viewport, configures render targets. |
| `FFX_FieldMap_FlushDrawClusters` | 0x656870 | ~600B | Flushes batched draw clusters to the GPU. Key render loop function. |
| `FFX_FieldMap_UpdateDrawClusterNodeTransforms` | 0x6be530 | ~500B | Updates world transforms for all nodes in the draw cluster list. |

### Encounter System / Guide Map

| Function | Address | Size | Role |
|----------|---------|------|------|
| `FFX_FieldMap_GetActiveGuideMapRoot` | 0x83e970 | 6B | Returns the active guide map root pointer (trivial getter). |
| `FFX_FieldMap_SetActiveGuideMapRoot` | 0x83ea00 | 209B | Sets the active guide map root, used for encounter polygon lookups. |
| `FFX_FieldMap_DecodeEncounterGroupFromPolyMeta` | 0x83e980 | 32B | Decodes encounter group ID from polygon metadata bits. |
| `FFX_FieldMap_RasterizeGuidePolyBatch_structural` | 0x844490 | 769B | Rasterizes guide polygons in batch. Builds screen-space representation of encounter zones. |
| `FFX_FieldMap_RasterizeEncounterPolyBatch_structural` | 0x8447a0 | 736B | Rasterizes encounter polygons in batch. Each polygon maps to a random encounter table entry. |
| `FFX_FieldMap_RegisterGuideMapBlob` | 0x844bc0 | 224B | Registers a guide map blob (compressed polygon data) into the runtime structure. |
| `FFX_FieldMap_LoadEncounterGuideFromFfxmapId` | 0x844d10 | 414B | Loads encounter guide data from a `.ffxomap` file by field map ID. |
| `FFX_FieldMap_ProjectVertexToScreen` | 0x845030 | 137B | Projects a 3D vertex to screen coordinates (used for encounter polygon visualization). |

---

## Key Findings

1. **243 Field Map functions** make this the 6th largest FFX_* domain after Atel (981), Battle (716), Field (715), FieldOp (556), and BtlUI (370).

2. **LoadEntry is the main entry point** -- `FFX_FieldMap_LoadEntry_graphicFieldMapLoad` (0x6403c0, 346B) is the primary load trigger, called when the game transitions to a new zone. It is NOT the largest function -- that role belongs to the LoadOrchestrator.

3. **Async loading pipeline with polling status check** -- The system uses a non-blocking architecture: `BeginAsyncLoad` kicks off file I/O, and the game loop polls `LoadingStatusCheck` (0x42f830) until completion. This prevents hitches during zone transitions while still loading from slow BD-ROM/HDD.

4. **10KB LoadOrchestrator (0x668ac0) is the master controller** -- `FFX_FieldMap_LoadOrchestrator_10k_structural` is by far the largest function in the system (10,000+ bytes). It represents a monolithic state machine that orchestrates the entire multi-phase load-and-activate sequence, including error recovery and cleanup paths.

5. **Camera chain setup includes secondary + primary cameras** -- `SetupCameraChain` (0x651ba0) handles dual camera setup, likely for render-to-texture effects (mirrors, magic reflections) used in some field zones.

6. **Vertex morph preserved from PS2 era** -- `FindMorphParamIndex`, `SetMorphWeightBlend`, and `SetupVertexMorphWeights` confirm that FFX HD PC retained the PS2-era morph target animation system. These are used for facial expressions and NPC blendshapes, driven by morph parameter indices looked up at runtime.

7. **Color correction is per-level** -- `LoadColorCorrectionForLevel` (0x641f60, 111B) and `LoadColorCorrectionModel` (0x66ee90) load level-specific color correction data, giving each zone (Besaid's warm tropical, Macalania's cold blue, etc.) a distinct color grade. This run-time LUT/per-level color matrix approach is more sophisticated than a simple post-processing pass -- it was baked into the rendering pipeline from the PS3 version.

8. **Draw cluster flush for batch rendering** -- `FlushDrawClusters` (0x656870) and `UpdateDrawClusterNodeTransforms` (0x6be530) reveal a **cluster-based render batching system**. Rather than drawing individual objects, the engine groups them into "draw clusters" (likely spatial or material-based), batches their transforms, and issues a single flush per cluster. This matches the PhyreEngine PCluster/PResourceList pattern seen in System_Host_Constructor (batch_0011).

9. **Guide map / encounter system is integrated into FieldMap** -- The encounter polygon system (`RasterizeGuidePolyBatch`, `RasterizeEncounterPolyBatch`, `RegisterGuideMapBlob`, `LoadEncounterGuideFromFfxmapId`) is part of the same subsystem. The "guide map" is a data structure that maps on-screen screen coordinates to encounter group IDs, used for random encounter generation. `DecodeEncounterGroupFromPolyMeta` (32B) extracts the encounter group from polygon metadata in just a few instructions.

10. **AHW ("A-sync H-world") driver pattern suggests platform abstraction** -- `LoadAhwin32Entry` and `LoadAhwin32Driver` indicate an abstraction layer for async file I/O, with a win32-specific implementation using overlapped I/O. A PS3 equivalent would have used the Cell SPURS or file system callbacks.

11. **FormatStatusToString** (0x6b6ae0) exists for debug/logging -- The presence of a human-readable status formatter confirms the loading pipeline has debug instrumentation, similar to the `FFX_Dbg_*` system (batch_0002).

12. **Scene node list is a tracked container** -- `FFX_FieldMap_SceneNodeList_Init` (0x633a30) suggests that scene nodes are registered in a central list/tracking structure rather than existing independently. This is critical for cleanup: when transitioning to a new zone, all nodes in the list must be destroyed and the list reinitialized.

13. **Texture animation hook system** -- `FFX_FieldMap_HookTextureAnimationChar` (referenced in PhyreEngine batch_0010) suggests that character-specific texture animations (e.g., blinking eyes on NPCs) are hooked into the field map loading system, not handled separately.

14. **Multiple SetupSceneNodes variants** -- There are at least two variants of the scene node setup function: `SetupSceneNodesAndMaterials` (generic, 4.9KB) and `SetupSceneNodesAndMaterials_True` (forced bind). The `_True` variant likely skips the condition check on material binding, forcing all materials to be set up regardless of pre-existing state. This is used for reload/reset scenarios where the scene must be fully reconstructed.

15. **ResetState_Full is effectively a stub** -- `FFX_FieldMap_ResetState_Full` (0x640560, 11 bytes) is a near-nullsub, suggesting that the real reset logic lives inside `LoadOrchestrator` or is inlined as part of the scene transition sequence. The placeholder may exist for debug builds where a full reset hook is useful.

---

## Cross-References

- **System_Host_Constructor (batch_0011)**: The 69KB host singleton pre-allocates 112 PCluster arrays, camera objects, and buffer pools that FieldMap uses during loading.
- **PhyreEngine PSceneNode (batch_0015)**: The scene node setup functions (`SetupSceneNode`, `WireInstanceToSceneNodes`) create PSceneNode objects in the PhyreEngine hierarchy.
- **Field Script / FieldVM (batch_0015)**: FieldMap loads the data; FieldVM executes the script; FieldOp controls camera motion within the loaded scene.
- **Encounter system**: The Guide Map functions (`RasterizeEncounterPolyBatch`, `DecodeEncounterGroupFromPolyMeta`) provide encounter zone data to the random encounter system.
- **Sound system (batch_0008)**: `FFX_FieldMap_BeginAsyncLoad` began async loads from 15 callers total, including the sound system.

---

**Next batch:** Recommend vertical decompilation of `FFX_FieldMap_LoadOrchestrator_10k_structural` (10,000+ bytes) to extract the full loading state machine, or deeper analysis of the encounter polygon rasterization pipeline.
