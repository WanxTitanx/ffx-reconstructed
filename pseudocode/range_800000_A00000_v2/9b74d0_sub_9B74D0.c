// Function: sub_9B74D0
// Address: 0x9b74d0
_DWORD *__thiscall sub_9B74D0(int this, int a2, char a3)
{
  int v4; // eax
  int v5; // edi
  int v6; // edi
  int v7; // eax
  int v8; // ebx
  int v9; // edx
  _DWORD *v10; // ecx
  _DWORD *result; // eax
  int v12; // [esp+8h] [ebp-4h]

  v4 = *(_DWORD *)(this + 192);
  v5 = *(_DWORD *)(this + 188);
  if ( v5 == v4 )
  {
    v6 = v5 ? 2 * v5 : 1;
    if ( v4 < v6 )
    {
      if ( v6 )
        v7 = sub_9D4CE0(4 * v6, 16);
      else
        v7 = 0;
      v8 = *(_DWORD *)(this + 188);
      v9 = 0;
      v12 = v7;
      if ( v8 > 0 )
      {
        v10 = (_DWORD *)v7;
        do
        {
          if ( v10 )
            *v10 = *(_DWORD *)(*(_DWORD *)(this + 196) + 4 * v9);
          ++v9;
          ++v10;
        }
        while ( v9 < v8 );
      }
      if ( *(_DWORD *)(this + 196) )
      {
        if ( *(_BYTE *)(this + 200) )
          sub_9D4D50(*(_DWORD *)(this + 196));
        *(_DWORD *)(this + 196) = 0;
      }
      *(_BYTE *)(this + 200) = 1;
      *(_DWORD *)(this + 196) = v12;
      *(_DWORD *)(this + 192) = v6;
    }
  }
  result = (_DWORD *)(*(_DWORD *)(this + 196) + 4 * *(_DWORD *)(this + 188));
  if ( result )
    *result = a2;
  ++*(_DWORD *)(this + 188);
  if ( a3 )
  {
    sub_9B4760(a2);
    return (_DWORD *)sub_9B4760(a2);
  }
  return result;
}
