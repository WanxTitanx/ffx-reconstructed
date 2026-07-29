# PClassDescriptor Function Inventory

**Database:** ffxoficial.exe.i64 (worker port 58018, session 09f6d736 original)
**Query:**  |  | 
**Generated:** 2026-07-27

## Summary

| Metric | Value |
|---|---|
| Total functions | 1364 |
| Has type info | 1364/1364 (100%) |

### Size Distribution

| Bucket | Count | Percentage |
|---|---|---|
| 0x3-0x11 (3-17 bytes) | 769 | 56.4% |
| 0x12 (18 bytes) | 42 | 3.1% |
| 0x13-0x1F (19-31 bytes) | 231 | 16.9% |
| 0x20-0x50 (32-80 bytes) | 252 | 18.5% |
| 0x51-0x100 (81-256 bytes) | 65 | 4.8% |
| 0x100+ (257+ bytes) | 5 | 0.4% |
| **Total** | **1364** | **100.1%** |

### All Unique Sizes

| Size (hex) | Size (bytes) | Count | Examples |
|---|---|---|---|
| 0x3 | 3 | 28 | Phyre_PClassDescriptor_Field0_getter, Phyre_PClassDescriptor_Field0_getter_0, Phyre_PClassDescriptor_Field0_getter_1 |
| 0x4 | 4 | 29 | Phyre_PClassDescriptor_Deref_PAnimationWeightedBlenderController, Phyre_PClassDescriptor_Deref_PAnimationWeightedBlenderController_B, Phyre_PClassDescriptor_DerefThis_PAnimationEventController |
| 0x5 | 5 | 106 | Phyre_PClassDescriptor_CanConvert_False_4B08A0, Phyre_PClassDescriptor_CanConvert_False_4B08B0, Phyre_PClassDescriptor_CanConvert_False_4B08C0 |
| 0x6 | 6 | 441 | Phyre_PClassDescriptor_AnimationNetworkInstance_GetDescPtr, Phyre_PClassDescriptor_AnimationNetworkInstance_GetDescPtr_Dup, Phyre_PClassDescriptor_AnimationNetworkInstance_GetSize48 |
| 0x7 | 7 | 3 | Phyre_PClassDescriptor_Field84_getter, Phyre_PClassDescriptor_Field88_getter, Phyre_PClassDescriptor_GetNumFields |
| 0x8 | 8 | 5 | Phyre_PClassDescriptor_ClearSignBit, Phyre_PClassDescriptor_GetIndex_Ret23, Phyre_PClassDescriptor_GetIndex_Ret23_A |
| 0xa | 10 | 33 | Phyre_PClassDescriptor_DestroyHierarchy_C90B00, Phyre_PClassDescriptor_dwordCB1D88_GetTotalSize, Phyre_PClassDescriptor_dwordCB1E20_GetTotalSize |
| 0xb | 11 | 114 | Phyre_PClassDescriptor_Destructor_w, Phyre_PClassDescriptor_Destructor_w_0, Phyre_PClassDescriptor_Destructor_w_1 |
| 0xc | 12 | 1 | Phyre_PClassDescriptor_IsRegistered |
| 0xd | 13 | 4 | Phyre_PClassDescriptor_SetField64, Phyre_PClassDescriptor_SetField68, Phyre_PClassDescriptor_SetField6C |
| 0x11 | 17 | 5 | Phyre_PClassDescriptor_Init_AnimState, Phyre_PClassDescriptor_Init_CalcForce, Phyre_PClassDescriptor_Init_PhysicsIntegrate |
| 0x12 | 18 | 42 | Phyre_PClassDescriptor_AbstractGetValue, Phyre_PClassDescriptor_AbstractGetValue_v10, Phyre_PClassDescriptor_AbstractGetValue_v11 |
| 0x13 | 19 | 1 | Phyre_PClassDescriptor_SetFields74_78 |
| 0x14 | 20 | 138 | Phyre_PClassDescriptor_Dtor_BrokenScreenPolygonDynamicMesh, Phyre_PClassDescriptor_Dtor_BrokenScreenPolygonDynamicMeshInstance, Phyre_PClassDescriptor_Dtor_ClothInstancingDynamicMesh |
| 0x15 | 21 | 9 | Phyre_PClassDescriptor_Construct_PPhysicsCharacterCamera, Phyre_PClassDescriptor_GetStaticField_PArrayU8_Wrapper, Phyre_PClassDescriptor_Init_characterState |
| 0x16 | 22 | 4 | Phyre_PClassDescriptor_CalcTotalSize_AdditiveBlenderController, Phyre_PClassDescriptor_CalcTotalSize_WeightedBlenderController, Phyre_PClassDescriptor_GetField0x0C_IfArgZero |
| 0x17 | 23 | 48 | Phyre_PClassDescriptor_GetField_PArrayU8_Wrapper, Phyre_PClassDescriptor_GetRefCount, Phyre_PClassDescriptor_PChar_RegisterAndFinalize |
| 0x18 | 24 | 3 | Phyre_PClassDescriptor_FinalizeRegistration, Phyre_PClassDescriptor_Unregister, Phyre_PClassDescriptor_VtableDispatch_Slot37 |
| 0x19 | 25 | 3 | Phyre_PClassDescriptor_CalcTotalSize_AnimationDescriptor, Phyre_PClassDescriptor_ReleaseResource03, Phyre_PClassDescriptor_SimpleInit_49BDA0 |
| 0x1a | 26 | 14 | Phyre_PClassDescriptor_GetDataPtrForIndex_A, Phyre_PClassDescriptor_GetDataPtrForIndex_B, Phyre_PClassDescriptor_GetDataPtrForIndex_C |
| 0x1b | 27 | 5 | Phyre_PClassDescriptor_PUByte_Setup, Phyre_PClassDescriptor_ScriptAccessor_AdditiveBlenderRefGet_AndCopy, Phyre_PClassDescriptor_ScriptAccessor_PAnimationHierarchyNode_CalcSize |
| 0x1d | 29 | 2 | Phyre_PClassDescriptor_Init2Dwords, Phyre_PClassDescriptor_ZeroOut2 |
| 0x1e | 30 | 4 | Phyre_PClassDescriptor_FreeIfNotFlagged, Phyre_PClassDescriptor_GetDataPtrForIndex_Masked, Phyre_PClassDescriptor_GetDataPtrForIndex_Masked_A |
| 0x20 | 32 | 5 | Phyre_PClassDescriptor_ReleaseResource00, Phyre_PClassDescriptor_ReleaseResource01, Phyre_PClassDescriptor_ReleaseResource02 |
| 0x21 | 33 | 9 | Phyre_PClassDescriptor_Dtor_A2BD40, Phyre_PClassDescriptor_Dtor_A2BD70, Phyre_PClassDescriptor_Dtor_Base |
| 0x22 | 34 | 8 | Phyre_PClassDescriptor_AnimatableComponent_GetSizeOrDefault, Phyre_PClassDescriptor_GetElementsOrDefault21, Phyre_PClassDescriptor_PLight_Setup_B |
| 0x24 | 36 | 1 | Phyre_PClassDescriptor_Init3DwordsZero |
| 0x26 | 38 | 10 | Phyre_PClassDescriptor_Construct_PPhysicsShape, Phyre_PClassDescriptor_Construct_PPhysicsShapeBullet, Phyre_PClassDescriptor_DeleteViaOffset |
| 0x27 | 39 | 120 | Phyre_PClassDescriptor_DtorV4, Phyre_PClassDescriptor_DtorV5, Phyre_PClassDescriptor_DtorV6 |
| 0x28 | 40 | 33 | Phyre_PClassDescriptor_DestroyWrap, Phyre_PClassDescriptor_DtorForward00, Phyre_PClassDescriptor_DtorForward01 |
| 0x2b | 43 | 4 | Phyre_PClassDescriptor_GetDataFromObject, Phyre_PClassDescriptor_GetDataFromObject_B, Phyre_PClassDescriptor_GetDataFromObject_C |
| 0x2c | 44 | 2 | Phyre_PClassDescriptor_GetDataMemberSize, Phyre_PClassDescriptor_GetMemberCount |
| 0x2e | 46 | 38 | Phyre_PClassDescriptor_EnableNotifications, Phyre_PClassDescriptor_SetFlag, Phyre_PClassDescriptor_SetFlag_2 |
| 0x33 | 51 | 1 | Phyre_PClassDescriptor_GetDestroyList |
| 0x38 | 56 | 1 | Phyre_PClassDescriptor_GetField_Direct |
| 0x3a | 58 | 6 | Phyre_PClassDescriptor_GetField, Phyre_PClassDescriptor_GetField_2, Phyre_PClassDescriptor_GetField_3 |
| 0x3b | 59 | 1 | Phyre_PClassDescriptor_GetStringName |
| 0x3d | 61 | 8 | Phyre_PClassDescriptor_GetField_Offset4, Phyre_PClassDescriptor_PushToStream, Phyre_PClassDescriptor_PushToStreamSize81 |
| 0x44 | 68 | 1 | Phyre_PClassDescriptor_DestroyHierarchy |
| 0x4b | 75 | 1 | Phyre_PClassDescriptor_ValidateAndAlloc |
| 0x4c | 76 | 2 | Phyre_PClassDescriptor_TraversePropertyList, Phyre_PClassDescriptor_TraversePropertyList_V2 |
| 0x4d | 77 | 1 | Phyre_PClassDescriptor_GetTotalSize |
| 0x53 | 83 | 1 | Phyre_PClassDescriptor_LoadVector3 |
| 0x57 | 87 | 1 | Phyre_PClassDescriptor_EvalCondition |
| 0x5c | 92 | 1 | Phyre_PClassDescriptor_EvalConditionEx |
| 0x68 | 104 | 2 | Phyre_PClassDescriptor_CalcLayoutSize, Phyre_PClassDescriptor_ValidateInheritance |
| 0x69 | 105 | 15 | Phyre_PClassDescriptor_ScriptAccessor_TraverseWithFlag, Phyre_PClassDescriptor_ScriptAccessor_TraverseWithFlag_A, Phyre_PClassDescriptor_SetFlag_Offset4 |
| 0x6d | 109 | 1 | Phyre_PClassDescriptor_GetOrInitSingleton |
| 0x76 | 118 | 13 | Phyre_PClassDescriptor_Init_PArrayAnimDataSource_A, Phyre_PClassDescriptor_Init_PArrayAnimDataSource_B, Phyre_PClassDescriptor_Init_PArrayAnimDataSource_C |
| 0x79 | 121 | 1 | Phyre_PClassDescriptor_FindByName |
| 0x7b | 123 | 1 | Phyre_PClassDescriptor_LoadMatrix4x4 |
| 0x7d | 125 | 1 | Phyre_PClassDescriptor_Traverse |
| 0x82 | 130 | 1 | Phyre_PClassDescriptor_RegisterBatch |
| 0x83 | 131 | 3 | Phyre_PClassDescriptor_FindByNameHierarchy_MemberList, Phyre_PClassDescriptor_FindByNamePropertyList2, Phyre_PClassDescriptor_FindByNameSelfList |
| 0x87 | 135 | 8 | Phyre_PClassDescriptor_FindByNamePropertyList, Phyre_PClassDescriptor_RegisterBatch_2, Phyre_PClassDescriptor_RegisterBatch_3 |
| 0x8b | 139 | 2 | Phyre_PClassDescriptor_GetStaticField_PArrayU8, Phyre_PClassDescriptor_PushPArrayAnimDataSource_ToStream |
| 0x90 | 144 | 7 | Phyre_PClassDescriptor_BrokenScreenMesh_ctor, Phyre_PClassDescriptor_BrokenScreenPolygonInstance_ctor, Phyre_PClassDescriptor_ctor_PPhysicsPlane |
| 0x91 | 145 | 2 | Phyre_PClassDescriptor_ctor_PGameSettings, Phyre_PClassDescriptor_PMorphModifierWeightsUserDataObject_ctor |
| 0x92 | 146 | 1 | Phyre_PClassDescriptor_ctor_PArrayPInputMapPtr4 |
| 0xb4 | 180 | 1 | Phyre_PClassDescriptor_GetField_PArrayU8 |
| 0xde | 222 | 1 | Phyre_PClassDescriptor_PNameValuePair_Register |
| 0xed | 237 | 1 | Phyre_PClassDescriptor_ctor |
| 0xef | 239 | 1 | Phyre_PClassDescriptor_Constructor |
| 0x102 | 258 | 1 | Phyre_PClassDescriptor_CreateType |
| 0x19a | 410 | 1 | Phyre_PClassDescriptor_RegisterAll |
| 0x1bf | 447 | 1 | Phyre_PClassDescriptor_Destructor |
| 0x206 | 518 | 1 | Phyre_PClassDescriptor_Register_PArrayPInputSource4 |
| 0x298 | 664 | 1 | Phyre_PClassDescriptor_RegisterBatch_4 |

### Top Name Prefixes (groups of related functions)

Total distinct prefixes: 868

| Prefix | Count |
|---|---|
| Phyre_PClassDescriptor_Destructor_w | 58 |
| Phyre_PClassDescriptor_Dtor_PPhysics | 40 |
| Phyre_PClassDescriptor_CanConvert_False | 23 |
| Phyre_PClassDescriptor_This_Ret | 20 |
| Phyre_PClassDescriptor_CanConvert_True | 15 |
| Phyre_PClassDescriptor_scalar_dtor | 15 |
| Phyre_PClassDescriptor_Dtor_PDynamicGeometry | 10 |
| Phyre_PClassDescriptor_GetNumFields_2 | 9 |
| Phyre_PClassDescriptor_GetSize_dword | 8 |
| Phyre_PClassDescriptor_PLight_Setup | 8 |
| Phyre_PClassDescriptor_SupportsType_RetTrue | 8 |
| Phyre_PClassDescriptor_GetIndex_Ret2 | 6 |
| Phyre_PClassDescriptor_ScriptAccessor_PushObjectOrNilToStream | 6 |
| Phyre_PClassDescriptor_Dtor_PScripting | 5 |
| Phyre_PClassDescriptor_GetSingleton_1940AD0 | 5 |
| Phyre_PClassDescriptor_GetSingleton_1941878 | 5 |
| Phyre_PClassDescriptor_GetSizePtr_18 | 5 |
| Phyre_PClassDescriptor_GetSizePtr_33 | 5 |
| Phyre_PClassDescriptor_GetSizePtr_52 | 5 |
| Phyre_PClassDescriptor_GetSizeTable_12 | 5 |
| Phyre_PClassDescriptor_GetSizeTable_62 | 5 |
| Phyre_PClassDescriptor_GetSizeTable_78 | 5 |
| Phyre_PClassDescriptor_DerefThis_PAnimationEventController | 4 |
| Phyre_PClassDescriptor_get_field | 4 |
| Phyre_PClassDescriptor_GetDescriptorPtr_LodData | 4 |
| Phyre_PClassDescriptor_GetNumFields_0x02 | 4 |
| Phyre_PClassDescriptor_GetTotalSize_w | 4 |
| Phyre_PClassDescriptor_GetTypeName_PModifierNetworkInfoPacket | 4 |
| Phyre_PClassDescriptor_PArray_PBitmapFontCharInfo | 4 |
| Phyre_PClassDescriptor_TraverseWithFlag_dword | 4 |
| Phyre_PClassDescriptor_Deref_PAnimationWeightedBlenderController | 3 |
| Phyre_PClassDescriptor_DerefThis_PAnimationSlotSet | 3 |
| Phyre_PClassDescriptor_Dtor_PArray | 3 |
| Phyre_PClassDescriptor_Dtor_PFramework | 3 |
| Phyre_PClassDescriptor_Field0_getter | 3 |
| Phyre_PClassDescriptor_GetDataPtr_LodDataBuf | 3 |
| Phyre_PClassDescriptor_GetDataPtr_PArrayAnimationSlotList | 3 |
| Phyre_PClassDescriptor_GetDescriptorPtr_AttachPoint | 3 |
| Phyre_PClassDescriptor_GetDescriptorPtr_PAnimationClipBinding | 3 |
| Phyre_PClassDescriptor_GetDescriptorPtr_PArrayAnimationSlotIndex | 3 |
| Phyre_PClassDescriptor_GetIndex_PAnimationBlenderWeight | 3 |
| Phyre_PClassDescriptor_GetIndex_Ret23 | 3 |
| Phyre_PClassDescriptor_GetSingleton_1940E60 | 3 |
| Phyre_PClassDescriptor_GetSingleton_1940EF8 | 3 |
| Phyre_PClassDescriptor_GetSingleton_1940F90 | 3 |
| Phyre_PClassDescriptor_GetSingleton_1941028 | 3 |
| Phyre_PClassDescriptor_GetSingleton_19410C0 | 3 |
| Phyre_PClassDescriptor_GetSingleton_1941158 | 3 |
| Phyre_PClassDescriptor_GetSingleton_19411F0 | 3 |
| Phyre_PClassDescriptor_GetSizePtr_29 | 3 |
| Phyre_PClassDescriptor_GetSizePtr_30 | 3 |
| Phyre_PClassDescriptor_GetSizePtr_34 | 3 |
| Phyre_PClassDescriptor_GetSizeTable_51 | 3 |
| Phyre_PClassDescriptor_GetSizeTable_53 | 3 |
| Phyre_PClassDescriptor_GetSizeTable_55 | 3 |
| Phyre_PClassDescriptor_GetSizeTable_70 | 3 |
| Phyre_PClassDescriptor_GetSizeTable_79 | 3 |
| Phyre_PClassDescriptor_GetSizeTable_83 | 3 |
| Phyre_PClassDescriptor_GetTypeSize_0x10 | 3 |
| Phyre_PClassDescriptor_Init_PArrayAnimDataSource | 3 |
| Phyre_PClassDescriptor_PBitmapFont_Dtor | 3 |
| Phyre_PClassDescriptor_PBitmapFontCharInfo_Dtor | 3 |
| Phyre_PClassDescriptor_PClassDescriptor_dtor | 3 |
| Phyre_PClassDescriptor_PDeferredLightingD3D11_Ctor | 3 |
| Phyre_PClassDescriptor_PDepthOfFieldBase_Ctor | 3 |
| Phyre_PClassDescriptor_PDepthOfFieldD3D11_Ctor | 3 |
| Phyre_PClassDescriptor_PFXAABase_Ctor | 3 |
| Phyre_PClassDescriptor_PFXAAD3D11_Ctor | 3 |
| Phyre_PClassDescriptor_PGlowBase_Ctor | 3 |
| Phyre_PClassDescriptor_PGlowD3D11_Ctor | 3 |
| Phyre_PClassDescriptor_PGlowGPUBase_Ctor | 3 |
| Phyre_PClassDescriptor_PLegacyGlow_Ctor | 3 |
| Phyre_PClassDescriptor_PLegacyGlowBase_Ctor | 3 |
| Phyre_PClassDescriptor_PLegacyGlowD3D11_Ctor | 3 |
| Phyre_PClassDescriptor_PLegacyGlowGPUBase_Ctor | 3 |
| Phyre_PClassDescriptor_PMeshParticleSystemBase_Ctor | 3 |
| Phyre_PClassDescriptor_PMLAA_Ctor | 3 |
| Phyre_PClassDescriptor_PMLAABase_Ctor | 3 |
| Phyre_PClassDescriptor_PMotionBlur_Ctor | 3 |
| Phyre_PClassDescriptor_PMotionBlurBase_Ctor | 3 |
| Phyre_PClassDescriptor_PMotionBlurD3D11_Ctor | 3 |
| Phyre_PClassDescriptor_PPostEffectBase_Ctor | 3 |
| Phyre_PClassDescriptor_PPostEffectManager_Ctor | 3 |
| Phyre_PClassDescriptor_PScreenSpaceAmbientOcclusion_Ctor | 3 |
| Phyre_PClassDescriptor_PScreenSpaceAmbientOcclusionBase_Ctor | 3 |
| Phyre_PClassDescriptor_PScreenSpaceAmbientOcclusionD3D11_Ctor | 3 |
| Phyre_PClassDescriptor_PScreenSpaceReflection_Ctor | 3 |
| Phyre_PClassDescriptor_PScreenSpaceReflectionBase_Ctor | 3 |
| Phyre_PClassDescriptor_PScreenSpaceReflectionD3D11_Ctor | 3 |
| Phyre_PClassDescriptor_Size11_Getter | 3 |
| Phyre_PClassDescriptor_Traverse_PArrayAnimDataSrc | 3 |
| Phyre_PClassDescriptor_Traverse_PArrayFloat4 | 3 |
| Phyre_PClassDescriptor_TraverseWithFlag_Size | 3 |
| Phyre_PClassDescriptor_AnimationNetworkInstance_GetDescPtr | 2 |
| Phyre_PClassDescriptor_Dtor_PArrayPInputAction4 | 2 |
| Phyre_PClassDescriptor_Dtor_PArrayPInputSource4 | 2 |
| Phyre_PClassDescriptor_Dtor_PInputAction | 2 |
| Phyre_PClassDescriptor_Dtor_PInputMap | 2 |
| Phyre_PClassDescriptor_Dtor_PInputSourceJoypadAxis | 2 |
| Phyre_PClassDescriptor_Dtor_PInputSourceJoypadButton | 2 |
| Phyre_PClassDescriptor_Dtor_PInputSourceKey | 2 |
| Phyre_PClassDescriptor_Dtor_PInputSourceMotionAngularVelocityX | 2 |
| Phyre_PClassDescriptor_Dtor_PInputSourceMotionAngularVelocityY | 2 |
| Phyre_PClassDescriptor_Dtor_PInputSourceMotionAngularVelocityZ | 2 |
| Phyre_PClassDescriptor_Dtor_PInputSourceMotionLinearAccelerationX | 2 |
| Phyre_PClassDescriptor_Dtor_PInputSourceMotionLinearAccelerationY | 2 |
| Phyre_PClassDescriptor_Dtor_PInputSourceMotionLinearAccelerationZ | 2 |
| Phyre_PClassDescriptor_Dtor_PInputSourceMotionQuatW | 2 |
| Phyre_PClassDescriptor_Dtor_PInputSourceMotionQuatX | 2 |
| Phyre_PClassDescriptor_Dtor_PInputSourceMotionQuatY | 2 |
| Phyre_PClassDescriptor_Dtor_PInputSourceMotionQuatZ | 2 |
| Phyre_PClassDescriptor_Dtor_PInputSourceMouseButton | 2 |
| Phyre_PClassDescriptor_Dtor_PInputSourceMouseDeltaX | 2 |
| Phyre_PClassDescriptor_Dtor_PInputSourceMouseDeltaY | 2 |
| Phyre_PClassDescriptor_Dtor_PInputSourceTouchDragX | 2 |
| Phyre_PClassDescriptor_Dtor_PInputSourceTouchDragY | 2 |
| Phyre_PClassDescriptor_Dtor_PInputSourceTouchPinch | 2 |
| Phyre_PClassDescriptor_Dtor_PInputSourceTouchRotate | 2 |
| Phyre_PClassDescriptor_Dtor_PInputSourceTouchTwoFingerDragX | 2 |
| Phyre_PClassDescriptor_Dtor_PInputSourceTouchTwoFingerDragY | 2 |
| Phyre_PClassDescriptor_Field4_getter | 2 |
| Phyre_PClassDescriptor_GetClassName_PAnimationAdditiveBlenderController | 2 |
| Phyre_PClassDescriptor_GetClassName_PAnimationWeightedBlenderController | 2 |
| Phyre_PClassDescriptor_GetDataPtr_AttachPoint | 2 |
| Phyre_PClassDescriptor_GetDataPtr_PAnimationClipBinding | 2 |
| Phyre_PClassDescriptor_GetDataPtr_PArrayAnimationClipPtr | 2 |
| Phyre_PClassDescriptor_GetDataPtr_PArrayAnimationSlotIndex | 2 |
| Phyre_PClassDescriptor_GetDataPtr_PArrayChannelTarget | 2 |
| Phyre_PClassDescriptor_GetDataPtr_PArrayKeyframe | 2 |
| Phyre_PClassDescriptor_GetDataPtr_PSharrayAnimationClip | 2 |
| Phyre_PClassDescriptor_GetDataPtrForIndex_Masked | 2 |
| Phyre_PClassDescriptor_GetDescriptorPtr_PArrayAnimationClipPtr | 2 |
| Phyre_PClassDescriptor_GetDescriptorPtr_PArrayChannelTarget | 2 |
| Phyre_PClassDescriptor_GetField_PArrayU8 | 2 |
| Phyre_PClassDescriptor_GetIndex_Ret16 | 2 |
| Phyre_PClassDescriptor_GetSingleton_1940B68 | 2 |
| Phyre_PClassDescriptor_GetSingleton_1940C00 | 2 |
| Phyre_PClassDescriptor_GetSingleton_1940C98 | 2 |
| Phyre_PClassDescriptor_GetSingleton_1940D30 | 2 |
| Phyre_PClassDescriptor_GetSingleton_1940DC8 | 2 |
| Phyre_PClassDescriptor_GetSingleton_1941288 | 2 |
| Phyre_PClassDescriptor_GetSingleton_1941320 | 2 |
| Phyre_PClassDescriptor_GetSingleton_19413B8 | 2 |
| Phyre_PClassDescriptor_GetSingleton_19414E8 | 2 |
| Phyre_PClassDescriptor_GetSingleton_1941580 | 2 |
| Phyre_PClassDescriptor_GetSingleton_1941618 | 2 |
| Phyre_PClassDescriptor_GetSingleton_19416B0 | 2 |
| Phyre_PClassDescriptor_GetSingleton_1941748 | 2 |
| Phyre_PClassDescriptor_GetSingleton_19417E0 | 2 |
| Phyre_PClassDescriptor_GetSizePtr_32 | 2 |
| Phyre_PClassDescriptor_GetSizePtr_64 | 2 |
| Phyre_PClassDescriptor_GetSizePtr_AttachPoint | 2 |
| Phyre_PClassDescriptor_GetSizePtr_PAnimationClipBinding | 2 |
| Phyre_PClassDescriptor_GetSizeTable_76 | 2 |
| Phyre_PClassDescriptor_GetStaticField_PArrayU8 | 2 |
| Phyre_PClassDescriptor_GetTypeName_PMorphModifierWeightsUserDataObject | 2 |
| Phyre_PClassDescriptor_GetTypeName_PScheduler | 2 |
| Phyre_PClassDescriptor_GetTypeName_PScript | 2 |
| Phyre_PClassDescriptor_GetTypeName_PScriptCallbackHandler | 2 |
| Phyre_PClassDescriptor_Init_PArray | 2 |
| Phyre_PClassDescriptor_Init_PArrayDataBlockD3D11 | 2 |
| Phyre_PClassDescriptor_Init_physicsState | 2 |
| Phyre_PClassDescriptor_Init_PSharrayDataBlockBufferD3D11 | 2 |
| Phyre_PClassDescriptor_Init_PSharrayIndexDataBlockBufferD3D11 | 2 |
| Phyre_PClassDescriptor_PArray_PostEffectBase4 | 2 |
| Phyre_PClassDescriptor_PArrayUChar_Destructor | 2 |
| Phyre_PClassDescriptor_PAsyncProcessHeader_dtor | 2 |
| Phyre_PClassDescriptor_PBase_dtor | 2 |
| Phyre_PClassDescriptor_PBitmapFont_Destructor | 2 |
| Phyre_PClassDescriptor_PBitmapFontCharInfo_Destructor | 2 |
| Phyre_PClassDescriptor_PClassDataMemberDynamic_Destructor | 2 |
| Phyre_PClassDescriptor_PClassDescriptorDynamic_Destructor | 2 |
| Phyre_PClassDescriptor_PClassMember_dtor | 2 |
| Phyre_PClassDescriptor_PDeferredLighting_Ctor | 2 |
| Phyre_PClassDescriptor_PDeferredLightingBase_Ctor | 2 |
| Phyre_PClassDescriptor_PDepthOfField_Ctor | 2 |
| Phyre_PClassDescriptor_PFXAA_Ctor | 2 |
| Phyre_PClassDescriptor_PGlow_Ctor | 2 |
| Phyre_PClassDescriptor_PMLAAD3D11_Ctor | 2 |
| Phyre_PClassDescriptor_PScriptableComponent_ScalarDeletingDtor | 2 |
| Phyre_PClassDescriptor_PString_Destructor | 2 |
| Phyre_PClassDescriptor_PushObject_CC9A40 | 2 |
| Phyre_PClassDescriptor_ScriptAccessor_PAnimationHierarchyNode | 2 |
| Phyre_PClassDescriptor_ScriptAccessor_PushPArrayToStream | 2 |
| Phyre_PClassDescriptor_ScriptAccessor_TraverseWithFlag | 2 |
| Phyre_PClassDescriptor_SupportsType_AnimationSlotFilter | 2 |
| Phyre_PClassDescriptor_SupportsType_RetFalse | 2 |
| Phyre_PClassDescriptor_Traverse_PAnimChannel | 2 |
| Phyre_PClassDescriptor_Traverse_PArrayAnimDataSource | 2 |
| Phyre_PClassDescriptor_TraverseWithFlag_Size95 | 2 |
| Phyre_PClassDescriptor_AbstractGetValue | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v10 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v11 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v12 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v13 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v14 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v15 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v16 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v17 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v18 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v19 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v2 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v20 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v21 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v22 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v23 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v24 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v25 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v26 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v27 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v28 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v29 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v3 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v30 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v31 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v32 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v33 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v34 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v35 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v36 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v37 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v38 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v39 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v4 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v40 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v41 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v5 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v6 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v7 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v8 | 1 |
| Phyre_PClassDescriptor_AbstractGetValue_v9 | 1 |
| Phyre_PClassDescriptor_AnimatableComponent_GetSizeOrDefault | 1 |
| Phyre_PClassDescriptor_AnimationNetworkInstance_GetSize48 | 1 |
| Phyre_PClassDescriptor_AnimationNetworkInstance_GetSize64 | 1 |
| Phyre_PClassDescriptor_AnimationNetworkInstance_Size48 | 1 |
| Phyre_PClassDescriptor_AnimationNetworkInstance_Size64 | 1 |
| Phyre_PClassDescriptor_BrokenScreenMesh_ctor | 1 |
| Phyre_PClassDescriptor_BrokenScreenPolygonInstance_ctor | 1 |
| Phyre_PClassDescriptor_CalcLayoutSize | 1 |
| Phyre_PClassDescriptor_CalcTotalSize_AdditiveBlenderController | 1 |
| Phyre_PClassDescriptor_CalcTotalSize_AnimationDescriptor | 1 |
| Phyre_PClassDescriptor_CalcTotalSize_WeightedBlenderController | 1 |
| Phyre_PClassDescriptor_ClearSignBit | 1 |
| Phyre_PClassDescriptor_Construct_PPhysicsCharacterCamera | 1 |
| Phyre_PClassDescriptor_Construct_PPhysicsShape | 1 |
| Phyre_PClassDescriptor_Construct_PPhysicsShapeBullet | 1 |
| Phyre_PClassDescriptor_Constructor | 1 |
| Phyre_PClassDescriptor_CreateType | 1 |
| Phyre_PClassDescriptor_ctor | 1 |
| Phyre_PClassDescriptor_ctor_PArrayPInputMapPtr4 | 1 |
| Phyre_PClassDescriptor_ctor_PGameSettings | 1 |
| Phyre_PClassDescriptor_ctor_PPhysicsPlane | 1 |
| Phyre_PClassDescriptor_DeleteViaOffset | 1 |
| Phyre_PClassDescriptor_Deref_PAnimationBlenderWeight | 1 |
| Phyre_PClassDescriptor_DestroyHierarchy | 1 |
| Phyre_PClassDescriptor_DestroyHierarchy_C90B00 | 1 |
| Phyre_PClassDescriptor_DestroyWrap | 1 |
| Phyre_PClassDescriptor_Destructor | 1 |
| Phyre_PClassDescriptor_DistortionGridDynamicMesh_ctor | 1 |
| Phyre_PClassDescriptor_DistortionGridInstance_ctor | 1 |
| Phyre_PClassDescriptor_Dtor_A2BD40 | 1 |
| Phyre_PClassDescriptor_Dtor_A2BD70 | 1 |
| Phyre_PClassDescriptor_Dtor_Base | 1 |
| Phyre_PClassDescriptor_Dtor_BrokenScreenPolygonDynamicMesh | 1 |
| Phyre_PClassDescriptor_Dtor_BrokenScreenPolygonDynamicMeshInstance | 1 |
| Phyre_PClassDescriptor_Dtor_ClothInstancingDynamicMesh | 1 |
| Phyre_PClassDescriptor_Dtor_ClothInstancingDynamicMeshInstance | 1 |
| Phyre_PClassDescriptor_Dtor_DistortionGridDynamicMesh | 1 |
| Phyre_PClassDescriptor_Dtor_DistortionGridDynamicMeshInstance | 1 |
| Phyre_PClassDescriptor_Dtor_DynamicMeshDefaultImplmenetation | 1 |
| Phyre_PClassDescriptor_Dtor_PClassDynamicMesh | 1 |
| Phyre_PClassDescriptor_Dtor_PClassDynamicMeshInstance | 1 |
| Phyre_PClassDescriptor_Dtor_PInputSource | 1 |
| Phyre_PClassDescriptor_Dtor_PInputSourceTouch | 1 |
| Phyre_PClassDescriptor_Dtor_PInputSourceTouchBase | 1 |
| Phyre_PClassDescriptor_Dtor_PInputTypeSemanticBool | 1 |
| Phyre_PClassDescriptor_Dtor_PInputTypeSemanticInt | 1 |
| Phyre_PClassDescriptor_Dtor_PSharray | 1 |
| Phyre_PClassDescriptor_Dtor_RadialLineDynamicMesh | 1 |
| Phyre_PClassDescriptor_Dtor_RadialLineDynamicMeshInstance | 1 |
| Phyre_PClassDescriptor_Dtor_ShadowDynamicMesh | 1 |
| Phyre_PClassDescriptor_Dtor_ShadowDynamicMeshInstance | 1 |
| Phyre_PClassDescriptor_DtorForward00 | 1 |
| Phyre_PClassDescriptor_DtorForward01 | 1 |
| Phyre_PClassDescriptor_DtorForward02 | 1 |
| Phyre_PClassDescriptor_DtorForward03 | 1 |
| Phyre_PClassDescriptor_DtorForward04 | 1 |
| Phyre_PClassDescriptor_DtorForward05 | 1 |
| Phyre_PClassDescriptor_DtorForward06 | 1 |
| Phyre_PClassDescriptor_DtorForward07 | 1 |
| Phyre_PClassDescriptor_DtorForward08 | 1 |
| Phyre_PClassDescriptor_DtorForward09 | 1 |
| Phyre_PClassDescriptor_DtorForward10 | 1 |
| Phyre_PClassDescriptor_DtorForward11 | 1 |
| Phyre_PClassDescriptor_DtorForward12 | 1 |
| Phyre_PClassDescriptor_DtorForward13 | 1 |
| Phyre_PClassDescriptor_DtorForward14 | 1 |
| Phyre_PClassDescriptor_DtorForward15 | 1 |
| Phyre_PClassDescriptor_DtorForward16 | 1 |
| Phyre_PClassDescriptor_DtorForward17 | 1 |
| Phyre_PClassDescriptor_DtorForward18 | 1 |
| Phyre_PClassDescriptor_DtorForward19 | 1 |
| Phyre_PClassDescriptor_DtorForward20 | 1 |
| Phyre_PClassDescriptor_DtorForward21 | 1 |
| Phyre_PClassDescriptor_DtorForward22 | 1 |
| Phyre_PClassDescriptor_DtorV0Forward00 | 1 |
| Phyre_PClassDescriptor_DtorV0Forward01 | 1 |
| Phyre_PClassDescriptor_DtorV4 | 1 |
| Phyre_PClassDescriptor_DtorV5 | 1 |
| Phyre_PClassDescriptor_DtorV6 | 1 |
| Phyre_PClassDescriptor_dwordCB1D88_Get | 1 |
| Phyre_PClassDescriptor_dwordCB1D88_GetTotalSize | 1 |
| Phyre_PClassDescriptor_dwordCB1E20_Get | 1 |
| Phyre_PClassDescriptor_dwordCB1E20_GetTotalSize | 1 |
| Phyre_PClassDescriptor_Enable | 1 |
| Phyre_PClassDescriptor_EnableNotifications | 1 |
| Phyre_PClassDescriptor_EvalCondition | 1 |
| Phyre_PClassDescriptor_EvalConditionEx | 1 |
| Phyre_PClassDescriptor_Field84_getter | 1 |
| Phyre_PClassDescriptor_Field88_getter | 1 |
| Phyre_PClassDescriptor_FinalizeRegistration | 1 |
| Phyre_PClassDescriptor_FindByName | 1 |
| Phyre_PClassDescriptor_FindByNameHierarchy_MemberList | 1 |
| Phyre_PClassDescriptor_FindByNamePropertyList | 1 |
| Phyre_PClassDescriptor_FindByNamePropertyList2 | 1 |
| Phyre_PClassDescriptor_FindByNameSelfList | 1 |
| Phyre_PClassDescriptor_FreeIfNotFlagged | 1 |
| Phyre_PClassDescriptor_GetClassName_PAnimationBlenderController | 1 |
| Phyre_PClassDescriptor_GetClassName_PAnimationDataSourceListEntry | 1 |
| Phyre_PClassDescriptor_GetClassName_PAnimationNetworkInstance | 1 |
| Phyre_PClassDescriptor_GetClassName_PAnimationNetworkInstanceTarget | 1 |
| Phyre_PClassDescriptor_GetClassName_PAnimationSlotFilter | 1 |
| Phyre_PClassDescriptor_GetClassName_PAnimationSlotFilterDeferredLoad | 1 |
| Phyre_PClassDescriptor_GetClassName_PAnimationSpuTargetBlenderController | 1 |
| Phyre_PClassDescriptor_GetClassName_PAnimationTargetBlenderController | 1 |
| Phyre_PClassDescriptor_GetData_PAnimationBlenderController | 1 |
| Phyre_PClassDescriptor_GetDataFromObject | 1 |
| Phyre_PClassDescriptor_GetDataFromObject_B | 1 |
| Phyre_PClassDescriptor_GetDataFromObject_C | 1 |
| Phyre_PClassDescriptor_GetDataFromObject_D | 1 |
| Phyre_PClassDescriptor_GetDataMemberSize | 1 |
| Phyre_PClassDescriptor_GetDataPtr | 1 |
| Phyre_PClassDescriptor_GetDataPtr_PAnimationBlenderController | 1 |
| Phyre_PClassDescriptor_GetDataPtr_PAnimationClipBindingDataBlockCache | 1 |
| Phyre_PClassDescriptor_GetDataPtr_PAnimationConstantChannel | 1 |
| Phyre_PClassDescriptor_GetDataPtr_PAnimationScriptController | 1 |
| Phyre_PClassDescriptor_GetDataPtr_PAnimationSlotFilter | 1 |
| Phyre_PClassDescriptor_GetDataPtr_PArrayAnimationChannelTarget | 1 |
| Phyre_PClassDescriptor_GetDataPtr_PArrayAnimationSlotListArray | 1 |
| Phyre_PClassDescriptor_GetDataPtr_PTimeIntervalController | 1 |
| Phyre_PClassDescriptor_GetDataPtr_PTimeScaleOffsetController | 1 |
| Phyre_PClassDescriptor_GetDataPtrForIndex_A | 1 |
| Phyre_PClassDescriptor_GetDataPtrForIndex_B | 1 |
| Phyre_PClassDescriptor_GetDataPtrForIndex_C | 1 |
| Phyre_PClassDescriptor_GetDataPtrForIndex_D | 1 |
| Phyre_PClassDescriptor_GetDataPtrForIndex_E | 1 |
| Phyre_PClassDescriptor_GetDataPtrForIndex_F | 1 |
| Phyre_PClassDescriptor_GetDescriptorPtr_PAnimationBlenderController | 1 |
| Phyre_PClassDescriptor_GetDescriptorPtr_PAnimationClip | 1 |
| Phyre_PClassDescriptor_GetDescriptorPtr_PAnimationClipBindingDataBlockCache | 1 |
| Phyre_PClassDescriptor_GetDescriptorPtr_PAnimationConstantChannel | 1 |
| Phyre_PClassDescriptor_GetDescriptorPtr_PAnimationSlotFilter | 1 |
| Phyre_PClassDescriptor_GetDescriptorPtr_PArrayAnimationSlotTarget | 1 |
| Phyre_PClassDescriptor_GetDescriptorPtr_PArrayKeyframe | 1 |
| Phyre_PClassDescriptor_GetDescriptorPtr_PArrayUInt | 1 |
| Phyre_PClassDescriptor_GetDescriptorPtr_PTimeIntervalController | 1 |
| Phyre_PClassDescriptor_GetDescriptorPtr_PTimeScaleOffsetController | 1 |
| Phyre_PClassDescriptor_GetDestroyList | 1 |
| Phyre_PClassDescriptor_GetDword_4BDA80 | 1 |
| Phyre_PClassDescriptor_GetDwordC9C288 | 1 |
| Phyre_PClassDescriptor_GetDwordC9C3B8 | 1 |
| Phyre_PClassDescriptor_GetDwordC9C450 | 1 |
| Phyre_PClassDescriptor_GetDwordC9C910 | 1 |
| Phyre_PClassDescriptor_GetDwordC9C9A8 | 1 |
| Phyre_PClassDescriptor_GetDwordC9CA40 | 1 |
| Phyre_PClassDescriptor_GetElementsOrDefault21 | 1 |
| Phyre_PClassDescriptor_GetField | 1 |
| Phyre_PClassDescriptor_GetField0x0C_IfArgZero | 1 |
| Phyre_PClassDescriptor_GetField4_4B0A20 | 1 |
| Phyre_PClassDescriptor_GetField4_4B0A30 | 1 |
| Phyre_PClassDescriptor_GetField4_4B9B80 | 1 |
| Phyre_PClassDescriptor_GetField4_4B9B90 | 1 |
| Phyre_PClassDescriptor_GetField4_4B9BA0 | 1 |
| Phyre_PClassDescriptor_GetField4_4B9BB0 | 1 |
| Phyre_PClassDescriptor_GetField4_4B9BC0 | 1 |
| Phyre_PClassDescriptor_GetField4_4B9BD0 | 1 |
| Phyre_PClassDescriptor_GetField4_4BD8E0 | 1 |
| Phyre_PClassDescriptor_GetField4_4BD8F0 | 1 |
| Phyre_PClassDescriptor_GetField_2 | 1 |
| Phyre_PClassDescriptor_GetField_3 | 1 |
| Phyre_PClassDescriptor_GetField_Direct | 1 |
| Phyre_PClassDescriptor_GetField_Index9 | 1 |
| Phyre_PClassDescriptor_GetField_Offset4 | 1 |
| Phyre_PClassDescriptor_GetFieldAt8 | 1 |
| Phyre_PClassDescriptor_GetIndex_PAnimationConstantChannel | 1 |
| Phyre_PClassDescriptor_GetIndex_RetNegOne | 1 |
| Phyre_PClassDescriptor_GetMemberCount | 1 |
| Phyre_PClassDescriptor_GetNumFields | 1 |
| Phyre_PClassDescriptor_GetOrInitSingleton | 1 |
| Phyre_PClassDescriptor_GetPtr_4AE870 | 1 |
| Phyre_PClassDescriptor_GetPtr_4AE880 | 1 |
| Phyre_PClassDescriptor_GetPtr_4AE890 | 1 |
| Phyre_PClassDescriptor_GetPtr_4AE8A0 | 1 |
| Phyre_PClassDescriptor_GetPtr_4AE8B0 | 1 |
| Phyre_PClassDescriptor_GetPtr_4B9BE0 | 1 |
| Phyre_PClassDescriptor_GetPtr_4B9BF0 | 1 |
| Phyre_PClassDescriptor_GetPtr_4B9C00 | 1 |
| Phyre_PClassDescriptor_GetPtr_4BD0F0 | 1 |
| Phyre_PClassDescriptor_GetPtr_4BD100 | 1 |
| Phyre_PClassDescriptor_GetPtr_4BD110 | 1 |
| Phyre_PClassDescriptor_GetPtr_4BD120 | 1 |
| Phyre_PClassDescriptor_GetPtr_4BD2D0 | 1 |
| Phyre_PClassDescriptor_GetPtr_4BD2E0 | 1 |
| Phyre_PClassDescriptor_GetPtr_4BD910 | 1 |
| Phyre_PClassDescriptor_GetPtr_4BE1D0 | 1 |
| Phyre_PClassDescriptor_GetPtr_4BE1E0 | 1 |
| Phyre_PClassDescriptor_GetPtr_4BE330 | 1 |
| Phyre_PClassDescriptor_GetPtr_4BE360 | 1 |
| Phyre_PClassDescriptor_GetRefCount | 1 |
| Phyre_PClassDescriptor_GetSingleton_1941450 | 1 |
| Phyre_PClassDescriptor_GetSingleton_1941878B | 1 |
| Phyre_PClassDescriptor_GetSingleton_19418A8 | 1 |
| Phyre_PClassDescriptor_GetSingleton_1941910 | 1 |
| Phyre_PClassDescriptor_GetSize76Ptr | 1 |
| Phyre_PClassDescriptor_GetSize76Ptr_B | 1 |
| Phyre_PClassDescriptor_GetSize76Ptr_C | 1 |
| Phyre_PClassDescriptor_GetSize76Ptr_D | 1 |
| Phyre_PClassDescriptor_GetSize76Ptr_E | 1 |
| Phyre_PClassDescriptor_GetSize76Ptr_F | 1 |
| Phyre_PClassDescriptor_GetSize_101 | 1 |
| Phyre_PClassDescriptor_GetSize_103 | 1 |
| Phyre_PClassDescriptor_GetSize_17Bytes | 1 |
| Phyre_PClassDescriptor_GetSize_60 | 1 |
| Phyre_PClassDescriptor_GetSize_94 | 1 |
| Phyre_PClassDescriptor_GetSize_95 | 1 |
| Phyre_PClassDescriptor_GetSizePtr_17 | 1 |
| Phyre_PClassDescriptor_GetSizePtr_48 | 1 |
| Phyre_PClassDescriptor_GetSizePtr_CA9810 | 1 |
| Phyre_PClassDescriptor_GetSizePtr_CACDB0 | 1 |
| Phyre_PClassDescriptor_GetSizePtr_dword | 1 |
| Phyre_PClassDescriptor_GetSizePtr_LodData | 1 |
| Phyre_PClassDescriptor_GetSizePtr_PAnimationConstantChannel | 1 |
| Phyre_PClassDescriptor_GetSizePtr_PAnimationScriptController | 1 |
| Phyre_PClassDescriptor_GetSizePtr_PArrayAnimationChannelSlotPtr | 1 |
| Phyre_PClassDescriptor_GetSizePtr_PArrayAnimationClipPtr | 1 |
| Phyre_PClassDescriptor_GetSizePtr_PArrayAnimationSlotIndex | 1 |
| Phyre_PClassDescriptor_GetSizePtr_PArrayAnimationSlotList | 1 |
| Phyre_PClassDescriptor_GetSizePtr_PArrayAnimationSlotListArray | 1 |
| Phyre_PClassDescriptor_GetSizePtr_PArrayChannelTarget | 1 |
| Phyre_PClassDescriptor_GetSizePtr_PArrayKeyframe | 1 |
| Phyre_PClassDescriptor_GetSizePtr_PArraySlotListIndex | 1 |
| Phyre_PClassDescriptor_GetSizeTable2 | 1 |
| Phyre_PClassDescriptor_GetSizeTable_13 | 1 |
| Phyre_PClassDescriptor_GetSizeTable_44 | 1 |
| Phyre_PClassDescriptor_GetSizeTable_45 | 1 |
| Phyre_PClassDescriptor_GetSizeTable_54 | 1 |
| Phyre_PClassDescriptor_GetSizeTable_57 | 1 |
| Phyre_PClassDescriptor_GetSizeTable_73 | 1 |
| Phyre_PClassDescriptor_GetSizeTable_86 | 1 |
| Phyre_PClassDescriptor_GetSizeTable_CBEE00 | 1 |
| Phyre_PClassDescriptor_GetSizeTable_CBEFC8 | 1 |
| Phyre_PClassDescriptor_GetSizeTable_CBFD70 | 1 |
| Phyre_PClassDescriptor_GetStaticField | 1 |
| Phyre_PClassDescriptor_GetStaticField_2 | 1 |
| Phyre_PClassDescriptor_GetStaticField_Offset4 | 1 |
| Phyre_PClassDescriptor_GetStringName | 1 |
| Phyre_PClassDescriptor_GetThis | 1 |
| Phyre_PClassDescriptor_GetTotalSize | 1 |
| Phyre_PClassDescriptor_GetTotalSize_64 | 1 |
| Phyre_PClassDescriptor_GetTotalSize_CACDB0 | 1 |
| Phyre_PClassDescriptor_GetTotalSize_CBB268 | 1 |
| Phyre_PClassDescriptor_GetTotalSize_CBBA08 | 1 |
| Phyre_PClassDescriptor_GetTotalSize_CBBAA0 | 1 |
| Phyre_PClassDescriptor_GetTotalSize_CBBB38 | 1 |
| Phyre_PClassDescriptor_GetTotalSize_LodData | 1 |
| Phyre_PClassDescriptor_GetTotalSize_PAnimationConstantChannel | 1 |
| Phyre_PClassDescriptor_GetTotalSize_PArrayAnimationSlotIndex | 1 |
| Phyre_PClassDescriptor_GetTotalSize_PArrayAnimationSlotList | 1 |
| Phyre_PClassDescriptor_GetTotalSize_Size76 | 1 |
| Phyre_PClassDescriptor_GetTotalSize_thunk | 1 |
| Phyre_PClassDescriptor_GetTotalSizeGlobal | 1 |
| Phyre_PClassDescriptor_GetTypeName_PModifierAndInputs | 1 |
| Phyre_PClassDescriptor_GetTypeName_PModifierNetwork | 1 |
| Phyre_PClassDescriptor_GetTypeName_PModifierNetworkBuffer | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsCylinder | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsCylinderBase | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsCylinderBullet | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsInterface | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsInterfaceBase | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsInterfaceBullet | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsMaterial | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsMesh | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsMeshBase | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsMeshBullet | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsModel | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsPlane | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsPlaneBase | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsPlaneBullet | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsRigidBody | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsRigidBodyBase | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsRigidBodyBullet | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsShape | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsShapeBase | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsShapeBullet | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsSphere | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsSphereBase | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsSphereBullet | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsTaperedCapsule | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsTaperedCylinder | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsWorld | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsWorldBase | 1 |
| Phyre_PClassDescriptor_GetTypeName_PPhysicsWorldBullet | 1 |
| Phyre_PClassDescriptor_GetTypeName_PRaycastResult | 1 |
| Phyre_PClassDescriptor_GetTypeName_PRenderStream | 1 |
| Phyre_PClassDescriptor_GetTypeName_PRenderStreamInput | 1 |
| Phyre_PClassDescriptor_GetTypeSize23 | 1 |
| Phyre_PClassDescriptor_GetTypeSize_0x02 | 1 |
| Phyre_PClassDescriptor_GetTypeSize_40 | 1 |
| Phyre_PClassDescriptor_GetTypeSize_44 | 1 |
| Phyre_PClassDescriptor_GetValue_CAD8DC | 1 |
| Phyre_PClassDescriptor_GetValue_CAD8E0 | 1 |
| Phyre_PClassDescriptor_GetValue_CAD8E4 | 1 |
| Phyre_PClassDescriptor_GetValue_CAD8E8 | 1 |
| Phyre_PClassDescriptor_GetValueAbort | 1 |
| Phyre_PClassDescriptor_GetWord_4BD900 | 1 |
| Phyre_PClassDescriptor_Init16Length | 1 |
| Phyre_PClassDescriptor_Init2Dwords | 1 |
| Phyre_PClassDescriptor_Init3DwordsZero | 1 |
| Phyre_PClassDescriptor_Init_2FieldsAt32 | 1 |
| Phyre_PClassDescriptor_Init_AnimState | 1 |
| Phyre_PClassDescriptor_Init_CalcForce | 1 |
| Phyre_PClassDescriptor_Init_characterState | 1 |
| Phyre_PClassDescriptor_Init_PBitmapFont | 1 |
| Phyre_PClassDescriptor_Init_PBitmapFontCharInfo | 1 |
| Phyre_PClassDescriptor_Init_PDeferredLighting | 1 |
| Phyre_PClassDescriptor_Init_PDeferredLightingBase | 1 |
| Phyre_PClassDescriptor_Init_PDeferredLightingD3D11 | 1 |
| Phyre_PClassDescriptor_Init_PDepthOfField | 1 |
| Phyre_PClassDescriptor_Init_PDepthOfFieldBase | 1 |
| Phyre_PClassDescriptor_Init_PDepthOfFieldD3D11 | 1 |
| Phyre_PClassDescriptor_Init_PFXAA | 1 |
| Phyre_PClassDescriptor_Init_PFXAABase | 1 |
| Phyre_PClassDescriptor_Init_PFXAAD3D11 | 1 |
| Phyre_PClassDescriptor_Init_PGlow | 1 |
| Phyre_PClassDescriptor_Init_PGlowBase | 1 |
| Phyre_PClassDescriptor_Init_PGlowD3D11 | 1 |
| Phyre_PClassDescriptor_Init_PGlowGPUBase | 1 |
| Phyre_PClassDescriptor_Init_PhysicsIntegrate | 1 |
| Phyre_PClassDescriptor_Init_PInputSourceMotionQuatX | 1 |
| Phyre_PClassDescriptor_Init_PLegacyGlow | 1 |
| Phyre_PClassDescriptor_Init_PLegacyGlowBase | 1 |
| Phyre_PClassDescriptor_Init_PLegacyGlowD3D11 | 1 |
| Phyre_PClassDescriptor_Init_PLegacyGlowGPUBase | 1 |
| Phyre_PClassDescriptor_Init_PMeshParticleSystemBase | 1 |
| Phyre_PClassDescriptor_Init_PMLAA | 1 |
| Phyre_PClassDescriptor_Init_PMLAABase | 1 |
| Phyre_PClassDescriptor_Init_PMLAAD3D11 | 1 |
| Phyre_PClassDescriptor_Init_PMotionBlur | 1 |
| Phyre_PClassDescriptor_Init_PMotionBlurBase | 1 |
| Phyre_PClassDescriptor_Init_PMotionBlurD3D11 | 1 |
| Phyre_PClassDescriptor_Init_POccluderGeometryInstance | 1 |
| Phyre_PClassDescriptor_Init_PPostEffectBase | 1 |
| Phyre_PClassDescriptor_Init_PPostEffectManager | 1 |
| Phyre_PClassDescriptor_Init_PScreenSpaceAmbientOcclusion | 1 |
| Phyre_PClassDescriptor_Init_PScreenSpaceAmbientOcclusionBase | 1 |
| Phyre_PClassDescriptor_Init_PScreenSpaceAmbientOcclusionD3D11 | 1 |
| Phyre_PClassDescriptor_Init_PScreenSpaceReflection | 1 |
| Phyre_PClassDescriptor_Init_PScreenSpaceReflectionBase | 1 |
| Phyre_PClassDescriptor_Init_PScreenSpaceReflectionD3D11 | 1 |
| Phyre_PClassDescriptor_Init_Skeleton | 1 |
| Phyre_PClassDescriptor_Init_Transform | 1 |
| Phyre_PClassDescriptor_InitVec3Zero | 1 |
| Phyre_PClassDescriptor_IsRegistered | 1 |
| Phyre_PClassDescriptor_LoadMatrix4x4 | 1 |
| Phyre_PClassDescriptor_LoadVector3 | 1 |
| Phyre_PClassDescriptor_OccluderGeoInstDtor | 1 |
| Phyre_PClassDescriptor_OccluderGeoInstDtor_B | 1 |
| Phyre_PClassDescriptor_OccluderGeoInstDtor_C | 1 |
| Phyre_PClassDescriptor_PAnimatableComponent_Dtor | 1 |
| Phyre_PClassDescriptor_PArray_PBmpFontCharInfo | 1 |
| Phyre_PClassDescriptor_PChar_RegisterAndFinalize | 1 |
| Phyre_PClassDescriptor_PMorphModifierWeightsUserDataObject_ctor | 1 |
| Phyre_PClassDescriptor_PNameValuePair_Register | 1 |
| Phyre_PClassDescriptor_PShape_Setup | 1 |
| Phyre_PClassDescriptor_PUByte_Setup | 1 |
| Phyre_PClassDescriptor_PUByte_Traverse | 1 |
| Phyre_PClassDescriptor_PUByteArray_Setup | 1 |
| Phyre_PClassDescriptor_PushObjectToStream | 1 |
| Phyre_PClassDescriptor_PushPArrayAnimDataSource_ToStream | 1 |
| Phyre_PClassDescriptor_PushToStream | 1 |
| Phyre_PClassDescriptor_PushToStream_C9CA40 | 1 |
| Phyre_PClassDescriptor_PushToStreamAlt | 1 |
| Phyre_PClassDescriptor_PushToStreamSize81 | 1 |
| Phyre_PClassDescriptor_PushToStreamSize87 | 1 |
| Phyre_PClassDescriptor_RadialLineInstance_ctor | 1 |
| Phyre_PClassDescriptor_RadialLineMesh_ctor | 1 |
| Phyre_PClassDescriptor_Register_1943718 | 1 |
| Phyre_PClassDescriptor_Register_19437B0 | 1 |
| Phyre_PClassDescriptor_Register_19438E0 | 1 |
| Phyre_PClassDescriptor_Register_1943978 | 1 |
| Phyre_PClassDescriptor_Register_1943AA8 | 1 |
| Phyre_PClassDescriptor_Register_1943B40 | 1 |
| Phyre_PClassDescriptor_Register_1943BD8 | 1 |
| Phyre_PClassDescriptor_Register_1943C70 | 1 |
| Phyre_PClassDescriptor_Register_1943D08 | 1 |
| Phyre_PClassDescriptor_Register_1943DF0 | 1 |
| Phyre_PClassDescriptor_Register_1943E88 | 1 |
| Phyre_PClassDescriptor_Register_1943F20 | 1 |
| Phyre_PClassDescriptor_Register_1943FB8 | 1 |
| Phyre_PClassDescriptor_Register_19440E8 | 1 |
| Phyre_PClassDescriptor_Register_1944180 | 1 |
| Phyre_PClassDescriptor_Register_1944218 | 1 |
| Phyre_PClassDescriptor_Register_19442B0 | 1 |
| Phyre_PClassDescriptor_Register_1944348 | 1 |
| Phyre_PClassDescriptor_Register_19443E0 | 1 |
| Phyre_PClassDescriptor_Register_1944478 | 1 |
| Phyre_PClassDescriptor_Register_1944510 | 1 |
| Phyre_PClassDescriptor_Register_19445A8 | 1 |
| Phyre_PClassDescriptor_Register_1944640 | 1 |
| Phyre_PClassDescriptor_Register_1944770 | 1 |
| Phyre_PClassDescriptor_Register_1944808 | 1 |
| Phyre_PClassDescriptor_Register_PArrayPInputSource4 | 1 |
| Phyre_PClassDescriptor_RegisterAll | 1 |
| Phyre_PClassDescriptor_RegisterAllLate | 1 |
| Phyre_PClassDescriptor_RegisterBatch | 1 |
| Phyre_PClassDescriptor_RegisterBatch_2 | 1 |
| Phyre_PClassDescriptor_RegisterBatch_3 | 1 |
| Phyre_PClassDescriptor_RegisterBatch_4 | 1 |
| Phyre_PClassDescriptor_RegisterFinalize_C9BD30 | 1 |
| Phyre_PClassDescriptor_RegisterFinalize_C9C748 | 1 |
| Phyre_PClassDescriptor_RegisterFinalize_C9C910 | 1 |
| Phyre_PClassDescriptor_RegisterFinalize_C9C9A8 | 1 |
| Phyre_PClassDescriptor_RegisterFinalize_C9CA40 | 1 |
| Phyre_PClassDescriptor_RegisterSingle | 1 |
| Phyre_PClassDescriptor_RegisterSingle_B | 1 |
| Phyre_PClassDescriptor_RegisterSingle_C | 1 |
| Phyre_PClassDescriptor_ReleaseResource00 | 1 |
| Phyre_PClassDescriptor_ReleaseResource01 | 1 |
| Phyre_PClassDescriptor_ReleaseResource02 | 1 |
| Phyre_PClassDescriptor_ReleaseResource03 | 1 |
| Phyre_PClassDescriptor_ReleaseResource04 | 1 |
| Phyre_PClassDescriptor_Return23 | 1 |
| Phyre_PClassDescriptor_Return2_4AE6C0 | 1 |
| Phyre_PClassDescriptor_Return2_4AE6D0 | 1 |
| Phyre_PClassDescriptor_Return2_4AE6E0 | 1 |
| Phyre_PClassDescriptor_Return2_4AE6F0 | 1 |
| Phyre_PClassDescriptor_Return2_4AE700 | 1 |
| Phyre_PClassDescriptor_ReturnError_4B0C40 | 1 |
| Phyre_PClassDescriptor_ReturnError_4B0C50 | 1 |
| Phyre_PClassDescriptor_ReturnError_4B0C60 | 1 |
| Phyre_PClassDescriptor_ReturnError_4B0C70 | 1 |
| Phyre_PClassDescriptor_ReturnError_4B0C80 | 1 |
| Phyre_PClassDescriptor_ReturnError_4B0C90 | 1 |
| Phyre_PClassDescriptor_ReturnError_4B0CA0 | 1 |
| Phyre_PClassDescriptor_ReturnError_4B0CB0 | 1 |
| Phyre_PClassDescriptor_ReturnError_4B0CC0 | 1 |
| Phyre_PClassDescriptor_ReturnError_4B0CD0 | 1 |
| Phyre_PClassDescriptor_ReturnError_4B0CE0 | 1 |
| Phyre_PClassDescriptor_ReturnError_4B0CF0 | 1 |
| Phyre_PClassDescriptor_ReturnError_4B0D00 | 1 |
| Phyre_PClassDescriptor_ReturnError_4B0D10 | 1 |
| Phyre_PClassDescriptor_ReturnError_4B0D20 | 1 |
| Phyre_PClassDescriptor_ReturnError_4B0D30 | 1 |
| Phyre_PClassDescriptor_ReturnError_4B0D40 | 1 |
| Phyre_PClassDescriptor_ReturnError_4B0D50 | 1 |
| Phyre_PClassDescriptor_ReturnError_4B0D60 | 1 |
| Phyre_PClassDescriptor_ReturnError_4B0D70 | 1 |
| Phyre_PClassDescriptor_ReturnError_4B0D80 | 1 |
| Phyre_PClassDescriptor_ReturnError_4B0D90 | 1 |
| Phyre_PClassDescriptor_ReturnError_4B0DA0 | 1 |
| Phyre_PClassDescriptor_ReturnError_4B0DB0 | 1 |
| Phyre_PClassDescriptor_ReturnError_4B0DC0 | 1 |
| Phyre_PClassDescriptor_ReturnMinus1 | 1 |
| Phyre_PClassDescriptor_ReturnMinus1_1 | 1 |
| Phyre_PClassDescriptor_ReturnMinus1_2 | 1 |
| Phyre_PClassDescriptor_ReturnMinus1_3 | 1 |
| Phyre_PClassDescriptor_ReturnMinus1_4 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v10 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v11 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v12 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v13 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v14 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v15 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v16 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v17 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v18 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v19 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v2 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v20 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v21 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v22 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v23 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v24 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v25 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v26 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v27 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v28 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v29 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v3 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v30 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v31 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v32 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v33 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v34 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v35 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v36 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v37 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v38 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v39 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v4 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v40 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v41 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v42 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v43 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v44 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v45 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v46 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v47 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v48 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v49 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v5 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v50 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v51 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v52 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v6 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v7 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v8 | 1 |
| Phyre_PClassDescriptor_ReturnMinusOne_v9 | 1 |
| Phyre_PClassDescriptor_ReturnThis | 1 |
| Phyre_PClassDescriptor_ReturnThis_2 | 1 |
| Phyre_PClassDescriptor_ReturnThis_3 | 1 |
| Phyre_PClassDescriptor_ReturnTwo | 1 |
| Phyre_PClassDescriptor_ReturnZero | 1 |
| Phyre_PClassDescriptor_ReturnZero_stdcall | 1 |
| Phyre_PClassDescriptor_ReturnZero_v10 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v11 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v12 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v13 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v14 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v15 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v16 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v17 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v18 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v19 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v2 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v20 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v21 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v22 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v23 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v24 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v25 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v26 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v27 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v28 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v29 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v3 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v30 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v31 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v32 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v33 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v34 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v35 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v36 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v37 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v38 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v39 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v4 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v40 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v5 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v6 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v7 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v8 | 1 |
| Phyre_PClassDescriptor_ReturnZero_v9 | 1 |
| Phyre_PClassDescriptor_ScriptAccessor_AdditiveBlenderControllerPtrGet | 1 |
| Phyre_PClassDescriptor_ScriptAccessor_AdditiveBlenderRefGet | 1 |
| Phyre_PClassDescriptor_ScriptAccessor_ChannelSetKeyframe | 1 |
| Phyre_PClassDescriptor_ScriptAccessor_GetWeight | 1 |
| Phyre_PClassDescriptor_ScriptAccessor_PAnimationSlotFilterDeferredLoadPtr | 1 |
| Phyre_PClassDescriptor_ScriptAccessor_PushArraySlotFilterDeferredLoadDescToStream | 1 |
| Phyre_PClassDescriptor_ScriptAccessor_PushArrayUIntDescToStream | 1 |
| Phyre_PClassDescriptor_ScriptAccessor_PushObjectToStream | 1 |
| Phyre_PClassDescriptor_ScriptAccessor_PushPArrayAnimDataSource | 1 |
| Phyre_PClassDescriptor_ScriptAccessor_SetWeight | 1 |
| Phyre_PClassDescriptor_ScriptAccessor_TargetBlenderControllerPtrGet | 1 |
| Phyre_PClassDescriptor_ScriptAccessor_UIntArrayAdd | 1 |
| Phyre_PClassDescriptor_ScriptAccessor_UIntArraySet | 1 |
| Phyre_PClassDescriptor_ScriptAccessor_UIntArraySetElement | 1 |
| Phyre_PClassDescriptor_ScriptAccessor_UIntPairArraySet | 1 |
| Phyre_PClassDescriptor_ScriptAccessor_WeightedBlenderControllerPtrGet | 1 |
| Phyre_PClassDescriptor_ScriptAccessor_WeightedBlenderRefGet | 1 |
| Phyre_PClassDescriptor_SetField64 | 1 |
| Phyre_PClassDescriptor_SetField68 | 1 |
| Phyre_PClassDescriptor_SetField6C | 1 |
| Phyre_PClassDescriptor_SetFields74_78 | 1 |
| Phyre_PClassDescriptor_SetFlag | 1 |
| Phyre_PClassDescriptor_SetFlag_2 | 1 |
| Phyre_PClassDescriptor_SetFlag_Offset4 | 1 |
| Phyre_PClassDescriptor_SetProperty | 1 |
| Phyre_PClassDescriptor_Setup_49BDD0 | 1 |
| Phyre_PClassDescriptor_SetValue | 1 |
| Phyre_PClassDescriptor_SetValueDirect | 1 |
| Phyre_PClassDescriptor_SetValueOrReset | 1 |
| Phyre_PClassDescriptor_SimpleInit_49BDA0 | 1 |
| Phyre_PClassDescriptor_Size16 | 1 |
| Phyre_PClassDescriptor_SizeCB1C58_Get | 1 |
| Phyre_PClassDescriptor_SizeCB1C58_GetTotalSize | 1 |
| Phyre_PClassDescriptor_SizeCB1CF0_Get | 1 |
| Phyre_PClassDescriptor_SizeCB1CF0_GetTotalSize | 1 |
| Phyre_PClassDescriptor_SizeCB1EB8_GetTotalSize | 1 |
| Phyre_PClassDescriptor_SizeCB1F50_Get | 1 |
| Phyre_PClassDescriptor_SizeCB1F50_GetTotalSize | 1 |
| Phyre_PClassDescriptor_SupportsType_PAnimationScriptController | 1 |
| Phyre_PClassDescriptor_Traverse | 1 |
| Phyre_PClassDescriptor_Traverse_PAnimatableComponent | 1 |
| Phyre_PClassDescriptor_Traverse_PAnimationDataSrcBuffer | 1 |
| Phyre_PClassDescriptor_Traverse_PArrayU8 | 1 |
| Phyre_PClassDescriptor_Traverse_PModifierAndInputs | 1 |
| Phyre_PClassDescriptor_Traverse_PModifierNetwork | 1 |
| Phyre_PClassDescriptor_Traverse_PModifierNetworkBuffer | 1 |
| Phyre_PClassDescriptor_Traverse_PModifierNetworkInfoPacket | 1 |
| Phyre_PClassDescriptor_Traverse_PModifierNetworkInfoPacketBuffer | 1 |
| Phyre_PClassDescriptor_Traverse_PModifierNetworkInfoPacketModifierCode | 1 |
| Phyre_PClassDescriptor_Traverse_PModifierNetworkInfoPacketModifierInstance | 1 |
| Phyre_PClassDescriptor_Traverse_PRenderStream | 1 |
| Phyre_PClassDescriptor_Traverse_PScriptableComponent | 1 |
| Phyre_PClassDescriptor_Traverse_PSpline | 1 |
| Phyre_PClassDescriptor_TraverseGlobal | 1 |
| Phyre_PClassDescriptor_TraversePropertyList | 1 |
| Phyre_PClassDescriptor_TraversePropertyList_V2 | 1 |
| Phyre_PClassDescriptor_TraverseSize78_Flagged | 1 |
| Phyre_PClassDescriptor_TraverseSize81 | 1 |
| Phyre_PClassDescriptor_TraverseSize87 | 1 |
| Phyre_PClassDescriptor_TraverseWithFlag | 1 |
| Phyre_PClassDescriptor_TraverseWithFlag_dword1940EF8 | 1 |
| Phyre_PClassDescriptor_TraverseWithFlag_dword1940F90 | 1 |
| Phyre_PClassDescriptor_TraverseWithFlag_dword1941028 | 1 |
| Phyre_PClassDescriptor_TraverseWithFlag_dword19410C0 | 1 |
| Phyre_PClassDescriptor_TraverseWithFlag_dword1941158 | 1 |
| Phyre_PClassDescriptor_TraverseWithFlag_dword19411F0 | 1 |
| Phyre_PClassDescriptor_TraverseWithFlag_PModifierAndInputs | 1 |
| Phyre_PClassDescriptor_TraverseWithFlag_PModifierNetworkBuffer | 1 |
| Phyre_PClassDescriptor_TraverseWithFlag_PRenderStreamInput | 1 |
| Phyre_PClassDescriptor_TraverseWithFlag_Size101 | 1 |
| Phyre_PClassDescriptor_TraverseWithFlag_Size102 | 1 |
| Phyre_PClassDescriptor_TraverseWithFlag_Size103 | 1 |
| Phyre_PClassDescriptor_TraverseWithFlag_Size112 | 1 |
| Phyre_PClassDescriptor_TraverseWithFlag_Size113 | 1 |
| Phyre_PClassDescriptor_TraverseWithFlag_Size114 | 1 |
| Phyre_PClassDescriptor_TraverseWithFlag_Size94 | 1 |
| Phyre_PClassDescriptor_TraverseWithFlag_Thunk | 1 |
| Phyre_PClassDescriptor_TraverseWithFlag_UsingSize57 | 1 |
| Phyre_PClassDescriptor_TraverseWithFlag_w | 1 |
| Phyre_PClassDescriptor_TraverseWithFlag_Wrapper | 1 |
| Phyre_PClassDescriptor_TraverseWithFlag_Wrapper2 | 1 |
| Phyre_PClassDescriptor_TraverseWithFlagWrap | 1 |
| Phyre_PClassDescriptor_TraverseWrapper | 1 |
| Phyre_PClassDescriptor_TrivialDtor | 1 |
| Phyre_PClassDescriptor_TrivialDtor_v2 | 1 |
| Phyre_PClassDescriptor_TrivialDtor_v3 | 1 |
| Phyre_PClassDescriptor_TrivialDtor_v4 | 1 |
| Phyre_PClassDescriptor_TrivialDtor_v5 | 1 |
| Phyre_PClassDescriptor_Unregister | 1 |
| Phyre_PClassDescriptor_ValidateAndAlloc | 1 |
| Phyre_PClassDescriptor_ValidateInheritance | 1 |
| Phyre_PClassDescriptor_VtableDispatch_Slot37 | 1 |
| Phyre_PClassDescriptor_ZeroOut2 | 1 |
| Phyre_PClassDescriptor_ZeroOutPtr | 1 |

## Complete Function List

| # | addr | name | size | has_type |
|---|---|---|---|---|
| 1 | 0x5fe660 | Phyre_PClassDescriptor_AbstractGetValue | 0x12 | true |
| 2 | 0x5fe780 | Phyre_PClassDescriptor_AbstractGetValue_v10 | 0x12 | true |
| 3 | 0x5fe7a0 | Phyre_PClassDescriptor_AbstractGetValue_v11 | 0x12 | true |
| 4 | 0x5fe7c0 | Phyre_PClassDescriptor_AbstractGetValue_v12 | 0x12 | true |
| 5 | 0x5fe7e0 | Phyre_PClassDescriptor_AbstractGetValue_v13 | 0x12 | true |
| 6 | 0x5fe800 | Phyre_PClassDescriptor_AbstractGetValue_v14 | 0x12 | true |
| 7 | 0x5fe820 | Phyre_PClassDescriptor_AbstractGetValue_v15 | 0x12 | true |
| 8 | 0x5fe840 | Phyre_PClassDescriptor_AbstractGetValue_v16 | 0x12 | true |
| 9 | 0x5fe860 | Phyre_PClassDescriptor_AbstractGetValue_v17 | 0x12 | true |
| 10 | 0x5fe880 | Phyre_PClassDescriptor_AbstractGetValue_v18 | 0x12 | true |
| 11 | 0x5fe8a0 | Phyre_PClassDescriptor_AbstractGetValue_v19 | 0x12 | true |
| 12 | 0x5fe680 | Phyre_PClassDescriptor_AbstractGetValue_v2 | 0x12 | true |
| 13 | 0x5fe8c0 | Phyre_PClassDescriptor_AbstractGetValue_v20 | 0x12 | true |
| 14 | 0x5fe8e0 | Phyre_PClassDescriptor_AbstractGetValue_v21 | 0x12 | true |
| 15 | 0x5fe900 | Phyre_PClassDescriptor_AbstractGetValue_v22 | 0x12 | true |
| 16 | 0x5fe920 | Phyre_PClassDescriptor_AbstractGetValue_v23 | 0x12 | true |
| 17 | 0x5fe940 | Phyre_PClassDescriptor_AbstractGetValue_v24 | 0x12 | true |
| 18 | 0x5fe960 | Phyre_PClassDescriptor_AbstractGetValue_v25 | 0x12 | true |
| 19 | 0x5fe980 | Phyre_PClassDescriptor_AbstractGetValue_v26 | 0x12 | true |
| 20 | 0x5fe9a0 | Phyre_PClassDescriptor_AbstractGetValue_v27 | 0x12 | true |
| 21 | 0x5fe9c0 | Phyre_PClassDescriptor_AbstractGetValue_v28 | 0x12 | true |
| 22 | 0x5fe9e0 | Phyre_PClassDescriptor_AbstractGetValue_v29 | 0x12 | true |
| 23 | 0x5fe6a0 | Phyre_PClassDescriptor_AbstractGetValue_v3 | 0x12 | true |
| 24 | 0x5fea00 | Phyre_PClassDescriptor_AbstractGetValue_v30 | 0x12 | true |
| 25 | 0x5fea20 | Phyre_PClassDescriptor_AbstractGetValue_v31 | 0x12 | true |
| 26 | 0x5fea40 | Phyre_PClassDescriptor_AbstractGetValue_v32 | 0x12 | true |
| 27 | 0x5fea60 | Phyre_PClassDescriptor_AbstractGetValue_v33 | 0x12 | true |
| 28 | 0x5fea80 | Phyre_PClassDescriptor_AbstractGetValue_v34 | 0x12 | true |
| 29 | 0x5feaa0 | Phyre_PClassDescriptor_AbstractGetValue_v35 | 0x12 | true |
| 30 | 0x5feac0 | Phyre_PClassDescriptor_AbstractGetValue_v36 | 0x12 | true |
| 31 | 0x5feae0 | Phyre_PClassDescriptor_AbstractGetValue_v37 | 0x12 | true |
| 32 | 0x5feb00 | Phyre_PClassDescriptor_AbstractGetValue_v38 | 0x12 | true |
| 33 | 0x5feb20 | Phyre_PClassDescriptor_AbstractGetValue_v39 | 0x12 | true |
| 34 | 0x5fe6c0 | Phyre_PClassDescriptor_AbstractGetValue_v4 | 0x12 | true |
| 35 | 0x5feb40 | Phyre_PClassDescriptor_AbstractGetValue_v40 | 0x12 | true |
| 36 | 0x5feb60 | Phyre_PClassDescriptor_AbstractGetValue_v41 | 0x12 | true |
| 37 | 0x5fe6e0 | Phyre_PClassDescriptor_AbstractGetValue_v5 | 0x12 | true |
| 38 | 0x5fe700 | Phyre_PClassDescriptor_AbstractGetValue_v6 | 0x12 | true |
| 39 | 0x5fe720 | Phyre_PClassDescriptor_AbstractGetValue_v7 | 0x12 | true |
| 40 | 0x5fe740 | Phyre_PClassDescriptor_AbstractGetValue_v8 | 0x12 | true |
| 41 | 0x5fe760 | Phyre_PClassDescriptor_AbstractGetValue_v9 | 0x12 | true |
| 42 | 0x544380 | Phyre_PClassDescriptor_AnimatableComponent_GetSizeOrDefault | 0x22 | true |
| 43 | 0x538ea0 | Phyre_PClassDescriptor_AnimationNetworkInstance_GetDescPtr | 0x6 | true |
| 44 | 0x538ed0 | Phyre_PClassDescriptor_AnimationNetworkInstance_GetDescPtr_Dup | 0x6 | true |
| 45 | 0x538ec0 | Phyre_PClassDescriptor_AnimationNetworkInstance_GetSize48 | 0x6 | true |
| 46 | 0x538eb0 | Phyre_PClassDescriptor_AnimationNetworkInstance_GetSize64 | 0x6 | true |
| 47 | 0x538e90 | Phyre_PClassDescriptor_AnimationNetworkInstance_Size48 | 0x6 | true |
| 48 | 0x538e80 | Phyre_PClassDescriptor_AnimationNetworkInstance_Size64 | 0x6 | true |
| 49 | 0x677620 | Phyre_PClassDescriptor_BrokenScreenMesh_ctor | 0x90 | true |
| 50 | 0x676c30 | Phyre_PClassDescriptor_BrokenScreenPolygonInstance_ctor | 0x90 | true |
| 51 | 0x43d7d0 | Phyre_PClassDescriptor_CalcLayoutSize | 0x68 | true |
| 52 | 0x52f8b0 | Phyre_PClassDescriptor_CalcTotalSize_AdditiveBlenderController | 0x16 | true |
| 53 | 0x52a610 | Phyre_PClassDescriptor_CalcTotalSize_AnimationDescriptor | 0x19 | true |
| 54 | 0x52e3b0 | Phyre_PClassDescriptor_CalcTotalSize_WeightedBlenderController | 0x16 | true |
| 55 | 0x4b08a0 | Phyre_PClassDescriptor_CanConvert_False_4B08A0 | 0x5 | true |
| 56 | 0x4b08b0 | Phyre_PClassDescriptor_CanConvert_False_4B08B0 | 0x5 | true |
| 57 | 0x4b08c0 | Phyre_PClassDescriptor_CanConvert_False_4B08C0 | 0x5 | true |
| 58 | 0x4b08d0 | Phyre_PClassDescriptor_CanConvert_False_4B08D0 | 0x5 | true |
| 59 | 0x4b08e0 | Phyre_PClassDescriptor_CanConvert_False_4B08E0 | 0x5 | true |
| 60 | 0x4b08f0 | Phyre_PClassDescriptor_CanConvert_False_4B08F0 | 0x5 | true |
| 61 | 0x4b0900 | Phyre_PClassDescriptor_CanConvert_False_4B0900 | 0x5 | true |
| 62 | 0x4b0910 | Phyre_PClassDescriptor_CanConvert_False_4B0910 | 0x5 | true |
| 63 | 0x4b0920 | Phyre_PClassDescriptor_CanConvert_False_4B0920 | 0x5 | true |
| 64 | 0x4b0930 | Phyre_PClassDescriptor_CanConvert_False_4B0930 | 0x5 | true |
| 65 | 0x4b0940 | Phyre_PClassDescriptor_CanConvert_False_4B0940 | 0x5 | true |
| 66 | 0x4b0950 | Phyre_PClassDescriptor_CanConvert_False_4B0950 | 0x5 | true |
| 67 | 0x4b0960 | Phyre_PClassDescriptor_CanConvert_False_4B0960 | 0x5 | true |
| 68 | 0x4b0970 | Phyre_PClassDescriptor_CanConvert_False_4B0970 | 0x5 | true |
| 69 | 0x4b0980 | Phyre_PClassDescriptor_CanConvert_False_4B0980 | 0x5 | true |
| 70 | 0x4b0990 | Phyre_PClassDescriptor_CanConvert_False_4B0990 | 0x5 | true |
| 71 | 0x4b09a0 | Phyre_PClassDescriptor_CanConvert_False_4B09A0 | 0x5 | true |
| 72 | 0x4b09b0 | Phyre_PClassDescriptor_CanConvert_False_4B09B0 | 0x5 | true |
| 73 | 0x4b09c0 | Phyre_PClassDescriptor_CanConvert_False_4B09C0 | 0x5 | true |
| 74 | 0x4b09d0 | Phyre_PClassDescriptor_CanConvert_False_4B09D0 | 0x5 | true |
| 75 | 0x4b09e0 | Phyre_PClassDescriptor_CanConvert_False_4B09E0 | 0x5 | true |
| 76 | 0x4b09f0 | Phyre_PClassDescriptor_CanConvert_False_4B09F0 | 0x5 | true |
| 77 | 0x4b0a00 | Phyre_PClassDescriptor_CanConvert_False_4B0A00 | 0x5 | true |
| 78 | 0x4b0710 | Phyre_PClassDescriptor_CanConvert_True_4B0710 | 0x5 | true |
| 79 | 0x4b0720 | Phyre_PClassDescriptor_CanConvert_True_4B0720 | 0x5 | true |
| 80 | 0x4b0730 | Phyre_PClassDescriptor_CanConvert_True_4B0730 | 0x5 | true |
| 81 | 0x4b0740 | Phyre_PClassDescriptor_CanConvert_True_4B0740 | 0x5 | true |
| 82 | 0x4b0750 | Phyre_PClassDescriptor_CanConvert_True_4B0750 | 0x5 | true |
| 83 | 0x4b0760 | Phyre_PClassDescriptor_CanConvert_True_4B0760 | 0x5 | true |
| 84 | 0x4b0770 | Phyre_PClassDescriptor_CanConvert_True_4B0770 | 0x5 | true |
| 85 | 0x4b0780 | Phyre_PClassDescriptor_CanConvert_True_4B0780 | 0x5 | true |
| 86 | 0x4b0790 | Phyre_PClassDescriptor_CanConvert_True_4B0790 | 0x5 | true |
| 87 | 0x4b07a0 | Phyre_PClassDescriptor_CanConvert_True_4B07A0 | 0x5 | true |
| 88 | 0x4b07b0 | Phyre_PClassDescriptor_CanConvert_True_4B07B0 | 0x5 | true |
| 89 | 0x4b07c0 | Phyre_PClassDescriptor_CanConvert_True_4B07C0 | 0x5 | true |
| 90 | 0x4b07d0 | Phyre_PClassDescriptor_CanConvert_True_4B07D0 | 0x5 | true |
| 91 | 0x4b07e0 | Phyre_PClassDescriptor_CanConvert_True_4B07E0 | 0x5 | true |
| 92 | 0x4b07f0 | Phyre_PClassDescriptor_CanConvert_True_4B07F0 | 0x5 | true |
| 93 | 0x4321c0 | Phyre_PClassDescriptor_ClearSignBit | 0x8 | true |
| 94 | 0x5f7d80 | Phyre_PClassDescriptor_Construct_PPhysicsCharacterCamera | 0x15 | true |
| 95 | 0x5f8330 | Phyre_PClassDescriptor_Construct_PPhysicsShape | 0x26 | true |
| 96 | 0x5f8360 | Phyre_PClassDescriptor_Construct_PPhysicsShapeBullet | 0x26 | true |
| 97 | 0x43b0a0 | Phyre_PClassDescriptor_Constructor | 0xef | true |
| 98 | 0x6434f0 | Phyre_PClassDescriptor_CreateType | 0x102 | true |
| 99 | 0x43b190 | Phyre_PClassDescriptor_ctor | 0xed | true |
| 100 | 0xa32ef0 | Phyre_PClassDescriptor_ctor_PArrayPInputMapPtr4 | 0x92 | true |
| 101 | 0xa32f90 | Phyre_PClassDescriptor_ctor_PGameSettings | 0x91 | true |
| 102 | 0x5ddfc0 | Phyre_PClassDescriptor_ctor_PPhysicsPlane | 0x90 | true |
| 103 | 0x52a2c0 | Phyre_PClassDescriptor_DeleteViaOffset | 0x26 | true |
| 104 | 0x5208f0 | Phyre_PClassDescriptor_Deref_PAnimationBlenderWeight | 0x5 | true |
| 105 | 0x520a30 | Phyre_PClassDescriptor_Deref_PAnimationWeightedBlenderController | 0x4 | true |
| 106 | 0x520a40 | Phyre_PClassDescriptor_Deref_PAnimationWeightedBlenderController_B | 0x4 | true |
| 107 | 0x520a50 | Phyre_PClassDescriptor_Deref_PAnimationWeightedBlenderController_C | 0x6 | true |
| 108 | 0x51cf00 | Phyre_PClassDescriptor_DerefThis_PAnimationEventController | 0x4 | true |
| 109 | 0x51cf10 | Phyre_PClassDescriptor_DerefThis_PAnimationEventController_B | 0x4 | true |
| 110 | 0x51cf20 | Phyre_PClassDescriptor_DerefThis_PAnimationEventController_C | 0x4 | true |
| 111 | 0x51cf30 | Phyre_PClassDescriptor_DerefThis_PAnimationEventController_D | 0x4 | true |
| 112 | 0x5167f0 | Phyre_PClassDescriptor_DerefThis_PAnimationSlotSet | 0x4 | true |
| 113 | 0x516800 | Phyre_PClassDescriptor_DerefThis_PAnimationSlotSet_B | 0x4 | true |
| 114 | 0x516810 | Phyre_PClassDescriptor_DerefThis_PAnimationSlotSet_C | 0x4 | true |
| 115 | 0x43ded0 | Phyre_PClassDescriptor_DestroyHierarchy | 0x44 | true |
| 116 | 0xafa150 | Phyre_PClassDescriptor_DestroyHierarchy_C90B00 | 0xa | true |
| 117 | 0x43cb80 | Phyre_PClassDescriptor_DestroyWrap | 0x28 | true |
| 118 | 0x43b4d0 | Phyre_PClassDescriptor_Destructor | 0x1bf | true |
| 119 | 0x509a10 | Phyre_PClassDescriptor_Destructor_w | 0xb | true |
| 120 | 0x496a40 | Phyre_PClassDescriptor_Destructor_w_0 | 0xb | true |
| 121 | 0x496a50 | Phyre_PClassDescriptor_Destructor_w_1 | 0xb | true |
| 122 | 0x4a17a0 | Phyre_PClassDescriptor_Destructor_w_10 | 0xb | true |
| 123 | 0x4a17b0 | Phyre_PClassDescriptor_Destructor_w_11 | 0xb | true |
| 124 | 0x4a17c0 | Phyre_PClassDescriptor_Destructor_w_12 | 0xb | true |
| 125 | 0x4a17d0 | Phyre_PClassDescriptor_Destructor_w_13 | 0xb | true |
| 126 | 0x4a17e0 | Phyre_PClassDescriptor_Destructor_w_14 | 0xb | true |
| 127 | 0x5e1630 | Phyre_PClassDescriptor_Destructor_w_15 | 0xb | true |
| 128 | 0x5e1a10 | Phyre_PClassDescriptor_Destructor_w_16 | 0xb | true |
| 129 | 0x5e1650 | Phyre_PClassDescriptor_Destructor_w_17 | 0xb | true |
| 130 | 0x5e1a20 | Phyre_PClassDescriptor_Destructor_w_18 | 0xb | true |
| 131 | 0x5e1a30 | Phyre_PClassDescriptor_Destructor_w_19 | 0xb | true |
| 132 | 0x496a60 | Phyre_PClassDescriptor_Destructor_w_2 | 0xb | true |
| 133 | 0x5e1a40 | Phyre_PClassDescriptor_Destructor_w_20 | 0xb | true |
| 134 | 0x5e1a50 | Phyre_PClassDescriptor_Destructor_w_21 | 0xb | true |
| 135 | 0x5e1a60 | Phyre_PClassDescriptor_Destructor_w_22 | 0xb | true |
| 136 | 0x5e1a70 | Phyre_PClassDescriptor_Destructor_w_23 | 0xb | true |
| 137 | 0x5e1a80 | Phyre_PClassDescriptor_Destructor_w_24 | 0xb | true |
| 138 | 0x5e1a90 | Phyre_PClassDescriptor_Destructor_w_25 | 0xb | true |
| 139 | 0x5e1aa0 | Phyre_PClassDescriptor_Destructor_w_26 | 0xb | true |
| 140 | 0x9e1df0 | Phyre_PClassDescriptor_Destructor_w_27 | 0xb | true |
| 141 | 0x9e1e00 | Phyre_PClassDescriptor_Destructor_w_28 | 0xb | true |
| 142 | 0x4be9e0 | Phyre_PClassDescriptor_Destructor_w_29 | 0xb | true |
| 143 | 0x496a70 | Phyre_PClassDescriptor_Destructor_w_3 | 0xb | true |
| 144 | 0x4be9f0 | Phyre_PClassDescriptor_Destructor_w_30 | 0xb | true |
| 145 | 0x9e1e10 | Phyre_PClassDescriptor_Destructor_w_31 | 0xb | true |
| 146 | 0x9e1e20 | Phyre_PClassDescriptor_Destructor_w_32 | 0xb | true |
| 147 | 0x4c61d0 | Phyre_PClassDescriptor_Destructor_w_33 | 0xb | true |
| 148 | 0x4c61e0 | Phyre_PClassDescriptor_Destructor_w_34 | 0xb | true |
| 149 | 0x9e1e30 | Phyre_PClassDescriptor_Destructor_w_35 | 0xb | true |
| 150 | 0x9e1e40 | Phyre_PClassDescriptor_Destructor_w_36 | 0xb | true |
| 151 | 0x9e1e50 | Phyre_PClassDescriptor_Destructor_w_37 | 0xb | true |
| 152 | 0x9e1e60 | Phyre_PClassDescriptor_Destructor_w_38 | 0xb | true |
| 153 | 0x9e1e70 | Phyre_PClassDescriptor_Destructor_w_39 | 0xb | true |
| 154 | 0x496a80 | Phyre_PClassDescriptor_Destructor_w_4 | 0xb | true |
| 155 | 0x9e1e80 | Phyre_PClassDescriptor_Destructor_w_40 | 0xb | true |
| 156 | 0x9e1e90 | Phyre_PClassDescriptor_Destructor_w_41 | 0xb | true |
| 157 | 0x9e1ea0 | Phyre_PClassDescriptor_Destructor_w_42 | 0xb | true |
| 158 | 0x9e1eb0 | Phyre_PClassDescriptor_Destructor_w_43 | 0xb | true |
| 159 | 0x9e1ec0 | Phyre_PClassDescriptor_Destructor_w_44 | 0xb | true |
| 160 | 0x9e1ed0 | Phyre_PClassDescriptor_Destructor_w_45 | 0xb | true |
| 161 | 0x6f9590 | Phyre_PClassDescriptor_Destructor_w_46 | 0xb | true |
| 162 | 0x9e1ef0 | Phyre_PClassDescriptor_Destructor_w_47 | 0xb | true |
| 163 | 0x9e1f00 | Phyre_PClassDescriptor_Destructor_w_48 | 0xb | true |
| 164 | 0x9e1f10 | Phyre_PClassDescriptor_Destructor_w_49 | 0xb | true |
| 165 | 0x4a1750 | Phyre_PClassDescriptor_Destructor_w_5 | 0xb | true |
| 166 | 0x9e1f20 | Phyre_PClassDescriptor_Destructor_w_50 | 0xb | true |
| 167 | 0x9e1f30 | Phyre_PClassDescriptor_Destructor_w_51 | 0xb | true |
| 168 | 0x6f95b0 | Phyre_PClassDescriptor_Destructor_w_52 | 0xb | true |
| 169 | 0x5bf6f0 | Phyre_PClassDescriptor_Destructor_w_53 | 0xb | true |
| 170 | 0x5bf700 | Phyre_PClassDescriptor_Destructor_w_54 | 0xb | true |
| 171 | 0x9e1f70 | Phyre_PClassDescriptor_Destructor_w_55 | 0xb | true |
| 172 | 0x5bf710 | Phyre_PClassDescriptor_Destructor_w_56 | 0xb | true |
| 173 | 0x4a1760 | Phyre_PClassDescriptor_Destructor_w_6 | 0xb | true |
| 174 | 0x4a1770 | Phyre_PClassDescriptor_Destructor_w_7 | 0xb | true |
| 175 | 0x4a1780 | Phyre_PClassDescriptor_Destructor_w_8 | 0xb | true |
| 176 | 0x4a1790 | Phyre_PClassDescriptor_Destructor_w_9 | 0xb | true |
| 177 | 0x674040 | Phyre_PClassDescriptor_DistortionGridDynamicMesh_ctor | 0x90 | true |
| 178 | 0x674ca0 | Phyre_PClassDescriptor_DistortionGridInstance_ctor | 0x90 | true |
| 179 | 0xa2bd40 | Phyre_PClassDescriptor_Dtor_A2BD40 | 0x21 | true |
| 180 | 0xa2bd70 | Phyre_PClassDescriptor_Dtor_A2BD70 | 0x21 | true |
| 181 | 0x43b900 | Phyre_PClassDescriptor_Dtor_Base | 0x21 | true |
| 182 | 0xb06b10 | Phyre_PClassDescriptor_Dtor_BrokenScreenPolygonDynamicMesh | 0x14 | true |
| 183 | 0xb06ac0 | Phyre_PClassDescriptor_Dtor_BrokenScreenPolygonDynamicMeshInstance | 0x14 | true |
| 184 | 0xb075e0 | Phyre_PClassDescriptor_Dtor_ClothInstancingDynamicMesh | 0x14 | true |
| 185 | 0xb07600 | Phyre_PClassDescriptor_Dtor_ClothInstancingDynamicMeshInstance | 0x14 | true |
| 186 | 0xb06980 | Phyre_PClassDescriptor_Dtor_DistortionGridDynamicMesh | 0x14 | true |
| 187 | 0xb069d0 | Phyre_PClassDescriptor_Dtor_DistortionGridDynamicMeshInstance | 0x14 | true |
| 188 | 0xb07620 | Phyre_PClassDescriptor_Dtor_DynamicMeshDefaultImplmenetation | 0x14 | true |
| 189 | 0xb04400 | Phyre_PClassDescriptor_Dtor_PArray_PDynamicGeometry_PModifierAndInputs_4 | 0x14 | true |
| 190 | 0xb04420 | Phyre_PClassDescriptor_Dtor_PArray_PDynamicGeometry_PModifierNetworkBuffer_4 | 0x14 | true |
| 191 | 0xb04440 | Phyre_PClassDescriptor_Dtor_PArray_PDynamicGeometry_PRenderStreamInput_4 | 0x14 | true |
| 192 | 0xb08120 | Phyre_PClassDescriptor_Dtor_PArrayPInputAction4 | 0x14 | true |
| 193 | 0x9e1fa0 | Phyre_PClassDescriptor_Dtor_PArrayPInputAction4_alt | 0xb | true |
| 194 | 0xb08140 | Phyre_PClassDescriptor_Dtor_PArrayPInputSource4 | 0x14 | true |
| 195 | 0x9e1fb0 | Phyre_PClassDescriptor_Dtor_PArrayPInputSource4_alt | 0xb | true |
| 196 | 0xb068e0 | Phyre_PClassDescriptor_Dtor_PClassDynamicMesh | 0x14 | true |
| 197 | 0xb06930 | Phyre_PClassDescriptor_Dtor_PClassDynamicMeshInstance | 0x14 | true |
| 198 | 0xb042b0 | Phyre_PClassDescriptor_Dtor_PDynamicGeometry_PModifierAndInputs | 0x14 | true |
| 199 | 0xb042d0 | Phyre_PClassDescriptor_Dtor_PDynamicGeometry_PModifierNetwork | 0x14 | true |
| 200 | 0xb042f0 | Phyre_PClassDescriptor_Dtor_PDynamicGeometry_PModifierNetworkBuffer | 0x14 | true |
| 201 | 0xb04310 | Phyre_PClassDescriptor_Dtor_PDynamicGeometry_PModifierNetworkInfoPacket | 0x14 | true |
| 202 | 0xb04330 | Phyre_PClassDescriptor_Dtor_PDynamicGeometry_PModifierNetworkInfoPacket_Buffer | 0x14 | true |
| 203 | 0xb04350 | Phyre_PClassDescriptor_Dtor_PDynamicGeometry_PModifierNetworkInfoPacket_ModifierCode | 0x14 | true |
| 204 | 0xb04370 | Phyre_PClassDescriptor_Dtor_PDynamicGeometry_PModifierNetworkInfoPacket_ModifierInstance | 0x14 | true |
| 205 | 0xb047b0 | Phyre_PClassDescriptor_Dtor_PDynamicGeometry_PMorphModifierWeightsUserDataObject | 0x14 | true |
| 206 | 0xb04390 | Phyre_PClassDescriptor_Dtor_PDynamicGeometry_PRenderStream | 0x14 | true |
| 207 | 0xb043b0 | Phyre_PClassDescriptor_Dtor_PDynamicGeometry_PRenderStreamInput | 0x14 | true |
| 208 | 0xb060d0 | Phyre_PClassDescriptor_Dtor_PFramework_PApplication | 0x14 | true |
| 209 | 0xb060f0 | Phyre_PClassDescriptor_Dtor_PFramework_PApplicationViewport | 0x14 | true |
| 210 | 0xb06110 | Phyre_PClassDescriptor_Dtor_PFramework_PInputMapper | 0x14 | true |
| 211 | 0xb07de0 | Phyre_PClassDescriptor_Dtor_PInputAction | 0x14 | true |
| 212 | 0x9e1fc0 | Phyre_PClassDescriptor_Dtor_PInputAction_alt | 0xb | true |
| 213 | 0xb07e00 | Phyre_PClassDescriptor_Dtor_PInputMap | 0x14 | true |
| 214 | 0x9e1fd0 | Phyre_PClassDescriptor_Dtor_PInputMap_alt | 0xb | true |
| 215 | 0xb07e20 | Phyre_PClassDescriptor_Dtor_PInputSource | 0x14 | true |
| 216 | 0xb07e40 | Phyre_PClassDescriptor_Dtor_PInputSourceJoypadAxis | 0x14 | true |
| 217 | 0x9e1fe0 | Phyre_PClassDescriptor_Dtor_PInputSourceJoypadAxis_alt | 0xb | true |
| 218 | 0xb07e60 | Phyre_PClassDescriptor_Dtor_PInputSourceJoypadButton | 0x14 | true |
| 219 | 0x9e1ff0 | Phyre_PClassDescriptor_Dtor_PInputSourceJoypadButton_alt | 0xb | true |
| 220 | 0xb07e80 | Phyre_PClassDescriptor_Dtor_PInputSourceKey | 0x14 | true |
| 221 | 0x9e2000 | Phyre_PClassDescriptor_Dtor_PInputSourceKey_thunk | 0xb | true |
| 222 | 0xb07ea0 | Phyre_PClassDescriptor_Dtor_PInputSourceMotionAngularVelocityX | 0x14 | true |
| 223 | 0x9e2010 | Phyre_PClassDescriptor_Dtor_PInputSourceMotionAngularVelocityX_thunk | 0xb | true |
| 224 | 0xb07ec0 | Phyre_PClassDescriptor_Dtor_PInputSourceMotionAngularVelocityY | 0x14 | true |
| 225 | 0x9e2020 | Phyre_PClassDescriptor_Dtor_PInputSourceMotionAngularVelocityY_thunk | 0xb | true |
| 226 | 0xb07ee0 | Phyre_PClassDescriptor_Dtor_PInputSourceMotionAngularVelocityZ | 0x14 | true |
| 227 | 0x9e2030 | Phyre_PClassDescriptor_Dtor_PInputSourceMotionAngularVelocityZ_thunk | 0xb | true |
| 228 | 0xb07f00 | Phyre_PClassDescriptor_Dtor_PInputSourceMotionLinearAccelerationX | 0x14 | true |
| 229 | 0x9e2040 | Phyre_PClassDescriptor_Dtor_PInputSourceMotionLinearAccelerationX_thunk | 0xb | true |
| 230 | 0xb07f20 | Phyre_PClassDescriptor_Dtor_PInputSourceMotionLinearAccelerationY | 0x14 | true |
| 231 | 0x9e2050 | Phyre_PClassDescriptor_Dtor_PInputSourceMotionLinearAccelerationY_thunk | 0xb | true |
| 232 | 0xb07f40 | Phyre_PClassDescriptor_Dtor_PInputSourceMotionLinearAccelerationZ | 0x14 | true |
| 233 | 0x9e2060 | Phyre_PClassDescriptor_Dtor_PInputSourceMotionLinearAccelerationZ_thunk | 0xb | true |
| 234 | 0xb07f60 | Phyre_PClassDescriptor_Dtor_PInputSourceMotionQuatW | 0x14 | true |
| 235 | 0x9e2070 | Phyre_PClassDescriptor_Dtor_PInputSourceMotionQuatW_thunk | 0xb | true |
| 236 | 0x9e1ee0 | Phyre_PClassDescriptor_Dtor_PInputSourceMotionQuatX | 0xb | true |
| 237 | 0x9e2080 | Phyre_PClassDescriptor_Dtor_PInputSourceMotionQuatX_thunk | 0xb | true |
| 238 | 0xb07fa0 | Phyre_PClassDescriptor_Dtor_PInputSourceMotionQuatY | 0x14 | true |
| 239 | 0x9e2090 | Phyre_PClassDescriptor_Dtor_PInputSourceMotionQuatY_thunk | 0xb | true |
| 240 | 0xb07fc0 | Phyre_PClassDescriptor_Dtor_PInputSourceMotionQuatZ | 0x14 | true |
| 241 | 0x9e20a0 | Phyre_PClassDescriptor_Dtor_PInputSourceMotionQuatZ_thunk | 0xb | true |
| 242 | 0xb07fe0 | Phyre_PClassDescriptor_Dtor_PInputSourceMouseButton | 0x14 | true |
| 243 | 0x9e20b0 | Phyre_PClassDescriptor_Dtor_PInputSourceMouseButton_thunk | 0xb | true |
| 244 | 0xb08000 | Phyre_PClassDescriptor_Dtor_PInputSourceMouseDeltaX | 0x14 | true |
| 245 | 0x9e20c0 | Phyre_PClassDescriptor_Dtor_PInputSourceMouseDeltaX_thunk | 0xb | true |
| 246 | 0xb08020 | Phyre_PClassDescriptor_Dtor_PInputSourceMouseDeltaY | 0x14 | true |
| 247 | 0x9e20d0 | Phyre_PClassDescriptor_Dtor_PInputSourceMouseDeltaY_thunk | 0xb | true |
| 248 | 0xb08040 | Phyre_PClassDescriptor_Dtor_PInputSourceTouch | 0x14 | true |
| 249 | 0xb08060 | Phyre_PClassDescriptor_Dtor_PInputSourceTouchBase | 0x14 | true |
| 250 | 0x9e1f40 | Phyre_PClassDescriptor_Dtor_PInputSourceTouchDragX | 0xb | true |
| 251 | 0x9e20e0 | Phyre_PClassDescriptor_Dtor_PInputSourceTouchDragX_thunk | 0xb | true |
| 252 | 0x9e1f50 | Phyre_PClassDescriptor_Dtor_PInputSourceTouchDragY | 0xb | true |
| 253 | 0x9e20f0 | Phyre_PClassDescriptor_Dtor_PInputSourceTouchDragY_thunk | 0xb | true |
| 254 | 0x9e1f60 | Phyre_PClassDescriptor_Dtor_PInputSourceTouchPinch | 0xb | true |
| 255 | 0x9e2100 | Phyre_PClassDescriptor_Dtor_PInputSourceTouchPinch_thunk | 0xb | true |
| 256 | 0xb080a0 | Phyre_PClassDescriptor_Dtor_PInputSourceTouchRotate | 0x14 | true |
| 257 | 0x9e2110 | Phyre_PClassDescriptor_Dtor_PInputSourceTouchRotate_thunk | 0xb | true |
| 258 | 0x9e1f80 | Phyre_PClassDescriptor_Dtor_PInputSourceTouchTwoFingerDragX | 0xb | true |
| 259 | 0x9e2120 | Phyre_PClassDescriptor_Dtor_PInputSourceTouchTwoFingerDragX_thunk | 0xb | true |
| 260 | 0x9e1f90 | Phyre_PClassDescriptor_Dtor_PInputSourceTouchTwoFingerDragY | 0xb | true |
| 261 | 0x9e2130 | Phyre_PClassDescriptor_Dtor_PInputSourceTouchTwoFingerDragY_thunk | 0xb | true |
| 262 | 0xb080e0 | Phyre_PClassDescriptor_Dtor_PInputTypeSemanticBool | 0x14 | true |
| 263 | 0xb080c0 | Phyre_PClassDescriptor_Dtor_PInputTypeSemanticInt | 0x14 | true |
| 264 | 0xb04bd0 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsBox | 0x14 | true |
| 265 | 0xb04bf0 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsBoxBase | 0x14 | true |
| 266 | 0xb04c10 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsBoxBullet | 0x14 | true |
| 267 | 0xb04c30 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsCallbackData | 0x14 | true |
| 268 | 0xb04c50 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsCapsule | 0x14 | true |
| 269 | 0xb04c70 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsCapsuleBase | 0x14 | true |
| 270 | 0xb04c90 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsCapsuleBullet | 0x14 | true |
| 271 | 0xb04cb0 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsCharacterCamera | 0x14 | true |
| 272 | 0xb04cd0 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsCharacterController | 0x14 | true |
| 273 | 0xb04cf0 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsCharacterControllerBase | 0x14 | true |
| 274 | 0xb04d10 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsCharacterControllerBullet | 0x14 | true |
| 275 | 0xb04d30 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsCylinder | 0x14 | true |
| 276 | 0xb04d50 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsCylinderBase | 0x14 | true |
| 277 | 0xb04d70 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsCylinderBullet | 0x14 | true |
| 278 | 0xb04d90 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsInterface | 0x14 | true |
| 279 | 0xb04db0 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsInterfaceBase | 0x14 | true |
| 280 | 0xb04dd0 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsInterfaceBullet | 0x14 | true |
| 281 | 0xb04df0 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsMaterial | 0x14 | true |
| 282 | 0xb04e10 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsMesh | 0x14 | true |
| 283 | 0xb04e30 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsMeshBase | 0x14 | true |
| 284 | 0xb04e50 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsMeshBullet | 0x14 | true |
| 285 | 0xb04e70 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsModel | 0x14 | true |
| 286 | 0xb04e90 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsPlane | 0x14 | true |
| 287 | 0xb04eb0 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsPlaneBase | 0x14 | true |
| 288 | 0xb04ed0 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsPlaneBullet | 0x14 | true |
| 289 | 0xb04ef0 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsRigidBody | 0x14 | true |
| 290 | 0xb04f10 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsRigidBodyBase | 0x14 | true |
| 291 | 0xb04f30 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsRigidBodyBullet | 0x14 | true |
| 292 | 0xb04f50 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsShape | 0x14 | true |
| 293 | 0xb04f70 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsShapeBase | 0x14 | true |
| 294 | 0xb04f90 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsShapeBullet | 0x14 | true |
| 295 | 0xb04fb0 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsSphere | 0x14 | true |
| 296 | 0xb04fd0 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsSphereBase | 0x14 | true |
| 297 | 0xb04ff0 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsSphereBullet | 0x14 | true |
| 298 | 0xb05010 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsTaperedCapsule | 0x14 | true |
| 299 | 0xb05030 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsTaperedCylinder | 0x14 | true |
| 300 | 0xb05050 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsWorld | 0x14 | true |
| 301 | 0xb05070 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsWorldBase | 0x14 | true |
| 302 | 0xb05090 | Phyre_PClassDescriptor_Dtor_PPhysics_PPhysicsWorldBullet | 0x14 | true |
| 303 | 0xb050b0 | Phyre_PClassDescriptor_Dtor_PPhysics_PRaycastResult | 0x14 | true |
| 304 | 0xb05fa0 | Phyre_PClassDescriptor_Dtor_PScripting_PAsyncProcessHeader | 0x14 | true |
| 305 | 0xb06000 | Phyre_PClassDescriptor_Dtor_PScripting_PClassCallableMethodScript | 0x14 | true |
| 306 | 0xb04940 | Phyre_PClassDescriptor_Dtor_PScripting_PScheduler | 0x14 | true |
| 307 | 0xb04aa0 | Phyre_PClassDescriptor_Dtor_PScripting_PScript | 0x14 | true |
| 308 | 0xb04a60 | Phyre_PClassDescriptor_Dtor_PScripting_PScriptCallbackHandler | 0x14 | true |
| 309 | 0xb05430 | Phyre_PClassDescriptor_Dtor_PSharray_PPhysicsShapePtr | 0x14 | true |
| 310 | 0xb06a70 | Phyre_PClassDescriptor_Dtor_RadialLineDynamicMesh | 0x14 | true |
| 311 | 0xb06a20 | Phyre_PClassDescriptor_Dtor_RadialLineDynamicMeshInstance | 0x14 | true |
| 312 | 0xb06b60 | Phyre_PClassDescriptor_Dtor_ShadowDynamicMesh | 0x14 | true |
| 313 | 0xb07ab0 | Phyre_PClassDescriptor_Dtor_ShadowDynamicMeshInstance | 0x14 | true |
| 314 | 0x5f8800 | Phyre_PClassDescriptor_DtorForward00 | 0x28 | true |
| 315 | 0x5f8830 | Phyre_PClassDescriptor_DtorForward01 | 0x28 | true |
| 316 | 0x5f8860 | Phyre_PClassDescriptor_DtorForward02 | 0x28 | true |
| 317 | 0x5f88a0 | Phyre_PClassDescriptor_DtorForward03 | 0x28 | true |
| 318 | 0x5f88d0 | Phyre_PClassDescriptor_DtorForward04 | 0x28 | true |
| 319 | 0x5f8900 | Phyre_PClassDescriptor_DtorForward05 | 0x28 | true |
| 320 | 0x5f8a90 | Phyre_PClassDescriptor_DtorForward06 | 0x28 | true |
| 321 | 0x5f8ac0 | Phyre_PClassDescriptor_DtorForward07 | 0x28 | true |
| 322 | 0x5f8af0 | Phyre_PClassDescriptor_DtorForward08 | 0x28 | true |
| 323 | 0x5f8be0 | Phyre_PClassDescriptor_DtorForward09 | 0x28 | true |
| 324 | 0x5f8c10 | Phyre_PClassDescriptor_DtorForward10 | 0x28 | true |
| 325 | 0x5f8c40 | Phyre_PClassDescriptor_DtorForward11 | 0x28 | true |
| 326 | 0x5f8c90 | Phyre_PClassDescriptor_DtorForward12 | 0x28 | true |
| 327 | 0x5f8cc0 | Phyre_PClassDescriptor_DtorForward13 | 0x28 | true |
| 328 | 0x5f8cf0 | Phyre_PClassDescriptor_DtorForward14 | 0x28 | true |
| 329 | 0x5f8e00 | Phyre_PClassDescriptor_DtorForward15 | 0x28 | true |
| 330 | 0x5f8e30 | Phyre_PClassDescriptor_DtorForward16 | 0x28 | true |
| 331 | 0x5f8e60 | Phyre_PClassDescriptor_DtorForward17 | 0x28 | true |
| 332 | 0x5f8e90 | Phyre_PClassDescriptor_DtorForward18 | 0x28 | true |
| 333 | 0x5f8ec0 | Phyre_PClassDescriptor_DtorForward19 | 0x28 | true |
| 334 | 0x5f8ef0 | Phyre_PClassDescriptor_DtorForward20 | 0x28 | true |
| 335 | 0x5f8f20 | Phyre_PClassDescriptor_DtorForward21 | 0x28 | true |
| 336 | 0x5f8f50 | Phyre_PClassDescriptor_DtorForward22 | 0x28 | true |
| 337 | 0x5f8930 | Phyre_PClassDescriptor_DtorV0Forward00 | 0x26 | true |
| 338 | 0x5f89f0 | Phyre_PClassDescriptor_DtorV0Forward01 | 0x26 | true |
| 339 | 0x43b7f0 | Phyre_PClassDescriptor_DtorV4 | 0x27 | true |
| 340 | 0x43b820 | Phyre_PClassDescriptor_DtorV5 | 0x27 | true |
| 341 | 0x43b930 | Phyre_PClassDescriptor_DtorV6 | 0x27 | true |
| 342 | 0x565820 | Phyre_PClassDescriptor_dwordCB1D88_Get | 0x6 | true |
| 343 | 0x565910 | Phyre_PClassDescriptor_dwordCB1D88_GetTotalSize | 0xa | true |
| 344 | 0x565830 | Phyre_PClassDescriptor_dwordCB1E20_Get | 0x6 | true |
| 345 | 0x565920 | Phyre_PClassDescriptor_dwordCB1E20_GetTotalSize | 0xa | true |
| 346 | 0x550970 | Phyre_PClassDescriptor_Enable | 0x28 | true |
| 347 | 0x5509a0 | Phyre_PClassDescriptor_EnableNotifications | 0x2e | true |
| 348 | 0x43cad0 | Phyre_PClassDescriptor_EvalCondition | 0x57 | true |
| 349 | 0x43d840 | Phyre_PClassDescriptor_EvalConditionEx | 0x5c | true |
| 350 | 0x43b6c0 | Phyre_PClassDescriptor_Field0_getter | 0x3 | true |
| 351 | 0x43b6d0 | Phyre_PClassDescriptor_Field0_getter_0 | 0x3 | true |
| 352 | 0x43b6e0 | Phyre_PClassDescriptor_Field0_getter_1 | 0x3 | true |
| 353 | 0x43b710 | Phyre_PClassDescriptor_Field4_getter | 0x4 | true |
| 354 | 0x43b720 | Phyre_PClassDescriptor_Field4_getter_0 | 0x4 | true |
| 355 | 0x43cd70 | Phyre_PClassDescriptor_Field84_getter | 0x7 | true |
| 356 | 0x43cdc0 | Phyre_PClassDescriptor_Field88_getter | 0x7 | true |
| 357 | 0x43c230 | Phyre_PClassDescriptor_FinalizeRegistration | 0x18 | true |
| 358 | 0x435ad0 | Phyre_PClassDescriptor_FindByName | 0x79 | true |
| 359 | 0x435c80 | Phyre_PClassDescriptor_FindByNameHierarchy_MemberList | 0x83 | true |
| 360 | 0x435da0 | Phyre_PClassDescriptor_FindByNamePropertyList | 0x87 | true |
| 361 | 0x435e30 | Phyre_PClassDescriptor_FindByNamePropertyList2 | 0x83 | true |
| 362 | 0x435d10 | Phyre_PClassDescriptor_FindByNameSelfList | 0x83 | true |
| 363 | 0x445ad0 | Phyre_PClassDescriptor_FreeIfNotFlagged | 0x1e | true |
| 364 | 0x500ad0 | Phyre_PClassDescriptor_get_field_0x0C | 0x4 | true |
| 365 | 0x500950 | Phyre_PClassDescriptor_get_field_0x10 | 0x4 | true |
| 366 | 0x500930 | Phyre_PClassDescriptor_get_field_0x20 | 0x4 | true |
| 367 | 0x500ac0 | Phyre_PClassDescriptor_get_field_0x70 | 0x4 | true |
| 368 | 0x52e960 | Phyre_PClassDescriptor_GetClassName_PAnimationAdditiveBlenderController | 0x6 | true |
| 369 | 0x52f620 | Phyre_PClassDescriptor_GetClassName_PAnimationAdditiveBlenderController_A | 0x6 | true |
| 370 | 0x52c630 | Phyre_PClassDescriptor_GetClassName_PAnimationBlenderController | 0x6 | true |
| 371 | 0x532fe0 | Phyre_PClassDescriptor_GetClassName_PAnimationDataSourceListEntry | 0x6 | true |
| 372 | 0x532ff0 | Phyre_PClassDescriptor_GetClassName_PAnimationNetworkInstance | 0x6 | true |
| 373 | 0x533000 | Phyre_PClassDescriptor_GetClassName_PAnimationNetworkInstanceTarget | 0x6 | true |
| 374 | 0x5297c0 | Phyre_PClassDescriptor_GetClassName_PAnimationSlotFilter | 0x6 | true |
| 375 | 0x5297d0 | Phyre_PClassDescriptor_GetClassName_PAnimationSlotFilterDeferredLoad | 0x6 | true |
| 376 | 0x52ffc0 | Phyre_PClassDescriptor_GetClassName_PAnimationSpuTargetBlenderController | 0x6 | true |
| 377 | 0x531340 | Phyre_PClassDescriptor_GetClassName_PAnimationTargetBlenderController | 0x6 | true |
| 378 | 0x52d440 | Phyre_PClassDescriptor_GetClassName_PAnimationWeightedBlenderController | 0x6 | true |
| 379 | 0x52e150 | Phyre_PClassDescriptor_GetClassName_PAnimationWeightedBlenderController_A | 0x6 | true |
| 380 | 0x51cfa0 | Phyre_PClassDescriptor_GetData_PAnimationBlenderController | 0x6 | true |
| 381 | 0x52a390 | Phyre_PClassDescriptor_GetDataFromObject | 0x2b | true |
| 382 | 0x52a3c0 | Phyre_PClassDescriptor_GetDataFromObject_B | 0x2b | true |
| 383 | 0x52a3f0 | Phyre_PClassDescriptor_GetDataFromObject_C | 0x2b | true |
| 384 | 0x52a420 | Phyre_PClassDescriptor_GetDataFromObject_D | 0x2b | true |
| 385 | 0x43ce70 | Phyre_PClassDescriptor_GetDataMemberSize | 0x2c | true |
| 386 | 0x52cd80 | Phyre_PClassDescriptor_GetDataPtr | 0x4 | true |
| 387 | 0x501570 | Phyre_PClassDescriptor_GetDataPtr_AttachPoint | 0x6 | true |
| 388 | 0x5015a0 | Phyre_PClassDescriptor_GetDataPtr_AttachPoint_A | 0x6 | true |
| 389 | 0x500eb0 | Phyre_PClassDescriptor_GetDataPtr_LodDataBuf | 0x6 | true |
| 390 | 0x500ee0 | Phyre_PClassDescriptor_GetDataPtr_LodDataBuf_A | 0x6 | true |
| 391 | 0x500f00 | Phyre_PClassDescriptor_GetDataPtr_LodDataBuf_B | 0x6 | true |
| 392 | 0x51cf80 | Phyre_PClassDescriptor_GetDataPtr_PAnimationBlenderController | 0x6 | true |
| 393 | 0x510d90 | Phyre_PClassDescriptor_GetDataPtr_PAnimationClipBinding | 0x6 | true |
| 394 | 0x510dc0 | Phyre_PClassDescriptor_GetDataPtr_PAnimationClipBinding_A | 0x6 | true |
| 395 | 0x510e80 | Phyre_PClassDescriptor_GetDataPtr_PAnimationClipBindingDataBlockCache | 0x6 | true |
| 396 | 0x519370 | Phyre_PClassDescriptor_GetDataPtr_PAnimationConstantChannel | 0x5 | true |
| 397 | 0x520340 | Phyre_PClassDescriptor_GetDataPtr_PAnimationScriptController | 0x6 | true |
| 398 | 0x5201b0 | Phyre_PClassDescriptor_GetDataPtr_PAnimationSlotFilter | 0x6 | true |
| 399 | 0x51baa0 | Phyre_PClassDescriptor_GetDataPtr_PArrayAnimationChannelTarget | 0x6 | true |
| 400 | 0x5124c0 | Phyre_PClassDescriptor_GetDataPtr_PArrayAnimationClipPtr | 0x6 | true |
| 401 | 0x5124e0 | Phyre_PClassDescriptor_GetDataPtr_PArrayAnimationClipPtr_A | 0x6 | true |
| 402 | 0x51bc40 | Phyre_PClassDescriptor_GetDataPtr_PArrayAnimationSlotIndex | 0x6 | true |
| 403 | 0x51e9f0 | Phyre_PClassDescriptor_GetDataPtr_PArrayAnimationSlotIndex_E | 0x6 | true |
| 404 | 0x51b7b0 | Phyre_PClassDescriptor_GetDataPtr_PArrayAnimationSlotList | 0x6 | true |
| 405 | 0x51e640 | Phyre_PClassDescriptor_GetDataPtr_PArrayAnimationSlotList_D | 0x6 | true |
| 406 | 0x51e950 | Phyre_PClassDescriptor_GetDataPtr_PArrayAnimationSlotList_E | 0x6 | true |
| 407 | 0x51bc60 | Phyre_PClassDescriptor_GetDataPtr_PArrayAnimationSlotListArray | 0x6 | true |
| 408 | 0x5185e0 | Phyre_PClassDescriptor_GetDataPtr_PArrayChannelTarget | 0x6 | true |
| 409 | 0x518600 | Phyre_PClassDescriptor_GetDataPtr_PArrayChannelTarget_B | 0x6 | true |
| 410 | 0x512610 | Phyre_PClassDescriptor_GetDataPtr_PArrayKeyframe | 0x6 | true |
| 411 | 0x512630 | Phyre_PClassDescriptor_GetDataPtr_PArrayKeyframe_A | 0x6 | true |
| 412 | 0x517d70 | Phyre_PClassDescriptor_GetDataPtr_PSharrayAnimationClip | 0x6 | true |
| 413 | 0x518430 | Phyre_PClassDescriptor_GetDataPtr_PSharrayAnimationClip_B | 0x6 | true |
| 414 | 0x520140 | Phyre_PClassDescriptor_GetDataPtr_PTimeIntervalController | 0x6 | true |
| 415 | 0x520160 | Phyre_PClassDescriptor_GetDataPtr_PTimeScaleOffsetController | 0x6 | true |
| 416 | 0x52a450 | Phyre_PClassDescriptor_GetDataPtrForIndex_A | 0x1a | true |
| 417 | 0x52a470 | Phyre_PClassDescriptor_GetDataPtrForIndex_B | 0x1a | true |
| 418 | 0x52a490 | Phyre_PClassDescriptor_GetDataPtrForIndex_C | 0x1a | true |
| 419 | 0x52a4b0 | Phyre_PClassDescriptor_GetDataPtrForIndex_D | 0x1a | true |
| 420 | 0x52cca0 | Phyre_PClassDescriptor_GetDataPtrForIndex_E | 0x1a | true |
| 421 | 0x52ccc0 | Phyre_PClassDescriptor_GetDataPtrForIndex_F | 0x1a | true |
| 422 | 0x52a510 | Phyre_PClassDescriptor_GetDataPtrForIndex_Masked | 0x1e | true |
| 423 | 0x52a530 | Phyre_PClassDescriptor_GetDataPtrForIndex_Masked_A | 0x1e | true |
| 424 | 0x501560 | Phyre_PClassDescriptor_GetDescriptorPtr_AttachPoint | 0x6 | true |
| 425 | 0x501580 | Phyre_PClassDescriptor_GetDescriptorPtr_AttachPoint_A | 0x6 | true |
| 426 | 0x501590 | Phyre_PClassDescriptor_GetDescriptorPtr_AttachPoint_B | 0x6 | true |
| 427 | 0x500ea0 | Phyre_PClassDescriptor_GetDescriptorPtr_LodData | 0x6 | true |
| 428 | 0x500ec0 | Phyre_PClassDescriptor_GetDescriptorPtr_LodData_A | 0x6 | true |
| 429 | 0x500ed0 | Phyre_PClassDescriptor_GetDescriptorPtr_LodData_B | 0x6 | true |
| 430 | 0x500ef0 | Phyre_PClassDescriptor_GetDescriptorPtr_LodData_C | 0x6 | true |
| 431 | 0x51cf90 | Phyre_PClassDescriptor_GetDescriptorPtr_PAnimationBlenderController | 0x6 | true |
| 432 | 0x512780 | Phyre_PClassDescriptor_GetDescriptorPtr_PAnimationClip | 0x6 | true |
| 433 | 0x510d70 | Phyre_PClassDescriptor_GetDescriptorPtr_PAnimationClipBinding | 0x6 | true |
| 434 | 0x510da0 | Phyre_PClassDescriptor_GetDescriptorPtr_PAnimationClipBinding_A | 0x6 | true |
| 435 | 0x510dd0 | Phyre_PClassDescriptor_GetDescriptorPtr_PAnimationClipBinding_B | 0x6 | true |
| 436 | 0x510e90 | Phyre_PClassDescriptor_GetDescriptorPtr_PAnimationClipBindingDataBlockCache | 0x6 | true |
| 437 | 0x519380 | Phyre_PClassDescriptor_GetDescriptorPtr_PAnimationConstantChannel | 0x5 | true |
| 438 | 0x5201c0 | Phyre_PClassDescriptor_GetDescriptorPtr_PAnimationSlotFilter | 0x6 | true |
| 439 | 0x5124d0 | Phyre_PClassDescriptor_GetDescriptorPtr_PArrayAnimationClipPtr | 0x6 | true |
| 440 | 0x5124f0 | Phyre_PClassDescriptor_GetDescriptorPtr_PArrayAnimationClipPtr_A | 0x6 | true |
| 441 | 0x51b7c0 | Phyre_PClassDescriptor_GetDescriptorPtr_PArrayAnimationSlotIndex | 0x6 | true |
| 442 | 0x51e650 | Phyre_PClassDescriptor_GetDescriptorPtr_PArrayAnimationSlotIndex_D | 0x6 | true |
| 443 | 0x51e9e0 | Phyre_PClassDescriptor_GetDescriptorPtr_PArrayAnimationSlotIndex_E | 0x6 | true |
| 444 | 0x51ea00 | Phyre_PClassDescriptor_GetDescriptorPtr_PArrayAnimationSlotTarget | 0x6 | true |
| 445 | 0x5185f0 | Phyre_PClassDescriptor_GetDescriptorPtr_PArrayChannelTarget | 0x6 | true |
| 446 | 0x518610 | Phyre_PClassDescriptor_GetDescriptorPtr_PArrayChannelTarget_B | 0x6 | true |
| 447 | 0x512620 | Phyre_PClassDescriptor_GetDescriptorPtr_PArrayKeyframe | 0x6 | true |
| 448 | 0x512740 | Phyre_PClassDescriptor_GetDescriptorPtr_PArrayUInt | 0x6 | true |
| 449 | 0x520150 | Phyre_PClassDescriptor_GetDescriptorPtr_PTimeIntervalController | 0x6 | true |
| 450 | 0x520170 | Phyre_PClassDescriptor_GetDescriptorPtr_PTimeScaleOffsetController | 0x6 | true |
| 451 | 0x43cbd0 | Phyre_PClassDescriptor_GetDestroyList | 0x33 | true |
| 452 | 0x4bda80 | Phyre_PClassDescriptor_GetDword_4BDA80 | 0x3 | true |
| 453 | 0x4ae190 | Phyre_PClassDescriptor_GetDwordC9C288 | 0x6 | true |
| 454 | 0x4ae1a0 | Phyre_PClassDescriptor_GetDwordC9C3B8 | 0x6 | true |
| 455 | 0x4ae1b0 | Phyre_PClassDescriptor_GetDwordC9C450 | 0x6 | true |
| 456 | 0x4ae170 | Phyre_PClassDescriptor_GetDwordC9C910 | 0x6 | true |
| 457 | 0x4ae180 | Phyre_PClassDescriptor_GetDwordC9C9A8 | 0x6 | true |
| 458 | 0x4ae160 | Phyre_PClassDescriptor_GetDwordC9CA40 | 0x6 | true |
| 459 | 0x52d190 | Phyre_PClassDescriptor_GetElementsOrDefault21 | 0x22 | true |
| 460 | 0x443be0 | Phyre_PClassDescriptor_GetField | 0x3a | true |
| 461 | 0x531720 | Phyre_PClassDescriptor_GetField0x0C_IfArgZero | 0x16 | true |
| 462 | 0x4b0a20 | Phyre_PClassDescriptor_GetField4_4B0A20 | 0x4 | true |
| 463 | 0x4b0a30 | Phyre_PClassDescriptor_GetField4_4B0A30 | 0x4 | true |
| 464 | 0x4b9b80 | Phyre_PClassDescriptor_GetField4_4B9B80 | 0x4 | true |
| 465 | 0x4b9b90 | Phyre_PClassDescriptor_GetField4_4B9B90 | 0x4 | true |
| 466 | 0x4b9ba0 | Phyre_PClassDescriptor_GetField4_4B9BA0 | 0x4 | true |
| 467 | 0x4b9bb0 | Phyre_PClassDescriptor_GetField4_4B9BB0 | 0x4 | true |
| 468 | 0x4b9bc0 | Phyre_PClassDescriptor_GetField4_4B9BC0 | 0x4 | true |
| 469 | 0x4b9bd0 | Phyre_PClassDescriptor_GetField4_4B9BD0 | 0x4 | true |
| 470 | 0x4bd8e0 | Phyre_PClassDescriptor_GetField4_4BD8E0 | 0x4 | true |
| 471 | 0x4bd8f0 | Phyre_PClassDescriptor_GetField4_4BD8F0 | 0x4 | true |
| 472 | 0x444910 | Phyre_PClassDescriptor_GetField_2 | 0x3a | true |
| 473 | 0x445cd0 | Phyre_PClassDescriptor_GetField_3 | 0x3a | true |
| 474 | 0x444950 | Phyre_PClassDescriptor_GetField_Direct | 0x38 | true |
| 475 | 0x511500 | Phyre_PClassDescriptor_GetField_Index9 | 0x4 | true |
| 476 | 0x446b20 | Phyre_PClassDescriptor_GetField_Offset4 | 0x3d | true |
| 477 | 0x448f00 | Phyre_PClassDescriptor_GetField_PArrayU8 | 0xb4 | true |
| 478 | 0x449b40 | Phyre_PClassDescriptor_GetField_PArrayU8_Wrapper | 0x17 | true |
| 479 | 0x50c850 | Phyre_PClassDescriptor_GetFieldAt8 | 0x4 | true |
| 480 | 0x5208a0 | Phyre_PClassDescriptor_GetIndex_PAnimationBlenderWeight | 0x5 | true |
| 481 | 0x520900 | Phyre_PClassDescriptor_GetIndex_PAnimationBlenderWeight_B | 0x5 | true |
| 482 | 0x520910 | Phyre_PClassDescriptor_GetIndex_PAnimationBlenderWeight_C | 0x5 | true |
| 483 | 0x519350 | Phyre_PClassDescriptor_GetIndex_PAnimationConstantChannel | 0x5 | true |
| 484 | 0x52b100 | Phyre_PClassDescriptor_GetIndex_Ret16 | 0x6 | true |
| 485 | 0x52c4d0 | Phyre_PClassDescriptor_GetIndex_Ret16_A | 0x6 | true |
| 486 | 0x5297f0 | Phyre_PClassDescriptor_GetIndex_Ret2 | 0x6 | true |
| 487 | 0x52aa80 | Phyre_PClassDescriptor_GetIndex_Ret23 | 0x8 | true |
| 488 | 0x52aa90 | Phyre_PClassDescriptor_GetIndex_Ret23_A | 0x8 | true |
| 489 | 0x52cf90 | Phyre_PClassDescriptor_GetIndex_Ret23_B | 0x8 | true |
| 490 | 0x532920 | Phyre_PClassDescriptor_GetIndex_Ret2_A | 0x6 | true |
| 491 | 0x501500 | Phyre_PClassDescriptor_GetIndex_Ret2_AttachPoint | 0x6 | true |
| 492 | 0x501510 | Phyre_PClassDescriptor_GetIndex_Ret2_AttachPoint_A | 0x6 | true |
| 493 | 0x500e80 | Phyre_PClassDescriptor_GetIndex_Ret2_LodData | 0x6 | true |
| 494 | 0x500e90 | Phyre_PClassDescriptor_GetIndex_Ret2_LodData_A | 0x6 | true |
| 495 | 0x500940 | Phyre_PClassDescriptor_GetIndex_RetNegOne | 0x6 | true |
| 496 | 0x43cc70 | Phyre_PClassDescriptor_GetMemberCount | 0x2c | true |
| 497 | 0x5ff550 | Phyre_PClassDescriptor_GetNumFields | 0x7 | true |
| 498 | 0x5c42c0 | Phyre_PClassDescriptor_GetNumFields_0x02 | 0x6 | true |
| 499 | 0x5c42d0 | Phyre_PClassDescriptor_GetNumFields_0x02_v2 | 0x6 | true |
| 500 | 0x5c42e0 | Phyre_PClassDescriptor_GetNumFields_0x02_v3 | 0x6 | true |
| 501 | 0x5c42f0 | Phyre_PClassDescriptor_GetNumFields_0x02_v4 | 0x6 | true |
| 502 | 0x5f0650 | Phyre_PClassDescriptor_GetNumFields_2 | 0x6 | true |
| 503 | 0x5f0660 | Phyre_PClassDescriptor_GetNumFields_2_v2 | 0x6 | true |
| 504 | 0x5f0670 | Phyre_PClassDescriptor_GetNumFields_2_v3 | 0x6 | true |
| 505 | 0x5f0680 | Phyre_PClassDescriptor_GetNumFields_2_v4 | 0x6 | true |
| 506 | 0x5f0690 | Phyre_PClassDescriptor_GetNumFields_2_v5 | 0x6 | true |
| 507 | 0x5f06a0 | Phyre_PClassDescriptor_GetNumFields_2_v6 | 0x6 | true |
| 508 | 0x5f06b0 | Phyre_PClassDescriptor_GetNumFields_2_v7 | 0x6 | true |
| 509 | 0x5f06c0 | Phyre_PClassDescriptor_GetNumFields_2_v8 | 0x6 | true |
| 510 | 0x5f06d0 | Phyre_PClassDescriptor_GetNumFields_2_v9 | 0x6 | true |
| 511 | 0x43a810 | Phyre_PClassDescriptor_GetOrInitSingleton | 0x6d | true |
| 512 | 0x4ae870 | Phyre_PClassDescriptor_GetPtr_4AE870 | 0x6 | true |
| 513 | 0x4ae880 | Phyre_PClassDescriptor_GetPtr_4AE880 | 0x6 | true |
| 514 | 0x4ae890 | Phyre_PClassDescriptor_GetPtr_4AE890 | 0x6 | true |
| 515 | 0x4ae8a0 | Phyre_PClassDescriptor_GetPtr_4AE8A0 | 0x6 | true |
| 516 | 0x4ae8b0 | Phyre_PClassDescriptor_GetPtr_4AE8B0 | 0x6 | true |
| 517 | 0x4b9be0 | Phyre_PClassDescriptor_GetPtr_4B9BE0 | 0x6 | true |
| 518 | 0x4b9bf0 | Phyre_PClassDescriptor_GetPtr_4B9BF0 | 0x6 | true |
| 519 | 0x4b9c00 | Phyre_PClassDescriptor_GetPtr_4B9C00 | 0x6 | true |
| 520 | 0x4bd0f0 | Phyre_PClassDescriptor_GetPtr_4BD0F0 | 0x6 | true |
| 521 | 0x4bd100 | Phyre_PClassDescriptor_GetPtr_4BD100 | 0x6 | true |
| 522 | 0x4bd110 | Phyre_PClassDescriptor_GetPtr_4BD110 | 0x6 | true |
| 523 | 0x4bd120 | Phyre_PClassDescriptor_GetPtr_4BD120 | 0x6 | true |
| 524 | 0x4bd2d0 | Phyre_PClassDescriptor_GetPtr_4BD2D0 | 0x6 | true |
| 525 | 0x4bd2e0 | Phyre_PClassDescriptor_GetPtr_4BD2E0 | 0x6 | true |
| 526 | 0x4bd910 | Phyre_PClassDescriptor_GetPtr_4BD910 | 0x6 | true |
| 527 | 0x4be1d0 | Phyre_PClassDescriptor_GetPtr_4BE1D0 | 0x6 | true |
| 528 | 0x4be1e0 | Phyre_PClassDescriptor_GetPtr_4BE1E0 | 0x6 | true |
| 529 | 0x4be330 | Phyre_PClassDescriptor_GetPtr_4BE330 | 0x6 | true |
| 530 | 0x4be360 | Phyre_PClassDescriptor_GetPtr_4BE360 | 0x6 | true |
| 531 | 0x4448c0 | Phyre_PClassDescriptor_GetRefCount | 0x17 | true |
| 532 | 0x9e8f90 | Phyre_PClassDescriptor_GetSingleton_1940AD0 | 0x6 | true |
| 533 | 0x9e9110 | Phyre_PClassDescriptor_GetSingleton_1940AD0_B | 0x6 | true |
| 534 | 0x9e9130 | Phyre_PClassDescriptor_GetSingleton_1940AD0_C | 0x6 | true |
| 535 | 0x9e8a10 | Phyre_PClassDescriptor_GetSingleton_1940AD0_D | 0x6 | true |
| 536 | 0x9dc3f0 | Phyre_PClassDescriptor_GetSingleton_1940AD0_v2 | 0x6 | true |
| 537 | 0x9e8a40 | Phyre_PClassDescriptor_GetSingleton_1940B68 | 0x6 | true |
| 538 | 0x9dc420 | Phyre_PClassDescriptor_GetSingleton_1940B68_v2 | 0x6 | true |
| 539 | 0x9e8a30 | Phyre_PClassDescriptor_GetSingleton_1940C00 | 0x6 | true |
| 540 | 0x9dc410 | Phyre_PClassDescriptor_GetSingleton_1940C00_B | 0x6 | true |
| 541 | 0x9e8a20 | Phyre_PClassDescriptor_GetSingleton_1940C98 | 0x6 | true |
| 542 | 0x9dc400 | Phyre_PClassDescriptor_GetSingleton_1940C98_B | 0x6 | true |
| 543 | 0x9e8af0 | Phyre_PClassDescriptor_GetSingleton_1940D30 | 0x6 | true |
| 544 | 0x9dc4d0 | Phyre_PClassDescriptor_GetSingleton_1940D30_v2 | 0x6 | true |
| 545 | 0x9e8b00 | Phyre_PClassDescriptor_GetSingleton_1940DC8 | 0x6 | true |
| 546 | 0x9dc4e0 | Phyre_PClassDescriptor_GetSingleton_1940DC8_v2 | 0x6 | true |
| 547 | 0x9e8990 | Phyre_PClassDescriptor_GetSingleton_1940E60 | 0x6 | true |
| 548 | 0x9e8b10 | Phyre_PClassDescriptor_GetSingleton_1940E60_B | 0x6 | true |
| 549 | 0x9dc4f0 | Phyre_PClassDescriptor_GetSingleton_1940E60_v2 | 0x6 | true |
| 550 | 0x9e89d0 | Phyre_PClassDescriptor_GetSingleton_1940EF8 | 0x6 | true |
| 551 | 0x9e8b50 | Phyre_PClassDescriptor_GetSingleton_1940EF8_B | 0x6 | true |
| 552 | 0x9dc530 | Phyre_PClassDescriptor_GetSingleton_1940EF8_v2 | 0x6 | true |
| 553 | 0x9e89c0 | Phyre_PClassDescriptor_GetSingleton_1940F90 | 0x6 | true |
| 554 | 0x9e8b40 | Phyre_PClassDescriptor_GetSingleton_1940F90_B | 0x6 | true |
| 555 | 0x9dc520 | Phyre_PClassDescriptor_GetSingleton_1940F90_v2 | 0x6 | true |
| 556 | 0x9e89a0 | Phyre_PClassDescriptor_GetSingleton_1941028 | 0x6 | true |
| 557 | 0x9e8b20 | Phyre_PClassDescriptor_GetSingleton_1941028_B | 0x6 | true |
| 558 | 0x9dc500 | Phyre_PClassDescriptor_GetSingleton_1941028_v2 | 0x6 | true |
| 559 | 0x9e89b0 | Phyre_PClassDescriptor_GetSingleton_19410C0 | 0x6 | true |
| 560 | 0x9e8b30 | Phyre_PClassDescriptor_GetSingleton_19410C0_B | 0x6 | true |
| 561 | 0x9dc510 | Phyre_PClassDescriptor_GetSingleton_19410C0_v2 | 0x6 | true |
| 562 | 0x9e89e0 | Phyre_PClassDescriptor_GetSingleton_1941158 | 0x6 | true |
| 563 | 0x9e8b60 | Phyre_PClassDescriptor_GetSingleton_1941158_B | 0x6 | true |
| 564 | 0x9dc540 | Phyre_PClassDescriptor_GetSingleton_1941158_v2 | 0x6 | true |
| 565 | 0x9e89f0 | Phyre_PClassDescriptor_GetSingleton_19411F0 | 0x6 | true |
| 566 | 0x9e8b70 | Phyre_PClassDescriptor_GetSingleton_19411F0_B | 0x6 | true |
| 567 | 0x9dc550 | Phyre_PClassDescriptor_GetSingleton_19411F0_v2 | 0x6 | true |
| 568 | 0x9e8ac0 | Phyre_PClassDescriptor_GetSingleton_1941288 | 0x6 | true |
| 569 | 0x9dc4a0 | Phyre_PClassDescriptor_GetSingleton_1941288_v2 | 0x6 | true |
| 570 | 0x9e8ad0 | Phyre_PClassDescriptor_GetSingleton_1941320 | 0x6 | true |
| 571 | 0x9dc4b0 | Phyre_PClassDescriptor_GetSingleton_1941320_v2 | 0x6 | true |
| 572 | 0x9e8ae0 | Phyre_PClassDescriptor_GetSingleton_19413B8 | 0x6 | true |
| 573 | 0x9dc4c0 | Phyre_PClassDescriptor_GetSingleton_19413B8_v2 | 0x6 | true |
| 574 | 0x9e8ab0 | Phyre_PClassDescriptor_GetSingleton_1941450 | 0x6 | true |
| 575 | 0x9e8a50 | Phyre_PClassDescriptor_GetSingleton_19414E8 | 0x6 | true |
| 576 | 0x9dc430 | Phyre_PClassDescriptor_GetSingleton_19414E8_v2 | 0x6 | true |
| 577 | 0x9e8a60 | Phyre_PClassDescriptor_GetSingleton_1941580 | 0x6 | true |
| 578 | 0x9dc440 | Phyre_PClassDescriptor_GetSingleton_1941580_v2 | 0x6 | true |
| 579 | 0x9e8a70 | Phyre_PClassDescriptor_GetSingleton_1941618 | 0x6 | true |
| 580 | 0x9dc450 | Phyre_PClassDescriptor_GetSingleton_1941618_v2 | 0x6 | true |
| 581 | 0x9e8a80 | Phyre_PClassDescriptor_GetSingleton_19416B0 | 0x6 | true |
| 582 | 0x9dc460 | Phyre_PClassDescriptor_GetSingleton_19416B0_v2 | 0x6 | true |
| 583 | 0x9e8a90 | Phyre_PClassDescriptor_GetSingleton_1941748 | 0x6 | true |
| 584 | 0x9dc470 | Phyre_PClassDescriptor_GetSingleton_1941748_v2 | 0x6 | true |
| 585 | 0x9e8aa0 | Phyre_PClassDescriptor_GetSingleton_19417E0 | 0x6 | true |
| 586 | 0x9dc480 | Phyre_PClassDescriptor_GetSingleton_19417E0_v2 | 0x6 | true |
| 587 | 0x9e8f40 | Phyre_PClassDescriptor_GetSingleton_1941878 | 0x6 | true |
| 588 | 0x9e9100 | Phyre_PClassDescriptor_GetSingleton_1941878_B | 0x6 | true |
| 589 | 0x9e9120 | Phyre_PClassDescriptor_GetSingleton_1941878_C | 0x6 | true |
| 590 | 0x9e8a00 | Phyre_PClassDescriptor_GetSingleton_1941878_D | 0x6 | true |
| 591 | 0x9dc3d0 | Phyre_PClassDescriptor_GetSingleton_1941878_v2 | 0x6 | true |
| 592 | 0x9dd620 | Phyre_PClassDescriptor_GetSingleton_1941878B_v2 | 0x6 | true |
| 593 | 0x9dc490 | Phyre_PClassDescriptor_GetSingleton_19418A8_v2 | 0x6 | true |
| 594 | 0x9dc3e0 | Phyre_PClassDescriptor_GetSingleton_1941910 | 0x6 | true |
| 595 | 0xa2aee0 | Phyre_PClassDescriptor_GetSize76Ptr | 0x6 | true |
| 596 | 0xa2b1f0 | Phyre_PClassDescriptor_GetSize76Ptr_B | 0x6 | true |
| 597 | 0xa2cf80 | Phyre_PClassDescriptor_GetSize76Ptr_C | 0x6 | true |
| 598 | 0xa2cf90 | Phyre_PClassDescriptor_GetSize76Ptr_D | 0x6 | true |
| 599 | 0xa2d180 | Phyre_PClassDescriptor_GetSize76Ptr_E | 0x6 | true |
| 600 | 0xa2d190 | Phyre_PClassDescriptor_GetSize76Ptr_F | 0x6 | true |
| 601 | 0x57f550 | Phyre_PClassDescriptor_GetSize_101 | 0x6 | true |
| 602 | 0x57f560 | Phyre_PClassDescriptor_GetSize_103 | 0x6 | true |
| 603 | 0xa311c0 | Phyre_PClassDescriptor_GetSize_17Bytes | 0x6 | true |
| 604 | 0x57f690 | Phyre_PClassDescriptor_GetSize_60 | 0xa | true |
| 605 | 0x57f6a0 | Phyre_PClassDescriptor_GetSize_94 | 0xa | true |
| 606 | 0x57f570 | Phyre_PClassDescriptor_GetSize_95 | 0x6 | true |
| 607 | 0x57f680 | Phyre_PClassDescriptor_GetSize_dword_CB3C00 | 0xa | true |
| 608 | 0x57f6f0 | Phyre_PClassDescriptor_GetSize_dword_CB3CF8 | 0xa | true |
| 609 | 0x57f6e0 | Phyre_PClassDescriptor_GetSize_dword_CB3D28 | 0xa | true |
| 610 | 0x57f670 | Phyre_PClassDescriptor_GetSize_dword_CB3D48 | 0xa | true |
| 611 | 0x57f6b0 | Phyre_PClassDescriptor_GetSize_dword_CB3D58 | 0xa | true |
| 612 | 0x57f6d0 | Phyre_PClassDescriptor_GetSize_dword_CB3D64 | 0xa | true |
| 613 | 0x57f6c0 | Phyre_PClassDescriptor_GetSize_dword_CB3D70 | 0xa | true |
| 614 | 0x57f660 | Phyre_PClassDescriptor_GetSize_dword_CB3DE0 | 0xa | true |
| 615 | 0x52ff20 | Phyre_PClassDescriptor_GetSizePtr_17 | 0x6 | true |
| 616 | 0x531330 | Phyre_PClassDescriptor_GetSizePtr_18 | 0x6 | true |
| 617 | 0x532b30 | Phyre_PClassDescriptor_GetSizePtr_18_A | 0x6 | true |
| 618 | 0x532b40 | Phyre_PClassDescriptor_GetSizePtr_18_B | 0x6 | true |
| 619 | 0x532d80 | Phyre_PClassDescriptor_GetSizePtr_18_C | 0x6 | true |
| 620 | 0x532f90 | Phyre_PClassDescriptor_GetSizePtr_18_D | 0x6 | true |
| 621 | 0x52d360 | Phyre_PClassDescriptor_GetSizePtr_29 | 0x6 | true |
| 622 | 0x52e130 | Phyre_PClassDescriptor_GetSizePtr_29_A | 0x6 | true |
| 623 | 0x52e140 | Phyre_PClassDescriptor_GetSizePtr_29_B | 0x6 | true |
| 624 | 0x52e880 | Phyre_PClassDescriptor_GetSizePtr_30 | 0x6 | true |
| 625 | 0x52f600 | Phyre_PClassDescriptor_GetSizePtr_30_A | 0x6 | true |
| 626 | 0x52f610 | Phyre_PClassDescriptor_GetSizePtr_30_B | 0x6 | true |
| 627 | 0x529720 | Phyre_PClassDescriptor_GetSizePtr_32 | 0x6 | true |
| 628 | 0x529740 | Phyre_PClassDescriptor_GetSizePtr_32_A | 0x6 | true |
| 629 | 0x529730 | Phyre_PClassDescriptor_GetSizePtr_33 | 0x6 | true |
| 630 | 0x529750 | Phyre_PClassDescriptor_GetSizePtr_33_A | 0x6 | true |
| 631 | 0x529a80 | Phyre_PClassDescriptor_GetSizePtr_33_B | 0x6 | true |
| 632 | 0x529aa0 | Phyre_PClassDescriptor_GetSizePtr_33_C | 0x6 | true |
| 633 | 0x52a380 | Phyre_PClassDescriptor_GetSizePtr_33_D | 0x6 | true |
| 634 | 0x52b190 | Phyre_PClassDescriptor_GetSizePtr_34 | 0x6 | true |
| 635 | 0x52c5e0 | Phyre_PClassDescriptor_GetSizePtr_34_A | 0x6 | true |
| 636 | 0x52c5f0 | Phyre_PClassDescriptor_GetSizePtr_34_B | 0x6 | true |
| 637 | 0x5323b0 | Phyre_PClassDescriptor_GetSizePtr_48 | 0x6 | true |
| 638 | 0x529950 | Phyre_PClassDescriptor_GetSizePtr_52 | 0x6 | true |
| 639 | 0x529960 | Phyre_PClassDescriptor_GetSizePtr_52_A | 0x6 | true |
| 640 | 0x529a70 | Phyre_PClassDescriptor_GetSizePtr_52_B | 0x6 | true |
| 641 | 0x52c790 | Phyre_PClassDescriptor_GetSizePtr_52_C | 0x6 | true |
| 642 | 0x52cc30 | Phyre_PClassDescriptor_GetSizePtr_52_D | 0x6 | true |
| 643 | 0x5323a0 | Phyre_PClassDescriptor_GetSizePtr_64 | 0x6 | true |
| 644 | 0x532d50 | Phyre_PClassDescriptor_GetSizePtr_64_A | 0x6 | true |
| 645 | 0x5014d0 | Phyre_PClassDescriptor_GetSizePtr_AttachPoint | 0x6 | true |
| 646 | 0x5014e0 | Phyre_PClassDescriptor_GetSizePtr_AttachPoint_A | 0x6 | true |
| 647 | 0x532d70 | Phyre_PClassDescriptor_GetSizePtr_CA9810 | 0x6 | true |
| 648 | 0x532d60 | Phyre_PClassDescriptor_GetSizePtr_CACDB0_A | 0x6 | true |
| 649 | 0x5323c0 | Phyre_PClassDescriptor_GetSizePtr_dword_CACDB0 | 0x6 | true |
| 650 | 0x500e40 | Phyre_PClassDescriptor_GetSizePtr_LodData | 0x6 | true |
| 651 | 0x510d80 | Phyre_PClassDescriptor_GetSizePtr_PAnimationClipBinding | 0x6 | true |
| 652 | 0x510db0 | Phyre_PClassDescriptor_GetSizePtr_PAnimationClipBinding_A | 0x6 | true |
| 653 | 0x519360 | Phyre_PClassDescriptor_GetSizePtr_PAnimationConstantChannel | 0x5 | true |
| 654 | 0x520330 | Phyre_PClassDescriptor_GetSizePtr_PAnimationScriptController | 0x6 | true |
| 655 | 0x51b8b0 | Phyre_PClassDescriptor_GetSizePtr_PArrayAnimationChannelSlotPtr | 0x6 | true |
| 656 | 0x5124b0 | Phyre_PClassDescriptor_GetSizePtr_PArrayAnimationClipPtr | 0x6 | true |
| 657 | 0x51bc30 | Phyre_PClassDescriptor_GetSizePtr_PArrayAnimationSlotIndex | 0x6 | true |
| 658 | 0x518440 | Phyre_PClassDescriptor_GetSizePtr_PArrayAnimationSlotList | 0x6 | true |
| 659 | 0x51b860 | Phyre_PClassDescriptor_GetSizePtr_PArrayAnimationSlotListArray | 0x6 | true |
| 660 | 0x512010 | Phyre_PClassDescriptor_GetSizePtr_PArrayChannelTarget | 0x6 | true |
| 661 | 0x512600 | Phyre_PClassDescriptor_GetSizePtr_PArrayKeyframe | 0x6 | true |
| 662 | 0x512020 | Phyre_PClassDescriptor_GetSizePtr_PArraySlotListIndex | 0x6 | true |
| 663 | 0x5fcf50 | Phyre_PClassDescriptor_GetSizeTable2 | 0x6 | true |
| 664 | 0x5c4090 | Phyre_PClassDescriptor_GetSizeTable_12 | 0x6 | true |
| 665 | 0x5c4110 | Phyre_PClassDescriptor_GetSizeTable_12_v2 | 0x6 | true |
| 666 | 0x5c4730 | Phyre_PClassDescriptor_GetSizeTable_12_v3 | 0x6 | true |
| 667 | 0x5c47a0 | Phyre_PClassDescriptor_GetSizeTable_12_v4 | 0x6 | true |
| 668 | 0x5c6150 | Phyre_PClassDescriptor_GetSizeTable_12_v5 | 0x6 | true |
| 669 | 0x5c40a0 | Phyre_PClassDescriptor_GetSizeTable_13 | 0x6 | true |
| 670 | 0x5f0880 | Phyre_PClassDescriptor_GetSizeTable_44 | 0x6 | true |
| 671 | 0x5f0840 | Phyre_PClassDescriptor_GetSizeTable_45 | 0x6 | true |
| 672 | 0x5c4520 | Phyre_PClassDescriptor_GetSizeTable_51 | 0x6 | true |
| 673 | 0x5c4560 | Phyre_PClassDescriptor_GetSizeTable_51_v2 | 0x6 | true |
| 674 | 0x5c4720 | Phyre_PClassDescriptor_GetSizeTable_51_v3 | 0x6 | true |
| 675 | 0x5c40d0 | Phyre_PClassDescriptor_GetSizeTable_53 | 0x6 | true |
| 676 | 0x5c4140 | Phyre_PClassDescriptor_GetSizeTable_53_v2 | 0x6 | true |
| 677 | 0x5c4760 | Phyre_PClassDescriptor_GetSizeTable_53_v3 | 0x6 | true |
| 678 | 0x5c4100 | Phyre_PClassDescriptor_GetSizeTable_54 | 0x6 | true |
| 679 | 0x5c4790 | Phyre_PClassDescriptor_GetSizeTable_55 | 0x6 | true |
| 680 | 0x5c47c0 | Phyre_PClassDescriptor_GetSizeTable_55_v2 | 0x6 | true |
| 681 | 0x5c6170 | Phyre_PClassDescriptor_GetSizeTable_55_v3 | 0x6 | true |
| 682 | 0x5f08c0 | Phyre_PClassDescriptor_GetSizeTable_57 | 0x6 | true |
| 683 | 0x5c40c0 | Phyre_PClassDescriptor_GetSizeTable_62 | 0x6 | true |
| 684 | 0x5c4130 | Phyre_PClassDescriptor_GetSizeTable_62_v2 | 0x6 | true |
| 685 | 0x5c4530 | Phyre_PClassDescriptor_GetSizeTable_62_v3 | 0x6 | true |
| 686 | 0x5c4570 | Phyre_PClassDescriptor_GetSizeTable_62_v4 | 0x6 | true |
| 687 | 0x5c4750 | Phyre_PClassDescriptor_GetSizeTable_62_v5 | 0x6 | true |
| 688 | 0x5c4510 | Phyre_PClassDescriptor_GetSizeTable_70 | 0x6 | true |
| 689 | 0x5c4550 | Phyre_PClassDescriptor_GetSizeTable_70_v2 | 0x6 | true |
| 690 | 0x5c4590 | Phyre_PClassDescriptor_GetSizeTable_70_v3 | 0x6 | true |
| 691 | 0x5d3740 | Phyre_PClassDescriptor_GetSizeTable_73 | 0x6 | true |
| 692 | 0x5d0030 | Phyre_PClassDescriptor_GetSizeTable_76 | 0x6 | true |
| 693 | 0x5d0040 | Phyre_PClassDescriptor_GetSizeTable_76_v2 | 0x6 | true |
| 694 | 0x5c40b0 | Phyre_PClassDescriptor_GetSizeTable_78 | 0x6 | true |
| 695 | 0x5c4120 | Phyre_PClassDescriptor_GetSizeTable_78_v2 | 0x6 | true |
| 696 | 0x5c4740 | Phyre_PClassDescriptor_GetSizeTable_78_v3 | 0x6 | true |
| 697 | 0x5c47b0 | Phyre_PClassDescriptor_GetSizeTable_78_v4 | 0x6 | true |
| 698 | 0x5c6160 | Phyre_PClassDescriptor_GetSizeTable_78_v5 | 0x6 | true |
| 699 | 0x5c40f0 | Phyre_PClassDescriptor_GetSizeTable_79 | 0x6 | true |
| 700 | 0x5c4160 | Phyre_PClassDescriptor_GetSizeTable_79_v2 | 0x6 | true |
| 701 | 0x5c4780 | Phyre_PClassDescriptor_GetSizeTable_79_v3 | 0x6 | true |
| 702 | 0x5c40e0 | Phyre_PClassDescriptor_GetSizeTable_83 | 0x6 | true |
| 703 | 0x5c4150 | Phyre_PClassDescriptor_GetSizeTable_83_v2 | 0x6 | true |
| 704 | 0x5c4770 | Phyre_PClassDescriptor_GetSizeTable_83_v3 | 0x6 | true |
| 705 | 0x5f08f0 | Phyre_PClassDescriptor_GetSizeTable_86 | 0x6 | true |
| 706 | 0x5f0010 | Phyre_PClassDescriptor_GetSizeTable_CBEE00 | 0x6 | true |
| 707 | 0x5f0030 | Phyre_PClassDescriptor_GetSizeTable_CBEFC8 | 0x6 | true |
| 708 | 0x5f0000 | Phyre_PClassDescriptor_GetSizeTable_CBFD70 | 0x6 | true |
| 709 | 0x443c20 | Phyre_PClassDescriptor_GetStaticField | 0x1a | true |
| 710 | 0x445d10 | Phyre_PClassDescriptor_GetStaticField_2 | 0x1a | true |
| 711 | 0x446b60 | Phyre_PClassDescriptor_GetStaticField_Offset4 | 0x26 | true |
| 712 | 0x449070 | Phyre_PClassDescriptor_GetStaticField_PArrayU8 | 0x8b | true |
| 713 | 0x449be0 | Phyre_PClassDescriptor_GetStaticField_PArrayU8_Wrapper | 0x15 | true |
| 714 | 0x43bd00 | Phyre_PClassDescriptor_GetStringName | 0x3b | true |
| 715 | 0x5009b0 | Phyre_PClassDescriptor_GetThis | 0x3 | true |
| 716 | 0x43cca0 | Phyre_PClassDescriptor_GetTotalSize | 0x4d | true |
| 717 | 0x532610 | Phyre_PClassDescriptor_GetTotalSize_64_Thunk | 0xa | true |
| 718 | 0x532640 | Phyre_PClassDescriptor_GetTotalSize_CACDB0_Thunk | 0xa | true |
| 719 | 0x5a8df0 | Phyre_PClassDescriptor_GetTotalSize_CBB268 | 0xa | true |
| 720 | 0x5b00c0 | Phyre_PClassDescriptor_GetTotalSize_CBBA08 | 0xa | true |
| 721 | 0x5b00d0 | Phyre_PClassDescriptor_GetTotalSize_CBBAA0 | 0xa | true |
| 722 | 0x5b00b0 | Phyre_PClassDescriptor_GetTotalSize_CBBB38 | 0xa | true |
| 723 | 0x500e50 | Phyre_PClassDescriptor_GetTotalSize_LodData | 0xa | true |
| 724 | 0x519340 | Phyre_PClassDescriptor_GetTotalSize_PAnimationConstantChannel | 0x5 | true |
| 725 | 0x51e700 | Phyre_PClassDescriptor_GetTotalSize_PArrayAnimationSlotIndex | 0xa | true |
| 726 | 0x51e6f0 | Phyre_PClassDescriptor_GetTotalSize_PArrayAnimationSlotList | 0xa | true |
| 727 | 0xa2af80 | Phyre_PClassDescriptor_GetTotalSize_Size76 | 0xa | true |
| 728 | 0x43f060 | Phyre_PClassDescriptor_GetTotalSize_thunk | 0xa | true |
| 729 | 0x4a0b40 | Phyre_PClassDescriptor_GetTotalSize_w | 0xa | true |
| 730 | 0x502ed0 | Phyre_PClassDescriptor_GetTotalSize_w_0 | 0xa | true |
| 731 | 0x49ce80 | Phyre_PClassDescriptor_GetTotalSize_w_1 | 0xa | true |
| 732 | 0x55c330 | Phyre_PClassDescriptor_GetTotalSize_w_2 | 0xa | true |
| 733 | 0x61e690 | Phyre_PClassDescriptor_GetTotalSizeGlobal | 0xa | true |
| 734 | 0x5c4200 | Phyre_PClassDescriptor_GetTypeName_PModifierAndInputs | 0x6 | true |
| 735 | 0x5c4210 | Phyre_PClassDescriptor_GetTypeName_PModifierNetwork | 0x6 | true |
| 736 | 0x5c4220 | Phyre_PClassDescriptor_GetTypeName_PModifierNetworkBuffer | 0x6 | true |
| 737 | 0x5c4230 | Phyre_PClassDescriptor_GetTypeName_PModifierNetworkInfoPacket | 0x6 | true |
| 738 | 0x5c4240 | Phyre_PClassDescriptor_GetTypeName_PModifierNetworkInfoPacket_Buffer | 0x6 | true |
| 739 | 0x5c4250 | Phyre_PClassDescriptor_GetTypeName_PModifierNetworkInfoPacket_ModifierCode | 0x6 | true |
| 740 | 0x5c4260 | Phyre_PClassDescriptor_GetTypeName_PModifierNetworkInfoPacket_ModifierInstance | 0x6 | true |
| 741 | 0x5ca0c0 | Phyre_PClassDescriptor_GetTypeName_PMorphModifierWeightsUserDataObject | 0x6 | true |
| 742 | 0x5cb880 | Phyre_PClassDescriptor_GetTypeName_PMorphModifierWeightsUserDataObject_v2 | 0x6 | true |
| 743 | 0x5f0350 | Phyre_PClassDescriptor_GetTypeName_PPhysicsCylinder | 0x6 | true |
| 744 | 0x5f0360 | Phyre_PClassDescriptor_GetTypeName_PPhysicsCylinderBase | 0x6 | true |
| 745 | 0x5f0370 | Phyre_PClassDescriptor_GetTypeName_PPhysicsCylinderBullet | 0x6 | true |
| 746 | 0x5f0380 | Phyre_PClassDescriptor_GetTypeName_PPhysicsInterface | 0x6 | true |
| 747 | 0x5f0390 | Phyre_PClassDescriptor_GetTypeName_PPhysicsInterfaceBase | 0x6 | true |
| 748 | 0x5f03a0 | Phyre_PClassDescriptor_GetTypeName_PPhysicsInterfaceBullet | 0x6 | true |
| 749 | 0x5f03b0 | Phyre_PClassDescriptor_GetTypeName_PPhysicsMaterial | 0x6 | true |
| 750 | 0x5f03c0 | Phyre_PClassDescriptor_GetTypeName_PPhysicsMesh | 0x6 | true |
| 751 | 0x5f03d0 | Phyre_PClassDescriptor_GetTypeName_PPhysicsMeshBase | 0x6 | true |
| 752 | 0x5f03e0 | Phyre_PClassDescriptor_GetTypeName_PPhysicsMeshBullet | 0x6 | true |
| 753 | 0x5f03f0 | Phyre_PClassDescriptor_GetTypeName_PPhysicsModel | 0x6 | true |
| 754 | 0x5f0400 | Phyre_PClassDescriptor_GetTypeName_PPhysicsPlane | 0x6 | true |
| 755 | 0x5f0410 | Phyre_PClassDescriptor_GetTypeName_PPhysicsPlaneBase | 0x6 | true |
| 756 | 0x5f0420 | Phyre_PClassDescriptor_GetTypeName_PPhysicsPlaneBullet | 0x6 | true |
| 757 | 0x5f0430 | Phyre_PClassDescriptor_GetTypeName_PPhysicsRigidBody | 0x6 | true |
| 758 | 0x5f0440 | Phyre_PClassDescriptor_GetTypeName_PPhysicsRigidBodyBase | 0x6 | true |
| 759 | 0x5f0450 | Phyre_PClassDescriptor_GetTypeName_PPhysicsRigidBodyBullet | 0x6 | true |
| 760 | 0x5f0460 | Phyre_PClassDescriptor_GetTypeName_PPhysicsShape | 0x6 | true |
| 761 | 0x5f0470 | Phyre_PClassDescriptor_GetTypeName_PPhysicsShapeBase | 0x6 | true |
| 762 | 0x5f0480 | Phyre_PClassDescriptor_GetTypeName_PPhysicsShapeBullet | 0x6 | true |
| 763 | 0x5f0490 | Phyre_PClassDescriptor_GetTypeName_PPhysicsSphere | 0x6 | true |
| 764 | 0x5f04a0 | Phyre_PClassDescriptor_GetTypeName_PPhysicsSphereBase | 0x6 | true |
| 765 | 0x5f04b0 | Phyre_PClassDescriptor_GetTypeName_PPhysicsSphereBullet | 0x6 | true |
| 766 | 0x5f04c0 | Phyre_PClassDescriptor_GetTypeName_PPhysicsTaperedCapsule | 0x6 | true |
| 767 | 0x5f04d0 | Phyre_PClassDescriptor_GetTypeName_PPhysicsTaperedCylinder | 0x6 | true |
| 768 | 0x5f04e0 | Phyre_PClassDescriptor_GetTypeName_PPhysicsWorld | 0x6 | true |
| 769 | 0x5f04f0 | Phyre_PClassDescriptor_GetTypeName_PPhysicsWorldBase | 0x6 | true |
| 770 | 0x5f0500 | Phyre_PClassDescriptor_GetTypeName_PPhysicsWorldBullet | 0x6 | true |
| 771 | 0x5f0510 | Phyre_PClassDescriptor_GetTypeName_PRaycastResult | 0x6 | true |
| 772 | 0x5c4270 | Phyre_PClassDescriptor_GetTypeName_PRenderStream | 0x6 | true |
| 773 | 0x5c4280 | Phyre_PClassDescriptor_GetTypeName_PRenderStreamInput | 0x6 | true |
| 774 | 0x5ceef0 | Phyre_PClassDescriptor_GetTypeName_PScheduler | 0x6 | true |
| 775 | 0x5cffa0 | Phyre_PClassDescriptor_GetTypeName_PScheduler_v2 | 0x6 | true |
| 776 | 0x5d4440 | Phyre_PClassDescriptor_GetTypeName_PScript | 0x6 | true |
| 777 | 0x5d50b0 | Phyre_PClassDescriptor_GetTypeName_PScript_v2 | 0x6 | true |
| 778 | 0x5d37d0 | Phyre_PClassDescriptor_GetTypeName_PScriptCallbackHandler | 0x6 | true |
| 779 | 0x5d3de0 | Phyre_PClassDescriptor_GetTypeName_PScriptCallbackHandler_v2 | 0x6 | true |
| 780 | 0x5f4f60 | Phyre_PClassDescriptor_GetTypeSize23 | 0x6 | true |
| 781 | 0x5c3d40 | Phyre_PClassDescriptor_GetTypeSize_0x02 | 0x6 | true |
| 782 | 0x5c3d30 | Phyre_PClassDescriptor_GetTypeSize_0x10 | 0x6 | true |
| 783 | 0x5c3d50 | Phyre_PClassDescriptor_GetTypeSize_0x10_v2 | 0x6 | true |
| 784 | 0x5c3d60 | Phyre_PClassDescriptor_GetTypeSize_0x10_v3 | 0x6 | true |
| 785 | 0x5f6620 | Phyre_PClassDescriptor_GetTypeSize_40 | 0x6 | true |
| 786 | 0x5f6630 | Phyre_PClassDescriptor_GetTypeSize_44 | 0x6 | true |
| 787 | 0x532fc0 | Phyre_PClassDescriptor_GetValue_CAD8DC | 0x6 | true |
| 788 | 0x532fd0 | Phyre_PClassDescriptor_GetValue_CAD8E0 | 0x6 | true |
| 789 | 0x532fb0 | Phyre_PClassDescriptor_GetValue_CAD8E4 | 0x6 | true |
| 790 | 0x532fa0 | Phyre_PClassDescriptor_GetValue_CAD8E8 | 0x6 | true |
| 791 | 0x61a320 | Phyre_PClassDescriptor_GetValueAbort | 0x12 | true |
| 792 | 0x4bd900 | Phyre_PClassDescriptor_GetWord_4BD900 | 0x4 | true |
| 793 | 0x5f7f70 | Phyre_PClassDescriptor_Init16Length | 0x28 | true |
| 794 | 0x5f7bb0 | Phyre_PClassDescriptor_Init2Dwords | 0x1d | true |
| 795 | 0x5f80f0 | Phyre_PClassDescriptor_Init3DwordsZero | 0x24 | true |
| 796 | 0x5f8550 | Phyre_PClassDescriptor_Init_2FieldsAt32 | 0x1e | true |
| 797 | 0x5f8d20 | Phyre_PClassDescriptor_Init_AnimState | 0x11 | true |
| 798 | 0x5f8d40 | Phyre_PClassDescriptor_Init_CalcForce | 0x11 | true |
| 799 | 0x5f8510 | Phyre_PClassDescriptor_Init_characterState | 0x15 | true |
| 800 | 0xb090e0 | Phyre_PClassDescriptor_Init_PArray_PBitmapFontCharInfo | 0x14 | true |
| 801 | 0xb08da0 | Phyre_PClassDescriptor_Init_PArray_PostEffectBase4 | 0x14 | true |
| 802 | 0x52b2b0 | Phyre_PClassDescriptor_Init_PArrayAnimDataSource_A | 0x76 | true |
| 803 | 0x52b330 | Phyre_PClassDescriptor_Init_PArrayAnimDataSource_B | 0x76 | true |
| 804 | 0x52b3b0 | Phyre_PClassDescriptor_Init_PArrayAnimDataSource_C | 0x76 | true |
| 805 | 0x55c870 | Phyre_PClassDescriptor_Init_PArrayDataBlockD3D11_A | 0x76 | true |
| 806 | 0x55ca30 | Phyre_PClassDescriptor_Init_PArrayDataBlockD3D11_B | 0x76 | true |
| 807 | 0xb09090 | Phyre_PClassDescriptor_Init_PBitmapFont | 0x14 | true |
| 808 | 0xb090b0 | Phyre_PClassDescriptor_Init_PBitmapFontCharInfo | 0x14 | true |
| 809 | 0xb086b0 | Phyre_PClassDescriptor_Init_PDeferredLighting | 0x14 | true |
| 810 | 0xb086d0 | Phyre_PClassDescriptor_Init_PDeferredLightingBase | 0x14 | true |
| 811 | 0xb086f0 | Phyre_PClassDescriptor_Init_PDeferredLightingD3D11 | 0x14 | true |
| 812 | 0xb08710 | Phyre_PClassDescriptor_Init_PDepthOfField | 0x14 | true |
| 813 | 0xb08730 | Phyre_PClassDescriptor_Init_PDepthOfFieldBase | 0x14 | true |
| 814 | 0xb08750 | Phyre_PClassDescriptor_Init_PDepthOfFieldD3D11 | 0x14 | true |
| 815 | 0xb08770 | Phyre_PClassDescriptor_Init_PFXAA | 0x14 | true |
| 816 | 0xb08790 | Phyre_PClassDescriptor_Init_PFXAABase | 0x14 | true |
| 817 | 0xb087b0 | Phyre_PClassDescriptor_Init_PFXAAD3D11 | 0x14 | true |
| 818 | 0xb087d0 | Phyre_PClassDescriptor_Init_PGlow | 0x14 | true |
| 819 | 0xb087f0 | Phyre_PClassDescriptor_Init_PGlowBase | 0x14 | true |
| 820 | 0xb08810 | Phyre_PClassDescriptor_Init_PGlowD3D11 | 0x14 | true |
| 821 | 0xb08830 | Phyre_PClassDescriptor_Init_PGlowGPUBase | 0x14 | true |
| 822 | 0x5f8f80 | Phyre_PClassDescriptor_Init_PhysicsIntegrate | 0x11 | true |
| 823 | 0x5f84f0 | Phyre_PClassDescriptor_Init_physicsState | 0x15 | true |
| 824 | 0x5f8530 | Phyre_PClassDescriptor_Init_physicsState_v2 | 0x15 | true |
| 825 | 0xb07f80 | Phyre_PClassDescriptor_Init_PInputSourceMotionQuatX | 0x14 | true |
| 826 | 0xb08850 | Phyre_PClassDescriptor_Init_PLegacyGlow | 0x14 | true |
| 827 | 0xb08870 | Phyre_PClassDescriptor_Init_PLegacyGlowBase | 0x14 | true |
| 828 | 0xb08890 | Phyre_PClassDescriptor_Init_PLegacyGlowD3D11 | 0x14 | true |
| 829 | 0xb088b0 | Phyre_PClassDescriptor_Init_PLegacyGlowGPUBase | 0x14 | true |
| 830 | 0xb08930 | Phyre_PClassDescriptor_Init_PMeshParticleSystemBase | 0x14 | true |
| 831 | 0xb088d0 | Phyre_PClassDescriptor_Init_PMLAA | 0x14 | true |
| 832 | 0xb088f0 | Phyre_PClassDescriptor_Init_PMLAABase | 0x14 | true |
| 833 | 0xb08910 | Phyre_PClassDescriptor_Init_PMLAAD3D11 | 0x14 | true |
| 834 | 0xb08950 | Phyre_PClassDescriptor_Init_PMotionBlur | 0x14 | true |
| 835 | 0xb08970 | Phyre_PClassDescriptor_Init_PMotionBlurBase | 0x14 | true |
| 836 | 0xb08990 | Phyre_PClassDescriptor_Init_PMotionBlurD3D11 | 0x14 | true |
| 837 | 0xb0a5c0 | Phyre_PClassDescriptor_Init_POccluderGeometryInstance | 0x14 | true |
| 838 | 0xb089b0 | Phyre_PClassDescriptor_Init_PPostEffectBase | 0x14 | true |
| 839 | 0xb089d0 | Phyre_PClassDescriptor_Init_PPostEffectManager | 0x14 | true |
| 840 | 0xb089f0 | Phyre_PClassDescriptor_Init_PScreenSpaceAmbientOcclusion | 0x14 | true |
| 841 | 0xb08a10 | Phyre_PClassDescriptor_Init_PScreenSpaceAmbientOcclusionBase | 0x14 | true |
| 842 | 0xb08a30 | Phyre_PClassDescriptor_Init_PScreenSpaceAmbientOcclusionD3D11 | 0x14 | true |
| 843 | 0xb08a50 | Phyre_PClassDescriptor_Init_PScreenSpaceReflection | 0x14 | true |
| 844 | 0xb08a70 | Phyre_PClassDescriptor_Init_PScreenSpaceReflectionBase | 0x14 | true |
| 845 | 0xb08a90 | Phyre_PClassDescriptor_Init_PScreenSpaceReflectionD3D11 | 0x14 | true |
| 846 | 0x55c8f0 | Phyre_PClassDescriptor_Init_PSharrayDataBlockBufferD3D11_A | 0x76 | true |
| 847 | 0x55cab0 | Phyre_PClassDescriptor_Init_PSharrayDataBlockBufferD3D11_B | 0x76 | true |
| 848 | 0x55c970 | Phyre_PClassDescriptor_Init_PSharrayIndexDataBlockBufferD3D11_A | 0x76 | true |
| 849 | 0x55cb30 | Phyre_PClassDescriptor_Init_PSharrayIndexDataBlockBufferD3D11_B | 0x76 | true |
| 850 | 0x5f8fb0 | Phyre_PClassDescriptor_Init_Skeleton | 0x11 | true |
| 851 | 0x5f8c70 | Phyre_PClassDescriptor_Init_Transform | 0x11 | true |
| 852 | 0x5f7ff0 | Phyre_PClassDescriptor_InitVec3Zero | 0x1a | true |
| 853 | 0x43d0a0 | Phyre_PClassDescriptor_IsRegistered | 0xc | true |
| 854 | 0x607600 | Phyre_PClassDescriptor_LoadMatrix4x4 | 0x7b | true |
| 855 | 0x6075a0 | Phyre_PClassDescriptor_LoadVector3 | 0x53 | true |
| 856 | 0xa30bd0 | Phyre_PClassDescriptor_OccluderGeoInstDtor | 0x27 | true |
| 857 | 0xa30c00 | Phyre_PClassDescriptor_OccluderGeoInstDtor_B | 0x27 | true |
| 858 | 0xa30c30 | Phyre_PClassDescriptor_OccluderGeoInstDtor_C | 0x27 | true |
| 859 | 0x53ebe0 | Phyre_PClassDescriptor_PAnimatableComponent_Dtor | 0xb | true |
| 860 | 0xa2bb40 | Phyre_PClassDescriptor_PArray_PBitmapFontCharInfo_Destructor | 0xb | true |
| 861 | 0xa2bb70 | Phyre_PClassDescriptor_PArray_PBitmapFontCharInfo_Destructor_B | 0xb | true |
| 862 | 0xa2bda0 | Phyre_PClassDescriptor_PArray_PBitmapFontCharInfo_Dtor | 0x27 | true |
| 863 | 0xa2be30 | Phyre_PClassDescriptor_PArray_PBitmapFontCharInfo_Dtor_B | 0x27 | true |
| 864 | 0xa2be90 | Phyre_PClassDescriptor_PArray_PBmpFontCharInfo_Dtor_C | 0x27 | true |
| 865 | 0xa01350 | Phyre_PClassDescriptor_PArray_PostEffectBase4_Ctor | 0x27 | true |
| 866 | 0xa01fb0 | Phyre_PClassDescriptor_PArray_PostEffectBase4_Ctor_B | 0x27 | true |
| 867 | 0x4478f0 | Phyre_PClassDescriptor_PArrayUChar_Destructor | 0xb | true |
| 868 | 0x447910 | Phyre_PClassDescriptor_PArrayUChar_Destructor_dup | 0xb | true |
| 869 | 0x617a20 | Phyre_PClassDescriptor_PAsyncProcessHeader_dtor | 0xb | true |
| 870 | 0x617a30 | Phyre_PClassDescriptor_PAsyncProcessHeader_dtor_B | 0xb | true |
| 871 | 0x4356c0 | Phyre_PClassDescriptor_PBase_dtor | 0xb | true |
| 872 | 0x4356d0 | Phyre_PClassDescriptor_PBase_dtor_0 | 0xb | true |
| 873 | 0xa2bb50 | Phyre_PClassDescriptor_PBitmapFont_Destructor | 0xb | true |
| 874 | 0xa2bbc0 | Phyre_PClassDescriptor_PBitmapFont_Destructor_B | 0xb | true |
| 875 | 0xa2bdd0 | Phyre_PClassDescriptor_PBitmapFont_Dtor | 0x27 | true |
| 876 | 0xa2bec0 | Phyre_PClassDescriptor_PBitmapFont_Dtor_B | 0x27 | true |
| 877 | 0xa2bf20 | Phyre_PClassDescriptor_PBitmapFont_Dtor_C | 0x27 | true |
| 878 | 0xa2bb60 | Phyre_PClassDescriptor_PBitmapFontCharInfo_Destructor | 0xb | true |
| 879 | 0xa2bb80 | Phyre_PClassDescriptor_PBitmapFontCharInfo_Destructor_B | 0xb | true |
| 880 | 0xa2be00 | Phyre_PClassDescriptor_PBitmapFontCharInfo_Dtor | 0x27 | true |
| 881 | 0xa2be60 | Phyre_PClassDescriptor_PBitmapFontCharInfo_Dtor_B | 0x27 | true |
| 882 | 0xa2bef0 | Phyre_PClassDescriptor_PBitmapFontCharInfo_Dtor_C | 0x27 | true |
| 883 | 0x503610 | Phyre_PClassDescriptor_PChar_RegisterAndFinalize | 0x17 | true |
| 884 | 0x446390 | Phyre_PClassDescriptor_PClassDataMemberDynamic_Destructor | 0xb | true |
| 885 | 0x4463b0 | Phyre_PClassDescriptor_PClassDataMemberDynamic_Destructor_dup | 0xb | true |
| 886 | 0x43b480 | Phyre_PClassDescriptor_PClassDescriptor_dtor | 0xb | true |
| 887 | 0x43b490 | Phyre_PClassDescriptor_PClassDescriptor_dtor_0 | 0xb | true |
| 888 | 0x43b690 | Phyre_PClassDescriptor_PClassDescriptor_dtor_1 | 0xb | true |
| 889 | 0x447900 | Phyre_PClassDescriptor_PClassDescriptorDynamic_Destructor | 0xb | true |
| 890 | 0x447940 | Phyre_PClassDescriptor_PClassDescriptorDynamic_Destructor_dup | 0xb | true |
| 891 | 0x43a1e0 | Phyre_PClassDescriptor_PClassMember_dtor | 0xb | true |
| 892 | 0x43a200 | Phyre_PClassDescriptor_PClassMember_dtor_0 | 0xb | true |
| 893 | 0xa019b0 | Phyre_PClassDescriptor_PDeferredLighting_Ctor | 0x27 | true |
| 894 | 0xa01fe0 | Phyre_PClassDescriptor_PDeferredLighting_Ctor_B | 0x27 | true |
| 895 | 0xa019e0 | Phyre_PClassDescriptor_PDeferredLightingBase_Ctor | 0x27 | true |
| 896 | 0xa02010 | Phyre_PClassDescriptor_PDeferredLightingBase_Ctor_B | 0x27 | true |
| 897 | 0xa013e0 | Phyre_PClassDescriptor_PDeferredLightingD3D11_Ctor | 0x27 | true |
| 898 | 0xa01a10 | Phyre_PClassDescriptor_PDeferredLightingD3D11_Ctor_B | 0x27 | true |
| 899 | 0xa02040 | Phyre_PClassDescriptor_PDeferredLightingD3D11_Ctor_C | 0x27 | true |
| 900 | 0xa01a40 | Phyre_PClassDescriptor_PDepthOfField_Ctor | 0x27 | true |
| 901 | 0xa02070 | Phyre_PClassDescriptor_PDepthOfField_Ctor_B | 0x27 | true |
| 902 | 0xa01440 | Phyre_PClassDescriptor_PDepthOfFieldBase_Ctor | 0x27 | true |
| 903 | 0xa01a70 | Phyre_PClassDescriptor_PDepthOfFieldBase_Ctor_B | 0x27 | true |
| 904 | 0xa020a0 | Phyre_PClassDescriptor_PDepthOfFieldBase_Ctor_C | 0x27 | true |
| 905 | 0xa01470 | Phyre_PClassDescriptor_PDepthOfFieldD3D11_Ctor | 0x27 | true |
| 906 | 0xa01aa0 | Phyre_PClassDescriptor_PDepthOfFieldD3D11_Ctor_B | 0x27 | true |
| 907 | 0xa020d0 | Phyre_PClassDescriptor_PDepthOfFieldD3D11_Ctor_C | 0x27 | true |
| 908 | 0xa014a0 | Phyre_PClassDescriptor_PFXAA_Ctor | 0x27 | true |
| 909 | 0xa02100 | Phyre_PClassDescriptor_PFXAA_Ctor_B | 0x27 | true |
| 910 | 0xa014d0 | Phyre_PClassDescriptor_PFXAABase_Ctor | 0x27 | true |
| 911 | 0xa01b00 | Phyre_PClassDescriptor_PFXAABase_Ctor_B | 0x27 | true |
| 912 | 0xa02130 | Phyre_PClassDescriptor_PFXAABase_Ctor_C | 0x27 | true |
| 913 | 0xa01500 | Phyre_PClassDescriptor_PFXAAD3D11_Ctor | 0x27 | true |
| 914 | 0xa01b30 | Phyre_PClassDescriptor_PFXAAD3D11_Ctor_B | 0x27 | true |
| 915 | 0xa02160 | Phyre_PClassDescriptor_PFXAAD3D11_Ctor_C | 0x27 | true |
| 916 | 0xa01b60 | Phyre_PClassDescriptor_PGlow_Ctor | 0x27 | true |
| 917 | 0xa02190 | Phyre_PClassDescriptor_PGlow_Ctor_B | 0x27 | true |
| 918 | 0xa01560 | Phyre_PClassDescriptor_PGlowBase_Ctor | 0x27 | true |
| 919 | 0xa01b90 | Phyre_PClassDescriptor_PGlowBase_Ctor_B | 0x27 | true |
| 920 | 0xa021c0 | Phyre_PClassDescriptor_PGlowBase_Ctor_C | 0x27 | true |
| 921 | 0xa01590 | Phyre_PClassDescriptor_PGlowD3D11_Ctor | 0x27 | true |
| 922 | 0xa01bc0 | Phyre_PClassDescriptor_PGlowD3D11_Ctor_B | 0x27 | true |
| 923 | 0xa021f0 | Phyre_PClassDescriptor_PGlowD3D11_Ctor_C | 0x27 | true |
| 924 | 0xa015c0 | Phyre_PClassDescriptor_PGlowGPUBase_Ctor | 0x27 | true |
| 925 | 0xa01bf0 | Phyre_PClassDescriptor_PGlowGPUBase_Ctor_B | 0x27 | true |
| 926 | 0xa02220 | Phyre_PClassDescriptor_PGlowGPUBase_Ctor_C | 0x27 | true |
| 927 | 0xa015f0 | Phyre_PClassDescriptor_PLegacyGlow_Ctor | 0x27 | true |
| 928 | 0xa01c20 | Phyre_PClassDescriptor_PLegacyGlow_Ctor_B | 0x27 | true |
| 929 | 0xa02250 | Phyre_PClassDescriptor_PLegacyGlow_Ctor_C | 0x27 | true |
| 930 | 0xa01620 | Phyre_PClassDescriptor_PLegacyGlowBase_Ctor | 0x27 | true |
| 931 | 0xa01c50 | Phyre_PClassDescriptor_PLegacyGlowBase_Ctor_B | 0x27 | true |
| 932 | 0xa02280 | Phyre_PClassDescriptor_PLegacyGlowBase_Ctor_C | 0x27 | true |
| 933 | 0xa01650 | Phyre_PClassDescriptor_PLegacyGlowD3D11_Ctor | 0x27 | true |
| 934 | 0xa01c80 | Phyre_PClassDescriptor_PLegacyGlowD3D11_Ctor_B | 0x27 | true |
| 935 | 0xa022b0 | Phyre_PClassDescriptor_PLegacyGlowD3D11_Ctor_C | 0x27 | true |
| 936 | 0xa01680 | Phyre_PClassDescriptor_PLegacyGlowGPUBase_Ctor | 0x27 | true |
| 937 | 0xa01cb0 | Phyre_PClassDescriptor_PLegacyGlowGPUBase_Ctor_B | 0x27 | true |
| 938 | 0xa022e0 | Phyre_PClassDescriptor_PLegacyGlowGPUBase_Ctor_C | 0x27 | true |
| 939 | 0x49d7d0 | Phyre_PClassDescriptor_PLight_Setup | 0x27 | true |
| 940 | 0x49d800 | Phyre_PClassDescriptor_PLight_Setup_B | 0x22 | true |
| 941 | 0x49d830 | Phyre_PClassDescriptor_PLight_Setup_C | 0x22 | true |
| 942 | 0x49d860 | Phyre_PClassDescriptor_PLight_Setup_D | 0x22 | true |
| 943 | 0x49d890 | Phyre_PClassDescriptor_PLight_Setup_E | 0x22 | true |
| 944 | 0x49d8c0 | Phyre_PClassDescriptor_PLight_Setup_F | 0x22 | true |
| 945 | 0x49d8f0 | Phyre_PClassDescriptor_PLight_Setup_G | 0x22 | true |
| 946 | 0x49d920 | Phyre_PClassDescriptor_PLight_Setup_H | 0x21 | true |
| 947 | 0xa01740 | Phyre_PClassDescriptor_PMeshParticleSystemBase_Ctor | 0x27 | true |
| 948 | 0xa01d70 | Phyre_PClassDescriptor_PMeshParticleSystemBase_Ctor_B | 0x27 | true |
| 949 | 0xa023a0 | Phyre_PClassDescriptor_PMeshParticleSystemBase_Ctor_C | 0x27 | true |
| 950 | 0xa016b0 | Phyre_PClassDescriptor_PMLAA_Ctor | 0x27 | true |
| 951 | 0xa01ce0 | Phyre_PClassDescriptor_PMLAA_Ctor_B | 0x27 | true |
| 952 | 0xa02310 | Phyre_PClassDescriptor_PMLAA_Ctor_C | 0x27 | true |
| 953 | 0xa016e0 | Phyre_PClassDescriptor_PMLAABase_Ctor | 0x27 | true |
| 954 | 0xa01d10 | Phyre_PClassDescriptor_PMLAABase_Ctor_B | 0x27 | true |
| 955 | 0xa02340 | Phyre_PClassDescriptor_PMLAABase_Ctor_C | 0x27 | true |
| 956 | 0xa01710 | Phyre_PClassDescriptor_PMLAAD3D11_Ctor | 0x27 | true |
| 957 | 0xa01d40 | Phyre_PClassDescriptor_PMLAAD3D11_Ctor_B | 0x27 | true |
| 958 | 0x5cb2b0 | Phyre_PClassDescriptor_PMorphModifierWeightsUserDataObject_ctor | 0x91 | true |
| 959 | 0xa01770 | Phyre_PClassDescriptor_PMotionBlur_Ctor | 0x27 | true |
| 960 | 0xa01da0 | Phyre_PClassDescriptor_PMotionBlur_Ctor_B | 0x27 | true |
| 961 | 0xa023d0 | Phyre_PClassDescriptor_PMotionBlur_Ctor_C | 0x27 | true |
| 962 | 0xa017a0 | Phyre_PClassDescriptor_PMotionBlurBase_Ctor | 0x27 | true |
| 963 | 0xa01dd0 | Phyre_PClassDescriptor_PMotionBlurBase_Ctor_B | 0x27 | true |
| 964 | 0xa02400 | Phyre_PClassDescriptor_PMotionBlurBase_Ctor_C | 0x27 | true |
| 965 | 0xa017d0 | Phyre_PClassDescriptor_PMotionBlurD3D11_Ctor | 0x27 | true |
| 966 | 0xa01e00 | Phyre_PClassDescriptor_PMotionBlurD3D11_Ctor_B | 0x27 | true |
| 967 | 0xa02430 | Phyre_PClassDescriptor_PMotionBlurD3D11_Ctor_C | 0x27 | true |
| 968 | 0x4d81f0 | Phyre_PClassDescriptor_PNameValuePair_Register | 0xde | true |
| 969 | 0xa01800 | Phyre_PClassDescriptor_PPostEffectBase_Ctor | 0x27 | true |
| 970 | 0xa01e30 | Phyre_PClassDescriptor_PPostEffectBase_Ctor_B | 0x27 | true |
| 971 | 0xa02460 | Phyre_PClassDescriptor_PPostEffectBase_Ctor_C | 0x27 | true |
| 972 | 0xa01830 | Phyre_PClassDescriptor_PPostEffectManager_Ctor | 0x27 | true |
| 973 | 0xa01e60 | Phyre_PClassDescriptor_PPostEffectManager_Ctor_B | 0x27 | true |
| 974 | 0xa02490 | Phyre_PClassDescriptor_PPostEffectManager_Ctor_C | 0x27 | true |
| 975 | 0xa01860 | Phyre_PClassDescriptor_PScreenSpaceAmbientOcclusion_Ctor | 0x27 | true |
| 976 | 0xa01e90 | Phyre_PClassDescriptor_PScreenSpaceAmbientOcclusion_Ctor_B | 0x27 | true |
| 977 | 0xa024c0 | Phyre_PClassDescriptor_PScreenSpaceAmbientOcclusion_Ctor_C | 0x27 | true |
| 978 | 0xa01890 | Phyre_PClassDescriptor_PScreenSpaceAmbientOcclusionBase_Ctor | 0x27 | true |
| 979 | 0xa01ec0 | Phyre_PClassDescriptor_PScreenSpaceAmbientOcclusionBase_Ctor_B | 0x27 | true |
| 980 | 0xa024f0 | Phyre_PClassDescriptor_PScreenSpaceAmbientOcclusionBase_Ctor_C | 0x27 | true |
| 981 | 0xa018c0 | Phyre_PClassDescriptor_PScreenSpaceAmbientOcclusionD3D11_Ctor | 0x27 | true |
| 982 | 0xa01ef0 | Phyre_PClassDescriptor_PScreenSpaceAmbientOcclusionD3D11_Ctor_B | 0x27 | true |
| 983 | 0xa02520 | Phyre_PClassDescriptor_PScreenSpaceAmbientOcclusionD3D11_Ctor_C | 0x27 | true |
| 984 | 0xa018f0 | Phyre_PClassDescriptor_PScreenSpaceReflection_Ctor | 0x27 | true |
| 985 | 0xa01f20 | Phyre_PClassDescriptor_PScreenSpaceReflection_Ctor_B | 0x27 | true |
| 986 | 0xa02550 | Phyre_PClassDescriptor_PScreenSpaceReflection_Ctor_C | 0x27 | true |
| 987 | 0xa01920 | Phyre_PClassDescriptor_PScreenSpaceReflectionBase_Ctor | 0x27 | true |
| 988 | 0xa01f50 | Phyre_PClassDescriptor_PScreenSpaceReflectionBase_Ctor_B | 0x27 | true |
| 989 | 0xa02580 | Phyre_PClassDescriptor_PScreenSpaceReflectionBase_Ctor_C | 0x27 | true |
| 990 | 0xa01950 | Phyre_PClassDescriptor_PScreenSpaceReflectionD3D11_Ctor | 0x27 | true |
| 991 | 0xa01f80 | Phyre_PClassDescriptor_PScreenSpaceReflectionD3D11_Ctor_B | 0x27 | true |
| 992 | 0xa025b0 | Phyre_PClassDescriptor_PScreenSpaceReflectionD3D11_Ctor_C | 0x27 | true |
| 993 | 0x552e50 | Phyre_PClassDescriptor_PScriptableComponent_ScalarDeletingDtor | 0x27 | true |
| 994 | 0x552e80 | Phyre_PClassDescriptor_PScriptableComponent_ScalarDeletingDtor_B | 0x27 | true |
| 995 | 0x49bea0 | Phyre_PClassDescriptor_PShape_Setup | 0x17 | true |
| 996 | 0x445410 | Phyre_PClassDescriptor_PString_Destructor | 0xb | true |
| 997 | 0x445420 | Phyre_PClassDescriptor_PString_Destructor_dup | 0xb | true |
| 998 | 0x49bf10 | Phyre_PClassDescriptor_PUByte_Setup | 0x1b | true |
| 999 | 0x49c010 | Phyre_PClassDescriptor_PUByte_Traverse | 0x3a | true |
| 1000 | 0x49be80 | Phyre_PClassDescriptor_PUByteArray_Setup | 0x17 | true |
| 1001 | 0x61a390 | Phyre_PClassDescriptor_PushObject_CC9A40_direct | 0x1a | true |
| 1002 | 0x61a350 | Phyre_PClassDescriptor_PushObject_CC9A40_nilcheck | 0x3a | true |
| 1003 | 0xa32310 | Phyre_PClassDescriptor_PushObjectToStream | 0x1a | true |
| 1004 | 0x52c920 | Phyre_PClassDescriptor_PushPArrayAnimDataSource_ToStream | 0x8b | true |
| 1005 | 0x43d3e0 | Phyre_PClassDescriptor_PushToStream | 0x3d | true |
| 1006 | 0x4b1f80 | Phyre_PClassDescriptor_PushToStream_C9CA40 | 0x1a | true |
| 1007 | 0x43d420 | Phyre_PClassDescriptor_PushToStreamAlt | 0x26 | true |
| 1008 | 0x4fcb80 | Phyre_PClassDescriptor_PushToStreamSize81 | 0x3d | true |
| 1009 | 0x4fab40 | Phyre_PClassDescriptor_PushToStreamSize87 | 0x3d | true |
| 1010 | 0x6755d0 | Phyre_PClassDescriptor_RadialLineInstance_ctor | 0x90 | true |
| 1011 | 0x675fc0 | Phyre_PClassDescriptor_RadialLineMesh_ctor | 0x90 | true |
| 1012 | 0xa0ea70 | Phyre_PClassDescriptor_Register_1943718 | 0x17 | true |
| 1013 | 0xa0eaa0 | Phyre_PClassDescriptor_Register_19437B0 | 0x17 | true |
| 1014 | 0xa0eac0 | Phyre_PClassDescriptor_Register_19438E0 | 0x17 | true |
| 1015 | 0xa0eaf0 | Phyre_PClassDescriptor_Register_1943978 | 0x17 | true |
| 1016 | 0xa0ece0 | Phyre_PClassDescriptor_Register_1943AA8 | 0x17 | true |
| 1017 | 0xa0ed10 | Phyre_PClassDescriptor_Register_1943B40 | 0x17 | true |
| 1018 | 0xa0ed70 | Phyre_PClassDescriptor_Register_1943BD8 | 0x17 | true |
| 1019 | 0xa0ed50 | Phyre_PClassDescriptor_Register_1943C70 | 0x17 | true |
| 1020 | 0xa0ed90 | Phyre_PClassDescriptor_Register_1943D08 | 0x17 | true |
| 1021 | 0xa0ec80 | Phyre_PClassDescriptor_Register_1943DF0 | 0x17 | true |
| 1022 | 0xa0ec60 | Phyre_PClassDescriptor_Register_1943E88 | 0x17 | true |
| 1023 | 0xa0eca0 | Phyre_PClassDescriptor_Register_1943F20 | 0x17 | true |
| 1024 | 0xa0ecc0 | Phyre_PClassDescriptor_Register_1943FB8 | 0x17 | true |
| 1025 | 0xa0ebc0 | Phyre_PClassDescriptor_Register_19440E8 | 0x17 | true |
| 1026 | 0xa0eb70 | Phyre_PClassDescriptor_Register_1944180 | 0x17 | true |
| 1027 | 0xa0eba0 | Phyre_PClassDescriptor_Register_1944218 | 0x17 | true |
| 1028 | 0xa0ec00 | Phyre_PClassDescriptor_Register_19442B0 | 0x17 | true |
| 1029 | 0xa0ec40 | Phyre_PClassDescriptor_Register_1944348 | 0x17 | true |
| 1030 | 0xa0ebe0 | Phyre_PClassDescriptor_Register_19443E0 | 0x17 | true |
| 1031 | 0xa0ec20 | Phyre_PClassDescriptor_Register_1944478 | 0x17 | true |
| 1032 | 0xa0eb30 | Phyre_PClassDescriptor_Register_1944510 | 0x17 | true |
| 1033 | 0xa0eb10 | Phyre_PClassDescriptor_Register_19445A8 | 0x17 | true |
| 1034 | 0xa0eb50 | Phyre_PClassDescriptor_Register_1944640 | 0x17 | true |
| 1035 | 0xa0edb0 | Phyre_PClassDescriptor_Register_1944770 | 0x17 | true |
| 1036 | 0xa0ede0 | Phyre_PClassDescriptor_Register_1944808 | 0x17 | true |
| 1037 | 0x9e5200 | Phyre_PClassDescriptor_Register_PArrayPInputSource4 | 0x206 | true |
| 1038 | 0x43bf60 | Phyre_PClassDescriptor_RegisterAll | 0x19a | true |
| 1039 | 0x9f51e0 | Phyre_PClassDescriptor_RegisterAllLate | 0x76 | true |
| 1040 | 0x9f5460 | Phyre_PClassDescriptor_RegisterBatch | 0x82 | true |
| 1041 | 0x9f6ed0 | Phyre_PClassDescriptor_RegisterBatch_2 | 0x87 | true |
| 1042 | 0x9f7510 | Phyre_PClassDescriptor_RegisterBatch_3 | 0x87 | true |
| 1043 | 0x9f9330 | Phyre_PClassDescriptor_RegisterBatch_4 | 0x298 | true |
| 1044 | 0x4aff80 | Phyre_PClassDescriptor_RegisterFinalize_C9BD30 | 0x17 | true |
| 1045 | 0x4b0000 | Phyre_PClassDescriptor_RegisterFinalize_C9C748 | 0x17 | true |
| 1046 | 0x4afec0 | Phyre_PClassDescriptor_RegisterFinalize_C9C910 | 0x17 | true |
| 1047 | 0x4afee0 | Phyre_PClassDescriptor_RegisterFinalize_C9C9A8 | 0x17 | true |
| 1048 | 0x4afea0 | Phyre_PClassDescriptor_RegisterFinalize_C9CA40 | 0x17 | true |
| 1049 | 0x9f6700 | Phyre_PClassDescriptor_RegisterSingle | 0x76 | true |
| 1050 | 0x9f67a0 | Phyre_PClassDescriptor_RegisterSingle_B | 0x76 | true |
| 1051 | 0x9f6840 | Phyre_PClassDescriptor_RegisterSingle_C | 0x76 | true |
| 1052 | 0x5f8fe0 | Phyre_PClassDescriptor_ReleaseResource00 | 0x20 | true |
| 1053 | 0x5f9000 | Phyre_PClassDescriptor_ReleaseResource01 | 0x20 | true |
| 1054 | 0x5f90b0 | Phyre_PClassDescriptor_ReleaseResource02 | 0x20 | true |
| 1055 | 0x5f9120 | Phyre_PClassDescriptor_ReleaseResource03 | 0x19 | true |
| 1056 | 0x5f91a0 | Phyre_PClassDescriptor_ReleaseResource04 | 0x20 | true |
| 1057 | 0x5b32c0 | Phyre_PClassDescriptor_Return23 | 0x8 | true |
| 1058 | 0x4ae6c0 | Phyre_PClassDescriptor_Return2_4AE6C0 | 0x6 | true |
| 1059 | 0x4ae6d0 | Phyre_PClassDescriptor_Return2_4AE6D0 | 0x6 | true |
| 1060 | 0x4ae6e0 | Phyre_PClassDescriptor_Return2_4AE6E0 | 0x6 | true |
| 1061 | 0x4ae6f0 | Phyre_PClassDescriptor_Return2_4AE6F0 | 0x6 | true |
| 1062 | 0x4ae700 | Phyre_PClassDescriptor_Return2_4AE700 | 0x6 | true |
| 1063 | 0x4b0c40 | Phyre_PClassDescriptor_ReturnError_4B0C40 | 0x6 | true |
| 1064 | 0x4b0c50 | Phyre_PClassDescriptor_ReturnError_4B0C50 | 0x6 | true |
| 1065 | 0x4b0c60 | Phyre_PClassDescriptor_ReturnError_4B0C60 | 0x6 | true |
| 1066 | 0x4b0c70 | Phyre_PClassDescriptor_ReturnError_4B0C70 | 0x6 | true |
| 1067 | 0x4b0c80 | Phyre_PClassDescriptor_ReturnError_4B0C80 | 0x6 | true |
| 1068 | 0x4b0c90 | Phyre_PClassDescriptor_ReturnError_4B0C90 | 0x6 | true |
| 1069 | 0x4b0ca0 | Phyre_PClassDescriptor_ReturnError_4B0CA0 | 0x6 | true |
| 1070 | 0x4b0cb0 | Phyre_PClassDescriptor_ReturnError_4B0CB0 | 0x6 | true |
| 1071 | 0x4b0cc0 | Phyre_PClassDescriptor_ReturnError_4B0CC0 | 0x6 | true |
| 1072 | 0x4b0cd0 | Phyre_PClassDescriptor_ReturnError_4B0CD0 | 0x6 | true |
| 1073 | 0x4b0ce0 | Phyre_PClassDescriptor_ReturnError_4B0CE0 | 0x6 | true |
| 1074 | 0x4b0cf0 | Phyre_PClassDescriptor_ReturnError_4B0CF0 | 0x6 | true |
| 1075 | 0x4b0d00 | Phyre_PClassDescriptor_ReturnError_4B0D00 | 0x6 | true |
| 1076 | 0x4b0d10 | Phyre_PClassDescriptor_ReturnError_4B0D10 | 0x6 | true |
| 1077 | 0x4b0d20 | Phyre_PClassDescriptor_ReturnError_4B0D20 | 0x6 | true |
| 1078 | 0x4b0d30 | Phyre_PClassDescriptor_ReturnError_4B0D30 | 0x6 | true |
| 1079 | 0x4b0d40 | Phyre_PClassDescriptor_ReturnError_4B0D40 | 0x6 | true |
| 1080 | 0x4b0d50 | Phyre_PClassDescriptor_ReturnError_4B0D50 | 0x6 | true |
| 1081 | 0x4b0d60 | Phyre_PClassDescriptor_ReturnError_4B0D60 | 0x6 | true |
| 1082 | 0x4b0d70 | Phyre_PClassDescriptor_ReturnError_4B0D70 | 0x6 | true |
| 1083 | 0x4b0d80 | Phyre_PClassDescriptor_ReturnError_4B0D80 | 0x6 | true |
| 1084 | 0x4b0d90 | Phyre_PClassDescriptor_ReturnError_4B0D90 | 0x6 | true |
| 1085 | 0x4b0da0 | Phyre_PClassDescriptor_ReturnError_4B0DA0 | 0x6 | true |
| 1086 | 0x4b0db0 | Phyre_PClassDescriptor_ReturnError_4B0DB0 | 0x6 | true |
| 1087 | 0x4b0dc0 | Phyre_PClassDescriptor_ReturnError_4B0DC0 | 0x6 | true |
| 1088 | 0x5ae900 | Phyre_PClassDescriptor_ReturnMinus1 | 0x6 | true |
| 1089 | 0x5ae910 | Phyre_PClassDescriptor_ReturnMinus1_1 | 0x6 | true |
| 1090 | 0x5ae920 | Phyre_PClassDescriptor_ReturnMinus1_2 | 0x6 | true |
| 1091 | 0x5ae930 | Phyre_PClassDescriptor_ReturnMinus1_3 | 0x6 | true |
| 1092 | 0x5ae940 | Phyre_PClassDescriptor_ReturnMinus1_4 | 0x6 | true |
| 1093 | 0x5fd0c0 | Phyre_PClassDescriptor_ReturnMinusOne | 0x6 | true |
| 1094 | 0x5fd150 | Phyre_PClassDescriptor_ReturnMinusOne_v10 | 0x6 | true |
| 1095 | 0x5fd160 | Phyre_PClassDescriptor_ReturnMinusOne_v11 | 0x6 | true |
| 1096 | 0x5fd170 | Phyre_PClassDescriptor_ReturnMinusOne_v12 | 0x6 | true |
| 1097 | 0x5fd180 | Phyre_PClassDescriptor_ReturnMinusOne_v13 | 0x6 | true |
| 1098 | 0x5fd190 | Phyre_PClassDescriptor_ReturnMinusOne_v14 | 0x6 | true |
| 1099 | 0x5fd1a0 | Phyre_PClassDescriptor_ReturnMinusOne_v15 | 0x6 | true |
| 1100 | 0x5fd1b0 | Phyre_PClassDescriptor_ReturnMinusOne_v16 | 0x6 | true |
| 1101 | 0x5fd1c0 | Phyre_PClassDescriptor_ReturnMinusOne_v17 | 0x6 | true |
| 1102 | 0x5fd1d0 | Phyre_PClassDescriptor_ReturnMinusOne_v18 | 0x6 | true |
| 1103 | 0x5fd1e0 | Phyre_PClassDescriptor_ReturnMinusOne_v19 | 0x6 | true |
| 1104 | 0x5fd0d0 | Phyre_PClassDescriptor_ReturnMinusOne_v2 | 0x6 | true |
| 1105 | 0x5fd1f0 | Phyre_PClassDescriptor_ReturnMinusOne_v20 | 0x6 | true |
| 1106 | 0x5fd200 | Phyre_PClassDescriptor_ReturnMinusOne_v21 | 0x6 | true |
| 1107 | 0x5fd210 | Phyre_PClassDescriptor_ReturnMinusOne_v22 | 0x6 | true |
| 1108 | 0x5fd220 | Phyre_PClassDescriptor_ReturnMinusOne_v23 | 0x6 | true |
| 1109 | 0x5fd230 | Phyre_PClassDescriptor_ReturnMinusOne_v24 | 0x6 | true |
| 1110 | 0x5fd240 | Phyre_PClassDescriptor_ReturnMinusOne_v25 | 0x6 | true |
| 1111 | 0x5fd250 | Phyre_PClassDescriptor_ReturnMinusOne_v26 | 0x6 | true |
| 1112 | 0x5fd260 | Phyre_PClassDescriptor_ReturnMinusOne_v27 | 0x6 | true |
| 1113 | 0x5fd270 | Phyre_PClassDescriptor_ReturnMinusOne_v28 | 0x6 | true |
| 1114 | 0x5fd280 | Phyre_PClassDescriptor_ReturnMinusOne_v29 | 0x6 | true |
| 1115 | 0x5fd0e0 | Phyre_PClassDescriptor_ReturnMinusOne_v3 | 0x6 | true |
| 1116 | 0x5fd290 | Phyre_PClassDescriptor_ReturnMinusOne_v30 | 0x6 | true |
| 1117 | 0x5fd2a0 | Phyre_PClassDescriptor_ReturnMinusOne_v31 | 0x6 | true |
| 1118 | 0x5fd2b0 | Phyre_PClassDescriptor_ReturnMinusOne_v32 | 0x6 | true |
| 1119 | 0x5fd2c0 | Phyre_PClassDescriptor_ReturnMinusOne_v33 | 0x6 | true |
| 1120 | 0x5fd2d0 | Phyre_PClassDescriptor_ReturnMinusOne_v34 | 0x6 | true |
| 1121 | 0x5fd2e0 | Phyre_PClassDescriptor_ReturnMinusOne_v35 | 0x6 | true |
| 1122 | 0x5fd2f0 | Phyre_PClassDescriptor_ReturnMinusOne_v36 | 0x6 | true |
| 1123 | 0x5fd300 | Phyre_PClassDescriptor_ReturnMinusOne_v37 | 0x6 | true |
| 1124 | 0x5fd310 | Phyre_PClassDescriptor_ReturnMinusOne_v38 | 0x6 | true |
| 1125 | 0x5fd320 | Phyre_PClassDescriptor_ReturnMinusOne_v39 | 0x6 | true |
| 1126 | 0x5fd0f0 | Phyre_PClassDescriptor_ReturnMinusOne_v4 | 0x6 | true |
| 1127 | 0x5fd330 | Phyre_PClassDescriptor_ReturnMinusOne_v40 | 0x6 | true |
| 1128 | 0x5fd340 | Phyre_PClassDescriptor_ReturnMinusOne_v41 | 0x6 | true |
| 1129 | 0x5fd4a0 | Phyre_PClassDescriptor_ReturnMinusOne_v42 | 0x6 | true |
| 1130 | 0x5fd4b0 | Phyre_PClassDescriptor_ReturnMinusOne_v43 | 0x6 | true |
| 1131 | 0x5fd4f0 | Phyre_PClassDescriptor_ReturnMinusOne_v44 | 0x6 | true |
| 1132 | 0x5fd500 | Phyre_PClassDescriptor_ReturnMinusOne_v45 | 0x6 | true |
| 1133 | 0x5fd510 | Phyre_PClassDescriptor_ReturnMinusOne_v46 | 0x6 | true |
| 1134 | 0x5fd540 | Phyre_PClassDescriptor_ReturnMinusOne_v47 | 0x6 | true |
| 1135 | 0x5fe220 | Phyre_PClassDescriptor_ReturnMinusOne_v48 | 0x6 | true |
| 1136 | 0x5fe230 | Phyre_PClassDescriptor_ReturnMinusOne_v49 | 0x6 | true |
| 1137 | 0x5fd100 | Phyre_PClassDescriptor_ReturnMinusOne_v5 | 0x6 | true |
| 1138 | 0x5fe240 | Phyre_PClassDescriptor_ReturnMinusOne_v50 | 0x6 | true |
| 1139 | 0x5fe250 | Phyre_PClassDescriptor_ReturnMinusOne_v51 | 0x6 | true |
| 1140 | 0x5fe260 | Phyre_PClassDescriptor_ReturnMinusOne_v52 | 0x6 | true |
| 1141 | 0x5fd110 | Phyre_PClassDescriptor_ReturnMinusOne_v6 | 0x6 | true |
| 1142 | 0x5fd120 | Phyre_PClassDescriptor_ReturnMinusOne_v7 | 0x6 | true |
| 1143 | 0x5fd130 | Phyre_PClassDescriptor_ReturnMinusOne_v8 | 0x6 | true |
| 1144 | 0x5fd140 | Phyre_PClassDescriptor_ReturnMinusOne_v9 | 0x6 | true |
| 1145 | 0x510270 | Phyre_PClassDescriptor_ReturnThis | 0x3 | true |
| 1146 | 0x510280 | Phyre_PClassDescriptor_ReturnThis_2 | 0x3 | true |
| 1147 | 0x510290 | Phyre_PClassDescriptor_ReturnThis_3 | 0x3 | true |
| 1148 | 0x43bd40 | Phyre_PClassDescriptor_ReturnTwo | 0x6 | true |
| 1149 | 0x5fbc90 | Phyre_PClassDescriptor_ReturnZero | 0x5 | true |
| 1150 | 0x43cb30 | Phyre_PClassDescriptor_ReturnZero_stdcall | 0x5 | true |
| 1151 | 0x5fbd20 | Phyre_PClassDescriptor_ReturnZero_v10 | 0x5 | true |
| 1152 | 0x5fbd30 | Phyre_PClassDescriptor_ReturnZero_v11 | 0x5 | true |
| 1153 | 0x5fbd40 | Phyre_PClassDescriptor_ReturnZero_v12 | 0x5 | true |
| 1154 | 0x5fbd50 | Phyre_PClassDescriptor_ReturnZero_v13 | 0x5 | true |
| 1155 | 0x5fbd60 | Phyre_PClassDescriptor_ReturnZero_v14 | 0x5 | true |
| 1156 | 0x5fbd70 | Phyre_PClassDescriptor_ReturnZero_v15 | 0x5 | true |
| 1157 | 0x5fbd80 | Phyre_PClassDescriptor_ReturnZero_v16 | 0x5 | true |
| 1158 | 0x5fbd90 | Phyre_PClassDescriptor_ReturnZero_v17 | 0x5 | true |
| 1159 | 0x5fbda0 | Phyre_PClassDescriptor_ReturnZero_v18 | 0x5 | true |
| 1160 | 0x5fbdb0 | Phyre_PClassDescriptor_ReturnZero_v19 | 0x5 | true |
| 1161 | 0x5fbca0 | Phyre_PClassDescriptor_ReturnZero_v2 | 0x5 | true |
| 1162 | 0x5fbdc0 | Phyre_PClassDescriptor_ReturnZero_v20 | 0x5 | true |
| 1163 | 0x5fbdd0 | Phyre_PClassDescriptor_ReturnZero_v21 | 0x5 | true |
| 1164 | 0x5fbde0 | Phyre_PClassDescriptor_ReturnZero_v22 | 0x5 | true |
| 1165 | 0x5fbdf0 | Phyre_PClassDescriptor_ReturnZero_v23 | 0x5 | true |
| 1166 | 0x5fbe00 | Phyre_PClassDescriptor_ReturnZero_v24 | 0x5 | true |
| 1167 | 0x5fbe10 | Phyre_PClassDescriptor_ReturnZero_v25 | 0x5 | true |
| 1168 | 0x5fbe20 | Phyre_PClassDescriptor_ReturnZero_v26 | 0x5 | true |
| 1169 | 0x5fbe30 | Phyre_PClassDescriptor_ReturnZero_v27 | 0x5 | true |
| 1170 | 0x5fbe40 | Phyre_PClassDescriptor_ReturnZero_v28 | 0x5 | true |
| 1171 | 0x5fbe50 | Phyre_PClassDescriptor_ReturnZero_v29 | 0x5 | true |
| 1172 | 0x5fbcb0 | Phyre_PClassDescriptor_ReturnZero_v3 | 0x5 | true |
| 1173 | 0x5fbe60 | Phyre_PClassDescriptor_ReturnZero_v30 | 0x5 | true |
| 1174 | 0x5fbe70 | Phyre_PClassDescriptor_ReturnZero_v31 | 0x5 | true |
| 1175 | 0x5fbe80 | Phyre_PClassDescriptor_ReturnZero_v32 | 0x5 | true |
| 1176 | 0x5fbe90 | Phyre_PClassDescriptor_ReturnZero_v33 | 0x5 | true |
| 1177 | 0x5fbea0 | Phyre_PClassDescriptor_ReturnZero_v34 | 0x5 | true |
| 1178 | 0x5fbeb0 | Phyre_PClassDescriptor_ReturnZero_v35 | 0x5 | true |
| 1179 | 0x5fbec0 | Phyre_PClassDescriptor_ReturnZero_v36 | 0x5 | true |
| 1180 | 0x5fbed0 | Phyre_PClassDescriptor_ReturnZero_v37 | 0x5 | true |
| 1181 | 0x5fbf00 | Phyre_PClassDescriptor_ReturnZero_v38 | 0x5 | true |
| 1182 | 0x5fbf10 | Phyre_PClassDescriptor_ReturnZero_v39 | 0x5 | true |
| 1183 | 0x5fbcc0 | Phyre_PClassDescriptor_ReturnZero_v4 | 0x5 | true |
| 1184 | 0x5fbf20 | Phyre_PClassDescriptor_ReturnZero_v40 | 0x5 | true |
| 1185 | 0x5fbcd0 | Phyre_PClassDescriptor_ReturnZero_v5 | 0x5 | true |
| 1186 | 0x5fbce0 | Phyre_PClassDescriptor_ReturnZero_v6 | 0x5 | true |
| 1187 | 0x5fbcf0 | Phyre_PClassDescriptor_ReturnZero_v7 | 0x5 | true |
| 1188 | 0x5fbd00 | Phyre_PClassDescriptor_ReturnZero_v8 | 0x5 | true |
| 1189 | 0x5fbd10 | Phyre_PClassDescriptor_ReturnZero_v9 | 0x5 | true |
| 1190 | 0x4b5b30 | Phyre_PClassDescriptor_scalar_dtor_CapBufLoc | 0x21 | true |
| 1191 | 0x4a92a0 | Phyre_PClassDescriptor_scalar_dtor_PArray_PShaderParameterDefinition_4 | 0x27 | true |
| 1192 | 0x4a92d0 | Phyre_PClassDescriptor_scalar_dtor_PArray_PShaderStreamDefinition_4 | 0x27 | true |
| 1193 | 0x4b5b60 | Phyre_PClassDescriptor_scalar_dtor_PShaderParamCapLoc2 | 0x21 | true |
| 1194 | 0x4a9120 | Phyre_PClassDescriptor_scalar_dtor_PShaderParameterCaptureBufferTextureBase | 0x27 | true |
| 1195 | 0x4a9150 | Phyre_PClassDescriptor_scalar_dtor_PShaderParameterCaptureBufferTextureCubeMap | 0x27 | true |
| 1196 | 0x4a9180 | Phyre_PClassDescriptor_scalar_dtor_PShaderParameterCaptureConstantBuffer | 0x27 | true |
| 1197 | 0x4a91b0 | Phyre_PClassDescriptor_scalar_dtor_PShaderProgramBase | 0x27 | true |
| 1198 | 0x4a91e0 | Phyre_PClassDescriptor_scalar_dtor_PShaderProgramParamsAndStreams | 0x27 | true |
| 1199 | 0x4a9210 | Phyre_PClassDescriptor_scalar_dtor_PShaderSource | 0x27 | true |
| 1200 | 0x4a9240 | Phyre_PClassDescriptor_scalar_dtor_PShaderStreamDefinition | 0x27 | true |
| 1201 | 0x4a9270 | Phyre_PClassDescriptor_scalar_dtor_PShaderVertexProgram | 0x27 | true |
| 1202 | 0x4b5b90 | Phyre_PClassDescriptor_scalar_dtor_ShaderPass | 0x21 | true |
| 1203 | 0x4b5bc0 | Phyre_PClassDescriptor_scalar_dtor_ShaderPassState | 0x21 | true |
| 1204 | 0x4b5bf0 | Phyre_PClassDescriptor_scalar_dtor_ShaderPassStateBase | 0x21 | true |
| 1205 | 0x52f890 | Phyre_PClassDescriptor_ScriptAccessor_AdditiveBlenderControllerPtrGet | 0x17 | true |
| 1206 | 0x52f910 | Phyre_PClassDescriptor_ScriptAccessor_AdditiveBlenderRefGet_AndCopy | 0x1b | true |
| 1207 | 0x52cd40 | Phyre_PClassDescriptor_ScriptAccessor_ChannelSetKeyframe | 0x17 | true |
| 1208 | 0x52cd60 | Phyre_PClassDescriptor_ScriptAccessor_GetWeight | 0x17 | true |
| 1209 | 0x52a750 | Phyre_PClassDescriptor_ScriptAccessor_PAnimationHierarchyNode_CalcSize | 0x1b | true |
| 1210 | 0x52a770 | Phyre_PClassDescriptor_ScriptAccessor_PAnimationHierarchyNode_GetClassDesc | 0x1b | true |
| 1211 | 0x52a5f0 | Phyre_PClassDescriptor_ScriptAccessor_PAnimationSlotFilterDeferredLoadPtr_Get | 0x17 | true |
| 1212 | 0x52a930 | Phyre_PClassDescriptor_ScriptAccessor_PushArraySlotFilterDeferredLoadDescToStream | 0x15 | true |
| 1213 | 0x52a910 | Phyre_PClassDescriptor_ScriptAccessor_PushArrayUIntDescToStream | 0x15 | true |
| 1214 | 0x52ce90 | Phyre_PClassDescriptor_ScriptAccessor_PushObjectOrNilToStream | 0x3d | true |
| 1215 | 0x52cef0 | Phyre_PClassDescriptor_ScriptAccessor_PushObjectOrNilToStream_A | 0x26 | true |
| 1216 | 0x52e630 | Phyre_PClassDescriptor_ScriptAccessor_PushObjectOrNilToStream_B | 0x3d | true |
| 1217 | 0x52e670 | Phyre_PClassDescriptor_ScriptAccessor_PushObjectOrNilToStream_C | 0x26 | true |
| 1218 | 0x52fce0 | Phyre_PClassDescriptor_ScriptAccessor_PushObjectOrNilToStream_D | 0x3d | true |
| 1219 | 0x52fd20 | Phyre_PClassDescriptor_ScriptAccessor_PushObjectOrNilToStream_E | 0x26 | true |
| 1220 | 0x52a980 | Phyre_PClassDescriptor_ScriptAccessor_PushObjectToStream | 0x1a | true |
| 1221 | 0x52ced0 | Phyre_PClassDescriptor_ScriptAccessor_PushPArrayAnimDataSource_ToStream | 0x15 | true |
| 1222 | 0x52a870 | Phyre_PClassDescriptor_ScriptAccessor_PushPArrayToStream | 0x17 | true |
| 1223 | 0x52ce70 | Phyre_PClassDescriptor_ScriptAccessor_PushPArrayToStream_A | 0x17 | true |
| 1224 | 0x52cfa0 | Phyre_PClassDescriptor_ScriptAccessor_SetWeight | 0x20 | true |
| 1225 | 0x5316d0 | Phyre_PClassDescriptor_ScriptAccessor_TargetBlenderControllerPtrGet | 0x17 | true |
| 1226 | 0x52e7e0 | Phyre_PClassDescriptor_ScriptAccessor_TraverseWithFlag | 0x69 | true |
| 1227 | 0x52fe90 | Phyre_PClassDescriptor_ScriptAccessor_TraverseWithFlag_A | 0x69 | true |
| 1228 | 0x52a850 | Phyre_PClassDescriptor_ScriptAccessor_UIntArrayAdd | 0x17 | true |
| 1229 | 0x52a5b0 | Phyre_PClassDescriptor_ScriptAccessor_UIntArraySet | 0x17 | true |
| 1230 | 0x52a590 | Phyre_PClassDescriptor_ScriptAccessor_UIntArraySetElement | 0x17 | true |
| 1231 | 0x52a5d0 | Phyre_PClassDescriptor_ScriptAccessor_UIntPairArraySet | 0x17 | true |
| 1232 | 0x52e390 | Phyre_PClassDescriptor_ScriptAccessor_WeightedBlenderControllerPtrGet | 0x17 | true |
| 1233 | 0x52e420 | Phyre_PClassDescriptor_ScriptAccessor_WeightedBlenderRefGet_AndCopy | 0x1b | true |
| 1234 | 0x43d600 | Phyre_PClassDescriptor_SetField64 | 0xd | true |
| 1235 | 0x43d6a0 | Phyre_PClassDescriptor_SetField68 | 0xd | true |
| 1236 | 0x43d6b0 | Phyre_PClassDescriptor_SetField6C | 0xd | true |
| 1237 | 0x43d680 | Phyre_PClassDescriptor_SetFields74_78 | 0x13 | true |
| 1238 | 0x4449b0 | Phyre_PClassDescriptor_SetFlag | 0x2e | true |
| 1239 | 0x445ee0 | Phyre_PClassDescriptor_SetFlag_2 | 0x2e | true |
| 1240 | 0x446be0 | Phyre_PClassDescriptor_SetFlag_Offset4 | 0x69 | true |
| 1241 | 0x550680 | Phyre_PClassDescriptor_SetProperty | 0x1a | true |
| 1242 | 0x49bdd0 | Phyre_PClassDescriptor_Setup_49BDD0 | 0xd | true |
| 1243 | 0x550600 | Phyre_PClassDescriptor_SetValue | 0x17 | true |
| 1244 | 0x550660 | Phyre_PClassDescriptor_SetValueDirect | 0x15 | true |
| 1245 | 0x550620 | Phyre_PClassDescriptor_SetValueOrReset | 0x3a | true |
| 1246 | 0x49bda0 | Phyre_PClassDescriptor_SimpleInit_49BDA0 | 0x19 | true |
| 1247 | 0x9f2e70 | Phyre_PClassDescriptor_Size11_Getter_A | 0x6 | true |
| 1248 | 0x9f2e80 | Phyre_PClassDescriptor_Size11_Getter_B | 0x6 | true |
| 1249 | 0x9f2e90 | Phyre_PClassDescriptor_Size11_Getter_C | 0x6 | true |
| 1250 | 0x43bcb0 | Phyre_PClassDescriptor_Size16 | 0x6 | true |
| 1251 | 0x565800 | Phyre_PClassDescriptor_SizeCB1C58_Get | 0x6 | true |
| 1252 | 0x5658f0 | Phyre_PClassDescriptor_SizeCB1C58_GetTotalSize | 0xa | true |
| 1253 | 0x565810 | Phyre_PClassDescriptor_SizeCB1CF0_Get | 0x6 | true |
| 1254 | 0x565900 | Phyre_PClassDescriptor_SizeCB1CF0_GetTotalSize | 0xa | true |
| 1255 | 0x5658d0 | Phyre_PClassDescriptor_SizeCB1EB8_GetTotalSize | 0xa | true |
| 1256 | 0x5657f0 | Phyre_PClassDescriptor_SizeCB1F50_Get | 0x6 | true |
| 1257 | 0x5658e0 | Phyre_PClassDescriptor_SizeCB1F50_GetTotalSize | 0xa | true |
| 1258 | 0x51f0e0 | Phyre_PClassDescriptor_SupportsType_AnimationSlotFilter | 0x5 | true |
| 1259 | 0x51f0f0 | Phyre_PClassDescriptor_SupportsType_AnimationSlotFilter_B | 0x5 | true |
| 1260 | 0x51cda0 | Phyre_PClassDescriptor_SupportsType_PAnimationScriptController | 0x5 | true |
| 1261 | 0x500870 | Phyre_PClassDescriptor_SupportsType_RetFalse | 0x5 | true |
| 1262 | 0x511230 | Phyre_PClassDescriptor_SupportsType_RetFalse_D | 0x5 | true |
| 1263 | 0x500860 | Phyre_PClassDescriptor_SupportsType_RetTrue | 0x5 | true |
| 1264 | 0x5111f0 | Phyre_PClassDescriptor_SupportsType_RetTrue_B | 0x5 | true |
| 1265 | 0x511200 | Phyre_PClassDescriptor_SupportsType_RetTrue_C | 0x5 | true |
| 1266 | 0x511240 | Phyre_PClassDescriptor_SupportsType_RetTrue_D | 0x5 | true |
| 1267 | 0x511250 | Phyre_PClassDescriptor_SupportsType_RetTrue_E | 0x5 | true |
| 1268 | 0x511260 | Phyre_PClassDescriptor_SupportsType_RetTrue_F | 0x5 | true |
| 1269 | 0x51cd80 | Phyre_PClassDescriptor_SupportsType_RetTrue_G | 0x5 | true |
| 1270 | 0x51cd90 | Phyre_PClassDescriptor_SupportsType_RetTrue_H | 0x5 | true |
| 1271 | 0x633b20 | Phyre_PClassDescriptor_This_Ret_thunk_01 | 0x3 | true |
| 1272 | 0x633b30 | Phyre_PClassDescriptor_This_Ret_thunk_02 | 0x3 | true |
| 1273 | 0x633b40 | Phyre_PClassDescriptor_This_Ret_thunk_03 | 0x3 | true |
| 1274 | 0x633b50 | Phyre_PClassDescriptor_This_Ret_thunk_04 | 0x3 | true |
| 1275 | 0x633b60 | Phyre_PClassDescriptor_This_Ret_thunk_05 | 0x3 | true |
| 1276 | 0x633b70 | Phyre_PClassDescriptor_This_Ret_thunk_06 | 0x3 | true |
| 1277 | 0x633b80 | Phyre_PClassDescriptor_This_Ret_thunk_07 | 0x3 | true |
| 1278 | 0x633b90 | Phyre_PClassDescriptor_This_Ret_thunk_08 | 0x3 | true |
| 1279 | 0x633ba0 | Phyre_PClassDescriptor_This_Ret_thunk_09 | 0x3 | true |
| 1280 | 0x633bb0 | Phyre_PClassDescriptor_This_Ret_thunk_10 | 0x3 | true |
| 1281 | 0x633bc0 | Phyre_PClassDescriptor_This_Ret_thunk_11 | 0x3 | true |
| 1282 | 0x633bd0 | Phyre_PClassDescriptor_This_Ret_thunk_12 | 0x3 | true |
| 1283 | 0x633be0 | Phyre_PClassDescriptor_This_Ret_thunk_13 | 0x3 | true |
| 1284 | 0x633bf0 | Phyre_PClassDescriptor_This_Ret_thunk_14 | 0x3 | true |
| 1285 | 0x633c00 | Phyre_PClassDescriptor_This_Ret_thunk_15 | 0x3 | true |
| 1286 | 0x636040 | Phyre_PClassDescriptor_This_Ret_thunk_16 | 0x3 | true |
| 1287 | 0x636050 | Phyre_PClassDescriptor_This_Ret_thunk_17 | 0x3 | true |
| 1288 | 0x636060 | Phyre_PClassDescriptor_This_Ret_thunk_18 | 0x3 | true |
| 1289 | 0x6361d0 | Phyre_PClassDescriptor_This_Ret_thunk_19 | 0x3 | true |
| 1290 | 0x6361e0 | Phyre_PClassDescriptor_This_Ret_thunk_20 | 0x3 | true |
| 1291 | 0x43d6c0 | Phyre_PClassDescriptor_Traverse | 0x7d | true |
| 1292 | 0x544530 | Phyre_PClassDescriptor_Traverse_PAnimatableComponent | 0x2e | true |
| 1293 | 0x544490 | Phyre_PClassDescriptor_Traverse_PAnimationDataSrcBuffer | 0x28 | true |
| 1294 | 0x52ae80 | Phyre_PClassDescriptor_Traverse_PAnimChannel_DataOrWeight | 0x28 | true |
| 1295 | 0x52aeb0 | Phyre_PClassDescriptor_Traverse_PAnimChannel_FlagsOrBlend | 0x28 | true |
| 1296 | 0x52b570 | Phyre_PClassDescriptor_Traverse_PArrayAnimDataSource_Flag0 | 0x87 | true |
| 1297 | 0x52b4b0 | Phyre_PClassDescriptor_Traverse_PArrayAnimDataSource_Flag1 | 0x87 | true |
| 1298 | 0x52aee0 | Phyre_PClassDescriptor_Traverse_PArrayAnimDataSrc | 0x69 | true |
| 1299 | 0x52d220 | Phyre_PClassDescriptor_Traverse_PArrayAnimDataSrc_V2 | 0x28 | true |
| 1300 | 0x52d250 | Phyre_PClassDescriptor_Traverse_PArrayAnimDataSrc_WithOffset | 0x69 | true |
| 1301 | 0x5cb0e0 | Phyre_PClassDescriptor_Traverse_PArrayFloat4 | 0x87 | true |
| 1302 | 0x52af50 | Phyre_PClassDescriptor_Traverse_PArrayFloat4_B | 0x2e | true |
| 1303 | 0x5cb190 | Phyre_PClassDescriptor_Traverse_PArrayFloat4_v2 | 0x87 | true |
| 1304 | 0x5d44a0 | Phyre_PClassDescriptor_Traverse_PArrayU8 | 0x87 | true |
| 1305 | 0x5c7f20 | Phyre_PClassDescriptor_Traverse_PModifierAndInputs | 0x2e | true |
| 1306 | 0x5c7f50 | Phyre_PClassDescriptor_Traverse_PModifierNetwork | 0x2e | true |
| 1307 | 0x5c7f80 | Phyre_PClassDescriptor_Traverse_PModifierNetworkBuffer | 0x2e | true |
| 1308 | 0x5c7fb0 | Phyre_PClassDescriptor_Traverse_PModifierNetworkInfoPacket | 0x2e | true |
| 1309 | 0x5c7fe0 | Phyre_PClassDescriptor_Traverse_PModifierNetworkInfoPacketBuffer | 0x2e | true |
| 1310 | 0x5c8010 | Phyre_PClassDescriptor_Traverse_PModifierNetworkInfoPacketModifierCode | 0x2e | true |
| 1311 | 0x5c8040 | Phyre_PClassDescriptor_Traverse_PModifierNetworkInfoPacketModifierInstance | 0x2e | true |
| 1312 | 0x5c8070 | Phyre_PClassDescriptor_Traverse_PRenderStream | 0x2e | true |
| 1313 | 0x552ae0 | Phyre_PClassDescriptor_Traverse_PScriptableComponent | 0x2e | true |
| 1314 | 0x54cd10 | Phyre_PClassDescriptor_Traverse_PSpline | 0x69 | true |
| 1315 | 0x618180 | Phyre_PClassDescriptor_TraverseGlobal | 0x2e | true |
| 1316 | 0x43ac50 | Phyre_PClassDescriptor_TraversePropertyList | 0x4c | true |
| 1317 | 0x43ae00 | Phyre_PClassDescriptor_TraversePropertyList_V2 | 0x4c | true |
| 1318 | 0xa427e0 | Phyre_PClassDescriptor_TraverseSize78_Flagged | 0x2e | true |
| 1319 | 0x4fce60 | Phyre_PClassDescriptor_TraverseSize81 | 0x69 | true |
| 1320 | 0x4fabb0 | Phyre_PClassDescriptor_TraverseSize87 | 0x69 | true |
| 1321 | 0x43d790 | Phyre_PClassDescriptor_TraverseWithFlag | 0x3d | true |
| 1322 | 0x9f01d0 | Phyre_PClassDescriptor_TraverseWithFlag_dword1940EF8_Stub | 0x69 | true |
| 1323 | 0x9f0160 | Phyre_PClassDescriptor_TraverseWithFlag_dword1940F90_Stub | 0x69 | true |
| 1324 | 0x9f0080 | Phyre_PClassDescriptor_TraverseWithFlag_dword1941028_Stub | 0x69 | true |
| 1325 | 0x9f00f0 | Phyre_PClassDescriptor_TraverseWithFlag_dword19410C0_Stub | 0x69 | true |
| 1326 | 0x9f0240 | Phyre_PClassDescriptor_TraverseWithFlag_dword1941158_Stub | 0x69 | true |
| 1327 | 0x9f02b0 | Phyre_PClassDescriptor_TraverseWithFlag_dword19411F0_Stub | 0x69 | true |
| 1328 | 0x59c240 | Phyre_PClassDescriptor_TraverseWithFlag_dword_CB39A0 | 0x2e | true |
| 1329 | 0x59c270 | Phyre_PClassDescriptor_TraverseWithFlag_dword_CB3A38 | 0x2e | true |
| 1330 | 0x59c2a0 | Phyre_PClassDescriptor_TraverseWithFlag_dword_CB3AD0 | 0x2e | true |
| 1331 | 0x59c210 | Phyre_PClassDescriptor_TraverseWithFlag_dword_CB3CB0 | 0x2e | true |
| 1332 | 0x5c7e90 | Phyre_PClassDescriptor_TraverseWithFlag_PModifierAndInputs | 0x28 | true |
| 1333 | 0x5c7ec0 | Phyre_PClassDescriptor_TraverseWithFlag_PModifierNetworkBuffer | 0x28 | true |
| 1334 | 0x5c7ef0 | Phyre_PClassDescriptor_TraverseWithFlag_PRenderStreamInput | 0x28 | true |
| 1335 | 0x59c150 | Phyre_PClassDescriptor_TraverseWithFlag_Size101 | 0x2e | true |
| 1336 | 0x59c180 | Phyre_PClassDescriptor_TraverseWithFlag_Size102 | 0x2e | true |
| 1337 | 0x59c1b0 | Phyre_PClassDescriptor_TraverseWithFlag_Size103 | 0x2e | true |
| 1338 | 0x59c090 | Phyre_PClassDescriptor_TraverseWithFlag_Size112 | 0x2e | true |
| 1339 | 0x59c0c0 | Phyre_PClassDescriptor_TraverseWithFlag_Size113 | 0x2e | true |
| 1340 | 0x59c060 | Phyre_PClassDescriptor_TraverseWithFlag_Size114 | 0x2e | true |
| 1341 | 0x59c120 | Phyre_PClassDescriptor_TraverseWithFlag_Size94 | 0x2e | true |
| 1342 | 0x59c1e0 | Phyre_PClassDescriptor_TraverseWithFlag_Size95 | 0x2e | true |
| 1343 | 0x9f0010 | Phyre_PClassDescriptor_TraverseWithFlag_Size95_Stub | 0x69 | true |
| 1344 | 0x5c80a0 | Phyre_PClassDescriptor_TraverseWithFlag_Size_55 | 0x2e | true |
| 1345 | 0x5cbdd0 | Phyre_PClassDescriptor_TraverseWithFlag_Size_56 | 0x2e | true |
| 1346 | 0x59c0f0 | Phyre_PClassDescriptor_TraverseWithFlag_Size_60 | 0x2e | true |
| 1347 | 0x5646a0 | Phyre_PClassDescriptor_TraverseWithFlag_Thunk | 0x2e | true |
| 1348 | 0x49c460 | Phyre_PClassDescriptor_TraverseWithFlag_UsingSize57 | 0x2e | true |
| 1349 | 0x61a430 | Phyre_PClassDescriptor_TraverseWithFlag_w | 0x2e | true |
| 1350 | 0x44cc60 | Phyre_PClassDescriptor_TraverseWithFlag_Wrapper | 0x2e | true |
| 1351 | 0x44e2f0 | Phyre_PClassDescriptor_TraverseWithFlag_Wrapper2 | 0x2e | true |
| 1352 | 0xa32330 | Phyre_PClassDescriptor_TraverseWithFlagWrap | 0x2e | true |
| 1353 | 0xa348c0 | Phyre_PClassDescriptor_TraverseWrapper | 0x2e | true |
| 1354 | 0x5f8890 | Phyre_PClassDescriptor_TrivialDtor | 0x5 | true |
| 1355 | 0x5f8b70 | Phyre_PClassDescriptor_TrivialDtor_v2 | 0x5 | true |
| 1356 | 0x5f8bd0 | Phyre_PClassDescriptor_TrivialDtor_v3 | 0x5 | true |
| 1357 | 0x5f8fa0 | Phyre_PClassDescriptor_TrivialDtor_v4 | 0x5 | true |
| 1358 | 0x5f8fd0 | Phyre_PClassDescriptor_TrivialDtor_v5 | 0x5 | true |
| 1359 | 0x43d510 | Phyre_PClassDescriptor_Unregister | 0x18 | true |
| 1360 | 0x445f10 | Phyre_PClassDescriptor_ValidateAndAlloc | 0x4b | true |
| 1361 | 0x450040 | Phyre_PClassDescriptor_ValidateInheritance | 0x68 | true |
| 1362 | 0x511c00 | Phyre_PClassDescriptor_VtableDispatch_Slot37 | 0x18 | true |
| 1363 | 0x4494e0 | Phyre_PClassDescriptor_ZeroOut2 | 0x1d | true |
| 1364 | 0x445ab0 | Phyre_PClassDescriptor_ZeroOutPtr | 0x16 | true |