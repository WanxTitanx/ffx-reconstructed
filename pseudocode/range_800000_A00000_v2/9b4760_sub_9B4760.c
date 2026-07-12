// Function: sub_9B4760
// Address: 0x9b4760
_DWORD *__thiscall sub_9B4760(int this, int a2)
{
  _DWORD *result; // eax
  int v4; // edx
  _DWORD *v5; // edi
  _DWORD *v6; // ecx
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  int v10; // edi
  int v11; // edx
  _DWORD *v12; // ecx
  int v13; // [esp+Ch] [ebp-4h]

  result = 0;
  v4 = *(_DWORD *)(this + 508);
  v5 = (_DWORD *)v4;
  if ( v4 > 0 )
  {
    v6 = *(_DWORD **)(this + 516);
    while ( *v6 != a2 )
    {
      result = (_DWORD *)((char *)result + 1);
      ++v6;
      if ( (int)result >= v4 )
        goto LABEL_7;
    }
    v5 = result;
  }
LABEL_7:
  if ( v5 == (_DWORD *)v4 )
  {
    v7 = *(_DWORD *)(this + 512);
    if ( v4 == v7 )
    {
      v8 = 2 * v4;
      if ( !v4 )
        v8 = 1;
      if ( v7 < v8 )
      {
        if ( v8 )
          v9 = sub_9D4CE0(4 * v8, 16);
        else
          v9 = 0;
        v10 = *(_DWORD *)(this + 508);
        v11 = 0;
        v13 = v9;
        if ( v10 > 0 )
        {
          v12 = (_DWORD *)v9;
          do
          {
            if ( v12 )
              *v12 = *(_DWORD *)(*(_DWORD *)(this + 516) + 4 * v11);
            ++v11;
            ++v12;
          }
          while ( v11 < v10 );
        }
        if ( *(_DWORD *)(this + 516) )
        {
          if ( *(_BYTE *)(this + 520) )
            sub_9D4D50(*(_DWORD *)(this + 516));
          *(_DWORD *)(this + 516) = 0;
        }
        *(_BYTE *)(this + 520) = 1;
        *(_DWORD *)(this + 516) = v13;
        *(_DWORD *)(this + 512) = v8;
      }
    }
    result = (_DWORD *)(*(_DWORD *)(this + 516) + 4 * *(_DWORD *)(this + 508));
    if ( result )
      *result = a2;
    ++*(_DWORD *)(this + 508);
  }
  *(_DWORD *)(this + 264) = 1;
  return result;
}
