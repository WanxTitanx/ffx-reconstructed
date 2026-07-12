// Function: sub_AF8030
// Address: 0xaf8030
// Size: 0x31
// Prototype: 

int sub_AF8030()
{
  if ( !sub_A32560("Key_2") )
  {
    dword_C6CB94 = dword_1A85578;
    dword_1A85578 = &off_C6CB8C;
  }
  return atexit(sub_B0AC60);
}

