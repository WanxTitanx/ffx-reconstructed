// Function: sub_8C0220
// Address: 0x8c0220
void __cdecl sub_8C0220(unsigned int n6, int a2, float a3, float a4, float a5)
{
  int v5; // ebx
  signed int n7; // edi
  int v7; // ecx
  int v8; // esi
  double v9; // st5
  char *v10; // esi
  int v11; // ecx
  int v12; // edi
  int v13; // [esp+Ch] [ebp-B8h]
  int v14; // [esp+10h] [ebp-B4h]
  int v15; // [esp+14h] [ebp-B0h]
  float v16; // [esp+18h] [ebp-ACh] BYREF
  float v17; // [esp+1Ch] [ebp-A8h] BYREF
  float v18; // [esp+20h] [ebp-A4h]
  char *Str; // [esp+24h] [ebp-A0h]
  int v20; // [esp+28h] [ebp-9Ch] BYREF
  float v21; // [esp+2Ch] [ebp-98h]
  float v22; // [esp+30h] [ebp-94h]
  float v23; // [esp+34h] [ebp-90h]
  int v24; // [esp+38h] [ebp-8Ch]
  int v25; // [esp+3Ch] [ebp-88h]
  int v26; // [esp+40h] [ebp-84h]
  int v27; // [esp+44h] [ebp-80h]
  float v28; // [esp+48h] [ebp-7Ch]
  float v29; // [esp+4Ch] [ebp-78h]
  float v30; // [esp+50h] [ebp-74h]
  float v31; // [esp+54h] [ebp-70h]
  int v32; // [esp+58h] [ebp-6Ch]
  int v33; // [esp+5Ch] [ebp-68h]
  int v34; // [esp+60h] [ebp-64h]
  int v35; // [esp+64h] [ebp-60h]
  int v36; // [esp+B8h] [ebp-Ch]
  int v37; // [esp+BCh] [ebp-8h]

  v5 = unk_23CC470;
  v13 = unk_23CC468;
  n7 = n6;
  v14 = unk_23CC460;
  v15 = unk_23CC458;
  v36 = 0;
  v37 = 0;
  if ( n6 > 6 )
  {
    v10 = FFX_Menu2D_TexHandleByAtlasId(11988);
    FFX_Menu2D_GetAtlasDimensions_structural(11988, &v17, &v16);
    v20 = a2;
    v21 = a3;
    v11 = 100 * ((int)(n6 - 8) / 5);
    v12 = 100 * ((int)(n6 - 8) % 5);
    *(float *)&Str = (float)v12;
    v22 = *(float *)&Str / v17;
    *(float *)&Str = (float)v11;
    v26 = v14;
    v27 = v15;
    v24 = v5;
    v25 = v13;
    v23 = *(float *)&Str / v16;
    v28 = *(float *)&a2 + a4;
    v29 = a3 + a5;
    *(float *)&Str = (float)(v12 + 100);
    v30 = *(float *)&Str / v17;
    *(float *)&Str = (float)(v11 + 100);
    v34 = v14;
    v35 = v15;
    v32 = v5;
    v33 = v13;
    v31 = *(float *)&Str / v16;
    sub_63F090((int)&v20, v10, 1, 0, 0.0);
  }
  else
  {
    *(float *)&Str = COERCE_FLOAT(FFX_Menu2D_TexHandleByAtlasId(11984));
    FFX_Menu2D_GetAtlasDimensions_structural(11984, &v17, &v16);
    if ( n6 == 6 && sub_86A770(v7) == 1 )
      n7 = 7;
    v20 = a2;
    v21 = a3;
    v8 = 100 * (n7 % 4);
    v18 = (float)v8;
    v9 = v18 / v17;
    LODWORD(v18) = 100 * (n7 / 4);
    v22 = v9;
    v18 = (float)SLODWORD(v18);
    v27 = v15;
    v24 = v5;
    v25 = v13;
    v26 = v14;
    v23 = v18 / v16;
    v28 = *(float *)&a2 + a4;
    v29 = a3 + a5;
    v18 = (float)(v8 + 100);
    v30 = v18 / v17;
    v18 = (float)(100 * (n7 / 4) + 100);
    v35 = v15;
    v32 = v5;
    v33 = v13;
    v34 = v14;
    v31 = v18 / v16;
    sub_63F090((int)&v20, Str, 1, 0, 0.0);
  }
}
