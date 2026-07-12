// Function: sub_AF5490
// Address: 0xaf5490
// Size: 0x31
// Prototype: 

int sub_AF5490()
{
  if ( !sub_A2E310("Button_L2") )
  {
    dword_C6BA0C = unk_1A85354;
    unk_1A85354 = &off_C6BA04;
  }
  return atexit(sub_B09650);
}

