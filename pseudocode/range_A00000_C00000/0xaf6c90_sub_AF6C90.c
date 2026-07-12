// Function: sub_AF6C90
// Address: 0xaf6c90
// Size: 0x31
// Prototype: 

int sub_AF6C90()
{
  if ( !sub_A2E780("Key_PageUp") )
  {
    dword_C6BE4C = dword_1A85390;
    dword_1A85390 = &off_C6BE44;
  }
  return atexit(sub_B0A260);
}

