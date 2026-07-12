// Function: sub_AE64D0
// Address: 0xae64d0
// Size: 0x31
// Prototype: 

int sub_AE64D0()
{
  if ( !sub_4DD9C0("FakeTransparent") )
  {
    dword_C16B18 = unk_CA54F8;
    unk_CA54F8 = &off_C16B14;                   // "FakeTransparent"
  }
  return atexit(sub_AFEB00);
}

