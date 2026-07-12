// Function: sub_AE6B10
// Address: 0xae6b10
// Size: 0x31
// Prototype: 

int sub_AE6B10()
{
  if ( !sub_4DD9C0("preTransparent") )
  {
    dword_C16A18 = unk_CA54F8;
    unk_CA54F8 = &off_C16A14;                   // "preTransparent"
  }
  return atexit(sub_AFEC90);
}

