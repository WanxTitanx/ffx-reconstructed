// Function: sub_A27EE0
// Address: 0xa27ee0
// Size: 0x35
// Prototype: 

int __stdcall sub_A27EE0(int a1, _WORD *a2, int a3)
{
  int v4; // [esp+0h] [ebp-4h] BYREF

  v4 = 0;
  if ( !((int (__stdcall *)(int, int *))FMOD::Sound::getUserData)(a1, &v4) && v4 )
    sub_A27170(v4, a2, a3);
  return 0;
}

