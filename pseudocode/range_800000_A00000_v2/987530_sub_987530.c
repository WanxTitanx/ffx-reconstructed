// Function: sub_987530
// Address: 0x987530
int __thiscall sub_987530(int *this, _DWORD *a2, int a3, int a4)
{
  int v5; // edx
  int v6; // eax
  _DWORD *v7; // ecx
  int result; // eax
  int v9; // ecx

  v5 = *(this + 69);
  v6 = 0;
  if ( v5 > 0 )
  {
    v7 = (_DWORD *)*(this + 71);
    while ( *v7 != *a2 )
    {
      ++v6;
      ++v7;
      if ( v6 >= v5 )
        goto LABEL_7;
    }
    v5 = v6;
  }
LABEL_7:
  result = *(this + 69);
  if ( v5 < result )
  {
    v9 = *(this + 71);
    result = *(_DWORD *)(v9 + 4 * result - 4);
    *(_DWORD *)(v9 + 4 * v5) = result;
    --*(this + 69);
  }
  return result;
}
