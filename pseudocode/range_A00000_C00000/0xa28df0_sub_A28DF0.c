// Function: sub_A28DF0
// Address: 0xa28df0
// Size: 0x46
// Prototype: 

char __thiscall sub_A28DF0(char *this, int a2, int a3)
{
  int v3; // eax
  _BYTE *i; // edx
  char *v6; // ecx

  v3 = 0;
  for ( i = this + 4; *i; i += 20 )
  {
    if ( (unsigned int)++v3 >= 5 )
      return 0;
  }
  v6 = this + 20 * v3;
  *((_DWORD *)v6 + 3) = a2;
  *((_DWORD *)v6 + 4) = a3;
  v6[4] = 1;
  *((_DWORD *)v6 + 2) = 0;
  *((_DWORD *)v6 + 5) = sub_A28C00;
  return 1;
}

