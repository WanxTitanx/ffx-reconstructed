// Function: sub_AF6650
// Address: 0xaf6650
// Size: 0x31
// Prototype: 

int sub_AF6650()
{
  if ( !sub_A2E780("Key_Left_Control") )
  {
    dword_C6BD0C = dword_1A85390;
    dword_1A85390 = &off_C6BD04;
  }
  return atexit(sub_B09F40);
}

