// Function: sub_9BBA40
// Address: 0x9bba40
int __thiscall sub_9BBA40(int *this, int a2)
{
  int result; // eax
  int v4; // esi
  int v5; // ebx
  _DWORD *v6; // ecx
  int v7; // eax
  int v8; // edx

  result = 0;
  v4 = *(this + 63);
  v5 = v4;
  if ( v4 > 0 )
  {
    v6 = (_DWORD *)*(this + 65);
    while ( *v6 != a2 )
    {
      ++result;
      ++v6;
      if ( result >= v4 )
        goto LABEL_7;
    }
    v5 = result;
  }
LABEL_7:
  if ( v5 < v4 )
  {
    v7 = *(this + 65);
    v8 = *(_DWORD *)(v7 + 4 * v5);
    *(_DWORD *)(v7 + 4 * v5) = *(_DWORD *)(v7 + 4 * v4 - 4);
    result = *(this + 65);
    *(_DWORD *)(result + 4 * v4 - 4) = v8;
    --*(this + 63);
  }
  return result;
}
