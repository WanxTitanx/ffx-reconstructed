// Function: sub_A3A820
// Address: 0xa3a820
// Size: 0x155
// Prototype: 

int __stdcall sub_A3A820(int a1, int a2, int a3, int a4, int a5, int a6)
{
  _DWORD *v6; // ecx
  int v7; // ebx
  int v8; // edx
  int v9; // eax
  int v10; // edi
  int v11; // ebx
  int v12; // esi
  int v13; // esi
  int v14; // eax
  int v15; // edx
  int v16; // edx
  int v17; // eax
  int v18; // edx
  int v19; // edx

  v6 = dword_1A858B4;
  if ( a1 || a2 || a3 != dword_1A858B4[436] )
  {
    v8 = a5;
    v7 = a4;
  }
  else
  {
    v7 = a4;
    v8 = dword_1A858B4[437] != a4 ? a5 : 0;
  }
  dword_1A858B4[438] = a3 - a1;
  v6[439] = v7 - a2;
  v6[442] = a1;
  v6[443] = a2;
  v9 = (a1 - v8) & ((a1 - v8 <= 0) - 1);
  v10 = v6[436];
  v6[444] = v9;
  v11 = (a2 - v8) & ((a2 - v8 <= 0) - 1);
  v12 = v8 + a3;
  v6[445] = v11;
  if ( v8 + a3 >= v10 )
    v12 = v10;
  v13 = v12 - v9;
  v14 = v8 + a4;
  v15 = v6[437];
  v6[440] = v13;
  if ( v14 >= v15 )
    v14 = v15;
  v16 = v6[432];
  v17 = v14 - v11;
  v6[441] = v17;
  if ( v13 <= v16 )
  {
    if ( v17 <= v6[433] )
      goto LABEL_17;
    if ( v13 <= v16 )
      v13 = v16;
  }
  v18 = v6[433];
  v6[432] = v13;
  if ( v17 <= v18 )
    v17 = v18;
  v6[433] = v17;
  sub_A36300(a6);
LABEL_17:
  sub_A3C280();
  (*(void (__stdcall **)(_DWORD, _DWORD, int, _DWORD, _DWORD))(*(_DWORD *)dword_1A858B4[1] + 212))(
    dword_1A858B4[1],
    dword_1A858B4[481],
    3,
    1.0,
    0);
  v19 = dword_1A858B4[482];
  if ( v19 )
    (*(void (__stdcall **)(_DWORD, int, int, _DWORD, _DWORD))(*(_DWORD *)dword_1A858B4[1] + 212))(
      dword_1A858B4[1],
      v19,
      3,
      1.0,
      0);
  sub_A3C350();
  sub_A3CD30();
  return sub_A3C570(a6);
}

