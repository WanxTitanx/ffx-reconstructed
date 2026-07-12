// Function: sub_8EFD90
// Address: 0x8efd90
int __cdecl sub_8EFD90(int a1, int n0x11, int a3, int a4, int a5, int a6, int a7, int a8, int n6)
{
  int n7; // esi
  int v10; // ecx
  double v11; // st7
  double v12; // st6
  int v13; // ebx
  int v15; // ecx
  double v16; // st7
  double v17; // st7
  int v18; // ebx
  float v19; // [esp+4h] [ebp-B4h] BYREF
  float v20; // [esp+8h] [ebp-B0h] BYREF
  float v21; // [esp+Ch] [ebp-ACh]
  char *Str; // [esp+10h] [ebp-A8h]
  char *Str_2; // [esp+14h] [ebp-A4h]
  float v24; // [esp+18h] [ebp-A0h]
  int Str_1; // [esp+1Ch] [ebp-9Ch] BYREF
  float v26; // [esp+20h] [ebp-98h]
  float v27; // [esp+24h] [ebp-94h]
  float v28; // [esp+28h] [ebp-90h]
  int v29; // [esp+2Ch] [ebp-8Ch]
  int v30; // [esp+30h] [ebp-88h]
  int v31; // [esp+34h] [ebp-84h]
  int v32; // [esp+38h] [ebp-80h]
  float v33; // [esp+3Ch] [ebp-7Ch]
  float v34; // [esp+40h] [ebp-78h]
  float v35; // [esp+44h] [ebp-74h]
  float v36; // [esp+48h] [ebp-70h]
  int v37; // [esp+4Ch] [ebp-6Ch]
  int v38; // [esp+50h] [ebp-68h]
  int v39; // [esp+54h] [ebp-64h]
  int v40; // [esp+58h] [ebp-60h]
  int v41; // [esp+ACh] [ebp-Ch]
  int v42; // [esp+B0h] [ebp-8h]
  int v43; // [esp+C4h] [ebp+Ch]

  n7 = n0x11;
  v41 = 0;
  v42 = 0;
  if ( (unsigned int)n0x11 > 0x11 )
    return a1;
  if ( n6 == 6 )
  {
    *(float *)&Str = COERCE_FLOAT(FFX_Menu2D_TexHandleByAtlasId(11984));
    FFX_Menu2D_GetAtlasDimensions_structural(11984, &v20, &v19);
    if ( n0x11 == 6 && sub_86A770(v10) == 1 )
      n7 = 7;
    v24 = (float)a3;
    v11 = v24;
    *(float *)&Str_1 = v24;
    v24 = (float)a4;
    v12 = v24;
    v26 = v24;
    v24 = (float)(100 * (n7 % 4));
    LODWORD(v21) = 100 * (n7 % 4) + 100;
    v27 = v24 / v20;
    v13 = 100 * (n7 / 4);
    v24 = (float)v13;
    v29 = a5;
    v30 = a6;
    v31 = a7;
    v32 = a8;
    v28 = v24 / v19;
    v33 = v11 + 53.33333206176758;
    v34 = v12 + 77.03704071044922;
    v21 = (float)SLODWORD(v21);
    v35 = v21 / v20;
    v21 = (float)(v13 + 100);
    v37 = a5;
    v38 = a6;
    v39 = a7;
    v40 = a8;
    v36 = v21 / v19;
    sub_63F090((int)&Str_1, Str, 1, 0, COERCE_FLOAT(6));
    return a1;
  }
  if ( n0x11 > 6 )
  {
    *(float *)&Str = COERCE_FLOAT(FFX_Menu2D_TexHandleByAtlasId(11988));
    FFX_Menu2D_GetAtlasDimensions_structural(11988, &v20, &v19);
    *(float *)&Str_2 = (float)a3;
    v24 = *(float *)&Str_2;
    v17 = *(float *)&Str_2;
    Str_1 = (int)Str_2;
    v26 = (float)a4;
    v18 = 100 * ((n0x11 - 8) / 5);
    v43 = 100 * ((n0x11 - 8) % 5);
    *(float *)&Str_2 = (float)v43;
    v27 = *(float *)&Str_2 / v20;
    *(float *)&Str_2 = (float)v18;
    v29 = a5;
    v30 = a6;
    v31 = a7;
    v32 = a8;
    v28 = *(float *)&Str_2 / v19;
    v33 = v17 + 63.0;
    v34 = (float)(a4 + 98);
    *(float *)&Str_2 = (float)(v43 + 100);
    v35 = *(float *)&Str_2 / v20;
    *(float *)&Str_2 = (float)(v18 + 100);
    v37 = a5;
    v38 = a6;
    v39 = a7;
    v40 = a8;
    v36 = *(float *)&Str_2 / v19;
    sub_63F090((int)&Str_1, Str, 1, 0, 0.0);
    return a1;
  }
  *(float *)&Str_2 = COERCE_FLOAT(FFX_Menu2D_TexHandleByAtlasId(11984));
  FFX_Menu2D_GetAtlasDimensions_structural(11984, &v20, &v19);
  if ( n0x11 == 6 && sub_86A770(v15) == 1 )
    n7 = 7;
  *(float *)&Str = (float)a3;
  v16 = *(float *)&Str;
  Str_1 = (int)Str;
  v26 = (float)a4;
  LODWORD(v21) = 100 * (n7 % 4);
  *(float *)&Str = (float)SLODWORD(v21);
  v27 = *(float *)&Str / v20;
  LODWORD(v24) = 100 * (n7 / 4);
  *(float *)&Str = (float)SLODWORD(v24);
  v29 = a5;
  v30 = a6;
  v31 = a7;
  v32 = a8;
  v28 = *(float *)&Str / v19;
  v33 = v16 + 63.0;
  v34 = (float)(a4 + 98);
  *(float *)&Str = (float)(LODWORD(v21) + 100);
  v35 = *(float *)&Str / v20;
  *(float *)&Str = (float)(LODWORD(v24) + 100);
  v37 = a5;
  v38 = a6;
  v39 = a7;
  v40 = a8;
  v36 = *(float *)&Str / v19;
  sub_63F090((int)&Str_1, Str_2, 1, 0, 0.0);
  return a1;
}
