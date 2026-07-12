// Function: sub_AF9070
// Address: 0xaf9070
// Size: 0x31
// Prototype: 

int sub_AF9070()
{
  if ( !sub_A32560("Key_Numpad_Minus") )
  {
    dword_C6C7F4 = dword_1A85578;
    dword_1A85578 = &off_C6C7EC;
  }
  return atexit(sub_B0B480);
}

