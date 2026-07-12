// Function: sub_8EC720
// Address: 0x8ec720
void __cdecl sub_8EC720(unsigned __int8 *a1, int a2, float a3, int a4, int a5, int a6, int a7, int a8, float a9)
{
  int v9; // ebx
  int v10; // esi
  int v11; // eax
  char v12; // bl
  int v13; // edi
  char *v14; // esi
  double v15; // [esp+18h] [ebp-C8h]
  double v16; // [esp+20h] [ebp-C0h]
  char *Str; // [esp+28h] [ebp-B8h]
  float v18; // [esp+2Ch] [ebp-B4h]
  float v19; // [esp+30h] [ebp-B0h]
  float v20; // [esp+34h] [ebp-ACh] BYREF
  float v21; // [esp+38h] [ebp-A8h] BYREF
  float v22; // [esp+3Ch] [ebp-A4h]
  float v23; // [esp+40h] [ebp-A0h]
  int v24; // [esp+44h] [ebp-9Ch] BYREF
  float v25; // [esp+48h] [ebp-98h] BYREF
  float v26; // [esp+4Ch] [ebp-94h] BYREF
  float v27; // [esp+50h] [ebp-90h] BYREF
  int v28; // [esp+54h] [ebp-8Ch]
  int v29; // [esp+58h] [ebp-88h]
  int v30; // [esp+5Ch] [ebp-84h]
  int v31; // [esp+60h] [ebp-80h]
  float v32; // [esp+64h] [ebp-7Ch] BYREF
  float v33; // [esp+68h] [ebp-78h] BYREF
  float v34; // [esp+6Ch] [ebp-74h] BYREF
  float v35; // [esp+70h] [ebp-70h] BYREF
  int v36; // [esp+74h] [ebp-6Ch]
  int v37; // [esp+78h] [ebp-68h]
  int v38; // [esp+7Ch] [ebp-64h]
  int v39; // [esp+80h] [ebp-60h]
  int v40; // [esp+CCh] [ebp-14h]
  int v41; // [esp+D4h] [ebp-Ch] BYREF
  int v42; // [esp+D8h] [ebp-8h]

  if ( *a1 >= 0x30u )
    v9 = *a1 - 48;
  else
    v9 = a1[1] + 160;
  v10 = v9 / 24;
  v11 = v9 % 24 / 2;
  v12 = v9 & 1;
  v13 = 10 * v11;
  v10 *= 12;
  LODWORD(v23) = 10 * v11;
  v22 = *(float *)&v10;
  v41 = 0;
  v42 = 0;
  Str = (char *)sub_8ACF00(15744, v12 + 2 * ((a4 >> 4) & 0xF), 0, 1, &v41);
  FFX_Menu2D_GetAtlasDimensions_structural(15744, &v21, &v20);
  v40 = 0;
  *(float *)&v24 = *(float *)&a2 + 1.0;
  v25 = a3 + 1.0;
  v23 = (float)SLODWORD(v23);
  v19 = v23;
  v26 = v23 / v21;
  v23 = (float)SLODWORD(v22);
  v28 = a5;
  v18 = v23;
  v29 = a6;
  v30 = a7;
  v31 = a8;
  v27 = v23 / v20;
  v15 = *(float *)&a2 + 10.0 * a9;
  v32 = v15 + 1.0;
  v16 = a3 + a9 * 12.0;
  v33 = v16 + 1.0;
  v23 = (float)(v13 + 10);
  v22 = v23;
  v34 = v23 / v21;
  v23 = (float)(v10 + 12);
  v39 = a8;
  v36 = a5;
  v37 = a6;
  v38 = a7;
  v35 = v23 / v20;
  if ( sub_8E5A20((float *)&v24, &v25, &v32, &v33, &v26, &v27, &v34, &v35) )
  {
    sub_640810((int)&v24, Str, 0.0, 0.0, 0);
    v41 = 0;
    v42 = 0;
    v14 = (char *)sub_8ACF00(15744, v12 + 2 * (a4 & 0xF), 0, 0, &v41);
    FFX_Menu2D_GetAtlasDimensions_structural(15744, &v21, &v20);
    v24 = a2;
    v25 = a3;
    v29 = a6;
    v37 = a6;
    v40 = 0;
    v28 = a5;
    v30 = a7;
    v31 = a8;
    v36 = a5;
    v38 = a7;
    v39 = a8;
    v26 = v19 / v21;
    v27 = v18 / v20;
    v32 = v15;
    v33 = v16;
    v34 = v22 / v21;
    v35 = v23 / v20;
    sub_640810((int)&v24, v14, 0.0, 0.0, 0);
  }
}
