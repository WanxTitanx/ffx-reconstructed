// Function: sub_A946E0
// Address: 0xa946e0
// Size: 0x3ae
// Prototype: int __thiscall(_DWORD)

int *__thiscall sub_A946E0(_DWORD *this)
{
  _DWORD *this_1; // ebx
  int *v2; // esi
  unsigned int v3; // eax
  unsigned int v4; // ecx
  int v5; // edx
  int i; // ecx
  int v7; // eax
  int v8; // eax
  int v9; // ebx
  int v10; // edi
  int v11; // edx
  unsigned int j; // eax
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // eax
  int v17; // edi
  int v18; // edi
  int k; // edi
  int v20; // eax
  int v21; // edi
  int v22; // eax
  int v23; // edi
  bool v24; // zf
  int v27; // [esp+Ch] [ebp-8h]
  int n31; // [esp+10h] [ebp-4h]
  int v29; // [esp+10h] [ebp-4h]

  this_1 = this;
  v2 = (int *)calloc_0(1u, 0x28u);
  *(_QWORD *)v2 = 0;
  *((_QWORD *)v2 + 1) = 0;
  *((_QWORD *)v2 + 2) = 0;
  *((_QWORD *)v2 + 3) = 0;
  *((_QWORD *)v2 + 4) = 0;
  v2[9] = 1;
  if ( (_UNKNOWN *)sub_42EB10(this_1, 24) != &loc_564342 )
    goto LABEL_52;
  *v2 = sub_42EB10(this_1, 16);
  v3 = sub_42EB10(this_1, 24);
  v2[1] = v3;
  if ( v3 == -1 )
    goto LABEL_52;
  v4 = *v2;
  v5 = 0;
  if ( *v2 )
  {
    do
    {
      ++v5;
      v4 >>= 1;
    }
    while ( v4 );
  }
  for ( i = 0; v3; v3 >>= 1 )
    ++i;
  if ( i + v5 > 24 )
    goto LABEL_52;
  v7 = sub_42EB10(this_1, 1);
  if ( v7 )
  {
    if ( v7 != 1 )
      goto LABEL_52;
    v8 = sub_42EB10(this_1, 5);
    v9 = v8 + 1;
    if ( v8 == -1 )
      goto LABEL_52;
    v10 = 0;
    v2[2] = (int)malloc_0(v2[1]);
    if ( v2[1] > 0 )
    {
      n31 = v9 - 1;
      do
      {
        v11 = 0;
        for ( j = v2[1] - v10; j; j >>= 1 )
          ++v11;
        v13 = sub_42EB10(this, v11);
        v14 = v13;
        if ( v13 == -1 || n31 > 31 || v13 > v2[1] - v10 )
          goto LABEL_52;
        if ( v13 > 0 )
        {
          if ( (v13 - 1) >> n31 > 1 )
            goto LABEL_52;
          do
          {
            *(_BYTE *)(++v10 + v2[2] - 1) = v9;
            --v14;
          }
          while ( v14 );
        }
        LOBYTE(v9) = v9 + 1;
        ++n31;
      }
      while ( v10 < v2[1] );
    }
    this_1 = this;
  }
  else
  {
    v18 = sub_42EB10(this_1, 1);
    if ( (v2[1] * (4 * (v18 == 0) + 1) + 7) >> 3 > this_1[4] - (this_1[1] + 7) / 8 - *this_1 )
      goto LABEL_52;
    v2[2] = (int)malloc_0(v2[1]);
    if ( v18 )
    {
      for ( k = 0; k < v2[1]; ++k )
      {
        if ( sub_42EB10(this_1, 1) )
        {
          v20 = sub_42EB10(this_1, 5);
          if ( v20 == -1 )
            goto LABEL_52;
          *(_BYTE *)(k + v2[2]) = v20 + 1;
        }
        else
        {
          *(_BYTE *)(k + v2[2]) = 0;
        }
      }
    }
    else
    {
      v21 = 0;
      if ( v2[1] > 0 )
      {
        do
        {
          v22 = sub_42EB10(this_1, 5);
          if ( v22 == -1 )
            goto LABEL_52;
          *(_BYTE *)(v21 + v2[2]) = v22 + 1;
        }
        while ( ++v21 < v2[1] );
      }
    }
  }
  v15 = sub_42EB10(this_1, 4);
  v2[3] = v15;
  if ( !v15 )
    return v2;
  if ( (unsigned int)(v15 - 1) <= 1 )
  {
    v2[4] = sub_42EB10(this_1, 32);
    v2[5] = sub_42EB10(this_1, 32);
    v2[6] = sub_42EB10(this_1, 4) + 1;
    v16 = sub_42EB10(this_1, 1);
    v2[7] = v16;
    if ( v16 != -1 )
    {
      v17 = 0;
      v29 = 0;
      if ( v2[3] == 1 )
      {
        if ( *v2 )
        {
          v17 = sub_A929C0(v2);
          v29 = v17;
        }
        else
        {
          v17 = 0;
          v29 = 0;
        }
      }
      else if ( v2[3] == 2 )
      {
        v17 = v2[1] * *v2;
        v29 = v17;
      }
      if ( (v17 * v2[6] + 7) >> 3 <= this_1[4] - (this_1[1] + 7) / 8 - *this_1 )
      {
        v27 = 4 * v17;
        v2[8] = (int)malloc_0(4 * v17);
        v23 = 0;
        v24 = v29 == 0;
        if ( v29 > 0 )
        {
          do
          {
            ++v23;
            *(_DWORD *)(v2[8] + 4 * v23 - 4) = sub_42EB10(this_1, v2[6]);
          }
          while ( v23 < v29 );
          v24 = v29 == 0;
        }
        if ( v24 || *(_DWORD *)(v27 + v2[8] - 4) != -1 )
          return v2;
      }
    }
  }
LABEL_52:
  if ( v2[9] )
  {
    if ( v2[8] )
      free_1((void *)v2[8]);
    if ( v2[2] )
      free_1((void *)v2[2]);
    *(_QWORD *)v2 = 0;
    *((_QWORD *)v2 + 1) = 0;
    *((_QWORD *)v2 + 2) = 0;
    *((_QWORD *)v2 + 3) = 0;
    *((_QWORD *)v2 + 4) = 0;
    free_1(v2);
  }
  return 0;
}

