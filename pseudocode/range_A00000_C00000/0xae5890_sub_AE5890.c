// Function: sub_AE5890
// Address: 0xae5890
// Size: 0x58
// Prototype: 

int sub_AE5890()
{
  if ( !unk_CA43B0 && !sub_4CB1B0("NoShadow") )
  {
    dword_C158B8 = unk_CA43A8;
    unk_CA43A8 = &off_C158B0;
    dword_C158BC = 1;
    dword_C158C0 = 0;
    unk_CA43B0 = &off_C158B0;
  }
  return atexit(sub_AFE560);
}

