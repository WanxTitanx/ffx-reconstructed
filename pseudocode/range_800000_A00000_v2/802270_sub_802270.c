// Function: sub_802270
// Address: 0x802270
int __cdecl sub_802270(float *a1, int a2)
{
  int v2; // ecx
  int v3; // esi
  int v4; // eax
  __int16 *v6; // [esp+10h] [ebp-Ch]
  float v7; // [esp+14h] [ebp-8h]
  float v8; // [esp+14h] [ebp-8h]
  unsigned __int16 *v9; // [esp+18h] [ebp-4h]

  v2 = *((_DWORD *)a1 + 136);
  v3 = v2 + 48;
  v7 = *(float *)(v2 + 60);
  v6 = (__int16 *)(*(_DWORD *)(v2 + 168) + 2);
  v9 = (unsigned __int16 *)v2;
  n1065353216 = *(_DWORD *)(v2 + 48);
  unk_C8F52C = *(_DWORD *)(v2 + 52);
  unk_C8F530 = *(_DWORD *)(v2 + 56);
  unk_C8F534 = *(_DWORD *)(v2 + 60);
  *(_DWORD *)a1 = n1065353216;
  *((_DWORD *)a1 + 1) = unk_C8F52C;
  *((_DWORD *)a1 + 2) = unk_C8F530;
  *((_DWORD *)a1 + 3) = unk_C8F534;
  *a1 = 0.0;
  v8 = v7 * 0.000000476837158203125;
  sub_7EA610(a1 + 32, v8);
  sub_7E9760(a1 + 32, a1 + 32, v3, v9 + 72);
  v4 = sub_801E20(a1, v9);
  sub_7E82C0(a1 + 48, v4, a1 + 32);
  sub_7E82C0(a1 + 48, a1 + 176, a1 + 48);
  sub_802370(a1 + 64, a1, a2, v9, *v6);
  *((_DWORD *)a1 + 64) |= 0x40u;
  return sub_802AF0(a1 + 64, a1, a2, v9, v6);
}
