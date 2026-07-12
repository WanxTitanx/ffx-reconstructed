// Function: sub_A295A0
// Address: 0xa295a0
// Size: 0xfb
// Prototype: 

int __thiscall sub_A295A0(int *this)
{
  int v2; // ecx

  sub_495AE0();
  v2 = *(this + 89);
  if ( v2 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 8))(v2);
  if ( *(this + 87) >= 0 && *(this + 88) )
    Phyre_Memory_AlignedFree(*(this + 88));
  *(this + 88) = 0;
  *(this + 87) = 0;
  sub_4F2DB0();
  sub_55E1E0();
  sub_433A00(this + 24);
  if ( *(this + 16) >= 0 && *(this + 17) )
    Phyre_Memory_AlignedFree(*(this + 17));
  *(this + 17) = 0;
  *(this + 16) = 0;
  return sub_433BF0();
}

