// Function: sub_81F910
// Address: 0x81f910
char *__cdecl sub_81F910(char a1)
{
  char *v1; // ecx
  char *result; // eax

  v1 = (char *)off_C4946C;
  result = (char *)off_C4946C + 32;
  if ( (_DWORD *)((char *)off_C4946C + 32) > &dword_12F4DC0 )
  {
    if ( (unk_12F4108 & 1) != 0 )
      nullsub_34();
    result = (char *)sub_81D700();
    v1 = (char *)off_C4946C;
  }
  *((_DWORD *)v1 + 1) = a1 & 0x7F;
  *(_DWORD *)v1 = 62;
  *((_DWORD *)v1 + 2) = 0;
  *((_DWORD *)v1 + 3) = 0;
  *((_DWORD *)v1 + 4) = 0;
  *((_DWORD *)v1 + 5) = 0;
  *((_DWORD *)v1 + 6) = 0;
  *((_DWORD *)v1 + 7) = 0;
  off_C4946C = v1 + 32;
  return result;
}
