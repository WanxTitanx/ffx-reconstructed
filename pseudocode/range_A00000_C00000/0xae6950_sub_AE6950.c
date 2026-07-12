// Function: sub_AE6950
// Address: 0xae6950
// Size: 0x31
// Prototype: 

int sub_AE6950()
{
  if ( !sub_4DD9C0("TransparentNoMSAA") )
  {
    dword_C169F8 = unk_CA54F8;
    unk_CA54F8 = &off_C169F4;                   // "TransparentNoMSAA"
  }
  return atexit(sub_AFEC20);
}

