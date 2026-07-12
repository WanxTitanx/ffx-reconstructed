// Function: sub_AE6A50
// Address: 0xae6a50
// Size: 0x31
// Prototype: 

int sub_AE6A50()
{
  if ( !sub_4DD9C0("postTransparent") )
  {
    dword_C16A48 = unk_CA54F8;
    unk_CA54F8 = &off_C16A44;                   // "postTransparent"
  }
  return atexit(sub_AFEC60);
}

