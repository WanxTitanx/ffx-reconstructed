// Function: sub_A23C60
// Address: 0xa23c60
// Size: 0x59
// Prototype: 

int __thiscall sub_A23C60(_DWORD *this, int a2, int a3, int a4)
{
  int *v4; // esi
  int v6; // ecx

  v4 = (int *)(a2 + *(this + 9) - *(_DWORD *)(*(this + 3) + 136));
  if ( a4 < 0 )
    return 5;
  v6 = v4[1];
  if ( v6 != a3 && *v4 >= 0 )
    Phyre_Memory_AlignedFree(v6);
  v4[1] = a3;
  *v4 = a4 | 0x80000000;
  return 0;
}

