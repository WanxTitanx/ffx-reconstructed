// Function: sub_98F620
// Address: 0x98f620
char __thiscall sub_98F620(int this, int a2, int a3, char a4)
{
  int v6; // eax
  int v7; // ebx
  int v8; // ebx
  bool v9; // zf
  int v10; // edx
  int v11; // ebx
  int v12; // ebx
  int v13; // ebx
  int v14; // ecx
  int v15; // edx
  char v16; // al
  _BYTE *v17; // ecx
  _BYTE *v18; // edx
  int v19; // ecx
  int v20; // edx
  char v21; // al
  _BYTE *v22; // ecx
  _BYTE *v23; // edx
  unsigned int v24; // ecx
  int v25; // ebx
  int v26; // edx
  int v27; // ecx
  int v28; // edx
  int v29; // ecx
  int v30; // ecx
  int v31; // eax
  int v32; // ecx
  int v33; // ebx
  int v34; // ebx
  int v35; // edx
  int v37; // [esp+8h] [ebp-4h]
  int v38; // [esp+8h] [ebp-4h]
  int v39; // [esp+8h] [ebp-4h]
  int v40; // [esp+14h] [ebp+8h]
  int v41; // [esp+14h] [ebp+8h]
  int v42; // [esp+1Ch] [ebp+10h]

  *(_DWORD *)(this + 180) = *(_DWORD *)(this + 164);
  if ( a2 )
    sub_98BB90((_DWORD *)a2);
  if ( a4 )
  {
    *(_DWORD *)(a2 + 68) = ((*(_DWORD *)(this + 68) & 0xFF00 | (*(_DWORD *)(this + 68) << 16)) << 8)
                         | ((HIWORD(*(_DWORD *)(this + 68)) | (unsigned int)&unk_FF0000 & *(_DWORD *)(this + 68)) >> 8);
    *(_BYTE *)(a2 + 16) = *(_BYTE *)(this + 19);
    *(_BYTE *)(a2 + 17) = *(_BYTE *)(this + 18);
    *(_BYTE *)(a2 + 18) = *(_BYTE *)(this + 17);
    *(_BYTE *)(a2 + 19) = *(_BYTE *)(this + 16);
    *(_BYTE *)(a2 + 20) = *(_BYTE *)(this + 23);
    *(_BYTE *)(a2 + 21) = *(_BYTE *)(this + 22);
    *(_BYTE *)(a2 + 22) = *(_BYTE *)(this + 21);
    *(_BYTE *)(a2 + 23) = *(_BYTE *)(this + 20);
    *(_BYTE *)(a2 + 24) = *(_BYTE *)(this + 27);
    *(_BYTE *)(a2 + 25) = *(_BYTE *)(this + 26);
    *(_BYTE *)(a2 + 26) = *(_BYTE *)(this + 25);
    *(_BYTE *)(a2 + 27) = *(_BYTE *)(this + 24);
    *(_BYTE *)(a2 + 28) = *(_BYTE *)(this + 31);
    *(_BYTE *)(a2 + 29) = *(_BYTE *)(this + 30);
    *(_BYTE *)(a2 + 30) = *(_BYTE *)(this + 29);
    *(_BYTE *)(a2 + 31) = *(_BYTE *)(this + 28);
    *(_BYTE *)(a2 + 32) = *(_BYTE *)(this + 35);
    *(_BYTE *)(a2 + 33) = *(_BYTE *)(this + 34);
    *(_BYTE *)(a2 + 34) = *(_BYTE *)(this + 33);
    *(_BYTE *)(a2 + 35) = *(_BYTE *)(this + 32);
    *(_BYTE *)(a2 + 36) = *(_BYTE *)(this + 39);
    *(_BYTE *)(a2 + 37) = *(_BYTE *)(this + 38);
    *(_BYTE *)(a2 + 38) = *(_BYTE *)(this + 37);
    *(_BYTE *)(a2 + 39) = *(_BYTE *)(this + 36);
    *(_BYTE *)(a2 + 40) = *(_BYTE *)(this + 43);
    *(_BYTE *)(a2 + 41) = *(_BYTE *)(this + 42);
    *(_BYTE *)(a2 + 42) = *(_BYTE *)(this + 41);
    *(_BYTE *)(a2 + 43) = *(_BYTE *)(this + 40);
    *(_BYTE *)(a2 + 44) = *(_BYTE *)(this + 47);
    *(_BYTE *)(a2 + 45) = *(_BYTE *)(this + 46);
    *(_BYTE *)(a2 + 46) = *(_BYTE *)(this + 45);
    *(_BYTE *)(a2 + 47) = *(_BYTE *)(this + 44);
    *(_BYTE *)(a2 + 48) = *(_BYTE *)(this + 51);
    *(_BYTE *)(a2 + 49) = *(_BYTE *)(this + 50);
    *(_BYTE *)(a2 + 50) = *(_BYTE *)(this + 49);
    *(_BYTE *)(a2 + 51) = *(_BYTE *)(this + 48);
    *(_BYTE *)(a2 + 52) = *(_BYTE *)(this + 55);
    *(_BYTE *)(a2 + 53) = *(_BYTE *)(this + 54);
    *(_BYTE *)(a2 + 54) = *(_BYTE *)(this + 53);
    *(_BYTE *)(a2 + 55) = *(_BYTE *)(this + 52);
    *(_BYTE *)(a2 + 56) = *(_BYTE *)(this + 59);
    *(_BYTE *)(a2 + 57) = *(_BYTE *)(this + 58);
    *(_BYTE *)(a2 + 58) = *(_BYTE *)(this + 57);
    *(_BYTE *)(a2 + 59) = *(_BYTE *)(this + 56);
    *(_BYTE *)(a2 + 60) = *(_BYTE *)(this + 63);
    *(_BYTE *)(a2 + 61) = *(_BYTE *)(this + 62);
    *(_BYTE *)(a2 + 62) = *(_BYTE *)(this + 61);
    *(_BYTE *)(a2 + 63) = *(_BYTE *)(this + 60);
    *(_DWORD *)(a2 + 156) = ((*(_DWORD *)(this + 156) & 0xFF00 | (*(_DWORD *)(this + 156) << 16)) << 8)
                          | ((HIWORD(*(_DWORD *)(this + 156)) | (unsigned int)&unk_FF0000 & *(_DWORD *)(this + 156)) >> 8);
    *(_DWORD *)(a2 + 180) = ((*(_DWORD *)(this + 180) & 0xFF00 | (*(_DWORD *)(this + 180) << 16)) << 8)
                          | ((HIWORD(*(_DWORD *)(this + 180)) | (unsigned int)&unk_FF0000 & *(_DWORD *)(this + 180)) >> 8);
  }
  else
  {
    *(_DWORD *)(a2 + 68) = *(_DWORD *)(this + 68);
    *(_DWORD *)(a2 + 16) = *(_DWORD *)(this + 16);
    *(_DWORD *)(a2 + 20) = *(_DWORD *)(this + 20);
    *(_DWORD *)(a2 + 24) = *(_DWORD *)(this + 24);
    *(_DWORD *)(a2 + 28) = *(_DWORD *)(this + 28);
    *(_DWORD *)(a2 + 32) = *(_DWORD *)(this + 32);
    *(_DWORD *)(a2 + 36) = *(_DWORD *)(this + 36);
    *(_DWORD *)(a2 + 40) = *(_DWORD *)(this + 40);
    *(_DWORD *)(a2 + 44) = *(_DWORD *)(this + 44);
    *(_DWORD *)(a2 + 48) = *(_DWORD *)(this + 48);
    *(_DWORD *)(a2 + 52) = *(_DWORD *)(this + 52);
    *(_DWORD *)(a2 + 56) = *(_DWORD *)(this + 56);
    *(_DWORD *)(a2 + 60) = *(_DWORD *)(this + 60);
    *(_DWORD *)(a2 + 156) = *(_DWORD *)(this + 156);
    *(_DWORD *)(a2 + 180) = *(_DWORD *)(this + 180);
  }
  *(_BYTE *)(a2 + 72) = *(_BYTE *)(this + 72);
  v6 = *(_DWORD *)(this + 68);
  v7 = a2 + 192;
  v40 = v6;
  if ( *(_BYTE *)(this + 72) )
  {
    if ( *(_DWORD *)(a2 + 148) )
    {
      if ( *(_BYTE *)(a2 + 152) )
      {
        sub_9D4D50(*(_DWORD *)(a2 + 148));
        v6 = v40;
      }
      *(_DWORD *)(a2 + 148) = 0;
    }
    *(_BYTE *)(a2 + 152) = 0;
    *(_DWORD *)(a2 + 148) = v7;
    *(_DWORD *)(a2 + 140) = v6;
    *(_DWORD *)(a2 + 144) = v6;
    if ( a4 )
    {
      if ( v6 > 0 )
      {
        v8 = 0;
        v37 = v6;
        do
        {
          v8 += 16;
          *(_WORD *)(v8 + *(_DWORD *)(a2 + 148) - 16) = __ROL2__(*(_WORD *)(v8 + *(_DWORD *)(this + 148) - 16), 8);
          *(_WORD *)(v8 + *(_DWORD *)(a2 + 148) - 14) = __ROL2__(*(_WORD *)(v8 + *(_DWORD *)(this + 148) - 14), 8);
          *(_WORD *)(v8 + *(_DWORD *)(a2 + 148) - 12) = __ROL2__(*(_WORD *)(v8 + *(_DWORD *)(this + 148) - 12), 8);
          *(_WORD *)(v8 + *(_DWORD *)(a2 + 148) - 10) = __ROL2__(*(_WORD *)(v8 + *(_DWORD *)(this + 148) - 10), 8);
          *(_WORD *)(v8 + *(_DWORD *)(a2 + 148) - 8) = __ROL2__(*(_WORD *)(v8 + *(_DWORD *)(this + 148) - 8), 8);
          *(_WORD *)(v8 + *(_DWORD *)(a2 + 148) - 6) = __ROL2__(*(_WORD *)(v8 + *(_DWORD *)(this + 148) - 6), 8);
          v9 = v37-- == 1;
          *(_DWORD *)(v8 + *(_DWORD *)(a2 + 148) - 4) = ((*(_DWORD *)(v8 + *(_DWORD *)(this + 148) - 4) & 0xFF00
                                                        | (*(_DWORD *)(v8 + *(_DWORD *)(this + 148) - 4) << 16)) << 8)
                                                      | ((HIWORD(*(_DWORD *)(v8 + *(_DWORD *)(this + 148) - 4))
                                                        | (unsigned int)&unk_FF0000
                                                        & *(_DWORD *)(v8 + *(_DWORD *)(this + 148) - 4)) >> 8);
        }
        while ( !v9 );
LABEL_19:
        v6 = v40;
        v7 = a2 + 192;
      }
    }
    else if ( v6 > 0 )
    {
      v10 = 0;
      v11 = v6;
      do
      {
        *(_WORD *)(v10 + *(_DWORD *)(a2 + 148)) = *(_WORD *)(v10 + *(_DWORD *)(this + 148));
        *(_WORD *)(v10 + *(_DWORD *)(a2 + 148) + 2) = *(_WORD *)(v10 + *(_DWORD *)(this + 148) + 2);
        *(_WORD *)(v10 + *(_DWORD *)(a2 + 148) + 4) = *(_WORD *)(v10 + *(_DWORD *)(this + 148) + 4);
        *(_WORD *)(v10 + *(_DWORD *)(a2 + 148) + 6) = *(_WORD *)(v10 + *(_DWORD *)(this + 148) + 6);
        *(_WORD *)(v10 + *(_DWORD *)(a2 + 148) + 8) = *(_WORD *)(v10 + *(_DWORD *)(this + 148) + 8);
        *(_WORD *)(v10 + *(_DWORD *)(a2 + 148) + 10) = *(_WORD *)(v10 + *(_DWORD *)(this + 148) + 10);
        *(_DWORD *)(v10 + *(_DWORD *)(a2 + 148) + 12) = *(_DWORD *)(v10 + *(_DWORD *)(this + 148) + 12);
        v10 += 16;
        --v11;
      }
      while ( v11 );
      goto LABEL_19;
    }
    v12 = 16 * v6 + v7;
    if ( *(_DWORD *)(a2 + 148) )
    {
      if ( *(_BYTE *)(a2 + 152) )
        sub_9D4D50(*(_DWORD *)(a2 + 148));
      *(_DWORD *)(a2 + 148) = 0;
    }
    *(_BYTE *)(a2 + 152) = 0;
    *(_DWORD *)(a2 + 148) = 0;
    *(_DWORD *)(a2 + 140) = 0;
    *(_DWORD *)(a2 + 144) = 0;
    goto LABEL_43;
  }
  if ( *(_DWORD *)(a2 + 108) )
  {
    if ( *(_BYTE *)(a2 + 112) )
    {
      sub_9D4D50(*(_DWORD *)(a2 + 108));
      v6 = v40;
    }
    *(_DWORD *)(a2 + 108) = 0;
  }
  *(_BYTE *)(a2 + 112) = 0;
  *(_DWORD *)(a2 + 108) = v7;
  *(_DWORD *)(a2 + 100) = v6;
  *(_DWORD *)(a2 + 104) = v6;
  if ( a4 )
  {
    if ( v6 > 0 )
    {
      v13 = 0;
      v38 = v6;
      do
      {
        v14 = *(_DWORD *)(this + 108);
        v15 = *(_DWORD *)(a2 + 108);
        *(_BYTE *)(v15 + v13) = *(_BYTE *)(v14 + v13 + 3);
        *(_BYTE *)(v15 + v13 + 1) = *(_BYTE *)(v14 + v13 + 2);
        *(_BYTE *)(v15 + v13 + 2) = *(_BYTE *)(v14 + v13 + 1);
        *(_BYTE *)(v15 + v13 + 3) = *(_BYTE *)(v14 + v13);
        *(_BYTE *)(v15 + v13 + 4) = *(_BYTE *)(v14 + v13 + 7);
        *(_BYTE *)(v15 + v13 + 5) = *(_BYTE *)(v14 + v13 + 6);
        *(_BYTE *)(v15 + v13 + 6) = *(_BYTE *)(v14 + v13 + 5);
        v16 = *(_BYTE *)(v14 + v13 + 4);
        v17 = (_BYTE *)(v13 + v14);
        v18 = (_BYTE *)(v13 + v15);
        v18[7] = v16;
        v18[8] = v17[11];
        v18[9] = v17[10];
        v18[10] = v17[9];
        v18[11] = v17[8];
        v18[12] = v17[15];
        v18[13] = v17[14];
        v18[14] = v17[13];
        v18[15] = v17[12];
        v19 = *(_DWORD *)(this + 108);
        v20 = *(_DWORD *)(a2 + 108);
        *(_BYTE *)(v20 + v13 + 16) = *(_BYTE *)(v19 + v13 + 19);
        *(_BYTE *)(v20 + v13 + 17) = *(_BYTE *)(v19 + v13 + 18);
        v21 = *(_BYTE *)(v19 + v13 + 17);
        v22 = (_BYTE *)(v13 + v19);
        v23 = (_BYTE *)(v13 + v20);
        v23[18] = v21;
        v23[19] = v22[16];
        v23[20] = v22[23];
        v23[21] = v22[22];
        v23[22] = v22[21];
        v23[23] = v22[20];
        v23[24] = v22[27];
        v23[25] = v22[26];
        v23[26] = v22[25];
        v23[27] = v22[24];
        v23[28] = v22[31];
        v23[29] = v22[30];
        v23[30] = v22[29];
        v23[31] = v22[28];
        v24 = *(_DWORD *)(v13 + *(_DWORD *)(this + 108) + 32);
        v13 += 64;
        *(_DWORD *)(v13 + *(_DWORD *)(a2 + 108) - 32) = ((v24 & 0xFF00 | (v24 << 16)) << 8)
                                                      | ((HIWORD(v24) | (unsigned int)&unk_FF0000 & v24) >> 8);
        *(_DWORD *)(v13 + *(_DWORD *)(a2 + 108) - 28) = ((*(_DWORD *)(v13 + *(_DWORD *)(this + 108) - 28) & 0xFF00
                                                        | (*(_DWORD *)(v13 + *(_DWORD *)(this + 108) - 28) << 16)) << 8)
                                                      | ((HIWORD(*(_DWORD *)(v13 + *(_DWORD *)(this + 108) - 28))
                                                        | (unsigned int)&unk_FF0000
                                                        & *(_DWORD *)(v13 + *(_DWORD *)(this + 108) - 28)) >> 8);
        v9 = v38-- == 1;
        *(_DWORD *)(v13 + *(_DWORD *)(a2 + 108) - 24) = ((*(_DWORD *)(v13 + *(_DWORD *)(this + 108) - 24) & 0xFF00
                                                        | (*(_DWORD *)(v13 + *(_DWORD *)(this + 108) - 24) << 16)) << 8)
                                                      | ((HIWORD(*(_DWORD *)(v13 + *(_DWORD *)(this + 108) - 24))
                                                        | (unsigned int)&unk_FF0000
                                                        & *(_DWORD *)(v13 + *(_DWORD *)(this + 108) - 24)) >> 8);
      }
      while ( !v9 );
LABEL_37:
      v6 = v40;
      v7 = a2 + 192;
    }
  }
  else if ( v6 > 0 )
  {
    v25 = 0;
    v39 = v6;
    do
    {
      v26 = *(_DWORD *)(this + 108);
      v27 = *(_DWORD *)(a2 + 108);
      *(_DWORD *)(v27 + v25) = *(_DWORD *)(v26 + v25);
      *(_DWORD *)(v27 + v25 + 4) = *(_DWORD *)(v26 + v25 + 4);
      *(_DWORD *)(v27 + v25 + 8) = *(_DWORD *)(v26 + v25 + 8);
      *(_DWORD *)(v25 + v27 + 12) = *(_DWORD *)(v26 + v25 + 12);
      v28 = *(_DWORD *)(this + 108);
      v29 = *(_DWORD *)(a2 + 108);
      *(_DWORD *)(v29 + v25 + 16) = *(_DWORD *)(v28 + v25 + 16);
      *(_DWORD *)(v29 + v25 + 20) = *(_DWORD *)(v28 + v25 + 20);
      v30 = v25 + v29;
      *(_DWORD *)(v30 + 24) = *(_DWORD *)(v28 + v25 + 24);
      *(_DWORD *)(v30 + 28) = *(_DWORD *)(v25 + v28 + 28);
      *(_DWORD *)(v25 + *(_DWORD *)(a2 + 108) + 32) = *(_DWORD *)(v25 + *(_DWORD *)(this + 108) + 32);
      *(_DWORD *)(v25 + *(_DWORD *)(a2 + 108) + 36) = *(_DWORD *)(v25 + *(_DWORD *)(this + 108) + 36);
      *(_DWORD *)(v25 + *(_DWORD *)(a2 + 108) + 40) = *(_DWORD *)(v25 + *(_DWORD *)(this + 108) + 40);
      v25 += 64;
      --v39;
    }
    while ( v39 );
    goto LABEL_37;
  }
  v12 = (v6 << 6) + v7;
  if ( *(_DWORD *)(a2 + 108) )
  {
    if ( *(_BYTE *)(a2 + 112) )
      sub_9D4D50(*(_DWORD *)(a2 + 108));
    *(_DWORD *)(a2 + 108) = 0;
  }
  *(_BYTE *)(a2 + 112) = 0;
  *(_DWORD *)(a2 + 108) = 0;
  *(_DWORD *)(a2 + 100) = 0;
  *(_DWORD *)(a2 + 104) = 0;
LABEL_43:
  v31 = *(_DWORD *)(a2 + 172);
  v32 = *(_DWORD *)(this + 180);
  v41 = v32;
  if ( v31 )
  {
    if ( *(_BYTE *)(a2 + 176) )
    {
      sub_9D4D50(v31);
      v32 = v41;
    }
    *(_DWORD *)(a2 + 172) = 0;
  }
  *(_BYTE *)(a2 + 176) = 0;
  *(_DWORD *)(a2 + 172) = v12;
  *(_DWORD *)(a2 + 164) = v32;
  *(_DWORD *)(a2 + 168) = v32;
  if ( a4 )
  {
    v42 = 0;
    if ( *(int *)(this + 180) > 0 )
    {
      v33 = 0;
      do
      {
        v33 += 32;
        *(_WORD *)(v33 + *(_DWORD *)(a2 + 172) - 32) = __ROL2__(*(_WORD *)(*(_DWORD *)(this + 172) + v33 - 32), 8);
        *(_WORD *)(v33 + *(_DWORD *)(a2 + 172) - 30) = __ROL2__(*(_WORD *)(*(_DWORD *)(this + 172) + v33 - 30), 8);
        *(_WORD *)(v33 + *(_DWORD *)(a2 + 172) - 28) = __ROL2__(*(_WORD *)(*(_DWORD *)(this + 172) + v33 - 28), 8);
        *(_WORD *)(v33 + *(_DWORD *)(a2 + 172) - 26) = __ROL2__(*(_WORD *)(*(_DWORD *)(this + 172) + v33 - 26), 8);
        *(_WORD *)(v33 + *(_DWORD *)(a2 + 172) - 24) = __ROL2__(*(_WORD *)(*(_DWORD *)(this + 172) + v33 - 24), 8);
        *(_WORD *)(v33 + *(_DWORD *)(a2 + 172) - 22) = __ROL2__(*(_WORD *)(*(_DWORD *)(this + 172) + v33 - 22), 8);
        *(_DWORD *)(v33 + *(_DWORD *)(a2 + 172) - 20) = ((*(_DWORD *)(*(_DWORD *)(this + 172) + v33 - 20) & 0xFF00
                                                        | (*(_DWORD *)(*(_DWORD *)(this + 172) + v33 - 20) << 16)) << 8)
                                                      | ((HIWORD(*(_DWORD *)(*(_DWORD *)(this + 172) + v33 - 20))
                                                        | (unsigned int)&unk_FF0000
                                                        & *(_DWORD *)(*(_DWORD *)(this + 172) + v33 - 20)) >> 8);
        *(_DWORD *)(v33 + *(_DWORD *)(a2 + 172) - 16) = ((*(_DWORD *)(*(_DWORD *)(this + 172) + v33 - 16) & 0xFF00
                                                        | (*(_DWORD *)(*(_DWORD *)(this + 172) + v33 - 16) << 16)) << 8)
                                                      | ((HIWORD(*(_DWORD *)(*(_DWORD *)(this + 172) + v33 - 16))
                                                        | (unsigned int)&unk_FF0000
                                                        & *(_DWORD *)(*(_DWORD *)(this + 172) + v33 - 16)) >> 8);
        ++v42;
      }
      while ( v42 < *(_DWORD *)(this + 180) );
    }
  }
  else
  {
    v34 = 0;
    if ( *(int *)(this + 180) > 0 )
    {
      v35 = 0;
      do
      {
        *(_WORD *)(v35 + *(_DWORD *)(a2 + 172)) = *(_WORD *)(v35 + *(_DWORD *)(this + 172));
        *(_WORD *)(v35 + *(_DWORD *)(a2 + 172) + 2) = *(_WORD *)(*(_DWORD *)(this + 172) + v35 + 2);
        *(_WORD *)(v35 + *(_DWORD *)(a2 + 172) + 4) = *(_WORD *)(*(_DWORD *)(this + 172) + v35 + 4);
        *(_WORD *)(v35 + *(_DWORD *)(a2 + 172) + 6) = *(_WORD *)(*(_DWORD *)(this + 172) + v35 + 6);
        *(_WORD *)(v35 + *(_DWORD *)(a2 + 172) + 8) = *(_WORD *)(*(_DWORD *)(this + 172) + v35 + 8);
        *(_WORD *)(v35 + *(_DWORD *)(a2 + 172) + 10) = *(_WORD *)(*(_DWORD *)(this + 172) + v35 + 10);
        *(_DWORD *)(v35 + *(_DWORD *)(a2 + 172) + 12) = *(_DWORD *)(*(_DWORD *)(this + 172) + v35 + 12);
        *(_DWORD *)(v35 + *(_DWORD *)(a2 + 172) + 16) = *(_DWORD *)(*(_DWORD *)(this + 172) + v35 + 16);
        ++v34;
        *(_DWORD *)(v35 + *(_DWORD *)(a2 + 172) + 20) = 0;
        v35 += 32;
        *(_DWORD *)(v35 + *(_DWORD *)(a2 + 172) - 8) = 0;
        *(_DWORD *)(v35 + *(_DWORD *)(a2 + 172) - 4) = 0;
      }
      while ( v34 < *(_DWORD *)(this + 180) );
    }
  }
  if ( *(_DWORD *)(a2 + 172) )
  {
    if ( *(_BYTE *)(a2 + 176) )
      sub_9D4D50(*(_DWORD *)(a2 + 172));
    *(_DWORD *)(a2 + 172) = 0;
  }
  *(_BYTE *)(a2 + 176) = 0;
  *(_DWORD *)(a2 + 172) = 0;
  *(_DWORD *)(a2 + 164) = 0;
  *(_DWORD *)(a2 + 168) = 0;
  *(_DWORD *)a2 = 0;
  return 1;
}
