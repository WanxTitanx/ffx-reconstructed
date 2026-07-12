// Function: sub_A35C90
// Address: 0xa35c90
// Size: 0x308
// Prototype: 

int sub_A35C90()
{
  _DWORD *v0; // esi
  int i; // edi
  int v2; // ecx
  _DWORD *v3; // ebx
  int j; // edi
  int v5; // ecx
  _DWORD *v6; // ebx
  int k; // edi
  int v8; // ecx
  _DWORD *v9; // ebx
  int m; // edi
  int v11; // ecx
  _DWORD *v12; // ebx
  int v13; // ecx
  int v14; // ecx
  int n156; // ebx
  int n; // edi
  int v17; // ecx
  int v18; // ecx
  int result; // eax
  int ii; // edi
  int v21; // ecx
  _DWORD *v22; // ebx
  int jj; // edi
  int v24; // ecx
  _DWORD *v25; // ebx
  int kk; // edi
  int v27; // ecx
  _DWORD *v28; // ebx
  int mm; // edi
  int v30; // ecx
  _DWORD *v31; // ebx
  int v32; // ecx
  int v33; // ecx
  int v34; // ecx
  int v35; // ecx
  int v36; // ecx
  int v37; // ecx
  int v38; // ecx
  _DWORD *v39; // [esp+Ch] [ebp-4h]
  _DWORD *v40; // [esp+Ch] [ebp-4h]

  v0 = dword_1A858B4;
  for ( i = 0; i < 36; i += 2 )
  {
    v2 = v0[i + 3];
    v3 = &v0[i];
    if ( v2 )
    {
      (*(void (__stdcall **)(int))(*(_DWORD *)v2 + 8))(v2);
      v0 = dword_1A858B4;
      v3[3] = 0;
    }
  }
  for ( j = 38; j < 64; j += 2 )
  {
    v5 = v0[j + 1];
    v6 = &v0[j];
    if ( v5 )
    {
      (*(void (__stdcall **)(int))(*(_DWORD *)v5 + 8))(v5);
      v0 = dword_1A858B4;
      v6[1] = 0;
    }
  }
  for ( k = 64; k < 128; k += 2 )
  {
    v8 = v0[k + 1];
    v9 = &v0[k];
    if ( v8 )
    {
      (*(void (__stdcall **)(int))(*(_DWORD *)v8 + 8))(v8);
      v0 = dword_1A858B4;
      v9[1] = 0;
    }
  }
  for ( m = 128; m < 148; m += 2 )
  {
    v11 = v0[m + 1];
    v12 = &v0[m];
    if ( v11 )
    {
      (*(void (__stdcall **)(int))(*(_DWORD *)v11 + 8))(v11);
      v0 = dword_1A858B4;
      v12[1] = 0;
    }
  }
  v13 = v0[149];
  if ( v13 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v13 + 8))(v0[149]);
    v0[149] = 0;
    v0 = dword_1A858B4;
  }
  v14 = v0[151];
  if ( v14 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v14 + 8))(v0[151]);
    v0[151] = 0;
    v0 = dword_1A858B4;
  }
  n156 = 156;
  for ( n = 152; n < 155; ++n )
  {
    v17 = v0[n];
    v39 = &v0[n];
    if ( v17 )
    {
      (*(void (__stdcall **)(int))(*(_DWORD *)v17 + 8))(v17);
      v0 = dword_1A858B4;
      *v39 = 0;
    }
    v18 = v0[n156 + 1];
    result = (int)&v0[n156];
    v40 = &v0[n156];
    if ( v18 )
    {
      (*(void (__stdcall **)(int))(*(_DWORD *)v18 + 8))(v18);
      result = (int)&v0[n156];
      v0 = dword_1A858B4;
      v40[1] = 0;
    }
    n156 += 2;
  }
  for ( ii = 491; ii < 493; ++ii )
  {
    v21 = v0[ii];
    v22 = &v0[ii];
    if ( v21 )
    {
      result = (*(int (__stdcall **)(int))(*(_DWORD *)v21 + 8))(v21);
      v0 = dword_1A858B4;
      *v22 = 0;
    }
  }
  for ( jj = 493; jj < 501; ++jj )
  {
    v24 = v0[jj];
    v25 = &v0[jj];
    if ( v24 )
    {
      result = (*(int (__stdcall **)(int))(*(_DWORD *)v24 + 8))(v24);
      v0 = dword_1A858B4;
      *v25 = 0;
    }
  }
  for ( kk = 501; kk < 507; ++kk )
  {
    v27 = v0[kk];
    v28 = &v0[kk];
    if ( v27 )
    {
      result = (*(int (__stdcall **)(int))(*(_DWORD *)v27 + 8))(v27);
      v0 = dword_1A858B4;
      *v28 = 0;
    }
  }
  for ( mm = 508; mm < 512; ++mm )
  {
    v30 = v0[mm];
    v31 = &v0[mm];
    if ( v30 )
    {
      result = (*(int (__stdcall **)(int))(*(_DWORD *)v30 + 8))(v30);
      v0 = dword_1A858B4;
      *v31 = 0;
    }
  }
  v32 = v0[507];
  if ( v32 )
  {
    result = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v32 + 8))(v0[507]);
    v0[507] = 0;
    v0 = dword_1A858B4;
  }
  v33 = v0[609];
  if ( v33 )
  {
    result = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v33 + 8))(v0[609]);
    v0[609] = 0;
    v0 = dword_1A858B4;
  }
  v34 = v0[610];
  if ( v34 )
  {
    result = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v34 + 8))(v0[610]);
    v0[610] = 0;
    v0 = dword_1A858B4;
  }
  v35 = v0[611];
  if ( v35 )
  {
    result = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v35 + 8))(v0[611]);
    v0[611] = 0;
    v0 = dword_1A858B4;
  }
  v36 = v0[612];
  if ( v36 )
  {
    result = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v36 + 8))(v0[612]);
    v0[612] = 0;
    v0 = dword_1A858B4;
  }
  v37 = v0[613];
  if ( v37 )
  {
    result = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v37 + 8))(v0[613]);
    v0[613] = 0;
    v0 = dword_1A858B4;
  }
  v38 = v0[488];
  if ( v38 )
  {
    result = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v38 + 8))(v0[488]);
    v0[488] = 0;
  }
  return result;
}

