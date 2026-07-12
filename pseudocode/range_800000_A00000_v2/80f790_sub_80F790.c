// Function: sub_80F790
// Address: 0x80f790
char *__cdecl sub_80F790(int a1)
{
  int v1; // eax
  char *v2; // ecx
  int n4352; // edx

  v1 = sub_7FE890(a1, 0, 0);
  v2 = (char *)&unk_12A2280 + 32 * v1;
  n4352 = *((_DWORD *)v2 + 1);
  if ( n4352 == 4347 || n4352 == 4348 || n4352 == 4349 )
    return (char *)&unk_12A2280 + 32 * v1;
  else
    return n4352 != 4352 ? 0 : v2;
}
