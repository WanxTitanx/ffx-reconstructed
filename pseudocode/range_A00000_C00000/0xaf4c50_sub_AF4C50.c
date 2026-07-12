// Function: sub_AF4C50
// Address: 0xaf4c50
// Size: 0x31
// Prototype: 

int sub_AF4C50()
{
  if ( !sub_A2DEA0("Gyro") )
  {
    dword_C6B6BC = dword_1A85318;
    dword_1A85318 = &off_C6B6B4;
  }
  return atexit(sub_B09220);
}

