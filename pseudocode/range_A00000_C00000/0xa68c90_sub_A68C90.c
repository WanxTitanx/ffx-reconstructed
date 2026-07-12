// Function: sub_A68C90
// Address: 0xa68c90
// Size: 0x178
// Prototype: 

int __cdecl sub_A68C90(int *a1, _DWORD *a2, int a3, void *a4)
{
  void *v4; // eax
  int *v5; // edi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v15; // [esp-28h] [ebp-108h]
  int v16; // [esp-24h] [ebp-104h]
  int v17; // [esp-10h] [ebp-F0h]
  int v18; // [esp-Ch] [ebp-ECh]
  int v19; // [esp-8h] [ebp-E8h]
  int v20; // [esp-4h] [ebp-E4h]
  int v21; // [esp+10h] [ebp-D0h]
  int v22; // [esp+14h] [ebp-CCh]
  int v23; // [esp+18h] [ebp-C8h]
  _BYTE v24[64]; // [esp+1Ch] [ebp-C4h] BYREF
  _BYTE v25[64]; // [esp+5Ch] [ebp-84h] BYREF
  _BYTE v26[64]; // [esp+9Ch] [ebp-44h] BYREF

  v4 = a4;
  v21 = a2[8];
  a2[8] = v25;
  a2[11] = v26;
  if ( !a4 )
    v4 = &unk_113FCB0;
  sub_7E7F20(v24, v4);
  v23 = a2[13];
  v22 = *((unsigned __int16 *)a1 + 2);
  v5 = a1 + 4;
  if ( *((_WORD *)a1 + 2) )
  {
    do
    {
      v6 = unknown_libname_741(v5[1]);
      v19 = v5[1];
      *(float *)(v6 + 48) = *(float *)(v6 + 48) * 1000.0;
      v7 = unknown_libname_741(v19);
      v18 = v5[1];
      *(float *)(v7 + 52) = *(float *)(v7 + 52) * 1000.0;
      v8 = unknown_libname_741(v18);
      v17 = v5[1];
      *(float *)(v8 + 56) = *(float *)(v8 + 56) * 1000.0;
      v9 = unknown_libname_741(v17);
      sub_7E82C0(v26, a3, v9);
      v10 = unknown_libname_741(v5[1]);
      v16 = v5[1];
      *(float *)(v10 + 48) = *(float *)(v10 + 48) * 0.001000000047497451;
      v11 = unknown_libname_741(v16);
      v15 = v5[1];
      *(float *)(v11 + 52) = *(float *)(v11 + 52) * 0.001000000047497451;
      v12 = unknown_libname_741(v15);
      *(float *)(v12 + 56) = *(float *)(v12 + 56) * 0.001000000047497451;
      sub_7E82C0(v25, v24, v26);
      v20 = *a1;
      v13 = unknown_libname_741(*v5);
      sub_A6A3A0(v13, a2, v20);
      v5 += 4;
      --v22;
    }
    while ( v22 > 0 );
  }
  a2[8] = v21;
  a2[11] = v23;
  return v23;
}

