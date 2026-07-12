// Function: sub_A3B590
// Address: 0xa3b590
// Size: 0x76
// Prototype: int(void)

int sub_A3B590()
{
  int v0; // esi
  int v2; // [esp+0h] [ebp-8h] BYREF
  int v3; // [esp+4h] [ebp-4h] BYREF

  if ( !*(_DWORD *)dword_1A858B4[683] )
    return dword_1A858B4[480];
  v0 = dword_1A858B4[1];
  v2 = 0;
  v3 = 0;
  (*(void (__stdcall **)(int, _DWORD, int, void *))(*(_DWORD *)v0 + 32))(v0, 0, 3, &unk_1A858B8);
  (*(void (__stdcall **)(int, _DWORD, int, int *, int *, int *))(*(_DWORD *)v0 + 72))(v0, 0, 1, &v2, &v3, &v3);
  (*(void (__stdcall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v0 + 76))(v0, 0, 0, 0);
  return *(_DWORD *)(*(_DWORD *)dword_1A858B4[683] + 8);
}

