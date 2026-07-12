// Function: sub_819C30
// Address: 0x819c30
int __cdecl sub_819C30(int a1, float a2)
{
  float v2; // ebx
  int v4; // esi
  int n0x2000; // eax
  double v6; // st7
  double v7; // st7
  double v8; // st7
  __int16 v10; // [esp+14h] [ebp+8h]
  float v11; // [esp+18h] [ebp+Ch]

  v2 = a2;
  v10 = *(_WORD *)(LODWORD(a2) + 2);
  v4 = *(_DWORD *)(a1 + 544);
  n0x2000 = *(_WORD *)(a1 + 538) & 0xE000;
  if ( (*(_WORD *)(a1 + 538) & 0xE000) == 0 )
  {
    v6 = sub_800B30(*(unsigned __int8 *)(v4 + 24), *(char *)(a1 + 542));
    goto LABEL_10;
  }
  if ( n0x2000 == 0x2000 )
  {
    if ( *(_BYTE *)(a1 + 542) )
    {
      sub_795730(*(unsigned __int8 *)(v4 + 24), (float *)a1);
      v7 = *(float *)(a1 + 4);
      if ( v7 >= 0.0 )
        goto LABEL_12;
      v6 = -v7;
    }
    else
    {
      v6 = 1.0;
    }
    goto LABEL_10;
  }
  if ( n0x2000 == 0x4000 )
  {
    v6 = sub_800BF0(*(unsigned __int8 *)(v4 + 24), *(char *)(a1 + 542));
LABEL_10:
    a2 = v6;
  }
  v7 = a2;
LABEL_12:
  if ( (*(_WORD *)(a1 + 538) & 0x1000) != 0 )
  {
    if ( (*(_WORD *)(a1 + 538) & 0x1000) == 0x1000 )
    {
      v11 = v7 * 16.0;
      v8 = v11;
      if ( ((v10 >> 4) & 1) != 0 )
        *(float *)(v4 + 64) = *(float *)(v4 + 64) * v8;
      if ( ((v10 >> 5) & 1) != 0 )
        *(float *)(v4 + 68) = *(float *)(v4 + 68) * v8;
      if ( ((v10 >> 5) & 2) != 0 )
      {
        *(float *)(v4 + 72) = v8 * *(float *)(v4 + 72);
        return LODWORD(v2) + 4;
      }
    }
  }
  else
  {
    if ( (v10 & 1) != 0 )
      *(float *)(v4 + 48) = *(float *)(v4 + 48) * v7;
    if ( ((v10 >> 1) & 1) != 0 )
      *(float *)(v4 + 52) = *(float *)(v4 + 52) * v7;
    if ( ((v10 >> 2) & 1) != 0 )
      *(float *)(v4 + 56) = *(float *)(v4 + 56) * v7;
    if ( ((v10 >> 3) & 1) != 0 )
      *(float *)(v4 + 60) = *(float *)(v4 + 60) * v7;
    if ( ((v10 >> 4) & 1) != 0 )
      *(float *)(v4 + 64) = *(float *)(v4 + 64) * v7;
    if ( ((v10 >> 5) & 1) != 0 )
      *(float *)(v4 + 68) = *(float *)(v4 + 68) * v7;
    if ( ((v10 >> 6) & 1) != 0 )
      *(float *)(v4 + 72) = *(float *)(v4 + 72) * v7;
    if ( ((v10 >> 6) & 2) != 0 )
    {
      *(float *)(v4 + 76) = v7 * *(float *)(v4 + 76);
      return LODWORD(v2) + 4;
    }
  }
  return LODWORD(v2) + 4;
}
