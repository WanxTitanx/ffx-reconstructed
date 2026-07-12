// Function: sub_A51560
// Address: 0xa51560
// Size: 0x196
// Prototype: 

int __usercall sub_A51560@<eax>(int a1@<ebp>, int n861)
{
  int n861_1; // edi
  int n861_2; // eax
  int v4; // edi
  int v5; // esi
  int v6; // eax
  _DWORD *v7; // ecx
  _WORD v8[2]; // [esp+14h] [ebp-10Ch] BYREF
  int v9; // [esp+18h] [ebp-108h]
  int v10; // [esp+1Ch] [ebp-104h]
  int v11; // [esp+20h] [ebp-100h]
  _BYTE *v12; // [esp+24h] [ebp-FCh]
  char v13; // [esp+2Ch] [ebp-F4h]
  _DWORD *v14; // [esp+30h] [ebp-F0h]
  _BYTE v15[64]; // [esp+4Ch] [ebp-D4h] BYREF
  _BYTE v16[64]; // [esp+8Ch] [ebp-94h] BYREF
  _DWORD v17[21]; // [esp+CCh] [ebp-54h] BYREF
  _UNKNOWN *retaddr; // [esp+120h] [ebp+0h]

  v17[18] = a1;
  v17[19] = retaddr;
  n861_1 = *(__int16 *)(dword_2305834[0] + 2);
  v12 = v15;
  v14 = v17;
  *(float *)&v17[3] = flt_C8F514[0];
  *(float *)&v17[7] = flt_C8F514[0];
  *(float *)&v17[11] = flt_C8F514[0];
  v8[1] = 20;
  n861_2 = n861;
  *(float *)&v17[14] = 16384.0;
  v10 = 0;
  *(float *)&v17[15] = 1.0;
  v11 = 0;
  v13 = 0;
  v17[0] = unk_C8F508[0];
  *(float *)&v17[1] = flt_C8F50C;
  *(float *)&v17[2] = flt_C8F510;
  v17[4] = unk_C8F508[0];
  *(float *)&v17[5] = flt_C8F50C;
  *(float *)&v17[6] = flt_C8F510;
  v17[8] = unk_C8F508[0];
  *(float *)&v17[9] = flt_C8F50C;
  *(float *)&v17[10] = flt_C8F510;
  v17[12] = unk_C8F508[0];
  *(float *)&v17[13] = flt_C8F50C;
  if ( n861 <= n861_1 )
  {
    v4 = dword_2305834[0];
    v5 = dword_2305834[0] + 8 * (5 * n861 + 257);
    sub_A5AD30((int)v16, v5, 1.0);
    sub_6ED700(v15, v4 + 70624, v16);
    v6 = 6 * *(unsigned __int16 *)(v5 + 6);
    if ( *(_BYTE *)(v5 + 33) )
    {
      v9 = -2142943931;
      v7 = *(_DWORD **)(v4 + 8 * v6 + 63528);
    }
    else
    {
      v9 = -2146299374;
      v7 = *(_DWORD **)(v4 + 8 * v6 + 63532);
    }
    return FFX_Menu2D_DrawQuadIndexedBatch(v7, (int)v8, n861);
  }
  return n861_2;
}

