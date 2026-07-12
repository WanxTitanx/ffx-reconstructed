// Function: sub_A1CA10
// Address: 0xa1ca10
// Size: 0x8a0
// Prototype: 

int __thiscall sub_A1CA10(int *this, int a2, int a3, int a4, int a5, int a6)
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
  int v18; // ecx
  _DWORD *v19; // esi
  unsigned int n4_2; // ebx
  size_t Size_2; // ecx
  int v22; // ecx
  _DWORD *v23; // esi
  unsigned int n4_3; // ebx
  size_t Size_3; // ecx
  int v26; // ecx
  _DWORD *v27; // esi
  unsigned int n4_4; // ebx
  size_t Size_4; // ecx
  int v30; // esi
  int v31; // edx
  int v32; // ecx
  int v33; // eax
  bool v34; // zf
  int v35; // eax
  int v36; // edx
  int v37; // edx
  int v38; // ecx
  int v39; // eax
  int v40; // eax
  int v41; // ecx
  int v42; // ecx
  int v43; // eax
  int v44; // eax
  int v45; // ecx
  int v46; // eax
  int v47; // eax
  int v48; // ecx
  int v49; // eax
  int v50; // eax
  int v51; // edx
  int v52; // edx
  int v53; // edx
  _BYTE v54[16]; // [esp+10h] [ebp-8Ch] BYREF
  _BYTE v55[16]; // [esp+20h] [ebp-7Ch] BYREF
  _BYTE v56[16]; // [esp+30h] [ebp-6Ch] BYREF
  _BYTE v57[16]; // [esp+40h] [ebp-5Ch] BYREF
  _BYTE v58[16]; // [esp+50h] [ebp-4Ch] BYREF
  int n66_2; // [esp+60h] [ebp-3Ch] BYREF
  int v60; // [esp+64h] [ebp-38h]
  _DWORD *v61; // [esp+68h] [ebp-34h]
  int v62; // [esp+6Ch] [ebp-30h]
  _DWORD v63[4]; // [esp+70h] [ebp-2Ch] BYREF
  _DWORD Src[4]; // [esp+80h] [ebp-1Ch] BYREF
  int v65; // [esp+98h] [ebp-4h]

  if ( !*(this + 974) )
    return 21;
  v8 = *(this + 994);
  if ( !v8 )
    goto LABEL_35;
  v9 = *(_DWORD **)(*(this + 975) + 4);
  n66 = *(unsigned __int8 *)(v8 + 2);
  Src[0] = 66;
  Src[1] = 0;
  Src[3] = a4;
  Src[2] = this + 985;
  if ( n66 != 66 && n66 != 217 && n66 != 218 && n66 != 219 && n66 != 220 && n66 != 18 )
    return 5;
  if ( this == (int *)-3940 || !a4 || (n3 = sub_59E6B0(a4)) == 0 )
  {
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
    if ( !n3 )
    {
LABEL_35:
      v13 = *(this + 997);
      if ( !v13 )
        goto LABEL_36;
      v14 = *(_DWORD **)(*(this + 975) + 4);
      n66_1 = *(unsigned __int8 *)(v13 + 2);
      v63[0] = 66;
      v63[1] = 0;
      v63[3] = a5;
      v63[2] = this + 976;
      if ( n66_1 != 66 && n66_1 != 217 && n66_1 != 218 && n66_1 != 219 && n66_1 != 220 && n66_1 != 18 )
        return 5;
      if ( this == (int *)-3904 || !a5 || (n3 = sub_59E6B0(a5)) == 0 )
      {
        n4_1 = *(unsigned __int16 *)(v13 + 8);
        Size_1 = *(_WORD *)(v13 + 10) & 0x1FFF;
        if ( n4_1 + Size_1 <= *v14 )
        {
          if ( n4_1 >= 4 )
          {
            memcpy((char *)v14 + n4_1, v63, Size_1);
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
        if ( !n3 )
        {
LABEL_36:
          v18 = *(this + 1005);
          if ( v18 )
          {
            v19 = *(_DWORD **)(*(this + 975) + 4);
            if ( this == (int *)-20 )
              return 1;
            n4_2 = *(unsigned __int16 *)(v18 + 8);
            Size_2 = *(_WORD *)(v18 + 10) & 0x1FFF;
            if ( Size_2 + n4_2 > *v19 || n4_2 < 4 )
              return 3;
            memcpy((char *)v19 + n4_2, this + 5, Size_2);
          }
          v22 = *(this + 1006);
          if ( v22 )
          {
            v23 = *(_DWORD **)(*(this + 975) + 4);
            if ( this == (int *)-24 )
              return 1;
            n4_3 = *(unsigned __int16 *)(v22 + 8);
            Size_3 = *(_WORD *)(v22 + 10) & 0x1FFF;
            if ( Size_3 + n4_3 > *v23 || n4_3 < 4 )
              return 3;
            memcpy((char *)v23 + n4_3, this + 6, Size_3);
          }
          v26 = *(this + 1007);
          if ( !v26 )
            goto LABEL_53;
          v27 = *(_DWORD **)(*(this + 975) + 4);
          if ( this == (int *)-28 )
            return 1;
          n4_4 = *(unsigned __int16 *)(v26 + 8);
          Size_4 = *(_WORD *)(v26 + 10) & 0x1FFF;
          if ( Size_4 + n4_4 <= *v27 && n4_4 >= 4 )
          {
            memcpy((char *)v27 + n4_4, this + 7, Size_4);
LABEL_53:
            n3 = sub_5BB750(0);
            if ( n3 )
              return n3;
            *(_DWORD *)(a2 + 72) = &unk_1944D14;
            sub_5B3760(*(this + 1004), 0);
            v65 = 0;
            v30 = sub_5BB2D0(v54, 0);
            if ( v30 )
              goto LABEL_122;
            v30 = sub_5B5FD0(0);
            if ( v30 )
              goto LABEL_122;
            v30 = sub_5B9C30(*(this + 974), *(_DWORD *)(*(this + 974) + 16), 0, *(_DWORD *)(a2 + 316));
            if ( v30 )
              goto LABEL_122;
            v30 = sub_5B6AF0(1);
            if ( v30 )
              goto LABEL_122;
            *(_DWORD *)(a2 + 72) = &unk_1944934;
            sub_5B3760(*(this + 971), 0);
            LOBYTE(v65) = 1;
            v30 = sub_5BB2D0(v55, 0);
            if ( v30 )
              goto LABEL_121;
            v30 = sub_5B5FD0(0);
            if ( v30 )
              goto LABEL_121;
            v30 = sub_5B9C10(*(this + 974));
            if ( v30 )
              goto LABEL_121;
            v30 = sub_5B6AF0(1);
            if ( v30 )
              goto LABEL_121;
            v31 = *(this + 1000);
            if ( v31 )
            {
              v30 = sub_638930(v31, this + 327);
              if ( v30 )
                goto LABEL_121;
            }
            v32 = *(this + 994);
            if ( v32 )
            {
              v33 = *(this + 971);
              n66_2 = 66;
              v34 = *(_BYTE *)(v33 + 4) == 0;
              v60 = 0;
              v35 = v34 ? *(_DWORD *)v33 : 0;
              v62 = v35;
              v61 = this + 976;
              v30 = sub_56E7E0(v32, &n66_2);
              if ( v30 )
                goto LABEL_121;
            }
            v36 = *(this + 999);
            if ( v36 )
            {
              v30 = sub_638930(v36, this + 323);
              if ( v30 )
              {
LABEL_121:
                LOBYTE(v65) = 0;
                nullsub_24(v55);
LABEL_122:
                v65 = -1;
                nullsub_24(v54);
                return v30;
              }
            }
            *(_DWORD *)(a2 + 72) = &unk_19435D8;
            sub_5B3760(*(this + 972), 0);
            LOBYTE(v65) = 2;
            v30 = sub_5BB2D0(v56, 0);
            if ( v30 )
              goto LABEL_120;
            v30 = sub_5B5FD0(0);
            if ( v30 )
              goto LABEL_120;
            v30 = sub_5B9C10(*(this + 974));
            if ( v30 )
              goto LABEL_120;
            v30 = sub_5B6AF0(1);
            if ( v30 )
              goto LABEL_120;
            v37 = *(this + 1000);
            if ( v37 )
            {
              v30 = sub_638930(v37, this + 355);
              if ( v30 )
                goto LABEL_120;
            }
            v38 = *(this + 994);
            if ( v38 )
            {
              v39 = *(this + 972);
              n66_2 = 66;
              v34 = *(_BYTE *)(v39 + 4) == 0;
              v60 = 0;
              v40 = v34 ? *(_DWORD *)v39 : 0;
              v62 = v40;
              v61 = this + 985;
              v30 = sub_56E7E0(v38, &n66_2);
              if ( v30 )
              {
LABEL_120:
                LOBYTE(v65) = 1;
                nullsub_24(v56);
                goto LABEL_121;
              }
            }
            *(_DWORD *)(a2 + 72) = &unk_19435D8;
            sub_5B3760(*(this + 973), 0);
            LOBYTE(v65) = 3;
            v30 = sub_5BB2D0(v57, 0);
            if ( v30 )
              goto LABEL_119;
            v30 = sub_5B5FD0(0);
            if ( v30 )
              goto LABEL_119;
            v30 = sub_5B9C10(*(this + 974));
            if ( v30 )
              goto LABEL_119;
            v30 = sub_5B6AF0(1);
            if ( v30 )
              goto LABEL_119;
            v41 = *(this + 994);
            if ( v41 )
            {
              v60 = 0;
              v62 = a4;
              v61 = this + 985;
              n66_2 = 66;
              v30 = sub_56E7E0(v41, &n66_2);
              if ( v30 )
                goto LABEL_119;
            }
            v42 = *(this + 995);
            if ( v42 )
            {
              v43 = *(this + 971);
              n66_2 = 66;
              v34 = *(_BYTE *)(v43 + 4) == 0;
              v60 = 0;
              v44 = v34 ? *(_DWORD *)v43 : 0;
              v62 = v44;
              v61 = this + 985;
              v30 = sub_56E7E0(v42, &n66_2);
              if ( v30 )
                goto LABEL_119;
            }
            v45 = *(this + 996);
            if ( v45 )
            {
              v46 = *(this + 973);
              n66_2 = 66;
              v34 = *(_BYTE *)(v46 + 4) == 0;
              v60 = 0;
              v47 = v34 ? *(_DWORD *)v46 : 0;
              v62 = v47;
              v61 = this + 985;
              v30 = sub_56E7E0(v45, &n66_2);
              if ( v30 )
                goto LABEL_119;
            }
            v48 = *(this + 998);
            if ( v48 )
            {
              v49 = *(this + 1004);
              n66_2 = 66;
              v34 = *(_BYTE *)(v49 + 4) == 0;
              v60 = 0;
              v50 = v34 ? *(_DWORD *)v49 : 0;
              v62 = v50;
              v61 = this + 985;
              v30 = sub_56E7E0(v48, &n66_2);
              if ( v30 )
                goto LABEL_119;
            }
            if ( (v51 = *(this + 1001)) != 0 && (v30 = sub_638930(v51, this + 383)) != 0
              || (v52 = *(this + 1002)) != 0 && (v30 = sub_638930(v52, this + 775)) != 0
              || (v53 = *(this + 1003)) != 0 && (v30 = sub_638930(v53, this + 579)) != 0 )
            {
LABEL_119:
              LOBYTE(v65) = 2;
              nullsub_24(v57);
              goto LABEL_120;
            }
            sub_5B3760(a6, 0);
            LOBYTE(v65) = 4;
            if ( a6 )
            {
              v30 = sub_5BB2D0(v58, 0);
              if ( v30 )
                goto LABEL_118;
            }
            else
            {
              v30 = sub_5BB2D0(0, 0);
              if ( v30 )
              {
LABEL_118:
                LOBYTE(v65) = 3;
                nullsub_24(v58);
                goto LABEL_119;
              }
            }
            v30 = sub_5BB750(0);
            if ( !v30 )
            {
              v30 = sub_5B5FD0(0);
              if ( !v30 )
              {
                *(_DWORD *)(a2 + 72) = &unk_1944D24;
                v30 = sub_5B9C10(*(this + 974));
                if ( !v30 )
                {
                  v30 = sub_5B6AF0(1);
                  if ( !v30 )
                    v30 = sub_5BB2D0(0, 0);
                }
              }
            }
            goto LABEL_118;
          }
          return 3;
        }
      }
    }
  }
  return n3;
}

