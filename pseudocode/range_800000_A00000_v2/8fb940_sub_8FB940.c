// Function: sub_8FB940
// Address: 0x8fb940
void __cdecl sub_8FB940(int *a1, __int16 *a2, float a3)
{
  char *Str_1; // eax
  int v4; // ecx
  float v5; // esi
  float v6; // edx
  float v7; // ecx
  float v8; // eax
  double v9; // st6
  double v10; // st5
  __int16 v11; // [esp-8h] [ebp-C8h]
  char v12; // [esp-4h] [ebp-C4h]
  __int16 v13; // [esp+0h] [ebp-C0h]
  float v14; // [esp+18h] [ebp-A8h] BYREF
  char *Str; // [esp+1Ch] [ebp-A4h]
  float v16; // [esp+20h] [ebp-A0h] BYREF
  int v17; // [esp+24h] [ebp-9Ch] BYREF
  float v18; // [esp+28h] [ebp-98h] BYREF
  float v19; // [esp+2Ch] [ebp-94h] BYREF
  float v20[5]; // [esp+30h] [ebp-90h] BYREF
  float v21; // [esp+44h] [ebp-7Ch] BYREF
  float v22; // [esp+48h] [ebp-78h] BYREF
  float v23; // [esp+4Ch] [ebp-74h] BYREF
  float v24[25]; // [esp+50h] [ebp-70h] BYREF
  _DWORD v25[2]; // [esp+B4h] [ebp-Ch] BYREF

  v13 = a2[2];
  v12 = *((_BYTE *)a1 + 27);
  v11 = *a2;
  v25[0] = 0;
  v25[1] = 0;
  Str_1 = (char *)sub_8ACF00(v11, v12, v13, 0, v25);
  v4 = *a2;
  Str = Str_1;
  FFX_Menu2D_GetAtlasDimensions_structural(v4, &v14, &v16);
  LODWORD(v5) = *(unsigned __int8 *)a1;
  v17 = a1[1];
  LODWORD(v6) = *((unsigned __int8 *)a1 + 1);
  LODWORD(v7) = *((unsigned __int8 *)a1 + 2);
  LODWORD(v8) = *((unsigned __int8 *)a1 + 3);
  v9 = a3 * *((float *)a2 + 6) * flt_C5D77C + *((float *)a1 + 2);
  v24[23] = 0.0;
  LODWORD(v24[21]) = 2000;
  v20[1] = v5;
  v18 = v9;
  v20[2] = v6;
  v10 = *((float *)a2 + 2);
  v20[3] = v7;
  v20[4] = v8;
  v24[1] = v5;
  v24[2] = v6;
  v24[3] = v7;
  v24[4] = v8;
  v19 = v10 / v14;
  v20[0] = *((float *)a2 + 3) / v16;
  v21 = *((float *)a2 + 7) * a3 * flt_C5D778 + *((float *)a1 + 1);
  v22 = flt_C5D77C * (a3 * (*((float *)a2 + 8) + *((float *)a2 + 6))) + *((float *)a1 + 2);
  v23 = *((float *)a2 + 4) / v14;
  v24[0] = *((float *)a2 + 5) / v16;
  if ( sub_8E5A20((float *)&v17, &v18, &v21, &v22, &v19, v20, &v23, v24) )
    sub_640810((int)&v17, Str, 0.0, 0.0, a2[2] + 2);
}
