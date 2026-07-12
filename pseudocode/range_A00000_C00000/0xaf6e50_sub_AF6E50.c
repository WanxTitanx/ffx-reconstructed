// Function: sub_AF6E50
// Address: 0xaf6e50
// Size: 0x31
// Prototype: 

int sub_AF6E50()
{
  if ( !sub_A2E780("Key_Right_Shift") )
  {
    dword_C6BCCC = dword_1A85390;
    dword_1A85390 = &off_C6BCC4;
  }
  return atexit(sub_B0A340);
}

