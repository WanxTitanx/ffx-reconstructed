// Function: sub_AE6990
// Address: 0xae6990
// Size: 0x31
// Prototype: 

int sub_AE6990()
{
  if ( !sub_4DD9C0("Transparent") )
  {
    dword_C169D8 = unk_CA54F8;
    unk_CA54F8 = &off_C169D4;                   // "Transparent"
  }
  return atexit(sub_AFEC30);
}

