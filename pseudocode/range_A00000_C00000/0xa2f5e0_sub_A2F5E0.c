// Function: sub_A2F5E0
// Address: 0xa2f5e0
// Size: 0x15d
// Prototype: _DWORD __cdecl(_BYTE *, _DWORD, _BYTE *, float *, int (__cdecl *sub_A2F780)(int))

_BYTE *__cdecl sub_A2F5E0(float *a1, int a2, _BYTE *a3, float *a4, int (__cdecl *sub_A2F780)(int))
{
  float *v5; // esi
  float *v6; // edi
  __int16 v7; // bx
  float *v8; // ecx
  float *v9; // eax
  _BYTE *v10; // edx
  int v11; // eax
  float *v12; // esi
  float *v13; // eax
  float *v14; // ecx
  float *v15; // eax
  bool v16; // zf
  int v18[4]; // [esp+4h] [ebp-24h] BYREF
  int v19[4]; // [esp+14h] [ebp-14h] BYREF
  float *v20; // [esp+24h] [ebp-4h]

  v5 = a4;
  *a4 = 0.0;
  if ( a2 )
  {
    v6 = a1;
    v20 = &a1[4 * a2 - 4];
    if ( ((double (__cdecl *)(float *))sub_A2F780)(v20) <= 0.0 )
    {
      v8 = (float *)&a3[16 * *(_DWORD *)a4];
      LOBYTE(v7) = 0;
      ++*(_DWORD *)a4;
      v9 = v20;
      *v8 = *v20;
      v8[1] = v9[1];
      v8[2] = v9[2];
      v8[3] = v9[3];
    }
    else
    {
      LOBYTE(v7) = 1;
    }
    while ( 1 )
    {
      HIBYTE(v7) = ((double (__cdecl *)(float *))sub_A2F780)(v6) > 0.0;
      if ( (_BYTE)v7 != HIBYTE(v7) )
        break;
      v10 = a3;
      if ( !(_BYTE)v7 )
        goto LABEL_11;
LABEL_14:
      v20 = v6;
      v6 += 4;
      v16 = a2-- == 1;
      LOBYTE(v7) = HIBYTE(v7);
      if ( v16 )
        return v10;
    }
    if ( !v7 )
      goto LABEL_13;
    v11 = *(_DWORD *)v5;
    v12 = (float *)&a3[16 * *(_DWORD *)v5];
    *(_DWORD *)a4 = v11 + 1;
    if ( !(_BYTE)v7 )
    {
      v15 = (float *)sub_A2F560(v18, v20, (int)v6, (double (__cdecl *)(int))sub_A2F780);
      *v12 = *v15;
      v12[1] = v15[1];
      v12[2] = v15[2];
      v12[3] = v15[3];
      v5 = a4;
LABEL_13:
      v10 = a3;
      goto LABEL_14;
    }
    v13 = (float *)sub_A2F560(v19, v6, (int)v20, (double (__cdecl *)(int))sub_A2F780);
    v10 = a3;
    *v12 = *v13;
    v12[1] = v13[1];
    v12[2] = v13[2];
    v12[3] = v13[3];
    v5 = a4;
LABEL_11:
    v14 = (float *)&v10[16 * (*(_DWORD *)v5)++];
    *v14 = *v6;
    v14[1] = v6[1];
    v14[2] = v6[2];
    v14[3] = v6[3];
    goto LABEL_14;
  }
  return a3;
}

