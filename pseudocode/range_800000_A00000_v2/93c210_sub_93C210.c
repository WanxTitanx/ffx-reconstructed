// Function: sub_93C210
// Address: 0x93c210
int __cdecl sub_93C210(unsigned __int8 *a1, int a2)
{
  int v2; // ecx
  int result; // eax

  v2 = 0;
  switch ( a2 )
  {
    case 1:
      result = (char)*a1;
      break;
    case 2:
      result = *a1;
      break;
    case 3:
      result = *(__int16 *)a1;
      break;
    case 4:
      result = *(unsigned __int16 *)a1;
      break;
    case 5:
    case 6:
      v2 = *(_DWORD *)a1;
      goto LABEL_7;
    default:
LABEL_7:
      result = v2;
      break;
  }
  return result;
}
