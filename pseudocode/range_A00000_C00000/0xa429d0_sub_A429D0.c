// Function: sub_A429D0
// Address: 0xa429d0
// Size: 0x2b
// Prototype: 

int __cdecl sub_A429D0(int a1)
{
  int v1; // esi

  v1 = a1 + *((_DWORD *)FFX_Btl_GetCoreWorkPtr() + 8);
  if ( *((_DWORD *)FFX_Btl_GetCoreWorkPtr() + 12) )
    return sub_A42C00(v1);
  else
    return 0;
}

