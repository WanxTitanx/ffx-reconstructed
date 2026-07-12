// Function: sub_AF64D0
// Address: 0xaf64d0
// Size: 0x31
// Prototype: 

int sub_AF64D0()
{
  if ( !sub_A2E780("Key_Insert") )
  {
    dword_C6BE2C = dword_1A85390;
    dword_1A85390 = &off_C6BE24;
  }
  return atexit(sub_B09E80);
}

