// Function: sub_9889E0
// Address: 0x9889e0
_DWORD *__cdecl sub_9889E0(int a1, int a2)
{
  int v2; // ebx
  int v4; // edi
  bool v5; // zf
  int v6; // ecx
  int v7; // eax
  int v8; // edi
  _DWORD *v9; // ecx
  int i_1; // eax
  int i_2; // edx
  _DWORD *result; // eax
  _DWORD *v13; // [esp+14h] [ebp+8h]
  int i; // [esp+18h] [ebp+Ch]

  v2 = a1;
  v4 = a1 + 40;
  if ( *(_DWORD *)(a1 + 40) )
  {
    do
    {
      sub_9889E0(*(_DWORD *)(v2 + 36), a2);
      v2 = *(_DWORD *)v4;
      v5 = *(_DWORD *)(*(_DWORD *)v4 + 40) == 0;
      v4 = *(_DWORD *)v4 + 40;
    }
    while ( !v5 );
  }
  v6 = *(_DWORD *)(a2 + 8);
  v7 = *(_DWORD *)(a2 + 4);
  if ( v7 == v6 )
  {
    v8 = 2 * v7;
    if ( !v7 )
      v8 = 1;
    if ( v6 < v8 )
    {
      if ( v8 )
      {
        v9 = (_DWORD *)sub_9D4CE0(4 * v8, 16);
        v13 = v9;
      }
      else
      {
        v9 = 0;
        v13 = 0;
      }
      i_1 = *(_DWORD *)(a2 + 4);
      i_2 = 0;
      for ( i = i_1; i_2 < i_1; ++v9 )
      {
        if ( v9 )
        {
          *v9 = *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * i_2);
          i_1 = i;
        }
        ++i_2;
      }
      if ( *(_DWORD *)(a2 + 12) )
      {
        if ( *(_BYTE *)(a2 + 16) )
          sub_9D4D50(*(_DWORD *)(a2 + 12));
        *(_DWORD *)(a2 + 12) = 0;
      }
      *(_BYTE *)(a2 + 16) = 1;
      *(_DWORD *)(a2 + 12) = v13;
      *(_DWORD *)(a2 + 8) = v8;
    }
  }
  result = (_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * *(_DWORD *)(a2 + 4));
  if ( result )
    *result = v2;
  ++*(_DWORD *)(a2 + 4);
  return result;
}
