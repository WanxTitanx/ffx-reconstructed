// Function: sub_A76B60
// Address: 0xa76b60
// Size: 0x490
// Prototype: 

int __cdecl sub_A76B60(int a1, int a2)
{
  int v2; // ebx
  int v3; // edi
  int n4096; // eax
  int v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // edi
  int v10; // eax
  int v11; // eax
  int v12; // esi
  int *v13; // edi
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // [esp+0h] [ebp-210h]
  int v18; // [esp+24h] [ebp-1ECh]
  int v19; // [esp+28h] [ebp-1E8h]
  int v20; // [esp+30h] [ebp-1E0h]
  int v21; // [esp+30h] [ebp-1E0h]
  int v22; // [esp+34h] [ebp-1DCh]
  int v23; // [esp+34h] [ebp-1DCh]
  _BYTE v24[64]; // [esp+3Ch] [ebp-1D4h] BYREF
  _BYTE v25[64]; // [esp+7Ch] [ebp-194h] BYREF
  _BYTE v26[64]; // [esp+BCh] [ebp-154h] BYREF
  _BYTE v27[64]; // [esp+FCh] [ebp-114h] BYREF
  _BYTE v28[64]; // [esp+13Ch] [ebp-D4h] BYREF
  _BYTE v29[64]; // [esp+17Ch] [ebp-94h] BYREF
  _BYTE v30[64]; // [esp+1BCh] [ebp-54h] BYREF
  float v31; // [esp+1FCh] [ebp-14h] BYREF
  float v32; // [esp+200h] [ebp-10h]
  float v33; // [esp+204h] [ebp-Ch]
  float v34; // [esp+208h] [ebp-8h]

  v2 = *(_DWORD *)(a1 + 544);
  v3 = a2;
  v22 = LODWORD(flt_12A80C0[*(unsigned __int8 *)(v2 + 24)]);
  v20 = *(_DWORD *)(a1 + 4 * *(unsigned __int8 *)(v2 + 30) + 864);
  n4096 = *(_WORD *)(a1 + 538) & 0xF000;
  v18 = a1 + 768;
  if ( n4096 == 4096 )
  {
    v19 = sub_800F80(a1 + 768, v2, *(unsigned __int16 *)(a2 + 2));
    v21 = sub_80E2C0(a1 + 256, a1, v18, v2, *(__int16 *)(a2 + 4));
    sub_80EA60(a1 + 256, a1, v18, v2, a2 + 4);
    *(_WORD *)(a1 + 332) = 128;
    *(_DWORD *)(a1 + 272) = 0;
    *(_DWORD *)(a1 + 280) = *(_DWORD *)(v19 + 200);
    *(_DWORD *)(a1 + 284) = 0;
    *(_DWORD *)(v2 + 168) = 0;
    v11 = sub_801E20(a1, v2);
    sub_7E82C0(v26, a1 + 704, v11);
    sub_8061E0(v28, *(unsigned __int8 *)(v2 + 24), 256.0, v2 + 48, v2 + 144, *(char *)(a1 + 542));
    *(_DWORD *)a1 = unk_C8F508[0];
    *(float *)(a1 + 4) = flt_C8F50C;
    *(float *)(a1 + 8) = flt_C8F510;
    *(float *)(a1 + 12) = flt_C8F514[0];
    sub_8061E0(v25, *(unsigned __int8 *)(v2 + 24), 256.0, a1 + 4, v2 + 144, *(char *)(a1 + 542));
    sub_8061E0(a1 + 128, *(unsigned __int8 *)(v2 + 24), 256.0, 0, v2 + 144, *(char *)(a1 + 542));
    *(_DWORD *)(a1 + 300) = v29;
    v12 = 0;
    if ( *(_WORD *)(v21 + 4) )
    {
      v13 = (int *)(v21 + 20);
      do
      {
        v14 = unknown_libname_741(*v13);
        sub_7E82C0(v30, v28, v14);
        sub_7E82C0(a1 + 192, v26, v30);
        v15 = unknown_libname_741(*v13);
        sub_7E82C0(v30, a1 + 128, v15);
        v16 = unknown_libname_741(*v13);
        sub_7E82C0(v29, v25, v16);
        sub_834000(v22, v24);
        sub_6ED5A0(v27, v29);
        v31 = *(float *)(v19 + 144);
        v32 = *(float *)(v19 + 148);
        v33 = *(float *)(v19 + 152);
        v34 = 1.0;
        sub_6ED420(&v31, v27, &v31);
        v31 = v31 / 1000.0;
        v32 = v32 / 1000.0;
        v33 = v33 / 1000.0;
        v34 = 1.0;
        sub_63B790(v22, 0, v32);
        sub_63B790(v22, 1, v33);
        if ( (_WORD)a1 )
        {
          *(_WORD *)(v2 + 168) = a1;
          *(_WORD *)(v2 + 170) = v12;
        }
        ++v12;
        v13 += 4;
      }
      while ( v12 < *(unsigned __int16 *)(v21 + 4) );
    }
    return a2 + 14;
  }
  if ( n4096 != 0x2000 )
    return v3;
  if ( *(_WORD *)(a1 + 530) )
    return a2 + 6;
  if ( *(_WORD *)(v2 + 168) )
  {
    v23 = sub_80B680(a1 + 768, v2, a2 + *(__int16 *)(a2 + 2), 1, 0);
    if ( v23 )
    {
      v6 = sub_7E3720(v20, 4, *(__int16 *)(a2 + 4));
      v17 = *(unsigned __int16 *)(v2 + 170);
      v7 = v6 + 16 * (v17 + 1);
      v8 = sub_803120(v6, v17);
      v9 = v8 + *(_DWORD *)(v8 + 8) + 16 * *(unsigned __int16 *)(v2 + 168);
      sub_8061E0(a1, *(unsigned __int8 *)(v2 + 24), 256.0, v2 + 48, v2 + 144, *(char *)(a1 + 542));
      v10 = unknown_libname_741(*(_DWORD *)(v7 + 4));
      sub_7E82C0(a1, a1, v10);
      sub_7E78B0(v23 + 144, a1, v9);
      sub_7EA760(v23 + 64, v23 + 144, 16.0);
      v3 = a2;
      *(float *)(v23 + 76) = 0.0;
    }
  }
  return v3 + 6;
}

