// Function: sub_A69DE0
// Address: 0xa69de0
// Size: 0x7a
// Prototype: 

int __cdecl sub_A69DE0(int a1, int a2, int a3)
{
  int n208; // eax
  char v4; // dl
  int v5; // ecx

  n208 = FFX_Btl_GetCurrentBattleFormationId();
  if ( n208 != 148 )
  {
    n208 = FFX_Btl_GetCurrentBattleFormationId();
    if ( n208 != 569 )
    {
      n208 = FFX_Btl_GetCurrentBattleFormationId();
      if ( n208 != 208 )
      {
        n208 = a1 + 32;
        if ( *(_BYTE *)(a1 + 33) != 0xFF )
        {
          do
          {
            v4 = *(_BYTE *)(n208 + 1);
            v5 = *(__int16 *)(n208 + 2);
            *(_DWORD *)(n208 + 8) = a2;
            *(_DWORD *)(n208 + 12) = a3;
            n208 += dword_C88AA8[v4 & 7] * v5 + 16;
          }
          while ( *(_BYTE *)(n208 + 1) != 0xFF );
        }
      }
    }
  }
  return n208;
}

