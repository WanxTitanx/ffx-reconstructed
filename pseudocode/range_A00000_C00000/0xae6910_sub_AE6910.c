// Function: sub_AE6910
// Address: 0xae6910
// Size: 0x31
// Prototype: 

int sub_AE6910()
{
  if ( !sub_4DD9C0("TransparentNega") )
  {
    dword_C16B08 = unk_CA54F8;
    unk_CA54F8 = &off_C16B04;                   // "TransparentNega"
  }
  return atexit(sub_AFEC10);
}

