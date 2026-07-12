// Function: sub_AE6410
// Address: 0xae6410
// Size: 0x31
// Prototype: 

int sub_AE6410()
{
  if ( !sub_4DD9C0("DressUpFast") )
  {
    dword_C16B28 = unk_CA54F8;
    unk_CA54F8 = &off_C16B24;                   // "DressUpFast"
  }
  return atexit(sub_AFEAD0);
}

