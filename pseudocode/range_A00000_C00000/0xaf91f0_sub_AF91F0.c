// Function: sub_AF91F0
// Address: 0xaf91f0
// Size: 0x31
// Prototype: 

int sub_AF91F0()
{
  if ( !sub_A32560("Key_PageDown") )
  {
    dword_C6C8E4 = dword_1A85578;
    dword_1A85578 = &off_C6C8DC;
  }
  return atexit(sub_B0B540);
}

