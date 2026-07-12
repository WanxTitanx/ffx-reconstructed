// Function: sub_A3DFB0
// Address: 0xa3dfb0
// Size: 0x64
// Prototype: 

char __thiscall sub_A3DFB0(int this, unsigned int *a2, unsigned int a3, int a4, unsigned int *a5, HANDLE *a6)
{
  unsigned int v7; // eax
  char result; // al
  unsigned int v9; // edx

  *a2 = a3 + a4 + 4;
  while ( 1 )
  {
    v7 = *a5;
    if ( a3 > *a5 )
      v7 += *(_DWORD *)(this + 48);
    if ( *a2 < v7 )
      break;
    if ( !*(_BYTE *)(this + 44) )
      return 0;
    PhyreEvent_WaitForever(a6);
  }
  v9 = *(_DWORD *)(this + 48);
  result = 1;
  if ( *a2 >= v9 )
    *a2 -= v9;
  return result;
}

