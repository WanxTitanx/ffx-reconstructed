// Function: sub_9BBAF0
// Address: 0x9bbaf0
BOOL __thiscall sub_9BBAF0(int *this, int a2)
{
  int v3; // edi
  int v4; // eax
  int v5; // edx
  _DWORD *v6; // ecx
  int v7; // eax
  int *v8; // ecx
  int v9; // edx

  v3 = *(this + 47);
  v4 = 0;
  v5 = v3;
  if ( v3 > 0 )
  {
    v6 = (_DWORD *)*(this + 49);
    while ( *v6 != a2 )
    {
      ++v4;
      ++v6;
      if ( v4 >= v3 )
        goto LABEL_7;
    }
    v5 = v4;
  }
LABEL_7:
  if ( v5 < v3 )
  {
    v7 = *(this + 49);
    v8 = (int *)(v7 + 4 * v5);
    v9 = *v8;
    *v8 = *(_DWORD *)(v7 + 4 * v3 - 4);
    *(_DWORD *)(*(this + 49) + 4 * v3 - 4) = v9;
    --*(this + 47);
  }
  sub_9B5490(*(int **)(a2 + 20), a2);
  return sub_9B5490(*(int **)(a2 + 24), a2);
}
