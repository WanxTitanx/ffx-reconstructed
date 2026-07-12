// Function: FFX_BtlQueue_SignedActionEvent
// Address: 0x8935d0
int __cdecl FFX_BtlQueue_SignedActionEvent(int KernelString_Table0_1)
{
  int KernelString_Table0; // eax

  sub_8B5770(7, 0, 1);
  sub_8B57A0(7, 0, KernelString_Table0_1);
  if ( KernelString_Table0_1 >= 0 )
    KernelString_Table0 = KernelString_Table0_1;
  else
    KernelString_Table0 = FFX_Btl_GetKernelString_Table0(12314, 0);
  if ( KernelString_Table0_1 )
  {
    if ( KernelString_Table0_1 > 0 )
      KernelString_Table0 = FFX_Btl_GetKernelString_Table0(12312, 0);
  }
  else
  {
    KernelString_Table0 = FFX_Btl_GetKernelString_Table0(12313, 0);
  }
  sub_89DB10(0, KernelString_Table0);
  return 7;
}
