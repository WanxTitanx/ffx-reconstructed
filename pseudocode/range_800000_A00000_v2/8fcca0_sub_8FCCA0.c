// Function: sub_8FCCA0
// Address: 0x8fcca0
void __cdecl sub_8FCCA0(float *a1, __int16 *a2, int n4)
{
  char *Str_1; // eax
  unsigned __int8 n3; // cl
  double v5; // st7
  float v6; // esi
  float v7; // edx
  float v8; // ecx
  float v9; // eax
  double v10; // st6
  double v11; // st4
  double v12; // st4
  __int16 v13; // [esp-8h] [ebp-CCh]
  char v14; // [esp-4h] [ebp-C8h]
  __int16 v15; // [esp+0h] [ebp-C4h]
  float v16; // [esp+18h] [ebp-ACh] BYREF
  char *Str; // [esp+1Ch] [ebp-A8h]
  float v18; // [esp+20h] [ebp-A4h] BYREF
  float v19; // [esp+24h] [ebp-A0h]
  int v20; // [esp+28h] [ebp-9Ch] BYREF
  float v21; // [esp+2Ch] [ebp-98h] BYREF
  float v22; // [esp+30h] [ebp-94h] BYREF
  float v23[5]; // [esp+34h] [ebp-90h] BYREF
  float v24; // [esp+48h] [ebp-7Ch] BYREF
  float v25; // [esp+4Ch] [ebp-78h] BYREF
  float v26; // [esp+50h] [ebp-74h] BYREF
  float v27[25]; // [esp+54h] [ebp-70h] BYREF
  _DWORD v28[2]; // [esp+B8h] [ebp-Ch] BYREF

  v15 = a2[2];
  v14 = *((_BYTE *)a1 + 27);
  v13 = *a2;
  v28[0] = 0;
  v28[1] = 0;
  Str_1 = (char *)sub_8ACF00(v13, v14, v15, 1, v28);
  n3 = *((_BYTE *)a1 + 26);
  Str = Str_1;
  if ( n3 == 3 || n3 == 1 )
    v5 = flt_C5D784;
  else
    v5 = 0.77999997;
  v19 = v5;
  FFX_Menu2D_GetAtlasDimensions_structural(*a2, &v16, &v18);
  LODWORD(v6) = *(unsigned __int8 *)a1;
  LODWORD(v7) = *((unsigned __int8 *)a1 + 1);
  LODWORD(v8) = *((unsigned __int8 *)a1 + 2);
  *(float *)&v20 = a1[1] + unk_18716A0;
  LODWORD(v9) = *((unsigned __int8 *)a1 + 3);
  v10 = *((float *)a2 + 6) * v19;
  v23[1] = v6;
  v11 = a1[2];
  v27[1] = v6;
  v27[23] = 0.0;
  LODWORD(v27[21]) = 2000;
  v23[2] = v7;
  v23[3] = v8;
  v23[4] = v9;
  v21 = v10 + v11 + unk_18716A4;
  v27[2] = v7;
  v12 = *((float *)a2 + 2);
  v27[3] = v8;
  v27[4] = v9;
  v22 = v12 / v16;
  v23[0] = *((float *)a2 + 3) / v18;
  v24 = unk_18716A0 + *((float *)a2 + 7) * v19 * flt_C5D778 + a1[1];
  v25 = unk_18716A4 + v19 * (*((float *)a2 + 8) + *((float *)a2 + 6)) * flt_C5D77C + a1[2];
  v26 = *((float *)a2 + 4) / v16;
  v27[0] = *((float *)a2 + 5) / v18;
  if ( n4 == 4 || sub_8E5A20((float *)&v20, &v21, &v24, &v25, &v22, v23, &v26, v27) )
    sub_640810((int)&v20, Str, 2.0, 2.0, n4 + a2[2]);
}
