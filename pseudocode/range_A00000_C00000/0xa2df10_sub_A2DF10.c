// Function: sub_A2DF10
// Address: 0xa2df10
// Size: 0x2b
// Prototype: 

int __cdecl sub_A2DF10(int a1, const char **a2, _DWORD *a3)
{
  const char *v3; // edx

  v3 = *(const char **)(a1 + 4);
  *a3 = strlen(v3) + 1;
  *a2 = v3;
  return 0;
}

