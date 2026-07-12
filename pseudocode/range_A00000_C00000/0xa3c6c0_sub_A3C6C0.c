// Function: sub_A3C6C0
// Address: 0xa3c6c0
// Size: 0x5ed
// Prototype: _DWORD __cdecl(int n2, int, int, float *)

int __cdecl sub_A3C6C0(int n2, int a2, int a3, float *a4)
{
  int *v4; // edi
  int v5; // ecx
  int v6; // ecx
  float *v7; // edx
  bool v8; // zf
  float *v9; // esi
  float *v10; // eax
  float *v11; // ecx
  float *v12; // eax
  float *v13; // ecx
  void *dst; // edi
  const void *src; // esi
  int v16; // edx
  int n5_1; // esi
  _DWORD *v18; // edx
  int v19; // esi
  int n5; // ecx
  int n2_1; // eax
  int v22; // esi
  int v23; // edx
  int *v24; // esi
  int v25; // eax
  int v26; // eax
  int v27; // ecx
  float *v28; // edx
  __int16 *v29; // eax
  _DWORD *v30; // ecx
  int v31; // eax
  int v32; // esi
  int v33; // edi
  int v34; // ecx
  int v35; // edx
  int v36; // eax
  int v37; // eax
  int v38; // edx
  int v39; // ecx
  _DWORD *v40; // esi
  int v41; // ecx
  int v42; // edx
  int v43; // eax
  int v44; // eax
  char v45; // dl
  unsigned int v46; // ecx
  int v47; // esi
  int v48; // eax
  int v50; // [esp-Ch] [ebp-7Ch]
  int v51; // [esp-Ch] [ebp-7Ch]
  float *v52; // [esp+Ch] [ebp-64h] BYREF
  float *v53; // [esp+18h] [ebp-58h] BYREF
  float v54; // [esp+24h] [ebp-4Ch]
  float v55; // [esp+28h] [ebp-48h]
  float v56; // [esp+2Ch] [ebp-44h]
  float v57; // [esp+30h] [ebp-40h]
  int *v58; // [esp+34h] [ebp-3Ch]
  int v59; // [esp+38h] [ebp-38h] BYREF
  float v60; // [esp+3Ch] [ebp-34h]
  float v61; // [esp+40h] [ebp-30h]
  double v62; // [esp+44h] [ebp-2Ch]
  _DWORD v63[4]; // [esp+4Ch] [ebp-24h] BYREF
  int v64; // [esp+5Ch] [ebp-14h] BYREF
  int v65; // [esp+60h] [ebp-10h]
  int v66; // [esp+64h] [ebp-Ch]
  int v67; // [esp+68h] [ebp-8h]

  v4 = (int *)dword_1A858B4[1];
  v5 = *v4;
  v50 = dword_1A858B4[2 * n2 + 157];
  v58 = v4;
  (*(void (__stdcall **)(int *, int, _DWORD, _DWORD))(v5 + 44))(v4, v50, 0, 0);
  v6 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, int, _DWORD, float **))(*(_DWORD *)dword_1A858B4[1] + 56))(
         dword_1A858B4[1],
         dword_1A858B4[609],
         0,
         4,
         0,
         &v53);
  if ( v6 >= 0 )
  {
    v7 = v53;
    if ( v53 )
    {
      v61 = (float)*(int *)a2;
      v8 = (*(_BYTE *)(a2 + 4) & 4) == 0;
      v9 = (float *)dword_1A858B4;
      HIDWORD(v62) = dword_1A858B4;
      v61 = 1.0 - (v61 + 1.0) * 0.0001220703125;
      if ( v8 )
      {
        v10 = *(float **)(a2 + 44);
        v11 = v53;
        v56 = v10[1];
        v55 = v10[2];
        v57 = v10[3];
        v54 = v10[4];
        v60 = v10[5];
        *v53 = *v10;
        v11[1] = v56;
        v11[2] = v61;
        v11[3] = v54;
        v11[4] = v55;
        v11[5] = v57;
        v11[6] = 0.0;
        v11[7] = v60;
      }
      else
      {
        v12 = v53;
        *v53 = *((float *)dword_1A858B4 + 489);
        v12[1] = 0.0;
        v12[2] = v61;
        v12[3] = 0.0;
        v12[4] = 0.0;
        v12[5] = v9[490];
        v12[6] = 0.0;
        v12[7] = 0.0;
      }
      v13 = *(float **)(a2 + 40);
      v7[8] = *v13;
      v7[9] = v13[1];
      v7[10] = v13[2];
      v7[11] = v13[3];
      if ( *(_BYTE *)(a2 + 8) )
      {
        v7[12] = *(float *)(a2 + 80);
        v7[13] = *(float *)(a2 + 84);
        v7[14] = *(float *)(a2 + 88);
        v7[15] = *(float *)(a2 + 92);
        v7[16] = *(float *)(a2 + 96);
        v7[17] = *(float *)(a2 + 100);
        v7[18] = *(float *)(a2 + 104);
        v7[19] = *(float *)(a2 + 108);
      }
      dst = v7 + 20;
      if ( *((_DWORD *)v9 + 479) )
        src = v9 + 467;
      else
        src = v9 + 455;
      v16 = HIDWORD(v62);
      qmemcpy(dst, src, 0x30u);
      (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(v16 + 4) + 60))(
        *(_DWORD *)(v16 + 4),
        *(_DWORD *)(v16 + 2436),
        0);
      v4 = v58;
      (*(void (__stdcall **)(int *, _DWORD, int, _DWORD *))(*v58 + 28))(v58, 0, 1, dword_1A858B4 + 609);
    }
  }
  else if ( v6 == -2147024882 )
  {
    IggyGDrawSendWarning(0, "GDraw D3D out of memory in %s%s", "Map", "of buffer");
  }
  else
  {
    IggyGDrawSendWarning(0, "GDraw D3D error in %s%s: 0x%08x", "Map", "of buffer", v6);
  }
  n5_1 = *(unsigned __int8 *)(a2 + 12);
  v18 = dword_1A858B4;
  if ( n5_1 != dword_1A858B4[626] )
  {
    dword_1A858B4[626] = n5_1;
    (*(void (__stdcall **)(int *, _DWORD, void *, int))(*v4 + 140))(v4, v18[n5_1 + 501], &unk_B7A3F8, -1);
    v18 = dword_1A858B4;
  }
  if ( n5_1 == 5 )
  {
    (*(void (__stdcall **)(int *, _DWORD, _DWORD, _DWORD))(*v4 + 36))(
      v4,
      v18[2 * *(unsigned __int8 *)(a2 + 13) + 39],
      0,
      0);
  }
  else
  {
    v19 = *(_DWORD *)(a2 + 24);
    n5 = *(unsigned __int8 *)(a2 + 9);
    n2_1 = 0;
    if ( v19 )
    {
      n2_1 = 1;
      if ( *(_WORD *)(v19 + 6) )
        n2_1 = 2;
    }
    v22 = v18[4 * n5 + 3 + 2 * n5 + 2 * n2_1];
    if ( *(_BYTE *)(a2 + 17) )
    {
      if ( n5 != 5 )
      {
        (*(void (__stdcall **)(int *, _DWORD, _DWORD, _DWORD))(*v4 + 36))(v4, 0, 0, 0);
        goto LABEL_27;
      }
      v51 = v18[507];
      v18[626] = -1;
      (*(void (__stdcall **)(int *, int, void *, int))(*v4 + 140))(v4, v51, &unk_B7A3F8, -1);
    }
    (*(void (__stdcall **)(int *, int, _DWORD, _DWORD))(*v4 + 36))(v4, v22, 0, 0);
  }
LABEL_27:
  v23 = *(_DWORD *)(a2 + 28);
  HIDWORD(v62) = *(unsigned __int8 *)(a2 + 10);
  LODWORD(v60) = *(unsigned __int8 *)(a2 + 11);
  v24 = (int *)dword_1A858B4[1];
  if ( v23 )
  {
    (*(void (__stdcall **)(int *, _DWORD, int, int))(*v24 + 32))(v24, 0, 1, v23 + 4);
    (*(void (__stdcall **)(int *, _DWORD, int, _DWORD *))(*v24 + 40))(
      v24,
      0,
      1,
      &dword_1A858B4[4 * LODWORD(v60) + 493 + HIDWORD(v62)]);
  }
  else
  {
    v25 = *v24;
    v59 = 0;
    (*(void (__stdcall **)(int *, _DWORD, int, int *))(v25 + 32))(v24, 0, 1, &v59);
  }
  v26 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, int, _DWORD, float **))(*(_DWORD *)dword_1A858B4[1] + 56))(
          dword_1A858B4[1],
          dword_1A858B4[610],
          0,
          4,
          0,
          &v52);
  if ( v26 >= 0 )
  {
    v28 = v52;
    if ( v52 )
    {
      *v52 = *(float *)(a2 + 48);
      v28[1] = *(float *)(a2 + 52);
      v28[2] = *(float *)(a2 + 56);
      v28[3] = *(float *)(a2 + 60);
      v29 = *(__int16 **)(a2 + 24);
      if ( v29 )
      {
        HIDWORD(v62) = *v29;
        v62 = (double)SHIDWORD(v62);
        v28[4] = v62 / 255.0;
        HIDWORD(v62) = *(__int16 *)(*(_DWORD *)(a2 + 24) + 2);
        v62 = (double)SHIDWORD(v62);
        v28[5] = v62 / 255.0;
        HIDWORD(v62) = *(__int16 *)(*(_DWORD *)(a2 + 24) + 4);
        v62 = (double)SHIDWORD(v62);
        v28[6] = v62 / 255.0;
        HIDWORD(v62) = *(__int16 *)(*(_DWORD *)(a2 + 24) + 6);
        v62 = (double)SHIDWORD(v62);
        v28[7] = v62 / 255.0;
      }
      else
      {
        v28[7] = 0.0;
        v28[6] = 0.0;
        v28[5] = 0.0;
        v28[4] = 0.0;
      }
      if ( *(_BYTE *)(a2 + 9) == 4 )
      {
        v28[8] = *(float *)(a2 + 112);
        v28[9] = *(float *)(a2 + 116);
        v28[10] = *(float *)(a2 + 120);
        v28[11] = *(float *)(a2 + 124);
      }
      if ( *(_BYTE *)(a2 + 12) == 5 )
      {
        v28[12] = *a4;
        v28[13] = a4[1];
        v28[14] = a4[2];
        v28[15] = a4[3];
      }
      (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)dword_1A858B4[1] + 60))(
        dword_1A858B4[1],
        dword_1A858B4[610],
        0);
      (*(void (__stdcall **)(int *, _DWORD, int, _DWORD *))(*v4 + 64))(v4, 0, 1, dword_1A858B4 + 610);
    }
  }
  else if ( v26 == -2147024882 )
  {
    IggyGDrawSendWarning(0, "GDraw D3D out of memory in %s%s", "Map", "of buffer");
  }
  else
  {
    IggyGDrawSendWarning(0, "GDraw D3D error in %s%s: 0x%08x", "Map", "of buffer", v26);
  }
  if ( (*(_BYTE *)(a2 + 4) & 8) != 0 )
  {
    v30 = dword_1A858B4;
    v8 = dword_1A858B4[683] == (_DWORD)(dword_1A858B4 + 627);
    dword_1A858B4[625] = 1;
    v31 = *(_DWORD *)(a2 + 64);
    if ( v8 )
    {
      v32 = v30[442];
      v33 = v30[434];
      v34 = v30[443];
      v35 = dword_1A858B4[435];
      v64 = v33 + v31 - v32;
      v65 = v35 + *(_DWORD *)(a2 + 68) - v34;
      v36 = v33 + *(_DWORD *)(a2 + 72) - v32;
      v4 = v58;
      v66 = v36;
      v37 = v35 + *(_DWORD *)(a2 + 76) - v34;
    }
    else
    {
      v38 = v30[444];
      v39 = v30[445];
      v64 = v31 - v38;
      v65 = *(_DWORD *)(a2 + 68) - v39;
      v66 = *(_DWORD *)(a2 + 72) - v38;
      v37 = *(_DWORD *)(a2 + 76) - v39;
    }
    v67 = v37;
    (*(void (__stdcall **)(int *, int, int *))(*v4 + 180))(v4, 1, &v64);
    v40 = dword_1A858B4;
  }
  else
  {
    v40 = dword_1A858B4;
    if ( dword_1A858B4[625] )
    {
      v41 = dword_1A858B4[447];
      v42 = dword_1A858B4[448];
      v63[2] = v41 + dword_1A858B4[449];
      v43 = dword_1A858B4[450];
      v63[1] = v42;
      v63[3] = v42 + v43;
      v44 = dword_1A858B4[1];
      v63[0] = v41;
      (*(void (__stdcall **)(int, int, _DWORD *))(*(_DWORD *)v44 + 180))(v44, 1, v63);
      v40 = dword_1A858B4;
      dword_1A858B4[625] = 0;
    }
  }
  LOBYTE(v27) = *(_BYTE *)(a2 + 16);
  v45 = *(_BYTE *)(a2 + 17);
  v8 = *(_WORD *)(a2 + 16) == 0;
  v59 = v27;
  v46 = *(_DWORD *)(a2 + 4);
  if ( v8 )
  {
    (*(void (__stdcall **)(int *, _DWORD, _DWORD))(*v4 + 144))(v4, v40[2 * ((v46 >> 1) & 1) + 508 + (v46 & 1)], 0);
  }
  else
  {
    v47 = *v4;
    v48 = sub_A3D020((v46 >> 1) & 1, v46 & 1, v59, v45);
    (*(void (__stdcall **)(int *, int, int))(v47 + 144))(v4, v48, 255);
  }
  return 1;
}

