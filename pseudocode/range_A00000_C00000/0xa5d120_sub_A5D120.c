// Function: sub_A5D120
// Address: 0xa5d120
// Size: 0x233
// Prototype: _DWORD __cdecl(_DWORD, int, char *EntryByIdRange, _DWORD)

int __cdecl sub_A5D120(int a1, int a2, char *EntryByIdRange, int n7_1)
{
  bool v4; // zf
  int v6; // esi
  int n7_2; // edi
  bool v8; // zf
  int v9; // eax
  int n7; // esi
  char n0xC; // al
  char n0xC_1; // al

  switch ( a1 )
  {
    case 1:
      v4 = EntryByIdRange[22] == 18;
      goto LABEL_3;
    case 2:
      return EntryByIdRange[22] == 17;
    case 3:
      return !EntryByIdRange[22];
    case 4:
      return EntryByIdRange[22] == 16;
    case 5:
    case 6:
    case 7:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
      return EntryByIdRange[22] == 1;
    case 8:
      v6 = a2;
      n7_2 = n7_1;
      if ( sub_A457D0(n7_1, a2) )
        return 0;
      v8 = EntryByIdRange[22] == 15;
      goto LABEL_15;
    case 9:
      v6 = a2;
      n7_2 = n7_1;
      if ( sub_A457D0(n7_1, a2) )
        return 0;
      v8 = EntryByIdRange[22] == 14;
      goto LABEL_15;
    case 10:
      v6 = a2;
      n7_2 = n7_1;
      if ( sub_A457D0(n7_1, a2) )
        return 0;
      v8 = EntryByIdRange[22] == 12;
      goto LABEL_15;
    case 11:
      v6 = a2;
      n7_2 = n7_1;
      if ( sub_A457D0(n7_1, a2) )
        return 0;
      v8 = EntryByIdRange[22] == 13;
LABEL_15:
      if ( !v8 )
        return 0;
      v9 = sub_A45800(n7_2, v6);
      return v9 != 0;
    case 12:
      if ( sub_A45870(n7_1) == a2 )
        return 0;
      v9 = sub_A457D0(n7_1, a2);
      return v9 != 0;
    case 13:
      if ( sub_A45870(n7_1) == a2 )
        return 0;
      v9 = sub_A45800(n7_1, a2);
      return v9 != 0;
    case 14:
      if ( sub_A45870(n7_1) == a2 )
        return 0;
      n7 = 0;
      break;
    case 15:
      if ( sub_A45870(n7_1) != a2 )
      {
        v4 = *((_WORD *)EntryByIdRange + 8) >= 0;
LABEL_3:
        if ( v4 )
          return 1;
      }
      return 0;
    case 23:
      n0xC = EntryByIdRange[22];
      return (unsigned __int8)n0xC > 1u && (unsigned __int8)n0xC < 0xCu;
    case 24:
      if ( sub_A457D0(n7_1, a2) )
        return 0;
      n0xC_1 = EntryByIdRange[22];
      return (unsigned __int8)n0xC_1 > 1u && (unsigned __int8)n0xC_1 < 0xCu && sub_A45800(n7_1, a2);
    default:
      return 0;
  }
  do
  {
    if ( n7_1 != n7 && FFX_Party_IsMemberActive(n7) && sub_A45870(n7) == a2 )
      return 1;
    ++n7;
  }
  while ( n7 < 7 );
  return 0;
}

