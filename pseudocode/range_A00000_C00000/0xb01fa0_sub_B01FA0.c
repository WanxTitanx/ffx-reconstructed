// Function: sub_B01FA0
// Address: 0xb01fa0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B01FA0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAEF24;
  v1 = (_DWORD *)unk_CAEF28;
  *(_DWORD *)(dword_CAEF24 + 4) = unk_CAEF28;
  *v1 = v0;
  dword_CAEF24 = &dword_CAEF24;
  unk_CAEF28 = &dword_CAEF24;
  if ( (unk_CAEF34 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAEF30);
}

