// Function: sub_89A260
// Address: 0x89a260
int __cdecl sub_89A260(_BYTE *a1)
{
  int n16; // eax

  for ( n16 = 0; n16 < 16; ++n16 )
  {
    if ( n16 )
      unk_133F758[n16] = a1[n16] + *((_BYTE *)&unk_133F757 + n16) - 48;
    else
      unk_133F758[0] = *a1 - 48;
  }
  return n16;
}
