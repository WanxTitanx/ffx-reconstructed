// Function: sub_9B4DF0
// Address: 0x9b4df0
char __thiscall sub_9B4DF0(int *this, int a2)
{
  int v3; // edi
  int v4; // eax
  int i; // ecx

  if ( (*(_BYTE *)(a2 + 244) & 2) == 0 )
    return 1;
  v3 = *(this + 127);
  v4 = 0;
  if ( v3 <= 0 )
    return 1;
  for ( i = *(this + 129); *(_DWORD *)(*(_DWORD *)i + 20) != a2 && *(_DWORD *)(*(_DWORD *)i + 24) != a2; i += 4 )
  {
    if ( ++v4 >= v3 )
      return 1;
  }
  return 0;
}
