// Function: sub_AE6310
// Address: 0xae6310
// Size: 0x31
// Prototype: 

int sub_AE6310()
{
  if ( !sub_4DD9C0("CaptureTriangleGeometry") )
  {
    dword_C16BC8 = unk_CA54F8;
    unk_CA54F8 = &off_C16BC4;                   // "CaptureTriangleGeometry"
  }
  return atexit(sub_AFEA90);
}

