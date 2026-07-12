// Function: sub_A49440
// Address: 0xa49440
// Size: 0x8b
// Prototype: 

int __cdecl sub_A49440(int a1, _DWORD *a2)
{
  int v2; // edi
  char *EntryByIdRange; // eax
  _DWORD *v4; // esi
  char *EntryByIdRange_1; // edx
  unsigned __int8 v6; // bl
  __int16 v8; // ax

  v2 = a1;
  EntryByIdRange = FFX_Table_GetEntryByIdRange(*(unsigned __int16 *)(a1 + 6), (__int16 *)unk_1A860E0, &a1);
  v4 = a2;
  EntryByIdRange_1 = EntryByIdRange;
  v6 = *(_BYTE *)(*a2 + 13);
  if ( v6 )
  {
    v4[3] |= sub_A5D120(v6, (v2 - dword_2305834[0] - 2056) / 40, EntryByIdRange, a2[1]);
    return v4[3];
  }
  else
  {
    if ( (*(_BYTE *)(v2 + 33) & (_BYTE)a2[2]) == 0 )
    {
      v8 = *((_WORD *)EntryByIdRange + 8);
      if ( (*((_WORD *)EntryByIdRange_1 + 8) & 0x8000) == 0 )
        a2[3] |= (unsigned __int16)(v8 & *(_WORD *)(*a2 + 10));
    }
    return v4[3];
  }
}

