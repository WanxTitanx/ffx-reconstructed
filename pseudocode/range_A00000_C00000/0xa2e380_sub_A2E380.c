// Function: sub_A2E380
// Address: 0xa2e380
// Size: 0x2b

int __cdecl sub_A2E380(int a1, const char **a2, _DWORD *a3)
{
  const char *v3; // edx

  v3 = *(const char **)(a1 + 4); /*0xa2e387*/
  *a3 = strlen(v3) + 1; /*0xa2e3a0*/
  *a2 = v3; /*0xa2e3a5*/
  return 0; /*0xa2e399*/
}