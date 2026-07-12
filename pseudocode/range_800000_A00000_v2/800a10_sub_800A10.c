// Function: sub_800A10
// Address: 0x800a10
_DWORD *__cdecl sub_800A10(_DWORD *a1, int a2)
{
  _DWORD *result; // eax
  int v3; // edx
  int n64; // esi

  result = a1;
  v3 = a2 - (_DWORD)a1;
  n64 = 64;
  do
  {
    *(_DWORD *)((char *)result + v3) = *result;
    *(_DWORD *)((char *)result + v3 + 4) = result[1];
    *(_DWORD *)((char *)result + v3 + 8) = result[2];
    *(_DWORD *)((char *)result + v3 + 12) = result[3];
    result += 4;
    --n64;
  }
  while ( n64 );
  return result;
}
