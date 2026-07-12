// Function: sub_A57040
// Address: 0xa57040
// Size: 0x5c
// Prototype: 

char __cdecl sub_A57040(int a1, int a2)
{
  char *EntryByIdRange; // eax
  char *EntryByIdRange_1; // edi
  int v4; // esi
  char v5; // al

  LOBYTE(EntryByIdRange) = FFX_Battle_GetMagicEntryById(*(_DWORD *)(a2 + 8), &a2)[93];
  if ( (_BYTE)EntryByIdRange != 0xFF )
  {
    EntryByIdRange = FFX_Table_GetEntryByIdRange((unsigned __int8)EntryByIdRange, (__int16 *)unk_1A860E4, &a2);
    EntryByIdRange_1 = EntryByIdRange;
    if ( EntryByIdRange )
    {
      v4 = a2;
      v5 = sub_7852B0();
      LOBYTE(EntryByIdRange) = sub_A59350(v4 + *(unsigned __int16 *)&EntryByIdRange_1[4 * (v5 & 1)]);
    }
  }
  return (char)EntryByIdRange;
}

