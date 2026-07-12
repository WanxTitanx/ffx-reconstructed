// Function: sub_93C060
// Address: 0x93c060
int __cdecl sub_93C060(int *a1, _DWORD *a2)
{
  int v2; // esi
  int v3; // eax
  int n2; // esi
  int v5; // esi

  v2 = sub_849AE0(*(_DWORD *)(unk_193C0F0 + 3048));
  v3 = sub_849AF0(*(_DWORD *)(unk_193C0F0 + 3048));
  if ( a1 )
  {
    n2 = v2 - *(_DWORD *)(unk_193C0F0 + 3060);
    *a1 = n2;
    if ( n2 < 2 )
      *a1 = n2 > -2 ? 0 : *a1;
  }
  if ( a2 )
    *a2 = v3 - *(_DWORD *)(unk_193C0F0 + 3064);
  v5 = sub_84A920(*(_DWORD *)(unk_193C0F0 + 3060), *(_DWORD *)(unk_193C0F0 + 3064), 0, 0, 0, nullsub_185);
  sub_849B90(v5);
  return sub_84AB80(v5);
}
