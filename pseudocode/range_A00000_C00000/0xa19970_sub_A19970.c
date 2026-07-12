// Function: sub_A19970
// Address: 0xa19970
// Size: 0x148
// Prototype: 

int __thiscall sub_A19970(int this, unsigned int a2, unsigned int a3)
{
  unsigned int v4; // esi
  _DWORD *v5; // eax
  _DWORD *v6; // edi
  int v7; // eax
  int v8; // esi

  if ( (unk_C9628C[0] & 1) == 0 )
  {
    unk_C9628C[0] |= 1u;
    PhyreSingleton_RegisterAtExit(byte_C94F00);
    atexit(PhyreSingleton_AtExit_C94F00_Cleanup);
  }
  v4 = a2;
  if ( !a2 )
    v4 = unk_C95100;
  if ( !a3 )
    a3 = unk_C95104;
  v5 = (_DWORD *)sub_4410E0(1, (int)&unk_CA37D0, 0);
  v6 = v5;
  if ( v5
    && !sub_4C41C0(v5, v4, a3, (int)&unk_CA310C, 0)
    && (v6[5] &= ~2u, *((_BYTE *)v6 + 5) = 0, sub_4C4350(v6), (v7 = sub_440C40(1, (int)&unk_CA4200, 0)) != 0)
    && (v8 = *(_DWORD *)(v7 + 52)) != 0 )
  {
    sub_583BF0(v6);
    *(_BYTE *)(v8 + 5) = 0;
    *(_DWORD *)(v8 + 12) = "PPostProcessUtils";
  }
  else
  {
    v8 = 0;
  }
  *(_DWORD *)(this + 92) = v8;
  if ( !v8 )
    return 13;
  *(_DWORD *)(this + 96) = sub_A06120(&unk_1943DA0);
  *(_BYTE *)(this + 16) = 1;
  return 0;
}

