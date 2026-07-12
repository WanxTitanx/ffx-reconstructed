// Function: sub_98B980
// Address: 0x98b980
int __thiscall sub_98B980(_DWORD *this, _DWORD *a2)
{
  _DWORD *v2; // esi

  v2 = (_DWORD *)*(this + 12);
  v2[4] = *a2;
  v2[5] = a2[1];
  v2[6] = a2[2];
  v2[7] = a2[3];
  return sub_98B8C0(this);
}
