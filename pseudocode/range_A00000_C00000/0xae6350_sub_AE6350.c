// Function: sub_AE6350
// Address: 0xae6350
// Size: 0x31
// Prototype: 

int sub_AE6350()
{
  if ( !sub_4DD9C0("DeferredRender") )
  {
    dword_C16A88 = unk_CA54F8;
    unk_CA54F8 = &off_C16A84;                   // "DeferredRender"
  }
  return atexit(sub_AFEAA0);
}

