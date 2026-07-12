// Function: sub_8009D0
// Address: 0x8009d0
_DWORD *__cdecl sub_8009D0(int a1, _DWORD *a2)
{
  _DWORD *result; // eax
  int v3; // edx
  int n64; // esi

  result = a2;
  v3 = a1 - (_DWORD)a2;
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
