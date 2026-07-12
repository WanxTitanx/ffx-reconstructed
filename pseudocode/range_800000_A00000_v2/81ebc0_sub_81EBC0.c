// Function: sub_81EBC0
// Address: 0x81ebc0
int __cdecl sub_81EBC0(char *Buffer)
{
  char *Buffer_1; // ecx
  int v2; // edx
  char v3; // al
  int result; // eax

  Buffer_1 = Buffer;
  v2 = off_C49458 - (_UNKNOWN *)Buffer;
  do
  {
    v3 = *Buffer_1;
    Buffer_1[v2] = *Buffer_1;
    ++Buffer_1;
  }
  while ( v3 );
  result = sub_81CCE0(2);
  if ( result )
    return *(_DWORD *)result;
  return result;
}
