// Function: sub_99DAC0
// Address: 0x99dac0
int __userpurge sub_99DAC0@<eax>(int a1@<ecx>, int a2@<ebp>, _DWORD *a3, _DWORD *a4, int a5, int a6)
{
  int result; // eax
  int v7; // edx
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  int v11; // [esp-38h] [ebp-E8h]
  int v12; // [esp-24h] [ebp-D4h] BYREF
  _DWORD *v13; // [esp-18h] [ebp-C8h]
  int v14; // [esp-14h] [ebp-C4h]
  int v15; // [esp-10h] [ebp-C0h]
  int v16[43]; // [esp-Ch] [ebp-BCh] BYREF
  int v17; // [esp+A0h] [ebp-10h]
  _DWORD v18[2]; // [esp+A4h] [ebp-Ch] BYREF
  int v19; // [esp+ACh] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+B0h] [ebp+0h]

  v18[0] = a2;
  v18[1] = retaddr;
  v17 = -1;
  v16[42] = (int)&loc_AD951B;
  v16[41] = (int)NtCurrentTeb()->NtTib.ExceptionList;
  v16[40] = (int)&v19;
  v15 = a1;
  result = *(_DWORD *)(a1 + 12);
  v13 = a4;
  v14 = a5;
  if ( result )
  {
    v7 = a3[51];
    v8 = a4[51];
    *(_DWORD *)(a6 + 4) = result;
    v16[0] = a3[4];
    v16[1] = a3[5];
    v16[2] = a3[6];
    v16[3] = a3[7];
    v16[4] = a3[8];
    v16[5] = a3[9];
    v16[6] = a3[10];
    v16[7] = a3[11];
    v16[8] = a3[12];
    v16[9] = a3[13];
    v16[10] = a3[14];
    v16[11] = a3[15];
    v16[12] = a3[16];
    v16[13] = a3[17];
    v16[14] = a3[18];
    v16[15] = a3[19];
    v16[16] = v13[4];
    v16[17] = v13[5];
    v16[18] = v13[6];
    v16[19] = v13[7];
    v16[20] = v13[8];
    v16[21] = v13[9];
    v16[22] = v13[10];
    v16[23] = v13[11];
    v16[24] = v13[12];
    v16[25] = v13[13];
    v16[26] = v13[14];
    v16[27] = v13[15];
    v16[28] = v13[16];
    v16[29] = v13[17];
    v16[30] = v13[18];
    v9 = v13[19];
    v16[33] = 0;
    v16[32] = 1566444395;
    v16[31] = v9;
    sub_9A9B40(v7, v8);
    v11 = *(_DWORD *)(v14 + 20);
    v17 = 0;
    sub_9AC830((int)&v12, (int)v18, (int)v13, a6, v16, a6, v11, 0);
    result = v15;
    if ( *(_BYTE *)(v15 + 8) )
    {
      v10 = *(_DWORD *)(a6 + 4);
      if ( *(_DWORD *)(v10 + 1176) )
      {
        if ( *(_DWORD *)(v10 + 1168) == *(_DWORD *)(a6 + 144) )
          return sub_9A4470(a6 + 16, a6 + 80);
        else
          return sub_9A4470(a6 + 80, a6 + 16);
      }
    }
  }
  return result;
}
