// Function: sub_9F0350
// Address: 0x9f0350
int __thiscall sub_9F0350(_DWORD *this)
{
  int v2; // ecx
  int n26; // edi
  int v4; // ecx
  int n26_1; // eax
  int v6; // ecx
  int result; // eax
  int v8; // ecx

  v2 = *(this + 8);
  if ( v2 )
    n26 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 4))(v2);
  else
    n26 = 0;
  v4 = *(this + 9);
  if ( v4 )
    n26_1 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 4))(v4);
  else
    n26_1 = 0;
  if ( n26 > 26 )
    *(this + 8) = &off_C6B884;
  if ( n26_1 > 26 )
    *(this + 9) = &off_C6B884;
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
