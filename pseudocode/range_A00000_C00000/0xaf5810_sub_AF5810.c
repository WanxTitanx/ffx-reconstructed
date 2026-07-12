// Function: sub_AF5810
// Address: 0xaf5810
// Size: 0x31
// Prototype: 

int sub_AF5810()
{
  if ( !sub_A2E310("Button_Square") )
  {
    dword_C6BB2C = unk_1A85354;
    unk_1A85354 = &off_C6BB24;
  }
  return atexit(sub_B09810);
}

