// Function: FFX_MagicCoreOp_1E_SetRecordParamByte
// Address: 0x817440
// Jarvis-HEAVY H06: Magic VM op 0x1E. Writes one byte into active record at record+0xB4+(opcode high nibble). Parameter byte/timing/index style, not direct RGBA except indirectly selecting record field.
int __cdecl FFX_MagicCoreOp_1E_SetRecordParamByte(int a1, int a2)
{
  int v3; // edi
  __int16 v4; // dx
  unsigned int n1024; // ecx
  __int16 v6; // bx
  __int16 v7; // ax
  __int16 v9; // cx
  __int16 v10; // [esp+14h] [ebp-4h]
  float v11; // [esp+20h] [ebp+8h]
  __int16 v12; // [esp+24h] [ebp+Ch]

  v3 = *(_DWORD *)(a1 + 544);
  v4 = *(_WORD *)(a2 + 2);
  n1024 = *(_WORD *)(a1 + 538) & 0xE00;
  v12 = v4;
  v6 = *(_WORD *)(a1 + 538) >> 12;
  if ( n1024 <= 0x400 )
  {
    if ( n1024 == 1024 )
    {
      *(_BYTE *)(v6 + v3 + 180) = v4 + sub_7E5C60(*(__int16 *)(a2 + 4));
      return a2 + 6;
    }
    if ( (*(_WORD *)(a1 + 538) & 0xE00) == 0 )
    {
      *(_BYTE *)(v6 + v3 + 180) = v4;
      return a2 + 4;
    }
    if ( n1024 == 512 )
    {
      v7 = sub_79A690(
             *((_DWORD *)&unk_12A40C0 + 8 * *(unsigned __int16 *)(v3 + 20)),
             *(unsigned __int8 *)(v3 + 24),
             0,
             0,
             0);
      *(_BYTE *)(v6 + v3 + 180) = v7;
      if ( !v7 )
        return a2 + v12;
      return a2 + 4;
    }
    return a2;
  }
  if ( n1024 == 1536 )
  {
    *(_BYTE *)(v6 + v3 + 180) = (int)*(float *)(v4 + v3);
    return a2 + 4;
  }
  if ( n1024 != 2048 )
    return a2;
  v10 = *(_WORD *)(a2 + 4);
  v11 = sub_800B30(*(unsigned __int8 *)(v3 + 24), *(char *)(a1 + 542)) * (double)v4;
  v9 = (int)v11;
  if ( v9 > v10 )
    v9 = v10;
  if ( v9 <= 0 )
    LOBYTE(v9) = 1;
  *(_BYTE *)(v6 + v3 + 180) = v9;
  return a2 + 6;
}
