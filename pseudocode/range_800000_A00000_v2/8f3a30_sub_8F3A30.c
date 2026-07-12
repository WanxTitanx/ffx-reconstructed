// Function: sub_8F3A30
// Address: 0x8f3a30
_DWORD *sub_8F3A30()
{
  _DWORD *result; // eax

  if ( dword_C5D780 )
  {
    result = dword_187168C;
    if ( (unsigned int)dword_187168C >= unk_1871688 )
      return (_DWORD *)sub_8F5BC0();
  }
  return result;
}
