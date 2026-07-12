// Function: sub_8FC870
// Address: 0x8fc870
void __cdecl sub_8FC870(float *a1, __int16 *a2)
{
  char *v2; // edi
  double v3; // st7
  unsigned __int8 n3; // al
  double v5; // st7
  float v6; // esi
  float v7; // edx
  float v8; // ecx
  double v9; // st7
  double v10; // st6
  double v11; // st7
  int i; // esi
  int v13; // eax
  __int16 v14; // [esp-8h] [ebp-E8h]
  char v15; // [esp-4h] [ebp-E4h]
  __int16 v16; // [esp+0h] [ebp-E0h]
  float v17; // [esp+4h] [ebp-DCh]
  float v18; // [esp+18h] [ebp-C8h] BYREF
  float v19; // [esp+1Ch] [ebp-C4h] BYREF
  float *v20; // [esp+20h] [ebp-C0h]
  float v21; // [esp+24h] [ebp-BCh]
  double v22; // [esp+28h] [ebp-B8h]
  int v23; // [esp+30h] [ebp-B0h] BYREF
  float v24; // [esp+34h] [ebp-ACh] BYREF
  float v25; // [esp+38h] [ebp-A8h] BYREF
  float v26[4]; // [esp+3Ch] [ebp-A4h] BYREF
  float v27; // [esp+4Ch] [ebp-94h]
  float v28; // [esp+50h] [ebp-90h] BYREF
  float v29; // [esp+54h] [ebp-8Ch] BYREF
  float v30; // [esp+58h] [ebp-88h] BYREF
  float v31[25]; // [esp+5Ch] [ebp-84h] BYREF
  _DWORD v32[2]; // [esp+C0h] [ebp-20h] BYREF
  _DWORD v33[5]; // [esp+C8h] [ebp-18h]

  v16 = a2[2];
  v15 = *((_BYTE *)a1 + 27);
  v14 = *a2;
  v20 = a1;
  v33[0] = -33489154;
  v33[1] = &unk_FFFE02;
  v33[2] = 65790;
  v33[3] = 50200578;
  v33[4] = &unk_2020200;
  v32[0] = 0;
  v32[1] = 0;
  v2 = (char *)sub_8ACF00(v14, v15, v16, 1, v32);
  v3 = sub_640F20();
  n3 = *((_BYTE *)a1 + 26);
  v21 = v3;
  if ( n3 == 3 || n3 == 1 )
    v5 = flt_C5D784;
  else
    v5 = 0.77999997;
  *((float *)&v22 + 1) = v5;
  FFX_Menu2D_GetAtlasDimensions_structural(*a2, &v19, &v18);
  LODWORD(v6) = *(unsigned __int8 *)a1;
  LODWORD(v7) = *((unsigned __int8 *)v20 + 1);
  LODWORD(v8) = *((unsigned __int8 *)v20 + 2);
  LODWORD(v27) = *((unsigned __int8 *)v20 + 3);
  v31[4] = v27;
  v31[23] = 0.0;
  LODWORD(v31[21]) = 2000;
  v26[1] = v6;
  v9 = v20[1];
  v26[2] = v7;
  *(float *)&v23 = v9;
  v26[3] = v8;
  v31[1] = v6;
  v31[2] = v7;
  v10 = *((float *)&v22 + 1) * *((float *)a2 + 6);
  v31[3] = v8;
  v24 = v10 + v20[2];
  v25 = *((float *)a2 + 2) / v19;
  v26[0] = *((float *)a2 + 3) / v18;
  v28 = *((float *)a2 + 7) * *((float *)&v22 + 1) + v20[1];
  v29 = *((float *)&v22 + 1) * (*((float *)a2 + 8) + *((float *)a2 + 6)) + v20[2];
  v30 = *((float *)a2 + 4) / v19;
  v31[0] = *((float *)a2 + 5) / v18;
  if ( sub_8E5A20((float *)&v23, &v24, &v28, &v29, &v25, v26, &v30, v31) )
  {
    v11 = v21;
    for ( i = 0; i < 10; ++i )
    {
      HIDWORD(v22) = *((char *)v33 + 2 * i + 1);
      v22 = (double)SHIDWORD(v22);
      v13 = *((char *)v33 + 2 * i);
      *((float *)&v22 + 1) = v22 / v11;
      v17 = *((float *)&v22 + 1);
      v22 = (double)v13;
      *((float *)&v22 + 1) = v22 / v11;
      sub_640810((int)&v23, v2, *((float *)&v22 + 1), v17, 0);
      v11 = v21;
    }
  }
}
