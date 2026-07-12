// Function: sub_B063B0
// Address: 0xb063b0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B063B0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CCA2DC;
  v1 = (_DWORD *)unk_CCA2E0;
  *(_DWORD *)(dword_CCA2DC + 4) = unk_CCA2E0;
  *v1 = v0;
  dword_CCA2DC = &dword_CCA2DC;
  unk_CCA2E0 = &dword_CCA2DC;
  if ( (unk_CCA2EC & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CCA2E8);
}

