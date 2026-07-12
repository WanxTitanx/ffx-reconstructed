// Function: sub_840680
// Address: 0x840680
_DWORD *__cdecl sub_840680(int a1, int a2, _DWORD *a3, _DWORD *a4, _DWORD *a5, _DWORD *a6)
{
  _DWORD *result; // eax
  _DWORD *v7; // edx

  result = &unk_1302F58;
  while ( 1 )
  {
    v7 = (_DWORD *)*result;
    if ( *(_DWORD *)*result == a2 && *((char *)v7 + 4) == a1 )
      break;
    if ( (int)++result >= (int)byte_13030E8 )
      return result;
  }
  v7[4] = 0;
  *a3 = v7 + 4;
  v7[6] = 0;
  *a5 = v7 + 6;
  v7[7] = 0;
  *a6 = v7 + 7;
  v7[5] = 0;
  *a4 = v7 + 5;
  v7[8] = 0;
  return a4;
}
