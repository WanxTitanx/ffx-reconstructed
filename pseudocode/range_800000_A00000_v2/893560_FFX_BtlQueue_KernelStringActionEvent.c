// Function: FFX_BtlQueue_KernelStringActionEvent
// Address: 0x893560
int __cdecl FFX_BtlQueue_KernelStringActionEvent(int a1, int a2)
{
  int v2; // eax
  int KernelString; // eax
  int KernelString_Table0; // eax

  sub_8B5770(7, 0, 0);
  v2 = sub_8AC800(a1);
  sub_8B57A0(7, 0, v2);
  sub_8B5770(7, 1, 0);
  KernelString = FFX_Table_GetKernelString(1, a2 + 4147, 0);
  sub_8B57A0(7, 1, KernelString);
  KernelString_Table0 = FFX_Btl_GetKernelString_Table0(12303, 0);
  sub_89DB10(0, KernelString_Table0);
  return 7;
}
