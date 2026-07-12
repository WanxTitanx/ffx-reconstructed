// Function: sub_AFA930
// Address: 0xafa930
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFA930()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C921CC;
  v1 = (_DWORD *)unk_C921D0;
  *(_DWORD *)(dword_C921CC + 4) = unk_C921D0;
  *v1 = v0;
  dword_C921CC = &dword_C921CC;
  unk_C921D0 = &dword_C921CC;
  if ( (unk_C921DC & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C921D8);
}

