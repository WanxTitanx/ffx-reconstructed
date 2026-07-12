// Function: sub_801E20
// Address: 0x801e20
int __cdecl sub_801E20(_DWORD *a1, unsigned __int16 *a2)
{
  int v2; // ecx
  __int16 v3; // si
  __int16 *v5; // edx
  __int16 v6; // ax
  int v7; // ebx
  int v8; // ecx
  __int16 *v9; // edx
  __int16 v10; // ax
  __int16 *v11; // edx
  __int16 v12; // ax
  int v13; // eax

  v2 = (int)a2;
  v3 = a2[92];
  if ( !v3 )
    return (int)(a1 + 160);
  if ( v3 >= 0 )
    goto LABEL_9;
  if ( v3 == -256 )
    return v2 + 192;
  if ( v3 == -1 )
    return (a2[14] << 8) + a1[200] + 192;
  if ( (v3 & 0xFF00) != 0xFE00 )
  {
    v13 = (unsigned __int16)-v3;
    do
    {
      v2 = a1[200] + (*(unsigned __int16 *)(v2 + 28) << 8);
      --v13;
    }
    while ( v13 );
    return v2 + 192;
  }
  v3 = a2[92] & 0xF | *(_WORD *)(*((_DWORD *)&unk_12A40C4 + 8 * a2[10]) + 26) & 0x7FF0;
LABEL_9:
  v5 = (__int16 *)a1[197];
  v6 = *v5;
  if ( *v5 < 0 )
  {
LABEL_13:
    v9 = (__int16 *)a1[196];
    v10 = *v9;
    if ( *v9 < 0 )
    {
LABEL_17:
      v11 = (__int16 *)a1[198];
      v12 = *v11;
      if ( *v11 < 0 )
        return a1[200] + 192;
      v7 = a1[200];
      while ( 1 )
      {
        v8 = v12 << 8;
        if ( *(unsigned __int16 *)(v8 + v7 + 26) == v3 )
          break;
        v12 = v11[1];
        ++v11;
        if ( v12 < 0 )
          return a1[200] + 192;
      }
    }
    else
    {
      v7 = a1[200];
      while ( 1 )
      {
        v8 = v10 << 8;
        if ( *(unsigned __int16 *)(v8 + v7 + 26) == v3 )
          break;
        v10 = v9[1];
        ++v9;
        if ( v10 < 0 )
          goto LABEL_17;
      }
    }
  }
  else
  {
    v7 = a1[200];
    while ( 1 )
    {
      v8 = v6 << 8;
      if ( *(unsigned __int16 *)(v8 + v7 + 26) == v3 )
        break;
      v6 = v5[1];
      ++v5;
      if ( v6 < 0 )
        goto LABEL_13;
    }
  }
  return v8 + v7 + 192;
}
