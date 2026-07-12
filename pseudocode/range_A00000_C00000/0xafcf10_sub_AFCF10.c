// Function: sub_AFCF10
// Address: 0xafcf10
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFCF10()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C9B208;
  v1 = (_DWORD *)unk_C9B20C;
  *(_DWORD *)(dword_C9B208 + 4) = unk_C9B20C;
  *v1 = v0;
  dword_C9B208 = &dword_C9B208;
  unk_C9B20C = &dword_C9B208;
  if ( (unk_C9B218 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C9B214);
}

