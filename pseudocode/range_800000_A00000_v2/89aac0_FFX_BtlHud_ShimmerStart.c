// Function: FFX_BtlHud_ShimmerStart
// Address: 0x89aac0
void FFX_BtlHud_ShimmerStart()
{
  if ( n2_4 != 2 )
  {
    n2_4 = 2;
    if ( !FFX_BtlEffect_CheckEffect(-2147483570) )
      FFX_BtlEffect_Enable(-2147483570);
  }
}
