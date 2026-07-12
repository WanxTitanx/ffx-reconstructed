// Function: sub_AE6AD0
// Address: 0xae6ad0
// Size: 0x31
// Prototype: 

int sub_AE6AD0()
{
  if ( !sub_4DD9C0("preTransparentATC") )
  {
    dword_C16A28 = unk_CA54F8;
    unk_CA54F8 = &off_C16A24;                   // "preTransparentATC"
  }
  return atexit(sub_AFEC80);
}

