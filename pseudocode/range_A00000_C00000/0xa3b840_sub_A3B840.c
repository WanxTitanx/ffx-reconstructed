// Function: sub_A3B840
// Address: 0xa3b840
// Size: 0x1ce
// Prototype: 

int __cdecl sub_A3B840(int a1)
{
  int v1; // ecx
  int v2; // eax
  const char *CreateTexture2D; // ecx
  _DWORD *v4; // edx
  _DWORD *v6; // esi
  int v7; // ecx
  int v8; // ecx
  _DWORD *v9; // eax
  _DWORD v10[11]; // [esp+30h] [ebp-30h] BYREF

  if ( dword_1A858B4[482] )
    return dword_1A858B4[482];
  v1 = *dword_1A858B4;
  v10[0] = dword_1A858B4[432];
  v10[1] = dword_1A858B4[433];
  v10[2] = 1;
  v10[3] = 1;
  v10[4] = 45;
  v10[5] = 1;
  v10[6] = 0;
  v10[7] = 0;
  v10[8] = 64;
  v10[9] = 0;
  v10[10] = 0;
  v2 = (*(int (__stdcall **)(int, _DWORD *, _DWORD, _DWORD *))(*(_DWORD *)v1 + 20))(v1, v10, 0, dword_1A858B4 + 485);
  CreateTexture2D = "CreateTexture2D";
  if ( v2 < 0
    || (v2 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD *))(*(_DWORD *)*dword_1A858B4 + 40))(
               *dword_1A858B4,
               dword_1A858B4[485],
               0,
               dword_1A858B4 + 482),
        CreateTexture2D = "CreateDepthStencilView while creating rendertarget",
        v2 < 0) )
  {
    if ( v2 == -2147024882 )
      IggyGDrawSendWarning(0, "GDraw D3D out of memory in %s%s", CreateTexture2D, &byte_B8FBDB);
    else
      IggyGDrawSendWarning(0, "GDraw D3D error in %s%s: 0x%08x", CreateTexture2D, &byte_B8FBDB, v2);
    v6 = dword_1A858B4;
    v7 = dword_1A858B4[485];
    if ( v7 )
    {
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v7 + 8))(dword_1A858B4[485]);
      v6[485] = 0;
      v6 = dword_1A858B4;
    }
    v8 = v6[482];
    if ( v8 )
    {
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v8 + 8))(v6[482]);
      v9 = dword_1A858B4;
      v6[482] = 0;
      return v9[482];
    }
    else
    {
      return 0;
    }
  }
  else
  {
    v4 = dword_1A858B4;
    *(_WORD *)a1 |= 4u;
    ++*(_WORD *)(a1 + 10);
    *(_DWORD *)(a1 + 28) += 4 * v4[432] * v4[433];
    (*(void (__stdcall **)(_DWORD, _DWORD, int, _DWORD, _DWORD))(*(_DWORD *)v4[1] + 212))(v4[1], v4[482], 3, 1.0, 0);
    return dword_1A858B4[482];
  }
}

