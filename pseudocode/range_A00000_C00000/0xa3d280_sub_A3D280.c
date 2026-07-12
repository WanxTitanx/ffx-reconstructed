// Function: sub_A3D280
// Address: 0xa3d280
// Size: 0x50
// Prototype: int(void)

int sub_A3D280()
{
  int v0; // esi
  int v2; // [esp+4h] [ebp-8h] BYREF
  int v3; // [esp+8h] [ebp-4h] BYREF

  v0 = dword_1A858B4[1];
  v2 = 0;
  v3 = 0;
  (*(void (__stdcall **)(int, _DWORD, int, void *))(*(_DWORD *)v0 + 32))(v0, 0, 3, &unk_1A858B8);
  (*(void (__stdcall **)(int, _DWORD, int, int *, int *, int *))(*(_DWORD *)v0 + 72))(v0, 0, 1, &v2, &v3, &v3);
  return (*(int (__stdcall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v0 + 76))(v0, 0, 0, 0);
}

