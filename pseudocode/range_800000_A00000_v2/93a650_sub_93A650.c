// Function: sub_93A650
// Address: 0x93a650
int __cdecl sub_93A650(int a1, int a2)
{
  int v2; // ebx
  int result; // eax
  int v4; // eax
  int v5; // eax
  _BYTE *v6; // edi
  int v7; // [esp+8h] [ebp-4h]

  v2 = 0;
  v7 = 0;
  sub_92BA30(a2);
  for ( result = sub_92BFB0(a2); !result; result = sub_92BFB0(a2) )
  {
    v4 = sub_92BE40(a2, off_C60E84); // "DataCnt"
    if ( v4 )
    {
      v5 = v4 - 1;
      if ( v5 )
      {
        result = v5 - 1;
        if ( !result )
          return result;
      }
      else
      {
        sub_92BA30(a2);
        v6 = *(_BYTE **)(a1 + 12);
        if ( v2 > 0 )
        {
          do
          {
            *v6 = sub_92BC50(a2);
            v6[1] = sub_92BC50(a2);
            v6[2] = sub_92BC50(a2);
            v6[3] = sub_92BC50(a2);
            v6 += 4;
            --v2;
          }
          while ( v2 );
          v2 = v7;
        }
        sub_92BA30(a2);
      }
    }
    else
    {
      v2 = sub_92BC50(a2);
      v7 = v2;
      sub_9308D0(a1, v2);
    }
  }
  return result;
}
