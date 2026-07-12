// Function: sub_AF5450
// Address: 0xaf5450
// Size: 0x31
// Prototype: 

int sub_AF5450()
{
  if ( !sub_A2E310("Button_L1") )
  {
    dword_C6BA6C = unk_1A85354;
    unk_1A85354 = &off_C6BA64;
  }
  return atexit(sub_B09630);
}

