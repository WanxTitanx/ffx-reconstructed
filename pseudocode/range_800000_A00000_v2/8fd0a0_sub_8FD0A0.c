// Function: sub_8FD0A0
// Address: 0x8fd0a0
void __cdecl sub_8FD0A0(int *a1, __int16 *a2)
{
  char *Str_1; // eax
  int v3; // ecx
  int v4; // eax
  int v5; // esi
  int v6; // edx
  int v7; // ecx
  double v8; // st6
  __int16 v9; // [esp-8h] [ebp-C8h]
  char v10; // [esp-4h] [ebp-C4h]
  __int16 v11; // [esp+0h] [ebp-C0h]
  float v12; // [esp+18h] [ebp-A8h] BYREF
  char *Str; // [esp+1Ch] [ebp-A4h]
  float v14; // [esp+20h] [ebp-A0h] BYREF
  int v15[36]; // [esp+24h] [ebp-9Ch] BYREF
  _DWORD v16[2]; // [esp+B4h] [ebp-Ch] BYREF

  v11 = a2[2];
  v10 = *((_BYTE *)a1 + 27);
  v9 = *a2;
  v16[0] = 0;
  v16[1] = 0;
  Str_1 = (char *)sub_8ACF00(v9, v10, v11, 0, v16);
  v3 = *a2;
  Str = Str_1;
  FFX_Menu2D_GetAtlasDimensions_structural(v3, &v12, &v14);
  v4 = *((unsigned __int8 *)a1 + 3);
  v15[0] = a1[1];
  v5 = *(unsigned __int8 *)a1;
  v6 = *((unsigned __int8 *)a1 + 1);
  v7 = *((unsigned __int8 *)a1 + 2);
  *(float *)&v15[1] = flt_C5D784 * *((float *)a2 + 6) + *((float *)a1 + 2);
  v8 = *((float *)a2 + 2);
  v15[7] = v4;
  v15[15] = v4;
  v15[34] = 0;
  v15[32] = 2001;
  v15[4] = v5;
  v15[5] = v6;
  v15[6] = v7;
  v15[12] = v5;
  v15[13] = v6;
  v15[14] = v7;
  *(float *)&v15[2] = v8 / v12;
  *(float *)&v15[3] = *((float *)a2 + 3) / v14;
  *(float *)&v15[8] = *((float *)a2 + 7) * flt_C5D784 + *((float *)a1 + 1);
  *(float *)&v15[9] = flt_C5D784 * (*((float *)a2 + 8) + *((float *)a2 + 6)) + *((float *)a1 + 2);
  *(float *)&v15[10] = *((float *)a2 + 4) / v12;
  *(float *)&v15[11] = *((float *)a2 + 5) / v14;
  sub_640810((int)v15, Str, 0.0, 0.0, 0);
}
