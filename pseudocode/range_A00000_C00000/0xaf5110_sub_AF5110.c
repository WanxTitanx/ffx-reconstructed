// Function: sub_AF5110
// Address: 0xaf5110
// Size: 0x31
// Prototype: 

int sub_AF5110()
{
  if ( !sub_A2E310("Button_3") )
  {
    dword_C6BAAC = unk_1A85354;
    unk_1A85354 = &off_C6BAA4;
  }
  return atexit(sub_B09490);
}

