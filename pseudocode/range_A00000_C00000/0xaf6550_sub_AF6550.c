// Function: sub_AF6550
// Address: 0xaf6550
// Size: 0x31
// Prototype: 

int sub_AF6550()
{
  if ( !sub_A2E780("Key_K") )
  {
    dword_C6C1FC = dword_1A85390;
    dword_1A85390 = &off_C6C1F4;
  }
  return atexit(sub_B09EC0);
}

