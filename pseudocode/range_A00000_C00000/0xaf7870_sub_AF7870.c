// Function: sub_AF7870
// Address: 0xaf7870
// Size: 0x31
// Prototype: 

int sub_AF7870()
{
  if ( !sub_A32560("Button_Back") )
  {
    dword_C6CE54 = dword_1A85578;
    dword_1A85578 = &off_C6CE4C;
  }
  return atexit(sub_B0A880);
}

