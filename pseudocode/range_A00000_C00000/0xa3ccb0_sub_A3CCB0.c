// Function: sub_A3CCB0
// Address: 0xa3ccb0
// Size: 0x5c
// Prototype: 

int __cdecl sub_A3CCB0(int a1, int a2, int a3, int a4)
{
  int v4; // edi

  v4 = dword_1A858B4[1];
  if ( a2 )
  {
    (*(void (__stdcall **)(int, int, int, int))(*(_DWORD *)v4 + 32))(v4, a1, 1, a2 + 4);
    return (*(int (__stdcall **)(int, int, int, _DWORD *))(*(_DWORD *)v4 + 40))(
             v4,
             a1,
             1,
             &dword_1A858B4[4 * a3 + 493 + a4]);
  }
  else
  {
    a2 = 0;
    return (*(int (__stdcall **)(int, int, int, int *))(*(_DWORD *)v4 + 32))(v4, a1, 1, &a2);
  }
}

