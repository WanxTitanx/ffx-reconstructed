// Function: sub_AE63D0
// Address: 0xae63d0
// Size: 0x31
// Prototype: 

int sub_AE63D0()
{
  if ( !sub_4DD9C0("DepthTestDisable") )
  {
    dword_C16B98 = unk_CA54F8;
    unk_CA54F8 = &off_C16B94;                   // "DepthTestDisable"
  }
  return atexit(sub_AFEAC0);
}

