// Function: sub_80AF20
// Address: 0x80af20
int __cdecl sub_80AF20(int a1, int a2)
{
  int v2; // edi
  __int16 v3; // ax
  char v4; // si
  int v6; // eax

  v2 = *(_DWORD *)(a1 + 544);
  v3 = *(_WORD *)(a1 + 538) >> 12;
  if ( (_BYTE)v3 )
  {
    v4 = *(_WORD *)(a1 + 538) >> 12;
    *(_DWORD *)(v2 + 4 * (unsigned __int8)v3) = unknown_libname_742(0);
    *(_BYTE *)(v2 + 31) &= ~(1 << v4) & 0xF;
  }
  else
  {
    v6 = unknown_libname_742(0);
    *(_BYTE *)(v2 + 31) &= 1u;
    *(_DWORD *)(v2 + 12) = v6;
    *(_DWORD *)(v2 + 8) = v6;
    *(_DWORD *)(v2 + 4) = v6;
  }
  return a2 + 2;
}
