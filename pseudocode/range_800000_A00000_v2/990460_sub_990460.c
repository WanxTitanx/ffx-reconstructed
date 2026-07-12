// Function: sub_990460
// Address: 0x990460
int __userpurge sub_990460@<eax>(int a1@<ecx>, int a2@<ebp>, int a3, int a4, int a5)
{
  int v5; // edx
  int v6; // esi
  int v7; // edi
  float *v8; // esi
  float *v9; // eax
  double v10; // st7
  int v11; // edi
  float *v12; // esi
  float *v13; // eax
  int v14; // esi
  int result; // eax
  int v16; // [esp-B0h] [ebp-BCh] BYREF
  int v17; // [esp-A0h] [ebp-ACh] BYREF
  int v18; // [esp-90h] [ebp-9Ch] BYREF
  int v19; // [esp-80h] [ebp-8Ch] BYREF
  float v20[4]; // [esp-70h] [ebp-7Ch]
  float v21; // [esp-60h] [ebp-6Ch]
  float v22; // [esp-5Ch] [ebp-68h]
  float v23; // [esp-58h] [ebp-64h]
  float v24; // [esp-50h] [ebp-5Ch]
  float v25; // [esp-4Ch] [ebp-58h]
  float v26; // [esp-48h] [ebp-54h]
  float v27; // [esp-40h] [ebp-4Ch]
  float v28; // [esp-3Ch] [ebp-48h]
  float v29; // [esp-38h] [ebp-44h]
  int v30; // [esp-28h] [ebp-34h]
  int v31; // [esp-24h] [ebp-30h]
  float v32; // [esp-20h] [ebp-2Ch]
  float v33; // [esp-1Ch] [ebp-28h]
  float v34; // [esp-18h] [ebp-24h]
  int v35; // [esp-14h] [ebp-20h]
  int v36; // [esp-8h] [ebp-14h]
  int v37; // [esp-4h] [ebp-10h]
  int v38; // [esp+0h] [ebp-Ch]
  void *v39; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v38 = a2;
  v39 = retaddr;
  v5 = a3;
  v6 = a4;
  v36 = a1;
  v31 = a3;
  v30 = a4 - a3;
  v32 = 0.0;
  v33 = 0.0;
  v34 = 0.0;
  v35 = 0;
  v7 = a3;
  if ( a3 < a4 )
  {
    do
    {
      v8 = (float *)sub_98E1E0(&v19, v7);
      v9 = (float *)sub_98E120(v36, (int)&v17, v7++);
      v21 = *v9 + *v8;
      v22 = v9[1] + v8[1];
      v10 = v9[2] + v8[2];
      v6 = a4;
      v23 = v10;
      v27 = v21 * 0.5;
      v28 = v22 * 0.5;
      v29 = 0.5 * v23;
      v32 = v27 + v32;
      v33 = v28 + v33;
      v34 = v29 + v34;
    }
    while ( v7 < a4 );
    v5 = a3;
  }
  v11 = v5;
  *(float *)&v37 = (float)v30;
  *(float *)&v37 = 1.0 / *(float *)&v37;
  v32 = *(float *)&v37 * v32;
  v33 = *(float *)&v37 * v33;
  v34 = *(float *)&v37 * v34;
  v37 = *((int *)&v32 + a5);
  if ( v5 < v6 )
  {
    v20[3] = 0.0;
    do
    {
      v12 = (float *)sub_98E1E0(&v18, v11);
      v13 = (float *)sub_98E120(v36, (int)&v16, v11);
      v24 = *v12 + *v13;
      v25 = v13[1] + v12[1];
      v26 = v13[2] + v12[2];
      v20[0] = v24 * 0.5;
      v20[1] = v25 * 0.5;
      v20[2] = 0.5 * v26;
      if ( v20[a5] > (double)*(float *)&v37 )
      {
        v14 = v31;
        sub_990640(v11, v31);
        v31 = v14 + 1;
      }
      v6 = a4;
      ++v11;
    }
    while ( v11 < a4 );
  }
  v37 = v30 / 3;
  result = v31;
  if ( v31 <= v30 / 3 + a3 || v31 >= v6 - v37 - 1 )
    return a3 + (v30 >> 1);
  return result;
}
