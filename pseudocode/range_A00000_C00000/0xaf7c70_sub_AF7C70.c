// Function: sub_AF7C70
// Address: 0xaf7c70
// Size: 0x31
// Prototype: 

int sub_AF7C70()
{
  if ( !sub_A32560("Button_RB") )
  {
    dword_C6CEE4 = dword_1A85578;
    dword_1A85578 = &off_C6CEDC;
  }
  return atexit(sub_B0AA80);
}

