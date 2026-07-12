// Function: sub_AFB2D0
// Address: 0xafb2d0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFB2D0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C9495C;
  v1 = (_DWORD *)unk_C94960;
  *(_DWORD *)(dword_C9495C + 4) = unk_C94960;
  *v1 = v0;
  dword_C9495C = &dword_C9495C;
  unk_C94960 = &dword_C9495C;
  if ( (unk_C9496C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C94968);
}

