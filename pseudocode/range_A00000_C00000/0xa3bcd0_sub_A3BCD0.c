// Function: sub_A3BCD0
// Address: 0xa3bcd0
// Size: 0x66
// Prototype: _DWORD __cdecl(int n2)

_DWORD *__cdecl sub_A3BCD0(int n2)
{
  int n9; // ebx
  _DWORD *result; // eax
  _DWORD *v4; // esi
  void *n2a; // [esp+14h] [ebp+8h]

  n9 = dword_C6D448[2 * n2];
  n2a = *(&off_C6D44C + 2 * n2);
  result = (_DWORD *)IggyGDrawMallocAnnotated(
                       56 * n9 + 424,
                       "r:\\hg_code\\middleware_w32\\iggysdk\\gdraw\\gdraw_d3d1x_shared.inl",
                       2152);
  v4 = result;
  if ( result )
  {
    sub_A39BC0(result, n9, n2a);
    v4[3] ^= (v4[3] ^ (n2 == 2)) & 1;
    return v4;
  }
  return result;
}

