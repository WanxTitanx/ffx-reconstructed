// Function: sub_A3BED0
// Address: 0xa3bed0
// Size: 0x197
// Prototype: 

void *__cdecl sub_A3BED0(int a1, int a2, int a3)
{
  int v3; // esi
  _DWORD *v4; // eax
  int v5; // eax
  void *result; // eax
  float v7; // [esp+6Ch] [ebp-14h]
  void *v8; // [esp+74h] [ebp-Ch] BYREF
  float v9; // [esp+90h] [ebp+10h]
  float v10; // [esp+90h] [ebp+10h]

  v3 = dword_1A858B4[1];
  (*(void (__stdcall **)(int, _DWORD, void *, int))(*(_DWORD *)v3 + 140))(v3, dword_1A858B4[501], &unk_B7A3F8, -1);
  (*(void (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v3 + 144))(v3, a2, 0);
  v4 = dword_1A858B4;
  dword_1A858B4[626] = 0;
  if ( a3 )
    sub_A3CE00(v4[434], v4[435], v4[438], v4[439]);
  else
    sub_A3CE00(0, 0, v4[440], v4[441]);
  sub_A3C450(0, dword_1A858B4[432], dword_1A858B4[433], 0);
  (*(void (__stdcall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v3 + 36))(v3, 0, 0, 0);
  v5 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, int, _DWORD, void **))(*(_DWORD *)dword_1A858B4[1] + 56))(
         dword_1A858B4[1],
         dword_1A858B4[610],
         0,
         4,
         0,
         &v8);
  if ( v5 >= 0 )
  {
    result = v8;
    if ( v8 )
    {
      memset(v8, 0, 0x40u);
      (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)dword_1A858B4[1] + 60))(
        dword_1A858B4[1],
        dword_1A858B4[610],
        0);
      (*(void (__stdcall **)(int, _DWORD, int, _DWORD *))(*(_DWORD *)v3 + 64))(v3, 0, 1, dword_1A858B4 + 610);
      v9 = (float)(int)dword_1A858B4[441];
      v7 = v9;
      v10 = (float)(int)dword_1A858B4[440];
      return (void *)sub_A36090((int)&unk_B7A3F8, a1, 0.0, 0.0, v10, v7);
    }
  }
  else if ( v5 == -2147024882 )
  {
    return (void *)IggyGDrawSendWarning(0, "GDraw D3D out of memory in %s%s", "Map", "of buffer");
  }
  else
  {
    return (void *)IggyGDrawSendWarning(0, "GDraw D3D error in %s%s: 0x%08x", "Map", "of buffer", v5);
  }
  return result;
}

