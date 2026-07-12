// Function: FFX_MagicCoreOp_2E_RecordFlag176Branch
// Address: 0x817af0
// [Jarvis naming goal 2026-06-17] Magic core opcode 0x2E handler: resolves active record then set/clear/test/branch on record+176 flags.
_WORD *__cdecl FFX_MagicCoreOp_2E_RecordFlag176Branch(int a1, _WORD *a2)
{
  _WORD *v2; // esi
  int v3; // eax
  __int16 v4; // bx
  int v5; // edi

  v2 = a2;
  v3 = sub_800F80((_DWORD *)(a1 + 768), *(_DWORD *)(a1 + 544), a2[1]);
  v4 = a2[2];
  v5 = v3;
  switch ( (*(__int16 *)(a1 + 538) >> 12) & 7 )
  {
    case 0:
      goto LABEL_12;
    case 1:
      *(_WORD *)(v3 + 176) &= ~v4;
      return a2 + 3;
    case 2:
      if ( (*(unsigned __int16 *)(v3 + 176) & v4) == 0 )
        return a2 + 4;
      return (_WORD *)((char *)a2 + (__int16)a2[3]);
    case 3:
      if ( (*(unsigned __int16 *)(v3 + 176) & v4) != 0 )
        return a2 + 4;
      else
        return (_WORD *)((char *)a2 + (__int16)a2[3]);
    case 4:
      if ( (*(unsigned __int16 *)(v3 + 176) & v4) == 0 )
        return a2 + 3;
      *(_BYTE *)(a1 + 528) = 1;
      return a2;
    case 5:
      if ( (*(unsigned __int16 *)(v3 + 176) & v4) != 0 )
        return a2 + 3;
      *(_BYTE *)(a1 + 528) = 1;
      return a2;
    case 6:
      if ( *((unsigned __int8 *)&unk_12A40C8 + 32 * *(unsigned __int16 *)(v3 + 20)) == (unsigned __int8)sub_800CC0(v3)
                                                                                     + 1 )
LABEL_12:
        *(_WORD *)(v5 + 176) |= v4;
      return a2 + 3;
    default:
      return v2;
  }
}
