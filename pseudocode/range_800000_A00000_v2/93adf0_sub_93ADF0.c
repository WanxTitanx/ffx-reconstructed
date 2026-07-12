// Function: sub_93ADF0
// Address: 0x93adf0
int __cdecl sub_93ADF0(int a1, int a2)
{
  int result; // eax
  int v3; // eax
  int v4; // eax

  sub_92BA30(a2);
  for ( result = sub_92BFB0(a2); !result; result = sub_92BFB0(a2) )
  {
    v3 = sub_92BE40(a2, off_C60E94); // "Type"
    if ( v3 )
    {
      v4 = v3 - 1;
      if ( v4 )
      {
        result = v4 - 1;
        if ( !result )
          return result;
      }
      else
      {
        *(_BYTE *)(a1 + 11) = sub_92BC50(a2);
      }
    }
    else
    {
      *(_BYTE *)(a1 + 10) = sub_92BC50(a2);
    }
  }
  return result;
}
