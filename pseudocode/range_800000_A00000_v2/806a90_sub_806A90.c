// Function: sub_806A90
// Address: 0x806a90
void __stdcall sub_806A90(void *a1)
{
  void *v1; // edi
  _DWORD *v2; // esi

  v1 = a1;
  v2 = a1;
  if ( !*((_BYTE *)a1 + 13) )
  {
    do
    {
      sub_806A90(v2[2]);
      v2 = (_DWORD *)*v2;
      FFX_Memory_Free(v1);
      v1 = v2;
    }
    while ( !*((_BYTE *)v2 + 13) );
  }
}
