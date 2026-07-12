// Function: FFX_Abmap_RecomputePartyStatsAndLearnedMoves
// Address: 0xa54860
// Size: 0x243
// Prototype: int()

int FFX_Abmap_RecomputePartyStatsAndLearnedMoves()
{
  int n7; // eax
  int v1; // ebx
  _BYTE *RuntimeStateTable; // edi
  int n1024; // esi
  int v4; // eax
  char *EntryByIdRange; // eax
  __int16 v6; // dx
  _DWORD *v7; // edi
  char n255_8; // cl
  char n255_9; // dl
  int v11; // [esp-10h] [ebp-64h]
  int v12; // [esp+0h] [ebp-54h] BYREF
  _DWORD *v13; // [esp+4h] [ebp-50h]
  int v14; // [esp+8h] [ebp-4Ch]
  int n255; // [esp+Ch] [ebp-48h]
  int v16; // [esp+10h] [ebp-44h]
  int n255_1; // [esp+14h] [ebp-40h]
  int n7_1; // [esp+18h] [ebp-3Ch]
  int n255_2; // [esp+1Ch] [ebp-38h]
  int n255_3; // [esp+20h] [ebp-34h]
  int n255_7; // [esp+24h] [ebp-30h]
  int n255_4; // [esp+28h] [ebp-2Ch]
  int n255_6; // [esp+2Ch] [ebp-28h]
  int n255_5; // [esp+30h] [ebp-24h]
  _DWORD v25[7]; // [esp+34h] [ebp-20h]

  sub_798830();
  n7 = 0;
  n7_1 = 0;
  do
  {
    v1 = 0;
    v25[0] = 0;
    v25[1] = 1;
    v25[2] = 2;
    v25[3] = 3;
    v25[4] = 4;
    v25[5] = 5;
    v25[6] = 6;
    v11 = v25[n7];
    v16 = 0;
    n255 = 0;
    n255_1 = 0;
    n255_2 = 0;
    n255_3 = 0;
    n255_4 = 0;
    n255_5 = 0;
    n255_6 = 0;
    n255_7 = 0;
    v13 = (_DWORD *)sub_798800(v11);
    RuntimeStateTable = FFX_SphereGrid_GetRuntimeStateTable();
    n1024 = 0;
    v4 = __ROL4__(1, n7_1);
    v14 = v4;
    do
    {
      if ( ((unsigned __int8)v4 & RuntimeStateTable[2 * n1024 + 1]) != 0 )
      {
        EntryByIdRange = FFX_Table_GetEntryByIdRange(
                           (unsigned __int8)RuntimeStateTable[2 * n1024],
                           (__int16 *)unk_1A860E0,
                           &v12);
        v6 = *((_WORD *)EntryByIdRange + 8);
        if ( (v6 & 1) != 0 )
          n255 += (unsigned __int8)EntryByIdRange[20];
        if ( (v6 & 2) != 0 )
          n255_1 += (unsigned __int8)EntryByIdRange[20];
        if ( (v6 & 4) != 0 )
          n255_2 += (unsigned __int8)EntryByIdRange[20];
        if ( (v6 & 8) != 0 )
          n255_3 += (unsigned __int8)EntryByIdRange[20];
        if ( (v6 & 0x10) != 0 )
          n255_4 += (unsigned __int8)EntryByIdRange[20];
        if ( (v6 & 0x20) != 0 )
          n255_5 += (unsigned __int8)EntryByIdRange[20];
        if ( (v6 & 0x40) != 0 )
          n255_6 += (unsigned __int8)EntryByIdRange[20];
        if ( (v6 & 0x80u) != 0 )
          n255_7 += (unsigned __int8)EntryByIdRange[20];
        if ( (v6 & 0x100) != 0 )
          v16 += (unsigned __int8)EntryByIdRange[20];
        if ( (v6 & 0x200) != 0 )
          v1 += (unsigned __int8)EntryByIdRange[20];
        FFX_SphereGrid_ApplyLearnedMove_structural(v25[n7_1], *((unsigned __int16 *)EntryByIdRange + 9));
        LOBYTE(v4) = v14;
      }
      ++n1024;
    }
    while ( n1024 < 1024 );
    v7 = v13;
    n255_8 = n255;
    if ( n255 > 255 )
      n255_8 = -1;
    n255_9 = n255_1;
    if ( n255_1 > 255 )
      n255_9 = -1;
    if ( n255_2 > 255 )
      n255_2 = 255;
    if ( n255_3 > 255 )
      n255_3 = 255;
    if ( n255_4 > 255 )
      n255_4 = 255;
    if ( n255_5 > 255 )
      n255_5 = 255;
    if ( n255_6 > 255 )
      n255_6 = 255;
    if ( n255_7 > 255 )
      n255_7 = 255;
    *v13 = v16;
    *((_BYTE *)v7 + 10) = n255_2;
    *((_BYTE *)v7 + 11) = n255_3;
    *((_BYTE *)v7 + 12) = n255_4;
    *((_BYTE *)v7 + 13) = n255_5;
    *((_BYTE *)v7 + 14) = n255_6;
    *((_BYTE *)v7 + 15) = n255_7;
    n7 = n7_1 + 1;
    v7[1] = v1;
    *((_BYTE *)v7 + 8) = n255_8;
    *((_BYTE *)v7 + 9) = n255_9;
    n7_1 = n7;
  }
  while ( n7 < 7 );
  return sub_7869C0();
}

