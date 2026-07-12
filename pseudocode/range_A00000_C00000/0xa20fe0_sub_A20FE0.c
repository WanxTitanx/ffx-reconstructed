// Function: sub_A20FE0
// Address: 0xa20fe0
// Size: 0x5d7
// Prototype: 

int __thiscall sub_A20FE0(int *this, int a2, int a3, int a4, int a5)
{
  int v6; // esi
  int v7; // edi
  int n66; // eax
  int n3; // eax
  unsigned int n4; // ecx
  size_t Size; // edx
  int v12; // esi
  int n66_1; // eax
  unsigned int n4_1; // ecx
  size_t Size_1; // edx
  int v17; // edx
  unsigned int v18; // ecx
  unsigned int n4_2; // ecx
  _DWORD *v20; // esi
  size_t Size_2; // edx
  int v22; // ecx
  int v23; // eax
  unsigned int n4_4; // edx
  _DWORD *v25; // esi
  size_t Size_3; // ecx
  int v27; // esi
  int v28; // ecx
  int *v29; // eax
  int v30; // eax
  unsigned int n4_3; // eax
  int v32; // edx
  int *v33; // eax
  int v34; // eax
  int v35; // ecx
  int v36; // eax
  bool v37; // zf
  int v38; // eax
  int v39; // [esp-4h] [ebp-B8h]
  int v40; // [esp-4h] [ebp-B8h]
  _BYTE v41[16]; // [esp+10h] [ebp-A4h] BYREF
  _BYTE v42[16]; // [esp+20h] [ebp-94h] BYREF
  _BYTE v43[16]; // [esp+30h] [ebp-84h] BYREF
  _DWORD Src[4]; // [esp+40h] [ebp-74h] BYREF
  _DWORD v45[4]; // [esp+50h] [ebp-64h] BYREF
  float v46[4]; // [esp+60h] [ebp-54h] BYREF
  _DWORD v47[4]; // [esp+70h] [ebp-44h] BYREF
  _DWORD v48[4]; // [esp+80h] [ebp-34h] BYREF
  _DWORD v49[4]; // [esp+90h] [ebp-24h] BYREF
  float v50; // [esp+A0h] [ebp-14h] BYREF
  _DWORD *v51; // [esp+A4h] [ebp-10h]
  int v52; // [esp+B0h] [ebp-4h]
  float v53; // [esp+C4h] [ebp+10h]
  float v54; // [esp+C4h] [ebp+10h]
  unsigned int n4_5; // [esp+C4h] [ebp+10h]
  _DWORD *v56; // [esp+C8h] [ebp+14h]

  v6 = *(this + 28);
  v7 = a4;
  if ( !v6 )
    goto LABEL_87;
  v51 = *(_DWORD **)(*(this + 27) + 4);
  n66 = *(unsigned __int8 *)(v6 + 2);
  Src[0] = 66;
  Src[1] = 0;
  Src[3] = a4;
  Src[2] = this + 14;
  if ( n66 != 66 && n66 != 217 && n66 != 218 && n66 != 219 && n66 != 220 && n66 != 18 )
    return 5;
  if ( this == (int *)-56 || !a4 || (n3 = sub_59E6B0(a4)) == 0 )
  {
    n4 = *(unsigned __int16 *)(v6 + 8);
    Size = *(_WORD *)(v6 + 10) & 0x1FFF;
    if ( n4 + Size <= *v51 )
    {
      if ( n4 >= 4 )
      {
        memcpy((char *)v51 + n4, Src, Size);
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
    v7 = a4;
    if ( !n3 )
    {
LABEL_87:
      v12 = *(this + 29);
      if ( !v12 )
        goto LABEL_34;
      v56 = *(_DWORD **)(*(this + 27) + 4);
      n66_1 = *(unsigned __int8 *)(v12 + 2);
      v45[0] = 66;
      v45[1] = 0;
      v45[3] = a5;
      v45[2] = this + 5;
      if ( n66_1 != 66 && n66_1 != 217 && n66_1 != 218 && n66_1 != 219 && n66_1 != 220 && n66_1 != 18 )
        return 5;
      if ( this == (int *)-20 || !a5 || (n3 = sub_59E6B0(a5)) == 0 )
      {
        n4_1 = *(unsigned __int16 *)(v12 + 8);
        Size_1 = *(_WORD *)(v12 + 10) & 0x1FFF;
        if ( n4_1 + Size_1 <= *v56 )
        {
          if ( n4_1 >= 4 )
          {
            memcpy((char *)v56 + n4_1, v45, Size_1);
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
        v7 = a4;
        if ( !n3 )
        {
LABEL_34:
          v17 = *(this + 33);
          if ( v17 )
          {
            v18 = *(_DWORD *)(v7 + 32);
            v53 = (float)*(unsigned int *)(v7 + 28);
            v46[0] = 1.0 / v53;
            v54 = (float)v18;
            n4_2 = *(unsigned __int16 *)(v17 + 8);
            v20 = *(_DWORD **)(*(this + 27) + 4);
            Size_2 = *(_WORD *)(v17 + 10) & 0x1FFF;
            v46[1] = 1.0 / v54;
            v46[2] = 0.0;
            v46[3] = 0.0;
            if ( n4_2 + Size_2 > *v20 || n4_2 < 4 )
              return 3;
            memcpy((char *)v20 + n4_2, v46, Size_2);
          }
          v22 = *(this + 34);
          if ( !v22 )
          {
LABEL_42:
            sub_5B3760(*(this + 23), 0);
            v52 = 0;
            v27 = sub_5BB2D0(v41, 0);
            if ( !v27 )
            {
              v27 = sub_5BB750(0);
              if ( !v27 )
              {
                v27 = sub_5B5FD0(0);
                if ( !v27 )
                {
                  v39 = *(_DWORD *)(a2 + 316);
                  *(_DWORD *)(a2 + 72) = &unk_1944954;
                  v27 = sub_5B9C30(*(this + 26), *(_DWORD *)(*(this + 26) + 16), 0, v39);
                  if ( !v27 )
                  {
                    v27 = sub_5B6AF0(1);
                    if ( !v27 )
                    {
                      v28 = *(this + 30);
                      if ( !v28
                        || ((v49[1] = 0, v29 = (int *)*(this + 23), v49[0] = 66, *((_BYTE *)v29 + 4))
                          ? (v30 = 0)
                          : (v30 = *v29),
                            v49[3] = v30,
                            v49[2] = this + 14,
                            (v27 = sub_56E7E0(v28, v49)) == 0) )
                      {
                        LOBYTE(n4_3) = 0;
                        n4_5 = 0;
                        do
                        {
                          v32 = *(this + 31);
                          if ( v32 )
                          {
                            v48[0] = 66;
                            v33 = (int *)*(this + 25 - (n4_3 & 1));
                            v48[1] = 0;
                            if ( *((_BYTE *)v33 + 4) )
                              v34 = 0;
                            else
                              v34 = *v33;
                            v48[3] = v34;
                            v48[2] = this + 14;
                            v27 = sub_56E7E0(v32, v48);
                            if ( v27 )
                              goto LABEL_84;
                            LOBYTE(n4_3) = n4_5;
                          }
                          sub_5B3760(*(this + (n4_3 & 1) + 24), 0);
                          LOBYTE(v52) = 1;
                          v27 = sub_5BB2D0(v42, 0);
                          if ( v27
                            || (v27 = sub_5BB750(0)) != 0
                            || (v27 = sub_5B5FD0(0)) != 0
                            || (n4_5 ? (*(_DWORD *)(a2 + 72) = &unk_1944974) : (*(_DWORD *)(a2 + 72) = &unk_1944964),
                                (v27 = sub_5B9C30(
                                         *(this + 26),
                                         *(_DWORD *)(*(this + 26) + 16),
                                         0,
                                         *(_DWORD *)(a2 + 316))) != 0
                             || (v27 = sub_5B6AF0(1)) != 0) )
                          {
                            LOBYTE(v52) = 0;
                            nullsub_24(v42);
                            goto LABEL_84;
                          }
                          LOBYTE(v52) = 0;
                          nullsub_24(v42);
                          n4_3 = n4_5 + 1;
                          n4_5 = n4_3;
                        }
                        while ( n4_3 < 4 );
                        v35 = *(this + 31);
                        if ( !v35 )
                          goto LABEL_74;
                        v36 = *(this + 25);
                        v47[0] = 66;
                        v37 = *(_BYTE *)(v36 + 4) == 0;
                        v47[1] = 0;
                        v38 = v37 ? *(_DWORD *)v36 : 0;
                        v47[3] = v38;
                        v47[2] = this + 14;
                        v27 = sub_56E7E0(v35, v47);
                        if ( !v27 )
                        {
LABEL_74:
                          if ( a3 )
                          {
                            sub_5B3760(a3, 0);
                            LOBYTE(v52) = 2;
                            v27 = sub_5BB2D0(v43, 0);
                            LOBYTE(v52) = 0;
                            nullsub_24(v43);
                          }
                          else
                          {
                            v27 = sub_5BB2D0(0, 0);
                          }
                          if ( !v27 )
                          {
                            v27 = sub_5BB750(0);
                            if ( !v27 )
                            {
                              v27 = sub_5B5FD0(0);
                              if ( !v27 )
                              {
                                v40 = *(_DWORD *)(a2 + 316);
                                *(_DWORD *)(a2 + 72) = &unk_1944984;
                                v27 = sub_5B9C30(*(this + 26), *(_DWORD *)(*(this + 26) + 16), 0, v40);
                                if ( !v27 )
                                {
                                  v27 = sub_5B6AF0(1);
                                  if ( !v27 )
                                    v27 = sub_5BB2D0(0, 0);
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
LABEL_84:
            v52 = -1;
            nullsub_24(v41);
            return v27;
          }
          v23 = *(this + 27);
          n4_4 = *(unsigned __int16 *)(v22 + 8);
          v50 = 0.5;
          v25 = *(_DWORD **)(v23 + 4);
          Size_3 = *(_WORD *)(v22 + 10) & 0x1FFF;
          if ( n4_4 + Size_3 <= *v25 && n4_4 >= 4 )
          {
            memcpy((char *)v25 + n4_4, &v50, Size_3);
            goto LABEL_42;
          }
          return 3;
        }
      }
    }
  }
  return n3;
}

