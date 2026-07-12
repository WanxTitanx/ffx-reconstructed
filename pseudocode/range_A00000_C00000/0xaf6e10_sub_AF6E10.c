// Function: sub_AF6E10
// Address: 0xaf6e10
// Size: 0x31
// Prototype: 

int sub_AF6E10()
{
  if ( !sub_A2E780("Key_Right_Control") )
  {
    dword_C6BCDC = dword_1A85390;
    dword_1A85390 = &off_C6BCD4;
  }
  return atexit(sub_B0A320);
}

