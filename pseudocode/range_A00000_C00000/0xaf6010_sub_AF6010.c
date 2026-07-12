// Function: sub_AF6010
// Address: 0xaf6010
// Size: 0x31
// Prototype: 

int sub_AF6010()
{
  if ( !sub_A2E780("Key_Equals") )
  {
    dword_C6BF3C = dword_1A85390;
    dword_1A85390 = &off_C6BF34;
  }
  return atexit(sub_B09C20);
}

