// Function: sub_AF5310
// Address: 0xaf5310
// Size: 0x31
// Prototype: 

int sub_AF5310()
{
  if ( !sub_A2E310("Button_B") )
  {
    dword_C6BABC = unk_1A85354;
    unk_1A85354 = &off_C6BAB4;
  }
  return atexit(sub_B09590);
}

