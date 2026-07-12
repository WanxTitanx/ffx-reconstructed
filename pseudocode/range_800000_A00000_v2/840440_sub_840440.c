// Function: sub_840440
// Address: 0x840440
void sub_840440()
{
  char *v0; // edi
  _DWORD *v1; // esi
  int v2; // ebx
  int v3; // ebx
  int v4; // [esp+0h] [ebp-Ch]

  v0 = (char *)&unk_1302F58;
  do
  {
    v1 = *(_DWORD **)v0;
    if ( *(_DWORD *)(*(_DWORD *)v0 + 12) && (v1[2] & 7) == 0 )
    {
      v2 = v1[4];
      if ( v2 )
      {
        if ( !sub_840950(*v1) )
          sub_63DB50(v2);
        v1[4] = 0;
      }
      v3 = v1[5];
      if ( v3 )
      {
        if ( !sub_840950(*v1) )
          sub_63DB50(v3);
        v1[5] = 0;
      }
      if ( v1[6] )
      {
        FFX_Memory_Delete(v1[6], v4);
        v1[6] = 0;
      }
      if ( v1[8] )
        sub_641020(v1 + 8);
      if ( v1[7] )
      {
        FFX_Memory_Delete(v1[7], v4);
        v1[7] = 0;
      }
      sub_840EC0(v1);
    }
    v0 += 4;
  }
  while ( (int)v0 < (int)byte_13030E8 );
}
