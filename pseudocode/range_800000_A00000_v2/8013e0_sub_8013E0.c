// Function: sub_8013E0
// Address: 0x8013e0
int __cdecl sub_8013E0(int a1, __int16 a2)
{
  int v2; // ebx
  int result; // eax
  __int16 v4; // cx
  __int16 v5; // cx
  __int16 v6; // cx
  int v7; // ecx
  __int16 i; // si
  int v9; // esi
  int v10; // ecx
  char v11; // al
  _WORD *v12; // eax
  int v13; // edi
  _WORD *v14; // ebx
  unsigned __int16 *v15; // esi
  int v16; // edi
  int v17; // edi
  __int64 v18; // [esp-10h] [ebp-20h]
  int v19; // [esp+4h] [ebp-Ch]
  int v20; // [esp+8h] [ebp-8h]
  int v21; // [esp+Ch] [ebp-4h]

  if ( unk_12A12BC )
    v2 = unk_12A12BC + 768;
  else
    v2 = a1;
  result = *(_DWORD *)(v2 + 20);
  v4 = *(_WORD *)result;
  v21 = v2;
  if ( *(__int16 *)result < 0 )
  {
LABEL_7:
    result = *(_DWORD *)(v2 + 16);
    v5 = *(_WORD *)result;
    if ( *(__int16 *)result < 0 )
    {
LABEL_10:
      result = *(_DWORD *)(v2 + 24);
      v6 = *(_WORD *)result;
      if ( *(__int16 *)result < 0 )
        return result;
      while ( v6 != a2 )
      {
        v6 = *(_WORD *)(result + 2);
        result += 2;
        if ( v6 < 0 )
          return result;
      }
    }
    else
    {
      while ( v5 != a2 )
      {
        v5 = *(_WORD *)(result + 2);
        result += 2;
        if ( v5 < 0 )
          goto LABEL_10;
      }
    }
  }
  else
  {
    while ( v4 != a2 )
    {
      v4 = *(_WORD *)(result + 2);
      result += 2;
      if ( v4 < 0 )
        goto LABEL_7;
    }
  }
  v7 = result + 2;
  for ( i = *(_WORD *)(result + 2); i >= 0; v7 += 2 )
  {
    *(_WORD *)result = i;
    result = v7;
    i = *(_WORD *)(v7 + 2);
  }
  *(_WORD *)result = -1;
  v9 = *(_DWORD *)(v2 + 32) + (a2 << 8);
  *(_DWORD *)v9 = 0;
  *(_DWORD *)(v9 + 4) = 0;
  *(_DWORD *)(v9 + 8) = 0;
  *(_DWORD *)(v9 + 12) = 0;
  v10 = *(_DWORD *)(v9 + 188);
  v20 = v9;
  if ( v10 )
  {
    v11 = *(_BYTE *)(v9 + 187);
    switch ( v11 )
    {
      case 3:
        (*(void (__cdecl **)(int))(*(_DWORD *)(v2 + 80) + 84))(v9);
        goto LABEL_35;
      case 5:
        sub_645430(v10, v10 >> 31);
LABEL_33:
        sub_7FF0F0(*(_DWORD *)(v2 + 168), *(_DWORD *)(v9 + 188));
        *(_DWORD *)(v9 + 188) = 0;
LABEL_35:
        *(_DWORD *)(v9 + 188) = 0;
        goto LABEL_36;
      case 10:
      case 17:
        v16 = 0;
        v19 = *(unsigned __int16 *)(v10 + 4);
        if ( !*(_WORD *)(v10 + 4) )
          goto LABEL_33;
        do
        {
          sub_645430(v16, (__PAIR64__(v9, 0) + v16) >> 32);
          ++v16;
        }
        while ( v16 < v19 );
        break;
      case 9:
        v12 = *(_WORD **)(v9 + 168);
        v13 = 0;
        v14 = v12 + 16;
        if ( !*v12 )
        {
LABEL_32:
          v2 = v21;
          goto LABEL_33;
        }
        v15 = *(unsigned __int16 **)(v9 + 168);
        do
        {
          HIDWORD(v18) = v14;
          LODWORD(v18) = 0;
          if ( sub_645580(v18) )
            sub_645430(0, v14);
          ++v13;
          v14 += 40;
        }
        while ( v13 < *v15 );
        break;
      default:
        goto LABEL_33;
    }
    v9 = v20;
    goto LABEL_32;
  }
LABEL_36:
  if ( *(_BYTE *)(v9 + 22) == 16 )
  {
    v17 = 0;
    if ( *(_BYTE *)(v9 + 23) )
    {
      do
      {
        sub_645430(v17, (__PAIR64__(v9, 0) + v17) >> 32);
        ++v17;
      }
      while ( v17 < *(unsigned __int8 *)(v9 + 23) );
      v2 = v21;
    }
  }
  if ( *(_BYTE *)(v9 + 187) == 1 )
    sub_645430(0, v9);
  if ( *(_BYTE *)(v9 + 187) == 2 )
    sub_645430(0, v9);
  sub_645430(21, (__PAIR64__(v9, 0) + 21) >> 32);
  --*(_WORD *)(v2 + 56);
  return 0xFFFF;
}
