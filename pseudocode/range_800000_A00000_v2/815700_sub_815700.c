// Function: sub_815700
// Address: 0x815700
int __cdecl sub_815700(_DWORD *a1, int a2)
{
  int v3; // ebx
  int v4; // esi

  v3 = a1[136];
  v4 = sub_800F80(a1 + 192, v3, *(_WORD *)(v3 + 160));
  sub_7EA5E0(a1);
  sub_7E9760(a1, a1, v3 + 48, v4 + 144);
  sub_7EA760(a1 + 16, v3 + 64, 0.0625);
  sub_7E78B0(a1 + 16, a1, a1 + 16);
  n1065353216 = a1[16];
  unk_C8F52C = a1[17];
  n1065353216_2 = a1[18];
  n1065353216_3 = a1[19];
  *(_DWORD *)(dword_C8B500 + v3 + 144) = n1065353216;
  *(_DWORD *)(dword_C8B500 + v3 + 148) = unk_C8F52C;
  dword_C8B500 = 0;
  *(_DWORD *)(v3 + 152) = n1065353216_2;
  return a2;
}
