// Function: sub_AE6610
// Address: 0xae6610
// Size: 0x31
// Prototype: 

int sub_AE6610()
{
  if ( !sub_4DD9C0("OptimizedTrans") )
  {
    dword_C16B88 = unk_CA54F8;
    unk_CA54F8 = &off_C16B84;                   // "OptimizedTrans"
  }
  return atexit(sub_AFEB50);
}

