// Function: sub_A1B9D0
// Address: 0xa1b9d0
// Size: 0x1d3
// Prototype: 

int __thiscall sub_A1B9D0(int *this, int a2, int a3)
{
  int v4; // eax
  int v5; // ecx
  int result; // eax
  int v7; // esi
  int v8; // edi
  int v9; // eax
  int v10; // esi
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  int v14; // esi
  _BYTE v15[16]; // [esp+20h] [ebp-2Ch] BYREF
  _DWORD Src[4]; // [esp+30h] [ebp-1Ch] BYREF
  int v17; // [esp+48h] [ebp-4h]

  if ( !*(this + 26) )
    return 21;
  if ( !*(this + 27) )
    return 21;
  v4 = *(this + 24);
  if ( !v4 )
    return 21;
  v5 = *(this + 25);
  if ( !v5 )
    return 21;
  if ( *(_UNKNOWN **)a3 != &unk_CA3454 )
    return 5;
  v7 = *(_BYTE *)(v4 + 4) ? 0 : *(_DWORD *)v4;
  v8 = *(_DWORD *)(a3 + 28);
  if ( *(_DWORD *)(v7 + 28) != v8 )
    return 5;
  v9 = *(_BYTE *)(v4 + 4) ? 0 : *(_DWORD *)v4;
  v10 = *(_DWORD *)(a3 + 32);
  if ( *(_DWORD *)(v9 + 32) != v10 )
    return 5;
  v11 = *(_BYTE *)(v5 + 4) ? 0 : *(_DWORD *)v5;
  if ( *(_DWORD *)(v11 + 28) != v8 )
    return 5;
  v12 = *(_BYTE *)(v5 + 4) ? 0 : *(_DWORD *)v5;
  if ( *(_DWORD *)(v12 + 32) != v10 )
    return 5;
  v13 = *(this + 28);
  if ( !v13 || (Src[2] = this + 6, Src[0] = 66, Src[1] = 0, Src[3] = a3, (result = sub_56E7E0(v13, Src)) == 0) )
  {
    *(_DWORD *)(a2 + 72) = &unk_1944D34;
    sub_5B3760(*(this + 24), 0);
    v17 = 0;
    v14 = sub_5BAF40(1.0, 1.0, 1.0, 1.0);
    if ( !v14 )
    {
      v14 = sub_5BB2D0(v15, 0);
      if ( !v14 )
      {
        v14 = sub_5BB750(0);
        if ( !v14 )
        {
          v14 = sub_5B5FD0(1);
          if ( !v14 )
          {
            v14 = sub_5B9C10(*(this + 26));
            if ( !v14 )
            {
              v14 = sub_5B6AF0(1);
              if ( !v14 )
                v14 = sub_5BB2D0(0, 0);
            }
          }
        }
      }
    }
    v17 = -1;
    nullsub_24(v15);
    return v14;
  }
  return result;
}

