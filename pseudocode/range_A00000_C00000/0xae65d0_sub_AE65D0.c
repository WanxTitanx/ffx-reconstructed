// Function: sub_AE65D0
// Address: 0xae65d0
// Size: 0x31
// Prototype: 

int sub_AE65D0()
{
  if ( !sub_4DD9C0("Opaque") )
  {
    dword_C169B8 = unk_CA54F8;
    unk_CA54F8 = &off_C169B4;                   // "Opaque"
  }
  return atexit(sub_AFEB40);
}

