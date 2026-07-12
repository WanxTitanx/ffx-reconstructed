// Function: sub_93C270
// Address: 0x93c270
_BYTE *__cdecl sub_93C270(_BYTE *a1, int a2, int a3)
{
  _BYTE *result; // eax

  result = (_BYTE *)(a2 - 1);
  switch ( a2 )
  {
    case 1:
    case 2:
      *a1 = a3;
      result = a1;
      break;
    case 3:
    case 4:
      *(_WORD *)a1 = a3;
      result = a1;
      break;
    case 5:
    case 6:
      *(_DWORD *)a1 = a3;
      result = a1;
      break;
    default:
      return result;
  }
  return result;
}
