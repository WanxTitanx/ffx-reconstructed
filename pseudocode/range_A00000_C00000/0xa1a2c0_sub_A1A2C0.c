// Function: sub_A1A2C0
// Address: 0xa1a2c0
// Size: 0x8b
// Prototype: 

int __thiscall sub_A1A2C0(_DWORD *this, int a2, unsigned int a3, unsigned int a4)
{
  int v5; // eax
  int v6; // esi

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
  if ( !v5 )
    return 13;
  *(this + 24) = sub_A06120(a2);
  return 0;
}

