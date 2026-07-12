// Function: sub_AF6850
// Address: 0xaf6850
// Size: 0x31
// Prototype: 

int sub_AF6850()
{
  if ( !sub_A2E780("Key_Numpad_2") )
  {
    dword_C6BDFC = dword_1A85390;
    dword_1A85390 = &off_C6BDF4;
  }
  return atexit(sub_B0A040);
}

