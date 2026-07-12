// Function: sub_89D920
// Address: 0x89d920
int __cdecl sub_89D920(int a1)
{
  int v1; // esi
  int result; // eax
  float v3; // [esp+0h] [ebp-30h]
  int v4; // [esp+4h] [ebp-2Ch]
  float v5; // [esp+4h] [ebp-2Ch]
  float v6; // [esp+8h] [ebp-28h]
  float v7; // [esp+8h] [ebp-28h]
  float v8; // [esp+Ch] [ebp-24h]
  int v9; // [esp+Ch] [ebp-24h]
  float v10; // [esp+10h] [ebp-20h]
  float v11; // [esp+14h] [ebp-1Ch]
  float v12; // [esp+2Ch] [ebp-4h]

  v1 = 16 * a1;
  if ( *((_DWORD *)&unk_133F4D0 + 4 * a1) )
  {
    v8 = FFX_Menu2D_ScaleY_1080to416(55.0);
    v6 = FFX_Menu2D_ScaleX_1920to512(1600.0);
    *(float *)&v4 = FFX_Menu2D_ScaleY_1080to416(96.0);
    v3 = FFX_Menu2D_ScaleX_1920to512(145.0);
    FFX_Menu2D_DrawTexQuadTinted(
      0xFFFFFFFF,
      v3,
      v4,
      v6,
      v8,
      COERCE_INT(0.0),
      COERCE_INT(544.0),
      COERCE_INT(1600.0),
      COERCE_INT(599.0),
      0x80808080,
      0x808080u);
    v11 = FFX_Menu2D_ScaleY_1080to416(22.0);
    v10 = FFX_Menu2D_ScaleX_1920to512(95.0);
    *(float *)&v9 = FFX_Menu2D_ScaleY_1080to416(78.0);
    v7 = FFX_Menu2D_ScaleX_1920to512(145.0);
    FFX_Menu2D_DrawTexQuadSolid(
      0x3Eu,
      v7,
      v9,
      v10,
      v11,
      COERCE_INT(0.65332031),
      COERCE_INT(0.94140625),
      COERCE_INT(0.75488281),
      COERCE_INT(0.96484375));
    sub_905320(*(_DWORD *)((char *)&n7_0 + v1), *(_DWORD *)((char *)&unk_133F4D8 + v1), (int)&a1, 0.77999997, 1.0);
    v5 = FFX_Menu2D_ScaleY_1080to416(101.0);
    v12 = (512.0 - *(float *)&a1) * 0.5;
    return sub_901700(
             *(_DWORD *)((char *)&n7_0 + v1),
             *(_DWORD *)((char *)&unk_133F4D8 + v1),
             v12,
             v5,
             0,
             1,
             128,
             128,
             128,
             128,
             0.77999997,
             1.0);
  }
  return result;
}
