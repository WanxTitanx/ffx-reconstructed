// Function: sub_811230
// Address: 0x811230
int __cdecl sub_811230(int a1, int a2, int a3, int a4)
{
  int v5; // esi
  float v7; // [esp+1Ch] [ebp+10h]

  v5 = *(unsigned __int8 *)(a3 + 2);
  v7 = sub_800BF0(
         *(unsigned __int8 *)(*(_DWORD *)(a2 + 32) + (*(unsigned __int16 *)(a4 + 76) << 8) + 24),
         *(char *)(a1 + 542));
  *(float *)(v5 + a4) = *(float *)(v5 + a4) * v7;
  return a3 + 4;
}
