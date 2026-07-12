// Function: FFX_MagicCoreOp_5A_RecordFieldScaleWrite
// Address: 0x81b5e0
// [Jarvis naming goal 2026-06-17 pass2] Magic core opcode 0x5A: writes record fields +0xA0/+0xA2/+0xBA and scales/copies vec3 fields depending on mode.
int __cdecl FFX_MagicCoreOp_5A_RecordFieldScaleWrite(int a1, int a2)
{
  int v2; // ecx
  unsigned __int8 n8; // al
  bool v4; // zf
  int result; // eax

  v2 = *(_DWORD *)(a1 + 544);
  *(_BYTE *)(v2 + 186) = *(_BYTE *)(a2 + 2);
  *(_WORD *)(v2 + 160) = *(_WORD *)(a2 + 4);
  *(_WORD *)(v2 + 162) = *(_WORD *)(a2 + 6);
  n8 = *(_BYTE *)(v2 + 186);
  if ( n8 < 8u )
    return a2 + 8;
  if ( n8 <= 9u )
  {
    *(float *)(v2 + 64) = *(float *)(v2 + 144) * 16.0;
    *(float *)(v2 + 68) = *(float *)(v2 + 148) * 16.0;
    *(float *)(v2 + 72) = 16.0 * *(float *)(v2 + 152);
    return a2 + 8;
  }
  v4 = n8 == 11;
  result = a2 + 8;
  if ( v4 )
  {
    *(float *)(v2 + 164) = *(float *)(v2 + 144);
    *(float *)(v2 + 68) = *(float *)(v2 + 148);
    *(float *)(v2 + 72) = *(float *)(v2 + 152);
  }
  return result;
}
