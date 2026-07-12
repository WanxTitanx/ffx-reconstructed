// Function: sub_AF5610
// Address: 0xaf5610
// Size: 0x31
// Prototype: 

int sub_AF5610()
{
  if ( !sub_A2E310("Button_R1") )
  {
    dword_C6BA3C = unk_1A85354;
    unk_1A85354 = &off_C6BA34;
  }
  return atexit(sub_B09710);
}

