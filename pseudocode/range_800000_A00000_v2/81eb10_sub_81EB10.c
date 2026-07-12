// Function: sub_81EB10
// Address: 0x81eb10
char *__cdecl sub_81EB10(int n3)
{
  char *v1; // ecx
  char *result; // eax

  v1 = (char *)off_C4946C;
  result = (char *)off_C4946C + 32;
  n2_9 = n3 >= 3 ? 0 : n3;
  if ( (_DWORD *)((char *)off_C4946C + 32) > &dword_12F4DC0 )
  {
    if ( (unk_12F4108 & 1) != 0 )
      nullsub_34();
    result = (char *)sub_81D700();
    v1 = (char *)off_C4946C;
  }
  *((_DWORD *)v1 + 1) = n3 >= 3 ? 0 : n3;
  *(_DWORD *)v1 = 3;
  *((_DWORD *)v1 + 2) = 0;
  *((_DWORD *)v1 + 3) = 0;
  *((_DWORD *)v1 + 4) = 0;
  *((_DWORD *)v1 + 5) = 0;
  *((_DWORD *)v1 + 6) = 0;
  *((_DWORD *)v1 + 7) = 0;
  off_C4946C = v1 + 32;
  return result;
}
