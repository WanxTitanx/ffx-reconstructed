// Function: sub_A198D0
// Address: 0xa198d0
// Size: 0x9c
// Prototype: 

int __thiscall sub_A198D0(int this, int a2, int a3)
{
  int v4; // eax
  int v5; // ecx
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
  result = sub_A176D0((_DWORD *)this, (int)&unk_1943DA0, v4, v5);
  if ( !result )
    *(_BYTE *)(this + 16) = 1;
  return result;
}

