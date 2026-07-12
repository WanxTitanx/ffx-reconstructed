// Function: sub_9B5490
// Address: 0x9b5490
BOOL __thiscall sub_9B5490(int *this, int a2)
{
  int v3; // eax
  int v4; // esi
  int v5; // ebx
  _DWORD *v6; // ecx
  int v7; // eax
  int v8; // edx
  BOOL result; // eax

  v3 = 0;
  v4 = *(this + 127);
  v5 = v4;
  if ( v4 > 0 )
  {
    v6 = (_DWORD *)*(this + 129);
    while ( *v6 != a2 )
    {
      ++v3;
      ++v6;
      if ( v3 >= v4 )
        goto LABEL_7;
    }
    v5 = v3;
  }
LABEL_7:
  if ( v5 < v4 )
  {
    v7 = *(this + 129);
    v8 = *(_DWORD *)(v7 + 4 * v5);
    *(_DWORD *)(v7 + 4 * v5) = *(_DWORD *)(v7 + 4 * v4 - 4);
    *(_DWORD *)(*(this + 129) + 4 * v4 - 4) = v8;
    --*(this + 127);
  }
  result = *(this + 127) > 0;
  *(this + 66) = result;
  return result;
}
