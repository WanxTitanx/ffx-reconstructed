// Function: sub_A8EA20
// Address: 0xa8ea20
// Size: 0x32
// Prototype: _DWORD __stdcall(int i)

int __thiscall sub_A8EA20(_DWORD *this, int i)
{
  int i_1; // eax

  sub_A8E7B0((int)this, i);
  for ( i_1 = 0; i_1 < i; *(_DWORD *)(*(this + 3) + 8 * i_1 - 4) = 1 )
  {
    *(_DWORD *)(*(this + 3) + 8 * i_1) = i_1;
    ++i_1;
  }
  return i_1;
}

