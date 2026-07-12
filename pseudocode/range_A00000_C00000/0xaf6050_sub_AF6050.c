// Function: sub_AF6050
// Address: 0xaf6050
// Size: 0x31
// Prototype: 

int sub_AF6050()
{
  if ( !sub_A2E780("Key_Escape") )
  {
    dword_C6C05C = dword_1A85390;
    dword_1A85390 = &off_C6C054;
  }
  return atexit(sub_B09C40);
}

