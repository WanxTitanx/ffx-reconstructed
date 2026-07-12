// Function: FFX_BtlHud_ShimmerResetAll
// Address: 0x897e70
int FFX_BtlHud_ShimmerResetAll()
{
  int result; // eax

  unk_133F748 = 0.0;
  MEMORY[0x133F74C] = 0.0;
  MEMORY[0x133F750] = 0.0;
  MEMORY[0x133F754] = 0.0;
  unk_133F744 = 0;
  FFX_BtlHud_GetAnimTiming(2, (int)"dum201", &word_133F740, &word_133F742);
  n2_4 = 0;
  result = FFX_BtlEffect_CheckEffect(-2147483570);
  if ( result )
    return FFX_BtlEffect_Disable(-2147483570);
  return result;
}
