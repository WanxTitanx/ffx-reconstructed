// Function: FFX_BtlHud_ShimmerStopOnExit
// Address: 0x89ab10
int FFX_BtlHud_ShimmerStopOnExit()
{
  int result; // eax

  n2_4 = 1;
  result = FFX_BtlEffect_CheckEffect(-2147483570);
  if ( result )
    return FFX_BtlEffect_Disable(-2147483570);
  return result;
}
