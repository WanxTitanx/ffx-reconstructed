// Function: sub_9A1570
// Address: 0x9a1570
char __thiscall sub_9A1570(int this, _DWORD *a2)
{
  int v2; // eax

  v2 = *(_DWORD *)(this + 4);
  if ( *a2 == v2 || a2[1] == v2 )
    (*(void (__thiscall **)(_DWORD, _DWORD *, _DWORD))(**(_DWORD **)(this + 8) + 28))(
      *(_DWORD *)(this + 8),
      a2,
      *(_DWORD *)(this + 12));
  return 0;
}
