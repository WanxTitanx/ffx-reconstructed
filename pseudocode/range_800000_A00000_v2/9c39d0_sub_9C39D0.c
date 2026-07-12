// Function: sub_9C39D0
// Address: 0x9c39d0
int __thiscall sub_9C39D0(int this, int a2)
{
  int v2; // eax
  int this_1; // esi
  int v4; // edi
  int v5; // ecx
  int v6; // edx
  int v7; // edi
  int v8; // ecx
  _DWORD *v9; // eax
  int v10; // ecx
  int i_1; // ecx
  int v12; // edi
  int v13; // edx
  double v14; // st7
  float *v15; // ecx
  double v16; // st6
  double v17; // st5
  int v18; // eax
  int v19; // esi
  int v20; // edx
  int v21; // edi
  _DWORD *v22; // ecx
  int result; // eax
  float v24; // [esp-C0h] [ebp-CCh]
  float v25; // [esp-BCh] [ebp-C8h]
  float v26; // [esp-B8h] [ebp-C4h]
  float v27; // [esp-B0h] [ebp-BCh]
  float v28; // [esp-ACh] [ebp-B8h]
  float v29; // [esp-A8h] [ebp-B4h]
  float v30; // [esp-A0h] [ebp-ACh]
  float v31; // [esp-9Ch] [ebp-A8h]
  float v32; // [esp-98h] [ebp-A4h]
  int v33; // [esp-8Ch] [ebp-98h]
  int v34; // [esp-88h] [ebp-94h]
  int v35; // [esp-84h] [ebp-90h]
  float v36; // [esp-80h] [ebp-8Ch]
  float v37; // [esp-7Ch] [ebp-88h]
  float v38; // [esp-78h] [ebp-84h]
  int v39; // [esp-70h] [ebp-7Ch]
  float v40; // [esp-58h] [ebp-64h]
  int v41; // [esp-54h] [ebp-60h]
  int v42; // [esp-50h] [ebp-5Ch]
  int v43; // [esp-48h] [ebp-54h]
  int n4; // [esp-40h] [ebp-4Ch]
  float v45; // [esp-3Ch] [ebp-48h]
  float v46; // [esp-38h] [ebp-44h]
  int i; // [esp-30h] [ebp-3Ch]
  int v49; // [esp-30h] [ebp-3Ch]
  int v50; // [esp-20h] [ebp-2Ch]
  int v51; // [esp-20h] [ebp-2Ch]
  char v52; // [esp-5h] [ebp-11h]
  int v53; // [esp-4h] [ebp-10h]
  _DWORD *v54; // [esp-4h] [ebp-10h]

  v2 = a2;
  this_1 = this;
  n4 = 0;
  *(_BYTE *)(this + 164) = 0;
  v4 = a2 + 28;
  do
  {
    v52 = 0;
    (*(void (__stdcall **)(_DWORD, int, _DWORD))(**(_DWORD **)(v2 + 24) + 28))(
      *(_DWORD *)(*(_DWORD *)(this_1 + 8) + 304),
      v4,
      *(_DWORD *)(v2 + 24));
    v5 = *(_DWORD *)(this_1 + 8);
    v45 = 0.0;
    *(_DWORD *)(this_1 + 96) = *(_DWORD *)(v5 + 64);
    *(_DWORD *)(this_1 + 100) = *(_DWORD *)(v5 + 68);
    *(_DWORD *)(this_1 + 104) = *(_DWORD *)(v5 + 72);
    *(_DWORD *)(this_1 + 108) = *(_DWORD *)(v5 + 76);
    v50 = 0;
    if ( (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v5 + 304) + 32))(*(_DWORD *)(v5 + 304)) > 0 )
    {
      v6 = this_1 + 144;
      v53 = 0;
      do
      {
        v7 = *(_DWORD *)(v6 + 4);
        if ( v7 < 0 )
        {
          if ( *(int *)(v6 + 8) < 0 )
          {
            if ( *(_DWORD *)(v6 + 12) )
            {
              if ( *(_BYTE *)(v6 + 16) )
              {
                sub_9D4D50(*(_DWORD *)(v6 + 12));
                v6 = this_1 + 144;
              }
              *(_DWORD *)(v6 + 12) = 0;
            }
            *(_BYTE *)(v6 + 16) = 1;
            *(_DWORD *)(v6 + 12) = 0;
            *(_DWORD *)(v6 + 8) = 0;
          }
          v8 = 4 * v7;
          do
          {
            v9 = (_DWORD *)(v8 + *(_DWORD *)(v6 + 12));
            if ( v9 )
              *v9 = 0;
            v8 += 4;
          }
          while ( v8 < 0 );
        }
        *(_DWORD *)(v6 + 4) = 0;
        v10 = *(_DWORD *)(v53
                        + *(_DWORD *)((*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(this_1 + 8) + 304) + 24))(*(_DWORD *)(*(_DWORD *)(this_1 + 8) + 304))
                                    + 12)
                        + 8);
        if ( v10 )
          (*(void (__thiscall **)(int, int))(*(_DWORD *)v10 + 12))(v10, this_1 + 144);
        i_1 = 0;
        for ( i = 0; i_1 < *(_DWORD *)(this_1 + 148); i = i_1 )
        {
          v46 = -1.0;
          v12 = *(_DWORD *)(*(_DWORD *)(this_1 + 156) + 4 * i_1);
          if ( *(_DWORD *)(v12 + 1168) != *(_DWORD *)(this_1 + 8) )
            v46 = 1.0;
          v13 = 0;
          if ( *(int *)(v12 + 1176) > 0 )
          {
            v14 = v46;
            v15 = (float *)(v12 + 88);
            do
            {
              v40 = v15[2];
              if ( v40 < 0.0 )
              {
                v16 = v40;
                if ( v45 > (double)v40 )
                {
                  v45 = v15[2];
                  v36 = *(v15 - 2) * v14;
                  v37 = *(v15 - 1) * v14;
                  v17 = *v15;
                  *(float *)(this_1 + 176) = v36;
                  *(float *)(this_1 + 180) = v37;
                  v38 = v17 * v14;
                  *(float *)(this_1 + 184) = v38;
                  *(_DWORD *)(this_1 + 188) = 0;
                }
                v52 = 1;
                v30 = *(v15 - 2) * v14;
                v31 = *(v15 - 1) * v14;
                v32 = *v15 * v14;
                v27 = v30 * v16;
                v28 = v31 * v16;
                v29 = v16 * v32;
                v24 = v27 * 0.2000000029802322;
                v25 = v28 * 0.2000000029802322;
                v26 = 0.2000000029802322 * v29;
                *(float *)(this_1 + 96) = v24 + *(float *)(this_1 + 96);
                *(float *)(this_1 + 100) = *(float *)(this_1 + 100) + v25;
                *(float *)(this_1 + 104) = *(float *)(this_1 + 104) + v26;
              }
              ++v13;
              v15 += 72;
            }
            while ( v13 < *(_DWORD *)(v12 + 1176) );
            i_1 = i;
          }
          ++i_1;
        }
        v53 += 16;
        ++v50;
        v18 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(this_1 + 8) + 304) + 32))(*(_DWORD *)(*(_DWORD *)(this_1 + 8) + 304));
        v6 = this_1 + 144;
      }
      while ( v50 < v18 );
    }
    v54 = *(_DWORD **)(this_1 + 8);
    v19 = v54[10];
    v20 = v54[9];
    v21 = v54[11];
    v49 = v54[12];
    v51 = v54[8];
    v35 = v54[13];
    v43 = v54[14];
    v33 = v54[15];
    v39 = *(_DWORD *)(this + 96);
    v34 = *(_DWORD *)(this + 100);
    v42 = *(_DWORD *)(this + 104);
    v41 = *(_DWORD *)(this + 108);
    v54[4] = v54[4];
    v54[5] = v54[5];
    v54[6] = v54[6];
    v54[7] = v54[7];
    v54[8] = v51;
    v54[12] = v49;
    v54[13] = v35;
    v54[14] = v43;
    v54[15] = v33;
    v54[9] = v20;
    v54[10] = v19;
    this_1 = this;
    v54[11] = v21;
    v54[16] = v39;
    v54[17] = v34;
    v54[18] = v42;
    v54[19] = v41;
    if ( !v52 )
      break;
    v2 = a2;
    ++n4;
    *(_BYTE *)(this + 164) = 1;
    v4 = a2 + 28;
  }
  while ( n4 <= 4 );
  v22 = *(_DWORD **)(this + 8);
  *(_DWORD *)(this + 96) = v22[16];
  *(_DWORD *)(this + 100) = v22[17];
  *(_DWORD *)(this + 104) = v22[18];
  *(_DWORD *)(this + 108) = v22[19];
  *(_DWORD *)(this + 128) = v22[16];
  *(_DWORD *)(this + 132) = v22[17];
  *(_DWORD *)(this + 136) = v22[18];
  result = v22[19];
  *(_DWORD *)(this + 140) = result;
  return result;
}
