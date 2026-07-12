// Function: sub_AF7E30
// Address: 0xaf7e30
// Size: 0x31
// Prototype: 

int sub_AF7E30()
{
  if ( !sub_A32560("Button_Start") )
  {
    dword_C6CE34 = dword_1A85578;
    dword_1A85578 = &off_C6CE2C;
  }
  return atexit(sub_B0AB60);
}

