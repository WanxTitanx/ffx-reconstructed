// Function: sub_A1A350
// Address: 0xa1a350
// Size: 0x182
// Prototype: 

int __thiscall sub_A1A350(_DWORD *this, int a2, unsigned int a3, unsigned int a4)
{
  int v5; // eax
  int v6; // esi
  int v7; // ebx
  _DWORD *v8; // eax
  _DWORD *v9; // edi
  int v10; // eax
  int v11; // esi
  _DWORD *i; // [esp+1Ch] [ebp-10h]

  v5 = sub_4410E0(1, (int)&unk_CA37D0, 0);
  v6 = v5;
  if ( v5 )
  {
    if ( sub_4C41C0((_DWORD *)v5, a3, a4, (int)&unk_CA310C, 0) )
    {
      v5 = 0;
    }
    else
    {
      *(_DWORD *)(v6 + 20) &= ~2u;
      *(_BYTE *)(v6 + 5) = 0;
      sub_4C4350(v6);
      v5 = sub_64AFA0(v6);
      if ( v5 )
      {
        *(_BYTE *)(v5 + 5) = 0;
        *(_DWORD *)(v5 + 12) = "PPostProcessUtils";
      }
    }
  }
  *(this + 23) = v5;
  if ( v5 )
  {
    v7 = 0;
    for ( i = this + 24; ; ++i )
    {
      v8 = (_DWORD *)sub_4410E0(1, (int)&unk_CA37D0, 0);
      v9 = v8;
      if ( v8
        && !sub_4C41C0(v8, a3, a4, (int)&unk_CA310C, 0)
        && (v9[5] &= ~2u, *((_BYTE *)v9 + 5) = 0, sub_4C4350(v9), (v10 = sub_440C40(1, (int)&unk_CA4200, 0)) != 0)
        && (v11 = *(_DWORD *)(v10 + 52)) != 0 )
      {
        sub_583BF0(v9);
        *(_BYTE *)(v11 + 5) = 0;
        *(_DWORD *)(v11 + 12) = "PPostProcessUtils";
      }
      else
      {
        v11 = 0;
      }
      *i = v11;
      if ( !v11 )
        break;
      if ( (unsigned int)++v7 >= 2 )
      {
        *(this + 26) = sub_A05E70(a2);
        return 0;
      }
    }
  }
  return 13;
}

