// Function: sub_840560
// Address: 0x840560
int __cdecl sub_840560(char a1, int a2, int a3)
{
  char *v3; // eax
  int v4; // edx
  int result; // eax

  while ( 2 )
  {
    v3 = (char *)&unk_1302F58;
    do
    {
      v4 = *(_DWORD *)v3;
      if ( !*(_DWORD *)(*(_DWORD *)v3 + 12) )
      {
        *(_DWORD *)v4 = a2;
        *(_DWORD *)(v4 + 12) = a3;
        *(_DWORD *)(v4 + 5) = 83886080;
        *(_BYTE *)(v4 + 4) = a1;
        return nullsub_113(a3, 4);
      }
      v3 += 4;
    }
    while ( (int)v3 < (int)byte_13030E8 );
    result = sub_8409A0();
    if ( !result )
      continue;
    break;
  }
  return result;
}
