// Function: sub_AF5850
// Address: 0xaf5850
// Size: 0x31
// Prototype: 

int sub_AF5850()
{
  if ( !sub_A2E310("Button_Start") )
  {
    dword_C6B97C = unk_1A85354;
    unk_1A85354 = &off_C6B974;
  }
  return atexit(sub_B09830);
}

