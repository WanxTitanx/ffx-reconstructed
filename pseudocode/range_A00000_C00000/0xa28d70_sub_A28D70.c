// Function: sub_A28D70
// Address: 0xa28d70
// Size: 0x33
// Prototype: 

void __cdecl sub_A28D70(_DWORD *a1, const char *a2)
{
  if ( a1 )
  {
    *a1 = 5;
    a1[2] = a2;
    a1[3] = strlen(a2);
  }
}

