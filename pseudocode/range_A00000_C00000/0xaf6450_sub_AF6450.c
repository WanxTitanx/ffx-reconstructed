// Function: sub_AF6450
// Address: 0xaf6450
// Size: 0x31
// Prototype: 

int sub_AF6450()
{
  if ( !sub_A2E780("Key_Home") )
  {
    dword_C6BE6C = dword_1A85390;
    dword_1A85390 = &off_C6BE64;
  }
  return atexit(sub_B09E40);
}

