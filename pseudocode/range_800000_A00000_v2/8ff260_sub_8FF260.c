// Function: sub_8FF260
// Address: 0x8ff260
void __cdecl sub_8FF260(int a1)
{
  int v1; // esi
  __int16 v2; // ax
  __int16 v3; // cx
  int v4; // [esp+4h] [ebp-2Ch]
  float v5; // [esp+8h] [ebp-28h]
  float v6; // [esp+Ch] [ebp-24h]
  int v7; // [esp+18h] [ebp-18h]
  float v8; // [esp+2Ch] [ebp-4h]
  int v9; // [esp+38h] [ebp+8h]
  float v10; // [esp+38h] [ebp+8h]
  int v11; // [esp+38h] [ebp+8h]
  float v12; // [esp+38h] [ebp+8h]

  v1 = 16 * a1;
  if ( *((_WORD *)&unk_18762A0 + 8 * a1) )
  {
    v2 = *((_WORD *)&unk_18762AA + 8 * a1);
    v3 = *((_WORD *)&unk_18762AC + 8 * a1);
    if ( v2 < v3 )
      *((_WORD *)&unk_18762AA + 8 * a1) = v2 + 1;
    v8 = sub_8F38C0(*((__int16 *)&unk_18762AA + 8 * a1), v3);
    *((_WORD *)&unk_18762A8 + 8 * a1) = (int)((double)*((__int16 *)&unk_18762A6 + 8 * a1) * v8);
    *(float *)&v9 = v8 * 298.0 * 0.0009765625;
    v7 = v9;
    v6 = FFX_Menu2D_ScaleY_1080to416(8.0);
    v10 = (float)*(__int16 *)((char *)&unk_18762A8 + v1);
    v5 = v10;
    *(float *)&v11 = (float)*(__int16 *)((char *)&unk_18762A4 + v1);
    v4 = v11;
    v12 = (float)*(__int16 *)((char *)&unk_18762A2 + v1);
    FFX_Menu2D_DrawTexQuadSolid(
      0xC8u,
      v12,
      v4,
      v5,
      v6,
      COERCE_INT(0.0),
      COERCE_INT(0.42285156),
      v7,
      COERCE_INT(0.43066406));
  }
}
