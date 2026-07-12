// Function: sub_93AB80
// Address: 0x93ab80
int __cdecl sub_93AB80(int a1, int a2)
{
  int result; // eax

  sub_92BA30(a2);
  result = sub_92BFB0(a2);
  if ( !result )
  {
    while ( 2 )
    {
      result = sub_92BE40(a2, off_C60E58); // "Flag"
      switch ( result )
      {
        case 0:
          *(_DWORD *)a1 = sub_92BC50(a2) & 0xFFFFFFFD;
          goto LABEL_12;
        case 1:
          *(_DWORD *)(a1 + 12) = sub_92BC50(a2);
          goto LABEL_12;
        case 2:
          *(_DWORD *)(a1 + 16) = sub_92BC50(a2);
          goto LABEL_12;
        case 3:
          *(float *)(a1 + 20) = sub_92BBB0(a2);
          *(float *)(a1 + 24) = sub_92BBB0(a2);
          *(float *)(a1 + 28) = sub_92BBB0(a2);
          *(float *)(a1 + 32) = sub_92BBB0(a2);
          goto LABEL_12;
        case 4:
          *(_DWORD *)(a1 + 44) = sub_92BC50(a2);
          goto LABEL_12;
        case 5:
          *(_DWORD *)(a1 + 48) = sub_92BC50(a2);
          goto LABEL_12;
        case 6:
          *(_QWORD *)(a1 + 56) = (int)sub_92BC50(a2);
          goto LABEL_12;
        case 7:
          sub_93A650(a1 + 144, a2);
          goto LABEL_12;
        case 8:
          sub_93ADF0(a1 + 176, a2);
          goto LABEL_12;
        case 9:
          return result;
        default:
LABEL_12:
          result = sub_92BFB0(a2);
          if ( result )
            return result;
          continue;
      }
    }
  }
  return result;
}
