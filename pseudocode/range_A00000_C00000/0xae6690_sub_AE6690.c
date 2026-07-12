// Function: sub_AE6690
// Address: 0xae6690
// Size: 0x31
// Prototype: 

int sub_AE6690()
{
  if ( !sub_4DD9C0("SetStencilFlag") )
  {
    dword_C16B68 = unk_CA54F8;
    unk_CA54F8 = &off_C16B64;                   // "SetStencilFlag"
  }
  return atexit(sub_AFEB70);
}

