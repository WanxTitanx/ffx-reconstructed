// Function: sub_AF5FD0
// Address: 0xaf5fd0
// Size: 0x31
// Prototype: 

int sub_AF5FD0()
{
  if ( !sub_A2E780("Key_Enter") )
  {
    dword_C6BF8C = dword_1A85390;
    dword_1A85390 = &off_C6BF84;
  }
  return atexit(sub_B09C00);
}

