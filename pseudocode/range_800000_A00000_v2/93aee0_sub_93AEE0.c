// Function: sub_93AEE0
// Address: 0x93aee0
int __cdecl sub_93AEE0(_DWORD *a1, int a2)
{
  int result; // eax

  sub_92BA30(a2);
  result = sub_92BFB0(a2);
  if ( !result )
  {
    while ( 2 )
    {
      result = sub_92BE40(a2, off_C60E44); // "OffX"
      switch ( result )
      {
        case 0:
          a1[23] = sub_92BC50(a2);
          goto LABEL_6;
        case 1:
          a1[24] = sub_92BC50(a2);
          goto LABEL_6;
        case 2:
          a1[25] = sub_92BC50(a2);
          goto LABEL_6;
        case 3:
          return result;
        default:
LABEL_6:
          result = sub_92BFB0(a2);
          if ( result )
            return result;
          continue;
      }
    }
  }
  return result;
}
