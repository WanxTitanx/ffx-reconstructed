// Function: sub_9BC560
// Address: 0x9bc560
void __thiscall sub_9BC560(int this)
{
  int v2; // edi
  int n2; // eax

  v2 = 0;
  if ( *(_BYTE *)(this + 246) )
  {
    if ( *(int *)(this + 8) > 0 )
    {
      do
      {
        if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 16) + 4 * v2) + 244) & 2) != 0 )
          sub_9BC5E0(*(_DWORD *)(*(_DWORD *)(this + 16) + 4 * v2));
        ++v2;
      }
      while ( v2 < *(_DWORD *)(this + 8) );
    }
  }
  else if ( *(int *)(this + 208) > 0 )
  {
    do
    {
      n2 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 216) + 4 * v2) + 228);
      if ( n2 != 2 && n2 != 5 )
        sub_9BC5E0(*(_DWORD *)(*(_DWORD *)(this + 216) + 4 * v2));
      ++v2;
    }
    while ( v2 < *(_DWORD *)(this + 208) );
  }
}
