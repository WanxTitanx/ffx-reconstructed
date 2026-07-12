// Function: sub_AF6310
// Address: 0xaf6310
// Size: 0x31
// Prototype: 

int sub_AF6310()
{
  if ( !sub_A2E780("Key_F8") )
  {
    dword_C6BFDC = dword_1A85390;
    dword_1A85390 = &off_C6BFD4;
  }
  return atexit(sub_B09DA0);
}

