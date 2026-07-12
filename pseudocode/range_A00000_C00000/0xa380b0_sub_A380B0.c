// Function: sub_A380B0
// Address: 0xa380b0
// Size: 0x4a
// Prototype: 

_DWORD *sub_A380B0()
{
  _DWORD *result; // eax
  _WORD v1[24]; // [esp+0h] [ebp-30h] BYREF

  if ( dword_1A858B4 )
  {
    memset(v1, 0, sizeof(v1));
    sub_A36300(v1);
    result = dword_1A858B4;
    dword_1A858B4[432] = 0;
    result[433] = 0;
  }
  return result;
}

