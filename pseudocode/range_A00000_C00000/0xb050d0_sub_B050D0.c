// Function: sub_B050D0
// Address: 0xb050d0
// Size: 0x8d
// Prototype: void __cdecl()

void __cdecl sub_B050D0()
{
  if ( dword_CC142C >= 0 && dword_CC1430 )
    Phyre_Memory_AlignedFree(dword_CC1430);
  dword_CC1430 = 0;
  dword_CC142C = 0;
  `eh vector destructor iterator'(&unk_CC13EC, 0x20u, 2, sub_5E2020);
  p____7btIDebugDraw__6B_ = &btIDebugDraw::`vftable';
}

