// Function: sub_A44EF0
// Address: 0xa44ef0
// Size: 0x106
// Prototype: 

int sub_A44EF0()
{
  int result; // eax
  __int16 v1; // cx
  int v2; // ecx
  _BYTE *v3; // eax

  result = sub_A58FF0(sub_A45000);
  if ( !*(_BYTE *)(unk_2305834 + 71117) && !*(_DWORD *)(unk_2305834 + 71088) )
  {
    *(_DWORD *)(unk_2305834 + 71196) = (*(unsigned __int16 *)(unk_2305834
                                                            + 40 * *(unsigned __int16 *)(unk_2305834 + 70396)
                                                            + 2092)
                                      + 3) >> 2;
    result = unk_2305834;
    v1 = *(_WORD *)(unk_2305834 + 71278);
    if ( (v1 & 0x20) != 0 )
    {
      v2 = *(__int16 *)(unk_2305834 + 4);
      if ( *(_WORD *)(unk_2305834 + 4) )
      {
        v3 = (_BYTE *)(unk_2305834 + 43030);
        do
        {
          *v3 &= 0xF8u;
          v3 += 20;
          --v2;
        }
        while ( v2 );
        result = unk_2305834;
      }
      *(_DWORD *)(result + 71080) = sub_A48230;
      *(_DWORD *)(unk_2305834 + 71084) = 0;
      *(_BYTE *)(unk_2305834 + 71107) = 0;
      return sub_A48C80(*(unsigned __int8 *)(unk_2305834 + 71100), *(_WORD *)(unk_2305834 + 70396));
    }
    else if ( (v1 & 0x40) != 0 )
    {
      sub_A473D0(240);
      FFX_BtlEffect_Enable(-2147483644);
      *(_BYTE *)(unk_2305834 + 71107) = 0;
      *(_DWORD *)(unk_2305834 + 71196) = 0;
      sub_A59950();
      return sub_A596D0(7);
    }
  }
  return result;
}

