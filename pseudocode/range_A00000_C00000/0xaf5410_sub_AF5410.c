// Function: sub_AF5410
// Address: 0xaf5410
// Size: 0x31
// Prototype: 

int sub_AF5410()
{
  if ( !sub_A2E310("Button_Down") )
  {
    dword_C6B8BC = unk_1A85354;
    unk_1A85354 = &off_C6B8B4;
  }
  return atexit(sub_B09610);
}

