// Function: sub_81CF80
// Address: 0x81cf80
char *sub_81CF80()
{
  char *v0; // ecx
  char *result; // eax

  v0 = (char *)off_C4946C;
  result = (char *)off_C4946C + 32;
  if ( (_UNKNOWN *)((char *)off_C4946C + 32) > &unk_12F4DC0 )
  {
    if ( (unk_12F4108 & 1) != 0 )
      nullsub_34();
    result = (char *)sub_81D700();
    v0 = (char *)off_C4946C;
  }
  *(_DWORD *)v0 = 0;
  *((_DWORD *)v0 + 1) = 0;
  *((_DWORD *)v0 + 2) = 0;
  *((_DWORD *)v0 + 3) = 0;
  *((_DWORD *)v0 + 4) = 0;
  *((_DWORD *)v0 + 5) = 0;
  *((_DWORD *)v0 + 6) = 0;
  *((_DWORD *)v0 + 7) = 0;
  off_C4946C = v0 + 32;
  return result;
}
