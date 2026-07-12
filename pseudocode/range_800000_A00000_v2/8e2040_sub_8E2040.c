// Function: sub_8E2040
// Address: 0x8e2040
int sub_8E2040()
{
  __int16 n4096; // dx
  int n16; // eax
  __int16 v2; // cx

  if ( unk_1871514 )
  {
    n4096_0 += 341;
    if ( n4096_0 > 4096 )
      n4096_0 = 4096;
    n4096 = 4096;
    for ( n16 = 0; n16 < 16; n16 += 2 )
    {
      v2 = *(_WORD *)((char *)word_1871628 + n16);
      if ( v2 )
      {
        *(_WORD *)((char *)word_1871628 + n16) = v2 - 1;
      }
      else
      {
        *(_WORD *)((char *)word_1871638 + n16) += 227;
        if ( *(__int16 *)((char *)word_1871638 + n16) > 4096 )
          *(_WORD *)((char *)word_1871638 + n16) = 4096;
      }
      n4096 &= *(_WORD *)((char *)word_1871638 + n16);
    }
    n4096_1 = n4096;
  }
  else
  {
    n16 = (n4096_0 - 341) & ((n4096_0 - 341 < 0) - 1);
    n4096_0 = n16;
  }
  return n16;
}
