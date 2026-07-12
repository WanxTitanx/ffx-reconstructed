// Function: sub_9C5BA0
// Address: 0x9c5ba0
// bad sp value at call has been detected, the output may be wrong!
int __userpurge sub_9C5BA0@<eax>(int a1@<ecx>, int a2@<ebp>, int a3, float a4, float a5)
{
  float v5; // xmm0_4
  double v6; // st6
  double v7; // st6
  float v9; // [esp-50h] [ebp-5Ch] BYREF
  float v10; // [esp-4Ch] [ebp-58h]
  unsigned int v11; // [esp-48h] [ebp-54h]
  float v12; // [esp-40h] [ebp-4Ch] BYREF
  float v13; // [esp-3Ch] [ebp-48h]
  float v14; // [esp-38h] [ebp-44h]
  float v15; // [esp-34h] [ebp-40h]
  float v16; // [esp-24h] [ebp-30h]
  int v17; // [esp-20h] [ebp-2Ch] BYREF
  double v18; // [esp-18h] [ebp-24h]
  float v19; // [esp-Ch] [ebp-18h] BYREF
  float v20; // [esp-8h] [ebp-14h]
  float v21; // [esp-4h] [ebp-10h]
  int v22; // [esp+0h] [ebp-Ch]
  void *v23; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v22 = a2;
  v23 = retaddr;
  v19 = cos(a4);
  v21 = v19;
  v19 = sin(a4);
  v5 = *(float *)(a1 + 480);
  v20 = v19;
  v16 = v5;
  v19 = v5;
  *((float *)&v18 + 1) = fabs(v21);
  if ( *((float *)&v18 + 1) > 0.00000011920929 )
  {
    *((float *)&v18 + 1) = v20 * v20 / (v21 * v21);
    v6 = v16;
    v16 = 1.0 / (*(float *)(a1 + 484) * *(float *)(a1 + 484));
    v16 = v16 + *((float *)&v18 + 1) / (v6 * v6);
    v16 = (*((float *)&v18 + 1) + 1.0) / v16;
    v16 = sqrt(v16);
    v19 = v16;
  }
  sub_997300(&v12, &v9, &v19);
  v18 = v13 * 0.0;
  v9 = v15 * a5 + v18 - v14 * 0.0;
  v7 = 0.0 * v12;
  v10 = v14 * a5 + v15 * 0.0 - v7;
  *(float *)&v11 = v15 * 0.0 + v7 - v13 * a5;
  sub_9C5A60(&v17);
  *(float *)a3 = v9;
  *(float *)(a3 + 4) = v10;
  *(_QWORD *)(a3 + 8) = v11;
  return a3;
}
