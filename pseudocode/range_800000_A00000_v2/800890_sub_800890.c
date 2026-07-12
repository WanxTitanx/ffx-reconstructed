// Function: sub_800890
// Address: 0x800890
int sub_800890()
{
  char *v0; // edi
  _DWORD *v1; // esi
  _DWORD *v2; // eax

  *(_DWORD *)off_C3A4C4 = &unk_12F2030;
  v0 = (char *)dword_12EA030;
  v1 = dword_12E9C30;
  do
  {
    if ( *v1 )
    {
      v2 = off_C3A4C4;
      *v1 = 0;
      *v2 = &unk_12F2030;
      FFX_MagicHost_ClearResourceBufferList((int)v0);
    }
    ++v1;
    v0 += 128;
  }
  while ( (int)v1 < (int)dword_12EA030 );
  return 0;
}
