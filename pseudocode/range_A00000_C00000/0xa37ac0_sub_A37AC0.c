// Function: sub_A37AC0
// Address: 0xa37ac0
// Size: 0x56
// Prototype: 

int __stdcall sub_A37AC0(_DWORD *a1)
{
  int v1; // ecx
  _WORD v3[24]; // [esp+4h] [ebp-30h] BYREF

  v1 = a1[1];
  if ( v1 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v1 + 8))(a1[1]);
    a1[1] = 0;
  }
  if ( *a1 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*a1 + 8))(*a1);
    *a1 = 0;
  }
  memset(v3, 0, sizeof(v3));
  return sub_A3B480(a1, v3);
}

