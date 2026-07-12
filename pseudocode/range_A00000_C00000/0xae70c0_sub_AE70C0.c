// Function: sub_AE70C0
// Address: 0xae70c0
// Size: 0x7e
// Prototype: 

int sub_AE70C0()
{
  char *v0; // esi
  int i; // edi

  PhyreNode_Init(dword_CA852C);
  unk_CA8544 = 0;
  v0 = (char *)&unk_CA8548;
  for ( i = 1; i >= 0; --i )
  {
    sub_4FD270(v0);
    v0 += 272;
  }
  return atexit(sub_AFF8A0);
}

