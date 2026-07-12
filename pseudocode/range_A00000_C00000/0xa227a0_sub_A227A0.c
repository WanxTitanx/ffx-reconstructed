// Function: sub_A227A0
// Address: 0xa227a0
// Size: 0x29d
// Prototype: 

int __thiscall sub_A227A0(int *this, int a2, int a3, int a4)
{
  int result; // eax
  int v6; // edi
  int n66; // eax
  int v8; // ecx
  int v9; // ecx
  int v10; // edx
  int v11; // edx
  int v12; // edx
  int v13; // edi
  _BYTE v14[16]; // [esp+10h] [ebp-3Ch] BYREF
  int n66_1; // [esp+20h] [ebp-2Ch] BYREF
  int v16; // [esp+24h] [ebp-28h]
  int v17; // [esp+28h] [ebp-24h]
  int v18; // [esp+2Ch] [ebp-20h]
  _DWORD Src[4]; // [esp+30h] [ebp-1Ch] BYREF
  int v20; // [esp+48h] [ebp-4h]

  if ( !*(this + 823) || !*(this + 822) )
    return 21;
  sub_A25410(a3);
  v6 = *(this + 844);
  if ( !v6 )
    goto LABEL_16;
  n66 = *(unsigned __int8 *)(v6 + 2);
  Src[0] = 66;
  Src[1] = 0;
  Src[3] = a4;
  Src[2] = this + 824;
  if ( n66 != 66 && n66 != 217 && n66 != 218 && n66 != 219 && n66 != 220 && n66 != 18 )
    return 5;
  if ( this == (int *)-3296 || !a4 || (result = sub_59E6B0(a4)) == 0 )
  {
    result = sub_4D5910(v6, Src);
    if ( !result )
    {
LABEL_16:
      v8 = *(this + 843);
      if ( !v8 || (n66_1 = 66, v16 = 0, v17 = 0, v18 = 0, (result = sub_56E7E0(v8, &n66_1)) == 0) )
      {
        v9 = *(this + 845);
        if ( !v9 || (n66_1 = 66, v16 = 0, v17 = 0, v18 = 0, (result = sub_56E7E0(v9, &n66_1)) == 0) )
        {
          v10 = *(this + 846);
          if ( !v10 || (result = sub_638870(v10, this + 821)) == 0 )
          {
            v11 = *(this + 849);
            if ( !v11 || (result = sub_6388D0(v11, this + 37)) == 0 )
            {
              v12 = *(this + 850);
              if ( !v12 || (result = sub_6388D0(v12, this + 581)) == 0 )
              {
                *(_DWORD *)(a2 + 72) = &unk_1944D94;
                sub_5B3760(*(this + 822), 0);
                v20 = 0;
                v13 = sub_5BB2D0(v14, 0);
                if ( !v13 )
                {
                  v13 = sub_5BB750(0);
                  if ( !v13 )
                  {
                    v13 = sub_5B5FD0(1);
                    if ( !v13 )
                    {
                      v13 = sub_5B9C30(*(this + 823), *(_DWORD *)(*(this + 823) + 16), 0, *(_DWORD *)(a2 + 316));
                      if ( !v13 )
                        v13 = sub_5B6AF0(1);
                    }
                  }
                }
                v20 = -1;
                nullsub_24(v14);
                return v13;
              }
            }
          }
        }
      }
    }
  }
  return result;
}

