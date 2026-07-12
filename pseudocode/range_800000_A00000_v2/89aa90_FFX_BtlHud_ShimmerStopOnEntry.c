// Function: FFX_BtlHud_ShimmerStopOnEntry
// Address: 0x89aa90
int FFX_BtlHud_ShimmerStopOnEntry()
{
  int result; // eax

  n2_4 = 1;
  result = FFX_BtlEffect_CheckEffect(-2147483570);
  if ( result )
    return FFX_BtlEffect_Disable(-2147483570);
  return result;
}
