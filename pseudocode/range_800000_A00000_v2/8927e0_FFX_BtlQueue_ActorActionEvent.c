// Function: FFX_BtlQueue_ActorActionEvent
// Address: 0x8927e0
int __cdecl FFX_BtlQueue_ActorActionEvent(unsigned __int8 a1, int a2)
{
  float *DurationFloatPtr; // eax
  int KernelString_Table0; // eax

  sub_8B5770(7, 0, 0);
  DurationFloatPtr = FFX_StatusEffect_GetDurationFloatPtr(a1);
  sub_8B57A0(7, 0, DurationFloatPtr);
  KernelString_Table0 = FFX_Btl_GetKernelString_Table0(a2, 0);
  sub_89DB10(0, KernelString_Table0);
  return 7;
}
