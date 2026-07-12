// Function: sub_98C950
// Address: 0x98c950
int __userpurge sub_98C950@<eax>(int a1@<ecx>, int a2@<ebp>, int a3, int a4)
{
  int v4; // edx
  int v5; // edi
  float *v6; // esi
  float *v7; // eax
  double v8; // st7
  float *v9; // esi
  float *v10; // eax
  int v12; // [esp-E0h] [ebp-ECh] BYREF
  int v13; // [esp-D0h] [ebp-DCh] BYREF
  int v14; // [esp-C0h] [ebp-CCh] BYREF
  int v15; // [esp-B0h] [ebp-BCh] BYREF
  float v16; // [esp-A0h] [ebp-ACh]
  float v17; // [esp-9Ch] [ebp-A8h]
  float v18; // [esp-98h] [ebp-A4h]
  float v19; // [esp-90h] [ebp-9Ch]
  float v20; // [esp-8Ch] [ebp-98h]
  float v21; // [esp-88h] [ebp-94h]
  float v22; // [esp-80h] [ebp-8Ch]
  float v23; // [esp-7Ch] [ebp-88h]
  float v24; // [esp-78h] [ebp-84h]
  float v25; // [esp-70h] [ebp-7Ch]
  float v26; // [esp-6Ch] [ebp-78h]
  float v27; // [esp-68h] [ebp-74h]
  float v28; // [esp-60h] [ebp-6Ch]
  float v29; // [esp-5Ch] [ebp-68h]
  float v30; // [esp-58h] [ebp-64h]
  float v31; // [esp-50h] [ebp-5Ch]
  float v32; // [esp-4Ch] [ebp-58h]
  float v33; // [esp-48h] [ebp-54h]
  float v34; // [esp-34h] [ebp-40h]
  float v35; // [esp-30h] [ebp-3Ch]
  float v36; // [esp-2Ch] [ebp-38h]
  float v37; // [esp-28h] [ebp-34h]
  float v38; // [esp-20h] [ebp-2Ch]
  float v39; // [esp-1Ch] [ebp-28h]
  float v40; // [esp-18h] [ebp-24h]
  int v41; // [esp-8h] [ebp-14h]
  int v42; // [esp-4h] [ebp-10h]
  int v43; // [esp+0h] [ebp-Ch]
  void *v44; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v43 = a2;
  v44 = retaddr;
  v4 = a3;
  v41 = a1;
  v35 = 0.0;
  v36 = 0.0;
  v37 = 0.0;
  v38 = 0.0;
  v39 = 0.0;
  v40 = 0.0;
  v42 = a4 - a3;
  v5 = a3;
  if ( a3 < a4 )
  {
    do
    {
      v6 = (float *)sub_98E1E0(&v15, v5);
      v7 = (float *)sub_98E120(&v13, v5++);
      v16 = *v7 + *v6;
      v17 = v7[1] + v6[1];
      v18 = v7[2] + v6[2];
      v25 = v16 * 0.5;
      v26 = v17 * 0.5;
      v27 = 0.5 * v18;
      v35 = v25 + v35;
      v36 = v26 + v36;
      v37 = v27 + v37;
    }
    while ( v5 < a4 );
    v4 = a3;
  }
  *(float *)&v42 = (float)v42;
  v8 = 1.0;
  v34 = 1.0 / *(float *)&v42;
  v35 = v34 * v35;
  v36 = v34 * v36;
  v37 = v34 * v37;
  if ( v4 < a4 )
  {
    do
    {
      v9 = (float *)sub_98E1E0(&v14, v4);
      v10 = (float *)sub_98E120(&v12, a3);
      v4 = a3 + 1;
      a3 = v4;
      v31 = *v9 + *v10;
      v32 = v10[1] + v9[1];
      v33 = v10[2] + v9[2];
      v19 = v31 * 0.5;
      v20 = v32 * 0.5;
      v21 = 0.5 * v33;
      v22 = v19 - v35;
      v23 = v20 - v36;
      v24 = v21 - v37;
      v28 = v22 * v22;
      v29 = v23 * v23;
      v30 = v24 * v24;
      v38 = v28 + v38;
      v39 = v29 + v39;
      v40 = v30 + v40;
    }
    while ( v4 < a4 );
    v8 = 1.0;
  }
  v34 = v8 / (*(float *)&v42 - v8);
  v38 = v34 * v38;
  v39 = v34 * v39;
  v40 = v34 * v40;
  if ( v39 > (double)v38 )
  {
    if ( v40 <= (double)v39 )
      return 1;
    return 2;
  }
  if ( v40 > (double)v38 )
    return 2;
  return 0;
}
