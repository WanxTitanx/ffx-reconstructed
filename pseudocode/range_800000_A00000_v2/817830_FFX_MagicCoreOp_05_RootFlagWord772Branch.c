// Function: FFX_MagicCoreOp_05_RootFlagWord772Branch
// Address: 0x817830
// [Jarvis naming goal 2026-06-17] Magic core opcode 0x05 handler: set/clear/test/branch on root flag word at context+772; structural flag name kept by offset.
int __cdecl FFX_MagicCoreOp_05_RootFlagWord772Branch(int a1, int a2)
{
  int v2; // esi
  int v3; // ebx
  int v4; // eax
  int v5; // ecx

  v2 = a2;
  v3 = *(unsigned __int16 *)(a2 + 2);
  v4 = *(unsigned __int16 *)(a1 + 538);
  v5 = *(_DWORD *)(a1 + 544);
  if ( (v4 & 0x8000) != 0 )
    v3 <<= 16;
  switch ( (v4 >> 12) & 7 )
  {
    case 0:
      goto LABEL_14;
    case 1:
      *(_DWORD *)(a1 + 772) &= ~v3;
      return a2 + 4;
    case 2:
      if ( (v3 & *(_DWORD *)(a1 + 772)) == 0 )
        return a2 + 6;
      return *(__int16 *)(a2 + 4) + a2;
    case 3:
      if ( (v3 & *(_DWORD *)(a1 + 772)) != 0 )
        return a2 + 6;
      else
        return *(__int16 *)(a2 + 4) + a2;
    case 4:
      if ( (v3 & *(_DWORD *)(a1 + 772)) == 0 )
        return a2 + 4;
      *(_BYTE *)(a1 + 528) = 1;
      return a2;
    case 5:
      if ( (v3 & *(_DWORD *)(a1 + 772)) != 0 )
        return a2 + 4;
      *(_BYTE *)(a1 + 528) = 1;
      return a2;
    case 6:
      if ( *((unsigned __int8 *)&unk_12A40C8 + 32 * *(unsigned __int16 *)(v5 + 20)) == (unsigned __int8)sub_800CC0(v5)
                                                                                     + 1 )
LABEL_14:
        *(_DWORD *)(a1 + 772) |= v3;
      return a2 + 4;
    default:
      return v2;
  }
}
