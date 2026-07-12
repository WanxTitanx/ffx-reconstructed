// Function: sub_8084F0
// Address: 0x8084f0
_WORD *__cdecl sub_8084F0(int a1, _WORD *a2)
{
  int v2; // edx
  unsigned int n0x4000; // eax
  int v5; // esi
  int v6; // ebx
  unsigned __int16 v7; // [esp+4h] [ebp-8h]
  int v8; // [esp+8h] [ebp-4h]

  v2 = *(_DWORD *)(a1 + 544);
  n0x4000 = *(_WORD *)(a1 + 538) & 0xF000;
  v8 = v2;
  if ( n0x4000 > 0x4000 )
  {
    switch ( n0x4000 )
    {
      case 0x5000u:
        sub_7E4450(a2 + 2, (__int16)a2[1] << 16);
        return a2 + 9;
      case 0x6000u:
        sub_7EB320(sub_7EC700, 0, 0, 1);
        return a2 + 1;
      case 0x7000u:
        sub_7EC700((int)*(float *)((__int16)a2[1] + v2) << 8);
        return a2 + 2;
      default:
        return a2;
    }
  }
  else
  {
    if ( n0x4000 == 0x4000 )
    {
      sub_7E4330(a2 + 2, (__int16)a2[1] << 16);
      return a2 + 9;
    }
    if ( (*(_WORD *)(a1 + 538) & 0xF000u) > 0x2000 )
    {
      if ( n0x4000 == 12288 )
      {
        sub_7EC700(0);
        sub_80AD40();
        return a2 + 1;
      }
      return a2;
    }
    if ( n0x4000 == 0x2000 )
    {
      nullsub_96(0, 0);
      return a2 + 1;
    }
    if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
    {
      if ( n0x4000 == 4096 )
      {
        sub_808BD0(a1, v2, (__int16)a2[1]);
        return a2 + 2;
      }
      return a2;
    }
    v7 = a2[2];
    if ( (v7 & 0x8000) != 0 )
      v7 = (a2[2] & 0x3FFF) + 6656;
    v5 = (unsigned __int16)a2[3];
    v6 = sub_7E3720(*(_DWORD *)(a1 + 4 * *(unsigned __int8 *)(v2 + 30) + 864), 2, (__int16)a2[1]);
    *(_DWORD *)(a1 + 852) = sub_7E52A0(
                              *(_DWORD *)(a1 + 852),
                              v6,
                              v7,
                              *(unsigned __int16 *)((char *)a2 + v5)
                            + (*(unsigned __int16 *)((char *)a2 + v5 + 2) << 16),
                              (__int16)a2[4],
                              (int)*(float *)(v8 + 64),
                              (int)*(float *)(v8 + 68),
                              *(_DWORD *)(v8 + 200),
                              *(unsigned __int8 *)(v8 + 194),
                              *(unsigned __int8 *)(v8 + 195));
    return a2 + 5;
  }
}
