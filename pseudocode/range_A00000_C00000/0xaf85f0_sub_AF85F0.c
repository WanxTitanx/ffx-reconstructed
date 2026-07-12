// Function: sub_AF85F0
// Address: 0xaf85f0
// Size: 0x31
// Prototype: 

int sub_AF85F0()
{
  if ( !sub_A32560("Key_Escape") )
  {
    dword_C6CB04 = dword_1A85578;
    dword_1A85578 = &off_C6CAFC;
  }
  return atexit(sub_B0AF40);
}

