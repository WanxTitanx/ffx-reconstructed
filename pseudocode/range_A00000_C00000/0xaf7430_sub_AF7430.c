// Function: sub_AF7430
// Address: 0xaf7430
// Size: 0x31
// Prototype: 

int sub_AF7430()
{
  if ( !sub_A32560("Button_10") )
  {
    dword_C6CE24 = dword_1A85578;
    dword_1A85578 = &off_C6CE1C;
  }
  return atexit(sub_B0A660);
}

