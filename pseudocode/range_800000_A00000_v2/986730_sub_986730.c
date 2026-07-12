// Function: sub_986730
// Address: 0x986730
int __thiscall sub_986730(int this, int *a2, int a3)
{
  int v4; // edx
  int v5; // ebx
  int result; // eax
  int v7; // edi
  _DWORD *v8; // ecx
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  int v12; // edi
  int v13; // edx
  _DWORD *v14; // ecx
  _DWORD *v15; // eax
  int v16; // [esp+Ch] [ebp-8h]
  int v17; // [esp+10h] [ebp-4h]

  if ( !a3 )
    a3 = *(_DWORD *)(this + 200);
  v4 = *(_DWORD *)(this + 276);
  v5 = *a2;
  result = 0;
  v16 = *a2;
  v7 = v4;
  if ( v4 > 0 )
  {
    v8 = *(_DWORD **)(this + 284);
    while ( *v8 != v5 )
    {
      ++result;
      ++v8;
      if ( result >= v4 )
        goto LABEL_9;
    }
    v7 = result;
  }
LABEL_9:
  if ( v7 == v4 )
  {
    v9 = *(_DWORD *)(this + 280);
    if ( v4 == v9 )
    {
      v10 = 2 * v4;
      if ( !v4 )
        v10 = 1;
      if ( v9 < v10 )
      {
        if ( v10 )
          v11 = sub_9D4CE0(4 * v10, 16);
        else
          v11 = 0;
        v12 = *(_DWORD *)(this + 276);
        v13 = 0;
        v17 = v11;
        if ( v12 > 0 )
        {
          v14 = (_DWORD *)v11;
          do
          {
            if ( v14 )
              *v14 = *(_DWORD *)(*(_DWORD *)(this + 284) + 4 * v13);
            ++v13;
            ++v14;
          }
          while ( v13 < v12 );
        }
        if ( *(_DWORD *)(this + 284) )
        {
          if ( *(_BYTE *)(this + 288) )
            sub_9D4D50(*(_DWORD *)(this + 284));
          *(_DWORD *)(this + 284) = 0;
        }
        *(_BYTE *)(this + 288) = 1;
        *(_DWORD *)(this + 284) = v17;
        *(_DWORD *)(this + 280) = v10;
      }
      v5 = v16;
    }
    v15 = (_DWORD *)(*(_DWORD *)(this + 284) + 4 * *(_DWORD *)(this + 276));
    if ( v15 )
      *v15 = v5;
    ++*(_DWORD *)(this + 276);
    return (*(int (__thiscall **)(_DWORD, int, int *))(**(_DWORD **)(this + 304) + 4))(*(_DWORD *)(this + 304), a3, a2);
  }
  return result;
}
