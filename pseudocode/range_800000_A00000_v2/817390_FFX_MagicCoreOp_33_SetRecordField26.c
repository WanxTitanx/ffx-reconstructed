// Function: FFX_MagicCoreOp_33_SetRecordField26
// Address: 0x817390
// Jarvis-HEAVY H06: Magic VM op 0x33. Writes word immediate to active record+0x1A. Field26 setter; color link unproved.
int __cdecl FFX_MagicCoreOp_33_SetRecordField26(int a1, int a2)
{
  *(_WORD *)(*(_DWORD *)(a1 + 544) + 26) = *(_WORD *)(a2 + 2);
  return a2 + 4;
}
