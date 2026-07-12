// Function: sub_99DF20
// Address: 0x99df20
int __userpurge sub_99DF20@<eax>(int a1@<ecx>, int a2@<ebp>, int a3, int a4, int a5, float *a6)
{
  float v6; // ecx
  int result; // eax
  int v8; // edi
  int v9; // esi
  double v10; // st7
  double v11; // st6
  float v12; // eax
  int v13; // ecx
  float v14; // [esp+14h] [ebp-5Ch]
  float v15; // [esp+14h] [ebp-5Ch]
  float v16; // [esp+18h] [ebp-58h]
  float v17; // [esp+18h] [ebp-58h]
  float v18; // [esp+1Ch] [ebp-54h]
  float v19; // [esp+1Ch] [ebp-54h]
  float v20; // [esp+24h] [ebp-4Ch] BYREF
  float v21; // [esp+28h] [ebp-48h]
  float v22; // [esp+2Ch] [ebp-44h]
  int v23; // [esp+30h] [ebp-40h]
  float v24; // [esp+34h] [ebp-3Ch] BYREF
  float v25; // [esp+38h] [ebp-38h]
  float v26; // [esp+3Ch] [ebp-34h]
  int v27; // [esp+40h] [ebp-30h]
  float v28; // [esp+48h] [ebp-28h]
  float v29; // [esp+4Ch] [ebp-24h]
  float v30; // [esp+50h] [ebp-20h]
  float v31; // [esp+54h] [ebp-1Ch]
  float v32; // [esp+58h] [ebp-18h]
  float v33; // [esp+5Ch] [ebp-14h]
  float v34; // [esp+60h] [ebp-10h]
  int v35; // [esp+64h] [ebp-Ch]
  void *v36; // [esp+68h] [ebp-8h]
  void *retaddr; // [esp+70h] [ebp+0h]

  v35 = a2;
  v36 = retaddr;
  v6 = *(float *)(a1 + 12);
  v28 = v6;
  if ( v6 != 0.0 )
  {
    a6[1] = v6;
    result = a4;
    v8 = *(_DWORD *)(a4 + 204);
    v33 = *(float *)(a4 + 64);
    v9 = *(_DWORD *)(a3 + 204);
    v20 = *(float *)(a3 + 64) - v33;
    v32 = *(float *)(a4 + 68);
    v21 = *(float *)(a3 + 68) - v32;
    v31 = *(float *)(a4 + 72);
    v22 = *(float *)(a3 + 72) - v31;
    v34 = v20 * v20 + v21 * v21 + v22 * v22;
    v34 = sqrt(v34);
    v29 = *(float *)(v9 + 32) * *(float *)(v9 + 16);
    v30 = *(float *)(v8 + 32) * *(float *)(v8 + 16);
    v10 = v30;
    v11 = v30 + v29;
    if ( v34 <= v11 )
    {
      v29 = v34 - v11;
      v24 = 1.0;
      v25 = 0.0;
      v26 = 0.0;
      v27 = 0;
      if ( v34 > 0.00000011920929 )
      {
        v28 = 1.0 / v34;
        v14 = v28 * v20;
        v24 = v14;
        v16 = v28 * v21;
        v25 = v16;
        v18 = v28 * v22;
        v26 = v18;
        v27 = 0;
      }
      v12 = *a6;
      v15 = v24 * v10;
      v23 = 0;
      v17 = v25 * v10;
      v19 = v10 * v26;
      v20 = v33 + v15;
      v21 = v32 + v17;
      v22 = v31 + v19;
      result = (*(int (__thiscall **)(float *, float *, float *, float))(LODWORD(v12) + 12))(
                 a6,
                 &v24,
                 &v20,
                 COERCE_FLOAT(LODWORD(v29)));
      v13 = *((_DWORD *)a6 + 1);
      if ( *(_DWORD *)(v13 + 1176) )
      {
        if ( *(_DWORD *)(v13 + 1168) == *((_DWORD *)a6 + 36) )
          return sub_9A4470(a6 + 4, a6 + 20);
        else
          return sub_9A4470(a6 + 20, a6 + 4);
      }
    }
    else if ( *(_DWORD *)(LODWORD(v28) + 1176) )
    {
      if ( *(_DWORD *)(LODWORD(v28) + 1168) == *((_DWORD *)a6 + 36) )
        return sub_9A4470(a6 + 4, a6 + 20);
      else
        return sub_9A4470(a6 + 20, a6 + 4);
    }
  }
  return result;
}
