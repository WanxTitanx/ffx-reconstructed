// Function: sub_8601B0
// Address: 0x8601b0
int __cdecl sub_8601B0(int a1, int a2, int *a3)
{
  float v4; // [esp+14h] [ebp-Ch]
  float v5; // [esp+18h] [ebp-8h]
  float v6; // [esp+1Ch] [ebp-4h]

  v6 = FFX_TK_PopStackFloat(a1, a3);
  v5 = FFX_TK_PopStackFloat(a1, a3);
  v4 = FFX_TK_PopStackFloat(a1, a3);
  sub_86F710(a1, v4, v5, v6);
  return 0;
}
