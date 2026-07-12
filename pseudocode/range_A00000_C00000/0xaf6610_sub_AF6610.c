// Function: sub_AF6610
// Address: 0xaf6610
// Size: 0x31
// Prototype: 

int sub_AF6610()
{
  if ( !sub_A2E780("Key_Left_Alt") )
  {
    dword_C6BCEC = dword_1A85390;
    dword_1A85390 = &off_C6BCE4;
  }
  return atexit(sub_B09F20);
}

