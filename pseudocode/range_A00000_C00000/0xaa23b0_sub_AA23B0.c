// Function: sub_AA23B0
// Address: 0xaa23b0
// Size: 0x170
// Prototype: int __cdecl(int, int, void *, int, int)

int __fastcall sub_AA23B0(int a1, int a2, int a3, int a4, _DWORD *a5, int a6, int a7)
{
  _DWORD *v7; // esi
  int v8; // edi
  int v10; // ecx
  int v11; // edx
  int v12; // eax
  float *v13; // edi
  int v14; // esi
  int n1023; // ecx
  float v16; // xmm0_4
  int v17; // eax
  int v19; // [esp+Ch] [ebp-34h]
  int v20; // [esp+10h] [ebp-30h]
  int v21; // [esp+14h] [ebp-2Ch]
  int v22; // [esp+18h] [ebp-28h]
  int v23; // [esp+1Ch] [ebp-24h]
  int v24; // [esp+20h] [ebp-20h]
  int v25; // [esp+24h] [ebp-1Ch]
  int v26; // [esp+28h] [ebp-18h]
  int v27; // [esp+2Ch] [ebp-14h]
  int v28; // [esp+30h] [ebp-10h]
  int v29; // [esp+34h] [ebp-Ch]
  int v30; // [esp+38h] [ebp-8h]
  int v32; // [esp+3Ch] [ebp-4h]

  v7 = a5;
  v8 = 0;
  v30 = 0;
  v29 = 0;
  v28 = 0;
  v27 = 0;
  v26 = 0;
  v25 = 0;
  v24 = 0;
  v23 = 0;
  v22 = 0;
  v21 = 0;
  v20 = 0;
  memset(a5, 0, 0x38u);
  v10 = a4;
  v11 = a3;
  *a5 = a3;
  a5[1] = a4;
  if ( a4 >= a6 )
  {
    v10 = a6 - 1;
    a4 = a6 - 1;
  }
  if ( a3 <= v10 )
  {
    v12 = a2 - a1;
    v13 = (float *)(a1 + 4 * a3);
    v32 = a2 - a1;
    v14 = 0;
    while ( 1 )
    {
      n1023 = (int)(float)((float)(*v13 * 7.3142858) + 1023.5);
      if ( n1023 > 1023 )
        break;
      if ( n1023 > 0 )
        goto LABEL_8;
LABEL_12:
      ++v11;
      ++v13;
      if ( v11 > a4 )
      {
        v19 = v14;
        v7 = a5;
        v8 = v19;
        goto LABEL_14;
      }
    }
    n1023 = 1023;
LABEL_8:
    v16 = *(float *)((char *)v13 + v12) + *(float *)(a7 + 1112);
    v17 = v11 * v11;
    if ( v16 < *v13 )
    {
      v23 += v17;
      v24 += n1023;
      v25 += v11;
      v22 += n1023 * n1023;
      v21 += v11 * n1023;
      ++v20;
    }
    else
    {
      v28 += v17;
      v29 += n1023;
      v30 += v11;
      v27 += n1023 * n1023;
      v26 += v11 * n1023;
      ++v14;
    }
    v12 = v32;
    goto LABEL_12;
  }
LABEL_14:
  v7[2] = v30;
  v7[3] = v29;
  v7[4] = v28;
  v7[5] = v27;
  v7[6] = v26;
  v7[8] = v25;
  v7[9] = v24;
  v7[10] = v23;
  v7[11] = v22;
  v7[12] = v21;
  v7[13] = v20;
  v7[7] = v8;
  return v8;
}

