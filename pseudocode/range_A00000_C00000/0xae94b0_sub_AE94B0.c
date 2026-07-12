// Function: sub_AE94B0
// Address: 0xae94b0
// Size: 0x31
// Prototype: 

int sub_AE94B0()
{
  if ( !sub_54D280("UnsetTrigger") )
  {
    dword_C21364 = unk_CAECE8;
    unk_CAECE8 = &off_C21360;                   // "UnsetTrigger"
  }
  return atexit(sub_B01E00);
}

