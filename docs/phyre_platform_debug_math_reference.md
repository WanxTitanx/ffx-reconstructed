# PhyreEngine SDK 3.1.5.0 -- Platform + Tools Headers Reference

> **Source:** `F:\ffx-reconstructed\EnginesExtras\Phyre_Engine\Phyre Engine\Include\Platform\`
> **Copyright:** (C) 2011 Sony Computer Entertainment Inc. -- SCE CONFIDENTIAL
> **SDK Version:** PhyreEngine(TM) Package 3.1.5.0

**Note:** The `Debug/` and `Math/` directories do not exist in this SDK release. Math types (Vector4, Matrix4, etc.) are provided by the external `Vectormath` library headers included elsewhere. This document covers all 30 `.h` files found under `Platform/`.

---

## 1. PhyrePlatform.h -- Master Platform Dispatcher

**Path:** `Platform/PhyrePlatform.h`

Defines the `Phyre::PPlatform` namespace and conditionally includes platform-specific headers via `PHYRE_RENDERING_PLATFORM_*` macros.

### Classes

#### `PPlatformLoader`
- **Basis:** Inherits `PHYRE_RENDERING_PLATFORM_IMPLEMENTATION(PPlatformLoader)` (resolved to the active platform, e.g., `PPlatformLoaderD3D11`)
- **Member variables:** (inherited from platform-specific subclass)
- **Key functions:**
  - `PResult allocateDataForPlatform(PCluster&, PClusterHeaderBase&)` -- Allocate GPU memory for cluster data
  - `PResult readDataForPlatform(PStreamReader&, PCluster&)` -- Read platform binary data into cluster

#### `PPlatform`
- **Basis:** Inherits `PHYRE_RENDERING_PLATFORM_IMPLEMENTATION(PPlatform)` (resolved to e.g. `PPlatformD3D11`)
- **Key functions:**
  - `static PUInt32 GetPlatformId()` -- Returns the numeric platform identifier

---

## 2. PhyrePlatformConverter.h -- Platform Conversion Framework

**Path:** `Platform/PhyrePlatformConverter.h`

### Classes

#### `PPlatformConverter`
- **Basis:** Inherits `PNamedSemantic<PPlatformConverter>`
- **Member variables:**
  - `const PBinary::PPlatformClassLayout& m_classLayout` -- Binary class layout for serialization
  - `const PInstanceListConvert& m_instanceListConvert` -- Instance list conversion map
- **Key functions:**
  - `const PPlatformConverter* getNext() const` -- Linked list traversal
  - `const PBinary::PPlatformClassLayout& getClassLayout() const`
  - `const PInstanceListConvert& getInstanceListConvert() const`
  - `static PResult RegisterPlatformConverter(PPlatformConverter&)` -- Register a converter
  - `static PResult UnregisterPlatformConverter(PPlatformConverter&)` -- Unregister a converter
  - `static const PPlatformConverter* GetPlatformConverterForInstanceListConvert(PInstanceListConvert&)` -- Lookup

---

## 3. PhyrePlatformShaderConverter.h -- Shader Conversion Pipeline

**Path:** `Platform/PhyrePlatformShaderConverter.h`

### Types

| Typedef | Definition |
|---------|-----------|
| `PCompiledCodeAligned4` | `PArray<PUInt8, 4>` |
| `PCompiledCodeAligned16` | `PArray<PUInt8, 16>` |
| `PMapShaderSourceToFile` | `PMapDynamic<const PString*, PTempShaderFile>` |
| `PMapShaderToParamsAndStreams` | `PMapDynamic<PShaderProgramBase*, PShaderProgramParamsAndStreams*>` |

### Classes

#### `PTempShaderFile`
- **Member variables:**
  - `PString m_name` -- Temp file path
  - `bool m_keepSource` -- Retain source after compilation
- **Key functions:**
  - `PTempShaderFile(const PString& name)`
  - `void keepSource()`

#### `PPlatformShaderConverter`
- **Member variables:**
  - `PMapShaderSourceToFile m_shaderSourceToFile`
  - `PConversionMapping<PShader> m_shaderMappings`
  - `PConversionMapping<PSceneRenderPass> m_sceneRenderPassMappings`
  - `PConversionMapping<PEffectVariant> m_effectVariantMappings`
  - `PConversionMapping<PShaderParameterDefinition> m_shaderParameterDefinitionMappings`
  - `PConversionMapping<PShaderVertexProgram, PShaderProgramBase> m_vertexProgramMappings`
  - `PConversionMapping<PShaderFragmentProgram, PShaderProgramBase> m_fragmentProgramMappings`
  - `PSetDynamic<PInstanceList*> m_instanceListsToDeleteOnReset`
  - `PInstanceListConversionVector& m_instanceLists`
  - `PCluster m_internalCluster`
  - `const PPlatformConverter* m_platformConverter` (protected)
- **Key functions:**
  - `void gatherEffectVariantsAndDupeParameterDefinitions(const PPlatformConverter*)`
  - `void gatherShaderSource(PInstanceListConversionVector&)`
  - `void releaseShaderSource()`
  - `void updateParameterBufferBitness(PInstanceListConversionVector&)`
  - `void addProgramMapping(PShaderVertexProgram&, PShaderProgramBase&)`
  - `void addProgramMapping(PShaderFragmentProgram&, PShaderProgramBase&)`
  - `static PResult GetContextStringsForCompile(PNodeContext&, PEffect&, PArray<PString>&)`
  - `static void CountParametersByType(PShaderProgramParamsAndStreams&, PUInt32& tex, PUInt32& nontex)`
  - `static void PropagateSizesAndOffset(...)` -- For parameters and streams
  - `static PUInt32 GetFrequencyBitfieldForShaderProgramCode(...)`
  - `void distributeNonMaterialParameters(...)`
  - `static void DistributeStreams(PShaderProgramParamsAndStreams&, PShader&)`
  - `static PUInt32 CountNonFoldedShaderPrograms(PEffectVariant&)`
  - `static void StripVariantFoldingInfo(...)` / `StripPassEntryInfo(...)` / `StripPlatformIncludeInfo(...)`
  - `template<T> static PInstanceList* BuildNewInstanceList(PUInt32 count)` -- Allocates uninitialized instance list
  - `template<T> static PInstanceList* BuildNewInstanceList(T* els, PUInt32 count)` -- Wraps existing array
  - `template<T> T* buildAndAddNewInstanceListAndReturnArray(PUInt32 count)`
  - `template<OLD_T, NEW_T> PInstanceList* buildAndAddReplaceInstanceList(...)`
  - `void addNewInstanceList(PInstanceList&)`
  - `void addReplaceInstanceList(PInstanceList& old, PInstanceList& new)`

#### `PPlatformShaderConverterForPlatform<SHADER_PASS_TYPE>`
- **Basis:** Inherits `PPlatformShaderConverter`
- **Member variables:**
  - `PMapOldPassToNewPass m_oldToNewPass` -- typedef: `PConversionMapping<const PShaderPass, SHADER_PASS_TYPE>`
- **Key functions:**
  - `void gatherShaderPassesAndShadersAndSceneRenderPasses(const PPlatformConverter*)`
  - `PResult propagateParameterBufferOffsetsToShaderPasses(PEffectVariant&, PClassLayoutInterface&, PMapShaderToParamsAndStreams&)`
  - `PResult processFoldedContextVariantsAndShaders(PEffectVariant&, PMapShaderToParamsAndStreams&)`
  - `PResult compileEffectVariant(PEffectVariant&, PMapShaderToParamsAndStreams&)`
  - `void convertEffectVariantParameterLayouts(PInstanceListConversionVector&)`
  - `static void RecordReplacementShaderPass(SHADER_PASS_TYPE&, PShaderPass&, void*)`

---

## 4. PhyreInstanceListConvertState.h -- Conversion State Base

**Path:** `Platform/PhyreInstanceListConvertState.h`

### Classes

#### `PConversionMapping<CONVERTED_FROM, CONVERTED_TO>`
- **Basis:** Inherits `PMapDynamic<const CONVERTED_FROM*, CONVERTED_TO*>`
- **Key functions:**
  - `void forAllMappings(void (*fn)(CONVERTED_TO&, const CONVERTED_FROM&, void*), void*) const`
  - `CONVERTED_TO* findNewForOld(const CONVERTED_FROM*) const`
  - `const CONVERTED_FROM* findOldForNew(CONVERTED_TO*) const`

#### `PMoppMapKey` (Havok only -- `PHYRE_PHYSICS_PLATFORM_HAVOK`)
- **Member variables:**
  - `PGeometry::PShape* m_shape`
  - `float m_sx, m_sy, m_sz` -- MOPP scale per axis
- **Key functions:**
  - `bool operator<(const PMoppMapKey&) const` -- Lexicographic sort

#### `PInstanceListConvertState`
- **Basis:** Inherits `PMemoryBase`
- **Member variables (conditional):**
  - **Havok:** `PMoppMap m_moppMap`, `PPhysicsMeshMap m_physicsMeshMap`, `bool m_useMoppChunkSubdivision`, `std::vector<PPhysicsHavokMoppData*> m_allocatedMopps`
  - **FMOD:** `PUInt32 m_fmodFlags`
- **Key functions:**
  - Constructor / virtual destructor

**Type aliases (Havok):**
- `PMoppMap = PMapDynamic<PMoppMapKey, PPhysicsHavokMoppData*>`
- `PPhysicsMeshMap = PConversionMapping<PPhysics::PPhysicsMesh>`

---

## 5. Platform Backend Headers

### 5a. PhyrePlatformGeneric.h
**Path:** `Platform/Generic/PhyrePlatformGeneric.h`

#### `PPlatformLoaderGeneric`
- `PResult allocateDataForPlatform(PCluster&, PClusterHeaderBase&)`
- `PResult readDataForPlatform(PStreamReader&, PCluster&)`

#### `PPlatformGeneric`
- `static PUInt32 GetPlatformId()`
- `static PResult Bind()`

---

### 5b. PhyrePlatformNull.h
**Path:** `Platform/Null/PhyrePlatformNull.h`

#### `PPlatformLoaderNull`
- `PResult allocateDataForPlatform(PCluster&, PClusterHeaderBase&)`
- `PResult readDataForPlatform(PStreamReader&, PCluster&)`

#### `PPlatformNull`
- `static PUInt32 GetPlatformId()`
- `static PResult Bind()`

---

### 5c. PhyrePlatformGCM.h (PS3 RSX)
**Path:** `Platform/GCM/PhyrePlatformGCM.h`

#### `PGpuSyncableGCM`
- **Basis:** Inherits `PBase`
- **Enum `PSyncableState`:** `NOSYNC=0`, `READMAPPED`, `WRITEMAPPED`, `SYNC`
- **Member variables:**
  - `mutable PUInt32 m_syncVal`
  - `mutable PSyncableState m_syncState`
- **Key functions:**
  - `PGpuSyncableGCM()`

#### `PPlatformLoaderGCM`
- **Member variables:**
  - `PUInt32 m_vramBufferSize` / `PCoreGcmMemoryBlock* m_vramMemoryBlock`
  - `PUInt32 m_hostBufferSize` / `PCoreGcmMemoryBlock* m_hostMemoryBlock`
- **Key functions:**
  - `PResult allocateDataForPlatform(...)` / `PResult readDataForPlatform(...)`

#### `PPlatformGCM`
- `static PUInt32 GetPlatformId()` / `static PResult Bind()`

#### `PSNTunerProfileBlock` (conditional: `PHYRE_ENABLE_CPU_PERF_ANALYSIS`)
- RAII profiler for SN Tuner CPU instrumentation
- `PSNTunerProfileBlock(const PChar* name)` / `~PSNTunerProfileBlock()`

---

### 5d. PhyrePlatformGXM.h (PS Vita)
**Path:** `Platform/GXM/PhyrePlatformGXM.h`

#### `PGpuSyncableGXM`
- **Basis:** Inherits `PBase`
- **Enum `PSyncableState`:** `NOSYNC=0`, `READMAPPED`, `WRITEMAPPED`, `VERTEXSYNC`, `FRAGMENTSYNC`
- **Member variables:**
  - `const PGpuSyncableGXM* m_parent` (protected)
  - `mutable PUInt32 m_syncVal`
  - `mutable PSyncableState m_syncState`
- **Key functions:**
  - `void setParentSyncable(const PGpuSyncableGXM*)` -- Hierarchical sync
  - `void setSyncState(PSyncableState) const`
  - `void setSyncStateAndVal(PSyncableState, PUInt32) const`
  - `PSyncableState getSyncState() const`
  - `PUInt32 getSyncVal() const`

#### `PPlatformLoaderGXM`
- **Member variables:**
  - `PMemoryBlockGXM* m_memoryBlock`
  - `PUInt32 m_textureBufferSize, m_indexBufferSize, m_vertexBufferSize`
  - `PUInt32 m_offsetOfTexturesInBuffer, m_offsetOfIndicesInBuffer, m_offsetOfVerticesInBuffer`
- **Key functions:**
  - `PResult allocateDataForPlatform(...)` / `PResult readDataForPlatform(...)`

#### `PPlatformGXM`
- `static PUInt32 GetPlatformId()` / `static PResult Bind()`

#### `PRazorProfileBlock` (conditional: `PHYRE_ENABLE_CPU_PERF_ANALYSIS`)
- RAII profiler for SCE Razor CPU instrumentation
- `static void Initialize()/Terminate()/InitializeThread()/TerminateThread()`
- Constructor calls `sceRazorCpuPushMarker(name)`, destructor calls `sceRazorCpuPopMarker()`

**Constant:** `PD_GXM_TEXTURE_ALIGNMENT_REQUIREMENT = 16` (UBC requires 16-byte alignment)

---

### 5e. PhyrePlatformGL.h (OpenGL)
**Path:** `Platform/GL/PhyrePlatformGL.h`

#### `PPlatformLoaderGL`
- **Member variables:**
  - `void* m_vertexBuffer` / `void* m_indexBuffer`
  - `PUInt32 m_vertexBufferID, m_indexBufferID, m_pixelBufferID`
  - `PUInt32 m_vertexBufferSize, m_indexBufferSize, m_maxTextureBufferSize`
- **Key functions:**
  - `PResult allocateDataForPlatform(...)` / `PResult readDataForPlatform(...)`

#### `PPlatformGL`
- `static PUInt32 GetPlatformId()` / `static PUInt32 GetPlatformIdx64()` / `static PResult Bind()`

---

### 5f. PhyrePlatformD3D11.h (Direct3D 11 -- **FFX HD PC target**)
**Path:** `Platform/D3D11/PhyrePlatformD3D11.h`

#### `PPlatformLoaderD3D11`
- **Member variables:**
  - `void* m_vertexBuffer` / `void* m_indexBuffer`
  - `PUInt32 m_vertexBufferID, m_indexBufferID, m_pixelBufferID`
  - `PUInt32 m_vertexBufferSize, m_indexBufferSize, m_maxTextureBufferSize`
- **Key functions:**
  - `PResult allocateDataForPlatform(...)` / `PResult readDataForPlatform(...)`

#### `PPlatformD3D11`
- `static PUInt32 GetPlatformId()` / `static PUInt32 GetPlatformIdx64()` / `static PResult Bind()`

**Note:** GL and D3D11 loaders share identical member layouts. The `GetPlatformIdx64()` distinguishes them from GCM/GXM which lack 64-bit index support.

---

## 6. Tools Headers

### 6a. PhyreUniqueShaderDatabase.h -- Deduplicated Shader Cache
**Path:** `Platform/Tools/PhyreUniqueShaderDatabase.h`

#### `PUniqueShaderDatabaseTreeKey`
- **Member variables:**
  - `static PUInt32 s_crcTable[256]` -- CRC32 lookup
  - `PUInt32 m_hash` -- Hash of program code
  - `PArray<PUInt8> m_programCode` -- Compiled shader bytecode
- **Key functions:**
  - `static PUInt32 CalcCRC32(const PUInt8* data, PUInt32 size)`
  - `PResult setCode(...)` -- Multiple overloads (PArray, PString, PStringBuilder)
  - `PResult setCodeByReference(...)` -- Zero-copy variant
  - `void releaseCode()`
  - `static PInt32 Compare(key1, key2)` -- Sort by hash -> length -> memcmp

#### `PUniqueShaderDatabaseTreeNodeBase`
- **Basis:** Inherits `PRedBlackTreeNode` + `PUniqueShaderDatabaseTreeKey`

#### `PUniqueShaderDatabaseTreeNode<PAYLOAD>`
- **Basis:** Inherits `PUniqueShaderDatabaseTreeNodeBase`
- **Member variables:**
  - `PAYLOAD m_payload` -- Platform-specific payload

#### `PUniqueShaderDatabaseBase`
- **Basis:** Inherits `PRedBlackTree`
- **Member variables:**
  - `PCriticalSectionSimple m_mutex` (protected)

#### `PUniqueShaderDatabase<PAYLOAD>`
- **Basis:** Inherits `PUniqueShaderDatabaseBase` (template, empty body)

#### `PUniqueShaderDatabaseTokenBase`
- **Member variables:**
  - `PCriticalSectionSimpleLock m_lock` (protected)

#### `PUniqueShaderDatabaseToken<PAYLOAD>`
- **Basis:** Inherits `PUniqueShaderDatabaseTokenBase`
- **Member variables:**
  - `PDatabase& m_database`
- **Key functions:**
  - `PTreeNode* find(KEY_TYPE& code)` -- Thread-safe lookup
  - `PResult insert(PTreeNode& node)` -- Thread-safe insert

---

### 6b. PhyrePlatformConverterUtil.h -- DXT Decode + Texture Transcoding
**Path:** `Platform/Tools/PhyrePlatformConverterUtil.h`

#### `PIntermediateConversion<TARGET>`
- **Member variables:**
  - `TARGET* m_target`

#### `PPlatformConverterUtil`

**Inner class `PRGBA`:**
- `PUInt8 m_rgba[4]`
- `void setDecode565(PUInt16)`, `void setHalf(a, b)`, `void setTwoThirds(a, b)`
- `void setUInt(PUInt32)`, `PUInt32 getUInt() const`

**Inner class `PDXTBlockDecoder`:**
- `static PUInt32* DecodeDXTRow(PUInt8 row, PUInt32* p, PUInt32 c[4])`
- `static void DecodeRows(PDXT1Block&, row0..row3)` -- DXT1
- `static void DecodeRows(PDXT3Block&, row0..row3)` -- DXT3
- `static void DecodeRows(PDXT5Block&, row0..row3)` -- DXT5
- `template<T> static void DecodeBlocks(srcPixels, pixels, width, height)` -- Decode full texture

**Static methods:**
- `static void DecompressDxtToRgba(PTexture2D& dest, PTexture2D& src)`
- `static void DecompressDxtToRgba(PTextureCubeMap& dest, PTextureCubeMap& src)`
- `static PFnSetTexel SetTexelFn(PTextureFormat&)` / `static PFnGetTexel GetTexelFn(PTextureFormat&)`
- `static void TranscodeTexture(PTexture2D&, PTexture2D&, destFormat, getTexel, setTexel)`
- `static void TranscodeTexture(PTextureCubeMap&, PTextureCubeMap&, destFormat, getTexel, setTexel)`
- `static PString GetTempPath(const PChar* basis)`
- `static PResult SaveShaderSource(const PChar* source, PString& tempSourcePath)`
- `template<ALIGNMENT> static void ReadFileToArray(PArray<PUInt8,ALIGNMENT>&, PChar* name, PChar* desc)`
- `static PUInt32 GetFileSize(const PChar* name)`
- `static PString RunDOSCommand(const PChar* command)`
- `static bool IsDBSAvailable()`
- `static PString RunDBSScript(const PChar* script, const PChar* project, const PChar* outputFilename = NULL)`

#### `PDBSScript`
- **Member variables:**
  - `PStringBuilder m_scriptBuilder`
  - `PArray<PString> m_outputFilePerJob`
- **Key functions:**
  - `PDBSScript(PUInt32 jobCount)` / destructor

---

### 6c. PhyrePlatformModifierUtils.h -- Mesh Modifier Injection
**Path:** `Platform/Tools/PhyrePlatformModifierUtils.h`

#### `PModifierNetworkAddModifier`
- **Member variables:**
  - `PCluster* m_clusterForModifierNetworkInfoPacket` (protected)
- **Key functions (protected virtual):**
  - `virtual PModifier* selectModifierForSegment(PMeshSegment&, PMaterial*, PModifierNetwork*)` -- Override per-segment
  - `virtual PModifierNetwork* allocateModifierNetwork(PModifierNetwork* old)`
  - `virtual PModifierNetworkDynamicMesh* allocateModifierNetworkDynamicMesh(...)`
  - `virtual PModifierNetworkDynamicMeshInstance* allocateModifierNetworkDynamicMeshInstance(...)`
  - `virtual PDynamicDataBlock* findOrCreateDynamicDataBlock(PDataBlock&)`
- **Static helpers:**
  - `static const PModifier& SelectSkinModifierForMeshSegment(PMeshSegment&)`
  - `static bool HasSkinnableStreamAndNoSkinningModifier(PMeshSegment&, PModifierNetwork*)`
- **Public:**
  - `PResult addModifiersToMeshInstance(PMeshInstance&)`

---

### 6d. PhyreTextureSwizzle.h -- Morton-Order Texture Swizzling
**Path:** `Platform/Tools/PhyreTextureSwizzle.h`

#### Enum `PSwizzleMortonOrder`
- `PE_SWIZZLETEXTURE_MORTON_XY = 0` -- Address pattern: ...XYXYXYXY
- `PE_SWIZZLETEXTURE_MORTON_YX = 1` -- Address pattern: ...YXYXYXYX

#### Free functions
- `PResult SwizzleTextureData(void* dst, const void* src, PUInt32 bpp, PUInt32 width, PUInt32 height, PSwizzleMortonOrder)`
- `PResult UnswizzleTextureData(void* dst, const void* src, PUInt32 bpp, PUInt32 width, PUInt32 height, PSwizzleMortonOrder)`
- `PUInt32 SwizzleTexture2DSize(PTexture2DGeneric&)`
- `PUInt32 SwizzleTexture3DSize(PTexture3DGeneric&)`
- `PUInt32 SwizzleTextureCubeMapSize(PTextureCubeMapGeneric&)`
- `PResult SwizzleTexture2D(PArray<PUInt8>&, PTexture2DGeneric&, PSwizzleMortonOrder)`
- `PResult SwizzleTexture3D(PArray<PUInt8>&, PTexture3DGeneric&, PSwizzleMortonOrder)`
- `PResult SwizzleTextureCubeMap(PArray<PUInt8>&, PTextureCubeMapGeneric&, PSwizzleMortonOrder)`

---

### 6e. PhyreLuaChunkRewriter.h -- Lua Bytecode Rewriter
**Path:** `Platform/Tools/PhyreLuaChunkRewriter.h`

#### `PLuaHeader`
- **Member variables:**
  - `PUInt8 m_sig[4]` -- Lua binary signature (0x1B 0x4C 0x75 0x61 = ESC "Lua")
  - `PUInt8 m_version` -- Lua version
  - `PUInt8 m_formatVersion` -- 0 = official
  - `PUInt8 m_endiannessFlags` -- 0=big, 1=little
  - `PUInt8 m_intSize` -- sizeof(int)
  - `PUInt8 m_sizetSize` -- sizeof(size_t)
  - `PUInt8 m_instrSize` -- sizeof(instruction)
  - `PUInt8 m_numberSize` -- sizeof(lua_Number)
  - `PUInt8 m_integral` -- 0=fp, 1=int
- **Key functions:**
  - `PLuaHeader()`

#### Free function
- `PResult RewriteLuaChunk(PArray<PUInt8>& dest, const PArray<PUInt8>& source, const PLuaHeader& destSpec)`

---

## 7. Platform-Specific Shader Compilation

### 7a. PhyreShaderCompressGCM.h (PS3 RSX Cg -> SPU microcode)
**Path:** `Platform/GCM/Tools/PhyreShaderCompressGCM.h`

#### `PConstantSourceInfo`
- **Member variables:** `PUInt32 m_constantIndex`, `PUInt32 m_constantLength`

#### `PShaderCompressGCM` -- All static methods
- `static PString GetPS3SdkPath()`
- `static PResult CompileSourceToRsxBinaryFromFile(filename, source, compiledCode, errorString, profile)`
- `static PResult CompileSourceToRsxBinary(source, compiledCode, errorString, profile)`
- `static bool InstrsEqual(PCgInstrGCM&, PCgInstrGCM&)`
- `static bool InstrsEqualMasked(instr1, instr2, mask)`
- `static PUInt32 FindOrInsertInstr(PCgCodebookGCM&, PArray<PUInt32>& freq, PCgInstrGCM&)`
- `static PUInt32 FindOrInsertInstrMasked(...)` -- With mask
- `static PUInt32 MapTexUnit(CGresource)` / `MapAttribute(CGresource)`
- `static PUInt32 CountParameters(...)` / `CountTexParameters(...)`
- `static bool ParameterOffsetsAreValid(CGprogram, CGparameter, PUInt32 microcodeSize)`
- `static PUInt32 GetConstantRowCountForParameter(CGprogram, CGparameter)`
- `static CGparameter CaptureDefaultValues(PCgDefaultValueGCM*&, CGprogram, CGparameter)`
- `static CGparameter GetFirstArrayParameter(CGprogram, name)`
- `static CGparameter CountDefaultValues(...)` / `static PUInt32 CountDefaultValues(...)`
- `static CGparameter CountPatchables(...)` / `static PUInt32 CountPatchables(...)`
- `static void PopulateVpParameters(...)` / `PopulateFpParameters(...)`
- `static PUInt16 GetTexture2DBitfield(...)` / `GetTexture3DBitfield(...)` / `GetTextureCubeMapBitfield(...)`
- `static void PopulateTexParameters(...)`
- `static PUInt16 PopulateStreams(...)`
- `static void PopulateDefaultValues(...)`
- `static bool PopulateFpConstantPatches(...)`
- `static void AdjustRegisterCount(...)`
- `static void ProcessVp(...)` / `ProcessFp(...)` -- Full pipeline

---

### 7b. PhyreCodebookOptimizeGCM.h -- RSX Microcode Codebook Optimizer
**Path:** `Platform/GCM/Tools/PhyreCodebookOptimizeGCM.h`

#### `PBitfieldGCM`
- **Member variables:** `PArray<PUInt32> m_bits`
- **Key functions:** `setSize(bitCount)`, `setBit(idx)`, `getBit(idx)`, `get32Bits(idx)`, `countBitsSet()`, `countBitsIntersected(other)`, `intersects(other)`, `operator&=`, `operator|=`, `andNot(other)`

#### `PProgInstrGroupGCM`
- `PArray<PUInt32> m_instrIndices`, `PUInt32 m_totalFreq`, `PUInt32 m_highLow`

#### `PProgInstrMapGCM`
- `PBitfieldGCM m_instrBitfield`, `PArray<PUInt32> m_instrGroupIndices`

#### `PCodebookCostGCM`
- `PUInt32 m_totalSpan, m_maxSpan, m_programCount, m_instructionCount, m_codebookSize`

#### Enum `PCodebookOptimizationGCM`
- `PE_CODEBOOKOPT_LINEAR=0`, `PE_CODEBOOKOPT_BELL`, `PE_CODEBOOKOPT_HYBRID`, `PE_CODEBOOKOPT_COUNT`

#### `PCodebookOptimizeGCM` -- All static
- `OptimizeVertexProgramCodebook(...)` / `OptimizeFragmentProgramCodebook(...)`
- `BuildInstructionGroups(...)` / `BuildAllOptimizationMappings(...)`
- `OptimizeCodebookWithProgMaps(strategy, size, instrGroups, progMaps, oldToNewIndex)`
- `OptimizeCodebook(strategy, codebook, freqs, oldToNewIndex)`
- `BuildArrayOfVpsThatAreUsingCodebook(...)` / `BuildArrayOfFpsThatAreUsingCodebook(...)`
- `EvaluateVpsCostWithRemap(...)` / `EvaluateFpsCostWithRemap(...)`
- `RemapVpInstrs(...)` / `RemapFpInstrs(...)`

---

### 7c. PhyreBufferConvertGCM.h -- Vertex/Index Buffer Conversion
**Path:** `Platform/GCM/Tools/PhyreBufferConvertGCM.h`

#### `PBufferConvertElementDescription`
- `PTypeID m_type`, `PUInt32 m_offset`
- `PConvertElement getConvertCallback() const`

#### `PBufferConvertGCM` -- All static
- `ConvertBuffer(destBuffer, srceBuffer, count, stride, elements)`
- `ConvertIndexBuffer(dest, PIndexDataBlockGeneric&)`
- `ConvertVertexBuffer(dest, PDataBlockGeneric&)`

---

### 7d. PhyrePlatformConverterGCM.h -- PS3 Conversion State
**Path:** `Platform/GCM/Tools/PhyrePlatformConverterGCM.h`

#### `PPayloadGCM<GEN, GCM>`
- `GEN* m_generic`, `GCM* m_gcm` -- Pairs Generic/GCM shader pointers

**Type aliases:**
| Alias | Definition |
|-------|-----------|
| `PVpPayloadGCM` | `PPayloadGCM<PShaderVertexProgram, PShaderVertexProgramGCM>` |
| `PFpPayloadGCM` | `PPayloadGCM<PShaderFragmentProgram, PShaderFragmentProgramGCM>` |
| `PVpDatabaseGCM` | `PUniqueShaderDatabase<PVpPayloadGCM>` |
| `PFpDatabaseGCM` | `PUniqueShaderDatabase<PFpPayloadGCM>` |
| `PVpNodeGCM` / `PFpNodeGCM` | Tree node types |

#### `PThreadPoolCompileSharedInfoGCM`
- Shared state across multi-threaded Cg compilation
- `PInstanceListConvertStateGCM& m_state`
- `PArray<PCgCodebookGCM*>& m_codebooks, m_codebookMasks`
- `PArray<PVpDatabaseGCM*>& m_vpUniqueShaderDatabases`
- `PArray<PFpDatabaseGCM*>& m_fpUniqueShaderDatabases`
- `PFreeListThreadSafe& m_uniqueDatabaseShaderNodeFreelist`
- `PArray<PArray<PUInt32>>& m_codebookFrequencies`
- `const PString& m_code`
- `const PArray<PString>* m_prebuiltShaders`

#### `PThreadPoolCompileGcmCgJob`
- **Basis:** Inherits `PThreadPoolJob`
- **Member variables:**
  - `PString m_entry` -- Shader entry point
  - `PArray<PString> m_compileOptions`
  - `const PChar* m_profile`
  - `PUInt32 m_codebookIndex`
  - `PShaderPassGCM* m_pass`
  - `PShaderProgramParamsAndStreams m_paramsAndStreams`
  - `PShaderVertexProgram* m_genericVertexProgram` / `PShaderVertexProgramGCM* m_vertexProgram`
  - `PVpNodeGCM* m_uniqueVp`
  - `PShaderFragmentProgram* m_genericFragmentProgram` / `PShaderFragmentProgramGCM* m_fragmentProgram`
  - `PFpNodeGCM* m_uniqueFp`
  - `PThreadPoolCompileSharedInfoGCM* m_sharedInfo`
  - `PUInt32 m_id`

#### `PThreadPoolOptimizeCodebookJob`
- **Basis:** Inherits `PThreadPoolJob`
- **Member variables:** `bool m_isVertex`, `PCgCodebookGCM* m_codebook`, `PArray<PUInt32>* m_frequencies`, `const PInstanceListConvertStateGCM* m_state`

#### `PInstanceListConvertStateGCM`
- **Basis:** Inherits `PInstanceListConvertState` + `PPlatformShaderConverterForPlatform<PShaderPassGCM>`
- **Member variables:**
  - `PMappingTableGCM<PTexture2D, PTexture2DGCM> m_texture2DMappings`
  - `PMappingTableGCM<PTexture3D, PTexture3DGCM> m_texture3DMappings`
  - `PMappingTableGCM<PTextureCubeMap, PTextureCubeMapGCM> m_textureCubeMapMappings`
  - `PMappingTableGCM<PDataBlockGeneric, PDataBlockGCM> m_dataBlockMappings`
  - `PMappingTableGCM<PIndexDataBlockGeneric, PIndexDataBlockGCM> m_indexDataBlockMappings`
  - `PMappingTableGCM<PDynamicDataBlock, PDynamicDataBlock> m_dynamicDataBlockMappings`
  - `PMappingTableGCM<PDataBlockGeneric, PDynamicDataBlock> m_allocatedDynamicDataBlockTable`
  - `PArray<PUnpatchableFragmentShaderGCM> m_unpatchableFragmentPrograms`
  - `PCriticalSectionSimple m_unpatchableFpCriticalSection`
  - `PMappingTableGCM<...> m_modifierNetworkDynamicMeshMappings`
  - `PMappingTableGCM<...> m_modifierNetworkDynamicMeshInstanceMappings`
  - `PUInt32 m_vramBufferSize`, `m_hostBufferSize`
- **Key functions:**
  - `PAllocatePlatformData allocateVramPlatformDataSpace(size, align)`
  - `PResult writeVramPlatformData(writer, data, size, align, expectedOffset)`
  - `PAllocatePlatformData allocateHostPlatformDataSpace(size, align)`
  - `PResult writeHostPlatformData(writer, data, size, align, expectedOffset)`
  - `PTexture2DGCM* findNewForOld(PTexture2D&)` (and 3D, CubeMap variants)
  - `PDataBlockGCM* findNewForOld(PDataBlockGeneric&)`
  - `PDynamicDataBlock* findOrCreateDynamicDataBlock(PDataBlockGeneric&)`

#### `PMappingTableGCM<OLD, NEW>`
- **Key functions:** `add(old, newItem)`, `findNewForOld(old)`, `getOld(i)`, `getNew(i)`, `reset()`, `getCount()`

---

### 7e. PhyreShaderCompileGXM.h (PS Vita Cg Compiler)
**Path:** `Platform/GCM/Tools/PhyreShaderCompileGXM.h`

#### `PShaderProgramParamsAndStreamsGXM`
- **Basis:** Inherits `PShaderProgramParamsAndStreams`
- **Member variables:**
  - `PArray<PCgBindingParameterInfoGXM> m_parameters`
  - `PArray<PUInt8> m_textureParameterIds`
  - `PArray<PUInt16> m_streamIds`
  - `PUInt16 m_allActiveTexturesBitField[PE_SHADER_PARAMETER_FREQUENCY_COUNT]`
  - `PUInt32 m_allActiveTexturesCubeMap`

#### `PShaderCompileUsingCommandLineGXM` -- All static
- `GetCommandLineForCompile(source, sourceFile, outputFile, profile, cmdLine)`
- `GetCommandLineForCgNm(inputFile, cmdLine)`
- `SortParametersByFrequency(PShaderProgramParamsAndStreamsGXM&)`
- `CompileSourceToGxmBinary(source, tempFile, compiledCode, cgnmOutput, profile)`
- `ParseCgNmOutputToParametersAndStreams(cgnmOutput, code, paramsAndStreams)`

#### `PCgcInterfaceGXM` -- DLL-loaded PSP2Cgc compiler
- **24 function pointers** for: `initializeCompileOptions`, `compileProgram`, `destroyCompileOutput`, `getFirstParameter`, `getNextParameter`, `getParameterName`, `getParameterSemantic`, `getParameterUserType`, `getParameterClass`, `getParameterVariability`, `getParameterDirection`, `getParameterBaseType`, `isParameterReferenced`, `getParameterResourceIndex`, `getParameterBufferIndex`, `getFirstStructParameter`, `getArraySize`, `getArrayParameter`, `getParameterVectorWidth`, `getParameterColumns`, `getParameterRows`, `getParameterMemoryLayout`, `getRowParameter`, `getSamplerQueryFormatWidth/PrecisionCount/Precision`
- **Member variables:** `HMODULE m_module`, all function pointers above, `PChar m_sdbCachePath[MAX_PATH]`
- **Key functions:**
  - `const ScePsp2CgcCompileOutput* compileSourceToGxmBinary(source, tempFile, compiledCode, profile) const`
  - `PResult parseParametersAndStreams(compileOutput, paramsAndStreams) const`
  - `PResult parseParameters(compileOutput, paramsAndStreams) const`
  - `static SceGxmParameterType BaseTypeToGxmType(ScePsp2CgcParameterBaseType)`

---

### 7f. PhyrePlatformConverterGXM.h -- PS Vita Conversion State
**Path:** `Platform/GXM/Tools/PhyrePlatformConverterGXM.h`

#### `PInstanceListConvertStateGXM`
- **Basis:** Inherits `PInstanceListConvertState` + `PPlatformShaderConverterForPlatform<PShaderPassGXM>`
- **Member variables:**
  - `PArray<PUInt8> m_indexData, m_vertexData, m_textureData`
  - `PCgcInterfaceGXM m_cgcIface`
  - `PVertexCacheOptimizerGXM m_vertexOptimizeIface`

#### `PVertexCacheOptimizerGXM` (PInternal)
- Wraps `sce_psp2vertexcache.dll`
- `int vertexCacheOptimizeTriangleList(void* indices, unsigned numIndices, ScePsp2VertexCacheIndexFormat, const SceMemoryAllocator*)`

#### `PPlatformConverterUtilGXM`
- `static PString GetPSP2SdkPath()`

---

### 7g. PhyreTextureConverterGXM.h -- Vita Texture Conversion
**Path:** `Platform/GXM/Tools/PhyreTextureConverterGXM.h`

#### `PTextureConverterGXM`
- `static void ConvertToGxtViaPvr(gxtPath, ddsPath, pvrFormatStr, PSP2SdkPath)`
- `static void ConvertToGxt(gxtPath, srcePath, PSP2SdkPath)`
- `static PResult ConvertTextureToTarget(dest, PTexture2DGXM&, PTexture2D&)`
- `static PResult ConvertTextureToTarget(dest, PTextureCubeMapGXM&, PTextureCubeMap&)`

---

## 8. Platform Converter States -- D3D11 + GL

### 8a. PhyrePlatformConverterD3D11.h
**Path:** `Platform/D3D11/Tools/PhyrePlatformConverterD3D11.h`

#### `PInstanceListConvertStateD3D11`
- **Basis:** Inherits `PInstanceListConvertState` + `PPlatformShaderConverterForPlatform<PShaderPassD3D11>`
- **Member variables:**
  - `PArray<const PIndexDataBlockGeneric*> m_indices`
  - `PArray<const PDataBlockGeneric*> m_vertices`
  - `PArray<const PTexture2D*> m_textures`
  - `PArray<const PTexture3D*> m_3dTextures`
  - `PArray<const PTextureCubeMap*> m_cubeMapTextures`
  - `PUInt32 m_indexOffset, m_vertexOffset`
  - `PUInt32 m_textureDataSize, m_3dTextureDataSize, m_cubeMapTextureDataSize`
  - `PUInt32 m_maxTextureBufferSize`
- **Key functions:**
  - `PUInt32 getNextVertexDataOffset() const` / `getNextIndexDataOffset() const`
  - `operator+=` overloads for IndexDataBlock, DataBlock, Texture2D, Texture3D, TextureCubeMap
  - `void updateHeaderForPlatform(PClusterHeaderD3D11&) const`
  - `PResult writeDataForPlatform(PStreamWriter&) const`

#### `PInstanceListConvertStateD3D11x64`
- **Basis:** Inherits `PInstanceListConvertStateD3D11`

#### Type alias
- `PDataBlockConversionsD3D11 = PConversionMapping<PDataBlockGeneric, PDataBlockD3D11>`

---

### 8b. PhyrePlatformConverterGL.h
**Path:** `Platform/GL/Tools/PhyrePlatformConverterGL.h`

#### `PInstanceListConvertStateGL`
- **Basis:** Inherits `PInstanceListConvertState` + `PPlatformShaderConverterForPlatform<PShaderPassGL>`
- **Member variables:** Same pattern as D3D11 (indices, vertices, textures, offsets, sizes)
  - Additional: `PDataBlockConversionsGL m_dataBlockMappings`
- **Key functions:** Same operator+= pattern, `updateHeaderForPlatform(PClusterHeaderGL&)`, `writeDataForPlatform(PStreamWriter&)`

#### `PInstanceListConvertStateGLx64`
- **Basis:** Inherits `PInstanceListConvertStateGL`

#### Type alias
- `PDataBlockConversionsGL = PConversionMapping<PDataBlockGeneric, PDataBlockGL>`

---

### 8c. PhyrePlatformConverterGeneric.h / Null.h
**Path:** `Platform/Generic/Tools/PhyrePlatformConverterGeneric.h`, `Platform/Null/Tools/PhyrePlatformConverterNull.h`

Both provide only a single bind function:
- `PResult BindPlatformConverterGeneric(PUInt32 platformId)`
- `PResult BindPlatformConverterNull(PUInt32 platformId)`

---

## 9. Key Observations for FFX HD PC Reverse Engineering

1. **D3D11 is the target platform.** FFX HD PC uses `PHYRE_RENDERING_PLATFORM_D3D11`. The `PPlatformLoaderD3D11` with `m_vertexBuffer`/`m_indexBuffer`/`m_pixelBuffer` triplet is the runtime path. `PInstanceListConvertStateD3D11` is what serialized all cluster data in the shipped binary.

2. **`PPlatform::GetPlatformId()`** returns the numeric platform ID baked into the FFX.exe cluster headers. This is what `PPlatformLoader::allocateDataForPlatform()` uses to dispatch memory allocation.

3. **Unique Shader Database** (`PUniqueShaderDatabase`) is how Phyre deduplicates compiled shaders. The red-black tree keys on CRC32+memcmp of shader bytecode. The FFX.exe likely uses this to minimize RSX/D3D shader count.

4. **Lua Chunk Rewriter** (`PLuaHeader` / `RewriteLuaChunk`) confirms PhyreEngine embeds Lua. The header format (0x1B4C7561 + version + endianness) is standard Lua 5.x binary chunk format. FFX's ATEL scripting VM uses Lua bytecode.

5. **Texture Swizzling** (`SwizzleTextureData`/`UnswizzleTextureData`) with Morton order is relevant for PS3/PS2-era texture data. The PC port likely unswizzles at load time.

6. **GCM codebook optimization** is PS3-specific (RSX microcode). Not present in the PC build, but the `PCgCodebookGCM` structures explain the binary format of PS3 cluster data if cross-referencing.

7. **GL/D3D11 share identical loader layouts** -- only the platform ID and header types differ. This means the PC binary's cluster loading code is structurally identical to what would run on GL (Linux/Mac).
