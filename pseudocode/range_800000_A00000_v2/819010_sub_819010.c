// Function: sub_819010
// Address: 0x819010
int __cdecl sub_819010(int a1, int a2)
{
  int v3; // ebx
  unsigned int n0x8000; // eax
  int v6; // [esp-8h] [ebp-18h]
  float v7; // [esp+18h] [ebp+8h]
  float v8; // [esp+18h] [ebp+8h]

  v3 = *(_DWORD *)(a1 + 544);
  n0x8000 = *(_WORD *)(a1 + 538) & 0xF000;
  if ( n0x8000 > 0x4000 )
  {
    if ( (*(_WORD *)(a1 + 538) & 0xF000u) > 0x7000 )
    {
      if ( n0x8000 != 0x8000 )
        goto LABEL_27;
      sub_81B410(a1);
    }
    else
    {
      if ( n0x8000 != 28672 )
      {
        if ( n0x8000 == 20480 )
        {
          sub_81B4F0((char *)&unk_12A40C0 + 32 * *(unsigned __int16 *)(v3 + 20), a1, 1);
          goto LABEL_26;
        }
        if ( n0x8000 != 24576 )
          goto LABEL_27;
      }
      sub_8053F0(
        a1,
        LODWORD(flt_12A80C0[*(unsigned __int8 *)(v3 + 24)]),
        ((*(_WORD *)(a1 + 538) & 0x1000 | 0x10000u) >> 12) + 0x8000);
    }
LABEL_26:
    sub_7EA760(v3 + 64, a1, 16.0);
    goto LABEL_27;
  }
  if ( n0x8000 == 0x4000 )
  {
    sub_81B2F0(*(unsigned __int8 *)(v3 + 24), a1);
    v8 = sub_800A90(*(unsigned __int8 *)(v3 + 24), *(char *)(a1 + 542)) * 0.5;
    if ( sub_800A60(*(unsigned __int8 *)(v3 + 24), v6) )
      *(float *)(a1 + 4) = *(float *)(a1 + 4) + v8;
    goto LABEL_26;
  }
  if ( (*(_WORD *)(a1 + 538) & 0xF000u) > 0x2000 )
  {
    if ( n0x8000 != 12288 )
      goto LABEL_27;
    sub_7948F0(*(unsigned __int8 *)(v3 + 24), a1);
    goto LABEL_26;
  }
  if ( n0x8000 == 0x2000 )
  {
    sub_81B4F0((char *)&unk_12A40C0 + 32 * *(unsigned __int16 *)(v3 + 20), a1, 0);
    goto LABEL_26;
  }
  if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0 )
  {
    sub_81B2F0(*(unsigned __int8 *)(v3 + 24), a1);
    goto LABEL_26;
  }
  if ( n0x8000 == 4096 )
  {
    v7 = sub_800A90(*(unsigned __int8 *)(v3 + 24), *(char *)(a1 + 542)) * 0.5;
    sub_81B2F0(*(unsigned __int8 *)(v3 + 24), a1);
    if ( *(_BYTE *)(a1 + 542) && !sub_794F80(*(unsigned __int8 *)(v3 + 24)) && !sub_7822A0() )
      *(float *)(a1 + 4) = *(float *)(a1 + 4) - v7;
    sub_8053F0(a1 + 16, LODWORD(flt_12A80C0[*(unsigned __int8 *)(v3 + 24)]), 32771);
    *(float *)a1 = *(float *)(a1 + 16);
    *(float *)(a1 + 8) = *(float *)(a1 + 24);
    sub_7EA760(v3 + 64, a1, 16.0);
  }
LABEL_27:
  sub_7EA760(v3 + 144, v3 + 64, 0.0625);
  return a2 + 2;
}
