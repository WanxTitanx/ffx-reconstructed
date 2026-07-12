// Function: sub_9B7A30
// Address: 0x9b7a30
void __thiscall sub_9B7A30(_DWORD *this)
{
  int i; // esi
  int n2; // eax

  for ( i = 0; i < *(this + 52); ++i )
  {
    n2 = *(_DWORD *)(*(_DWORD *)(*(this + 54) + 4 * i) + 228);
    if ( n2 != 2 && n2 != 5 )
      sub_9B4D20();
  }
}
