// Function: sub_A1B7B0
// Address: 0xa1b7b0
// Size: 0x2f
// Prototype: 

int __thiscall sub_A1B7B0(_DWORD *this)
{
  _DWORD *v2; // eax
  int v3; // eax
  int result; // eax

  v2 = (_DWORD *)*(this + 2);
  if ( !v2 || !*v2 || (v3 = sub_A161B0(), (result = sub_A1A830(&unk_1943DA0, v3)) == 0) )
  {
    *(this + 3) = *(this + 2);
    return 0;
  }
  return result;
}

