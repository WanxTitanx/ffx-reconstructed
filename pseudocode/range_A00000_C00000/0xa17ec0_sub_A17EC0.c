// Function: sub_A17EC0
// Address: 0xa17ec0
// Size: 0x159
// Prototype: 

int __thiscall sub_A17EC0(_DWORD *this, int a2, unsigned int a3, unsigned int a4)
{
  int v5; // eax
  int v7; // eax
  int v8; // esi
  int v9; // eax
  int v10; // esi
  int v11; // esi
  int v12; // eax

  v5 = sub_A05E70(a2);
  *(this + 7) = v5;
  if ( !v5 )
    return 14;
  v7 = sub_4410E0(1, (int)&unk_CA37D0, 0);
  v8 = v7;
  if ( v7 )
  {
    if ( sub_4C41C0((_DWORD *)v7, a3 >> 1, a4 >> 1, (int)&unk_CA310C, 0) )
    {
      v7 = 0;
    }
    else
    {
      *(_DWORD *)(v8 + 20) &= ~2u;
      *(_BYTE *)(v8 + 5) = 0;
      sub_4C4350(v8);
      v7 = sub_64AFA0(v8);
      if ( v7 )
      {
        *(_BYTE *)(v7 + 5) = 0;
        *(_DWORD *)(v7 + 12) = "PPostProcessUtils";
      }
    }
  }
  *(this + 26) = v7;
  v9 = sub_4410E0(1, (int)&unk_CA37D0, 0);
  v10 = v9;
  if ( v9 )
  {
    if ( sub_4C41C0((_DWORD *)v9, a3 >> 1, a4 >> 1, (int)&unk_CA3314, 0) )
    {
      v9 = 0;
    }
    else
    {
      *(_DWORD *)(v10 + 20) &= ~2u;
      *(_BYTE *)(v10 + 5) = 0;
      sub_4C4350(v10);
      v9 = sub_64AFA0(v10);
      if ( v9 )
      {
        *(_BYTE *)(v9 + 5) = 0;
        *(_DWORD *)(v9 + 12) = "PPostProcessUtils";
      }
    }
  }
  *(this + 27) = v9;
  v11 = sub_4410E0(1, (int)&unk_CA37D0, 0);
  if ( v11
    && !sub_4C41C0((_DWORD *)v11, a3 >> 1, a4 >> 1, (int)&unk_CA310C, 0)
    && (*(_DWORD *)(v11 + 20) &= ~2u, *(_BYTE *)(v11 + 5) = 0, sub_4C4350(v11), (v12 = sub_64AFA0(v11)) != 0) )
  {
    *(_BYTE *)(v12 + 5) = 0;
    *(_DWORD *)(v12 + 12) = "PPostProcessUtils";
    *(this + 28) = v12;
    return 0;
  }
  else
  {
    *(this + 28) = 0;
    return 0;
  }
}

