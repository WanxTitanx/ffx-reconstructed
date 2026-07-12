// Function: sub_AF6290
// Address: 0xaf6290
// Size: 0x31
// Prototype: 

int sub_AF6290()
{
  if ( !sub_A2E780("Key_F6") )
  {
    dword_C6BFFC = dword_1A85390;
    dword_1A85390 = &off_C6BFF4;
  }
  return atexit(sub_B09D60);
}

