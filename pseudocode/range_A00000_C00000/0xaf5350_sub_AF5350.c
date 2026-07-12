// Function: sub_AF5350
// Address: 0xaf5350
// Size: 0x31
// Prototype: 

int sub_AF5350()
{
  if ( !sub_A2E310("Button_Back") )
  {
    dword_C6B99C = unk_1A85354;
    unk_1A85354 = &off_C6B994;
  }
  return atexit(sub_B095B0);
}

