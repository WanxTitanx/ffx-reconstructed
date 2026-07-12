// Function: sub_AEC740
// Address: 0xaec740
// Size: 0x31
// Prototype: 

int sub_AEC740()
{
  if ( !sub_5CBFC0("ScreenSize") )
  {
    dword_C297A8 = unk_CBD908;
    unk_CBD908 = &off_C297A0;
  }
  return atexit(sub_B048B0);
}

