// Function: sub_A41690
// Address: 0xa41690
// Size: 0x85
// Prototype: 

int __cdecl sub_A41690(_DWORD *a1, int *a2)
{
  int v2; // eax
  int v4; // eax
  int v5; // ebx
  _DWORD *v6; // edi
  int v7; // esi
  _DWORD *Singleton; // eax

  v2 = sub_45F3C0();
  (*(void (__thiscall **)(int *, _DWORD *, unsigned int, int, _DWORD))(*a2 + 4))(
    a2,
    a1 + 12,
    (unsigned int)(*a1 + 3) >> 2,
    v2,
    0);
  v4 = sub_45F5A0();
  (*(void (__thiscall **)(int *, _DWORD *, _DWORD, int, _DWORD))(*a2 + 4))(
    a2,
    &a1[16 * ((unsigned int)(*a1 + 3) >> 2) + 12],
    a1[1],
    v4,
    0);
  v5 = a1[2];
  v6 = &a1[16 * ((unsigned int)(*a1 + 3) >> 2) + 12 + 4 * a1[1]];
  v7 = *a2;
  Singleton = Phyre_PTypeDefault_Uint8_GetSingleton();
  return (*(int (__thiscall **)(int *, _DWORD *, int, _DWORD *, _DWORD))(v7 + 4))(a2, v6, 4 * v5, Singleton, 0);
}

