// Function: sub_AF5210
// Address: 0xaf5210
// Size: 0x31
// Prototype: 

int sub_AF5210()
{
  if ( !sub_A2E310("Button_7") )
  {
    dword_C6B9EC = unk_1A85354;
    unk_1A85354 = &off_C6B9E4;
  }
  return atexit(sub_B09510);
}

