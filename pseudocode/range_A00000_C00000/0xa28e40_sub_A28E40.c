// Function: sub_A28E40
// Address: 0xa28e40
// Size: 0x44
// Prototype: 

char __thiscall sub_A28E40(char *this, int a2, int a3, int a4, int a5)
{
  int v5; // eax
  _BYTE *i; // edx
  char *v8; // ecx

  v5 = 0;
  for ( i = this + 4; *i; i += 20 )
  {
    if ( (unsigned int)++v5 >= 5 )
      return 0;
  }
  v8 = this + 20 * v5;
  *((_DWORD *)v8 + 2) = a2;
  *((_DWORD *)v8 + 3) = a3;
  *((_DWORD *)v8 + 4) = a4;
  *((_DWORD *)v8 + 5) = a5;
  v8[4] = 1;
  return 1;
}

