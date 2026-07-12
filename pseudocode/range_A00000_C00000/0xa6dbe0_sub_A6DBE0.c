// Function: sub_A6DBE0
// Address: 0xa6dbe0
// Size: 0x5c8
// Prototype: 

int __cdecl sub_A6DBE0(int a1, int a2)
{
  int v2; // ebx
  int v3; // esi
  unsigned int n24576; // eax
  int v5; // eax
  int v7; // esi
  int v8; // eax
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  int v12; // edi
  int v13; // eax
  int *v14; // edi
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // ebx
  int v24; // eax
  int v25; // esi
  int v26; // eax
  double v27; // st7
  int v28; // eax
  int v29; // [esp-18h] [ebp-120h]
  int v30; // [esp-14h] [ebp-11Ch]
  int v31; // [esp+0h] [ebp-108h]
  int v32; // [esp+4h] [ebp-104h]
  int v33; // [esp+8h] [ebp-100h]
  int v34; // [esp+2Ch] [ebp-DCh]
  int v35; // [esp+2Ch] [ebp-DCh]
  int v36; // [esp+34h] [ebp-D4h]
  int v37; // [esp+38h] [ebp-D0h]
  float v38; // [esp+38h] [ebp-D0h]
  float v39; // [esp+38h] [ebp-D0h]
  int v40; // [esp+3Ch] [ebp-CCh]
  int v41; // [esp+3Ch] [ebp-CCh]
  int v42; // [esp+3Ch] [ebp-CCh]
  int v43; // [esp+40h] [ebp-C8h]
  int v44; // [esp+40h] [ebp-C8h]
  char v45; // [esp+44h] [ebp-C4h] BYREF
  char v46; // [esp+84h] [ebp-84h] BYREF
  _BYTE v47[64]; // [esp+C4h] [ebp-44h] BYREF

  v2 = a2;
  v3 = *(_DWORD *)(a1 + 544);
  v43 = v3;
  n24576 = *(_WORD *)(a1 + 538) & 0xF000;
  v34 = *(_DWORD *)(a1 + 4 * *(unsigned __int8 *)(v3 + 30) + 864);
  if ( n24576 > 0x4000 )
  {
    if ( n24576 == 20480 )
    {
      v42 = *(_DWORD *)(v3 + 188);
      v23 = *(_DWORD *)(sub_800F80(a1 + 768, v3, *(unsigned __int16 *)(a2 + 6)) + 188);
      v24 = sub_800F80(a1 + 768, v3, *(unsigned __int16 *)(a2 + 2));
      *(_DWORD *)a1 = unk_C8F508[0];
      *(float *)(a1 + 4) = flt_C8F50C;
      *(float *)(a1 + 8) = flt_C8F510;
      v25 = v24;
      v26 = *(char *)(a1 + 542);
      *(float *)(a1 + 12) = flt_C8F514[0];
      *(float *)(a1 + 4) = *(float *)(v43 + 52);
      sub_8061E0(a1 + 128, *(unsigned __int8 *)(v43 + 24), 256.0, a1, v43 + 144, v26);
      v27 = *(float *)(v42 + 36);
      v38 = v27 - *(float *)(v42 + 20);
      v39 = v27 - v38 * *(float *)(v25 + 68) * 0.00390625;
      v28 = sub_7E3720(v34, 4, *(__int16 *)(a2 + 4));
      sub_A6ED40(v28, v42, v23, a1 + 128, LODWORD(v39), &unk_1F80000);
      sub_A6E260(v42);
      unk_22FB3DC = LODWORD(flt_12A80C0[*(unsigned __int8 *)(v43 + 24)]);
      return a2 + 8;
    }
    else
    {
      if ( n24576 != 24576 )
        return a2;
      *(_DWORD *)a1 = unk_C8F508[0];
      *(float *)(a1 + 4) = flt_C8F50C;
      *(float *)(a1 + 8) = flt_C8F510;
      *(float *)(a1 + 12) = flt_C8F514[0];
      v13 = *(char *)(a1 + 542);
      *(float *)(a1 + 4) = *(float *)(v3 + 52);
      sub_8061E0(a1 + 128, *(unsigned __int8 *)(v3 + 24), 256.0, a1, v3 + 144, v13);
      memset((void *)(a1 + 256), 0, 0x70u);
      v36 = sub_80E2C0(a1 + 256, a1, a1 + 768, v3, *(__int16 *)(a2 + 4));
      *(_DWORD *)(a1 + 296) = &v45;
      *(_DWORD *)(a1 + 292) = &v46;
      *(_DWORD *)(a1 + 300) = v47;
      sub_80EA60(a1 + 256, a1, a1 + 768, v3, a2 + 4);
      unk_2332EA4 = sub_801E20(a1, v3);
      sub_7E82C0(a1 + 64, a1 + 704, unk_2332EA4);
      v37 = sub_800F80(a1 + 768, v3, *(unsigned __int16 *)(a2 + 2));
      v35 = *(_DWORD *)(v3 + 188);
      v41 = 0;
      v14 = (int *)(v36 + 16);
      v44 = 0;
      if ( *(_WORD *)(v36 + 4) )
      {
        do
        {
          v15 = unknown_libname_741(v14[1]);
          v33 = v14[1];
          *(float *)(v15 + 48) = *(float *)(v15 + 48) * 1000.0;
          v16 = unknown_libname_741(v33);
          v32 = v14[1];
          *(float *)(v16 + 52) = *(float *)(v16 + 52) * 1000.0;
          v17 = unknown_libname_741(v32);
          v31 = v14[1];
          *(float *)(v17 + 56) = *(float *)(v17 + 56) * 1000.0;
          v18 = unknown_libname_741(v31);
          sub_7E82C0(v47, a1 + 128, v18);
          v19 = unknown_libname_741(v14[1]);
          v30 = v14[1];
          *(float *)(v19 + 48) = *(float *)(v19 + 48) / 1000.0;
          v20 = unknown_libname_741(v30);
          v29 = v14[1];
          *(float *)(v20 + 52) = *(float *)(v20 + 52) / 1000.0;
          v21 = unknown_libname_741(v29);
          *(float *)(v21 + 56) = *(float *)(v21 + 56) / 1000.0;
          sub_7E82C0(a1 + 192, a1 + 64, v47);
          v22 = unknown_libname_741(*v14);
          v41 = sub_A6E650(v22, a1 + 256, v3, v37, v35, v41, v44);
          v14 += 4;
          ++v44;
        }
        while ( v44 < *(unsigned __int16 *)(v36 + 4) );
        v2 = a2;
      }
      return v2 + 14;
    }
  }
  else if ( n24576 == 0x4000 )
  {
    v9 = sub_7E3720(*(_DWORD *)(a1 + 4 * *(unsigned __int8 *)(v3 + 30) + 864), 4, *(__int16 *)(a2 + 2));
    v10 = *(__int16 *)(a2 + 4);
    v40 = v9;
    v11 = sub_A6A2B0(v9);
    v12 = sub_7FF6A0(*(_DWORD *)(a1 + 936), (2 * (48 * v10 + v11) + 63) & 0xFFFFFFF0);
    *(_DWORD *)(v3 + 188) = v12;
    *(_DWORD *)a1 = unk_C8F508[0];
    *(float *)(a1 + 4) = flt_C8F50C;
    *(float *)(a1 + 8) = flt_C8F510;
    *(float *)(a1 + 12) = flt_C8F514[0];
    sub_8061E0(a1 + 128, *(unsigned __int8 *)(v3 + 24), 256.0, a1, v3 + 144, *(char *)(a1 + 542));
    sub_A6E1B0(v12, v40, a1 + 128, v10);
    return a2 + 6;
  }
  else if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
  {
    if ( n24576 != 4096 )
    {
      if ( n24576 == 0x2000 )
      {
        v5 = sub_801E20(a1, v3);
        sub_7E7F20(a1, v5);
        sub_A6E2E0(*(_DWORD *)(v3 + 188));
        return a2 + 2;
      }
      return a2;
    }
    sub_7EA760(a1, v3 + 48, 0.00390625);
    sub_A6E5D0(*(_DWORD *)(v3 + 188), v3 + 144, a1);
    return a2 + 2;
  }
  else
  {
    v7 = *(__int16 *)(a2 + 2);
    v8 = sub_7FF6A0(*(_DWORD *)(a1 + 936), 32 * v7 + 16);
    *(_DWORD *)(v43 + 188) = v8;
    sub_A6E540(v8, v7);
    return a2 + 4;
  }
}

