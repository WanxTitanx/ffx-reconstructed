// Function: sub_8E2F80
// Address: 0x8e2f80
int __cdecl sub_8E2F80(int a1)
{
  int v1; // esi
  double v2; // st7
  bool v3; // zf
  double v4; // st7
  double v5; // st7
  double v6; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st7
  int result; // eax
  double v12; // st7
  double v13; // st7
  float v14; // [esp+8h] [ebp-4Ch]
  float v15; // [esp+Ch] [ebp-48h]
  float v16; // [esp+18h] [ebp-3Ch]
  float v17; // [esp+18h] [ebp-3Ch]
  float v18; // [esp+24h] [ebp-30h]
  float v19; // [esp+24h] [ebp-30h]
  float v20; // [esp+24h] [ebp-30h]
  float v21; // [esp+24h] [ebp-30h]
  float v22; // [esp+24h] [ebp-30h]
  int v23; // [esp+28h] [ebp-2Ch] BYREF
  double v24; // [esp+2Ch] [ebp-28h]
  float v25; // [esp+34h] [ebp-20h]
  float v26; // [esp+38h] [ebp-1Ch]
  float v27; // [esp+3Ch] [ebp-18h]
  double v28; // [esp+40h] [ebp-14h]
  int v29; // [esp+48h] [ebp-Ch] BYREF
  double v30; // [esp+4Ch] [ebp-8h]

  v1 = a1;
  *((float *)&v24 + 1) = 0.0;
  v25 = 0.0;
  *(float *)&v23 = 0.0;
  sub_8B6C60(0, *(_DWORD *)(a1 + 36), (int)&v29, (int)&a1, 0.77999997, 1.0, 0, 0);
  v18 = *(float *)&a1;
  if ( *(_DWORD *)(v1 + 88) )
  {
    v2 = FFX_Menu2D_ScaleY_1080to416(48.0);
    *(float *)&a1 = v2 * 2.0 + *(float *)&a1;
    sub_905290(*(_DWORD *)(v1 + 92), (int)&v23, 0, 0.77999997);
  }
  v26 = FFX_Menu2D_ScaleX_1920to512(34.0);
  v27 = FFX_Menu2D_ScaleY_1080to416(15.0);
  v3 = *(_DWORD *)(v1 + 148) == 0;
  *(float *)&v29 = v26 * 2.0 + *(float *)&v29;
  v28 = 2.0 * v27;
  *(float *)&a1 = v28 + *(float *)&a1;
  if ( v3 )
    goto LABEL_6;
  *((float *)&v24 + 1) = v26;
  v25 = v27;
  v4 = FFX_Menu2D_ScaleX_1920to512(80.0);
  v26 = v4 + v26;
  v5 = FFX_Menu2D_ScaleX_1920to512(80.0);
  *(float *)&v29 = v5 + *(float *)&v29;
  v30 = *(float *)&a1;
  v6 = FFX_Menu2D_ScaleY_1080to416(60.0);
  if ( v6 + v28 <= v30 )
  {
LABEL_6:
    v8 = 0.5;
  }
  else
  {
    v7 = FFX_Menu2D_ScaleY_1080to416(60.0);
    *(float *)&a1 = v7 + v28;
    v25 = v27;
    v8 = 0.5;
    v27 = (*(float *)&a1 - v18) * 0.5;
  }
  *((float *)&v28 + 1) = (512.0 - *(float *)&v29) * v8;
  *((float *)&v30 + 1) = (float)*(int *)(v1 + 96);
  *((float *)&v30 + 1) = v8 * (416.0 - *(float *)&a1) + *((float *)&v30 + 1);
  sub_8F5F70(*((float *)&v28 + 1), *((float *)&v30 + 1), *(float *)&v29, *(float *)&a1, 10);
  if ( *(_DWORD *)(v1 + 148) == 1 )
  {
    v15 = FFX_Menu2D_ScaleY_1080to416(60.0);
    v14 = FFX_Menu2D_ScaleX_1920to512(60.0);
    v25 = *((float *)&v30 + 1) + v25;
    *((float *)&v24 + 1) = *((float *)&v28 + 1) + *((float *)&v24 + 1);
    FFX_Menu2D_DrawTexQuadSolid(
      0xF3u,
      *((float *)&v24 + 1),
      SLODWORD(v25),
      v14,
      v15,
      COERCE_INT(0.92675781),
      COERCE_INT(0.22851562),
      COERCE_INT(0.99902344),
      COERCE_INT(0.30175781));
  }
  if ( *(_DWORD *)(v1 + 148) == 2 )
  {
    FFX_BtlHud_NamedAnimStart(1, "scene7");
    sub_8AF010(1, "scene7", (int)*((float *)&v28 + 1), (int)*((float *)&v30 + 1));
  }
  v3 = *(_DWORD *)(v1 + 88) == 0;
  *((float *)&v28 + 1) = *((float *)&v28 + 1) + v26;
  v9 = *((float *)&v30 + 1) + v27;
  if ( v3 )
  {
    v24 = v9;
    v10 = FFX_Menu2D_ScaleY_1080to416(3.0);
    v9 = v24 - v10;
  }
  *((float *)&v30 + 1) = v9;
  result = sub_9016B0(0, *(_DWORD *)(v1 + 36), *((float *)&v28 + 1), *((float *)&v30 + 1), 0, 0.77999997, 1.0);
  if ( *(_DWORD *)(v1 + 88) )
  {
    *((float *)&v28 + 1) = (512.0 - *(float *)&v23) * 0.5;
    v12 = FFX_Menu2D_ScaleY_1080to416(9.0);
    *((float *)&v30 + 1) = v12 + *((float *)&v30 + 1) + v18;
    sub_9016B0(0, *(_DWORD *)(v1 + 88), *((float *)&v28 + 1), *((float *)&v30 + 1), 0, 0.77999997, 1.0);
    if ( !*(_WORD *)(v1 + 72) )
    {
      v19 = *((float *)&v30 + 1) + 1.0;
      v16 = v19;
      v20 = *((float *)&v28 + 1) - 5.0;
      sub_8C0640(v20, v16, 0);
    }
    v13 = FFX_Menu2D_ScaleY_1080to416(48.0);
    *((float *)&v30 + 1) = v13 + *((float *)&v30 + 1);
    result = sub_9016B0(0, *(_DWORD *)(v1 + 92), *((float *)&v28 + 1), *((float *)&v30 + 1), 0, 0.77999997, 1.0);
    if ( *(_WORD *)(v1 + 72) )
    {
      v21 = *((float *)&v30 + 1) + 1.0;
      v17 = v21;
      v22 = *((float *)&v28 + 1) - 5.0;
      return sub_8C0640(v22, v17, 0);
    }
  }
  return result;
}
