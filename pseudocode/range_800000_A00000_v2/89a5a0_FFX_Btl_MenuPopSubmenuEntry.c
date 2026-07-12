// Function: FFX_Btl_MenuPopSubmenuEntry
// Address: 0x89a5a0
int FFX_Btl_MenuPopSubmenuEntry()
{
  char v0; // bl
  __int16 v2; // ax
  int v3; // esi
  bool v4; // zf
  char v5; // bl
  int v6; // eax
  char v7; // cl

  v0 = unk_23CC092[0];
  if ( unk_23CC092[0] <= 0 )
    return 0;
  v2 = unk_23CC088[0];
  v3 = 120 * unk_23CC092[0];
  *((_BYTE *)&unk_133C911 + v3 * 2) = 5;
  *(_WORD *)((char *)&unk_133C918 + v3 * 2) = v2;
  word_133C926[v3] = 255;
  v4 = unk_133C912[v3 * 2] == 1;
  n256_0 &= unk_133C91C[v3] == 12574 ? 0 : (unk_133C91C[v3] == 12329) - 1;
  if ( v4 )
    *((_WORD *)&unk_133C9B6 + 120 * v0) = *((_WORD *)&unk_133C8C6 + 120 * v0);
  v5 = v0 - 1;
  v6 = 240 * v5;
  unk_23CC092[0] = v5;
  *((_BYTE *)&unk_133C911 + v6) = 2;
  v7 = *((_BYTE *)&unk_133C91B + v6);
  if ( v7 >= *((char *)&unk_133C91A + v6) && v7 > 0 )
    *((_BYTE *)&unk_133C91B + 240 * v5) = v7 - 1;
  if ( unk_133C912[240 * v5] == 1 )
  {
    qmemcpy(&n0x1C, &n0x1C_0, 0x140u);
    unk_133F0C6 = 0;
  }
  return 1;
}
