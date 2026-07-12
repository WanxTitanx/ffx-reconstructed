// Function: sub_8EE9C0
// Address: 0x8ee9c0
int __cdecl sub_8EE9C0(int a1, unsigned __int8 *a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v9; // ebx
  int v10; // esi
  int v11; // eax
  int v12; // edi
  char *v13; // ebx
  char *v14; // esi
  float v16; // [esp+18h] [ebp-B8h]
  int v17; // [esp+1Ch] [ebp-B4h]
  float v18; // [esp+1Ch] [ebp-B4h]
  float v19; // [esp+20h] [ebp-B0h] BYREF
  float v20; // [esp+24h] [ebp-ACh] BYREF
  float v21; // [esp+28h] [ebp-A8h]
  int v22; // [esp+2Ch] [ebp-A4h]
  float v23; // [esp+30h] [ebp-A0h]
  int v24; // [esp+34h] [ebp-9Ch] BYREF
  float v25; // [esp+38h] [ebp-98h]
  float v26; // [esp+3Ch] [ebp-94h]
  float v27; // [esp+40h] [ebp-90h]
  int v28; // [esp+44h] [ebp-8Ch]
  int v29; // [esp+48h] [ebp-88h]
  int v30; // [esp+4Ch] [ebp-84h]
  int v31; // [esp+50h] [ebp-80h]
  float v32; // [esp+54h] [ebp-7Ch]
  float v33; // [esp+58h] [ebp-78h]
  float v34; // [esp+5Ch] [ebp-74h]
  float v35; // [esp+60h] [ebp-70h]
  int v36; // [esp+64h] [ebp-6Ch]
  int v37; // [esp+68h] [ebp-68h]
  int v38; // [esp+6Ch] [ebp-64h]
  int v39; // [esp+70h] [ebp-60h]
  int v40; // [esp+BCh] [ebp-14h]
  int v41; // [esp+C4h] [ebp-Ch] BYREF
  int v42; // [esp+C8h] [ebp-8h]

  if ( *a2 >= 0x30u )
    v9 = *a2 - 48;
  else
    v9 = a2[1] + 160;
  v10 = v9 / 24;
  v11 = v9 % 24 / 2;
  LOBYTE(v9) = v9 & 1;
  v12 = 10 * v11;
  v10 *= 12;
  v17 = 10 * v11;
  v21 = *(float *)&v10;
  v41 = 0;
  v42 = 0;
  v22 = v9;
  v13 = (char *)sub_8ACF00(15744, v9 + 2 * ((a5 >> 4) & 0xF), 0, 1, &v41);
  FFX_Menu2D_GetAtlasDimensions_structural(15744, &v19, &v20);
  *(float *)&v24 = (float)(a3 + 1);
  v40 = 0;
  v25 = (float)(a4 + 1);
  v23 = (float)v17;
  v16 = v23;
  v26 = v23 / v19;
  v23 = (float)SLODWORD(v21);
  v28 = a6;
  v21 = v23;
  v31 = a9;
  v29 = a7;
  v30 = a8;
  v27 = v23 / v20;
  v32 = (float)(a3 + 11);
  v33 = (float)(a4 + 13);
  v23 = (float)(v12 + 10);
  v18 = v23;
  v34 = v23 / v19;
  v23 = (float)(v10 + 12);
  v36 = a6;
  v37 = a7;
  v38 = a8;
  v39 = a9;
  v35 = v23 / v20;
  sub_640810((int)&v24, v13, 0.0, 0.0, 0);
  v41 = 0;
  v42 = 0;
  v14 = (char *)sub_8ACF00(15744, v22 + 2 * (a5 & 0xF), 0, 0, &v41);
  FFX_Menu2D_GetAtlasDimensions_structural(15744, &v19, &v20);
  v40 = 0;
  *(float *)&v24 = (float)a3;
  v28 = a6;
  v25 = (float)a4;
  v26 = v16 / v19;
  v27 = v21 / v20;
  v22 = a4 + 12;
  v32 = (float)(a3 + 10);
  v33 = (float)(a4 + 12);
  v29 = a7;
  v30 = a8;
  v31 = a9;
  v36 = a6;
  v37 = a7;
  v38 = a8;
  v39 = a9;
  v34 = v18 / v19;
  v35 = v23 / v20;
  sub_640810((int)&v24, v14, 0.0, 0.0, 0);
  return a1;
}
