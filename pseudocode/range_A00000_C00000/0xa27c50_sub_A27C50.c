// Function: sub_A27C50
// Address: 0xa27c50
// Size: 0x60
// Prototype: int __thiscall(_DWORD)

bool __thiscall sub_A27C50(int this)
{
  bool v2; // bl
  int v3; // eax
  int v5; // [esp+8h] [ebp-4h] BYREF

  v2 = 1;
  v3 = *(_DWORD *)(this + 668);
  if ( v3 && !FMOD::Sound::getOpenState(v3, &v5, 0, 0, 0) )
    v2 = v5 == 0;
  return *(_BYTE *)(this + 340) || *(_DWORD *)(this + 660) && !v2 || sub_A3DDE0(this + 64);
}

