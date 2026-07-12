// Function: sub_AF8BF0
// Address: 0xaf8bf0
// Size: 0x31
// Prototype: 

int sub_AF8BF0()
{
  if ( !sub_A32560("Key_Left_Control") )
  {
    dword_C6C7B4 = dword_1A85578;
    dword_1A85578 = &off_C6C7AC;
  }
  return atexit(sub_B0B240);
}

