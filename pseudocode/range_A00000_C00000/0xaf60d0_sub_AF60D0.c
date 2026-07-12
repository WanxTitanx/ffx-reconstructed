// Function: sub_AF60D0
// Address: 0xaf60d0
// Size: 0x31
// Prototype: 

int sub_AF60D0()
{
  if ( !sub_A2E780("Key_F11") )
  {
    dword_C6BFAC = dword_1A85390;
    dword_1A85390 = &off_C6BFA4;
  }
  return atexit(sub_B09C80);
}

