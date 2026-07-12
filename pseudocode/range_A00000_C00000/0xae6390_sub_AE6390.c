// Function: sub_AE6390
// Address: 0xae6390
// Size: 0x31
// Prototype: 

int sub_AE6390()
{
  if ( !sub_4DD9C0("DepthTestDisableWithOptimize") )
  {
    dword_C16BA8 = unk_CA54F8;
    unk_CA54F8 = &off_C16BA4;                   // "DepthTestDisableWithOptimize"
  }
  return atexit(sub_AFEAB0);
}

