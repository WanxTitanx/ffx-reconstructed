// Function: sub_9BCA40
// Address: 0x9bca40
int __thiscall sub_9BCA40(_DWORD *this, float a2)
{
  int v3; // esi
  double v4; // st7
  int v5; // ecx
  int result; // eax
  float v7; // [esp+0h] [ebp-Ch]

  v3 = 0;
  if ( (int)*(this + 63) > 0 )
  {
    v4 = a2;
    do
    {
      v5 = *(_DWORD *)(*(this + 65) + 4 * v3);
      v7 = v4;
      result = (*(int (__thiscall **)(int, _DWORD *, _DWORD))(*(_DWORD *)v5 + 4))(v5, this, LODWORD(v7));
      v4 = a2;
      ++v3;
    }
    while ( v3 < *(this + 63) );
  }
  return result;
}
