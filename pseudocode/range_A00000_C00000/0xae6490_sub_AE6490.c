// Function: sub_AE6490
// Address: 0xae6490
// Size: 0x31
// Prototype: 

int sub_AE6490()
{
  if ( !sub_4DD9C0("EnableStencilTest") )
  {
    dword_C16B78 = unk_CA54F8;
    unk_CA54F8 = &off_C16B74;                   // "EnableStencilTest"
  }
  return atexit(sub_AFEAF0);
}

