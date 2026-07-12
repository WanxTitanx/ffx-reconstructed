// Function: sub_AF5550
// Address: 0xaf5550
// Size: 0x31
// Prototype: 

int sub_AF5550()
{
  if ( !sub_A2E310("Button_LS") )
  {
    dword_C6B94C = unk_1A85354;
    unk_1A85354 = &off_C6B944;
  }
  return atexit(sub_B096B0);
}

