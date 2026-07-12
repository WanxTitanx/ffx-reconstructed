// Function: sub_A943E0
// Address: 0xa943e0
// Size: 0x2f3
// Prototype: int __fastcall(_DWORD, _DWORD)

int __fastcall sub_A943E0(int *a1, int a2)
{
  int v2; // edi
  int *v3; // esi
  int v4; // ebx
  int v5; // ecx
  _BYTE *v6; // eax
  int i_1; // ebx
  int i; // edi
  int v9; // eax
  char v10; // cl
  char v11; // al
  int v12; // ecx
  unsigned int j; // eax
  bool v14; // zf
  int v15; // ecx
  unsigned int k; // eax
  int m_1; // ecx
  int m; // eax
  int n; // ebx
  int ii; // ebx
  int v21; // eax
  int kk_2; // ebx
  int X_2; // eax
  int v25; // esi
  double X_1; // xmm0_8
  double kk_3; // st7
  int X_4; // eax
  int jj; // edi
  int X_5; // ecx
  int X_6; // edx
  int kk_1; // ecx
  __int64 v33; // rax
  int X; // [esp+0h] [ebp-48h]
  int v36; // [esp+34h] [ebp-14h]
  int X_3; // [esp+34h] [ebp-14h]
  int v38; // [esp+38h] [ebp-10h]
  int kk; // [esp+38h] [ebp-10h]

  v2 = a2;
  v3 = a1;
  sub_42E350(a2, &loc_564342, 24);
  sub_42E350(v2, *v3, 16);
  sub_42E350(v2, v3[1], 24);
  v4 = v3[1];
  v5 = 1;
  if ( v4 > 1 )
  {
    v6 = (_BYTE *)v3[2];
    do
    {
      if ( !*v6 )
        break;
      if ( v6[1] < *v6 )
        break;
      ++v5;
      ++v6;
    }
    while ( v5 < v4 );
  }
  if ( v5 == v4 )
  {
    i_1 = 0;
    sub_42E350(v2, 1, 1);
    sub_42E350(v2, *(char *)v3[2] - 1, 5);
    for ( i = 1; i < v3[1]; ++i )
    {
      v9 = v3[2];
      v10 = *(_BYTE *)(v9 + i);
      v11 = *(_BYTE *)(v9 + i - 1);
      if ( v10 > v11 && v11 < v10 )
      {
        v36 = v10 - v11;
        do
        {
          v12 = 0;
          for ( j = v3[1] - i_1; j; j >>= 1 )
            ++v12;
          sub_42E350(a2, i - i_1, v12);
          v14 = v36-- == 1;
          i_1 = i;
        }
        while ( !v14 );
      }
    }
    v15 = 0;
    for ( k = v3[1] - i_1; k; k >>= 1 )
      ++v15;
    X = i - i_1;
    v2 = a2;
    sub_42E350(a2, X, v15);
  }
  else
  {
    sub_42E350(v2, 0, 1);
    m_1 = v3[1];
    for ( m = 0; m < m_1; ++m )
    {
      if ( !*(_BYTE *)(v3[2] + m) )
        break;
    }
    if ( m == m_1 )
    {
      sub_42E350(v2, 0, 1);
      for ( n = 0; n < v3[1]; ++n )
        sub_42E350(v2, *(char *)(v3[2] + n) - 1, 5);
    }
    else
    {
      sub_42E350(v2, 1, 1);
      for ( ii = 0; ii < v3[1]; ++ii )
      {
        if ( *(_BYTE *)(ii + v3[2]) )
        {
          sub_42E350(v2, 1, 1);
          sub_42E350(v2, *(char *)(v3[2] + ii) - 1, 5);
        }
        else
        {
          sub_42E350(v2, 0, 1);
        }
      }
    }
  }
  sub_42E350(v2, v3[3], 4);
  v21 = v3[3];
  if ( v21 )
  {
    if ( (unsigned int)(v21 - 1) > 1 || !v3[8] )
      return -1;
    sub_42E350(v2, v3[4], 32);
    sub_42E350(v2, v3[5], 32);
    sub_42E350(v2, v3[6] - 1, 4);
    sub_42E350(v2, v3[7], 1);
    if ( v3[3] == 1 )
    {
      X_2 = v3[1];
      v25 = *v3;
      X_1 = (float)X_2;
      X_3 = X_2;
      v38 = v25;
      libm_sse2_pow_precise();
      kk_3 = floor(X_1);
      X_4 = X_3;
      kk_2 = (int)kk_3;
      for ( jj = (int)kk_3 + 1; ; ++jj )
      {
        while ( 1 )
        {
          X_5 = 1;
          X_6 = 1;
          if ( v25 > 0 )
          {
            do
            {
              X_5 *= kk_2;
              X_6 *= jj;
              --v25;
            }
            while ( v25 );
            X_4 = X_3;
            v25 = v38;
          }
          if ( X_5 <= X_4 )
            break;
          --kk_2;
          --jj;
        }
        if ( X_6 > X_4 )
          break;
        ++kk_2;
      }
      v3 = a1;
      v2 = a2;
    }
    else if ( v3[3] == 2 )
    {
      kk_2 = *v3 * v3[1];
    }
    else
    {
      kk_2 = -1;
    }
    kk_1 = 0;
    for ( kk = 0; kk_1 < kk_2; kk = kk_1 )
    {
      v33 = *(int *)(v3[8] + 4 * kk_1);
      sub_42E350(v2, (HIDWORD(v33) ^ v33) - HIDWORD(v33), v3[6]);
      kk_1 = kk + 1;
    }
  }
  return 0;
}

