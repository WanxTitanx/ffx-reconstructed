// Function: sub_AF8430
// Address: 0xaf8430
// Size: 0x31
// Prototype: 

int sub_AF8430()
{
  if ( !sub_A32560("Key_D") )
  {
    dword_C6CD14 = dword_1A85578;
    dword_1A85578 = &off_C6CD0C;
  }
  return atexit(sub_B0AE60);
}

