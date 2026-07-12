// Function: FFX_MagicCoreOp_2F_RecordFlag176Branch
// Address: 0x817930
int __cdecl FFX_MagicCoreOp_2F_RecordFlag176Branch(int a1, int a2)
{
  int v2; // esi
  __int16 v3; // bx
  int v4; // edi

  v2 = a2;
  v3 = *(_WORD *)(a2 + 2);
  v4 = *(_DWORD *)(a1 + 544);
  switch ( (*(__int16 *)(a1 + 538) >> 12) & 7 )
  {
    case 0:
      goto LABEL_12;
    case 1:
      *(_WORD *)(v4 + 176) &= ~v3;
      return a2 + 4;
    case 2:
      if ( (*(unsigned __int16 *)(v4 + 176) & v3) == 0 )
        return a2 + 6;
      return *(__int16 *)(a2 + 4) + a2;
    case 3:
      if ( (*(unsigned __int16 *)(v4 + 176) & v3) != 0 )
        return a2 + 6;
      else
        return *(__int16 *)(a2 + 4) + a2;
    case 4:
      if ( (*(unsigned __int16 *)(v4 + 176) & v3) == 0 )
        return a2 + 4;
      *(_BYTE *)(a1 + 528) = 1;
      return a2;
    case 5:
      if ( (*(unsigned __int16 *)(v4 + 176) & v3) != 0 )
        return a2 + 4;
      *(_BYTE *)(a1 + 528) = 1;
      return a2;
    case 6:
      if ( *((unsigned __int8 *)&unk_12A40C8 + 32 * *(unsigned __int16 *)(v4 + 20)) == (unsigned __int8)sub_800CC0(*(_DWORD *)(a1 + 544))
                                                                                     + 1 )
LABEL_12:
        *(_WORD *)(v4 + 176) |= v3;
      return a2 + 4;
    default:
      return v2;
  }
}
