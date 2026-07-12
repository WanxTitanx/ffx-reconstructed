// Function: sub_A25860
// Address: 0xa25860
// Size: 0x56
// Prototype: 

int __thiscall sub_A25860(int (__stdcall **this)(_DWORD), int a2, int a3, _DWORD *a4, _DWORD *a5)
{
  int v5; // edi

  if ( !a2 )
    return 0;
  *a5 += 4;
  v5 = (*(this + 1))(*(_DWORD *)(*a5 - 4));
  if ( !a4 || a3 != ((unsigned int)Phyre_GetGlobalTypeAccessor() | 1) )
    return 0;
  a4[1] = v5;
  *a4 = 0;
  return 1;
}

