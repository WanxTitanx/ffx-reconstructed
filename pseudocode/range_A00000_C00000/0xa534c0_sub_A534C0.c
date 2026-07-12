// Function: sub_A534C0
// Address: 0xa534c0
// Size: 0x4e
// Prototype: 

char __usercall sub_A534C0@<al>(int a1@<ebp>)
{
  int *v1; // edx
  int v2; // edi
  unsigned int *v3; // esi
  int v4; // edx
  unsigned int v5; // ecx
  unsigned int v6; // eax
  unsigned int v7; // edx
  unsigned int v8; // ecx
  double v9; // st7
  int v10; // ecx
  int v11; // edx
  int v12; // edi
  _DWORD *v13; // ecx
  int v14; // esi
  int v15; // eax
  int n2_1; // eax
  int v17; // eax
  int v19; // [esp+10h] [ebp-1D0h]
  int v20; // [esp+14h] [ebp-1CCh]
  int v21; // [esp+18h] [ebp-1C8h]
  int v22; // [esp+18h] [ebp-1C8h]
  int *v23; // [esp+1Ch] [ebp-1C4h]
  _BYTE *v24; // [esp+1Ch] [ebp-1C4h]
  char v25; // [esp+23h] [ebp-1BDh]
  _DWORD v26[2]; // [esp+24h] [ebp-1BCh] BYREF
  __int16 v27; // [esp+2Ch] [ebp-1B4h]
  char v28; // [esp+2Eh] [ebp-1B2h]
  int v29; // [esp+30h] [ebp-1B0h]
  int v30; // [esp+34h] [ebp-1ACh]
  int v31; // [esp+38h] [ebp-1A8h]
  int v32; // [esp+3Ch] [ebp-1A4h]
  int v33; // [esp+40h] [ebp-1A0h]
  _BYTE *v34; // [esp+44h] [ebp-19Ch]
  int v35; // [esp+48h] [ebp-198h]
  int v36; // [esp+4Ch] [ebp-194h]
  _BYTE *v37; // [esp+50h] [ebp-190h]
  int v38; // [esp+5Ch] [ebp-184h]
  int v39; // [esp+60h] [ebp-180h]
  int v40; // [esp+64h] [ebp-17Ch]
  _DWORD *v41; // [esp+68h] [ebp-178h]
  _BYTE v42[8]; // [esp+9Ch] [ebp-144h] BYREF
  int v43; // [esp+A4h] [ebp-13Ch] BYREF
  _BYTE v44[64]; // [esp+10Ch] [ebp-D4h] BYREF
  _BYTE v45[64]; // [esp+14Ch] [ebp-94h] BYREF
  _DWORD v46[14]; // [esp+18Ch] [ebp-54h] BYREF
  float v47; // [esp+1C4h] [ebp-1Ch]
  float v48; // [esp+1C8h] [ebp-18h]
  int v49; // [esp+1D4h] [ebp-Ch]
  void *v50; // [esp+1D8h] [ebp-8h]
  int n2; // [esp+1DCh] [ebp-4h]
  void *retaddr; // [esp+1E0h] [ebp+0h]

  if ( *(int *)(dword_2305834[0] + 71336) >= 0 )
    sub_A50ED0(*(_DWORD *)(dword_2305834[0] + 71336));
  n2_1 = *(_DWORD *)(dword_2305834[0] + 71344);
  if ( n2_1 == -2 )
  {
    n2 = 2;
LABEL_7:
    sub_639280(n2);
    goto LABEL_8;
  }
  if ( n2_1 == 2 )
  {
    n2 = 3;
    goto LABEL_7;
  }
LABEL_8:
  LOBYTE(v17) = dword_2305834[0];
  if ( *(int *)(dword_2305834[0] + 71344) > 0 )
  {
    v49 = a1;
    v50 = retaddr;
    v21 = *(__int16 *)(dword_2305834[0] + 2);
    v20 = dword_2305834[0] + 2056;
    v1 = &dword_C8659C;
    v2 = (unsigned __int8)(108
                         - (int)(flt_C44BE0[((*(unsigned __int16 *)(dword_2305834[0] + 2094)
                                            + (*(_DWORD *)(dword_2305834[0] + 71320) << 11)) >> 4)
                                          & 0xFFF]
                               * 0.1500000059604645
                               * -96.0));
    v23 = &dword_C8659C;
    v3 = (unsigned int *)&v43;
    do
    {
      v4 = *v1;
      v5 = (unsigned int)&unk_1FFFFFF & ((v2 * HIBYTE(v4)) >> 7);
      v6 = (unsigned int)&unk_1FFFFFF & ((v2 * BYTE2(v4)) >> 7);
      v3[1] = v5;
      v7 = (unsigned int)&unk_1FFFFFF & ((v2 * BYTE1(v4)) >> 7);
      v8 = v7 + ((v6 + (v5 << 8)) << 8);
      *(v3 - 1) = v7;
      *v3 = v6;
      v1 = v23 + 1;
      *(v3 - 2) = ((unsigned int)&unk_1FFFFFF & ((v2 * (unsigned __int8)*v23) >> 7)) + (v8 << 8);
      v23 = v1;
      v3 += 4;
    }
    while ( (int)v1 < (int)&dword_C865B8 );
    v9 = 1.0;
    v34 = v44;
    v41 = v46;
    v37 = v45;
    LOBYTE(v17) = LOBYTE(flt_C8F514[0]);
    *(float *)&v46[2] = flt_C8F510;
    *(float *)&v46[6] = flt_C8F510;
    *(float *)&v46[10] = flt_C8F510;
    v47 = flt_C8F510;
    v10 = v21;
    v48 = 1.0;
    v33 = 0;
    v28 = 0;
    v39 = 0;
    v38 = 0;
    v26[1] = byte_1740830;
    v29 = 0;
    v30 = 0;
    v31 = 0;
    v40 = 0;
    v36 = 0;
    v35 = 0;
    v46[0] = unk_C8F508[0];
    *(float *)&v46[1] = flt_C8F50C;
    *(float *)&v46[3] = flt_C8F514[0];
    v46[4] = unk_C8F508[0];
    *(float *)&v46[5] = flt_C8F50C;
    *(float *)&v46[7] = flt_C8F514[0];
    v46[8] = unk_C8F508[0];
    *(float *)&v46[9] = flt_C8F50C;
    *(float *)&v46[11] = flt_C8F514[0];
    v46[12] = unk_C8F508[0];
    *(float *)&v46[13] = flt_C8F50C;
    if ( v21 )
    {
      v11 = v20;
      do
      {
        v17 = *(unsigned __int16 *)(v11 + 6);
        v22 = --v10;
        if ( (_WORD)v17 != 0xFFFF )
        {
          v19 = dword_2305834[0] + 48 * v17 + 63528;
          v12 = v19 + 20;
          LOBYTE(v17) = 0;
          if ( *(_WORD *)(v19 + 20) != 4096 )
          {
            LOBYTE(v17) = *(_BYTE *)(v11 + 33) & *(_BYTE *)(dword_2305834[0] + 71113);
            v27 = -32668;
            v13 = v42;
            v25 = v17;
            v14 = -1;
            v24 = v42;
            do
            {
              if ( (v17 & 1) != 0 )
              {
                v15 = *v13;
                v47 = v9;
                v32 = v15;
                HIBYTE(v32) = 0x80;
                v26[0] = 44;
                sub_A5AD30((int)v45, v11, *(float *)(v19 + 16));
                sub_A5A360((int)v45, v20, v12, 0.00079999998);
                sub_6ED700(v44, dword_2305834[0] + 70624, v45);
                sub_A68140(unk_23057EC, v26, *(__int16 *)(dword_2305834[0] + 2) - v22 - 1, v14);
                v9 = 1.0;
                LOBYTE(v17) = v25;
                v13 = v24;
                v11 = v20;
              }
              v13 += 4;
              --v14;
              LOBYTE(v17) = (unsigned __int8)v17 >> 1;
              v12 += 4;
              v24 = v13;
              v25 = v17;
            }
            while ( v14 > -8 );
            v10 = v22;
          }
        }
        v11 += 40;
        v20 = v11;
      }
      while ( v10 );
    }
  }
  return v17;
}

