// Function: sub_AE2BD0
// Address: 0xae2bd0
// Size: 0x58
// Prototype: 

int sub_AE2BD0()
{
  if ( !unk_C9AF00 && !sub_49E390("PointLight") )
  {
    dword_C1081C = unk_C9AEF8;
    unk_C9AEF8 = &off_C10814;
    dword_C10820 = 1;
    dword_C10824 = 0;
    unk_C9AF00 = &off_C10814;
  }
  return atexit(sub_AFCE80);
}

