// Function: sub_A1A100
// Address: 0xa1a100
// Size: 0x86
// Prototype: 

int __thiscall sub_A1A100(int *this, _DWORD *a2, _DWORD *a3)
{
  int v3; // edi
  int v6; // eax
  _DWORD *v7; // esi
  _DWORD *v8; // ecx
  int v9; // edi
  _DWORD *v10; // edx
  _DWORD *v11; // ecx
  int v12; // [esp+8h] [ebp-4h]

  v3 = (int)a2;
  if ( !a2 )
    return 13;
  v6 = *this & 0x7FFFFFFF;
  v7 = (_DWORD *)*(this + 1);
  v12 = v6;
  v8 = a2;
  if ( v6 )
  {
    v9 = v6;
    do
    {
      v10 = v8++;
      if ( v10 )
        *v10 = *v7++;
      --v9;
    }
    while ( v9 );
    v3 = (int)a2;
  }
  v11 = (_DWORD *)(v3 + 4 * v6);
  if ( v11 )
    *v11 = *a3;
  if ( *(this + 1) != v3 && *this >= 0 )
    Phyre_Memory_AlignedFree(*(this + 1));
  *(this + 1) = v3;
  *this = v12 + 1;
  return 0;
}

