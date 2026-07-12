// Function: sub_9B7AC0
// Address: 0x9b7ac0
int __thiscall sub_9B7AC0(int this)
{
  int i_1; // ebx
  int i; // esi
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int n2; // edx
  int n2_1; // edx

  (*(void (__thiscall **)(_DWORD, int, _DWORD))(**(_DWORD **)(this + 180) + 4))(
    *(_DWORD *)(this + 180),
    this,
    *(_DWORD *)(this + 24));
  i_1 = *(_DWORD *)(this + 188);
  for ( i = 0; i < i_1; ++i )
  {
    v4 = *(_DWORD *)(*(_DWORD *)(this + 196) + 4 * i);
    v5 = *(_DWORD *)(v4 + 20);
    v6 = *(_DWORD *)(v4 + 24);
    if ( v5 && (*(_BYTE *)(v5 + 216) & 3) == 0 && v6 && (*(_BYTE *)(v6 + 216) & 3) == 0 )
    {
      if ( (n2 = *(_DWORD *)(v5 + 228), n2 != 2) && n2 != 5 || (n2_1 = *(_DWORD *)(v6 + 228), n2_1 != 2) && n2_1 != 5 )
        sub_9BC670(*(_DWORD *)(v5 + 220), *(_DWORD *)(v6 + 220));
    }
  }
  return (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(this + 180) + 8))(*(_DWORD *)(this + 180), this);
}
