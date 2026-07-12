// Function: sub_99B3C0
// Address: 0x99b3c0
int __thiscall sub_99B3C0(int *this, int a2)
{
  int i; // esi
  int result; // eax
  int v5; // ecx

  for ( i = 0; i < *(this + 3); ++i )
  {
    result = *(this + 5);
    v5 = *(_DWORD *)(result + 4 * i);
    if ( v5 )
      result = (*(int (__thiscall **)(int, int))(*(_DWORD *)v5 + 12))(v5, a2);
  }
  return result;
}
