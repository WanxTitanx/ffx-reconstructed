// Function: sub_AE6A90
// Address: 0xae6a90
// Size: 0x31
// Prototype: 

int sub_AE6A90()
{
  if ( !sub_4DD9C0("preOpaque") )
  {
    dword_C16A08 = unk_CA54F8;
    unk_CA54F8 = &off_C16A04;                   // "preOpaque"
  }
  return atexit(sub_AFEC70);
}

