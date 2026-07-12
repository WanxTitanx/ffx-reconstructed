// Function: sub_A387E0
// Address: 0xa387e0
// Size: 0x2bf
// Prototype: int __stdcall(int, size_t Size, int, int)

int __stdcall sub_A387E0(int a1, size_t Size, int a3, _WORD *a4)
{
  bool v4; // zf
  int v5; // ebx
  size_t Size_1; // edi
  int v7; // esi
  int result; // eax
  int v9; // esi
  _DWORD *v10; // eax
  int v11; // ebx
  int v12; // ecx
  int v13; // esi
  int v14; // edx
  int v15; // eax
  _WORD *v16; // ecx
  size_t Size_2; // esi
  void *v18; // eax
  _DWORD *v19; // esi
  size_t Size_5; // eax
  size_t Size_3; // esi
  void *v22; // eax
  int v23; // esi
  int v24; // esi
  int v25; // ebx
  int v26; // esi
  void *v27; // eax
  _DWORD *v28; // edi
  int v29; // eax
  int v30; // edi
  int v31; // [esp+Ch] [ebp-10h] BYREF
  int v32; // [esp+10h] [ebp-Ch]
  size_t Size_4; // [esp+14h] [ebp-8h] BYREF
  int v34; // [esp+18h] [ebp-4h] BYREF

  v4 = (*(_BYTE *)(a1 + 4) & 0x10) == 0;
  v5 = dword_1A858B4[1];
  Size_1 = Size;
  v32 = v5;
  v7 = *(_DWORD *)(Size + 16);
  if ( v4 )
  {
    result = sub_A3C6C0(v7, a1, a4, &unk_B7A828);
    if ( !result )
      return result;
  }
  else
  {
    (*(void (__stdcall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v5 + 44))(v5, dword_1A858B4[2 * v7 + 157], 0, 0);
  }
  v34 = dword_C6D50C[v7];
  (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)v5 + 68))(v5, dword_1A858B4[v7 + 152]);
  v9 = a3;
  if ( a3 )
  {
    Size = *(_DWORD *)Size_1;
    (*(void (__stdcall **)(int, _DWORD, int, int, int *, size_t *))(*(_DWORD *)v5 + 72))(v5, 0, 1, a3, &v34, &Size);
    (*(void (__stdcall **)(int, _DWORD, int, _DWORD))(*(_DWORD *)v5 + 76))(
      v5,
      *(_DWORD *)(v9 + 4),
      57,
      *(_DWORD *)(Size_1 + 4));
LABEL_6:
    (*(void (__stdcall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v5 + 48))(v5, *(_DWORD *)(Size_1 + 12), 0, 0);
    goto LABEL_7;
  }
  if ( *(_DWORD *)(Size_1 + 4) )
  {
    Size_2 = v34 * *(_DWORD *)(Size_1 + 8);
    Size = 2 * *(_DWORD *)(Size_1 + 12);
    v18 = (void *)sub_A3CF40(dword_1A858B4 + 614, Size_2);
    if ( !v18 )
      goto LABEL_7;
    memcpy(v18, *(const void **)Size_1, Size_2);
    v19 = dword_1A858B4;
    (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)dword_1A858B4[1] + 60))(
      dword_1A858B4[1],
      dword_1A858B4[614],
      0);
    Size_5 = v19[616];
    Size_3 = Size;
    Size_4 = Size_5;
    v22 = (void *)sub_A3CF40(dword_1A858B4 + 618, Size);
    if ( !v22 )
      goto LABEL_7;
    memcpy(v22, *(const void **)(Size_1 + 4), Size_3);
    v23 = sub_A362C0(dword_1A858B4 + 618);
    (*(void (__stdcall **)(int, _DWORD, int, _DWORD *, int *, size_t *))(*(_DWORD *)v5 + 72))(
      v5,
      0,
      1,
      dword_1A858B4 + 614,
      &v34,
      &Size_4);
    (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)v5 + 76))(v5, dword_1A858B4[618], 57, v23);
    goto LABEL_6;
  }
  (*(void (__stdcall **)(int, _DWORD, int, _DWORD))(*(_DWORD *)v5 + 76))(v5, dword_1A858B4[488], 57, 0);
  v10 = dword_1A858B4;
  if ( !dword_1A858B4[624] )
    goto LABEL_8;
  v24 = *(_DWORD *)(Size_1 + 8);
  v25 = 0;
  if ( v24 <= 0 )
    goto LABEL_8;
  while ( 1 )
  {
    v26 = v24 - v25;
    if ( v26 >= v10[624] )
      v26 = v10[624];
    Size_4 = v34 * v26;
    v27 = (void *)sub_A3CF40(v10 + 614, v34 * v26);
    if ( v27 )
    {
      memcpy(v27, (const void *)(*(_DWORD *)Size_1 + v34 * v25), Size_4);
      v28 = dword_1A858B4;
      (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)dword_1A858B4[1] + 60))(
        dword_1A858B4[1],
        dword_1A858B4[614],
        0);
      v29 = v28[616];
      v30 = v32;
      v31 = v29;
      (*(void (__stdcall **)(int, _DWORD, int, _DWORD *, int *, int *))(*(_DWORD *)v32 + 72))(
        v32,
        0,
        1,
        dword_1A858B4 + 614,
        &v34,
        &v31);
      (*(void (__stdcall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)v30 + 48))(v30, 6 * (v26 >> 2), 0, 0);
      Size_1 = Size;
    }
    v25 += v26;
    v24 = *(_DWORD *)(Size_1 + 8);
    if ( v25 >= v24 )
      break;
    v10 = dword_1A858B4;
  }
LABEL_7:
  v10 = dword_1A858B4;
LABEL_8:
  v11 = a3;
  v12 = *(_DWORD *)(a1 + 32);
  v13 = v10[688];
  v14 = *(_DWORD *)(a1 + 28);
  v15 = v10[689];
  if ( a3 )
  {
    *(_DWORD *)(a3 + 40) = v13;
    *(_DWORD *)(v11 + 44) = v15;
  }
  if ( v14 )
  {
    *(_DWORD *)(v14 + 40) = v13;
    *(_DWORD *)(v14 + 44) = v15;
  }
  if ( v12 )
  {
    *(_DWORD *)(v12 + 40) = v13;
    *(_DWORD *)(v12 + 44) = v15;
  }
  v16 = a4;
  *a4 |= 1u;
  ++v16[1];
  *((_DWORD *)v16 + 4) += *(_DWORD *)(Size_1 + 12);
  result = *(_DWORD *)(Size_1 + 8);
  *((_DWORD *)v16 + 5) += result;
  return result;
}

