// Function: sub_9C36F0
// Address: 0x9c36f0
// bad sp value at call has been detected, the output may be wrong!
int __userpurge sub_9C36F0@<eax>(int a1@<ecx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>, int a5, float a6)
{
  double v7; // st6
  int (__stdcall *v8)(int, int, int, int, _DWORD, _DWORD, _DWORD, int, int, int, _DWORD, _DWORD, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int); // eax
  char v9; // al
  _DWORD *v10; // ecx
  char v11; // al
  double v12; // st7
  double v13; // st6
  _DWORD *v14; // ecx
  double v15; // st7
  float *v16; // eax
  double v17; // st6
  float v18; // xmm0_4
  int v21; // [esp+Ch] [ebp-84h]
  int v22; // [esp+10h] [ebp-80h]
  float v23; // [esp+14h] [ebp-7Ch] BYREF
  float v24; // [esp+18h] [ebp-78h]
  float v25; // [esp+1Ch] [ebp-74h]
  int v26; // [esp+20h] [ebp-70h]
  int v27; // [esp+24h] [ebp-6Ch]
  int v28; // [esp+28h] [ebp-68h]
  float v29; // [esp+2Ch] [ebp-64h]
  float v30; // [esp+30h] [ebp-60h]
  int v31; // [esp+34h] [ebp-5Ch] BYREF
  int v32; // [esp+38h] [ebp-58h]
  int v33; // [esp+3Ch] [ebp-54h]
  int v34; // [esp+40h] [ebp-50h]
  int v35; // [esp+44h] [ebp-4Ch]
  int v36; // [esp+48h] [ebp-48h]
  int v37; // [esp+4Ch] [ebp-44h]
  int v38; // [esp+50h] [ebp-40h]
  int v39; // [esp+54h] [ebp-3Ch]
  int v40; // [esp+58h] [ebp-38h]
  int v41; // [esp+5Ch] [ebp-34h]
  int v42; // [esp+60h] [ebp-30h]
  int v43; // [esp+64h] [ebp-2Ch]
  int v44; // [esp+68h] [ebp-28h]
  int v45; // [esp+6Ch] [ebp-24h]
  int v46; // [esp+70h] [ebp-20h]
  int v47; // [esp+74h] [ebp-1Ch]
  int v48; // [esp+78h] [ebp-18h]
  int v49; // [esp+7Ch] [ebp-14h]
  int v50; // [esp+84h] [ebp-Ch]
  void *v51; // [esp+88h] [ebp-8h]
  void *retaddr; // [esp+90h] [ebp+0h]

  v50 = a2;
  v51 = retaddr;
  if ( *(_BYTE *)(a1 + 195) || *(float *)(a1 + 196) > 0.0 )
  {
    v11 = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)a1 + 44))(a1, a3, a4);
    v12 = *(float *)(a1 + 44);
    *(_BYTE *)(a1 + 192) = v11;
    v30 = *(float *)(a1 + 16) - v12 * a6;
    v13 = v30;
    *(float *)(a1 + 16) = v30;
    if ( v13 > 0.0 )
    {
      v30 = *(float *)(a1 + 28);
      if ( v13 > v30 )
        *(float *)(a1 + 16) = v30;
    }
    v29 = *(float *)(a1 + 16);
    if ( v29 < 0.0 )
    {
      v30 = fabs(*(float *)(a1 + 24));
      v29 = fabs(v29);
      if ( v29 > (double)v30 )
        *(float *)(a1 + 16) = -v30;
    }
    v14 = *(_DWORD **)(a1 + 8);
    v15 = a6 * *(float *)(a1 + 16);
    v49 = a5;
    *(float *)(a1 + 20) = v15;
    v31 = v14[4];
    v32 = v14[5];
    v33 = v14[6];
    v34 = v14[7];
    v35 = v14[8];
    v36 = v14[9];
    v37 = v14[10];
    v38 = v14[11];
    v39 = v14[12];
    v40 = v14[13];
    v41 = v14[14];
    v42 = v14[15];
    sub_9C4C60(v49);
    if ( *(_BYTE *)(a1 + 195) )
    {
      v16 = (float *)(a1 + 64);
    }
    else
    {
      v29 = *(float *)(a1 + 196);
      v17 = v29;
      if ( v29 <= (double)a6 )
        v18 = v29;
      else
        v18 = a6;
      v29 = v18;
      v26 = 0;
      v16 = &v23;
      *(float *)(a1 + 196) = v17 - a6;
      v23 = *(float *)(a1 + 64) * v29;
      v24 = *(float *)(a1 + 68) * v29;
      v25 = v29 * *(float *)(a1 + 72);
    }
    sub_9C4740(a5, v16);
    sub_9C4410(a5, LODWORD(a6));
  }
  else
  {
    v30 = *(float *)(a1 + 16) - *(float *)(a1 + 44) * a6;
    v7 = v30;
    *(float *)(a1 + 16) = v30;
    if ( v7 > 0.0 )
    {
      v30 = *(float *)(a1 + 28);
      if ( v7 > v30 )
        *(float *)(a1 + 16) = v30;
    }
    v29 = *(float *)(a1 + 16);
    if ( v29 < 0.0 )
    {
      v30 = fabs(*(float *)(a1 + 24));
      v29 = fabs(v29);
      if ( v29 > (double)v30 )
        *(float *)(a1 + 16) = -v30;
    }
    v8 = *(int (__stdcall **)(int, int, int, int, _DWORD, _DWORD, _DWORD, int, int, int, _DWORD, _DWORD, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int))(*(_DWORD *)a1 + 44);
    *(float *)(a1 + 20) = a6 * *(float *)(a1 + 16);
    v9 = v8(
           a3,
           a4,
           v21,
           v22,
           LODWORD(v23),
           LODWORD(v24),
           LODWORD(v25),
           v26,
           v27,
           v28,
           LODWORD(v29),
           LODWORD(v30),
           v31,
           v32,
           v33,
           v34,
           v35,
           v36,
           v37,
           v38,
           v39,
           v40,
           v41,
           v42,
           v43,
           v44,
           v45,
           v46,
           v47,
           v48,
           v49);
    v49 = a5;
    *(_BYTE *)(a1 + 192) = v9;
    sub_9C4C60(v49);
    sub_9C4410(a5, LODWORD(a6));
    v10 = *(_DWORD **)(a1 + 8);
    v31 = v10[4];
    v32 = v10[5];
    v33 = v10[6];
    v34 = v10[7];
    v35 = v10[8];
    v36 = v10[9];
    v37 = v10[10];
    v38 = v10[11];
    v39 = v10[12];
    v40 = v10[13];
    v41 = v10[14];
    v42 = v10[15];
  }
  return sub_6043A0(&v31);
}
