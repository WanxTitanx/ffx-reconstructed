// Function: sub_9308D0
// Address: 0x9308d0
char *__cdecl sub_9308D0(int a1, int a2)
{
  char *result; // eax
  int v3; // edx

  result = (char *)sub_9258F0(*(void **)(a1 + 12), 4 * a2, (int)"..\\program\\src\\rcBg\\rcbgAnime.c", 54);
  v3 = *(_DWORD *)(a1 + 8);
  *(_DWORD *)(a1 + 12) = result;
  if ( a2 > v3 )
    result = (char *)memset(&result[4 * v3], 0, 4 * (a2 - v3));
  *(_DWORD *)(a1 + 8) = a2;
  return result;
}
