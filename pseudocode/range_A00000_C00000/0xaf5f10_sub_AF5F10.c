// Function: sub_AF5F10
// Address: 0xaf5f10
// Size: 0x31
// Prototype: 

int sub_AF5F10()
{
  if ( !sub_A2E780("Key_Down") )
  {
    dword_C6BE7C = dword_1A85390;
    dword_1A85390 = &off_C6BE74;
  }
  return atexit(sub_B09BA0);
}

