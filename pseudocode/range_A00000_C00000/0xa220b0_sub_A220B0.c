// Function: sub_A220B0
// Address: 0xa220b0
// Size: 0x6e1
// Prototype: 

int __thiscall sub_A220B0(int *this, int a2, int a3, int a4, int a5, int a6)
{
  int n3; // eax
  int v8; // esi
  _DWORD *v9; // ebx
  int n66; // eax
  unsigned int n4; // ecx
  size_t Size; // edx
  int v13; // esi
  _DWORD *v14; // ebx
  int n66_1; // eax
  unsigned int n4_1; // ecx
  size_t Size_1; // edx
  int v18; // esi
  int n66_2; // eax
  int v20; // ecx
  _DWORD *v21; // esi
  unsigned int n4_2; // ebx
  size_t Size_2; // ecx
  int v24; // ecx
  _DWORD *v25; // esi
  unsigned int n4_3; // ebx
  size_t Size_3; // ecx
  int v28; // esi
  int v29; // ecx
  int *v30; // eax
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  bool v34; // zf
  int v35; // eax
  int v36; // ecx
  int v37; // ecx
  int v38; // ecx
  int v39; // eax
  int v40; // eax
  _BYTE v41[16]; // [esp+10h] [ebp-7Ch] BYREF
  _BYTE v42[16]; // [esp+20h] [ebp-6Ch] BYREF
  _BYTE v43[16]; // [esp+30h] [ebp-5Ch] BYREF
  int n66_3; // [esp+40h] [ebp-4Ch] BYREF
  int v45; // [esp+44h] [ebp-48h]
  _DWORD *v46; // [esp+48h] [ebp-44h]
  int v47; // [esp+4Ch] [ebp-40h]
  _DWORD v48[4]; // [esp+50h] [ebp-3Ch] BYREF
  _DWORD v49[4]; // [esp+60h] [ebp-2Ch] BYREF
  _DWORD Src[4]; // [esp+70h] [ebp-1Ch] BYREF
  int v51; // [esp+88h] [ebp-4h]

  if ( !*(this + 7) )
    return 21;
  v8 = *(this + 30);
  if ( v8 )
  {
    v9 = *(_DWORD **)(*(this + 29) + 4);
    n66 = *(unsigned __int8 *)(v8 + 2);
    Src[0] = 66;
    Src[1] = 0;
    Src[3] = a4;
    Src[2] = this + 17;
    if ( n66 != 66 && n66 != 217 && n66 != 218 && n66 != 219 && n66 != 220 && n66 != 18 )
      return 5;
    if ( this != (int *)-68 )
    {
      if ( a4 )
      {
        n3 = sub_59E6B0(a4);
        if ( n3 )
          return n3;
      }
    }
    n4 = *(unsigned __int16 *)(v8 + 8);
    Size = *(_WORD *)(v8 + 10) & 0x1FFF;
    if ( n4 + Size <= *v9 )
    {
      if ( n4 >= 4 )
      {
        memcpy((char *)v9 + n4, Src, Size);
        n3 = 0;
      }
      else
      {
        n3 = 3;
      }
    }
    else
    {
      n3 = 3;
    }
    if ( n3 )
      return n3;
  }
  v13 = *(this + 31);
  if ( v13 )
  {
    v14 = *(_DWORD **)(*(this + 29) + 4);
    n66_1 = *(unsigned __int8 *)(v13 + 2);
    v49[0] = 66;
    v49[1] = 0;
    v49[3] = a5;
    v49[2] = this + 8;
    if ( n66_1 != 66 && n66_1 != 217 && n66_1 != 218 && n66_1 != 219 && n66_1 != 220 && n66_1 != 18 )
      return 5;
    if ( this != (int *)-32 )
    {
      if ( a5 )
      {
        n3 = sub_59E6B0(a5);
        if ( n3 )
          return n3;
      }
    }
    n4_1 = *(unsigned __int16 *)(v13 + 8);
    Size_1 = *(_WORD *)(v13 + 10) & 0x1FFF;
    if ( n4_1 + Size_1 <= *v14 )
    {
      if ( n4_1 >= 4 )
      {
        memcpy((char *)v14 + n4_1, v49, Size_1);
        n3 = 0;
      }
      else
      {
        n3 = 3;
      }
    }
    else
    {
      n3 = 3;
    }
    if ( n3 )
      return n3;
  }
  v18 = *(this + 33);
  if ( v18 )
  {
    n66_2 = *(unsigned __int8 *)(v18 + 2);
    v48[0] = 66;
    v48[1] = 0;
    v48[3] = a6;
    v48[2] = this + 8;
    if ( n66_2 == 66 || n66_2 == 217 || n66_2 == 218 || n66_2 == 219 || n66_2 == 220 || n66_2 == 18 )
    {
      if ( this != (int *)-32 )
      {
        if ( a6 )
        {
          n3 = sub_59E6B0(a6);
          if ( n3 )
            return n3;
        }
      }
      n3 = sub_4D5910(v18, v48);
      if ( n3 )
        return n3;
      goto LABEL_47;
    }
    return 5;
  }
LABEL_47:
  v20 = *(this + 35);
  if ( v20 )
  {
    v21 = *(_DWORD **)(*(this + 29) + 4);
    if ( this == (int *)-20 )
      return 1;
    n4_2 = *(unsigned __int16 *)(v20 + 8);
    Size_2 = *(_WORD *)(v20 + 10) & 0x1FFF;
    if ( Size_2 + n4_2 > *v21 || n4_2 < 4 )
      return 3;
    memcpy((char *)v21 + n4_2, this + 5, Size_2);
  }
  v24 = *(this + 36);
  if ( v24 )
  {
    v25 = *(_DWORD **)(*(this + 29) + 4);
    if ( this == (int *)-24 )
      return 1;
    n4_3 = *(unsigned __int16 *)(v24 + 8);
    Size_3 = *(_WORD *)(v24 + 10) & 0x1FFF;
    if ( Size_3 + n4_3 > *v25 || n4_3 < 4 )
      return 3;
    memcpy((char *)v25 + n4_3, this + 6, Size_3);
  }
  sub_5B3760(*(this + 26), 0);
  v51 = 0;
  v28 = sub_5BB2D0(v41, 0);
  if ( !v28 )
  {
    v28 = sub_5BB750(0);
    if ( !v28 )
    {
      *(_DWORD *)(a2 + 72) = &unk_1944F08;
      v28 = sub_5B5FD0(0);
      if ( !v28 )
      {
        v28 = sub_5B9C30(*(this + 7), *(_DWORD *)(*(this + 7) + 16), 0, *(_DWORD *)(a2 + 316));
        if ( !v28 )
        {
          v28 = sub_5B6AF0(1);
          if ( !v28 )
          {
            v28 = sub_5BB2D0(0, 0);
            if ( !v28 )
            {
              sub_5B3760(*(this + 27), 0);
              LOBYTE(v51) = 1;
              v28 = sub_5BB2D0(v42, 0);
              if ( !v28 )
              {
                v28 = sub_5BB750(0);
                if ( !v28 )
                {
                  *(_DWORD *)(a2 + 72) = &unk_1944F18;
                  v28 = sub_5B5FD0(0);
                  if ( !v28 )
                  {
                    v28 = sub_5B9C10(*(this + 7));
                    if ( !v28 )
                    {
                      v28 = sub_5B6AF0(1);
                      if ( !v28 )
                      {
                        v28 = sub_5BB2D0(0, 0);
                        if ( !v28 )
                        {
                          v29 = *(this + 30);
                          if ( !v29
                            || ((v45 = 0, v30 = (int *)*(this + 26), n66_3 = 66, *((_BYTE *)v30 + 4))
                              ? (v31 = 0)
                              : (v31 = *v30),
                                v47 = v31,
                                v46 = this + 17,
                                (v28 = sub_56E7E0(v29, &n66_3)) == 0) )
                          {
                            v32 = *(this + 32);
                            if ( !v32 )
                              goto LABEL_81;
                            v33 = *(this + 27);
                            n66_3 = 66;
                            v34 = *(_BYTE *)(v33 + 4) == 0;
                            v45 = 0;
                            v35 = v34 ? *(_DWORD *)v33 : 0;
                            v47 = v35;
                            v46 = this + 8;
                            v28 = sub_56E7E0(v32, &n66_3);
                            if ( !v28 )
                            {
LABEL_81:
                              sub_5B3760(*(this + 28), 0);
                              LOBYTE(v51) = 2;
                              v28 = sub_5BB2D0(v43, 0);
                              if ( !v28 )
                              {
                                v28 = sub_5BB750(0);
                                if ( !v28 )
                                {
                                  *(_DWORD *)(a2 + 72) = &unk_19449E4;
                                  v28 = sub_5B5FD0(0);
                                  if ( !v28 )
                                  {
                                    v28 = sub_5B9C10(*(this + 7));
                                    if ( !v28 )
                                    {
                                      v28 = sub_5B6AF0(1);
                                      if ( !v28 )
                                      {
                                        v28 = sub_5BB2D0(0, 0);
                                        if ( !v28 )
                                        {
                                          v36 = *(this + 30);
                                          if ( !v36
                                            || (v45 = 0,
                                                v47 = a4,
                                                v46 = this + 17,
                                                n66_3 = 66,
                                                (v28 = sub_56E7E0(v36, &n66_3)) == 0) )
                                          {
                                            v37 = *(this + 31);
                                            if ( !v37
                                              || (v47 = a5,
                                                  v46 = this + 8,
                                                  n66_3 = 66,
                                                  v45 = 0,
                                                  (v28 = sub_56E7E0(v37, &n66_3)) == 0) )
                                            {
                                              v38 = *(this + 34);
                                              if ( !v38 )
                                                goto LABEL_96;
                                              v39 = *(this + 28);
                                              n66_3 = 66;
                                              v34 = *(_BYTE *)(v39 + 4) == 0;
                                              v45 = 0;
                                              v40 = v34 ? *(_DWORD *)v39 : 0;
                                              v47 = v40;
                                              v46 = this + 17;
                                              v28 = sub_56E7E0(v38, &n66_3);
                                              if ( !v28 )
                                              {
LABEL_96:
                                                *(_DWORD *)(a2 + 72) = &unk_1944F28;
                                                if ( a3 )
                                                {
                                                  sub_5B3760(a3, 0);
                                                  LOBYTE(v51) = 3;
                                                  v28 = sub_5BB2D0(&n66_3, 0);
                                                  LOBYTE(v51) = 2;
                                                  nullsub_24(&n66_3);
                                                }
                                                else
                                                {
                                                  v28 = sub_5BB2D0(0, 0);
                                                }
                                                if ( !v28 )
                                                {
                                                  v28 = sub_5BB750(0);
                                                  if ( !v28 )
                                                  {
                                                    v28 = sub_5B5FD0(0);
                                                    if ( !v28 )
                                                    {
                                                      v28 = sub_5B9C10(*(this + 7));
                                                      if ( !v28 )
                                                      {
                                                        v28 = sub_5B6AF0(1);
                                                        if ( !v28 )
                                                          v28 = sub_5BB2D0(0, 0);
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                              LOBYTE(v51) = 1;
                              nullsub_24(v43);
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              LOBYTE(v51) = 0;
              nullsub_24(v42);
            }
          }
        }
      }
    }
  }
  v51 = -1;
  nullsub_24(v41);
  return v28;
}

