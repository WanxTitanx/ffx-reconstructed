// Function: sub_8EEEE0
// Address: 0x8eeee0
int __cdecl sub_8EEEE0(int a1, char *a2, int a3, float a4, int a5, int a6, int a7, int a8, int a9)
{
  int v9; // ecx
  int v10; // kr04_4
  int v11; // eax
  int v12; // edi
  char *v13; // ebx
  int v14; // eax
  int v15; // esi
  int v16; // edi
  char *v17; // eax
  double v19; // [esp+18h] [ebp-ECh]
  float v20; // [esp+20h] [ebp-E4h] BYREF
  int v21; // [esp+24h] [ebp-E0h]
  int v22; // [esp+28h] [ebp-DCh]
  float v23; // [esp+2Ch] [ebp-D8h] BYREF
  int v24; // [esp+30h] [ebp-D4h]
  float v25; // [esp+34h] [ebp-D0h] BYREF
  int v26; // [esp+38h] [ebp-CCh]
  float v27; // [esp+3Ch] [ebp-C8h]
  int v28; // [esp+40h] [ebp-C4h]
  float v29; // [esp+44h] [ebp-C0h] BYREF
  int v30; // [esp+48h] [ebp-BCh]
  float v31; // [esp+4Ch] [ebp-B8h]
  int v32; // [esp+50h] [ebp-B4h]
  int v33; // [esp+54h] [ebp-B0h]
  float v34; // [esp+58h] [ebp-ACh]
  int v35; // [esp+5Ch] [ebp-A8h]
  double v36; // [esp+60h] [ebp-A4h]
  int v37; // [esp+68h] [ebp-9Ch] BYREF
  float v38; // [esp+6Ch] [ebp-98h]
  float v39; // [esp+70h] [ebp-94h]
  float v40; // [esp+74h] [ebp-90h]
  int v41; // [esp+78h] [ebp-8Ch]
  int v42; // [esp+7Ch] [ebp-88h]
  int v43; // [esp+80h] [ebp-84h]
  int v44; // [esp+84h] [ebp-80h]
  float v45; // [esp+88h] [ebp-7Ch]
  float v46; // [esp+8Ch] [ebp-78h]
  float v47; // [esp+90h] [ebp-74h]
  float v48; // [esp+94h] [ebp-70h]
  int v49; // [esp+98h] [ebp-6Ch]
  int v50; // [esp+9Ch] [ebp-68h]
  int v51; // [esp+A0h] [ebp-64h]
  int v52; // [esp+A4h] [ebp-60h]
  int v53; // [esp+F0h] [ebp-14h]
  int v54; // [esp+F8h] [ebp-Ch] BYREF
  int v55; // [esp+FCh] [ebp-8h]

  v30 = a3;
  v35 = a3;
  v27 = a4;
  v31 = a4;
  v26 = a6;
  v24 = a7;
  v22 = a1;
  v28 = a8;
  v33 = a9;
  v9 = *a2 - 32;
  v10 = v9 % 32;
  v11 = v9 / 32;
  LOBYTE(v9) = v9 & 1;
  v12 = 10 * v11 + 192;
  v32 = 8 * (v10 / 2);
  HIDWORD(v36) = v12;
  v54 = 0;
  v55 = 0;
  v21 = v9;
  v13 = (char *)sub_8ACF00(15744, v9 + 2 * ((a5 >> 4) & 0xF), 0, 1, &v54);
  FFX_Menu2D_GetAtlasDimensions_structural(15744, &v23, &v20);
  FFX_Menu2D_GetAtlasDimensions_structural(15744, &v29, &v25);
  v53 = 0;
  *(float *)&v37 = (float)(v30 + 1);
  v38 = (float)SLODWORD(v31);
  v34 = (float)v32;
  *(float *)&v32 = v34;
  v39 = v34 / v29;
  *((float *)&v36 + 1) = (float)SHIDWORD(v36);
  v41 = v26;
  v31 = *((float *)&v36 + 1);
  v42 = v24;
  v44 = v33;
  v43 = v28;
  v40 = *((float *)&v36 + 1) / v25;
  v45 = (float)(v30 + 11);
  HIDWORD(v36) = 8 * (v10 / 2) + 11;
  v14 = v12 + 11;
  v46 = (float)(LODWORD(v27) + 12);
  v15 = v26;
  v16 = v24;
  v36 = (double)SHIDWORD(v36);
  v19 = v36 - 3.5;
  v47 = v19 / v29;
  *((float *)&v36 + 1) = (float)v14;
  v52 = v33;
  v34 = *((float *)&v36 + 1);
  v49 = v26;
  v50 = v24;
  v51 = v28;
  v48 = *((float *)&v36 + 1) / v25;
  sub_640810((int)&v37, v13, 0.0, 0.0, 0);
  v54 = 0;
  v55 = 0;
  v17 = (char *)sub_8ACF00(15744, v21 + 2 * (a5 & 0xF), 0, 0, &v54);
  *(float *)&v37 = (float)v35;
  v44 = v33;
  v38 = (float)(LODWORD(v27) - 1);
  v53 = 0;
  v41 = v15;
  v42 = v16;
  v43 = v28;
  v39 = *(float *)&v32 / v23;
  v40 = v31 / v20;
  v35 = LODWORD(v27) + 11;
  v45 = (float)(v30 + 10);
  v52 = v33;
  v46 = (float)(LODWORD(v27) + 11);
  v49 = v15;
  v50 = v16;
  v51 = v28;
  v47 = v19 / v23;
  v48 = v34 / v20;
  sub_640810((int)&v37, v17, 0.0, 0.0, 0);
  return v22 + 16;
}
