// Function: sub_81EF30
// Address: 0x81ef30
int __cdecl sub_81EF30(int a1)
{
  char *v1; // ecx

  v1 = (char *)off_C4946C;
  if ( (_UNKNOWN *)((char *)off_C4946C + 32) > &unk_12F4DC0 )
  {
    if ( (unk_12F4108 & 1) != 0 )
      nullsub_34();
    sub_81D700();
    v1 = (char *)off_C4946C;
  }
  *(_DWORD *)v1 = 55;
  *((_DWORD *)v1 + 1) = a1;
  *((_DWORD *)v1 + 2) = 64;
  *((_DWORD *)v1 + 3) = 127;
  *((_DWORD *)v1 + 4) = 0;
  *((_DWORD *)v1 + 5) = 0;
  *((_DWORD *)v1 + 6) = 0;
  *((_DWORD *)v1 + 7) = 0;
  off_C4946C = v1 + 32;
  unk_12F4F44 = 1;
  unk_12F4E54 = 1;
  return a1;
}
