// Function: sub_8E4140
// Address: 0x8e4140
int __cdecl sub_8E4140(int a1)
{
  int v2; // edi
  double v3; // st7
  int v4; // esi
  double v5; // st7
  int v6; // ecx
  int n4096; // eax
  int n4096_1; // esi
  double v9; // st7
  double v10; // st6
  int (__cdecl *v11)(int, int, _DWORD); // eax
  BOOL v12; // edi
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  int v17; // [esp+4h] [ebp-5Ch]
  float v18; // [esp+8h] [ebp-58h]
  float v19; // [esp+Ch] [ebp-54h]
  int v20; // [esp+18h] [ebp-48h]
  int v21; // [esp+1Ch] [ebp-44h]
  double v22; // [esp+2Ch] [ebp-34h]
  float v23; // [esp+30h] [ebp-30h]
  int v24; // [esp+34h] [ebp-2Ch] BYREF
  double v25; // [esp+38h] [ebp-28h]
  int v26; // [esp+40h] [ebp-20h]
  double v27; // [esp+44h] [ebp-1Ch]
  int n4096_3; // [esp+4Ch] [ebp-14h]
  float v29; // [esp+50h] [ebp-10h]
  int n4096_2; // [esp+54h] [ebp-Ch]
  float v31; // [esp+58h] [ebp-8h]
  int v32; // [esp+5Ch] [ebp-4h]
  float v33; // [esp+68h] [ebp+8h]
  float v34; // [esp+68h] [ebp+8h]
  float v35; // [esp+68h] [ebp+8h]
  float v36; // [esp+68h] [ebp+8h]
  float v37; // [esp+68h] [ebp+8h]
  int v38; // [esp+68h] [ebp+8h]
  float v39; // [esp+68h] [ebp+8h]
  int v40; // [esp+68h] [ebp+8h]
  float v41; // [esp+68h] [ebp+8h]

  n4096_2 = *(unsigned __int16 *)(a1 + 48);
  v2 = *(__int16 *)(MEMORY[0x23CC128] + 70);
  v33 = (float)(*(__int16 *)(MEMORY[0x23CC128] + 74) + *(__int16 *)(MEMORY[0x23CC128] + 78));
  v3 = FFX_Menu2D_ScaleX_1920to512(160.0);
  v4 = *(unsigned __int16 *)(MEMORY[0x23CC128] + 48);
  v22 = v33 - v3;
  v25 = (double)*(__int16 *)(MEMORY[0x23CC128] + 78);
  v34 = (float)(v4 - 1);
  v5 = (v25 - FFX_Menu2D_ScaleX_1920to512(320.0)) * v34;
  v25 = (double)v4;
  v35 = (float)(4096 - v2);
  v6 = *(__int16 *)(MEMORY[0x23CC128] + 74) + *(__int16 *)(MEMORY[0x23CC128] + 78);
  v29 = v22 - v5 / v25 * v35 * 0.000244140625;
  v36 = (float)v6;
  v37 = v36 - FFX_Menu2D_ScaleX_1920to512(160.0) - v29;
  *(float *)&n4096_3 = (float)*(__int16 *)(MEMORY[0x23CC128] + 76);
  *((float *)&v27 + 1) = (float)n4096_2;
  v31 = v37 / *((float *)&v27 + 1);
  n4096 = (int)(FFX_Menu2D_ScaleY_1080to416(8.0) + *(float *)&n4096_3);
  n4096_1 = 0;
  n4096_3 = n4096;
  HIDWORD(v27) = 0;
  if ( n4096_2 > 0 )
  {
    v9 = v29;
    v26 = (int)v37;
    HIDWORD(v25) = (int)v29;
    *(float *)&v38 = (float)n4096_3;
    v32 = v38;
    v23 = *(float *)&v38 - 1.5;
    v10 = v31;
    while ( 1 )
    {
      v39 = (float)SHIDWORD(v27);
      n4096_3 = *(int *)(a1 + 12 * n4096_1 + 88);
      v40 = (int)(v9 + v10 * v39);
      v11 = *(int (__cdecl **)(int, int, _DWORD))(a1 + 28);
      v12 = v11 && !v11(a1, n4096_1, 0);
      if ( n4096_1 == *(__int16 *)(a1 + 72) && *(char *)(a1 + 69) > 0 )
      {
        v21 = (int)FFX_Menu2D_ScaleX_1920to512(298.0);
        v13 = FFX_Menu2D_ScaleY_1080to416(34.0);
        v20 = (int)(v13 + *(float *)&v32);
        *((float *)&v27 + 1) = (float)v40;
        v27 = v31 * 0.5 + *((float *)&v27 + 1);
        v14 = FFX_Menu2D_ScaleX_1920to512(298.0);
        sub_900F80(*(_DWORD *)(a1 + 144) + 15, (int)(v27 - v14 * 0.5), v20, v21);
        sub_900F60(*(_DWORD *)(a1 + 144) + 15, 1);
        sub_8FF260(*(_DWORD *)(a1 + 144) + 15);
      }
      if ( !n4096_1 && *(__int16 *)(MEMORY[0x23CC128] + 72) == *(unsigned __int16 *)(MEMORY[0x23CC128] + 48) - 1 )
      {
        v19 = FFX_Menu2D_ScaleY_1080to416(35.0);
        v18 = FFX_Menu2D_ScaleX_1920to512(28.0);
        v17 = v32;
        *((float *)&v27 + 1) = (float)v40;
        v27 = *((float *)&v27 + 1);
        v15 = FFX_Menu2D_ScaleX_1920to512(28.0);
        *((float *)&v27 + 1) = v27 - v15;
        FFX_Menu2D_DrawTexQuadSolid(
          0xC8u,
          *((float *)&v27 + 1),
          v17,
          v18,
          v19,
          COERCE_INT(0.81347656),
          COERCE_INT(0.01171875),
          COERCE_INT(0.84472656),
          COERCE_INT(0.04296875));
      }
      sub_8F9230(HIDWORD(v25), 0, v26, 416);
      sub_905290(n4096_3, (int)&v24, v12, 0.77999997);
      v27 = (double)v40;
      v41 = (float)(int)((v31 - *(float *)&v24) * 0.5 + v27);
      FFX_Menu2D_DrawKernelString((char *)n4096_3, v41, v23, *(float *)&v12, 0.77999997);
      sub_8F9230(0, 0, 512, 416);
      n4096 = *(__int16 *)(a1 + 72);
      if ( n4096_1 == n4096 && *(char *)(a1 + 69) <= 0 )
      {
        n4096 = 4096;
        if ( *(_WORD *)(a1 + 70) == 4096 )
        {
          v16 = FFX_Menu2D_ScaleY_1080to416(2.0);
          *((float *)&v27 + 1) = v16 + *(float *)&v32;
          sub_8C0640(v41, *((float *)&v27 + 1), 0);
          n4096 = sub_8FF140(*(_DWORD *)(a1 + 144) + 15);
        }
      }
      HIDWORD(v27) = ++n4096_1;
      if ( n4096_1 >= n4096_2 )
        break;
      v10 = v31;
      v9 = v29;
    }
  }
  return n4096;
}
