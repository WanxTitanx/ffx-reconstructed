// Function: sub_A258C0
// Address: 0xa258c0
// Size: 0x4a
// Prototype: 

int __thiscall sub_A258C0(int (__stdcall **this)(_DWORD), int a2, void *a3, _DWORD *a4, _DWORD *a5)
{
  int v5; // eax

  if ( !a2 )
    return 0;
  *a5 += 4;
  v5 = (*(this + 1))(*(_DWORD *)(*a5 - 4));
  if ( !a4 || a3 != &unk_C90761 )
    return 0;
  *a4 = 0;
  a4[1] = v5;
  return 1;
}

