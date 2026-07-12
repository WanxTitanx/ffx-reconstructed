// Function: sub_AEC240
// Address: 0xaec240
// Size: 0xb1
// Prototype: 

int sub_AEC240()
{
  sub_5C8280("Morph32", sub_5CB8D0, sub_5CA560, 3, 1, &dword_CBD4EC, &dword_CBD51C, 0, 0, 0);
  unk_CBD4E8 = unk_CBD388;
  unk_CBD388 = &unk_CBD4A8;
  dword_CBD4EC = 0;
  unk_CBD4F0 = 1;
  unk_CBD4F8 = 0;
  unk_CBD4FC = 1;
  unk_CBD504 = 0;
  unk_CBD508 = 1;
  unk_CBD510 = 0;
  unk_CBD514 = 1;
  dword_CBD51C = 0;
  unk_CBD520 = 1;
  return atexit(sub_B04800);
}

