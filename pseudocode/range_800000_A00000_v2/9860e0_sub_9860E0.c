// Function: sub_9860E0
// Address: 0x9860e0
void __thiscall sub_9860E0(int this)
{
  int i; // esi
  int v3; // ecx
  int n2; // eax

  for ( i = 0; i < *(_DWORD *)(this + 8); ++i )
  {
    v3 = *(_DWORD *)(*(_DWORD *)(this + 16) + 4 * i);
    if ( !*(_BYTE *)(this + 88) )
    {
      n2 = *(_DWORD *)(v3 + 228);
      if ( n2 == 2 || n2 == 5 )
        continue;
    }
    sub_986120(v3);
  }
}
