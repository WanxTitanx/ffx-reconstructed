// Function: IsProcessorFeaturePresent
// Address: 0xa8d6ca
// Size: 0x6
// Prototype: BOOL __stdcall(DWORD ProcessorFeature)

// attributes: thunk
BOOL __stdcall IsProcessorFeaturePresent(DWORD ProcessorFeature)
{
  return __imp_IsProcessorFeaturePresent(ProcessorFeature);
}

