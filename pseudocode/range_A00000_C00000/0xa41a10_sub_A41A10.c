// Function: sub_A41A10
// Address: 0xa41a10
// Size: 0x85
// Prototype: 

char *__thiscall sub_A41A10(int this, unsigned int n0x3FFFFFFF)
{
  char *v3; // esi
  char *result; // eax
  int v6; // [esp+0h] [ebp-Ch]
  int v7; // [esp+14h] [ebp+8h]

  v3 = 0;
  if ( n0x3FFFFFFF )
  {
    if ( n0x3FFFFFFF > 0x3FFFFFFF || (v3 = (char *)FFX_Memory_Alloc_w(4 * n0x3FFFFFFF, v6)) == 0 )
      std::_Xbad_alloc();
  }
  memmove(v3, *(const void **)this, (*(_DWORD *)(this + 4) - *(_DWORD *)this) & 0xFFFFFFFC);
  v7 = (*(_DWORD *)(this + 4) - *(_DWORD *)this) >> 2;
  if ( *(_DWORD *)this )
    FFX_Memory_Free(*(void **)this);
  std::_Container_base0::_Orphan_all((std::_Container_base0 *)this);
  *(_DWORD *)(this + 8) = &v3[4 * n0x3FFFFFFF];
  *(_DWORD *)this = v3;
  result = &v3[4 * v7];
  *(_DWORD *)(this + 4) = result;
  return result;
}

