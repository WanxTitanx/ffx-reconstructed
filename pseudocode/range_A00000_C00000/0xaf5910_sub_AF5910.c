// Function: sub_AF5910
// Address: 0xaf5910
// Size: 0x31
// Prototype: 

int sub_AF5910()
{
  if ( !sub_A2E310("Button_X") )
  {
    dword_C6BB1C = unk_1A85354;
    unk_1A85354 = &off_C6BB14;
  }
  return atexit(sub_B09890);
}

