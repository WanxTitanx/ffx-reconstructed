// Function: sub_840250
// Address: 0x840250
int __cdecl sub_840250(int a1, int a2, int a3)
{
  char *v3; // ecx
  _DWORD *v4; // esi
  int v6; // edi
  int v7; // [esp+0h] [ebp-8h]

  v3 = (char *)&unk_1302F58;
  while ( 1 )
  {
    v4 = *(_DWORD **)v3;
    if ( *(_DWORD *)(*(_DWORD *)v3 + 12) )
    {
      if ( *v4 == a2 && *((char *)v4 + 4) == a1 )
        break;
    }
    v3 += 4;
    if ( (int)v3 >= (int)byte_13030E8 )
      return 1;
  }
  if ( *((_BYTE *)v4 + 5) && a3 )
    return -1;
  if ( v4[4] )
  {
    sub_640240();
    if ( !sub_840950(*v4) )
      sub_63DB50(v4[4]);
    v4[4] = 0;
  }
  v6 = v4[5];
  if ( v6 )
  {
    if ( !sub_840950(*v4) )
      sub_63DB50(v6);
    v4[5] = 0;
  }
  if ( v4[6] )
  {
    FFX_Memory_Delete(v4[6], v7);
    v4[6] = 0;
  }
  if ( v4[8] )
    sub_641020(v4 + 8);
  if ( v4[7] )
  {
    FFX_Memory_Delete(v4[7], v7);
    v4[7] = 0;
  }
  sub_840EC0(v4);
  return 0;
}
