// Function: sub_8E2B60
// Address: 0x8e2b60
int __cdecl sub_8E2B60(int a1)
{
  int v1; // edi
  int v2; // eax
  int v3; // esi
  int v4; // esi
  int StubZero; // eax
  int v6; // esi
  float v8; // [esp+0h] [ebp-30h]
  int v9; // [esp+4h] [ebp-2Ch]
  float v10; // [esp+8h] [ebp-28h]
  float v11; // [esp+8h] [ebp-28h]
  float v12; // [esp+Ch] [ebp-24h]
  int v13; // [esp+Ch] [ebp-24h]
  float v14; // [esp+10h] [ebp-20h]
  float v15; // [esp+14h] [ebp-1Ch]
  float v16; // [esp+14h] [ebp-1Ch]
  float v17; // [esp+18h] [ebp-18h]

  sub_8BEF00();
  sub_8F9230(0, 0, 512, 416);
  sub_902810(0, 0, (*(_DWORD *)(a1 + 100) << 24) | 0x808080, (*(_DWORD *)(a1 + 100) << 24) | 0x808080);
  if ( *(_DWORD *)(a1 + 100) == 128 )
  {
    v1 = sub_873A80();
    v2 = sub_873A90();
    v3 = v2;
    if ( v1 || v2 )
    {
      FFX_BtlHud_NamedAnimStart(1, "scene30");
      sub_8AF010(1, "scene30", v1 / 2, v3 / 2 - 16);
    }
    v12 = FFX_Menu2D_ScaleY_1080to416(55.0);
    v10 = FFX_Menu2D_ScaleX_1920to512(1130.0);
    *(float *)&v9 = FFX_Menu2D_ScaleY_1080to416(951.0);
    v8 = FFX_Menu2D_ScaleX_1920to512(445.0);
    FFX_Menu2D_DrawTexQuadTinted(
      0xFFFFFFFF,
      v8,
      v9,
      v10,
      v12,
      COERCE_INT(0.0),
      COERCE_INT(544.0),
      COERCE_INT(1600.0),
      COERCE_INT(599.0),
      0x80808080,
      0x808080u);
    v15 = FFX_Menu2D_ScaleY_1080to416(24.0);
    v14 = FFX_Menu2D_ScaleX_1920to512(360.0);
    *(float *)&v13 = FFX_Menu2D_ScaleY_1080to416(933.0);
    v11 = FFX_Menu2D_ScaleX_1920to512(445.0);
    FFX_Menu2D_DrawTexQuadSolid(
      0xC8u,
      v11,
      v13,
      v14,
      v15,
      COERCE_INT(0.52929688),
      COERCE_INT(0.46582031),
      COERCE_INT(0.88085938),
      COERCE_INT(0.48925781));
    v4 = sub_86C3A0();
    StubZero = FFX_Kernel_GetStubZero();
    v6 = sub_86C3C0(v4, StubZero);
    v17 = FFX_Menu2D_ScaleY_1080to416(954.0);
    v16 = FFX_Menu2D_ScaleX_1920to512(535.0);
    sub_9016B0(0, v6, v16, v17, 0, 0.77999997, 1.0);
  }
  return sub_8BE9F0();
}
