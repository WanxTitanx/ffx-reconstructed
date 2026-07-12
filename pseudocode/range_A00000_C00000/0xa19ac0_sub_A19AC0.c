// Function: sub_A19AC0
// Address: 0xa19ac0
// Size: 0x9c
// Prototype: 

int __thiscall sub_A19AC0(int this, unsigned int a2, unsigned int a3)
{
  unsigned int v4; // eax
  unsigned int v5; // ecx
  int result; // eax

  if ( (unk_C9628C[0] & 1) == 0 )
  {
    unk_C9628C[0] |= 1u;
    PhyreSingleton_RegisterAtExit(byte_C94F00);
    atexit(PhyreSingleton_AtExit_C94F00_Cleanup);
  }
  v4 = a2;
  if ( !a2 )
    v4 = unk_C95100;
  v5 = a3;
  if ( !a3 )
    v5 = unk_C95104;
  result = sub_A179A0((_DWORD *)this, (int)&unk_1943DA0, v4, v5);
  if ( !result )
    *(_BYTE *)(this + 16) = 1;
  return result;
}

