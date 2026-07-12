// Function: sub_8405B0
// Address: 0x8405b0
_DWORD *__cdecl sub_8405B0(int a1, int a2, int a3)
{
  _DWORD *result; // eax
  _DWORD *v4; // edx

  result = &unk_1302F58;
  while ( 1 )
  {
    v4 = (_DWORD *)*result;
    if ( *(_DWORD *)*result == a2 && *((char *)v4 + 4) == a1 )
      break;
    if ( (int)++result >= (int)byte_13030E8 )
      return result;
  }
  v4[8] = a3;
  return (_DWORD *)a3;
}
