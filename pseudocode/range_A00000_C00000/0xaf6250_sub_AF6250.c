// Function: sub_AF6250
// Address: 0xaf6250
// Size: 0x31
// Prototype: 

int sub_AF6250()
{
  if ( !sub_A2E780("Key_F5") )
  {
    dword_C6C00C = dword_1A85390;
    dword_1A85390 = &off_C6C004;
  }
  return atexit(sub_B09D40);
}

