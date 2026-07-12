// Function: sub_AF6AD0
// Address: 0xaf6ad0
// Size: 0x31
// Prototype: 

int sub_AF6AD0()
{
  if ( !sub_A2E780("Key_Numpad_Minus") )
  {
    dword_C6BD4C = dword_1A85390;
    dword_1A85390 = &off_C6BD44;
  }
  return atexit(sub_B0A180);
}

