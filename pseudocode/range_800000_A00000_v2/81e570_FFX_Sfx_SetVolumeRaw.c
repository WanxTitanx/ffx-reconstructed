// Function: FFX_Sfx_SetVolumeRaw
// Address: 0x81e570
int __cdecl FFX_Sfx_SetVolumeRaw(int a1, int a2, char a3)
{
  return FFX_Sound_Cmd61_Volume(a2 & 0x7FFFFFFF, a3 & 0x7F);
}
