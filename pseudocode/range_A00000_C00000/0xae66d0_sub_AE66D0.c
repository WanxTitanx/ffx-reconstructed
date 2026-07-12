// Function: sub_AE66D0
// Address: 0xae66d0
// Size: 0x31
// Prototype: 

int sub_AE66D0()
{
  if ( !sub_4DD9C0("ShadowTransparent") )
  {
    dword_C16A68 = unk_CA54F8;
    unk_CA54F8 = &off_C16A64;                   // "ShadowTransparent"
  }
  return atexit(sub_AFEB80);
}

