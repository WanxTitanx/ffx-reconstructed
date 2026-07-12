// Function: sub_AE6510
// Address: 0xae6510
// Size: 0x31
// Prototype: 

int sub_AE6510()
{
  if ( !sub_4DD9C0("HSVPass") )
  {
    dword_C16B48 = unk_CA54F8;
    unk_CA54F8 = &off_C16B44;                   // "HSVPass"
  }
  return atexit(sub_AFEB10);
}

