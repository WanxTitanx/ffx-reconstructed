// Function: sub_9A9BB0
// Address: 0x9a9bb0
int __cdecl sub_9A9BB0(signed int n2, float *a2, int a3, int a4, int *a5)
{
  int result; // eax
  int *v6; // esi
  double v7; // st7
  int v8; // ecx
  double v9; // st7
  double v10; // st7
  double v11; // st1
  double v12; // st7
  double v13; // st6
  double v14; // st2
  double v15; // st7
  signed int n2_1; // esi
  double v17; // st6
  double v18; // st6
  long double v19; // st7
  int v20; // ecx
  int v21; // edx
  int *v22; // esi
  double v23; // st7
  double v24; // st4
  double v25; // st3
  signed int n2_2; // ecx
  double i_1; // st2
  float v28; // [esp+10h] [ebp-64h]
  float v29; // [esp+10h] [ebp-64h]
  float v30; // [esp+14h] [ebp-60h]
  float v31; // [esp+14h] [ebp-60h]
  float v32; // [esp+18h] [ebp-5Ch]
  float v33; // [esp+18h] [ebp-5Ch]
  float v34; // [esp+1Ch] [ebp-58h]
  float v35; // [esp+1Ch] [ebp-58h]
  float v36; // [esp+1Ch] [ebp-58h]
  float v37; // [esp+1Ch] [ebp-58h]
  float v38; // [esp+20h] [ebp-54h]
  float v39; // [esp+20h] [ebp-54h]
  float i; // [esp+20h] [ebp-54h]
  float v41; // [esp+24h] [ebp-50h]
  float v42; // [esp+24h] [ebp-50h]
  float v43; // [esp+24h] [ebp-50h]
  float i_2; // [esp+24h] [ebp-50h]
  float v45; // [esp+28h] [ebp-4Ch]
  float v46; // [esp+28h] [ebp-4Ch]
  float v47; // [esp+28h] [ebp-4Ch]
  float v48; // [esp+28h] [ebp-4Ch]
  float v49; // [esp+28h] [ebp-4Ch]
  float v50[9]; // [esp+2Ch] [ebp-48h]
  _DWORD buf[8]; // [esp+50h] [ebp-24h] BYREF

  result = a4;
  v6 = a5;
  if ( n2 == 1 )
  {
    v32 = *a2;
    v50[0] = a2[1];
  }
  else
  {
    if ( n2 == 2 )
    {
      v32 = (a2[2] + *a2) * 0.5;
      v7 = 0.5 * (a2[3] + a2[1]);
    }
    else
    {
      v8 = n2 - 1;
      v34 = 0.0;
      v33 = 0.0;
      v50[0] = 0.0;
      if ( n2 - 1 > 0 )
      {
        result = (int)(a2 + 3);
        do
        {
          v9 = *(float *)result;
          result += 8;
          v30 = v9;
          v28 = *(float *)(result - 16);
          v10 = *(float *)(result - 20);
          v11 = *(float *)(result - 12);
          v38 = v10 * v30 - v28 * v11;
          v34 = v38 + v34;
          v33 = (v11 + v10) * v38 + v33;
          v50[0] = v38 * (v28 + v30) + v50[0];
          --v8;
        }
        while ( v8 );
      }
      v29 = a2[1];
      v31 = a2[2 * n2 - 1];
      v12 = a2[2 * n2 - 2];
      v13 = *a2;
      v39 = v12 * v29 - v31 * v13;
      v14 = v39 + v34;
      v45 = v14;
      v46 = fabs(v45);
      if ( v46 <= 0.00000011920929 )
        v35 = 9.9999998e17;
      else
        v35 = 1.0 / (v14 * 3.0);
      v32 = ((v13 + v12) * v39 + v33) * v35;
      v7 = (v39 * (v29 + v31) + v50[0]) * v35;
    }
    v50[0] = v7;
  }
  if ( n2 > 0 )
  {
    v15 = v32;
    n2_1 = 0;
    v17 = v50[0];
    do
    {
      v47 = a2[2 * n2_1 + 1] - v17;
      v18 = a2[2 * n2_1] - v15;
      v19 = v47;
      v48 = v18;
      v49 = atan2(v19, v48);
      v50[++n2_1] = v49;
      v15 = v32;
      v17 = v50[0];
    }
    while ( n2_1 < n2 );
    v6 = a5;
    result = 1;
    memset32(buf, 1, n2);
  }
  v20 = a4;
  v21 = 1;
  *v6 = a4;
  v22 = v6 + 1;
  buf[a4] = 0;
  LODWORD(v50[0]) = 1;
  if ( a3 > 1 )
  {
    v41 = (float)a3;
    v23 = 6.283185482025146 / v41;
    v24 = v50[a4 + 1];
    do
    {
      v42 = (float)SLODWORD(v50[0]);
      v36 = v42 * v23 + v24;
      v25 = v36;
      if ( v36 > 3.141592741012573 )
      {
        v37 = v25 - 6.283185482025146;
        v25 = v37;
      }
      *v22 = v20;
      n2_2 = 0;
      for ( i = 1000000000.0; n2_2 < n2; ++n2_2 )
      {
        if ( buf[n2_2] )
        {
          v43 = v50[n2_2 + 1] - v25;
          i_2 = fabs(v43);
          v50[0] = i_2;
          i_1 = i_2;
          if ( i_2 > 3.141592741012573 )
          {
            v50[0] = 6.283185482025146 - i_1;
            i_1 = v50[0];
          }
          if ( i > i_1 )
          {
            i = v50[0];
            *v22 = n2_2;
          }
        }
      }
      result = *v22;
      v20 = a4;
      ++v21;
      ++v22;
      buf[result] = 0;
      LODWORD(v50[0]) = v21;
    }
    while ( v21 < a3 );
  }
  return result;
}
