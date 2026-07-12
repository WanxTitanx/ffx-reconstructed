// Function: sub_AF6CD0
// Address: 0xaf6cd0
// Size: 0x31
// Prototype: 

int sub_AF6CD0()
{
  if ( !sub_A2E780("Key_Period") )
  {
    dword_C6BECC = dword_1A85390;
    dword_1A85390 = &off_C6BEC4;
  }
  return atexit(sub_B0A280);
}

