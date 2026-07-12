// Function: sub_A3CD30
// Address: 0xa3cd30
// Size: 0x72
// Prototype: int(void)

int sub_A3CD30()
{
  _DWORD *v0; // edx

  if ( dword_1A858B4[446] )
    return sub_A3CE00(0, 0, dword_1A858B4[440], dword_1A858B4[441]);
  v0 = (_DWORD *)dword_1A858B4[683];
  if ( v0 == dword_1A858B4 + 627 )
    return sub_A3CE00(dword_1A858B4[434], dword_1A858B4[435], dword_1A858B4[438], dword_1A858B4[439]);
  if ( !v0[6] )
    return sub_A3CE00(0, 0, dword_1A858B4[440], dword_1A858B4[441]);
  else
    return sub_A3CE00(0, 0, v0[3], v0[4]);
}

