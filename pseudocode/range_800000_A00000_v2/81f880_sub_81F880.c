// Function: sub_81F880
// Address: 0x81f880
char *sub_81F880()
{
  char *v0; // ecx
  char *result; // eax

  v0 = (char *)off_C4946C;
  result = (char *)off_C4946C + 32;
  if ( (_DWORD *)((char *)off_C4946C + 32) > &dword_12F4DC0 )
  {
    if ( (unk_12F4108 & 1) != 0 )
      nullsub_34();
    result = (char *)sub_81D700();
    v0 = (char *)off_C4946C;
  }
  *(_DWORD *)v0 = 51;
  *((_DWORD *)v0 + 1) = 0;
  *((_DWORD *)v0 + 2) = 0;
  *((_DWORD *)v0 + 3) = 0;
  *((_DWORD *)v0 + 4) = 0;
  *((_DWORD *)v0 + 5) = 0;
  *((_DWORD *)v0 + 6) = 0;
  *((_DWORD *)v0 + 7) = 0;
  off_C4946C = v0 + 32;
  n3_15 = 3;
  unk_12F4E9C = 0;
  return result;
}
