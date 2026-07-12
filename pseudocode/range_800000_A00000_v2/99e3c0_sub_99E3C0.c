// Function: sub_99E3C0
// Address: 0x99e3c0
int __userpurge sub_99E3C0@<eax>(int a1@<ecx>, int a2@<ebp>, _DWORD *a3, _DWORD *a4, int a5, int a6)
{
  _DWORD *v6; // edi
  _DWORD *v7; // esi
  int result; // eax
  int v9; // edi
  int v10; // esi
  int v11; // eax
  int v12; // ecx
  float v13; // [esp+0h] [ebp-F4h]
  _DWORD *v14; // [esp+24h] [ebp-D0h]
  _DWORD *v16; // [esp+34h] [ebp-C0h]
  _DWORD v17[43]; // [esp+38h] [ebp-BCh] BYREF
  int v18; // [esp+E4h] [ebp-10h]
  int v19; // [esp+E8h] [ebp-Ch]
  void *v20; // [esp+ECh] [ebp-8h]
  int v21; // [esp+F0h] [ebp-4h] BYREF
  void *retaddr; // [esp+F4h] [ebp+0h]

  v19 = a2;
  v20 = retaddr;
  v18 = -1;
  v17[42] = &loc_AD967B;
  v17[41] = NtCurrentTeb()->NtTib.ExceptionList;
  v17[40] = &v21;
  v6 = a3;
  v7 = a4;
  result = *(_DWORD *)(a1 + 12);
  if ( result )
  {
    if ( *(_BYTE *)(a1 + 16) )
    {
      v6 = a4;
      v7 = a3;
    }
    v14 = v6;
    v9 = v6[51];
    v16 = v7;
    v10 = v7[51];
    *(_DWORD *)(a6 + 4) = result;
    v13 = sub_9A43D0(*(_DWORD *)(a1 + 12));
    sub_9ACC90(v9, v10, LODWORD(v13));
    v18 = 0;
    v17[0] = v14[4];
    v17[1] = v14[5];
    v17[2] = v14[6];
    v17[3] = v14[7];
    v17[4] = v14[8];
    v17[5] = v14[9];
    v17[6] = v14[10];
    v17[7] = v14[11];
    v17[8] = v14[12];
    v17[9] = v14[13];
    v17[10] = v14[14];
    v17[11] = v14[15];
    v17[12] = v14[16];
    v17[13] = v14[17];
    v17[14] = v14[18];
    v17[15] = v14[19];
    v17[16] = v16[4];
    v17[17] = v16[5];
    v17[18] = v16[6];
    v17[19] = v16[7];
    v17[20] = v16[8];
    v17[21] = v16[9];
    v17[22] = v16[10];
    v17[23] = v16[11];
    v17[24] = v16[12];
    v17[25] = v16[13];
    v17[26] = v16[14];
    v17[27] = v16[15];
    v11 = v16[16];
    v17[33] = 0;
    v17[32] = 1566444395;
    v17[28] = v11;
    v17[29] = v16[17];
    v17[30] = v16[18];
    v17[31] = v16[19];
    result = sub_9AD400(v17, a6, *(_DWORD *)(a5 + 20), *(unsigned __int8 *)(a1 + 16));
    if ( *(_BYTE *)(a1 + 8) )
    {
      v12 = *(_DWORD *)(a6 + 4);
      if ( *(_DWORD *)(v12 + 1176) )
      {
        if ( *(_DWORD *)(v12 + 1168) == *(_DWORD *)(a6 + 144) )
          return sub_9A4470(a6 + 16, a6 + 80);
        else
          return sub_9A4470(a6 + 80, a6 + 16);
      }
    }
  }
  return result;
}
