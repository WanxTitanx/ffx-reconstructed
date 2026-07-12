// Function: sub_9D10C0
// Address: 0x9d10c0
void __usercall sub_9D10C0(int a1@<ecx>, int a2@<ebp>)
{
  int v3; // ecx
  int n16; // edi
  int v5; // xmm0_4
  int v6; // xmm0_4
  int v7; // xmm0_4
  int n3; // eax
  int *v9; // edi
  _DWORD v10[4]; // [esp-60h] [ebp-6Ch] BYREF
  _DWORD v11[4]; // [esp-50h] [ebp-5Ch] BYREF
  int v12; // [esp-40h] [ebp-4Ch]
  int v13; // [esp-3Ch] [ebp-48h]
  int v14; // [esp-38h] [ebp-44h]
  int v15; // [esp-34h] [ebp-40h]
  int v16; // [esp-30h] [ebp-3Ch]
  int v17; // [esp-2Ch] [ebp-38h]
  int v18; // [esp-28h] [ebp-34h]
  int v19; // [esp-24h] [ebp-30h]
  int v20; // [esp-20h] [ebp-2Ch] BYREF
  int v21; // [esp-1Ch] [ebp-28h]
  int v22; // [esp-18h] [ebp-24h]
  int v23; // [esp-14h] [ebp-20h]
  int n3_1; // [esp-8h] [ebp-14h]
  int v25; // [esp-4h] [ebp-10h]
  int v26; // [esp+0h] [ebp-Ch]
  void *v27; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v26 = a2;
  v27 = retaddr;
  if ( *(_BYTE *)(a1 + 1416) )
  {
    *(_DWORD *)(a1 + 784) = 0;
    *(_DWORD *)(a1 + 788) = 0;
    *(_DWORD *)(a1 + 792) = 0;
    *(_DWORD *)(a1 + 796) = 0;
    *(_DWORD *)(a1 + 1020) = 0;
    *(_DWORD *)(a1 + 1084) = 0;
    *(_DWORD *)(a1 + 1148) = 0;
    sub_9D1F90(*(_DWORD *)(a1 + 20) + 16, *(_DWORD *)(a1 + 24) + 16);
    (*(void (__thiscall **)(int))(*(_DWORD *)a1 + 40))(a1);
    v10[0] = *(_DWORD *)(a1 + 1392);
    v10[1] = *(_DWORD *)(a1 + 1396);
    v10[2] = *(_DWORD *)(a1 + 1400);
    v10[3] = *(_DWORD *)(a1 + 1404);
    v11[0] = *(_DWORD *)(a1 + 1392);
    v11[1] = *(_DWORD *)(a1 + 1396);
    v11[2] = *(_DWORD *)(a1 + 1400);
    v3 = a1 + 176;
    v11[3] = *(_DWORD *)(a1 + 1404);
    n16 = 16;
    v25 = a1 + 176;
    do
    {
      if ( *(float *)(a1 + n16 + 752) >= (double)*(float *)(a1 + n16 + 736) )
      {
        if ( *(_BYTE *)(a1 + 1408) )
        {
          v16 = *(_DWORD *)(n16 + a1 + 1152);
          v5 = *(_DWORD *)(n16 + a1 + 1168);
          v20 = v16;
          v17 = v5;
          v6 = *(_DWORD *)(n16 + a1 + 1184);
          v21 = v17;
          v18 = v6;
          v19 = 0;
        }
        else
        {
          v12 = *(_DWORD *)(n16 + a1 + 1216);
          v7 = *(_DWORD *)(n16 + a1 + 1232);
          v20 = v12;
          v13 = v7;
          v6 = *(_DWORD *)(n16 + a1 + 1248);
          v21 = v13;
          v14 = v6;
          v15 = 0;
        }
        v22 = v6;
        v23 = 0;
        sub_9D12E0(v3, &v20, v10, v11);
        v3 = v25;
      }
      n16 += 4;
      v3 += 96;
      v25 = v3;
    }
    while ( n16 < 28 );
    n3 = 0;
    n3_1 = 0;
    v25 = a1 + 464;
    v9 = (int *)(a1 + 1312);
    do
    {
      if ( (unsigned __int8)sub_9D4500(n3) )
      {
        v20 = *v9;
        v21 = v9[1];
        v22 = v9[2];
        v23 = v9[3];
        sub_9D0F70(v25, &v20);
      }
      v25 += 96;
      n3 = n3_1 + 1;
      v9 += 4;
      n3_1 = n3;
    }
    while ( n3 < 3 );
  }
}
