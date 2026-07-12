// Function: sub_800010
// Address: 0x800010
// Size: 0x74

int sub_800010()
{
  int v0; // esi

  v0 = 0; /*0x800016*/
  if ( unk_23C3648 ) /*0x80001a*/
  {
    if ( unk_23C3648 != -1 ) /*0x80001f*/
      return 0x2000; /*0x800064*/
    if ( sub_885E40(0) ) /*0x800022*/
      return 4096; /*0x800034*/
    unk_23C3648 = 0; /*0x800035*/
  }
  if ( unk_23C364C ) /*0x800042*/
  {
    if ( unk_23C364C != -1 ) /*0x800047*/
      return 8193; /*0x80007d*/
    if ( sub_885E40(0) ) /*0x80004b*/
      return 4097; /*0x80005d*/
    unk_23C364C = 0; /*0x800065*/
  }
  if ( word_23C3642 ) /*0x800074*/
    return word_23C3642; /*0x800076*/
  return v0; /*0x800033*/
}
