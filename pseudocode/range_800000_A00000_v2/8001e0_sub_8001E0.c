// Function: sub_8001E0
// Address: 0x8001e0
int __cdecl sub_8001E0(int a1, unsigned __int16 i_3, __int16 n1000, int n2048)
{
  unsigned __int16 v4; // cx
  unsigned __int16 i_1; // ax
  int i_2; // esi
  int i; // edi
  _BYTE *v8; // eax

  if ( FFX_Btl_GetCurrentBattleFormationId() != 507 )
  {
    v4 = *(_WORD *)(a1 + 76);
    if ( v4 )
    {
      i_1 = n1000 + 1;
      if ( (unsigned __int16)(n1000 + 1) >= v4 )
        i_1 = *(_WORD *)(a1 + 76);
      i_2 = i_3;
      for ( i = i_1; i_2 < i; ++i_2 )
      {
        v8 = (_BYTE *)sub_7E3720(a1, 6, i_2);
        if ( v8 && *v8 == 1 )
          sub_7FFDD0(v8, n2048);
      }
    }
  }
  return 0;
}
