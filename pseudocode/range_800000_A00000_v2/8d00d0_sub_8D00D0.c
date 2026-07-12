// Function: sub_8D00D0
// Address: 0x8d00d0
int __cdecl sub_8D00D0(int a1, int a2, int a3)
{
  double v3; // st7
  float v5; // [esp+4h] [ebp-10h]
  float v6; // [esp+1Ch] [ebp+8h]
  float v7; // [esp+24h] [ebp+10h]
  float v8; // [esp+24h] [ebp+10h]

  v3 = FFX_Menu2D_ScaleY_1080to416(79.0);
  v6 = (float)(*(__int16 *)(a1 + 72) - *(__int16 *)(a1 + 50));
  v7 = (float)(int)(v3 * v6 + (double)a3);
  v5 = v7;
  v8 = (float)a2;
  return sub_8C0550(v8, v5, 0);
}
