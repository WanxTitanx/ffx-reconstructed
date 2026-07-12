// Function: sub_A28FF0
// Address: 0xa28ff0
// Size: 0x33
// Prototype: 

int __thiscall sub_A28FF0(char *this)
{
  char *v1; // esi
  int n5; // edi
  int result; // eax

  v1 = this + 16;
  n5 = 5;
  do
  {
    if ( *(v1 - 12) )
    {
      result = (*((int (__cdecl **)(_DWORD, _DWORD, _DWORD))v1 + 1))(
                 *((_DWORD *)v1 - 2),
                 *((_DWORD *)v1 - 1),
                 *(_DWORD *)v1);
      *(v1 - 12) = 0;
    }
    v1 += 20;
    --n5;
  }
  while ( n5 );
  return result;
}

