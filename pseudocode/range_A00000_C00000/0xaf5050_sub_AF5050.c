// Function: sub_AF5050
// Address: 0xaf5050
// Size: 0x31
// Prototype: 

int sub_AF5050()
{
  if ( !sub_A2E310("Button_15") )
  {
    dword_C6B8AC = unk_1A85354;
    unk_1A85354 = &off_C6B8A4;
  }
  return atexit(sub_B09430);
}

