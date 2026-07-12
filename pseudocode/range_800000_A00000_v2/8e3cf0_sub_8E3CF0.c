// Function: sub_8E3CF0
// Address: 0x8e3cf0
void __cdecl sub_8E3CF0(int a1)
{
  int v2; // esi
  int v3; // ebx
  double v4; // st7
  bool v5; // zf
  int v6; // esi
  char **v7; // ebx
  double v8; // st7
  double v9; // st6
  double v10; // st7
  int (__cdecl *v11)(int, int, _DWORD); // eax
  BOOL v12; // ebx
  double v13; // st7
  double v14; // st7
  double v15; // st7
  int v16; // [esp+4h] [ebp-5Ch]
  float v17; // [esp+8h] [ebp-58h]
  float v18; // [esp+Ch] [ebp-54h]
  float v19; // [esp+10h] [ebp-50h]
  float v20; // [esp+14h] [ebp-4Ch]
  float v21; // [esp+18h] [ebp-48h]
  int v22; // [esp+18h] [ebp-48h]
  float v23; // [esp+1Ch] [ebp-44h]
  int v24; // [esp+1Ch] [ebp-44h]
  double v25; // [esp+2Ch] [ebp-34h]
  double v26; // [esp+2Ch] [ebp-34h]
  float v27; // [esp+30h] [ebp-30h]
  double v28; // [esp+34h] [ebp-2Ch]
  double v29; // [esp+34h] [ebp-2Ch]
  float v30; // [esp+38h] [ebp-28h]
  float v31; // [esp+38h] [ebp-28h]
  float v32; // [esp+3Ch] [ebp-24h]
  int v33; // [esp+3Ch] [ebp-24h]
  float v34; // [esp+40h] [ebp-20h]
  int v35; // [esp+40h] [ebp-20h]
  int v36; // [esp+44h] [ebp-1Ch]
  float v37; // [esp+48h] [ebp-18h]
  int v38; // [esp+48h] [ebp-18h]
  float v39; // [esp+48h] [ebp-18h]
  float v40; // [esp+48h] [ebp-18h]
  float v41; // [esp+48h] [ebp-18h]
  float v42; // [esp+48h] [ebp-18h]
  float v43; // [esp+48h] [ebp-18h]
  int v44; // [esp+48h] [ebp-18h]
  int v45; // [esp+4Ch] [ebp-14h]
  char *v46; // [esp+4Ch] [ebp-14h]
  int v47; // [esp+50h] [ebp-10h] BYREF
  int v48; // [esp+54h] [ebp-Ch]
  float v49; // [esp+58h] [ebp-8h]
  float v50; // [esp+5Ch] [ebp-4h]
  int v51; // [esp+68h] [ebp+8h]
  float v52; // [esp+68h] [ebp+8h]
  float v53; // [esp+68h] [ebp+8h]
  float v54; // [esp+68h] [ebp+8h]
  float v55; // [esp+68h] [ebp+8h]
  float v56; // [esp+68h] [ebp+8h]

  v2 = *(__int16 *)(a1 + 70);
  v3 = *(unsigned __int16 *)(a1 + 48);
  v4 = (double)*(__int16 *)(a1 + 74);
  v51 = *(__int16 *)(a1 + 76);
  v50 = v4;
  v36 = v3;
  v34 = (float)v51;
  v32 = FFX_Menu2D_ScaleX_1920to512(170.0) + v50;
  v25 = (double)*(__int16 *)(a1 + 78);
  v52 = v25 - FFX_Menu2D_ScaleX_1920to512(320.0);
  v26 = (double)*(__int16 *)(a1 + 78);
  v37 = (float)v3;
  v49 = (v26 - FFX_Menu2D_ScaleX_1920to512(320.0)) / v37;
  *(float *)&v38 = (float)(4096 - v2);
  v48 = v38;
  v39 = (float)v2;
  v53 = (*(float *)&v48 * v49 + v39 * v52) * 0.000244140625;
  v5 = *(_DWORD *)(a1 + 148) == 0;
  v50 = 0.000244140625 * (v50 * v39 + *(float *)&v48 * (v50 - v49 * (double)*(__int16 *)(a1 + 72)));
  if ( v5 )
  {
    v40 = (float)*(__int16 *)(a1 + 80);
    v21 = v40;
    v41 = (float)*(__int16 *)(a1 + 78);
    v20 = v41;
    v42 = (float)*(__int16 *)(a1 + 76);
    v19 = v42;
    v43 = (float)*(__int16 *)(a1 + 74);
    sub_8F5F70(v43, v19, v20, v21, 1);
  }
  v6 = 0;
  v45 = 0;
  *(float *)&v48 = FFX_Menu2D_ScaleY_1080to416(8.0) + v34;
  if ( v3 > 0 )
  {
    v35 = (int)v53;
    v7 = (char **)(a1 + 88);
    v33 = (int)v32;
    v44 = a1 + 88;
    v27 = *(float *)&v48 - 1.5;
    v8 = 0.0;
    v9 = 160.0;
    do
    {
      *(float *)&v47 = v8;
      v23 = v9;
      v10 = FFX_Menu2D_ScaleX_1920to512(v23);
      v54 = (float)v45;
      v46 = *v7;
      v11 = *(int (__cdecl **)(int, int, _DWORD))(a1 + 28);
      v55 = v10 + v50 + v54 * v49;
      v12 = v11 && !v11(a1, v6, 0);
      if ( v6 == *(__int16 *)(a1 + 72) && *(char *)(a1 + 69) > 0 )
      {
        v24 = (int)FFX_Menu2D_ScaleX_1920to512(298.0);
        v13 = FFX_Menu2D_ScaleY_1080to416(34.0);
        v22 = (int)(v13 + *(float *)&v48);
        v28 = v49 * 0.5 + v55;
        v14 = v28 - FFX_Menu2D_ScaleX_1920to512(298.0) * 0.5;
        sub_900F80(*(_DWORD *)(a1 + 144) + 15, (int)v14, v22, v24);
        sub_900F60(*(_DWORD *)(a1 + 144) + 15, 1);
        sub_8FF260(*(_DWORD *)(a1 + 144) + 15);
      }
      sub_8F9230(v33, 0, v35, 416);
      if ( v6 )
      {
        v18 = FFX_Menu2D_ScaleY_1080to416(35.0);
        v17 = FFX_Menu2D_ScaleX_1920to512(28.0);
        v16 = v48;
        v30 = v55 - FFX_Menu2D_ScaleX_1920to512(28.0);
        FFX_Menu2D_DrawTexQuadSolid(
          0xC8u,
          v30,
          v16,
          v17,
          v18,
          COERCE_INT(0.81347656),
          COERCE_INT(0.01171875),
          COERCE_INT(0.84472656),
          COERCE_INT(0.04296875));
      }
      sub_905290((int)v46, (int)&v47, v12, 0.77999997);
      v29 = v49 - *(float *)&v47;
      v56 = (v29 - FFX_Menu2D_ScaleX_1920to512(28.0)) * 0.5 + v55;
      FFX_Menu2D_DrawKernelString(v46, v56, v27, *(float *)&v12, 0.77999997);
      sub_8F9230(0, 0, 512, 416);
      if ( v6 == *(__int16 *)(a1 + 72) && *(char *)(a1 + 69) <= 0 )
      {
        v15 = FFX_Menu2D_ScaleY_1080to416(2.0);
        v31 = v15 + *(float *)&v48;
        sub_8C0640(v56, v31, 0);
        sub_8FF140(*(_DWORD *)(a1 + 144) + 15);
      }
      v8 = 0.0;
      v9 = 160.0;
      ++v6;
      v7 = (char **)(v44 + 12);
      v45 = v6;
      v44 += 12;
    }
    while ( v6 < v36 );
  }
}
