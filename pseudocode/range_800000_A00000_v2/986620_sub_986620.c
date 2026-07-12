// Function: sub_986620
// Address: 0x986620
_DWORD *__thiscall sub_986620(int this, int *a2, int a3)
{
  int v3; // ebx
  _DWORD *result; // eax
  int v6; // edx
  _DWORD *v7; // edi
  _DWORD *v8; // ecx
  int v9; // eax
  int v10; // edi
  int v11; // eax
  int v12; // ebx
  int v13; // edx
  _DWORD *v14; // ecx
  int v15; // [esp+Ch] [ebp-4h]
  int v16; // [esp+18h] [ebp+8h]

  v3 = *a2;
  result = 0;
  v6 = *(_DWORD *)(this + 276);
  v15 = *a2;
  v7 = (_DWORD *)v6;
  if ( v6 > 0 )
  {
    v8 = *(_DWORD **)(this + 284);
    while ( *v8 != v3 )
    {
      result = (_DWORD *)((char *)result + 1);
      ++v8;
      if ( (int)result >= v6 )
        goto LABEL_7;
    }
    v7 = result;
  }
LABEL_7:
  if ( v7 == (_DWORD *)v6 )
  {
    v9 = *(_DWORD *)(this + 280);
    if ( v6 == v9 )
    {
      v10 = 2 * v6;
      if ( !v6 )
        v10 = 1;
      if ( v9 < v10 )
      {
        if ( v10 )
          v11 = sub_9D4CE0(4 * v10, 16);
        else
          v11 = 0;
        v12 = *(_DWORD *)(this + 276);
        v13 = 0;
        v16 = v11;
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
        v3 = v15;
        *(_BYTE *)(this + 288) = 1;
        *(_DWORD *)(this + 284) = v16;
        *(_DWORD *)(this + 280) = v10;
      }
    }
    result = (_DWORD *)(*(_DWORD *)(this + 284) + 4 * *(_DWORD *)(this + 276));
    if ( result )
      *result = v3;
    ++*(_DWORD *)(this + 276);
  }
  return result;
}
