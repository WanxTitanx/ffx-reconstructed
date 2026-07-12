// Function: sub_840150
// Address: 0x840150
int sub_840150()
{
  char *v0; // edi
  _DWORD *v1; // esi
  char n5; // al
  int v3; // ebx
  int v4; // ebx
  int v6; // [esp+0h] [ebp-Ch]

  v0 = (char *)&unk_1302F58;
  do
  {
    v1 = *(_DWORD **)v0;
    if ( *(_DWORD *)(*(_DWORD *)v0 + 12) )
    {
      if ( !*((_BYTE *)v1 + 5) )
      {
        n5 = v1[2] & 7;
        if ( n5 != 5 && n5 != 7 )
        {
          if ( *((_BYTE *)v1 + 6) )
          {
            v1[9] = 1;
          }
          else
          {
            v3 = v1[4];
            if ( v3 )
            {
              if ( !sub_840950(*v1) )
                sub_63DB50(v3);
              v1[4] = 0;
            }
            v4 = v1[5];
            if ( v4 )
            {
              if ( !sub_840950(*v1) )
                sub_63DB50(v4);
              v1[5] = 0;
            }
            if ( v1[6] )
            {
              FFX_Memory_Delete(v1[6], v6);
              v1[6] = 0;
            }
            if ( v1[8] )
              sub_641020(v1 + 8);
            if ( v1[7] )
            {
              FFX_Memory_Delete(v1[7], v6);
              v1[7] = 0;
            }
            sub_840EC0(v1);
          }
        }
      }
    }
    v0 += 4;
  }
  while ( (int)v0 < (int)byte_13030E8 );
  return nullsub_117();
}
