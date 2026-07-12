// Function: sub_A41750
// Address: 0xa41750
// Size: 0x37
// Prototype: 

_DWORD *__thiscall sub_A41750(_DWORD *this)
{
  _DWORD *v2; // edx
  int v4; // [esp+0h] [ebp-4h]

  v2 = (_DWORD *)FFX_Memory_Alloc_w(0x14u, v4);
  if ( !v2 )
    std::_Xbad_alloc();
  *v2 = *this;
  if ( v2 != (_DWORD *)-4 )
    v2[1] = *this;
  if ( v2 != (_DWORD *)-8 )
    v2[2] = *this;
  return v2;
}

