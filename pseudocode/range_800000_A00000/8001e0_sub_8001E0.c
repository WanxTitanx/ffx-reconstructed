// Function: sub_8001E0
// Address: 0x8001E0
// Size: 0x64

int __cdecl sub_8001E0(int a1, unsigned __int16 i_3, __int16 n1000, int n2048)
{
  unsigned __int16 v4; // cx
  unsigned __int16 i_1; // ax
  int i_2; // esi
  int i; // edi
  _BYTE *v8; // eax

  if ( FFX_Btl_GetCurrentBattleFormationId() != 507 ) /*0x8001ed*/
  {
    v4 = *(_WORD *)(a1 + 76); /*0x8001f3*/
    if ( v4 ) /*0x8001fa*/
    {
      i_1 = n1000 + 1; /*0x8001ff*/
      if ( (unsigned __int16)(n1000 + 1) >= v4 ) /*0x800206*/
        i_1 = *(_WORD *)(a1 + 76); /*0x800208*/
      i_2 = i_3; /*0x80020b*/
      for ( i = i_1; i_2 < i; ++i_2 ) /*0x800215*/
      {
        v8 = (_BYTE *)sub_7E3720(a1, 6, i_2); /*0x80021b*/
        if ( v8 && *v8 == 1 ) /*0x80022a*/
          sub_7FFDD0(v8, n2048); /*0x800230*/
      }
    }
  }
  return 0; /*0x800242*/
}
