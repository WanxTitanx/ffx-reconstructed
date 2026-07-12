// Function: sub_9A2570
// Address: 0x9a2570
int __userpurge sub_9A2570@<eax>(
        int a1@<ebp>,
        int a2,
        float *a3,
        int a4,
        float *a5,
        _DWORD *a6,
        float a7,
        float *a8,
        float *a9,
        _DWORD *a10)
{
  int result; // eax
  int n126_3; // esi
  float v12; // eax
  float v13; // edx
  int n128_1; // ecx
  double v15; // st7
  int n128_2; // edi
  float *v17; // ecx
  double v18; // st6
  double v19; // st6
  double v20; // st6
  int v21; // ecx
  double v22; // st5
  unsigned int v23; // ecx
  double v24; // st6
  double v25; // st5
  float v26; // xmm1_4
  double v27; // st6
  double v28; // st5
  double v29; // rtt
  unsigned int v30; // ecx
  double v31; // st3
  double v32; // st4
  float *v33; // ecx
  int n126_1; // esi
  float v35; // eax
  float v36; // ecx
  int v37; // esi
  int n128_4; // edx
  _DWORD *v39; // eax
  int v40; // ecx
  int n126_2; // eax
  float v42; // [esp-1Ch] [ebp-9Ch]
  float v43; // [esp-18h] [ebp-98h]
  _DWORD v44[2]; // [esp-14h] [ebp-94h]
  float v45; // [esp-Ch] [ebp-8Ch]
  float v46; // [esp-8h] [ebp-88h]
  _DWORD v47[6]; // [esp-4h] [ebp-84h]
  int n128_3; // [esp+14h] [ebp-6Ch]
  int n128; // [esp+18h] [ebp-68h]
  float v50; // [esp+1Ch] [ebp-64h]
  char v51; // [esp+20h] [ebp-60h]
  float v52; // [esp+24h] [ebp-5Ch]
  float v53; // [esp+28h] [ebp-58h]
  float v54; // [esp+2Ch] [ebp-54h]
  int v55; // [esp+30h] [ebp-50h]
  float v56; // [esp+34h] [ebp-4Ch]
  float v57; // [esp+38h] [ebp-48h]
  float v58; // [esp+3Ch] [ebp-44h]
  int v59; // [esp+40h] [ebp-40h]
  int n126_4; // [esp+44h] [ebp-3Ch]
  int n126; // [esp+48h] [ebp-38h]
  float v62; // [esp+4Ch] [ebp-34h]
  float v63; // [esp+50h] [ebp-30h]
  float *v64; // [esp+54h] [ebp-2Ch]
  float v65; // [esp+58h] [ebp-28h]
  float v66; // [esp+5Ch] [ebp-24h]
  float v67; // [esp+60h] [ebp-20h]
  int *v68; // [esp+64h] [ebp-1Ch]
  _DWORD v69[2]; // [esp+68h] [ebp-18h] BYREF
  int v70; // [esp+70h] [ebp-10h]
  int v71; // [esp+74h] [ebp-Ch]
  void *v72; // [esp+78h] [ebp-8h]
  int v73; // [esp+7Ch] [ebp-4h] BYREF
  void *retaddr; // [esp+80h] [ebp+0h]

  v71 = a1;
  v72 = retaddr;
  v70 = -1;
  v69[1] = &loc_AD9968;
  v69[0] = NtCurrentTeb()->NtTib.ExceptionList;
  v68 = &v73;
  result = (int)v69;
  if ( a2 )
  {
    n126_3 = 1;
    n126 = 126;
    n128_3 = 0;
    v70 = 0;
    v12 = COERCE_FLOAT(sub_9D4CE0(512, 16));
    v13 = v12;
    v65 = v12;
    v51 = 1;
    v50 = v12;
    n128 = 128;
    n128_1 = 128;
    do
    {
      if ( v12 != 0.0 )
        *(_DWORD *)LODWORD(v12) = 0;
      LODWORD(v12) += 4;
      --n128_1;
    }
    while ( n128_1 );
    v15 = a7;
    n128_2 = 128;
    n128_3 = 128;
    *(_DWORD *)LODWORD(v13) = a2;
    v59 = 0;
    v55 = 0;
    do
    {
      v17 = *(float **)(LODWORD(v13) + 4 * n126_3-- - 4);
      v18 = v17[2] - a9[2];
      v64 = v17;
      n126_4 = n126_3;
      v63 = v18;
      v62 = v17[1] - a9[1];
      v56 = *v17 - *a9;
      v42 = v56;
      v57 = v62;
      v43 = v62;
      v58 = v63;
      v19 = v17[6];
      *(float *)v44 = v63;
      v44[1] = v59;
      v63 = v19 - a8[2];
      v62 = v17[5] - a8[1];
      v20 = v17[4];
      v21 = 16 * *a6;
      v52 = v20 - *a8;
      v45 = v52;
      v53 = v62;
      v46 = v62;
      v54 = v63;
      *(float *)v47 = v63;
      v47[1] = v55;
      v62 = *a3;
      v63 = *a5;
      v67 = (*(float *)((char *)&v42 + v21) - v62) * v63;
      v22 = *(float *)((char *)&v45 - v21) - v62;
      v23 = 16 * a6[1];
      v66 = v63 * v22;
      v62 = a3[1];
      v63 = a5[1];
      v24 = v63;
      v63 = (*(float *)&v44[v23 / 4 - 1] - v62) * v63;
      v62 = v24 * (*(float *)&v47[v23 / 0xFFFFFFFC - 1] - v62);
      v25 = v67;
      if ( v67 > (double)v62 || v63 > (double)v66 )
        goto LABEL_23;
      if ( v63 > v25 )
      {
        v67 = v63;
        v25 = v63;
      }
      if ( v66 <= (double)v62 )
      {
        v26 = v66;
        v29 = v25;
        v28 = v66;
        v27 = v29;
      }
      else
      {
        v26 = v62;
        v27 = v25;
        v66 = v62;
        v28 = v62;
      }
      v30 = 16 * a6[2];
      v62 = a3[2];
      v63 = a5[2];
      v31 = v62;
      v62 = (*(float *)&v44[v30 / 4] - v62) * v63;
      v63 = v63 * (*(float *)&v47[v30 / 0xFFFFFFFC] - v31);
      v32 = v27;
      if ( v27 > v63 || v62 > v28 )
        goto LABEL_23;
      if ( v62 > v27 )
      {
        v67 = v62;
        v32 = v62;
      }
      if ( v28 > v63 )
        v26 = v63;
      if ( v15 <= v32 || v26 <= 0.0 )
LABEL_23:
        LOBYTE(result) = 0;
      else
        LOBYTE(result) = 1;
      result = (unsigned __int8)result;
      if ( (_BYTE)result )
      {
        v33 = v64;
        if ( *((_DWORD *)v64 + 10) )
        {
          if ( n126_3 > n126 )
          {
            n126_1 = 2 * n128_2;
            n126 = 2 * n128_2;
            if ( 2 * n128_2 > n128_2 )
            {
              if ( n128 < n126_1 )
              {
                if ( n126_1 )
                {
                  v35 = COERCE_FLOAT(sub_9D4CE0(8 * n128_2, 16));
                  v13 = v65;
                }
                else
                {
                  v35 = 0.0;
                }
                v62 = v35;
                if ( n128_2 > 0 )
                {
                  v36 = v35;
                  v37 = LODWORD(v13) - LODWORD(v35);
                  n128_4 = n128_2;
                  do
                  {
                    if ( v36 != 0.0 )
                      *(_DWORD *)LODWORD(v36) = *(_DWORD *)(v37 + LODWORD(v36));
                    LODWORD(v36) += 4;
                    --n128_4;
                  }
                  while ( n128_4 );
                  n126_1 = n126;
                }
                if ( v65 != 0.0 )
                  sub_9D4D50(LODWORD(v65));
                v13 = v62;
                v51 = 1;
                v65 = v62;
                v50 = v62;
                n128 = n126_1;
              }
              if ( n128_2 < n126_1 )
              {
                v39 = (_DWORD *)(LODWORD(v13) + 4 * n128_2);
                v40 = n126_1 - n128_2;
                do
                {
                  if ( v39 )
                    *v39 = 0;
                  ++v39;
                  --v40;
                }
                while ( v40 );
              }
            }
            v33 = v64;
            n128_2 = n126_1;
            n126_2 = n126_1 - 2;
            n126_3 = n126_4;
            n128_3 = n128_2;
            n126 = n126_2;
          }
          *(float *)(LODWORD(v13) + 4 * n126_3) = v33[9];
          result = *((_DWORD *)v33 + 10);
          *(_DWORD *)(LODWORD(v13) + 4 * n126_3 + 4) = result;
          n126_3 += 2;
        }
        else
        {
          result = (*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)*a10 + 4))(*a10, *((_DWORD *)v64 + 9));
          v13 = v65;
        }
      }
      v15 = a7;
    }
    while ( n126_3 );
    v70 = -1;
    if ( v13 != 0.0 )
      return sub_9D4D50(LODWORD(v13));
  }
  return result;
}
