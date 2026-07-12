// Function: sub_800F80
// Address: 0x800f80
int __cdecl sub_800F80(_DWORD *a1, int a2, __int16 a3)
{
  int v3; // esi
  __int16 v4; // di
  _DWORD *v6; // edi
  __int16 *v7; // edx
  __int16 v8; // ax
  int v9; // ecx
  __int16 *v10; // edx
  __int16 v11; // ax
  __int16 *v12; // edx
  __int16 v13; // ax
  int v14; // eax

  v3 = a2;
  v4 = a3;
  if ( a3 < 0 )
  {
    if ( a3 == -256 )
      return v3;
    if ( a3 == -1 )
    {
      v6 = a1 + 8;
      v3 = a1[8] + (*(unsigned __int16 *)(a2 + 28) << 8);
LABEL_25:
      if ( !sub_A446A0(*(_DWORD *)v3) )
        return v3;
      return *v6;
    }
    if ( (unsigned __int16)(a3 + 20479) > 0x1FFEu )
    {
      if ( (a3 & 0xFF00) != 0xFE00 )
      {
        v6 = a1 + 8;
        v14 = (unsigned __int16)-a3;
        do
        {
          v3 = a1[8] + (*(unsigned __int16 *)(v3 + 28) << 8);
          --v14;
        }
        while ( v14 );
        goto LABEL_25;
      }
      v4 = a3 & 0xF | *(_WORD *)(*((_DWORD *)&unk_12A40C4 + 8 * *(unsigned __int16 *)(a2 + 20)) + 26) & 0x7FF0;
    }
    else
    {
      v4 = *(_WORD *)(a2 + 26) + 0x4000 + a3;
    }
  }
  v7 = (__int16 *)a1[5];
  v8 = *v7;
  if ( *v7 < 0 )
  {
LABEL_12:
    v10 = (__int16 *)a1[4];
    v11 = *v10;
    if ( *v10 < 0 )
    {
LABEL_16:
      v12 = (__int16 *)a1[6];
      v13 = *v12;
      if ( *v12 < 0 )
        return a1[8];
      while ( 1 )
      {
        v9 = a1[8] + (v13 << 8);
        if ( *(unsigned __int16 *)(v9 + 26) == v4 && *(_BYTE *)(v9 + 30) == *(_BYTE *)(a2 + 30) )
          break;
        v13 = v12[1];
        ++v12;
        if ( v13 < 0 )
          return a1[8];
      }
    }
    else
    {
      while ( 1 )
      {
        v9 = a1[8] + (v11 << 8);
        if ( *(unsigned __int16 *)(v9 + 26) == v4 && *(_BYTE *)(v9 + 30) == *(_BYTE *)(a2 + 30) )
          break;
        v11 = v10[1];
        ++v10;
        if ( v11 < 0 )
          goto LABEL_16;
      }
    }
  }
  else
  {
    while ( 1 )
    {
      v9 = a1[8] + (v8 << 8);
      if ( *(unsigned __int16 *)(v9 + 26) == v4 && *(_BYTE *)(v9 + 30) == *(_BYTE *)(a2 + 30) )
        break;
      v8 = v7[1];
      ++v7;
      if ( v8 < 0 )
        goto LABEL_12;
    }
  }
  return v9;
}
