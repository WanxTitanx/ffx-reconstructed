// Function: sub_A73D90
// Address: 0xa73d90
// Size: 0x674
// Prototype: 

int __cdecl sub_A73D90(int a1, int a2)
{
  int v2; // esi
  int v3; // eax
  _DWORD *v4; // eax
  int v5; // esi
  _DWORD *v6; // ecx
  int v7; // edi
  int *v8; // ebx
  int v9; // esi
  double v10; // st7
  int v11; // eax
  int v12; // eax
  int v13; // edi
  int v14; // ecx
  double v15; // st7
  double v16; // st6
  int v17; // edi
  int v18; // esi
  float *v19; // ecx
  int v20; // edx
  int v21; // ecx
  int v22; // ecx
  int v23; // eax
  int v24; // esi
  __int64 n2622; // [esp-14h] [ebp-A8h]
  __int64 v27; // [esp-4h] [ebp-98h]
  int v28; // [esp+10h] [ebp-84h]
  int v29; // [esp+18h] [ebp-7Ch]
  int v30; // [esp+20h] [ebp-74h]
  int v31; // [esp+24h] [ebp-70h]
  _DWORD *v32; // [esp+2Ch] [ebp-68h]
  int *v33; // [esp+30h] [ebp-64h]
  float v34; // [esp+30h] [ebp-64h]
  float v35; // [esp+30h] [ebp-64h]
  float v36; // [esp+34h] [ebp-60h]
  float v37; // [esp+34h] [ebp-60h]
  float v38; // [esp+34h] [ebp-60h]
  float v39; // [esp+34h] [ebp-60h]
  float v40; // [esp+34h] [ebp-60h]
  float v41; // [esp+34h] [ebp-60h]
  float v42; // [esp+34h] [ebp-60h]
  int v43; // [esp+34h] [ebp-60h]
  _BYTE v44[48]; // [esp+40h] [ebp-54h] BYREF
  _BYTE v45[12]; // [esp+70h] [ebp-24h] BYREF
  float v46; // [esp+7Ch] [ebp-18h]
  float v47; // [esp+80h] [ebp-14h] BYREF
  float v48; // [esp+84h] [ebp-10h]
  float v49; // [esp+88h] [ebp-Ch]

  v2 = *(_DWORD *)(a1 + 544);
  v36 = *(float *)(v2 + 60) * 0.000000476837158203125;
  v30 = v2;
  v28 = a1 + 128;
  sub_7EA610((void *)(a1 + 128), v36);
  sub_7E9760(a1 + 128, a1 + 128, v2 + 48, v2 + 144);
  v3 = sub_801E20(a1, v2);
  sub_7E82C0(a1 + 192, a1 + 704, v3);
  v4 = (_DWORD *)sub_7E6910(512);
  v5 = *(_DWORD *)(v2 + 188);
  v6 = v4;
  v4[4] = &unk_12A8D68;
  v7 = *(_DWORD *)(v5 + 4);
  v8 = (int *)(v5 + 32);
  v32 = v4;
  v31 = v5;
  v33 = (int *)(v5 + 32);
  if ( v7 > 0 )
  {
    v9 = v5 + 128;
    do
    {
      if ( !*(_WORD *)(a1 + 530) )
      {
        v10 = *(float *)(v9 + 16) + *(float *)v9;
        *(_DWORD *)(v9 + 80) += *(_DWORD *)(v9 + 84);
        v37 = v10;
        *(float *)v9 = v37;
        *(float *)(v9 - 16) = v37 + *(float *)(v9 - 16);
        v38 = *(float *)(v9 + 20) + *(float *)(v9 + 4);
        *(float *)(v9 + 4) = v38;
        *(float *)(v9 - 12) = v38 + *(float *)(v9 - 12);
        v39 = *(float *)(v9 + 24) + *(float *)(v9 + 8);
        *(float *)(v9 + 8) = v39;
        *(float *)(v9 - 8) = v39 + *(float *)(v9 - 8);
        v40 = *(float *)(v9 + 64) + *(float *)(v9 + 48);
        *(float *)(v9 + 48) = v40;
        *(float *)(v9 + 32) = v40 + *(float *)(v9 + 32);
        v41 = *(float *)(v9 + 68) + *(float *)(v9 + 52);
        *(float *)(v9 + 52) = v41;
        *(float *)(v9 + 36) = v41 + *(float *)(v9 + 36);
        v42 = *(float *)(v9 + 72) + *(float *)(v9 + 56);
        *(float *)(v9 + 56) = v42;
        *(float *)(v9 + 40) = v42 + *(float *)(v9 + 40);
      }
      sub_7E9440(v9 + 96, v28, v9 + 32);
      if ( *(_WORD *)(v31 + 18) )
      {
        if ( *(_WORD *)(v31 + 18) == 1 )
        {
          v11 = ((int)*(float *)(v9 - 8) & 0xFFF) + 1024;
          *(float *)(v9 + 144) = flt_C43BE0[v11] * *(float *)(v9 - 16);
          *(float *)(v9 + 152) = flt_C44BE0[v11 & 0xFFF] * *(float *)(v9 - 16);
          *(float *)(v9 + 148) = *(float *)(v9 - 12);
        }
      }
      else
      {
        *(float *)(v9 + 144) = *(float *)(v9 - 16);
        *(float *)(v9 + 148) = *(float *)(v9 - 12);
        *(float *)(v9 + 152) = *(float *)(v9 - 8);
      }
      --v7;
      v9 += 256;
    }
    while ( v7 > 0 );
    v8 = v33;
    v5 = v31;
    v6 = v32;
  }
  v6[8] = *(_DWORD *)(a2 + 84);
  v6[9] = *(_DWORD *)(v5 + 4);
  HIDWORD(v27) = v30;
  LODWORD(v27) = 0;
  v6[10] = 0;
  v12 = sub_645580(v27);
  v13 = v12;
  v29 = v12;
  if ( v12 && sub_63FF60(v12, 0, 3 * *(_DWORD *)(v5 + 4), 3 * *(_DWORD *)(v5 + 4)) )
  {
    v14 = 0;
    v43 = 0;
    if ( *(int *)(v5 + 4) > 0 )
    {
      v15 = 0.000244140625;
      v16 = 0.0;
      do
      {
        v34 = (float)v8[44];
        v35 = v34 * v15;
        if ( v35 > v16 )
        {
          sub_6ED4A0(v44, v8 + 48);
          v46 = 1.0;
          sub_6ED420(v45, v28, v45);
          v17 = 9 * v32[10];
          v18 = *(_DWORD *)(*(_DWORD *)(v29 + 148) + 12);
          *((float *)v8 + 15) = 1.0;
          *((float *)v8 + 11) = 1.0;
          *((float *)v8 + 7) = 1.0;
          sub_6ED420(&v47, v44, v8 + 4);
          *(float *)(v18 + 4 * v17) = v47;
          *(float *)(v18 + 4 * v17 + 4) = v48;
          *(float *)(v18 + 4 * v17 + 8) = v49;
          sub_6ED420(&v47, v44, v8 + 8);
          *(float *)(v18 + 4 * v17 + 12) = v47;
          *(float *)(v18 + 4 * v17 + 16) = v48;
          *(float *)(v18 + 4 * v17 + 20) = v49;
          sub_6ED420(&v47, v44, v8 + 12);
          *(float *)(v18 + 4 * v17 + 24) = v47;
          *(float *)(v18 + 4 * v17 + 28) = v48;
          *(float *)(v18 + 4 * v17 + 32) = v49;
          v13 = v29;
          v19 = (float *)(*(_DWORD *)(*(_DWORD *)(v29 + 148) + 20) + 48 * v32[10]);
          *v19 = (double)*(unsigned __int8 *)v8 * 0.00390625;
          v19[1] = (double)*((unsigned __int8 *)v8 + 1) * 0.00390625;
          v19[2] = (double)*((unsigned __int8 *)v8 + 2) * 0.00390625;
          v19[3] = (double)*((unsigned __int8 *)v8 + 3) * v35 * 0.00390625;
          v19[4] = (double)*((unsigned __int8 *)v8 + 4) * 0.00390625;
          v19[5] = (double)*((unsigned __int8 *)v8 + 5) * 0.00390625;
          v19[6] = (double)*((unsigned __int8 *)v8 + 6) * 0.00390625;
          v19[7] = (double)*((unsigned __int8 *)v8 + 7) * v35 * 0.00390625;
          v19[8] = (double)*((unsigned __int8 *)v8 + 8) * 0.00390625;
          v19[9] = (double)*((unsigned __int8 *)v8 + 9) * 0.00390625;
          v19[10] = (double)*((unsigned __int8 *)v8 + 10) * 0.00390625;
          v19[11] = 0.00390625 * (v35 * (double)*((unsigned __int8 *)v8 + 11));
          v20 = 3 * v32[10];
          v21 = *(_DWORD *)(*(_DWORD *)(v29 + 148) + 24);
          v15 = 0.000244140625;
          *(float *)(v21 + 8 * v20) = (double)*((unsigned __int16 *)v8 + 32) * 0.000244140625;
          *(float *)(v21 + 8 * v20 + 4) = (double)*((unsigned __int16 *)v8 + 33) * 0.000244140625;
          *(float *)(v21 + 8 * v20 + 8) = (double)*((unsigned __int16 *)v8 + 34) * 0.000244140625;
          *(float *)(v21 + 8 * v20 + 12) = (double)*((unsigned __int16 *)v8 + 35) * 0.000244140625;
          *(float *)(v21 + 8 * v20 + 16) = (double)*((unsigned __int16 *)v8 + 36) * 0.000244140625;
          *(float *)(v21 + 8 * v20 + 20) = (double)*((unsigned __int16 *)v8 + 37) * 0.000244140625;
          v16 = 0.0;
          *(_WORD *)(*(_DWORD *)(*(_DWORD *)(v29 + 148) + 28) + 6 * v32[10]) = 3 * *((_WORD *)v32 + 20);
          *(_WORD *)(*(_DWORD *)(*(_DWORD *)(v29 + 148) + 28) + 6 * v32[10] + 2) = 2 * *((_WORD *)v32 + 20)
                                                                                 + *((_WORD *)v32 + 20)
                                                                                 + 1;
          *(_WORD *)(*(_DWORD *)(*(_DWORD *)(v29 + 148) + 28) + 6 * v32[10]++ + 4) = 2 * *((_WORD *)v32 + 20)
                                                                                   + 2
                                                                                   + *((_WORD *)v32 + 20);
          v5 = v31;
          v14 = v43;
        }
        ++v14;
        v8 += 64;
        v43 = v14;
      }
      while ( v14 < *(_DWORD *)(v5 + 4) );
    }
    v22 = v32[10];
    v23 = *(_DWORD *)(v5 + 4);
    if ( v22 < v23 )
      memset((void *)(*(_DWORD *)(*(_DWORD *)(v13 + 148) + 28) + 6 * v22), 0, 6 * (v23 - v22));
    *(_DWORD *)(v13 + 176) = 0;
    sub_6EDAE0(v13);
    v24 = v30;
    *(_DWORD *)(v13 + 128) = 0;
    *(float *)(v13 + 152) = -9999999.0;
    *(float *)(v13 + 156) = -9999999.0;
    *(float *)(v13 + 160) = -9999999.0;
    *(float *)(v13 + 164) = 9999999.0;
    *(float *)(v13 + 168) = 9999999.0;
    *(float *)(v13 + 172) = 9999999.0;
    sub_6458C0(0, v30, 1);
    HIDWORD(n2622) = v30;
    LODWORD(n2622) = 0;
    FFX_MagicHost_CommitDrawableResources(n2622);
  }
  else
  {
    v24 = v30;
  }
  *(_DWORD *)(a2 + 84) = v32[8];
  if ( !v32[10] )
  {
    *(_WORD *)(v30 + 176) |= *(_WORD *)(*(_DWORD *)(v30 + 168) + 2);
    sub_800C30(a2, *(_WORD *)(a1 + 532));
    --*(_WORD *)(a1 + 536);
    sub_645430(0, v24);
  }
  sub_7E6970(512);
  return 0;
}

