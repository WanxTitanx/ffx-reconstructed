// Function: sub_934FB0
// Address: 0x934fb0
int sub_934FB0()
{
  char Buffer[64]; // [esp+0h] [ebp-44h] BYREF

  sprintf(Buffer, "Load - %s", off_C60E30[*(_DWORD *)(unk_193C0F0 + 100)]);// "yanagi"
  return sub_84B6A0(*(_DWORD *)(unk_193C0F0 + 4));
}
