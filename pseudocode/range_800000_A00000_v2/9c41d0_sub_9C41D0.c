// Function: sub_9C41D0
// Address: 0x9c41d0
int __thiscall sub_9C41D0(int this, int a2)
{
  int v2; // eax
  int v3; // ebx
  int result; // eax
  int v5; // edi
  int v6; // esi
  int v7; // eax

  *(_DWORD *)(this + 16) = 0;
  *(_DWORD *)(this + 20) = 0;
  *(_WORD *)(this + 192) = 0;
  *(_DWORD *)(this + 64) = 0;
  *(_DWORD *)(this + 68) = 0;
  *(_DWORD *)(this + 72) = 0;
  *(_DWORD *)(this + 76) = 0;
  v2 = *(_DWORD *)(this + 8);
  *(_DWORD *)(this + 196) = 0;
  v3 = *(_DWORD *)(v2 + 304);
  for ( result = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 24))(v3);
        *(int *)(result + 4) > 0;
        result = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 24))(v3) )
  {
    v5 = *(_DWORD *)(a2 + 24);
    v6 = *(_DWORD *)((*(int (__thiscall **)(int))(*(_DWORD *)v3 + 24))(v3) + 12);
    v7 = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 24))(v3);
    (*(void (__thiscall **)(int, _DWORD, _DWORD, int))(*(_DWORD *)v3 + 8))(
      v3,
      **(_DWORD **)(v7 + 12),
      *(_DWORD *)(v6 + 4),
      v5);
  }
  return result;
}
