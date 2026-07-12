// Function: sub_AF7050
// Address: 0xaf7050
// Size: 0x31
// Prototype: 

int sub_AF7050()
{
  if ( !sub_A2E780("Key_U") )
  {
    dword_C6C15C = dword_1A85390;
    dword_1A85390 = &off_C6C154;
  }
  return atexit(sub_B0A440);
}

