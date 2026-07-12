// Function: sub_AF4FD0
// Address: 0xaf4fd0
// Size: 0x31
// Prototype: 

int sub_AF4FD0()
{
  if ( !sub_A2E310("Button_13") )
  {
    dword_C6B8EC = unk_1A85354;
    unk_1A85354 = &off_C6B8E4;
  }
  return atexit(sub_B093F0);
}

