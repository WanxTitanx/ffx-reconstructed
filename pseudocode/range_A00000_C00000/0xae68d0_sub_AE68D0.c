// Function: sub_AE68D0
// Address: 0xae68d0
// Size: 0x31
// Prototype: 

int sub_AE68D0()
{
  if ( !sub_4DD9C0("TransparentClipY") )
  {
    dword_C16B58 = unk_CA54F8;
    unk_CA54F8 = &off_C16B54;                   // "TransparentClipY"
  }
  return atexit(sub_AFEC00);
}

