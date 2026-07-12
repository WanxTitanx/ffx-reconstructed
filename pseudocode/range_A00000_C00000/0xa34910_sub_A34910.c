// Function: sub_A34910
// Address: 0xa34910
// Size: 0x1c
// Prototype: 

int __cdecl sub_A34910(_DWORD *a1)
{
  int result; // eax

  if ( *a1 )
  {
    result = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)*a1 + 8))(*a1);
    *a1 = 0;
  }
  return result;
}

