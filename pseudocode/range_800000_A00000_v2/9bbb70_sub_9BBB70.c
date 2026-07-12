// Function: sub_9BBB70
// Address: 0x9bbb70
int __thiscall sub_9BBB70(int *this, int a2)
{
  int v3; // esi
  int v4; // eax
  int v5; // edx
  _DWORD *v6; // ecx
  int v7; // eax
  int *v8; // ecx
  int v9; // edx

  v3 = *(this + 52);
  v4 = 0;
  v5 = v3;
  if ( v3 > 0 )
  {
    v6 = (_DWORD *)*(this + 54);
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
    v7 = *(this + 54);
    v8 = (int *)(v7 + 4 * v5);
    v9 = *v8;
    *v8 = *(_DWORD *)(v7 + 4 * v3 - 4);
    *(_DWORD *)(*(this + 54) + 4 * v3 - 4) = v9;
    --*(this + 52);
  }
  return sub_985860((int)this, a2);
}
