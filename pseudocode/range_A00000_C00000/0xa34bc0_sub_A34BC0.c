// Function: sub_A34BC0
// Address: 0xa34bc0
// Size: 0xd0
// Prototype: 

unsigned int __cdecl sub_A34BC0(_DWORD *a1)
{
  int v1; // esi
  unsigned int n1342177280; // eax
  int v3; // ecx
  int v4; // ecx
  int v5; // ecx
  int v6; // [esp+4h] [ebp-8h] BYREF
  int v7; // [esp+8h] [ebp-4h] BYREF

  v1 = *(_DWORD *)(unk_1A858B4 + 4);
  v6 = 0;
  v7 = 0;
  (*(void (__stdcall **)(int, _DWORD, int, void *))(*(_DWORD *)v1 + 32))(v1, 0, 3, &unk_1A858B8);
  (*(void (__stdcall **)(int, _DWORD, int, int *, int *, int *))(*(_DWORD *)v1 + 72))(v1, 0, 1, &v6, &v7, &v7);
  (*(void (__stdcall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v1 + 76))(v1, 0, 0, 0);
  n1342177280 = a1[12] & 0xF0000000;
  if ( n1342177280 != 1342177280 )
  {
    n1342177280 = a1[6];
    if ( (*(_BYTE *)(n1342177280 + 12) & 1) != 0 )
    {
      if ( *a1 )
      {
        n1342177280 = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)*a1 + 8))(*a1);
        *a1 = 0;
      }
      v5 = a1[1];
      if ( v5 )
      {
        n1342177280 = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v5 + 8))(a1[1]);
        a1[1] = 0;
      }
    }
    else
    {
      v3 = a1[1];
      if ( v3 )
      {
        n1342177280 = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v3 + 8))(a1[1]);
        a1[1] = 0;
      }
      v4 = a1[2];
      if ( v4 )
      {
        n1342177280 = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v4 + 8))(a1[2]);
        a1[2] = 0;
      }
      if ( *a1 )
      {
        n1342177280 = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)*a1 + 8))(*a1);
        *a1 = 0;
      }
    }
  }
  return n1342177280;
}

