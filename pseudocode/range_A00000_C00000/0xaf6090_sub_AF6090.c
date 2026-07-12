// Function: sub_AF6090
// Address: 0xaf6090
// Size: 0x31
// Prototype: 

int sub_AF6090()
{
  if ( !sub_A2E780("Key_F10") )
  {
    dword_C6BFBC = dword_1A85390;
    dword_1A85390 = &off_C6BFB4;
  }
  return atexit(sub_B09C60);
}

