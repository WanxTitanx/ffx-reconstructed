// Function: sub_9B5A00
// Address: 0x9b5a00
int __thiscall sub_9B5A00(void *this, int *a2)
{
  int v2; // esi
  int v4; // eax
  int v5; // esi
  int v6; // eax

  v2 = *a2;
  v4 = (*(int (__thiscall **)(void *, int))(*(_DWORD *)this + 12))(this, 1);
  v5 = (*(int (__thiscall **)(int *, int))(v2 + 12))(a2, v4);
  v6 = (*(int (__thiscall **)(void *, _DWORD, int *))(*(_DWORD *)this + 16))(this, *(_DWORD *)(v5 + 8), a2);
  return (*(int (__thiscall **)(int *, int, int, int, void *))(*a2 + 16))(a2, v5, v6, 1497645650, this);
}
