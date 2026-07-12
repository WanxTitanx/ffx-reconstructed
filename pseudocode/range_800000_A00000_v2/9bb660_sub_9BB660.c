// Function: sub_9BB660
// Address: 0x9bb660
_DWORD *__thiscall sub_9BB660(int this)
{
  int v2; // edx
  int v3; // edi
  _DWORD *result; // eax
  int v5; // edi
  int v6; // ecx
  int v7; // edi
  int v8; // ecx
  int v9; // edi
  int v10; // ecx

  v2 = *(_DWORD *)(this + 76);
  v3 = *(_DWORD *)(this + 56);
  result = (_DWORD *)(v3 + v2);
  if ( v3 + v2 > 0 )
    result = (_DWORD *)(*(int (__thiscall **)(_DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, int, _DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(this + 8) + 8))(
                         *(_DWORD *)(this + 8),
                         *(_DWORD *)(this + 44),
                         *(_DWORD *)(this + 36),
                         *(_DWORD *)(this + 64),
                         v3,
                         *(_DWORD *)(this + 84),
                         v2,
                         *(_DWORD *)(this + 4),
                         *(_DWORD *)(this + 20),
                         *(_DWORD *)(this + 24),
                         *(_DWORD *)(this + 28));
  v5 = *(_DWORD *)(this + 36);
  if ( v5 < 0 )
  {
    if ( *(int *)(this + 40) < 0 )
    {
      if ( *(_DWORD *)(this + 44) )
      {
        if ( *(_BYTE *)(this + 48) )
          sub_9D4D50(*(_DWORD *)(this + 44));
        *(_DWORD *)(this + 44) = 0;
      }
      *(_BYTE *)(this + 48) = 1;
      *(_DWORD *)(this + 44) = 0;
      *(_DWORD *)(this + 40) = 0;
    }
    v6 = 4 * v5;
    do
    {
      result = (_DWORD *)(v6 + *(_DWORD *)(this + 44));
      if ( result )
        *result = 0;
      v6 += 4;
    }
    while ( v6 < 0 );
  }
  *(_DWORD *)(this + 36) = 0;
  v7 = *(_DWORD *)(this + 56);
  if ( v7 < 0 )
  {
    if ( *(int *)(this + 60) < 0 )
    {
      if ( *(_DWORD *)(this + 64) )
      {
        if ( *(_BYTE *)(this + 68) )
          sub_9D4D50(*(_DWORD *)(this + 64));
        *(_DWORD *)(this + 64) = 0;
      }
      *(_BYTE *)(this + 68) = 1;
      *(_DWORD *)(this + 64) = 0;
      *(_DWORD *)(this + 60) = 0;
    }
    v8 = 4 * v7;
    do
    {
      result = (_DWORD *)(v8 + *(_DWORD *)(this + 64));
      if ( result )
        *result = 0;
      v8 += 4;
    }
    while ( v8 < 0 );
  }
  *(_DWORD *)(this + 56) = 0;
  v9 = *(_DWORD *)(this + 76);
  if ( v9 < 0 )
  {
    if ( *(int *)(this + 80) < 0 )
    {
      if ( *(_DWORD *)(this + 84) )
      {
        if ( *(_BYTE *)(this + 88) )
          sub_9D4D50(*(_DWORD *)(this + 84));
        *(_DWORD *)(this + 84) = 0;
      }
      *(_BYTE *)(this + 88) = 1;
      *(_DWORD *)(this + 84) = 0;
      *(_DWORD *)(this + 80) = 0;
    }
    v10 = 4 * v9;
    do
    {
      result = (_DWORD *)(v10 + *(_DWORD *)(this + 84));
      if ( result )
        *result = 0;
      v10 += 4;
    }
    while ( v10 < 0 );
  }
  *(_DWORD *)(this + 76) = 0;
  return result;
}
