// Function: sub_B00990
// Address: 0xb00990
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B00990()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAB02C;
  v1 = (_DWORD *)unk_CAB030;
  *(_DWORD *)(dword_CAB02C + 4) = unk_CAB030;
  *v1 = v0;
  dword_CAB02C = &dword_CAB02C;
  unk_CAB030 = &dword_CAB02C;
  if ( (unk_CAB03C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAB038);
}

