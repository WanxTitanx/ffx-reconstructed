// Function: sub_AFB390
// Address: 0xafb390
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFB390()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C9451C;
  v1 = (_DWORD *)unk_C94520;
  *(_DWORD *)(dword_C9451C + 4) = unk_C94520;
  *v1 = v0;
  dword_C9451C = &dword_C9451C;
  unk_C94520 = &dword_C9451C;
  if ( (unk_C9452C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C94528);
}

