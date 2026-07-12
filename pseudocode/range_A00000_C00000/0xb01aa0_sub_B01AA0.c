// Function: sub_B01AA0
// Address: 0xb01aa0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B01AA0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAE71C;
  v1 = (_DWORD *)unk_CAE720;
  *(_DWORD *)(dword_CAE71C + 4) = unk_CAE720;
  *v1 = v0;
  dword_CAE71C = &dword_CAE71C;
  unk_CAE720 = &dword_CAE71C;
  if ( (unk_CAE72C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAE728);
}

