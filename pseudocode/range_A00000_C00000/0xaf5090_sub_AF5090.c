// Function: sub_AF5090
// Address: 0xaf5090
// Size: 0x31
// Prototype: 

int sub_AF5090()
{
  if ( !sub_A2E310("Button_1") )
  {
    dword_C6BB0C = unk_1A85354;
    unk_1A85354 = &off_C6BB04;
  }
  return atexit(sub_B09450);
}

