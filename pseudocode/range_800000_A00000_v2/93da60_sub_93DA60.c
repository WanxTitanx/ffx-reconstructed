// Function: sub_93DA60
// Address: 0x93da60
int __cdecl sub_93DA60(int a1, LPVOID lpBuffer)
{
  int v2; // eax
  int v3; // esi
  signed int nNumberOfBytesToRead; // ebx

  v2 = sub_62FBE0(a1, 1);
  v3 = v2;
  if ( v2 < 0 )
  {
    nullsub_34();
    while ( 1 )
      sub_77DB90();
  }
  nNumberOfBytesToRead = sub_62FA90(v2, 0, 2);
  if ( nNumberOfBytesToRead >= 0
    && sub_62FA90(v3, 0, 0) >= 0
    && (nullsub_34(), nullsub_33(0), IopDevice_ReadFile(v3, lpBuffer, nNumberOfBytesToRead) == nNumberOfBytesToRead) )
  {
    FFX_FileIO_IopDevice_Close(v3);
    nullsub_34();
    return 1;
  }
  else
  {
    nullsub_34();
    FFX_FileIO_IopDevice_Close(v3);
    return 0;
  }
}
