// Function: sub_9F03C0
// Address: 0x9f03c0
int __thiscall sub_9F03C0(_DWORD *this)
{
  int v2; // ecx
  int n28; // edi
  int v4; // ecx
  int n28_1; // eax
  int v6; // ecx
  int result; // eax
  int v8; // ecx

  v2 = *(this + 8);
  if ( v2 )
    n28 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 4))(v2);
  else
    n28 = 0;
  v4 = *(this + 9);
  if ( v4 )
    n28_1 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 4))(v4);
  else
    n28_1 = 0;
  if ( n28 < 28 )
    *(this + 8) = &off_C6BC94;
  if ( n28_1 < 28 )
    *(this + 9) = &off_C6BC94;
  v6 = *(this + 8);
  if ( v6 )
    result = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 4))(v6);
  else
    result = 0;
  v8 = *(this + 9);
  *(this + 6) = result;
  if ( v8 )
  {
    result = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 4))(v8);
    *(this + 7) = result;
  }
  else
  {
    *(this + 7) = 0;
  }
  return result;
}
