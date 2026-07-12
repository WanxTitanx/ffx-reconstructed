// Function: sub_A417D0
// Address: 0xa417d0
// Size: 0x37
// Prototype: 

void __stdcall sub_A417D0(void *a1)
{
  void *v1; // edi
  _DWORD *v2; // esi

  v1 = a1;
  v2 = a1;
  if ( !*((_BYTE *)a1 + 13) )
  {
    do
    {
      sub_A417D0(v2[2]);
      v2 = (_DWORD *)*v2;
      FFX_Memory_Free(v1);
      v1 = v2;
    }
    while ( !*((_BYTE *)v2 + 13) );
  }
}

