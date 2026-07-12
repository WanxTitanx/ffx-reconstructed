// Function: FFX_Btl_DialogueTextComplete
// Address: 0x8e02b0
int __cdecl FFX_Btl_DialogueTextComplete(int a1)
{
  bool v1; // zf

  v1 = *(_WORD *)(a1 + 18) == 1;
  *(_DWORD *)(a1 + 288) = FFX_Btl_DialogueTextComplete;
  if ( v1 )
    sub_8B8C50(*(__int16 *)(a1 + 4));
  return 0;
}
