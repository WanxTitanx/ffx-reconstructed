// Function: sub_A6ED40
// Address: 0xa6ed40
// Size: 0x48d
// Prototype: int __cdecl(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD)

int __usercall sub_A6ED40@<eax>(int a1@<ebp>, int a2@<edi>, int a3, unsigned __int16 *a4, _DWORD *a5, int a6, float a7)
{
  unsigned __int16 *v7; // edi
  int result; // eax
  int *v9; // esi
  int v10; // esi
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // edx
  int v19; // edi
  int v20; // eax
  int v21; // esi
  unsigned __int16 *v22; // eax
  unsigned __int16 *v23; // esi
  int v24; // eax
  int v25; // esi
  __int16 v26; // ax
  int v27; // ecx
  int v28; // esi
  int v29; // [esp-28h] [ebp-108h]
  int v30; // [esp+4h] [ebp-DCh]
  float *v31; // [esp+18h] [ebp-C8h]
  float *v32; // [esp+1Ch] [ebp-C4h]
  float v33; // [esp+28h] [ebp-B8h]
  int v34; // [esp+30h] [ebp-B0h]
  int v35; // [esp+44h] [ebp-9Ch]
  int v36; // [esp+4Ch] [ebp-94h]
  int v37; // [esp+54h] [ebp-8Ch]
  float *v38; // [esp+58h] [ebp-88h]
  unsigned __int16 *v39; // [esp+5Ch] [ebp-84h]
  int v40; // [esp+60h] [ebp-80h]
  int v41; // [esp+64h] [ebp-7Ch]
  int v42; // [esp+68h] [ebp-78h]
  int v43; // [esp+68h] [ebp-78h]
  unsigned __int16 *v44; // [esp+68h] [ebp-78h]
  int v45; // [esp+6Ch] [ebp-74h]
  int v46; // [esp+70h] [ebp-70h]
  float v47; // [esp+70h] [ebp-70h]
  float v48; // [esp+70h] [ebp-70h]
  float v49; // [esp+70h] [ebp-70h]
  int n8; // [esp+70h] [ebp-70h]
  float v51[6]; // [esp+74h] [ebp-6Ch] BYREF
  _DWORD v52[21]; // [esp+8Ch] [ebp-54h] BYREF
  _UNKNOWN *retaddr; // [esp+E0h] [ebp+0h]

  v52[18] = a1;
  v52[19] = retaddr;
  v30 = a2;
  v7 = a4;
  result = 0;
  v9 = (int *)(a3 + 16);
  v41 = 0;
  v45 = a3 + 16;
  v36 = 0;
  if ( *(_WORD *)(a3 + 4) )
  {
    while ( 1 )
    {
      v10 = unknown_libname_741(*v9);
      v46 = v10;
      v42 = v10 + *(_DWORD *)(v10 + 8);
      v11 = unknown_libname_741(*(_DWORD *)(v45 + 4));
      *(float *)(v11 + 48) = *(float *)(v11 + 48) * 1000.0;
      v12 = unknown_libname_741(*(_DWORD *)(v45 + 4));
      *(float *)(v12 + 52) = *(float *)(v12 + 52) * 1000.0;
      v13 = unknown_libname_741(*(_DWORD *)(v45 + 4));
      *(float *)(v13 + 56) = *(float *)(v13 + 56) * 1000.0;
      v14 = unknown_libname_741(*(_DWORD *)(v45 + 4));
      sub_7E82C0(v52, a6, v14);
      v15 = unknown_libname_741(*(_DWORD *)(v45 + 4));
      *(float *)(v15 + 48) = *(float *)(v15 + 48) / 1000.0;
      v16 = unknown_libname_741(*(_DWORD *)(v45 + 4));
      *(float *)(v16 + 52) = *(float *)(v16 + 52) / 1000.0;
      v17 = unknown_libname_741(*(_DWORD *)(v45 + 4));
      *(float *)(v17 + 56) = *(float *)(v17 + 56) / 1000.0;
      v18 = FFX_Memory_Alloc(16 * *(__int16 *)(v10 + 18), v29);
      v40 = v18;
      if ( *(__int16 *)(v10 + 18) > 0 )
      {
        v19 = 0;
        v20 = v42 - v18;
        v21 = v18;
        v43 = v42 - v18;
        do
        {
          sub_6ED420(v21, v52, v21 + v20);
          ++v19;
          v21 += 16;
          v20 = v43;
        }
        while ( v19 < *(__int16 *)(v46 + 18) );
        v7 = a4;
        v18 = v40;
        v10 = v46;
      }
      v22 = (unsigned __int16 *)(v10 + *(_DWORD *)(v10 + 4));
      v39 = v22;
      if ( *((_BYTE *)v22 + 1) == 16 )
        break;
LABEL_24:
      v9 = (int *)(v45 + 16);
      v45 += 16;
      FFX_Memory_Delete(v40, v30);
      result = *(unsigned __int16 *)(a3 + 4);
      if ( ++v36 >= result )
        return result;
    }
    while ( 1 )
    {
      v23 = v22 + 16;
      v44 = v22 + 16;
      v35 = 0;
      if ( (__int16)v22[1] > 0 )
        break;
LABEL_23:
      v22 = v23;
      v39 = v23;
      if ( *((_BYTE *)v23 + 1) != 16 )
        goto LABEL_24;
      v18 = v40;
    }
    while ( 1 )
    {
      v24 = v41;
      if ( *(_WORD *)(*((_DWORD *)v7 + 3) + 2 * v41) != 0xFFFF )
        goto LABEL_22;
      v31 = (float *)(v18 + 16 * *v23);
      v47 = *(float *)(v18 + 16 * v23[1] + 4) + v31[1];
      v32 = (float *)(v18 + 16 * v23[1]);
      v38 = (float *)(v40 + 16 * v23[2]);
      v48 = v47 + v38[1];
      v49 = v48 / 3.0;
      if ( a7 < (double)v49 )
        goto LABEL_21;
      *(_WORD *)(*((_DWORD *)v7 + 3) + 2 * v41) = v7[1];
      v25 = 96 * v7[1];
      v37 = v25;
      v26 = *(unsigned __int16 *)((char *)v7 + v25 + 60);
      if ( v26 >= 0 )
      {
        v27 = *((_DWORD *)v7 + 3);
        if ( *(__int16 *)(v27 + 2 * v26) >= 0 )
          *(_WORD *)(v27 + 2 * v26) = -2;
      }
      v7[1] = (v7[1] + 1) % *v7;
      *(float *)((char *)v7 + v25 + 48) = (*v32 + *v31 + *v38) * 0.3333329856395721;
      *(float *)((char *)v7 + v25 + 52) = (v32[1] + v31[1] + v38[1]) * 0.3333329856395721;
      *(float *)((char *)v7 + v25 + 56) = 0.3333329856395721 * (v32[2] + v31[2] + v38[2]);
      *(_DWORD *)((char *)v7 + v25 + 128) = unk_C8F508[0];
      *(float *)((char *)v7 + v25 + 132) = flt_C8F50C;
      *(float *)((char *)v7 + v25 + 136) = flt_C8F510;
      *(float *)((char *)v7 + v25 + 140) = flt_C8F514[0];
      *(unsigned __int16 *)((char *)v7 + v25 + 76) = 0;
      v24 = v41;
      *(unsigned __int16 *)((char *)v7 + v25 + 60) = v41;
      *((_BYTE *)v7 + v25 + 62) = 0;
      *(unsigned __int16 *)((char *)v7 + v25 + 142) = 4096;
      if ( a5 )
        break;
      v23 = v44;
LABEL_22:
      v41 = v24 + 1;
      v23 += 14;
      v44 = v23;
      if ( ++v35 >= (__int16)v39[1] )
        goto LABEL_23;
      v18 = v40;
    }
    n8 = 8;
    do
    {
      sub_7E6610(4.0);
      v51[0] = *(float *)((char *)v7 + v25 + 48) + (float)4.0;
      v51[1] = (float)4.0 + *(float *)((char *)v7 + v25 + 52);
      v51[2] = (float)4.0 + *(float *)((char *)v7 + v25 + 56);
      sub_7E6610(16.0);
      v33 = (16.0 - 20.0) * 0.0625;
      v28 = (int)&a5[8 * (a5[1] % *a5) + 4];
      sub_7EA760(v28, v51, 1.0);
      *(float *)&unk_C8F530 = 0.0;
      unk_C8F534 = v34;
      *(float *)&MEMORY[0xC8F528] = 0.0;
      unk_C8F52C = LODWORD(v33);
      *(float *)(v28 + 16) = 0.0;
      *(float *)(v28 + 20) = v33;
      *(float *)(v28 + 24) = 0.0;
      v7 = a4;
      *(_DWORD *)(v28 + 28) = v34;
      *(_WORD *)(v28 + 28) = 0;
      v25 = v37;
      ++a5[1];
      --n8;
    }
    while ( n8 );
    v23 = v44;
LABEL_21:
    v24 = v41;
    goto LABEL_22;
  }
  return result;
}

