// Function: sub_9BBFC0
// Address: 0x9bbfc0
void __thiscall sub_9BBFC0(_DWORD *this, int a2)
{
  int i; // esi
  _BYTE *v4; // ecx
  int v5; // eax
  int v6; // edi
  int v7; // eax
  int j_1; // ecx
  int v9; // edi
  int v10; // eax
  int v11; // esi
  int v12; // eax
  _BYTE *v13; // [esp+Ch] [ebp-4h]
  int j; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < *(this + 2); ++i )
  {
    v4 = *(_BYTE **)(*(this + 4) + 4 * i);
    v13 = v4;
    if ( (v4[244] & 2) != 0 )
    {
      v5 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)v4 + 12))(v4);
      v6 = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)a2 + 12))(a2, v5, 1);
      v7 = (*(int (__thiscall **)(_BYTE *, _DWORD, int))(*(_DWORD *)v13 + 16))(v13, *(_DWORD *)(v6 + 8), a2);
      (*(void (__thiscall **)(int, int, int, int, _BYTE *))(*(_DWORD *)a2 + 16))(a2, v6, v7, 1497645650, v13);
    }
  }
  j_1 = 0;
  for ( j = 0; j_1 < *(this + 47); j = j_1 )
  {
    v9 = *(_DWORD *)(*(this + 49) + 4 * j_1);
    v10 = (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 32))(v9);
    v11 = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)a2 + 12))(a2, v10, 1);
    v12 = (*(int (__thiscall **)(int, _DWORD, int))(*(_DWORD *)v9 + 36))(v9, *(_DWORD *)(v11 + 8), a2);
    (*(void (__thiscall **)(int, int, int, int, int))(*(_DWORD *)a2 + 16))(a2, v11, v12, 1397641027, v9);
    j_1 = j + 1;
  }
}
