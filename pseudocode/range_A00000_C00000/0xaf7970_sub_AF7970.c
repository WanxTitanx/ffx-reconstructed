// Function: sub_AF7970
// Address: 0xaf7970
// Size: 0x31
// Prototype: 

int sub_AF7970()
{
  if ( !sub_A32560("Button_L1") )
  {
    dword_C6CF24 = dword_1A85578;
    dword_1A85578 = &off_C6CF1C;
  }
  return atexit(sub_B0A900);
}

