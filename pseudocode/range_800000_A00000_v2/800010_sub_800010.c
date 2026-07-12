// Function: sub_800010
// Address: 0x800010
int sub_800010()
{
  int v0; // esi

  v0 = 0;
  if ( unk_23C3648 )
  {
    if ( unk_23C3648 != -1 )
      return 0x2000;
    if ( sub_885E40(0) )
      return 4096;
    unk_23C3648 = 0;
  }
  if ( unk_23C364C )
  {
    if ( unk_23C364C != -1 )
      return 8193;
    if ( sub_885E40(0) )
      return 4097;
    unk_23C364C = 0;
  }
  if ( word_23C3642 )
    return word_23C3642;
  return v0;
}
