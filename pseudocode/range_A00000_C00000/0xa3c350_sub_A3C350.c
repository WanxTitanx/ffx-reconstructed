// Function: sub_A3C350
// Address: 0xa3c350
// Size: 0xa0
// Prototype: int(void)

int sub_A3C350()
{
  _DWORD *v0; // edi
  int result; // eax

  if ( !dword_1A858B4[446] )
  {
    v0 = (_DWORD *)dword_1A858B4[683];
    if ( v0 == dword_1A858B4 + 627 )
    {
      return sub_A3C450(
               dword_1A858B4[442],
               dword_1A858B4[442] + dword_1A858B4[438],
               dword_1A858B4[443] + dword_1A858B4[439],
               dword_1A858B4[443]);
    }
    else if ( v0[6] )
    {
      return sub_A3C450(v0[1], v0[1] + v0[3], v0[2], v0[2] + v0[4]);
    }
    else
    {
      return sub_A3C450(
               dword_1A858B4[444],
               dword_1A858B4[444] + dword_1A858B4[440],
               dword_1A858B4[445] + dword_1A858B4[441],
               dword_1A858B4[445]);
    }
  }
  return result;
}

