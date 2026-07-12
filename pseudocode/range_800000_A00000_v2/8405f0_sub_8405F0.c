// Function: sub_8405F0
// Address: 0x8405f0
char __cdecl sub_8405F0(int a1, int a2, char ArgList)
{
  char *v3; // ecx
  int v4; // edx

  v3 = (char *)&unk_1302F58;
  while ( 1 )
  {
    v4 = *(_DWORD *)v3;
    if ( *(_DWORD *)(*(_DWORD *)v3 + 12) )
    {
      if ( *(_DWORD *)v4 == a2 && *(char *)(v4 + 4) == a1 )
        break;
    }
    v3 += 4;
    if ( (int)v3 >= (int)byte_13030E8 )
    {
      sub_83BBD0(0);
      sub_838180(a2);
      return sub_90AE50(0, (int)"Memory Cache", "Can't find cache yet=%d id=%s:%d [%s]", ArgList);
    }
  }
  *(_BYTE *)(v4 + 6) = ArgList;
  return ArgList;
}
