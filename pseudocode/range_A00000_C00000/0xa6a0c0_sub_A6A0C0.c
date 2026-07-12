// Function: sub_A6A0C0
// Address: 0xa6a0c0
// Size: 0x1e8
// Prototype: 

int __cdecl sub_A6A0C0(int a1, int a2, float *a3, float *a4)
{
  int result; // eax
  int *v5; // edx
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  double v15; // st7
  double v16; // st6
  double v17; // st5
  double v18; // rt0
  double v19; // st5
  double v20; // st7
  int v21; // [esp+Ch] [ebp-60h]
  int v22; // [esp+10h] [ebp-5Ch]
  int v23; // [esp+14h] [ebp-58h]
  _BYTE v24[64]; // [esp+18h] [ebp-54h] BYREF
  float v25; // [esp+58h] [ebp-14h] BYREF
  float v26; // [esp+5Ch] [ebp-10h]
  float v27; // [esp+60h] [ebp-Ch]
  int v28; // [esp+64h] [ebp-8h]

  result = a1;
  a3[2] = 16777216.0;
  v5 = (int *)(a1 + 16);
  a3[1] = 16777216.0;
  v23 = a1 + 16;
  *a3 = 16777216.0;
  a4[2] = -16777216.0;
  a4[1] = -16777216.0;
  *a4 = -16777216.0;
  v21 = *(unsigned __int16 *)(a1 + 4);
  if ( *(_WORD *)(a1 + 4) )
  {
    do
    {
      v6 = unknown_libname_741(*v5);
      v7 = v6 + *(_DWORD *)(v6 + 8);
      v22 = *(__int16 *)(v6 + 18);
      v8 = unknown_libname_741(*(_DWORD *)(v23 + 4));
      *(float *)(v8 + 48) = *(float *)(v8 + 48) * 1000.0;
      v9 = unknown_libname_741(*(_DWORD *)(v23 + 4));
      *(float *)(v9 + 52) = *(float *)(v9 + 52) * 1000.0;
      v10 = unknown_libname_741(*(_DWORD *)(v23 + 4));
      *(float *)(v10 + 56) = *(float *)(v10 + 56) * 1000.0;
      v11 = unknown_libname_741(*(_DWORD *)(v23 + 4));
      sub_7E82C0(v24, a2, v11);
      v12 = unknown_libname_741(*(_DWORD *)(v23 + 4));
      *(float *)(v12 + 48) = *(float *)(v12 + 48) / 1000.0;
      v13 = unknown_libname_741(*(_DWORD *)(v23 + 4));
      *(float *)(v13 + 52) = *(float *)(v13 + 52) / 1000.0;
      v14 = unknown_libname_741(*(_DWORD *)(v23 + 4));
      *(float *)(v14 + 56) = *(float *)(v14 + 56) / 1000.0;
      if ( v22 > 0 )
      {
        do
        {
          v25 = *(float *)v7;
          v26 = *(float *)(v7 + 4);
          v27 = *(float *)(v7 + 8);
          v28 = *(_DWORD *)(v7 + 12);
          sub_6ED420(&v25, v24, &v25);
          v15 = v25;
          if ( v25 < (double)*a3 )
            *a3 = v25;
          v16 = v26;
          if ( v26 < (double)a3[1] )
            a3[1] = v26;
          v17 = v27;
          if ( v27 < (double)a3[2] )
            a3[2] = v27;
          if ( *a4 >= v15 )
          {
            v20 = v17;
          }
          else
          {
            v18 = v17;
            v19 = v15;
            v20 = v18;
            *a4 = v19;
          }
          if ( a4[1] < v16 )
            a4[1] = v16;
          if ( a4[2] < v20 )
            a4[2] = v20;
          v7 += 16;
          --v22;
        }
        while ( v22 );
      }
      result = v21 - 1;
      v5 = (int *)(v23 + 16);
      v23 += 16;
      v21 = result;
    }
    while ( result > 0 );
  }
  return result;
}

