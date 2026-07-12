// Function: sub_804760
// Address: 0x804760
int __cdecl sub_804760(_DWORD *a1, int a2)
{
  int v2; // edi
  int v3; // esi
  int v4; // eax
  unsigned int n24576; // eax
  int v7; // eax
  double v8; // st6
  int v9; // edi
  __int16 n2048; // ax
  int v11; // edi
  int v12; // [esp-14h] [ebp-50h]
  int v13; // [esp+4h] [ebp-38h]
  int v14; // [esp+20h] [ebp-1Ch]
  float v15; // [esp+20h] [ebp-1Ch]
  int v16; // [esp+24h] [ebp-18h]
  float v17; // [esp+24h] [ebp-18h]
  _BYTE v18[16]; // [esp+28h] [ebp-14h] BYREF
  int savedregs; // [esp+3Ch] [ebp+0h] BYREF

  v2 = a1[136];
  v14 = LODWORD(flt_12A80C0[*(unsigned __int8 *)(v2 + 24)]);
  v3 = v14;
  sub_82ABE0(v14);
  if ( (*((_WORD *)a1 + 269) & 0x800) != 0 )
    v4 = sub_801E20(a1, (unsigned __int16 *)v2);
  else
    v4 = v2;
  v16 = v4;
  n24576 = *((_WORD *)a1 + 269) & 0xF000;
  if ( n24576 > 0x4000 )
  {
    if ( n24576 != 20480 )
    {
      if ( n24576 == 24576 )
      {
        sub_8061E0(
          COERCE_FLOAT(&savedregs),
          a1 + 64,
          *(unsigned __int8 *)(v2 + 24),
          *(float *)(v2 + 60),
          0,
          0,
          *((char *)a1 + 542));
        sub_7E9760(a1, a1 + 64, v2 + 48, v2 + 144);
        if ( (*((_WORD *)a1 + 269) & 0x800) != 0 )
          sub_7E82C0(a1, v16, a1);
        v7 = sub_8356E0(v14, 1, v18);
        sub_833C00(v14, v7, a1 + 32);
        sub_7E78B0(a1 + 44, a1 + 32, v18);
        if ( !sub_800A60(*(unsigned __int8 *)(v2 + 24), v12) )
        {
          sub_7E78B0(a1 + 20, a1 + 64, a1 + 44);
          sub_7E78B0(a1 + 16, a1, a1 + 44);
          *((float *)a1 + 12) = *((float *)a1 + 12) - (*((float *)a1 + 16) - *((float *)a1 + 12)) * 0.5;
          v8 = *((float *)a1 + 13);
          *((float *)a1 + 14) = *((float *)a1 + 14) - (*((float *)a1 + 18) - *((float *)a1 + 14)) * 0.5;
          v17 = v8 - (*((float *)a1 + 17) - v8) * 0.5;
          *((float *)a1 + 13) = 0.5 * *((float *)a1 + 21) + v17;
        }
        v9 = v2 + 192;
        sub_7E7F20(v9, a1);
        if ( v14 )
        {
          FFX_BtlMenu_ClearActorModelAnimation(v14, v9);
          sub_82AAB0(v14, 0);
        }
        return a2 + 2;
      }
      if ( n24576 != 28672 )
        return a2;
      v15 = *(float *)(v2 + 60) * 0.00390625 * 0.001000000047497451;
      *((float *)a1 + 18) = v15;
      *((float *)a1 + 16) = v15;
      *((float *)a1 + 17) = 0.001000000047497451 * (0.00390625 * *(float *)(v2 + 76));
      sub_7EA640(a1, (int)(a1 + 16));
      sub_7E9760(a1, a1, v2 + 48, v2 + 144);
      goto LABEL_28;
    }
    goto LABEL_22;
  }
  if ( n24576 == 0x4000 || (*((_WORD *)a1 + 269) & 0xF000) == 0 )
  {
LABEL_25:
    sub_8061E0(
      COERCE_FLOAT(&savedregs),
      a1,
      *(unsigned __int8 *)(v2 + 24),
      *(float *)(v2 + 60),
      0,
      0,
      *((char *)a1 + 542));
    if ( (*((_WORD *)a1 + 269) & 0x4000) != 0 )
      sub_7E9440(a1, a1, v2 + 48);
    else
      sub_7E9760(a1, a1, v2 + 48, v2 + 144);
LABEL_28:
    v11 = v2 + 192;
    if ( (*((_WORD *)a1 + 269) & 0x800) != 0 )
      sub_7E82C0(v11, v16, a1);
    else
      sub_7E7F20(v11, a1);
    if ( !v3 )
      return a2 + 2;
    FFX_BtlMenu_ClearActorModelAnimation(v3, v11);
    v13 = 0;
    goto LABEL_33;
  }
  if ( n24576 != 4096 )
  {
    if ( n24576 != 0x2000 )
      return a2;
LABEL_22:
    v16 = sub_801E20(a1, (unsigned __int16 *)v2);
    n2048 = 2048;
    if ( (*((_WORD *)a1 + 269) & 0xF000) != 0x2000 )
      n2048 = 18432;
    *((_WORD *)a1 + 269) = n2048;
    goto LABEL_25;
  }
  if ( v14 )
  {
    FFX_BtlMenu_ClearActorModelAnimation(v14, 0);
    v13 = 1;
LABEL_33:
    sub_82AAB0(v3, v13);
  }
  return a2 + 2;
}
