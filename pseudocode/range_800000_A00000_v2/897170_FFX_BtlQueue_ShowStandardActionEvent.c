// Function: FFX_BtlQueue_ShowStandardActionEvent
// Address: 0x897170
int __cdecl FFX_BtlQueue_ShowStandardActionEvent(int a1, int a2)
{
  int v2; // eax
  int KernelString_Table0; // eax

  sub_8B5770(7, 0, 0);
  v2 = sub_8AC800(a1);
  sub_8B57A0(7, 0, v2);
  KernelString_Table0 = FFX_Btl_GetKernelString_Table0(a2, 0);
  sub_89DB10(0, KernelString_Table0);
  return 7;
}
