// Function: sub_8FDF20
// Address: 0x8fdf20
void __cdecl sub_8FDF20(int a1)
{
  int v1; // ecx
  int v2; // edx
  int v3; // eax
  int v4; // eax
  int v5; // [esp+4h] [ebp-A0h]
  int v6[38]; // [esp+8h] [ebp-9Ch] BYREF

  v6[36] = 0;
  v6[37] = 0;
  v6[32] = 0;
  v6[34] = 0;
  if ( sub_8AE4E0(2, "bwakk") == 3 && *(_WORD *)(a1 + 14) == 7 && *(_WORD *)(a1 + 18) == 22 )
    *(_WORD *)(a1 + 14) = 67;
  v6[4] = *(unsigned __int8 *)(a1 + 4);
  v6[5] = *(unsigned __int8 *)(a1 + 5);
  v1 = *(__int16 *)(a1 + 12);
  v6[6] = *(unsigned __int8 *)(a1 + 6);
  v2 = *(__int16 *)(a1 + 14);
  v6[7] = *(unsigned __int8 *)(a1 + 7);
  v6[12] = *(unsigned __int8 *)(a1 + 8);
  v6[13] = *(unsigned __int8 *)(a1 + 9);
  v6[14] = *(unsigned __int8 *)(a1 + 10);
  v6[15] = *(unsigned __int8 *)(a1 + 11);
  v3 = *(__int16 *)(a1 + 16);
  *(float *)v6 = (float)v1;
  v5 = v1 + v3;
  v4 = *(__int16 *)(a1 + 18);
  *(float *)&v6[1] = (float)v2;
  *(float *)&v6[8] = (float)v5;
  *(float *)&v6[9] = (float)(v2 + v4);
  sub_63F090((int)v6, 0, 1, 0, 0.0);
}
