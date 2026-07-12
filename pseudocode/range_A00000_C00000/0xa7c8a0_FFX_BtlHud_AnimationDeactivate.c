// Function: FFX_BtlHud_AnimationDeactivate
// Address: 0xa7c8a0
// Size: 0x20
// Prototype: int __cdecl(int n2, int)

int __cdecl FFX_BtlHud_AnimationDeactivate(int n2, int a2)
{
  int result; // eax

  result = FFX_BtlHud_AnimationSlotHandler(n2, a2, 0);
  if ( result )
    *(_DWORD *)(result + 4) &= 0x3FFFFFFFu;
  return result;
}

