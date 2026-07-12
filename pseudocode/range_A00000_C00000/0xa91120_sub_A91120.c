// Function: sub_A91120
// Address: 0xa91120
// Size: 0x7a
// Prototype: int __thiscall(_DWORD)

int __thiscall sub_A91120(_DWORD *this)
{
  int v1; // edi
  int v2; // eax
  int v4; // edx
  int v5; // eax
  int v6; // edx

  v1 = *(this + 26);
  v2 = *(this + 1);
  if ( !v1 )
    return -1;
  if ( !v2 )
    return -1;
  v4 = *(_DWORD *)(v2 + 28);
  if ( !v4 )
    return -1;
  v5 = *(_DWORD *)(v4 + 3656);
  v6 = *(int *)(v4 + 4) >> (v5 + 1);
  *(this + 6) = -1;
  *(this + 14) = -1;
  *(this + 12) = v6;
  *(this + 15) = -1;
  *(this + 16) = -1;
  *(this + 17) = -1;
  *(this + 5) = v6 >> v5;
  *(this + 8) = 0;
  *(_DWORD *)(v1 + 128) = -1;
  *(_DWORD *)(v1 + 132) = -1;
  return 0;
}

