// Function: sub_8EE240
// Address: 0x8ee240
int __cdecl sub_8EE240(int a1, char *a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v9; // ebx
  char *v10; // esi
  float v12; // [esp+18h] [ebp-BCh]
  int v13; // [esp+20h] [ebp-B4h]
  float v14; // [esp+20h] [ebp-B4h]
  float v15; // [esp+24h] [ebp-B0h] BYREF
  float v16; // [esp+28h] [ebp-ACh] BYREF
  int v17; // [esp+2Ch] [ebp-A8h]
  char *Str; // [esp+30h] [ebp-A4h]
  float v19; // [esp+34h] [ebp-A0h]
  int v20; // [esp+38h] [ebp-9Ch] BYREF
  float v21; // [esp+3Ch] [ebp-98h] BYREF
  float v22; // [esp+40h] [ebp-94h] BYREF
  float v23; // [esp+44h] [ebp-90h] BYREF
  int v24; // [esp+48h] [ebp-8Ch]
  int v25; // [esp+4Ch] [ebp-88h]
  int v26; // [esp+50h] [ebp-84h]
  int v27; // [esp+54h] [ebp-80h]
  float v28; // [esp+58h] [ebp-7Ch] BYREF
  float v29; // [esp+5Ch] [ebp-78h] BYREF
  float v30; // [esp+60h] [ebp-74h] BYREF
  float v31; // [esp+64h] [ebp-70h] BYREF
  int v32; // [esp+68h] [ebp-6Ch]
  int v33; // [esp+6Ch] [ebp-68h]
  int v34; // [esp+70h] [ebp-64h]
  int v35; // [esp+74h] [ebp-60h]
  int v36; // [esp+C0h] [ebp-14h]
  int v37; // [esp+C8h] [ebp-Ch] BYREF
  int v38; // [esp+CCh] [ebp-8h]

  v9 = *a2 - 32;
  v13 = 10 * (v9 % 24 / 2);
  v17 = 4 * (3 * (v9 / 24) + 36);
  v37 = 0;
  v38 = 0;
  Str = (char *)sub_8ACF00(15744, (v9 & 1) + 2 * ((a5 >> 4) & 0xF), 0, 1, &v37);
  FFX_Menu2D_GetAtlasDimensions_structural(15744, &v15, &v16);
  *(float *)&v20 = (float)(a3 + 1);
  v36 = 0;
  v21 = (float)(a4 + 1);
  v19 = (float)v13;
  v12 = v19;
  v22 = v19 / v15;
  v19 = (float)v17;
  v24 = a6;
  *(float *)&v17 = v19;
  v25 = a7;
  v23 = v19 / v16;
  v27 = a9;
  v28 = (float)(a3 + 11);
  v26 = a8;
  v29 = (float)(a4 + 13);
  v19 = (float)(v13 + 10);
  v14 = v19;
  v30 = v19 / v15;
  v19 = (float)(4 * (3 * (v9 / 24) + 36) + 12);
  v35 = a9;
  v32 = a6;
  v33 = a7;
  v34 = a8;
  v31 = v19 / v16;
  if ( sub_8E5A20((float *)&v20, &v21, &v28, &v29, &v22, &v23, &v30, &v31) )
  {
    sub_640810((int)&v20, Str, 0.0, 0.0, 0);
    v37 = 0;
    v38 = 0;
    v10 = (char *)sub_8ACF00(15744, (v9 & 1) + 2 * (a5 & 0xF), 0, 0, &v37);
    FFX_Menu2D_GetAtlasDimensions_structural(15744, &v15, &v16);
    *(float *)&v20 = (float)a3;
    v21 = (float)a4;
    v36 = 0;
    v24 = a6;
    v25 = a7;
    v26 = a8;
    v27 = a9;
    v32 = a6;
    v33 = a7;
    v34 = a8;
    v35 = a9;
    v22 = v12 / v15;
    v23 = *(float *)&v17 / v16;
    Str = (char *)(a4 + 12);
    v28 = (float)(a3 + 10);
    v29 = (float)(a4 + 12);
    v30 = v14 / v15;
    v31 = v19 / v16;
    if ( sub_8E5A20((float *)&v20, &v21, &v28, &v29, &v22, &v23, &v30, &v31) )
      sub_640810((int)&v20, v10, 0.0, 0.0, 0);
  }
  return a1;
}
