// Function: FFX_Sound_PlaySfx
// Address: 0x81e5f0
int __cdecl FFX_Sound_PlaySfx(int a1, int a2, char n63, char n127)
{
  if ( !++unk_12F4E3C )
    unk_12F4E3C = 1;
  FFX_Sound_Cmd51_Play(a2 & 0x7FFFFFFF, n127 & 0x7F, n63 & 0x7F);
  unk_12F4F24 |= 1u;
  return unk_12F4E3C;
}
