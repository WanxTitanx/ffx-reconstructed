// Function: sub_8B0FD0
// Address: 0x8b0fd0
int __usercall sub_8B0FD0@<eax>(int a1@<ebp>)
{
  int v1; // eax
  int v2; // eax

  v1 = sub_8AC710();
  sub_8B0AC0(
    a1,
    *((_DWORD *)&unk_1841D60 + 4 * v1),
    15360,
    20,
    0,
    0,
    *((__int16 *)&unk_1841D6C + 8 * v1),
    *((__int16 *)&unk_1841D6E + 8 * v1));
  if ( FFX_Battle_QueueGateCheck() )
  {
    if ( sub_781750() )
      sub_8B0AC0(a1, unk_1841D80, 15616, 20, 0, 0, unk_1841D8C, unk_1841D8E);
    if ( !FFX_Game_GetRegion() )
      sub_8B0AC0(a1, unk_1841DA0, 15680, 20, 0, 0, unk_1841DAC, unk_1841DAE);
  }
  else if ( sub_873A60() )
  {
    sub_8B0AC0(a1, unk_1841D70, 15616, 20, 0, 0, unk_1841D7C, unk_1841D7E);
  }
  sub_8B0AC0(a1, unk_1841D54, 15744, 20, 0, 0, 128, 256);
  sub_8B0AC0(a1, unk_1841D58, 15808, 20, 0, 0, 256, 128);
  sub_8B0AC0(a1, unk_1841DC0, 15872, 19, 0, 0, 256, 256);
  v2 = sub_8AC270();
  sub_8B0AC0(a1, v2, 16128, 19, 0, 0, 256, 256);
  return sub_8B0AC0(a1, unk_1841DC8, 11936, 0, 0, 0, 64, 64);
}
