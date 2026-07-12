// Function: sub_8E49F0
// Address: 0x8e49f0
int sub_8E49F0()
{
  int result; // eax

  result = unk_23CC124;
  if ( unk_23CC124 )
  {
    *(_BYTE *)(unk_23CC124 + 69) = 0;
    result = unk_23CC124;
    *(_DWORD *)(unk_23CC124 + 40) = 1;
  }
  return result;
}
