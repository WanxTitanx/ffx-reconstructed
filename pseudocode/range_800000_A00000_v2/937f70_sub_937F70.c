// Function: sub_937F70
// Address: 0x937f70
unsigned int __cdecl sub_937F70(int a1)
{
  int v1; // edx
  char v2; // bl
  unsigned int v3; // ecx
  unsigned int result; // eax

  v1 = a1 / 10 + 48;
  v2 = a1 % 10 + 48;
  v3 = unk_193C0F0 + 372 + strlen((const char *)(unk_193C0F0 + 372)) + 1 - (unk_193C0F0 + 373);
  *(_BYTE *)(unk_193C0F0 + v3 + 370) = v1;
  *(_BYTE *)(unk_193C0F0 + v3 + 371) = v2;
  result = unk_193C0F0 + 636 + strlen((const char *)(unk_193C0F0 + 636)) + 1 - (unk_193C0F0 + 637);
  *(_BYTE *)(unk_193C0F0 + result + 634) = v1;
  *(_BYTE *)(unk_193C0F0 + result + 635) = v2;
  return result;
}
