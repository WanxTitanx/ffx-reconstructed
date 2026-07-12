// Function: sub_AE58F0
// Address: 0xae58f0
// Size: 0x58
// Prototype: 

int sub_AE58F0()
{
  if ( !unk_CA43B4 && !sub_4CB1B0("PCFShadowMap") )
  {
    dword_C158CC = unk_CA43A8;
    unk_CA43A8 = &off_C158C4;
    n2_18 = 2;
    dword_C158D4 = 1;
    unk_CA43B4 = &off_C158C4;
  }
  return atexit(sub_AFE5A0);
}

