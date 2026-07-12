// Function: sub_AF5010
// Address: 0xaf5010
// Size: 0x31
// Prototype: 

int sub_AF5010()
{
  if ( !sub_A2E310("Button_14") )
  {
    dword_C6B8CC = unk_1A85354;
    unk_1A85354 = &off_C6B8C4;
  }
  return atexit(sub_B09410);
}

