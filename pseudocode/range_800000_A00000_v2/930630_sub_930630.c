// Function: sub_930630
// Address: 0x930630
int __cdecl sub_930630(int a1)
{
  int v2; // eax
  int v4; // [esp-4h] [ebp-20h]
  float v5; // [esp+4h] [ebp-18h]
  float v6; // [esp+8h] [ebp-14h]
  float v7; // [esp+Ch] [ebp-10h]
  float v8; // [esp+24h] [ebp+8h]
  float v9; // [esp+24h] [ebp+8h]
  float v10; // [esp+24h] [ebp+8h]
  float v11; // [esp+24h] [ebp+8h]

  sub_6ED700(a1 + 128, &dst__8, a1 + 192);
  sub_831380(*(_DWORD *)(a1 + 4), -1);
  sub_831250(*(_DWORD *)(a1 + 4), -1);
  sub_8301E0(*(_DWORD *)(a1 + 4), 1);
  sub_8269D0(1);
  v8 = (double)*(unsigned __int8 *)(a1 + 43) * 0.0078125;
  v7 = v8;
  v9 = (double)*(unsigned __int8 *)(a1 + 42) * 0.0078125;
  v6 = v9;
  v10 = (double)*(unsigned __int8 *)(a1 + 41) * 0.0078125;
  v5 = v10;
  v11 = 0.0078125 * (double)*(unsigned __int8 *)(a1 + 40);
  v4 = *(_DWORD *)(a1 + 4);
  v2 = sub_826BF0(v4);
  return sub_63BCF0(v2, v4, v11, v5, v6, v7);
}
