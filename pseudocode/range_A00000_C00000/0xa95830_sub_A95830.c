// Function: sub_A95830
// Address: 0xa95830
// Size: 0x152
// Prototype: 

int __usercall sub_A95830@<eax>(int a1@<edx>, int *a2@<ecx>, int a3@<xmm3>, int a4, float a5)
{
  int v6; // esi
  void *v7; // esp
  float v8; // xmm1_4
  int v9; // eax
  int v10; // eax
  int n4_1; // ecx
  int v12; // ebx
  signed int n4_2; // edx
  int v14; // esi
  unsigned int v15; // ebx
  int n8; // edx
  int v17; // ecx
  float v18; // xmm0_4
  int v19; // ecx
  _DWORD v21[3]; // [esp+4h] [ebp-28h] BYREF
  int v22; // [esp+10h] [ebp-1Ch]
  _DWORD *v23; // [esp+14h] [ebp-18h]
  int v24; // [esp+18h] [ebp-14h]
  unsigned int n4_3; // [esp+1Ch] [ebp-10h]
  int v26; // [esp+20h] [ebp-Ch]
  int v27; // [esp+24h] [ebp-8h]
  int n4; // [esp+28h] [ebp-4h]

  v24 = a3;
  v6 = a2[10];
  n4 = *a2;
  v22 = a1;
  v7 = alloca(4 * v6);
  v8 = *(float *)(a2[1] + 4) + a5;
  v9 = 0;
  v23 = v21;
  if ( v6 > 0 )
  {
    do
      v21[v9++] = -971228160;
    while ( v9 < a2[10] );
  }
  v10 = a2[1];
  if ( *(float *)(v10 + 8) > v8 )
    v8 = *(float *)(v10 + 8);
  n4_1 = n4;
  v12 = a4;
  n4_2 = 0;
  if ( n4 >= 4 )
  {
    v26 = 4 - a4;
    v27 = -8 - a4;
    v14 = a4 + 8;
    n4_3 = 4 * (((unsigned int)(n4 - 4) >> 2) + 1);
    v15 = ((unsigned int)(n4 - 4) >> 2) + 1;
    n8 = 8;
    do
    {
      v17 = v14 + v27;
      n8 += 16;
      *(float *)(v14 - 8) = *(float *)(v14 + v27 + a2[4]) + v8;
      v18 = *(float *)(v17 + a2[4] + 4);
      v19 = v14 + v26;
      v14 += 16;
      *(float *)(v14 - 20) = v18 + v8;
      *(float *)(v14 - 16) = *(float *)(n8 + a2[4] - 16) + v8;
      *(float *)(v14 - 12) = *(float *)(v19 + a2[4]) + v8;
      --v15;
    }
    while ( v15 );
    n4_2 = n4_3;
    v12 = a4;
    n4_1 = n4;
  }
  for ( ; n4_2 < n4_1; *(float *)(v12 + 4 * n4_2 - 4) = *(float *)(a2[4] + 4 * n4_2 - 4) + v8 )
    ++n4_2;
  sub_A965D0(v22, v12, v23, v24);
  return sub_A96330(v12);
}

