// Function: sub_AF7090
// Address: 0xaf7090
// Size: 0x31
// Prototype: 

int sub_AF7090()
{
  if ( !sub_A2E780("Key_Up") )
  {
    dword_C6BE8C = dword_1A85390;
    dword_1A85390 = &off_C6BE84;
  }
  return atexit(sub_B0A460);
}

