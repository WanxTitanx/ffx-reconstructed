// Function: sub_B04960
// Address: 0xb04960
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B04960()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CBDA5C;
  v1 = (_DWORD *)unk_CBDA60;
  *(_DWORD *)(dword_CBDA5C + 4) = unk_CBDA60;
  *v1 = v0;
  dword_CBDA5C = &dword_CBDA5C;
  unk_CBDA60 = &dword_CBDA5C;
  if ( (unk_CBDA6C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CBDA68);
}

