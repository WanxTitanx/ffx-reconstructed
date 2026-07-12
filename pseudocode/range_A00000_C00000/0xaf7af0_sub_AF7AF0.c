// Function: sub_AF7AF0
// Address: 0xaf7af0
// Size: 0x31
// Prototype: 

int sub_AF7AF0()
{
  if ( !sub_A32560("Button_LeftMB") )
  {
    dword_C6CFF4 = dword_1A85578;
    dword_1A85578 = &off_C6CFEC;
  }
  return atexit(sub_B0A9C0);
}

