// Function: sub_9BC090
// Address: 0x9bc090
int __thiscall sub_9BC090(int this, int a2)
{
  if ( *(_BYTE *)(this + 245) )
    sub_9D4D50(*(_DWORD *)(this + 176));
  *(_DWORD *)(this + 176) = a2;
  *(_BYTE *)(this + 245) = 0;
  return a2;
}
