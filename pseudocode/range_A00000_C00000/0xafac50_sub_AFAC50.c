// Function: sub_AFAC50
// Address: 0xafac50
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFAC50()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C92868;
  v1 = (_DWORD *)unk_C9286C;
  *(_DWORD *)(dword_C92868 + 4) = unk_C9286C;
  *v1 = v0;
  dword_C92868 = &dword_C92868;
  unk_C9286C = &dword_C92868;
  if ( (unk_C92878 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C92874);
}

