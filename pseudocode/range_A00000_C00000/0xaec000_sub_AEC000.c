// Function: sub_AEC000
// Address: 0xaec000
// Size: 0xb1
// Prototype: 

int sub_AEC000()
{
  sub_5C8280("Morph22", sub_5CB8D0, sub_5CA0D0, 2, 1, &dword_CBD46C, &dword_CBD49C, 0, 0, 0);
  unk_CBD468 = unk_CBD388;
  unk_CBD388 = &unk_CBD428;
  dword_CBD46C = 0;
  unk_CBD470 = 1;
  unk_CBD478 = 0;
  unk_CBD47C = 1;
  unk_CBD484 = 0;
  unk_CBD488 = 1;
  unk_CBD490 = 0;
  unk_CBD494 = 1;
  dword_CBD49C = 0;
  unk_CBD4A0 = 1;
  return atexit(sub_B047D0);
}

