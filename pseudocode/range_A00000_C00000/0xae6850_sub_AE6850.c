// Function: sub_AE6850
// Address: 0xae6850
// Size: 0x31
// Prototype: 

int sub_AE6850()
{
  if ( !sub_4DD9C0("SpecularPass_nolight") )
  {
    dword_C16AA8 = unk_CA54F8;
    unk_CA54F8 = &off_C16AA4;                   // "SpecularPass_nolight"
  }
  return atexit(sub_AFEBE0);
}

