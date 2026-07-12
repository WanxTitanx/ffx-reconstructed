// Function: sub_936570
// Address: 0x936570
int sub_936570()
{
  int result; // eax

  *(_DWORD *)(unk_193C0F0 + 92) = 0;
  *(_DWORD *)(unk_193C0F0 + 648) = 0;
  *(_DWORD *)(unk_193C0F0 + 776) = 0;
  *(_DWORD *)(unk_193C0F0 + 780) = 0;
  result = sub_908F10();
  if ( (result & 1) != 0 )
    return sub_909E10(1);
  return result;
}
