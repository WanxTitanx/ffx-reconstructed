// Function: sub_8F5BC0
// Address: 0x8f5bc0
signed int sub_8F5BC0()
{
  signed int n32; // eax

  n32 = ((unsigned int)dword_187168C - unk_1871680) & 0xFFFFFFF0;
  if ( n32 > 32 )
  {
    nullsub_33(0);
    sub_62FA30(0, 0);
    nullsub_39(unk_18716B4, unk_1871680);
    return sub_62FA30(0, 0);
  }
  return n32;
}
