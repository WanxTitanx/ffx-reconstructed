// Function: sub_AE69D0
// Address: 0xae69d0
// Size: 0x31
// Prototype: 

int sub_AE69D0()
{
  if ( !sub_4DD9C0("ZPrePass") )
  {
    dword_C16A78 = unk_CA54F8;
    unk_CA54F8 = &off_C16A74;                   // "ZPrePass"
  }
  return atexit(sub_AFEC40);
}

