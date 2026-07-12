// Function: sub_81BAC0
// Address: 0x81bac0
_WORD *__cdecl sub_81BAC0(int a1, _WORD *a2)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edx
  __int16 *v5; // edi
  __int16 *v6; // ecx
  int v7; // esi
  int v8; // eax
  _DWORD *v9; // edx
  int v10; // ecx
  __int16 *v11; // ebx
  int v12; // esi
  int v13; // eax
  int v14; // edx
  _DWORD *v15; // ecx
  __int16 v16; // dx
  int v18; // [esp-Ch] [ebp-2Ch]
  int v19; // [esp+Ch] [ebp-14h]
  int v20; // [esp+10h] [ebp-10h]
  int v21; // [esp+14h] [ebp-Ch]
  int v22; // [esp+18h] [ebp-8h]
  int v23; // [esp+18h] [ebp-8h]
  __int16 *v24; // [esp+1Ch] [ebp-4h]

  v2 = *(_DWORD *)(a1 + 544);
  v19 = v2;
  v24 = (__int16 *)sub_7E3720(*(_DWORD *)(a1 + 4 * *(unsigned __int8 *)(v2 + 30) + 864), 4, (unsigned __int16)a2[1]);
  sub_800C80(a1 + 768, *(_WORD *)(a1 + 532));
  v3 = 0;
  *(_DWORD *)(v2 + 212) = v24;
  *(_DWORD *)(v2 + 192) = sub_480080;
  *(_DWORD *)(v2 + 196) = 0;
  *(_WORD *)(v2 + 232) = 0;
  v4 = v24[3];
  v5 = v24 + 8;
  v22 = 0;
  if ( v4 > 0 )
  {
    v6 = v24 + 9;
    do
    {
      v22 += *v6;
      v6 += 4;
      --v4;
    }
    while ( v4 );
    v3 = v22;
  }
  *(_WORD *)(v2 + 232) = v3 / 256;
  v20 = (__int16)a2[2];
  v23 = 16 * v20 + 16;
  v7 = (*(_WORD *)(a1 + 538) & 0x1000) != 0 ? 16 * v20 : 0;
  v8 = sub_7FF6A0(*(_DWORD *)(a1 + 936), v23 + v7 + ((4 * (v3 / 256) + 15) & 0x7FFFFFF0));
  *(_DWORD *)(v2 + 188) = v8;
  sub_7E5E40(v8, 0, 32769, v20);
  v9 = (_DWORD *)(*(_DWORD *)(v2 + 188) + v7 + v23);
  v10 = 0;
  *(_DWORD *)(v2 + 224) = v9;
  v21 = 0;
  if ( v24[3] > 0 )
  {
    v11 = v24;
    do
    {
      v12 = (int)v11 + *v5;
      v13 = 0;
      v11 = v24;
      if ( v5[1] > 0 )
      {
        do
        {
          *v9 = v12;
          v13 += 256;
          ++v9;
        }
        while ( v13 < v5[1] );
        v10 = v21;
      }
      ++v10;
      v5 += 4;
      v21 = v10;
    }
    while ( v10 < v24[3] );
    v2 = v19;
  }
  if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
  {
    if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0x1000 )
    {
      v18 = *(_DWORD *)(v2 + 188);
      *(_BYTE *)(v2 + 187) = 17;
      sub_7E5E90(v18, v2 + 144, 0);
      v14 = v20;
      v15 = (_DWORD *)(v23 + *(_DWORD *)(v2 + 188));
      if ( v20 > 0 )
      {
        do
        {
          *v15 = *(_DWORD *)(v2 + 144);
          v15[1] = *(_DWORD *)(v2 + 148);
          v15[2] = *(_DWORD *)(v2 + 152);
          v15[3] = *(_DWORD *)(v2 + 156);
          v15 += 4;
          --v14;
        }
        while ( v14 );
      }
      v16 = a2[4];
      *(_WORD *)(v2 + 168) = a2[3];
      *(_WORD *)(v2 + 170) = v16;
      return a2 + 5;
    }
    else
    {
      return a2;
    }
  }
  else
  {
    *(_BYTE *)(v2 + 187) = 10;
    return a2 + 3;
  }
}
