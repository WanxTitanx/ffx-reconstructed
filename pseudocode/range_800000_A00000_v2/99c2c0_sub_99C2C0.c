// Function: sub_99C2C0
// Address: 0x99c2c0
int __thiscall sub_99C2C0(int this)
{
  int v2; // esi
  int v3; // ebx
  int result; // eax
  void (__thiscall ***v5)(_DWORD, _DWORD); // ecx

  v2 = 0;
  v3 = *(_DWORD *)(this + 12);
  if ( v3 > 0 )
  {
    do
    {
      result = *(_DWORD *)(this + 20);
      v5 = *(void (__thiscall ****)(_DWORD, _DWORD))(result + 4 * v2);
      if ( v5 )
      {
        (**v5)(v5, 0);
        result = (*(int (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(this + 4) + 48))(
                   *(_DWORD *)(this + 4),
                   *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * v2));
      }
      ++v2;
    }
    while ( v2 < v3 );
  }
  return result;
}
