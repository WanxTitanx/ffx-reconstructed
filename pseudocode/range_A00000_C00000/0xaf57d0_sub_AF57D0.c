// Function: sub_AF57D0
// Address: 0xaf57d0
// Size: 0x31
// Prototype: 

int sub_AF57D0()
{
  if ( !sub_A2E310("Button_Select") )
  {
    dword_C6B9AC = unk_1A85354;
    unk_1A85354 = &off_C6B9A4;
  }
  return atexit(sub_B097F0);
}

