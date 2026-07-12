// Function: sub_840120
// Address: 0x840120
char *sub_840120()
{
  char *result; // eax

  result = (char *)&unk_1302F58;
  do
  {
    if ( (*(_BYTE *)(*(_DWORD *)result + 8) & 7) != 0 && (*(_BYTE *)(*(_DWORD *)result + 8) & 7) != 7 )
      *(_BYTE *)(*(_DWORD *)result + 8) ^= (*(_BYTE *)(*(_DWORD *)result + 8)
                                          ^ (*(_BYTE *)(*(_DWORD *)result + 8) - 1))
                                         & 7;
    result += 4;
  }
  while ( (int)result < (int)byte_13030E8 );
  return result;
}
