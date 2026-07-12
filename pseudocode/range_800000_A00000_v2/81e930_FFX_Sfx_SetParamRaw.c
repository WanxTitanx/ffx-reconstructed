// Function: FFX_Sfx_SetParamRaw
// Address: 0x81e930
int __cdecl FFX_Sfx_SetParamRaw(int a1, int a2, char a3)
{
  return FFX_Sound_Cmd59_Param(a2 & 0x7FFFFFFF, a3 & 0x7F);
}
