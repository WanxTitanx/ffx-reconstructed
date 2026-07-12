// Function: sub_A3C280
// Address: 0xa3c280
// Size: 0x86
// Prototype: int(void)

_DWORD *sub_A3C280()
{
  int v0; // edi
  int i; // esi
  _DWORD *result; // eax

  v0 = dword_1A858B4[1];
  (*(void (__stdcall **)(int))(*(_DWORD *)v0 + 440))(v0);
  (*(void (__stdcall **)(int, int))(*(_DWORD *)v0 + 96))(v0, 4);
  (*(void (__stdcall **)(int, int, int, _DWORD *))(*(_DWORD *)v0 + 32))(v0, 7, 1, dword_1A858B4 + 487);
  (*(void (__stdcall **)(int, int, int, _DWORD *))(*(_DWORD *)v0 + 40))(v0, 7, 1, dword_1A858B4 + 493);
  for ( i = 0; i < 3; ++i )
    (*(void (__stdcall **)(int, int, int, _DWORD *))(*(_DWORD *)v0 + 40))(v0, i, 1, dword_1A858B4 + 493);
  result = dword_1A858B4;
  dword_1A858B4[625] = -1;
  result[626] = -1;
  return result;
}

