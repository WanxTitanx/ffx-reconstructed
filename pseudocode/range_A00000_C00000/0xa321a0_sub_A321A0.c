// Function: sub_A321A0
// Address: 0xa321a0
// Size: 0x2e
// Prototype: 

_DWORD *sub_A321A0()
{
  if ( (dword_1A85540[0] & 1) == 0 )
  {
    dword_1A85540[0] |= 1u;
    dword_1A85538 = (char *)Size_5 + 1;
    unk_1A8553C = 0;
  }
  return &dword_1A85538;
}

