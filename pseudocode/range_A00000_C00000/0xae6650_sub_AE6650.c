// Function: sub_AE6650
// Address: 0xae6650
// Size: 0x31
// Prototype: 

int sub_AE6650()
{
  if ( !sub_4DD9C0("PS2Lighting") )
  {
    dword_C16AF8 = unk_CA54F8;
    unk_CA54F8 = &off_C16AF4;                   // "PS2Lighting"
  }
  return atexit(sub_AFEB60);
}

