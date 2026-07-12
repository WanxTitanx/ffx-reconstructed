// Function: sub_A3DDC0
// Address: 0xa3ddc0
// Size: 0x1f
// Prototype: int __thiscall(_DWORD *this)

int __thiscall sub_A3DDC0(HANDLE *this)
{
  char *v1; // edx
  int result; // eax

  v1 = (char *)*(this + 5);
  *(this + 13) = (char *)*(this + 13) + 1;
  *(this + 2) = v1;
  if ( *(this + 3) > v1 )
    v1 = &v1[(_DWORD)*(this + 12)];
  if ( *(this + 4) < v1 )
    return PhyreEvent_Set(this + 7);
  return result;
}

