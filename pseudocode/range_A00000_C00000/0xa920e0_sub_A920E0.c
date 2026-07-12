// Function: sub_A920E0
// Address: 0xa920e0
// Size: 0x6d
// Prototype: int __thiscall(_DWORD)

void __thiscall sub_A920E0(int this)
{
  int v2; // esi
  int v3; // edi
  int v4; // ecx

  v2 = *(_DWORD *)(this + 84);
  if ( v2 )
  {
    do
    {
      v3 = *(_DWORD *)(v2 + 4);
      free_1(*(void **)v2);
      *(_QWORD *)v2 = 0;
      free_1((void *)v2);
      v2 = v3;
    }
    while ( v3 );
  }
  v4 = *(_DWORD *)(this + 80);
  if ( v4 )
  {
    *(_DWORD *)(this + 68) = realloc_0(*(void **)(this + 68), v4 + *(_DWORD *)(this + 76));
    *(_DWORD *)(this + 76) += *(_DWORD *)(this + 80);
    *(_DWORD *)(this + 80) = 0;
  }
  *(_DWORD *)(this + 84) = 0;
  *(_DWORD *)(this + 72) = 0;
}

