// Function: FFX_BtlHud_AnimationActivate
// Address: 0xa7c880
// Size: 0x20
// Prototype: int __cdecl(int n2, int)

int __cdecl FFX_BtlHud_AnimationActivate(int n2, int a2)
{
  int result; // eax

  result = FFX_BtlHud_AnimationSlotHandler(n2, a2, 1);
  if ( result )
    *(_DWORD *)(result + 4) |= 0xC0000000;
  return result;
}

