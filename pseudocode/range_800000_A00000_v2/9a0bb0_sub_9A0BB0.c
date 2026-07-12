// Function: sub_9A0BB0
// Address: 0x9a0bb0
int __thiscall sub_9A0BB0(int *this, _DWORD *a2)
{
  int v2; // esi
  int v3; // edx
  _DWORD *i; // ecx

  v2 = *(this + 1);
  v3 = 0;
  if ( v2 <= 0 )
    return *(this + 1);
  for ( i = (_DWORD *)*(this + 3); *i != *a2 || i[1] != a2[1]; i += 4 )
  {
    if ( ++v3 >= v2 )
      return v2;
  }
  return v3;
}
