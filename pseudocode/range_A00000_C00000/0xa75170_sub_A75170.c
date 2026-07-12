// Function: sub_A75170
// Address: 0xa75170
// Size: 0x277
// Prototype: 

int __cdecl sub_A75170(int a1, int a2, int a3, float *a4, int a5)
{
  float *v7; // edi
  double v8; // st7
  int v9; // esi
  int v10; // esi
  int v12; // [esp+Ch] [ebp-4h]
  float v13; // [esp+1Ch] [ebp+Ch]
  float v14; // [esp+1Ch] [ebp+Ch]
  float v15; // [esp+1Ch] [ebp+Ch]
  float v16; // [esp+20h] [ebp+10h]
  int v17; // [esp+24h] [ebp+14h]
  int n1856; // [esp+28h] [ebp+18h]

  *(_DWORD *)(a5 + 16) = 1;
  *(_DWORD *)(a5 + 20) = 1342177280;
  *(_DWORD *)(a5 + 24) = 978670;
  *(_DWORD *)(a5 + 28) = 0;
  *(_QWORD *)(a5 + 48) = *(unsigned __int8 *)(a2 + 203);
  *(_DWORD *)(a5 + 56) = 59;
  *(_DWORD *)(a5 + 60) = 0;
  *(_DWORD *)(a5 + 64) = 5;
  *(_DWORD *)(a5 + 68) = 0;
  *(_DWORD *)(a5 + 72) = 8;
  *(_DWORD *)(a5 + 76) = 0;
  *(_DWORD *)(a5 + 32) = 458765;
  *(_DWORD *)(a5 + 36) = 0;
  *(_DWORD *)(a5 + 40) = 71;
  *(_DWORD *)(a5 + 44) = 0;
  *(_DWORD *)(a5 + 96) = *(unsigned __int8 *)(a2 + 194);
  *(_DWORD *)(a5 + 100) = *(unsigned __int8 *)(a2 + 195);
  *(_DWORD *)(a5 + 104) = 66;
  *(_DWORD *)(a5 + 80) = 1688345088;
  *(_DWORD *)(a5 + 84) = 2;
  *(_DWORD *)(a5 + 88) = 6;
  *(_DWORD *)(a5 + 92) = 0;
  v13 = *a4;
  v7 = (float *)(a3 + 32);
  v16 = a4[1];
  v17 = (int)*(float *)(a2 + 72);
  v8 = v13;
  v12 = (int)*(float *)(a2 + 76);
  n1856 = 1856;
  v9 = a5 + 128;
  do
  {
    if ( !*(_WORD *)(a1 + 530) )
    {
      v14 = v7[19] + v7[18];
      v7[18] = v14;
      if ( v14 >= 1.0 )
        v7[18] = 1.0;
      v15 = v7[21] + v7[20];
      v7[20] = v15;
      if ( v15 >= 1.0 )
        v7[20] = 1.0;
    }
    *(float *)v9 = (v7[14] - v7[12]) * v7[18] + v7[12];
    *(float *)(v9 + 4) = (v7[15] - v7[13]) * v7[18] + v7[13];
    *(float *)(v9 + 8) = 1.0;
    *(_DWORD *)(v9 + 32) = 16 * (int)(*v7 + v8);
    *(_DWORD *)(v9 + 36) = 16 * (int)(v7[1] + v16);
    *(_DWORD *)(v9 + 28) = v17;
    *(_DWORD *)(v9 + 40) = &unk_FFFFFF;
    *(_DWORD *)(v9 + 44) = 0;
    *(_DWORD *)(v9 + 16) = 128;
    *(_DWORD *)(v9 + 20) = 128;
    *(_DWORD *)(v9 + 24) = 128;
    *(float *)(v9 + 48) = v7[14];
    *(float *)(v9 + 52) = v7[15];
    *(float *)(v9 + 56) = 1.0;
    *(_DWORD *)(v9 + 80) = 16 * (int)v7[4];
    *(_DWORD *)(v9 + 84) = 16 * (int)v7[5];
    *(_DWORD *)(v9 + 88) = &unk_FFFFFF;
    *(_DWORD *)(v9 + 92) = 0;
    *(_DWORD *)(v9 + 64) = 128;
    *(_DWORD *)(v9 + 68) = 128;
    *(_DWORD *)(v9 + 72) = 128;
    *(_DWORD *)(v9 + 76) = v12;
    v7 += 22;
    v9 += 96;
    --n1856;
  }
  while ( n1856 );
  v10 = ((v9 - a5) >> 4) + 1879048191;
  *(_DWORD *)a5 = v10;
  *(_QWORD *)(a5 + 112) = (((unsigned __int16)v10 - 7) / 6) | 0x602CC00000008000LL;
  *(_DWORD *)(a5 + 120) = 4269074;
  *(_DWORD *)(a5 + 124) = 0;
  sub_62FA30(0, 0);
  nullsub_33(0);
  nullsub_39(unk_23328E0, a5);
  return sub_62FA30(0, 0);
}

