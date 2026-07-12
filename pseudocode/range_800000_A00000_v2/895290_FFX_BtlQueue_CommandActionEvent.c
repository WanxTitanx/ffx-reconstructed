// Function: FFX_BtlQueue_CommandActionEvent
// Address: 0x895290
int __cdecl FFX_BtlQueue_CommandActionEvent(int a1, int a2)
{
  int v2; // eax
  float *v3; // eax
  int v4; // esi
  int KernelString_Table0; // eax
  int v7; // [esp+4h] [ebp-4h] BYREF

  sub_8B5770(7, 0, 0);
  v2 = sub_8AC800(a1);
  sub_8B57A0(7, 0, v2);
  v3 = FFX_Btl_LookupCommandDataById(a2, &v7);
  v4 = v7 + *(unsigned __int16 *)v3;
  sub_8B5770(7, 1, 0);
  sub_8B57A0(7, 1, v4);
  KernelString_Table0 = FFX_Btl_GetKernelString_Table0(12301, 0);
  sub_89DB10(0, KernelString_Table0);
  return 7;
}
