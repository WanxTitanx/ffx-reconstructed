// Function: sub_AF5710
// Address: 0xaf5710
// Size: 0x31
// Prototype: 

int sub_AF5710()
{
  if ( !sub_A2E310("Button_RS") )
  {
    dword_C6B91C = unk_1A85354;
    unk_1A85354 = &off_C6B914;
  }
  return atexit(sub_B09790);
}

