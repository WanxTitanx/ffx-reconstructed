// Function: sub_815F60
// Address: 0x815f60
int __cdecl sub_815F60(int n6_1, int a2)
{
  int v2; // edx
  int n6; // eax
  unsigned __int8 v4; // cl

  v2 = *(_DWORD *)(n6_1 + 544);
  if ( (*(_WORD *)(n6_1 + 538) & 0xF000) != 0 )
  {
    if ( (*(_WORD *)(n6_1 + 538) & 0xF000) == 0x1000 )
      n6 = 6;
    else
      n6 = n6_1;
  }
  else
  {
    n6 = 5;
  }
  if ( (*(_WORD *)(n6_1 + 538) & 0x800) != 0 )
    v4 = *(_BYTE *)(v2 + 24);
  else
    v4 = *((_BYTE *)&unk_12A40C0 + 32 * *(unsigned __int16 *)(v2 + 20) + 16);
  FFX_Btl_DispatchActionAnimationByResultCode(v4, n6, 1);
  return a2 + 2;
}
