// Function: sub_AF5750
// Address: 0xaf5750
// Size: 0x31
// Prototype: 

int sub_AF5750()
{
  if ( !sub_A2E310("Button_RT") )
  {
    dword_C6B9CC = unk_1A85354;
    unk_1A85354 = &off_C6B9C4;
  }
  return atexit(sub_B097B0);
}

