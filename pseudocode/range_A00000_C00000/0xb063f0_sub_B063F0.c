// Function: sub_B063F0
// Address: 0xb063f0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B063F0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CC9F6C;
  v1 = (_DWORD *)unk_CC9F70;
  *(_DWORD *)(dword_CC9F6C + 4) = unk_CC9F70;
  *v1 = v0;
  dword_CC9F6C = &dword_CC9F6C;
  unk_CC9F70 = &dword_CC9F6C;
  if ( (unk_CC9F7C & 1) != 0 )
    Phyre_Memory_AlignedFree((int)dword_CC9F78);
}

