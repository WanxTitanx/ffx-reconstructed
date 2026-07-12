// Function: sub_AF5ED0
// Address: 0xaf5ed0
// Size: 0x31
// Prototype: 

int sub_AF5ED0()
{
  if ( !sub_A2E780("Key_Delete") )
  {
    dword_C6BE1C = dword_1A85390;
    dword_1A85390 = &off_C6BE14;
  }
  return atexit(sub_B09B80);
}

