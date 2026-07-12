// Function: sub_AF6A50
// Address: 0xaf6a50
// Size: 0x31
// Prototype: 

int sub_AF6A50()
{
  if ( !sub_A2E780("Key_Numpad_Asterisk") )
  {
    dword_C6BD5C = dword_1A85390;
    dword_1A85390 = &off_C6BD54;
  }
  return atexit(sub_B0A140);
}

