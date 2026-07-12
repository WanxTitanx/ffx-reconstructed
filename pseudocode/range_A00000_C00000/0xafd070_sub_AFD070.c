// Function: sub_AFD070
// Address: 0xafd070
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFD070()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C9B320;
  v1 = (_DWORD *)unk_C9B324;
  *(_DWORD *)(dword_C9B320 + 4) = unk_C9B324;
  *v1 = v0;
  dword_C9B320 = &dword_C9B320;
  unk_C9B324 = &dword_C9B320;
  if ( (unk_C9B330 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C9B32C);
}

