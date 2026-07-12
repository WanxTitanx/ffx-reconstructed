// Function: sub_AFA070
// Address: 0xafa070
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFA070()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = unk_C907FC;
  v1 = (_DWORD *)unk_C90800;
  *(_DWORD *)(unk_C907FC + 4) = unk_C90800;
  *v1 = v0;
  unk_C907FC = &unk_C907FC;
  unk_C90800 = &unk_C907FC;
  if ( (unk_C9080C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C90808);
}

