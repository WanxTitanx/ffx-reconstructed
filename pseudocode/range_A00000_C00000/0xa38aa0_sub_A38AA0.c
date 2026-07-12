// Function: sub_A38AA0
// Address: 0xa38aa0
// Size: 0x13d
// Prototype: int __cdecl(int, int, void *Src, int, int, int, int, int)

int __cdecl sub_A38AA0(int a1, int a2, void *Src, int *a4, int a5, int a6, float a7, int a8)
{
  int *v8; // esi
  int v9; // edi
  int v10; // edx
  int v11; // eax
  int v12; // esi
  _DWORD *v13; // eax
  float v14; // edx
  int v15; // eax
  int result; // eax
  int v17; // edx
  _DWORD *v18; // ecx
  const void *Src_1; // [esp+50h] [ebp-14h]
  float v20; // [esp+50h] [ebp-14h]
  float v21; // [esp+54h] [ebp-10h]
  float v22; // [esp+58h] [ebp-Ch]

  v8 = (int *)dword_1A858B4[1];
  v9 = a1;
  v10 = *(_DWORD *)(a1 + 28);
  if ( v10 )
  {
    (*(void (__stdcall **)(int *, _DWORD, int, int))(*v8 + 32))(v8, 0, 1, v10 + 4);
    (*(void (__stdcall **)(int *, _DWORD, int, _DWORD *))(*v8 + 40))(v8, 0, 1, dword_1A858B4 + 493);
  }
  else
  {
    v11 = *v8;
    a1 = 0;
    (*(void (__stdcall **)(int *, _DWORD, int, int *))(v11 + 32))(v8, 0, 1, &a1);
  }
  v12 = a2;
  (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)dword_1A858B4[1] + 36))(
    dword_1A858B4[1],
    dword_1A858B4[2 * a2 + 129],
    0,
    0);
  v13 = (_DWORD *)sub_A3CEC0(dword_1A858B4[613]);
  v14 = a7;
  *v13 = *(_DWORD *)LODWORD(a7);
  v13[1] = *(_DWORD *)(LODWORD(v14) + 4);
  v13[2] = *(_DWORD *)(LODWORD(v14) + 8);
  Src_1 = Src;
  v13[3] = *(_DWORD *)(LODWORD(v14) + 12);
  memcpy(v13 + 4, Src_1, 16 * v12);
  v15 = dword_1A858B4[1];
  a2 = dword_1A858B4[613];
  (*(void (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v15 + 60))(v15, a2, 0);
  (*(void (__stdcall **)(_DWORD, int, int, int *))(*(_DWORD *)dword_1A858B4[1] + 64))(dword_1A858B4[1], 1, 1, &a2);
  a7 = (float)a4[3];
  v22 = a7;
  a7 = (float)a4[2];
  v21 = a7;
  a7 = (float)a4[1];
  v20 = a7;
  a7 = (float)*a4;
  result = sub_A36090(a5, a8, a7, v20, v21, v22);
  v17 = *(_DWORD *)(v9 + 28);
  if ( v17 )
  {
    v18 = dword_1A858B4;
    *(_DWORD *)(v17 + 40) = dword_1A858B4[688];
    result = v18[689];
    *(_DWORD *)(v17 + 44) = result;
  }
  return result;
}

