// Function: sub_AFA6F0
// Address: 0xafa6f0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFA6F0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C91FB8;
  v1 = (_DWORD *)unk_C91FBC;
  *(_DWORD *)(dword_C91FB8 + 4) = unk_C91FBC;
  *v1 = v0;
  dword_C91FB8 = &dword_C91FB8;
  unk_C91FBC = &dword_C91FB8;
  if ( (unk_C91FC8 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C91FC4);
}

