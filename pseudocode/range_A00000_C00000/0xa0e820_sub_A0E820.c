// Function: sub_A0E820
// Address: 0xa0e820
// Size: 0xc3

int __thiscall sub_A0E820(_DWORD *this, int a2, int a3)
{
  int v4; // eax
  int v6; // esi
  _BYTE v7[16]; // [esp+Ch] [ebp-1Ch] BYREF
  int v8; // [esp+24h] [ebp-4h]

  v4 = *(this + 4109); /*0xa0e849*/
  if ( !v4 ) /*0xa0e851*/
    return 21; /*0xa0e853*/
  sub_5BA760(v4, 0); /*0xa0e873*/
  *(_DWORD *)(a3 + 200) = *(this + 4109); /*0xa0e883*/
  sub_5B3760(*(this + 4108), 0); /*0xa0e892*/
  v8 = 0; /*0xa0e89f*/
  v6 = sub_5BB2D0(v7, 0); /*0xa0e8ab*/
  if ( !v6 ) /*0xa0e8af*/
    v6 = sub_5BB750(0); /*0xa0e8b9*/
  v8 = -1; /*0xa0e8c2*/
  nullsub_24(v7); /*0xa0e8c9*/
  return v6; /*0xa0e858*/
}