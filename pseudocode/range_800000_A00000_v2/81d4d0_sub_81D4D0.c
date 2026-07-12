// Function: sub_81D4D0
// Address: 0x81d4d0
int __cdecl sub_81D4D0(char *a1)
{
  char *v1; // eax
  int v2; // edx
  char v3; // cl

  v1 = a1;
  v2 = off_C49458 - (_UNKNOWN *)a1;
  do
  {
    v3 = *v1;
    v1[v2] = *v1;
    ++v1;
  }
  while ( v3 );
  return sub_81CCE0(7);
}
