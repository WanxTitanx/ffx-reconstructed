// Function: sub_98E340
// Address: 0x98e340
int __thiscall sub_98E340(int this, int a2, int a3, int a4)
{
  if ( *(_DWORD *)(this + 12) )
  {
    if ( *(_BYTE *)(this + 16) )
      sub_9D4D50(*(_DWORD *)(this + 12));
    *(_DWORD *)(this + 12) = 0;
  }
  *(_DWORD *)(this + 12) = a2;
  *(_DWORD *)(this + 4) = a3;
  *(_BYTE *)(this + 16) = 0;
  *(_DWORD *)(this + 8) = a4;
  return a4;
}
