// Function: sub_A423C0
// Address: 0xa423c0
// Size: 0xc5
// Prototype: 

_DWORD *__thiscall sub_A423C0(_DWORD *this, _DWORD *a2, _DWORD *a3, int a4, int a5)
{
  unsigned int i; // ebx
  _DWORD *result; // eax
  unsigned int v9; // edi
  _DWORD *v10; // esi
  unsigned __int8 *v11; // edi
  int v12; // ebx
  bool v13; // zf
  int v14; // eax
  int v15; // eax
  _DWORD *this_1; // [esp+Ch] [ebp-4h]
  int v17; // [esp+1Ch] [ebp+Ch]

  this_1 = this;
  for ( i = 0; i < 0x10; ++i )
  {
    result = (_DWORD *)*(this + i + 16);
    v9 = 0;
    if ( *(this + i) )
    {
      do
      {
        *a2 = result[2];
        a2[1] = result[3];
        *a3 = *result;
        a3[1] = result[1];
        this = this_1;
        ++v9;
        a2 += 2;
        a3 += 2;
        result += 4;
      }
      while ( v9 < this_1[i] );
    }
  }
  v10 = (_DWORD *)this_1[49];
  v11 = (unsigned __int8 *)this_1[51];
  if ( a5 )
  {
    v12 = a4 + 8;
    v17 = a4 - (_DWORD)v10 - 8;
    do
    {
      v13 = a5-- == 1;
      v12 += 12;
      v14 = *(_DWORD *)(this_1[*v11 + 32] + 4 * *v10);
      v10 += 3;
      *(_DWORD *)((char *)v10 + v17 - 4) = v14;
      v15 = this_1[v11[1] + 32];
      v11 += 3;
      *(_DWORD *)(v12 - 16) = *(_DWORD *)(v15 + 4 * *(v10 - 2));
      result = *(_DWORD **)(this_1[*(v11 - 1) + 32] + 4 * *(v10 - 1));
      *(_DWORD *)(v12 - 12) = result;
    }
    while ( !v13 );
  }
  return result;
}

