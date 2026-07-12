// Function: sub_89B510
// Address: 0x89b510
float *__cdecl sub_89B510(unsigned __int8 a1, int a2, int *a3)
{
  float *result; // eax
  float *v4; // edx
  int i; // eax
  bool v6; // cc
  int j; // ecx
  int i_1; // [esp+4h] [ebp-4h] BYREF

  i_1 = 0;
  result = FFX_Btl_GetPartyDataArray(a1, a2, &i_1);
  v4 = result;
  switch ( a2 )
  {
    case 6:
    case 17:
    case 20:
      *a3 = i_1;
      break;
    case 7:
    case 15:
      for ( i = i_1; i > 0; i_1 = --i )
      {
        if ( *((_WORD *)v4 + i - 1) != 255 )
          break;
      }
      v6 = i <= 0;
      *a3 = i;
      result = v4;
      if ( v6 )
        *a3 = 1;
      break;
    default:
      for ( j = i_1; j > 0; i_1 = --j )
      {
        if ( *((_WORD *)result + j - 1) != 255 )
          break;
      }
      *a3 = j;
      break;
  }
  return result;
}
