// Function: sub_AF8C30
// Address: 0xaf8c30
// Size: 0x31
// Prototype: 

int sub_AF8C30()
{
  if ( !sub_A32560("Key_Left_Shift") )
  {
    dword_C6C7A4 = dword_1A85578;
    dword_1A85578 = &off_C6C79C;
  }
  return atexit(sub_B0B260);
}

