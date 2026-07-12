// Function: sub_99D4A0
// Address: 0x99d4a0
void __userpurge sub_99D4A0(int a1@<ecx>, int a2@<ebp>, int a3, int a4, int a5, int a6)
{
  char v7; // dl
  int v8; // eax
  int v9; // eax
  float v10; // eax
  double v11; // st7
  double v12; // st7
  float v13; // eax
  int v14; // ecx
  float v15[4]; // [esp-A0h] [ebp-ACh] BYREF
  _BYTE v16[12]; // [esp-90h] [ebp-9Ch] BYREF
  int n1065353216; // [esp-84h] [ebp-90h]
  float v18; // [esp-80h] [ebp-8Ch]
  float v19; // [esp-7Ch] [ebp-88h]
  float v20; // [esp-78h] [ebp-84h]
  float v21; // [esp-70h] [ebp-7Ch] BYREF
  float v22; // [esp-6Ch] [ebp-78h]
  float v23; // [esp-68h] [ebp-74h]
  float v24; // [esp-54h] [ebp-60h] BYREF
  float v25; // [esp-50h] [ebp-5Ch]
  float v26; // [esp-4Ch] [ebp-58h]
  float v27; // [esp-48h] [ebp-54h]
  float v28; // [esp-44h] [ebp-50h]
  float v29; // [esp-40h] [ebp-4Ch] BYREF
  float v30; // [esp-3Ch] [ebp-48h]
  float v31; // [esp-38h] [ebp-44h]
  float v32; // [esp-34h] [ebp-40h]
  float *v33; // [esp-24h] [ebp-30h]
  float v34; // [esp-20h] [ebp-2Ch] BYREF
  float v35; // [esp-1Ch] [ebp-28h]
  float v36; // [esp-18h] [ebp-24h]
  float v37; // [esp-14h] [ebp-20h]
  float v38; // [esp-10h] [ebp-1Ch]
  float v39; // [esp-Ch] [ebp-18h] BYREF
  float v40; // [esp-8h] [ebp-14h]
  int v41; // [esp-4h] [ebp-10h]
  _DWORD v42[3]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v42[0] = a2;
  v42[1] = retaddr;
  if ( *(_DWORD *)(a1 + 12) )
  {
    v7 = *(_BYTE *)(a1 + 16);
    v8 = a3;
    if ( v7 )
      v8 = a4;
    v38 = *(float *)(v8 + 204);
    v9 = a4;
    if ( v7 )
      v9 = a3;
    v33 = (float *)(*(_DWORD *)(v9 + 204) + 48);
    memset(v16, 0, sizeof(v16));
    n1065353216 = 1065353216;
    sub_99C910(a1, (int)v42, a1, a6, (int)v16, a3, a4, a5, *(float *)&a6);
    if ( *(_DWORD *)(*(_DWORD *)(a6 + 4) + 1176) < *(_DWORD *)(a1 + 24) )
    {
      v40 = v33[2];
      *(float *)&v41 = fabs(v40);
      if ( *(float *)&v41 <= 0.70710677 )
      {
        v40 = v33[1];
        v39 = *v33;
        *(float *)&v41 = v39 * v39 + v40 * v40;
        *(float *)&v41 = sqrt(*(float *)&v41);
        v23 = 0.0;
        *(float *)&v41 = 1.0 / *(float *)&v41;
        v21 = -v40 * *(float *)&v41;
        v22 = *(float *)&v41 * v39;
      }
      else
      {
        v39 = v33[1];
        *(float *)&v41 = v39 * v39 + v40 * v40;
        *(float *)&v41 = sqrt(*(float *)&v41);
        v21 = 0.0;
        *(float *)&v41 = 1.0 / *(float *)&v41;
        v22 = -v40 * *(float *)&v41;
        v23 = *(float *)&v41 * v39;
      }
      v38 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(*(_DWORD *)LODWORD(v38) + 12))(LODWORD(v38));
      v39 = flt_C64838 / v38;
      if ( v39 > 0.3926990926265717 )
        v39 = 0.39269909;
      sub_997300(&v29, &v21, &v39);
      v10 = *(float *)(a1 + 20);
      v40 = 0.0;
      *(float *)&v41 = v10;
      if ( SLODWORD(v10) > 0 )
      {
        v11 = 6.283185482025146;
        do
        {
          v38 = (float)v41;
          v12 = v11 / v38;
          v38 = (float)SLODWORD(v40);
          v24 = v12 * v38;
          sub_997300(&v34, v33, &v24);
          v18 = -v34;
          v19 = -v35;
          v20 = -v36;
          v25 = v31 * v19 + v32 * v18 + v29 * v37 - v30 * v20;
          v26 = v30 * v37 + v32 * v19 + v29 * v20 - v31 * v18;
          v27 = v31 * v37 + v32 * v20 + v30 * v18 - v29 * v19;
          v28 = v32 * v37 - v18 * v29 - v19 * v30 - v20 * v31;
          v15[0] = v25 * v37 + v28 * v34 + v26 * v36 - v27 * v35;
          v15[1] = v26 * v37 + v28 * v35 + v27 * v34 - v25 * v36;
          v15[2] = v27 * v37 + v28 * v36 + v25 * v35 - v26 * v34;
          v15[3] = v37 * v28 - v25 * v34 - v26 * v35 - v27 * v36;
          sub_99C910(a1, (int)v42, a1, a6, (int)v15, a3, a4, a5, *(float *)&a6);
          v11 = 6.283185482025146;
          v13 = *(float *)(a1 + 20);
          ++LODWORD(v40);
          *(float *)&v41 = v13;
        }
        while ( SLODWORD(v40) < SLODWORD(v13) );
      }
    }
    if ( *(_BYTE *)(a1 + 8) )
    {
      if ( *(_DWORD *)(*(_DWORD *)(a1 + 12) + 1176) )
      {
        v14 = *(_DWORD *)(a6 + 4);
        if ( *(_DWORD *)(v14 + 1176) )
        {
          if ( *(_DWORD *)(v14 + 1168) == *(_DWORD *)(a6 + 144) )
            sub_9A4470(a6 + 16, a6 + 80);
          else
            sub_9A4470(a6 + 80, a6 + 16);
        }
      }
    }
  }
}
