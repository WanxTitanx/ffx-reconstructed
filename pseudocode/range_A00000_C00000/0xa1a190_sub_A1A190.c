// Function: sub_A1A190
// Address: 0xa1a190
// Size: 0x125
// Prototype: 

int __thiscall sub_A1A190(_DWORD *this, int a2, unsigned int a3, unsigned int a4)
{
  int v4; // ebx
  int v5; // edi
  int v6; // eax
  int v7; // esi
  _DWORD *i; // [esp+1Ch] [ebp-10h]

  v4 = 0;
  for ( i = this + 971; ; ++i )
  {
    v5 = sub_4410E0(1, (int)&unk_CA37D0, 0);
    if ( v5
      && !sub_4C41C0((_DWORD *)v5, a3 >> 1, a4 >> 1, (int)&unk_CA310C, 0)
      && (*(_DWORD *)(v5 + 20) &= ~2u,
          *(_BYTE *)(v5 + 5) = 0,
          sub_4C4350(v5),
          (v6 = sub_440C40(1, (int)&unk_CA4200, 0)) != 0)
      && (v7 = *(_DWORD *)(v6 + 52)) != 0 )
    {
      sub_583BF0(v5);
      *(_BYTE *)(v7 + 5) = 0;
      *(_DWORD *)(v7 + 12) = "PPostProcessUtils";
    }
    else
    {
      v7 = 0;
    }
    *i = v7;
    if ( !v7 )
      break;
    if ( (unsigned int)++v4 >= 3 )
    {
      *(this + 974) = sub_A05E70(a2);
      return 0;
    }
  }
  return 13;
}

