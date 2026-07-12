// Function: sub_89AD00
// Address: 0x89ad00
int sub_89AD00()
{
  int result; // eax

  n2_4 = 1;
  if ( FFX_BtlEffect_CheckEffect(-2147483570) )
    FFX_BtlEffect_Disable(-2147483570);
  FFX_BtlHud_SubmenuStateClear();
  result = sub_8AF570(0);
  unk_133C908 = 0;
  return result;
}
