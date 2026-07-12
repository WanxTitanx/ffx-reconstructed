// Function: sub_AF9230
// Address: 0xaf9230
// Size: 0x31
// Prototype: 

int sub_AF9230()
{
  if ( !sub_A32560("Key_PageUp") )
  {
    dword_C6C8F4 = dword_1A85578;
    dword_1A85578 = &off_C6C8EC;
  }
  return atexit(sub_B0B560);
}

