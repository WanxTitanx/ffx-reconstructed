// Function: sub_AE6290
// Address: 0xae6290
// Size: 0x31
// Prototype: 

int sub_AE6290()
{
  if ( !sub_4DD9C0("BlackInside") )
  {
    dword_C169C8 = unk_CA54F8;
    unk_CA54F8 = &off_C169C4;                   // "BlackInside"
  }
  return atexit(sub_AFEA70);
}

