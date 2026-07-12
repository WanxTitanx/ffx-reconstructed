// Function: sub_9A34A0
// Address: 0x9a34a0
int __thiscall sub_9A34A0(int this, int a2, int a3)
{
  int *v4; // ecx
  int v5; // ecx
  int v6; // eax
  int v7; // ecx
  int result; // eax

  v4 = (int *)(this + 44);
  if ( *(_DWORD *)(a2 + 60) != 2 )
    v4 = (int *)(this + 4);
  sub_989750(v4, *(_DWORD **)(a2 + 48));
  v5 = *(_DWORD *)(a2 + 52);
  v6 = *(_DWORD *)(a2 + 56);
  if ( v5 )
    *(_DWORD *)(v5 + 56) = v6;
  else
    *(_DWORD *)(this + 4 * *(_DWORD *)(a2 + 60) + 84) = v6;
  v7 = *(_DWORD *)(a2 + 56);
  if ( v7 )
    *(_DWORD *)(v7 + 52) = *(_DWORD *)(a2 + 52);
  (*(void (__thiscall **)(_DWORD, int, int))(**(_DWORD **)(this + 96) + 12))(*(_DWORD *)(this + 96), a2, a3);
  result = sub_9D4D50(a2);
  *(_BYTE *)(this + 154) = 1;
  return result;
}
