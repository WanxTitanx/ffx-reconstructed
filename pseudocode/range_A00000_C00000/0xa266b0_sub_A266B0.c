// Function: sub_A266B0
// Address: 0xa266b0
// Size: 0x139
// Prototype: 

_DWORD *__thiscall sub_A266B0(int *this, int a2, _BYTE *a3, int a4)
{
  _BYTE *v4; // edx
  char v5; // bl
  int i; // esi
  int v7; // eax
  int v9; // esi
  unsigned int v10; // edx
  unsigned int v11; // ecx
  _BYTE *v12; // eax
  _DWORD *result; // eax
  _DWORD *v14; // edx
  int v15; // ecx
  _DWORD *v16; // edi
  int v17; // eax
  _DWORD *v18; // ecx
  _DWORD *v19; // ecx
  int v20; // ecx
  int v21; // edx
  int v22; // [esp+Ch] [ebp-18h]
  int v23; // [esp+1Ch] [ebp-8h]
  int v24; // [esp+20h] [ebp-4h]
  int v25; // [esp+30h] [ebp+Ch]

  v4 = a3;
  v5 = *a3;
  for ( i = 5381; v5; i = v7 + 33 * i )
  {
    v7 = v5;
    v5 = *++v4;
  }
  v9 = i & 0x7FFFFFFF;
  v10 = 0;
  v11 = *(this + 4) & 0x7FFFFFFF;
  if ( v11 )
  {
    v12 = (_BYTE *)*(this + 5);
    while ( *v12 )
    {
      ++v10;
      v12 += 16;
      if ( v10 >= v11 )
        goto LABEL_7;
    }
    v21 = 2 * v10;
    *(_DWORD *)(*(this + 5) + 8 * v21 + 4) = v9;
    *(_DWORD *)(*(this + 5) + 8 * v21 + 8) = a4;
    *(_BYTE *)(*(this + 5) + 8 * v21) = 1;
    *(_DWORD *)(*(this + 5) + 8 * v21 + 12) = a2;
    return (_DWORD *)a2;
  }
  else
  {
LABEL_7:
    LOBYTE(v22) = 1;
    result = (_DWORD *)sub_42FC60(16 * (v11 + 1), 4);
    v23 = (int)result;
    if ( result )
    {
      v14 = (_DWORD *)*(this + 5);
      v15 = *(this + 4) & 0x7FFFFFFF;
      v24 = v15;
      v16 = result;
      if ( v15 )
      {
        v17 = *(this + 4) & 0x7FFFFFFF;
        v25 = v17;
        do
        {
          v18 = v16;
          v16 += 4;
          if ( v18 )
          {
            *v18 = *v14;
            v18[1] = v14[1];
            v18[2] = v14[2];
            v18[3] = v14[3];
            v17 = v25;
            v14 += 4;
          }
          v25 = --v17;
        }
        while ( v17 );
        v15 = v24;
      }
      v19 = (_DWORD *)(v23 + 16 * v15);
      if ( v19 )
      {
        *v19 = v22;
        v19[1] = v9;
        v19[2] = a4;
        v19[3] = a2;
      }
      v20 = *(this + 5);
      if ( v20 != v23 && *(this + 4) >= 0 )
      {
        if ( v20 )
          Phyre_Memory_AlignedFree(*(this + 5));
      }
      *(this + 5) = v23;
      *(this + 4) = v24 + 1;
      return (_DWORD *)(v24 + 1);
    }
  }
  return result;
}

