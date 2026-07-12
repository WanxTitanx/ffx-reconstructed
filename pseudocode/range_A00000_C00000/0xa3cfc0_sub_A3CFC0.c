// Function: sub_A3CFC0
// Address: 0xa3cfc0
// Size: 0x55
// Prototype: int(void)

_DWORD *sub_A3CFC0()
{
  _DWORD *result; // eax
  int i; // esi
  _DWORD *v2; // edi
  int v3; // ecx

  result = dword_1A858B4;
  for ( i = 544; i < 576; ++i )
  {
    v2 = &result[i];
    result[i - 32] = 0;
    v3 = result[i];
    if ( v3 )
    {
      (*(void (__stdcall **)(int))(*(_DWORD *)v3 + 8))(v3);
      result = dword_1A858B4;
      *v2 = 0;
    }
    result[i + 32] = 0;
  }
  result[608] = 0;
  return result;
}

