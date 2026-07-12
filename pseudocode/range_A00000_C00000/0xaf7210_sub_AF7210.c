// Function: sub_AF7210
// Address: 0xaf7210
// Size: 0x31
// Prototype: 

int sub_AF7210()
{
  if ( !sub_A2EBF0("Button_LeftMB") )
  {
    dword_C6C3F4 = dword_1A853CC;
    dword_1A853CC = &off_C6C3EC;
  }
  return atexit(sub_B0A530);
}

