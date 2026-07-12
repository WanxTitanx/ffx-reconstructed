// Function: sub_A0FD00
// Address: 0xa0fd00
// Size: 0x13c
// Prototype: 

int __thiscall sub_A0FD00(int *this, int a2, int a3, int a4)
{
  int v6; // esi
  int v7; // ecx
  int v8; // [esp-4h] [ebp-40h]
  _BYTE v9[16]; // [esp+10h] [ebp-2Ch] BYREF
  _DWORD Src[4]; // [esp+20h] [ebp-1Ch] BYREF
  int v11; // [esp+38h] [ebp-4h]

  if ( !a4 )
    return 5;
  sub_5B3760(a3, 0);
  v11 = 0;
  v6 = sub_5BB2D0(v9, 0);
  if ( !v6 )
  {
    v6 = sub_5BB750(0);
    if ( !v6 )
    {
      v7 = *(this + 4053);
      if ( !v7 || (Src[1] = 0, Src[3] = a4, Src[2] = this + 4026, Src[0] = 66, (v6 = sub_56E7E0(v7, Src)) == 0) )
      {
        v6 = sub_5B5FD0(0);
        if ( !v6 )
        {
          v8 = *(_DWORD *)(a2 + 316);
          *(_DWORD *)(a2 + 72) = &unk_1944B88;
          v6 = sub_5B9C30(*(this + 4023), *(_DWORD *)(*(this + 4023) + 16), 0, v8);
          if ( !v6 )
          {
            v6 = sub_5B6AF0(1);
            if ( !v6 )
              v6 = sub_5BB2D0(0, 0);
          }
        }
      }
    }
  }
  v11 = -1;
  nullsub_24(v9);
  return v6;
}

