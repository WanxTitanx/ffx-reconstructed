// Function: sub_9BC670
// Address: 0x9bc670
int __thiscall sub_9BC670(_DWORD *this, int a2, int a3)
{
  int v3; // edi
  int v5; // edx
  int v6; // ecx
  _DWORD *v7; // edx
  _DWORD *v8; // ecx
  int v9; // ecx
  int result; // eax
  int v11; // edx
  int v12; // ecx
  _DWORD *v13; // edx
  _DWORD *v14; // ecx
  int v15; // eax
  int v16; // ecx

  v3 = a2;
  v5 = 8 * a2;
  if ( a2 != *(_DWORD *)(8 * a2 + *(this + 3)) )
  {
    do
    {
      v6 = *(this + 3);
      v7 = (_DWORD *)(v6 + v5);
      v8 = (_DWORD *)(v6 + 8 * *v7);
      *v7 = *v8;
      v3 = *v8;
      v5 = 8 * *v8;
    }
    while ( *v8 != *(_DWORD *)(v5 + *(this + 3)) );
  }
  v9 = a3;
  result = *(this + 3);
  v11 = 8 * a3;
  if ( a3 != *(_DWORD *)(8 * a3 + result) )
  {
    do
    {
      v12 = *(this + 3);
      v13 = (_DWORD *)(v12 + v11);
      v14 = (_DWORD *)(v12 + 8 * *v13);
      *v13 = *v14;
      v9 = *v14;
      result = *(this + 3);
      v11 = 8 * v9;
    }
    while ( v9 != *(_DWORD *)(8 * v9 + result) );
  }
  if ( v3 != v9 )
  {
    *(_DWORD *)(*(this + 3) + 8 * v3) = v9;
    v15 = *(this + 3);
    v16 = v15 + 8 * v9;
    result = *(_DWORD *)(v15 + 8 * v3 + 4);
    *(_DWORD *)(v16 + 4) += result;
  }
  return result;
}
