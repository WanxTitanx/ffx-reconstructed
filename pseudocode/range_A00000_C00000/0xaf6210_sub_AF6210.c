// Function: sub_AF6210
// Address: 0xaf6210
// Size: 0x31
// Prototype: 

int sub_AF6210()
{
  if ( !sub_A2E780("Key_F4") )
  {
    dword_C6C01C = dword_1A85390;
    dword_1A85390 = &off_C6C014;
  }
  return atexit(sub_B09D20);
}

