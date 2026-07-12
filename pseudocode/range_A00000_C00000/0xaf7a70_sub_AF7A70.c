// Function: sub_AF7A70
// Address: 0xaf7a70
// Size: 0x31
// Prototype: 

int sub_AF7A70()
{
  if ( !sub_A32560("Button_LS") )
  {
    dword_C6CE04 = dword_1A85578;
    dword_1A85578 = &off_C6CDFC;
  }
  return atexit(sub_B0A980);
}

