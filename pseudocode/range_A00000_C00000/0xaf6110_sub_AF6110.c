// Function: sub_AF6110
// Address: 0xaf6110
// Size: 0x31
// Prototype: 

int sub_AF6110()
{
  if ( !sub_A2E780("Key_F12") )
  {
    dword_C6BF9C = dword_1A85390;
    dword_1A85390 = &off_C6BF94;
  }
  return atexit(sub_B09CA0);
}

