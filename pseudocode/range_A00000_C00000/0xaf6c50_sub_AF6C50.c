// Function: sub_AF6C50
// Address: 0xaf6c50
// Size: 0x31
// Prototype: 

int sub_AF6C50()
{
  if ( !sub_A2E780("Key_PageDown") )
  {
    dword_C6BE3C = dword_1A85390;
    dword_1A85390 = &off_C6BE34;
  }
  return atexit(sub_B0A240);
}

