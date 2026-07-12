// Function: sub_800890
// Address: 0x800890
// Size: 0x49

int sub_800890()
{
  char *buf__1; // edi
  _DWORD *buf_; // esi
  _DWORD *v2; // eax

  *(_DWORD *)off_C3A4C4 = dword_12F2030;
  buf__1 = (char *)buf__1;
  buf_ = buf__0;
  do
  {
    if ( *buf_ )
    {
      v2 = off_C3A4C4;
      *buf_ = 0;
      *v2 = dword_12F2030;
      FFX_MagicHost_ClearResourceBufferList((int)buf__1);
    }
    ++buf_;
    buf__1 += 128;
  }
  while ( (int)buf_ < (int)buf__1 );
  return 0;
}
