// Function: sub_A3A200
// Address: 0xa3a200
// Size: 0x32c
// Prototype: 

_DWORD *__stdcall sub_A3A200(_DWORD *a1, int a2)
{
  _DWORD *v2; // ebx
  int v3; // edx
  int v4; // ecx
  _DWORD *v5; // esi
  int v6; // eax
  int v7; // edi
  int *v8; // esi
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  BOOL v12; // eax
  int v13; // edi
  int v14; // edx
  BOOL v15; // ebx
  int v16; // eax
  int v17; // ebx
  int v18; // edx
  int v19; // eax
  int v20; // eax
  int v21; // ecx
  int v22; // edx
  int v23; // eax
  _DWORD *v25; // [esp+Ch] [ebp-174h]
  int v26; // [esp+14h] [ebp-16Ch]
  int v27; // [esp+1Ch] [ebp-164h]
  int v28; // [esp+20h] [ebp-160h]
  int v29; // [esp+24h] [ebp-15Ch]
  int v30; // [esp+2Ch] [ebp-154h]
  const char *CreateTexture2D; // [esp+2Ch] [ebp-154h]
  _DWORD v32[8]; // [esp+30h] [ebp-150h] BYREF
  _DWORD v33[3]; // [esp+50h] [ebp-130h] BYREF
  char v34[288]; // [esp+5Ch] [ebp-124h] BYREF

  v2 = a1;
  v3 = a1[19];
  v4 = *a1;
  v29 = a1[14];
  v5 = (_DWORD *)a1[6];
  v27 = a1[15];
  v6 = a1[20];
  v7 = 0;
  v25 = v5;
  v30 = *a1;
  v26 = v3;
  v28 = v6;
  if ( v3 > 0 )
  {
    v8 = v33;
    do
    {
      v8[3] = v4;
      v9 = v29 >> v7;
      if ( v29 >> v7 <= 1 )
        v9 = 1;
      v10 = v6 * v9;
      v8[4] = v10;
      v8[5] = 0;
      v11 = v27 >> v7;
      if ( v27 >> v7 <= 1 )
        v11 = 1;
      v4 = v11 * v10 + v30;
      v30 = v4;
      if ( v7 )
      {
        sub_A384D0(v8[3], v10, v29 >> v7, v27 >> v7, *v8, v8[1], v28);
        v4 = v30;
      }
      v3 = v26;
      v6 = v28;
      ++v7;
      v8 += 3;
    }
    while ( v7 < v26 );
    v5 = v25;
    v2 = a1;
  }
  v32[0] = v29;
  v32[1] = v27;
  v32[4] = v2[17];
  v12 = (v2[16] & 2) == 0;
  v32[2] = v3;
  v32[7] = v12;
  v32[3] = 1;
  v32[5] = 1;
  v32[6] = 0;
  v33[0] = 8;
  v33[1] = 0;
  v33[2] = 0;
  CreateTexture2D = "CreateTexture2D";
  v13 = (*(int (__stdcall **)(_DWORD, _DWORD *, char *, _DWORD *))(*(_DWORD *)*dword_1A858B4 + 20))(
          *dword_1A858B4,
          v32,
          v34,
          v5);
  if ( v13 < 0
    || (CreateTexture2D = "CreateShaderResourceView",
        v13 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD *))(*(_DWORD *)*dword_1A858B4 + 28))(
                *dword_1A858B4,
                *v5,
                0,
                v5 + 1),
        v13 < 0) )
  {
    if ( *v5 )
    {
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v5 + 8))(*v5);
      *v5 = 0;
    }
    v21 = v5[1];
    if ( v21 )
    {
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v21 + 8))(v5[1]);
      v5[1] = 0;
    }
    v22 = v5[6];
    *(_DWORD *)(v5[8] + 28) = v5[7];
    *(_DWORD *)(v5[7] + 32) = v5[8];
    v22 += 16;
    v5[7] = v22;
    v23 = *(_DWORD *)(v22 + 32);
    v5[8] = v23;
    *(_DWORD *)(v23 + 28) = v5;
    *(_DWORD *)(v5[7] + 32) = v5;
    v5[12] &= 0xFFFFFFFu;
    v5 = 0;
    if ( v13 == -2147024882 )
      IggyGDrawSendWarning(0, "GDraw D3D out of memory in %s%s", CreateTexture2D, " while creating texture");
    else
      IggyGDrawSendWarning(0, "GDraw D3D error in %s%s: 0x%08x", CreateTexture2D, " while creating texture", v13);
  }
  else
  {
    v14 = a1[18];
    v15 = (v2[16] & 4) != 0;
    v16 = v14 ^ v5[12];
    v5[5] = a1[7];
    v5[12] ^= v16 & 0xFFFFFFF;
    *(_DWORD *)v5[6] -= v14;
    v17 = 2 * v15 + 2;
    v18 = v5[6] + 8 * (7 * v17 + 2);
    *(_DWORD *)(v5[8] + 28) = v5[7];
    *(_DWORD *)(v5[7] + 32) = v5[8];
    v5[7] = v18;
    v19 = *(_DWORD *)(v18 + 32);
    v5[8] = v19;
    *(_DWORD *)(v19 + 28) = v5;
    *(_DWORD *)(v5[7] + 32) = v5;
    v20 = (v17 << 28) | v5[12] & 0xFFFFFFF;
    v2 = a1;
    v5[12] = v20;
    *(_WORD *)a2 |= 4u;
    ++*(_WORD *)(a2 + 10);
    *(_DWORD *)(a2 + 28) += a1[18];
  }
  IggyGDrawFree(*v2);
  return v5;
}

