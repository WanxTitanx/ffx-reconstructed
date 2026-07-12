// Function: sub_99E620
// Address: 0x99e620
char __userpurge sub_99E620@<al>(
        int a1@<ebp>,
        int a2,
        int a3,
        int a4,
        float *a5,
        float *a6,
        _DWORD *a7,
        _DWORD *a8,
        _DWORD *a9,
        int a10,
        int a11)
{
  double v11; // st7
  double v12; // st7
  _DWORD *v13; // ecx
  _DWORD *v15; // ecx
  float v16[7]; // [esp-90h] [ebp-9Ch] BYREF
  float *v17; // [esp-74h] [ebp-80h]
  float *v18; // [esp-70h] [ebp-7Ch]
  int v19; // [esp-6Ch] [ebp-78h]
  _DWORD *v20; // [esp-68h] [ebp-74h]
  int v21; // [esp-64h] [ebp-70h]
  _BYTE v22[16]; // [esp-60h] [ebp-6Ch] BYREF
  int v23; // [esp-50h] [ebp-5Ch]
  int v24; // [esp-4Ch] [ebp-58h]
  int v25; // [esp-48h] [ebp-54h]
  int v26; // [esp-44h] [ebp-50h]
  int v27; // [esp-40h] [ebp-4Ch]
  int v28; // [esp-3Ch] [ebp-48h]
  int v29; // [esp-38h] [ebp-44h]
  int v30; // [esp-34h] [ebp-40h]
  int v31; // [esp-30h] [ebp-3Ch]
  int v32; // [esp-2Ch] [ebp-38h]
  int v33; // [esp-28h] [ebp-34h]
  int v34; // [esp-24h] [ebp-30h]
  int v35; // [esp+0h] [ebp-Ch]
  void *v36; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v35 = a1;
  v36 = retaddr;
  v11 = a5[12] - a6[12];
  v21 = a3;
  v16[0] = v11;
  v12 = a5[13] - a6[13];
  v19 = a4;
  v20 = a9;
  v16[1] = v12;
  v16[2] = a5[14] - a6[14];
  v17 = a5;
  v18 = a6;
  v16[3] = 0.0;
  if ( (unsigned __int8)sub_9B01C0(a3, a5, a4, a6, v16, v22, 1) )
  {
    v13 = v20;
    *a8 = v23;
    a8[1] = v24;
    a8[2] = v25;
    a8[3] = v26;
    *v13 = v27;
    v13[1] = v28;
    v13[2] = v29;
    v13[3] = v30;
    *a7 = v31;
    a7[1] = v32;
    a7[2] = v33;
    a7[3] = v34;
    return 1;
  }
  else
  {
    if ( (unsigned __int8)sub_9AE090(v21, v17, v19, v18, v16, v22) )
    {
      v15 = v20;
      *a8 = v23;
      a8[1] = v24;
      a8[2] = v25;
      a8[3] = v26;
      *v15 = v27;
      v15[1] = v28;
      v15[2] = v29;
      v15[3] = v30;
      *a7 = v31;
      a7[1] = v32;
      a7[2] = v33;
      a7[3] = v34;
    }
    return 0;
  }
}
