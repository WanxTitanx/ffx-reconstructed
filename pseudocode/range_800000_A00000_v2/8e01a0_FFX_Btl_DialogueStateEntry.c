// Function: FFX_Btl_DialogueStateEntry
// Address: 0x8e01a0
int __cdecl FFX_Btl_DialogueStateEntry(int a1)
{
  int HasSubmenuActive; // eax
  int v3; // [esp-4h] [ebp-8h]

  *(_DWORD *)(a1 + 160) = 0;
  HasSubmenuActive = FFX_BtlHud_HasSubmenuActive();
  v3 = *(_DWORD *)(a1 + 148);
  *(_DWORD *)(a1 + 172) = HasSubmenuActive != 0 ? 25 : 30;
  *(_DWORD *)(a1 + 168) = sub_8B8060(*(__int16 *)(a1 + 4), v3);
  *(_DWORD *)(a1 + 280) = FFX_Btl_DialogueStateEntry;
  return 0;
}
