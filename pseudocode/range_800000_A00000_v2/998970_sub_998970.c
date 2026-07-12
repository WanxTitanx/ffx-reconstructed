// Function: sub_998970
// Address: 0x998970
char __userpurge sub_998970@<al>(float *a1@<ecx>, int a2@<ebp>, float *a3, float a4)
{
  double v5; // st7
  int v6; // esi
  double v7; // st7
  float v9[4]; // [esp-60h] [ebp-6Ch] BYREF
  float v10; // [esp-50h] [ebp-5Ch]
  float v11; // [esp-4Ch] [ebp-58h]
  float v12; // [esp-48h] [ebp-54h]
  float v13; // [esp-40h] [ebp-4Ch] BYREF
  float v14; // [esp-3Ch] [ebp-48h]
  float v15; // [esp-38h] [ebp-44h]
  float v16; // [esp-30h] [ebp-3Ch] BYREF
  float v17; // [esp-2Ch] [ebp-38h]
  float v18; // [esp-28h] [ebp-34h]
  float v19; // [esp-20h] [ebp-2Ch]
  float v20; // [esp-1Ch] [ebp-28h]
  float v21; // [esp-18h] [ebp-24h]
  float v22; // [esp-8h] [ebp-14h]
  float v23; // [esp-4h] [ebp-10h]
  int v24; // [esp+0h] [ebp-Ch]
  void *v25; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v24 = a2;
  v25 = retaddr;
  sub_997B00(a1, (int)&v16);
  v23 = a3[2] * v18 + a3[1] * v17 + *a3 * v16;
  v5 = v23;
  v23 = v16 * a1[16] + v17 * a1[17] + v18 * a1[18];
  v22 = v5 - v23;
  v23 = -a4;
  if ( v22 >= (double)v23 && a4 >= (double)v22 )
  {
    v6 = 0;
    while ( 1 )
    {
      (*(void (__thiscall **)(float *, int, float *, float *))(*(_DWORD *)a1 + 88))(a1, v6, &v13, v9);
      v10 = v9[0] - v13;
      v11 = v9[1] - v14;
      v12 = v9[2] - v15;
      v19 = v11 * v18 - v12 * v17;
      v20 = v12 * v16 - v18 * v10;
      v21 = v17 * v10 - v11 * v16;
      v22 = v19 * v19 + v20 * v20 + v21 * v21;
      v22 = sqrt(v22);
      v22 = 1.0 / v22;
      v19 = v19 * v22;
      v20 = v20 * v22;
      v21 = v22 * v21;
      v22 = *a3 * v19 + v20 * a3[1] + v21 * a3[2];
      v7 = v22;
      v22 = v21 * v15 + v19 * v13 + v20 * v14;
      v22 = v7 - v22;
      if ( v23 > (double)v22 )
        break;
      if ( ++v6 >= 3 )
        return 1;
    }
  }
  return 0;
}
