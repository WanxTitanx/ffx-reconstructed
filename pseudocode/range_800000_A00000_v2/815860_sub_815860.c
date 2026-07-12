// Function: sub_815860
// Address: 0x815860
int __cdecl sub_815860(int a1, int a2)
{
  int v2; // ecx
  __int16 v3; // si

  v2 = *(_DWORD *)(a1 + 544);
  v3 = *(_WORD *)(a2 + 2);
  *(_DWORD *)(v2 + 168) = a2 + 4;
  *(_BYTE *)(v2 + 187) = 8;
  sub_800C80(a1 + 768, *(_WORD *)(a1 + 532));
  return a2 + 6 + 2 * v3;
}
