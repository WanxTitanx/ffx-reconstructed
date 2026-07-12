// Function: sub_AE6590
// Address: 0xae6590
// Size: 0x31
// Prototype: 

int sub_AE6590()
{
  if ( !sub_4DD9C0("OpaqueNoMSAA") )
  {
    dword_C169E8 = unk_CA54F8;
    unk_CA54F8 = &off_C169E4;                   // "OpaqueNoMSAA"
  }
  return atexit(sub_AFEB30);
}

