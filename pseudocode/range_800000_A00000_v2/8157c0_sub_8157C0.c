// Function: sub_8157C0
// Address: 0x8157c0
int __cdecl sub_8157C0(int a1)
{
  int v2; // edi
  __int16 *v3; // esi
  float v5; // [esp+24h] [ebp+8h]

  v2 = *(_DWORD *)(a1 + 544);
  v3 = *(__int16 **)(sub_800F80((_DWORD *)(a1 + 768), v2, *(_WORD *)(v2 + 160)) + 188);
  v5 = *(float *)(*(char *)(v2 + 162) + v2) * 0.00390625;
  sub_7EA030(a1, v5, *((_DWORD *)v3 + 2), *((_DWORD *)v3 + 3), *v3);
  if ( *((_BYTE *)v3 + 7) )
    sub_7EA760(v2 + 144, a1, 16.0);
  else
    sub_7EA760(v2 + 144, a1, 1.0);
  return 0;
}
