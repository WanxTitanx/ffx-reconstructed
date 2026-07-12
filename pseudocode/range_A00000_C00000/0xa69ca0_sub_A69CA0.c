// Function: sub_A69CA0
// Address: 0xa69ca0
// Size: 0x136
// Prototype: _DWORD __cdecl(int, int, __int16, __int16 n0x4000)

int __cdecl sub_A69CA0(int a1, int a2, unsigned __int16 n0x4000_2, unsigned __int16 n0x4000)
{
  int result; // eax
  __int16 n0x3FFF; // di
  int v6; // esi
  __int16 n0x3FFF_1; // bx
  char v8; // dl
  int v9; // ecx
  int v10; // esi
  int v11; // ecx
  char v12; // bl
  int n0x4000_1; // esi
  unsigned int v14; // esi
  __int16 n0x3FFF_2; // [esp+Ch] [ebp-4h]

  result = a1 + 32;
  n0x3FFF = 0x3FFF;
  v6 = a1 + 32;
  n0x3FFF_1 = 0x3FFF;
  v8 = *(_BYTE *)(a1 + 33);
  n0x3FFF_2 = 0x3FFF;
  if ( v8 != -1 )
  {
    do
    {
      if ( (v8 & 2) != 0 )
      {
        if ( (__int16)((*(_WORD *)(v6 + 8) & 0x3FFF) - 0x3FFF) < n0x3FFF_1 )
          n0x3FFF_1 = (*(_WORD *)(v6 + 8) & 0x3FFF) - 0x3FFF;
        if ( (__int16)(((*(_DWORD *)(v6 + 12) >> 5) & 0x3FFF) - 0x3FFF) < n0x3FFF )
          n0x3FFF = ((*(_DWORD *)(v6 + 12) >> 5) & 0x3FFF) - 0x3FFF;
      }
      v9 = *(__int16 *)(v6 + 2);
      v10 = v6 + 16;
      v11 = dword_C88AA8[v8 & 7] * v9;
      v8 = *(_BYTE *)(v10 + v11 + 1);
      v6 = v11 + v10;
    }
    while ( v8 != -1 );
    n0x3FFF_2 = n0x3FFF_1;
  }
  if ( *(_BYTE *)(a1 + 33) != 0xFF )
  {
    do
    {
      v12 = *(_BYTE *)(result + 1);
      if ( (v12 & 2) != 0 )
      {
        n0x4000_1 = *(_WORD *)(result + 8) & 0x3FFF;
        if ( n0x4000_1 >= n0x4000_2 && n0x4000_1 <= n0x4000 )
        {
          v14 = *(_DWORD *)(result + 12);
          v12 = *(_BYTE *)(result + 1);
          *(_DWORD *)(result + 8) = (__int16)(((*(_WORD *)(result + 8) & 0x3FFF) - n0x3FFF_2)
                                            & (((__int16)((*(_WORD *)(result + 8) & 0x3FFF) - n0x3FFF_2) < 0) - 1))
                                  | *(_DWORD *)(result + 8) & 0xFFFFC000;
          *(_DWORD *)(result + 12) = v14 & 0xFFF8001F
                                   | (32
                                    * (__int16)((((v14 >> 5) & 0x3FFF) - n0x3FFF)
                                              & (((__int16)(((v14 >> 5) & 0x3FFF) - n0x3FFF) < 0) - 1)));
        }
      }
      result += dword_C88AA8[v12 & 7] * *(__int16 *)(result + 2) + 16;
    }
    while ( *(_BYTE *)(result + 1) != 0xFF );
  }
  return result;
}

