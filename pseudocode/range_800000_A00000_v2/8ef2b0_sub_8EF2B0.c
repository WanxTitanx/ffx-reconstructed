// Function: sub_8EF2B0
// Address: 0x8ef2b0
int __cdecl sub_8EF2B0(int a1, char *a2, int a3, float a4, int a5, int a6, int a7, int a8, int a9)
{
  int v9; // ecx
  int v10; // kr04_4
  int v11; // ebx
  int v12; // esi
  int v13; // eax
  int v14; // ebx
  int v15; // edi
  char *v16; // eax
  double v17; // st7
  double v19; // [esp+18h] [ebp-F0h]
  char v20; // [esp+20h] [ebp-E8h]
  float v21; // [esp+24h] [ebp-E4h] BYREF
  float v22; // [esp+28h] [ebp-E0h] BYREF
  int v23; // [esp+2Ch] [ebp-DCh]
  char *Str; // [esp+30h] [ebp-D8h]
  float v25; // [esp+34h] [ebp-D4h] BYREF
  float v26; // [esp+38h] [ebp-D0h] BYREF
  float v27; // [esp+3Ch] [ebp-CCh]
  int v28; // [esp+40h] [ebp-C8h]
  int v29; // [esp+44h] [ebp-C4h]
  int v30; // [esp+48h] [ebp-C0h]
  int v31; // [esp+4Ch] [ebp-BCh]
  int v32; // [esp+50h] [ebp-B8h]
  int v33; // [esp+54h] [ebp-B4h]
  int v34; // [esp+58h] [ebp-B0h]
  float v35; // [esp+5Ch] [ebp-ACh]
  float v36; // [esp+60h] [ebp-A8h]
  double v37; // [esp+64h] [ebp-A4h]
  int v38; // [esp+6Ch] [ebp-9Ch] BYREF
  float v39; // [esp+70h] [ebp-98h]
  float v40; // [esp+74h] [ebp-94h]
  float v41; // [esp+78h] [ebp-90h]
  int v42; // [esp+7Ch] [ebp-8Ch]
  int v43; // [esp+80h] [ebp-88h]
  int v44; // [esp+84h] [ebp-84h]
  int v45; // [esp+88h] [ebp-80h]
  float v46; // [esp+8Ch] [ebp-7Ch]
  float v47; // [esp+90h] [ebp-78h]
  float v48; // [esp+94h] [ebp-74h]
  float v49; // [esp+98h] [ebp-70h]
  int v50; // [esp+9Ch] [ebp-6Ch]
  int v51; // [esp+A0h] [ebp-68h]
  int v52; // [esp+A4h] [ebp-64h]
  int v53; // [esp+A8h] [ebp-60h]
  int v54; // [esp+F4h] [ebp-14h]
  int v55; // [esp+FCh] [ebp-Ch] BYREF
  int v56; // [esp+100h] [ebp-8h]

  v27 = a4;
  v35 = a4;
  v29 = a6;
  v28 = a7;
  v23 = a1;
  v30 = a8;
  v32 = a9;
  v9 = *a2 - 32;
  v31 = a3;
  v10 = v9 % 32;
  v11 = 10 * (v9 / 32) + 192;
  v34 = 8 * (v9 % 32 / 2);
  HIDWORD(v37) = v11;
  v55 = 0;
  v56 = 0;
  v20 = v9 & 1;
  Str = (char *)sub_8ACF00(15744, (v9 & 1) + 2 * ((a5 >> 4) & 0xF), 0, 1, &v55);
  FFX_Menu2D_GetAtlasDimensions_structural(15744, &v21, &v22);
  FFX_Menu2D_GetAtlasDimensions_structural(15744, &v26, &v25);
  v54 = 0;
  *(float *)&v38 = (float)(a3 + 1);
  v39 = (float)SLODWORD(v35);
  v36 = (float)v34;
  *(float *)&v34 = v36;
  v40 = v36 / v26;
  *((float *)&v37 + 1) = (float)SHIDWORD(v37);
  v42 = v29;
  v35 = *((float *)&v37 + 1);
  v43 = v28;
  v33 = a3 + 11;
  v44 = v30;
  v45 = v32;
  v41 = *((float *)&v37 + 1) / v25;
  v46 = (float)(a3 + 12);
  v12 = LODWORD(v27) + 14;
  v13 = v11 + 11;
  v47 = (float)(LODWORD(v27) + 14);
  v14 = v29;
  v15 = v28;
  v37 = (double)(8 * (v10 / 2) + 11);
  v19 = v37 - 3.5;
  v48 = v19 / v26;
  *((float *)&v37 + 1) = (float)v13;
  v50 = v29;
  v36 = *((float *)&v37 + 1);
  v51 = v28;
  v52 = v30;
  v53 = v32;
  v49 = *((float *)&v37 + 1) / v25;
  sub_640810((int)&v38, Str, 0.0, 0.0, 0);
  v55 = 0;
  v56 = 0;
  v16 = (char *)sub_8ACF00(15744, v20 + 2 * (a5 & 0xF), 0, 0, &v55);
  v17 = (double)v31;
  v31 = LODWORD(v27) - 1;
  *(float *)&v38 = v17;
  v54 = 0;
  v39 = (float)(LODWORD(v27) - 1);
  v42 = v14;
  v43 = v15;
  v44 = v30;
  v45 = v32;
  v40 = *(float *)&v34 / v21;
  v41 = v35 / v22;
  v46 = (float)v33;
  v33 = v12 - 1;
  v47 = (float)(v12 - 1);
  v53 = v32;
  v50 = v14;
  v51 = v15;
  v52 = v30;
  v48 = v19 / v21;
  v49 = v36 / v22;
  sub_640810((int)&v38, v16, 0.0, 0.0, 0);
  return v23 + 16;
}
