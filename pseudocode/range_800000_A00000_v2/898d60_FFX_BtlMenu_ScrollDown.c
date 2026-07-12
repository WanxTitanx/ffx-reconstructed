// Function: FFX_BtlMenu_ScrollDown
// Address: 0x898d60
int __cdecl FFX_BtlMenu_ScrollDown(int a1)
{
  int result; // eax

  if ( !unk_133C8F8 )
    unk_133F768 = *(__int16 *)(a1 + 60);
  result = FFX_BtlMenu_GetScrollStep();
  *(_WORD *)(a1 + 60) += result;
  *(_DWORD *)(a1 + 136) = nullsub_136;
  return result;
}
