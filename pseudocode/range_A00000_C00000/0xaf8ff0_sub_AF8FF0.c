// Function: sub_AF8FF0
// Address: 0xaf8ff0
// Size: 0x31
// Prototype: 

int sub_AF8FF0()
{
  if ( !sub_A32560("Key_Numpad_Asterisk") )
  {
    dword_C6C804 = dword_1A85578;
    dword_1A85578 = &off_C6C7FC;
  }
  return atexit(sub_B0B440);
}

