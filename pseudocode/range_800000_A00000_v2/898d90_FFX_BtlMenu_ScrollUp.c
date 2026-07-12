// Function: FFX_BtlMenu_ScrollUp
// Address: 0x898d90
int __cdecl FFX_BtlMenu_ScrollUp(int a1)
{
  int result; // eax

  result = FFX_BtlMenu_GetScrollStep();
  *(_WORD *)(a1 + 60) -= result;
  *(_DWORD *)(a1 + 136) = nullsub_136;
  return result;
}
