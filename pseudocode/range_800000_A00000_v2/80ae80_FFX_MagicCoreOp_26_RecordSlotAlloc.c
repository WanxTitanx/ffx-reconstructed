// Function: FFX_MagicCoreOp_26_RecordSlotAlloc
// Address: 0x80ae80
int __cdecl FFX_MagicCoreOp_26_RecordSlotAlloc(int a1, int a2)
{
  int v2; // ebx
  int v3; // ecx
  unsigned __int8 v4; // bl
  unsigned int v6; // [esp+4h] [ebp-4h]
  int v7; // [esp+10h] [ebp+8h]

  v2 = *(unsigned __int16 *)(a1 + 538);
  v3 = *(_DWORD *)(a1 + 544);
  v7 = v3;
  v6 = ((__int16)v2 & 0xFFFF8000) << 16;
  v4 = (v2 >> 12) & 3;
  if ( !v4 )
  {
    v4 = 1;
    while ( !sub_A446A0(*(_DWORD *)(v3 + 4 * v4)) )
    {
      v3 = v7;
      if ( ++v4 >= 4u )
        return a2 + 4;
    }
  }
  *(_DWORD *)(v7 + 4 * v4) = unknown_libname_742(a2 + *(__int16 *)(a2 + 2));
  *(_BYTE *)(v7 + 31) |= ((v6 == 0x80000000) << v4) & 0xF;
  *(_BYTE *)(v4 + v7 + 16) = 0;
  return a2 + 4;
}
