// Function: sub_AFB550
// Address: 0xafb550
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFB550()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C9490C;
  v1 = (_DWORD *)unk_C94910;
  *(_DWORD *)(dword_C9490C + 4) = unk_C94910;
  *v1 = v0;
  dword_C9490C = &dword_C9490C;
  unk_C94910 = &dword_C9490C;
  if ( (unk_C9491C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C94918);
}

