// Function: sub_A3BD40
// Address: 0xa3bd40
// Size: 0x189
// Prototype: 

void *__cdecl sub_A3BD40(int *a1, int a2)
{
  int v2; // edi
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  int v5; // eax
  void *result; // eax
  float v7; // [esp+64h] [ebp-24h]
  float v8; // [esp+68h] [ebp-20h]
  int v9; // [esp+6Ch] [ebp-1Ch]
  float v10; // [esp+6Ch] [ebp-1Ch]
  void *v11; // [esp+78h] [ebp-10h] BYREF
  float v12; // [esp+84h] [ebp-4h]

  v2 = dword_1A858B4[1];
  (*(void (__stdcall **)(int, _DWORD, void *, int))(*(_DWORD *)v2 + 140))(v2, dword_1A858B4[501], &unk_B7A3F8, -1);
  (*(void (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)v2 + 144))(v2, dword_1A858B4[508], 0);
  v3 = dword_1A858B4;
  v9 = dword_1A858B4[433];
  dword_1A858B4[626] = 0;
  sub_A3CE00(0, 0, v3[432], v9);
  v4 = dword_1A858B4;
  sub_A3C450(0, dword_1A858B4[432], dword_1A858B4[433], 0);
  (*(void (__stdcall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v2 + 36))(v2, v4[151], 0, 0);
  v5 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, int, _DWORD, void **))(*(_DWORD *)dword_1A858B4[1] + 56))(
         dword_1A858B4[1],
         dword_1A858B4[610],
         0,
         4,
         0,
         &v11);
  if ( v5 >= 0 )
  {
    result = v11;
    if ( v11 )
    {
      memset(v11, 0, 0x40u);
      (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)dword_1A858B4[1] + 60))(
        dword_1A858B4[1],
        dword_1A858B4[610],
        0);
      (*(void (__stdcall **)(int, _DWORD, int, _DWORD *))(*(_DWORD *)v2 + 64))(v2, 0, 1, dword_1A858B4 + 610);
      v12 = (float)a1[3];
      v10 = v12;
      v12 = (float)a1[2];
      v8 = v12;
      v12 = (float)a1[1];
      v7 = v12;
      v12 = (float)*a1;
      return (void *)sub_A36090((int)&unk_B7A3F8, a2, v12, v7, v8, v10);
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

