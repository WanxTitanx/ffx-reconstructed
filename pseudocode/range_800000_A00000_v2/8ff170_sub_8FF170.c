// Function: sub_8FF170
// Address: 0x8ff170
int __cdecl sub_8FF170(int a1, int a2)
{
  __int16 v3; // ax
  __int16 v4; // cx
  int v5; // eax
  int v6; // eax

  if ( !*((_WORD *)&unk_18762A0 + 8 * a1) )
    return a2;
  v3 = *((_WORD *)&unk_18762AA + 8 * a1);
  v4 = *((_WORD *)&unk_18762AC + 8 * a1);
  if ( v3 < v4 )
    *((_WORD *)&unk_18762AA + 8 * a1) = v3 + 1;
  *((_WORD *)&unk_18762A8 + 8 * a1) = (int)(sub_8F38C0(*((__int16 *)&unk_18762AA + 8 * a1), v4)
                                          * (double)*((__int16 *)&unk_18762A6 + 8 * a1));
  v5 = sub_8F2F80(a2, 0xE2u, *((__int16 *)&unk_18762A2 + 8 * a1) - 5, *((__int16 *)&unk_18762A4 + 8 * a1));
  v6 = sub_8F2FE0(
         v5,
         0xE3u,
         *((__int16 *)&unk_18762A2 + 8 * a1) + 11,
         *((__int16 *)&unk_18762A4 + 8 * a1),
         *((__int16 *)&unk_18762A8 + 8 * a1) - 11,
         0,
         -2139062144,
         -2139062144);
  return sub_8F2F80(
           v6,
           0xE4u,
           *((__int16 *)&unk_18762A8 + 8 * a1) + *((__int16 *)&unk_18762A2 + 8 * a1),
           *((__int16 *)&unk_18762A4 + 8 * a1));
}
