// Function: sub_8EE600
// Address: 0x8ee600
int __cdecl sub_8EE600(int a1, char *a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v9; // ebx
  int v10; // esi
  char *v11; // esi
  char *Str; // [esp+20h] [ebp-BCh]
  float v14; // [esp+28h] [ebp-B4h]
  float v15; // [esp+2Ch] [ebp-B0h]
  float v16; // [esp+30h] [ebp-ACh] BYREF
  float v17; // [esp+34h] [ebp-A8h] BYREF
  int v18; // [esp+38h] [ebp-A4h]
  float v19; // [esp+3Ch] [ebp-A0h]
  int v20; // [esp+40h] [ebp-9Ch] BYREF
  float v21; // [esp+44h] [ebp-98h] BYREF
  float v22; // [esp+48h] [ebp-94h] BYREF
  float v23; // [esp+4Ch] [ebp-90h] BYREF
  int v24; // [esp+50h] [ebp-8Ch]
  int v25; // [esp+54h] [ebp-88h]
  int v26; // [esp+58h] [ebp-84h]
  int v27; // [esp+5Ch] [ebp-80h]
  float v28; // [esp+60h] [ebp-7Ch] BYREF
  float v29; // [esp+64h] [ebp-78h] BYREF
  float v30; // [esp+68h] [ebp-74h] BYREF
  float v31; // [esp+6Ch] [ebp-70h] BYREF
  int v32; // [esp+70h] [ebp-6Ch]
  int v33; // [esp+74h] [ebp-68h]
  int v34; // [esp+78h] [ebp-64h]
  int v35; // [esp+7Ch] [ebp-60h]
  int v36; // [esp+C8h] [ebp-14h]
  int v37; // [esp+D0h] [ebp-Ch] BYREF
  int v38; // [esp+D4h] [ebp-8h]

  v9 = *a2 - 32;
  v10 = 4 * (3 * (v9 / 24) + 36);
  v18 = 10 * (v9 % 24 / 2);
  v37 = 0;
  v38 = 0;
  Str = (char *)sub_8ACF00(15744, (v9 & 1) + 2 * ((a5 >> 4) & 0xF), 0, 1, &v37);
  FFX_Menu2D_GetAtlasDimensions_structural(15744, &v16, &v17);
  v36 = 0;
  *(float *)&v20 = (float)(a3 + 1);
  v21 = (float)(a4 + 1);
  v19 = (float)v18;
  v14 = v19;
  v22 = v19 / v16;
  v19 = (float)v10;
  v24 = a6;
  v15 = v19;
  v25 = a7;
  v23 = v19 / v17;
  v26 = a8;
  v27 = a9;
  v28 = (float)(a3 + 11);
  LODWORD(v19) = 10 * (v9 % 24 / 2) + 10;
  v29 = (float)(a4 + 12);
  v19 = (float)SLODWORD(v19);
  *(float *)&v18 = v19;
  v30 = v19 / v16;
  v19 = (float)(v10 + 12);
  v33 = a7;
  v34 = a8;
  v35 = a9;
  v32 = a6;
  v31 = v19 / v17;
  if ( sub_8E5A20((float *)&v20, &v21, &v28, &v29, &v22, &v23, &v30, &v31) )
  {
    sub_640810((int)&v20, Str, 0.0, 0.0, 0);
    v37 = 0;
    v38 = 0;
    v11 = (char *)sub_8ACF00(15744, (v9 & 1) + 2 * (a5 & 0xF), 0, 0, &v37);
    FFX_Menu2D_GetAtlasDimensions_structural(15744, &v16, &v17);
    *(float *)&v20 = (float)a3;
    v25 = a7;
    v33 = a7;
    v21 = (float)a4;
    v36 = 0;
    v24 = a6;
    v26 = a8;
    v27 = a9;
    v32 = a6;
    v34 = a8;
    v35 = a9;
    v22 = v14 / v16;
    v23 = v15 / v17;
    v28 = (float)(a3 + 10);
    v29 = (float)(a4 + 11);
    v30 = *(float *)&v18 / v16;
    v31 = v19 / v17;
    if ( sub_8E5A20((float *)&v20, &v21, &v28, &v29, &v22, &v23, &v30, &v31) )
      sub_640810((int)&v20, v11, 0.0, 0.0, 0);
  }
  return a1;
}
