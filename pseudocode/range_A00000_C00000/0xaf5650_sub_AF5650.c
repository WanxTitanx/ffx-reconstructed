// Function: sub_AF5650
// Address: 0xaf5650
// Size: 0x31
// Prototype: 

int sub_AF5650()
{
  if ( !sub_A2E310("Button_R2") )
  {
    dword_C6B9DC = unk_1A85354;
    unk_1A85354 = &off_C6B9D4;
  }
  return atexit(sub_B09730);
}

