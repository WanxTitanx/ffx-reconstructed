// Function: sub_910070
// Address: 0x910070
int __cdecl sub_910070(unsigned int *a1, int a2, float *a3, float *a4)
{
  int v4; // edx
  unsigned int *v5; // esi
  int n3; // edi
  int v7; // eax
  double v8; // st7
  int v9; // eax
  double v10; // st7
  int v11; // eax
  double v12; // st7
  int v13; // eax
  double v14; // st7
  int v15; // eax
  double v16; // st7
  int v17; // eax
  double v18; // st7
  int v19; // eax
  double v20; // st7
  int v21; // eax
  double v22; // st7
  int v23; // eax
  double v24; // st7
  int v25; // eax
  double v26; // st7
  int v27; // eax
  double v28; // st7
  int n3_1; // esi
  float *i_2; // edx
  int i_4; // edx
  int v32; // edx
  float *i; // esi
  int result; // eax
  int v35; // edx
  float i_1[8]; // [esp+4h] [ebp-84h] BYREF
  float i_3[12]; // [esp+24h] [ebp-64h] BYREF
  float i_5[12]; // [esp+54h] [ebp-34h] BYREF

  v4 = a2;
  i_1[0] = *a3;
  v5 = a1;
  i_1[2] = a3[2];
  i_1[4] = *a4;
  i_1[6] = a3[2];
  i_3[0] = *a4;
  i_3[2] = a4[2];
  i_3[4] = *a3;
  i_3[6] = a4[2];
  i_3[8] = *a3;
  i_3[10] = a3[2];
  if ( a2 )
  {
    n3 = 3;
    do
    {
      v5[3] = 1065353216;
      sub_6ED420((char *)v5 + (char *)i_5 - (char *)a1, v4, v5);
      v4 = a2;
      v5 += 4;
      --n3;
    }
    while ( n3 );
  }
  else
  {
    v7 = a1[1];
    i_5[0] = (float)*a1;
    v8 = (double)(int)a1[1];
    if ( v7 < 0 )
      v8 = v8 + 4294967300.0;
    v9 = a1[2];
    i_5[1] = v8;
    v10 = (double)(int)a1[2];
    if ( v9 < 0 )
      v10 = v10 + 4294967300.0;
    v11 = a1[3];
    i_5[2] = v10;
    v12 = (double)(int)a1[3];
    if ( v11 < 0 )
      v12 = v12 + 4294967300.0;
    v13 = a1[4];
    i_5[3] = v12;
    v14 = (double)(int)a1[4];
    if ( v13 < 0 )
      v14 = v14 + 4294967300.0;
    v15 = a1[5];
    i_5[4] = v14;
    v16 = (double)(int)a1[5];
    if ( v15 < 0 )
      v16 = v16 + 4294967300.0;
    v17 = a1[6];
    i_5[5] = v16;
    v18 = (double)(int)a1[6];
    if ( v17 < 0 )
      v18 = v18 + 4294967300.0;
    v19 = a1[7];
    i_5[6] = v18;
    v20 = (double)(int)a1[7];
    if ( v19 < 0 )
      v20 = v20 + 4294967300.0;
    v21 = a1[8];
    i_5[7] = v20;
    v22 = (double)(int)a1[8];
    if ( v21 < 0 )
      v22 = v22 + 4294967300.0;
    v23 = a1[9];
    i_5[8] = v22;
    v24 = (double)(int)a1[9];
    if ( v23 < 0 )
      v24 = v24 + 4294967300.0;
    v25 = a1[10];
    i_5[9] = v24;
    v26 = (double)(int)a1[10];
    if ( v25 < 0 )
      v26 = v26 + 4294967300.0;
    v27 = a1[11];
    i_5[10] = v26;
    v28 = (double)(int)a1[11];
    if ( v27 < 0 )
      v28 = v28 + 4294967300.0;
    i_5[11] = v28;
  }
  n3_1 = 0;
  i_2 = i_5;
  while ( !sub_910270(i_1, i_2) && !sub_910270(i_3, i_4) )
  {
    ++n3_1;
    i_2 = (float *)(v32 + 16);
    if ( n3_1 >= 3 )
    {
      for ( i = i_1; ; i += 4 )
      {
        result = sub_910270(i_5, i);
        if ( result )
          break;
        if ( v35 + 1 >= 4 )
          return result;
      }
      return 1;
    }
  }
  return 1;
}
