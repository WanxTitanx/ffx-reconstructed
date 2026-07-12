// Function: sub_A21DA0
// Address: 0xa21da0
// Size: 0x2fe
// Prototype: 

int __thiscall sub_A21DA0(int this, int a2, int a3)
{
  int v4; // eax
  int v5; // ecx
  _DWORD *v6; // esi
  unsigned int n4; // ebx
  size_t Size; // ecx
  int v10; // ecx
  _DWORD *v11; // esi
  unsigned int n4_1; // ebx
  size_t Size_1; // ecx
  int n5; // esi
  int v15; // edx
  char v16; // al
  float *v17; // ecx
  int v18; // ecx
  bool v19; // zf
  int v20; // ecx
  int v21; // [esp-4h] [ebp-48h]
  int v22; // [esp-4h] [ebp-48h]
  int Src; // [esp+10h] [ebp-34h] BYREF
  int v24; // [esp+14h] [ebp-30h]
  int v25; // [esp+18h] [ebp-2Ch]
  int v26; // [esp+1Ch] [ebp-28h]
  int v27; // [esp+20h] [ebp-24h]
  _BYTE v28[20]; // [esp+24h] [ebp-20h] BYREF
  int v29; // [esp+40h] [ebp-4h]
  char v30; // [esp+53h] [ebp+Fh]

  if ( *(_BYTE *)(this + 16428) )
  {
    v4 = *(_DWORD *)(this + 16088);
    if ( v4 )
    {
      v5 = *(_DWORD *)(this + 16408);
      if ( v5 )
      {
        v6 = *(_DWORD **)(v4 + 4);
        if ( this == -16072 )
          return 1;
        n4 = *(unsigned __int16 *)(v5 + 8);
        Size = *(_WORD *)(v5 + 10) & 0x1FFF;
        if ( Size + n4 > *v6 || n4 < 4 )
          return 3;
        memcpy((char *)v6 + n4, (const void *)(this + 16072), Size);
      }
      v10 = *(_DWORD *)(this + 16412);
      if ( v10 )
      {
        v11 = *(_DWORD **)(*(_DWORD *)(this + 16088) + 4);
        if ( this == -16076 )
          return 1;
        n4_1 = *(unsigned __int16 *)(v10 + 8);
        Size_1 = *(_WORD *)(v10 + 10) & 0x1FFF;
        if ( Size_1 + n4_1 > *v11 || n4_1 < 4 )
          return 3;
        memcpy((char *)v11 + n4_1, (const void *)(this + 16076), Size_1);
      }
      sub_5B3760(a3, 0);
      v29 = 0;
      n5 = sub_5BB2D0(a3 != 0 ? v28 : 0, 0);
      if ( n5 )
        goto LABEL_37;
      n5 = sub_5B5FD0(0);
      if ( n5 )
        goto LABEL_37;
      v15 = *(_DWORD *)(this + 16080);
      v16 = 0;
      v30 = 0;
      if ( v15 )
      {
        v17 = (float *)(this + 136);
        do
        {
          if ( *((_DWORD *)v17 - 9) != 1 )
          {
            if ( *v17 <= 0.00009999999747378752 )
            {
              v16 = v30;
            }
            else
            {
              v16 = 1;
              v30 = 1;
            }
          }
          v17 += 31;
          --v15;
        }
        while ( v15 );
        if ( v16 )
        {
          v21 = *(_DWORD *)(a2 + 316);
          *(_DWORD *)(a2 + 72) = &unk_1944C2C;
          n5 = sub_5B9C30(*(_DWORD *)(this + 16092), *(_DWORD *)(*(_DWORD *)(this + 16092) + 16), 0, v21);
          if ( n5 )
            goto LABEL_37;
        }
      }
      v18 = *(_DWORD *)(this + 16420);
      if ( v18 )
      {
        v19 = *(_BYTE *)(v18 + 2) == 72;
        v26 = *(_DWORD *)(this + 16436);
        Src = 72;
        v25 = 0;
        v27 = 0;
        v24 = 0;
        if ( !v19 )
        {
LABEL_31:
          n5 = 5;
          goto LABEL_37;
        }
        n5 = sub_4D5910(v18, &Src);
        if ( n5 )
        {
LABEL_37:
          v29 = -1;
          nullsub_24(v28);
          return n5;
        }
      }
      v20 = *(_DWORD *)(this + 16400);
      if ( v20 )
      {
        v19 = *(_BYTE *)(v20 + 2) == 72;
        v26 = *(_DWORD *)(this + 16340);
        Src = 72;
        v25 = 0;
        v27 = 0;
        v24 = 0;
        if ( !v19 )
          goto LABEL_31;
        n5 = sub_4D5910(v20, &Src);
        if ( n5 )
          goto LABEL_37;
      }
      v22 = *(_DWORD *)(a2 + 316);
      *(_DWORD *)(a2 + 72) = &unk_1944C4C;
      n5 = sub_5B9C30(*(_DWORD *)(this + 16092), *(_DWORD *)(*(_DWORD *)(this + 16092) + 16), 0, v22);
      if ( n5 )
        goto LABEL_37;
      n5 = sub_5B6AF0(1);
      if ( n5 )
        goto LABEL_37;
      n5 = sub_5BB2D0(0, 0);
      if ( n5 )
        goto LABEL_37;
      n5 = sub_5BB750(0);
      if ( n5 )
        goto LABEL_37;
      v29 = -1;
      nullsub_24(v28);
    }
  }
  return 0;
}

