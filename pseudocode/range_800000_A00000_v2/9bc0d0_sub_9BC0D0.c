// Function: sub_9BC0D0
// Address: 0x9bc0d0
int __thiscall sub_9BC0D0(_DWORD *this, _DWORD *a2)
{
  int v3; // esi
  int n2; // eax
  int v5; // ecx

  v3 = 0;
  *(this + 56) = *a2;
  *(this + 57) = a2[1];
  *(this + 58) = a2[2];
  n2 = a2[3];
  for ( *(this + 59) = n2; v3 < *(this + 52); ++v3 )
  {
    v5 = *(_DWORD *)(*(this + 54) + 4 * v3);
    n2 = *(_DWORD *)(v5 + 228);
    if ( n2 != 2 && n2 != 5 && (*(_BYTE *)(v5 + 524) & 1) == 0 )
      n2 = sub_9B5C70(v5, (int)a2);
  }
  return n2;
}
