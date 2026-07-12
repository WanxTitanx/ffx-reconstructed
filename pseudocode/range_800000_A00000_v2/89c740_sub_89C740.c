// Function: sub_89C740
// Address: 0x89c740
int __cdecl sub_89C740(int a1)
{
  int v1; // esi
  float v3; // [esp+4h] [ebp-1Ch]
  _BYTE v4[4]; // [esp+18h] [ebp-8h] BYREF
  _BYTE v5[4]; // [esp+1Ch] [ebp-4h] BYREF
  float v6; // [esp+28h] [ebp+8h]
  float v7; // [esp+28h] [ebp+8h]

  v1 = sub_78F810(word_133F66A, 2);
  sub_8B9600(0, v1, v4, v5, 0, 0);
  v3 = FFX_Menu2D_ScaleY_1080to416(590.0);
  v6 = (float)a1;
  v7 = FFX_Menu2D_ScaleX_1920to512(915.0) + v6;
  return sub_9016B0(0, v1, v7, v3, 0, 0.63999999, 0.5);
}
