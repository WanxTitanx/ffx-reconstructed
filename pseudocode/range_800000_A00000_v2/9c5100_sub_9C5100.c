// Function: sub_9C5100
// Address: 0x9c5100
// bad sp value at call has been detected, the output may be wrong!
void __userpurge sub_9C5100(int a1@<ecx>, int a2@<ebp>, int a3, int a4, float a5)
{
  int v6; // eax
  float v7; // ecx
  float v8; // [esp-30h] [ebp-3Ch] BYREF
  float v9; // [esp-2Ch] [ebp-38h]
  float v10; // [esp-28h] [ebp-34h]
  int v11; // [esp-24h] [ebp-30h]
  float v12; // [esp-20h] [ebp-2Ch] BYREF
  float v13; // [esp-1Ch] [ebp-28h]
  float v14; // [esp-18h] [ebp-24h]
  int v15; // [esp-14h] [ebp-20h]
  float v16; // [esp-8h] [ebp-14h]
  float v17; // [esp-4h] [ebp-10h]
  int v18; // [esp+0h] [ebp-Ch]
  void *v19; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v18 = a2;
  v19 = retaddr;
  v15 = 0;
  v12 = *(float *)(a1 + 128) - *(float *)(a1 + 96);
  v13 = *(float *)(a1 + 132) - *(float *)(a1 + 100);
  v14 = *(float *)(a1 + 136) - *(float *)(a1 + 104);
  v17 = v12 * v12 + v13 * v13 + v14 * v14;
  v17 = sqrt(v17);
  v16 = v17;
  if ( v17 > 0.00000011920929 )
  {
    v17 = 1.0 / v17;
    v12 = v17 * v12;
    v13 = v13 * v17;
    v14 = v17 * v14;
    sub_9C3310((int)&v8, &v12, (float *)LODWORD(v17));
    v17 = v8 * v8 + v9 * v9 + v10 * v10;
    v17 = sqrt(v17);
    v17 = 1.0 / v17;
    v8 = v8 * v17;
    v9 = v9 * v17;
    v10 = v17 * v10;
    v6 = sub_9C3630((int)&v12, &v8, (float *)LODWORD(v17));
    v8 = *(float *)v6;
    v9 = *(float *)(v6 + 4);
    v7 = *(float *)(v6 + 8);
    v11 = *(_DWORD *)(v6 + 12);
    *(_DWORD *)(a1 + 128) = *(_DWORD *)(a1 + 96);
    *(_DWORD *)(a1 + 132) = *(_DWORD *)(a1 + 100);
    *(_DWORD *)(a1 + 136) = *(_DWORD *)(a1 + 104);
    *(_DWORD *)(a1 + 140) = *(_DWORD *)(a1 + 108);
    v10 = v7;
    if ( a5 != 0.0 )
    {
      v16 = v16 * a5;
      v12 = v16 * v8;
      v13 = v16 * v9;
      v14 = v16 * v10;
      *(float *)(a1 + 128) = *(float *)(a1 + 128) + v12;
      *(float *)(a1 + 132) = *(float *)(a1 + 132) + v13;
      *(float *)(a1 + 136) = *(float *)(a1 + 136) + v14;
    }
  }
}
