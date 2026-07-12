// Function: sub_AF9030
// Address: 0xaf9030
// Size: 0x31
// Prototype: 

int sub_AF9030()
{
  if ( !sub_A32560("Key_Numpad_Enter") )
  {
    dword_C6C7D4 = dword_1A85578;
    dword_1A85578 = &off_C6C7CC;
  }
  return atexit(sub_B0B460);
}

