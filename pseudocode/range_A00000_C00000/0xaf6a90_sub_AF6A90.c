// Function: sub_AF6A90
// Address: 0xaf6a90
// Size: 0x31
// Prototype: 

int sub_AF6A90()
{
  if ( !sub_A2E780("Key_Numpad_Enter") )
  {
    dword_C6BD2C = dword_1A85390;
    dword_1A85390 = &off_C6BD24;
  }
  return atexit(sub_B0A160);
}

