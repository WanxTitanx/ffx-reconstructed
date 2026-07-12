// Function: sub_AF6810
// Address: 0xaf6810
// Size: 0x31
// Prototype: 

int sub_AF6810()
{
  if ( !sub_A2E780("Key_Numpad_1") )
  {
    dword_C6BE0C = dword_1A85390;
    dword_1A85390 = &off_C6BE04;
  }
  return atexit(sub_B0A020);
}

