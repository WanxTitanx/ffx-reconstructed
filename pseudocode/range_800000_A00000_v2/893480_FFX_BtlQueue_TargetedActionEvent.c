// Function: FFX_BtlQueue_TargetedActionEvent
// Address: 0x893480
int __cdecl FFX_BtlQueue_TargetedActionEvent(int a1, int n2)
{
  int KernelString_Table0; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax

  sub_8B5770(7, 0, 51);
  sub_8B57A0(7, 0, a1);
  sub_8B5770(7, 1, 1);
  sub_8B57A0(7, 1, n2);
  if ( n2 == -1 )
  {
    KernelString_Table0 = FFX_Btl_GetKernelString_Table0(12295, 0);
    sub_89DB10(0, KernelString_Table0);
    return 7;
  }
  else if ( n2 )
  {
    if ( n2 == 1 )
    {
      v5 = FFX_Btl_GetKernelString_Table0(12293, 0);
      sub_89DB10(0, v5);
      return 7;
    }
    else
    {
      if ( n2 < 2 )
      {
        sub_89DB10(0, n2);
      }
      else
      {
        v6 = FFX_Btl_GetKernelString_Table0(12294, 0);
        sub_89DB10(0, v6);
      }
      return 7;
    }
  }
  else
  {
    v4 = FFX_Btl_GetKernelString_Table0(12296, 0);
    sub_89DB10(0, v4);
    return 7;
  }
}
