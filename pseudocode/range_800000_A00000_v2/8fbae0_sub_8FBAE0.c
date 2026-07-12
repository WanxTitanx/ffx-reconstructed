// Function: sub_8FBAE0
// Address: 0x8fbae0
void __cdecl sub_8FBAE0(float *a1, __int16 *a2, float a3)
{
  char *Str_1; // eax
  int v4; // ecx
  float v5; // esi
  float v6; // edx
  float v7; // ecx
  float v8; // eax
  double v9; // st5
  double v10; // st5
  double v11; // st7
  __int16 v12; // [esp-8h] [ebp-C8h]
  char v13; // [esp-4h] [ebp-C4h]
  __int16 v14; // [esp+0h] [ebp-C0h]
  float v15; // [esp+18h] [ebp-A8h] BYREF
  char *Str; // [esp+1Ch] [ebp-A4h]
  float v17; // [esp+20h] [ebp-A0h] BYREF
  int v18; // [esp+24h] [ebp-9Ch] BYREF
  float v19; // [esp+28h] [ebp-98h] BYREF
  float v20; // [esp+2Ch] [ebp-94h] BYREF
  float v21[5]; // [esp+30h] [ebp-90h] BYREF
  float v22; // [esp+44h] [ebp-7Ch] BYREF
  float v23; // [esp+48h] [ebp-78h] BYREF
  float v24; // [esp+4Ch] [ebp-74h] BYREF
  float v25[25]; // [esp+50h] [ebp-70h] BYREF
  _DWORD v26[2]; // [esp+B4h] [ebp-Ch] BYREF

  v14 = a2[2];
  v13 = *((_BYTE *)a1 + 27);
  v12 = *a2;
  v26[0] = 0;
  v26[1] = 0;
  Str_1 = (char *)sub_8ACF00(v12, v13, v14, 1, v26);
  v4 = *a2;
  Str = Str_1;
  FFX_Menu2D_GetAtlasDimensions_structural(v4, &v15, &v17);
  LODWORD(v5) = *(unsigned __int8 *)a1;
  LODWORD(v6) = *((unsigned __int8 *)a1 + 1);
  LODWORD(v7) = *((unsigned __int8 *)a1 + 2);
  *(float *)&v18 = a1[1] + unk_18716A0;
  LODWORD(v8) = *((unsigned __int8 *)a1 + 3);
  v9 = a3 * *((float *)a2 + 6);
  v25[23] = 0.0;
  LODWORD(v25[21]) = 2000;
  v10 = v9 + a1[2];
  v21[1] = v5;
  v21[2] = v6;
  v21[3] = v7;
  v21[4] = v8;
  v19 = v10 + unk_18716A4;
  v20 = *((float *)a2 + 2) / v15;
  v21[0] = *((float *)a2 + 3) / v17;
  v22 = unk_18716A0 + *((float *)a2 + 7) * a3 * flt_C5D778 + a1[1];
  v23 = unk_18716A4 + a3 * (*((float *)a2 + 8) + *((float *)a2 + 6)) * flt_C5D77C + a1[2];
  v24 = *((float *)a2 + 4) / v15;
  v11 = *((float *)a2 + 5) / v17;
  v25[4] = v8;
  v25[1] = v5;
  v25[2] = v6;
  v25[3] = v7;
  v25[0] = v11;
  if ( sub_8E5A20((float *)&v18, &v19, &v22, &v23, &v20, v21, &v24, v25) )
    sub_640810((int)&v18, Str, 2.0, 2.0, a2[2]);
}
