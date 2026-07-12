// Function: sub_810F80
// Address: 0x810f80
int __cdecl sub_810F80(int a1, int a2, int a3, int a4)
{
  int v4; // esi
  int v5; // ebx
  __int16 v6; // di
  int v7; // ebx
  __int16 v8; // ax
  __int16 v9; // ax
  int v11; // [esp+1Ch] [ebp+Ch]

  v4 = *(_DWORD *)(a2 + 32) + (*(unsigned __int16 *)(a4 + 76) << 8);
  v5 = *(__int16 *)(a3 + 2);
  v6 = *(_WORD *)(v5 + a3);
  v7 = a3 + v5;
  v8 = sub_7E5C60(v6);
  if ( v8 >= v6 )
    v8 = v6 - 1;
  v11 = *(__int16 *)(v7 + 2 * v8 + 2);
  v9 = sub_833D70(LODWORD(flt_12A80C0[*(unsigned __int8 *)(v4 + 24)]), v11);
  *(float *)(a4 + 64) = (float)v11;
  *(float *)(a4 + 68) = (float)(v9 < 0 ? 0 : v9);
  rand();
  sub_7E6690(1.0);
  *(float *)(a4 + 72) = 1.0;
  *(_BYTE *)(a4 + 78) = 4;
  return a3 + 4;
}
