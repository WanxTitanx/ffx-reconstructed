// Function: sub_AE62D0
// Address: 0xae62d0
// Size: 0x31
// Prototype: 

int sub_AE62D0()
{
  if ( !sub_4DD9C0("CaptureEmissiveSurfaces") )
  {
    dword_C16BB8 = unk_CA54F8;
    unk_CA54F8 = &off_C16BB4;                   // "CaptureEmissiveSurfaces"
  }
  return atexit(sub_AFEA80);
}

