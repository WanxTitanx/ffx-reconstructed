// Function: sub_A452D0
// Address: 0xa452d0
// Size: 0x14c
// Prototype: 

int sub_A452D0()
{
  int result; // eax
  _WORD *v1; // edi
  int v2; // esi
  __int16 v3; // dx
  __int16 v4; // si

  sub_A58FF0(sub_A45000);
  result = unk_2305834;
  if ( !*(_BYTE *)(unk_2305834 + 71117) && !*(_DWORD *)(unk_2305834 + 71088) )
  {
    v1 = (_WORD *)unk_1A86108;
    if ( !*(_DWORD *)(unk_1A86108 + 6708) )
    {
      result = *(unsigned __int16 *)(unk_2305834 + 71278);
      if ( (result & 0x20) != 0 )
      {
        v2 = *(_DWORD *)(unk_1A86108 + 12 * (*(__int16 *)(unk_1A86108 + 6680) + 6) + 6656);
        *(_BYTE *)(unk_1A86108 + 6691) = 0;
        sub_A59680(8);
        sub_A5B930();
        sub_A5BCA0(
          *(unsigned __int8 *)(unk_2305834 + 71100),
          *(unsigned __int16 *)(unk_2305834 + 70396),
          (unsigned __int16)v2);
        *(_WORD *)(unk_1A86108 + 6686) = 0;
        sub_A45FD0(8, 3);
        v3 = v1[3343];
        if ( (__int16)v1[3340] >= v3 )
          v1[3340] = v3 - 1;
        if ( (__int16)v1[3340] < 0 )
          v1[3340] = 0;
        v4 = v1[3339];
        if ( (__int16)v1[3341] > v3 - v4 )
          v1[3341] = v3 - v4;
        if ( (__int16)v1[3341] < 0 )
          v1[3341] = 0;
        return sub_A47400(252);
      }
      else if ( (result & 0x40) != 0 )
      {
        sub_A598A0();
        sub_A596D0(8);
        sub_A47400(252);
        return FFX_BtlEffect_Enable(-2147483644);
      }
    }
  }
  return result;
}

