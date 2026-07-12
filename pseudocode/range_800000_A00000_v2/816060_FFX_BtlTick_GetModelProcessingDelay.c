// Function: FFX_BtlTick_GetModelProcessingDelay
// Address: 0x816060
int __cdecl FFX_BtlTick_GetModelProcessingDelay(int a1, int a2)
{
  bool v2; // zf
  int result; // eax

  if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
    return a2;
  v2 = FFX_BtlTick_GetActorModelState(*(_BYTE *)(*(_DWORD *)(a1 + 544) + 24)) == 0;
  result = a2;
  if ( !v2 )
    return a2 + 2;
  *(_BYTE *)(a1 + 528) = 1;
  return result;
}
