// [Jarvis naming goal 2026-06-25] Backfilled existing FieldMap encounter poly decoder into durable replay; extracts (polyMeta >> 17) & 0x7FFF when encounter raster gate is active.
// FFX FieldMap: Decode encounter group from poly meta
int __cdecl FFX_FieldMap_DecodeEncounterGroupFromPolyMeta(int a1)
{
  // [Jarvis naming goal 2026-06-17] proved/navigation name from aggressive-honest FFX.exe pass. /*0x83e983*/
  if ( FFX_FieldMap_GetGuidePolyMetaFlag() ) /*0x83e983*/
    return (a1 >> 17) & 0x7FFF; /*0x83e992*/
  else
    return 16912; /*0x83e999*/
}