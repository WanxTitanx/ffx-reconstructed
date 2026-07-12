// Function: sub_8FCAD0
// Address: 0x8fcad0
void __cdecl sub_8FCAD0(int *a1, __int16 *a2, int n5)
{
  char *Str_1; // eax
  unsigned __int8 n3; // cl
  double v5; // st7
  float v6; // esi
  float v7; // edx
  float v8; // ecx
  float v9; // eax
  double v10; // st6
  int n4; // eax
  __int16 v12; // [esp-8h] [ebp-CCh]
  char v13; // [esp-4h] [ebp-C8h]
  __int16 v14; // [esp+0h] [ebp-C4h]
  float v15; // [esp+18h] [ebp-ACh] BYREF
  char *Str; // [esp+1Ch] [ebp-A8h]
  float v17; // [esp+20h] [ebp-A4h] BYREF
  float v18; // [esp+24h] [ebp-A0h]
  int v19; // [esp+28h] [ebp-9Ch] BYREF
  float v20; // [esp+2Ch] [ebp-98h] BYREF
  float v21; // [esp+30h] [ebp-94h] BYREF
  float v22[5]; // [esp+34h] [ebp-90h] BYREF
  float v23; // [esp+48h] [ebp-7Ch] BYREF
  float v24; // [esp+4Ch] [ebp-78h] BYREF
  float v25; // [esp+50h] [ebp-74h] BYREF
  float v26[25]; // [esp+54h] [ebp-70h] BYREF
  _DWORD v27[2]; // [esp+B8h] [ebp-Ch] BYREF

  v14 = a2[2];
  v13 = *((_BYTE *)a1 + 27);
  v12 = *a2;
  v27[0] = 0;
  v27[1] = 0;
  Str_1 = (char *)sub_8ACF00(v12, v13, v14, 0, v27);
  n3 = *((_BYTE *)a1 + 26);
  Str = Str_1;
  if ( n3 == 3 || n3 == 1 )
    v5 = flt_C5D784;
  else
    v5 = 0.77999997;
  v18 = v5;
  FFX_Menu2D_GetAtlasDimensions_structural(*a2, &v15, &v17);
  LODWORD(v6) = *(unsigned __int8 *)a1;
  v19 = a1[1];
  LODWORD(v7) = *((unsigned __int8 *)a1 + 1);
  LODWORD(v8) = *((unsigned __int8 *)a1 + 2);
  LODWORD(v9) = *((unsigned __int8 *)a1 + 3);
  v20 = *((float *)a2 + 6) * v18 + *((float *)a1 + 2);
  v10 = *((float *)a2 + 2);
  v26[23] = 0.0;
  LODWORD(v26[21]) = 2000;
  v22[1] = v6;
  v22[2] = v7;
  v22[3] = v8;
  v22[4] = v9;
  v26[1] = v6;
  v26[2] = v7;
  v26[3] = v8;
  v26[4] = v9;
  v21 = v10 / v15;
  v22[0] = *((float *)a2 + 3) / v17;
  v23 = *((float *)a2 + 7) * v18 * flt_C5D778 + *((float *)a1 + 1);
  v24 = v18 * (*((float *)a2 + 8) + *((float *)a2 + 6)) * flt_C5D77C + *((float *)a1 + 2);
  v25 = *((float *)a2 + 4) / v15;
  v26[0] = *((float *)a2 + 5) / v17;
  if ( n5 == 5 )
  {
    n4 = a2[2] + 6;
  }
  else
  {
    if ( !sub_8E5A20((float *)&v19, &v20, &v23, &v24, &v21, v22, &v25, v26) )
      return;
    n4 = a2[2] + 2;
  }
  sub_640810((int)&v19, Str, 0.0, 0.0, n4);
}
