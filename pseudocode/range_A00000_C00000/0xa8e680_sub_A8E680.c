// Function: sub_A8E680
// Address: 0xa8e680
// Size: 0x76
// Prototype: _DWORD __cdecl()

int __thiscall sub_A8E680(int this)
{
  int result; // eax

  result = *(_DWORD *)(this + 12);
  if ( result )
  {
    if ( *(_BYTE *)(this + 16) )
      result = sub_9D4D50(result);
    *(_DWORD *)(this + 12) = 0;
  }
  *(_BYTE *)(this + 16) = 1;
  *(_DWORD *)(this + 12) = 0;
  *(_DWORD *)(this + 4) = 0;
  *(_DWORD *)(this + 8) = 0;
  return result;
}

