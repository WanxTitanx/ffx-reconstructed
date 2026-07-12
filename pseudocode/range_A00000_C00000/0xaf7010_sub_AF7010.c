// Function: sub_AF7010
// Address: 0xaf7010
// Size: 0x31
// Prototype: 

int sub_AF7010()
{
  if ( !sub_A2E780("Key_Tab") )
  {
    dword_C6BF6C = dword_1A85390;
    dword_1A85390 = &off_C6BF64;
  }
  return atexit(sub_B0A420);
}

