// Function: sub_988AB0
// Address: 0x988ab0
_DWORD *__cdecl sub_988AB0(int a1, int a2, int a3, int a4)
{
  int v4; // edx
  _DWORD *result; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // edi
  int v9; // eax
  int v10; // ebx
  int v11; // edx
  _DWORD *v12; // ecx
  int v13; // [esp+Ch] [ebp-4h]

  v4 = a2;
  if ( *(_DWORD *)(a2 + 40) && a4 )
  {
    sub_988AB0(a1, *(_DWORD *)(a2 + 36), a3, a4 - 1);
    sub_988AB0(a1, *(_DWORD *)(a2 + 40), a3, a4 - 1);
    result = (_DWORD *)sub_9D4D50(*(_DWORD *)(a1 + 4));
    *(_DWORD *)(a1 + 4) = a2;
  }
  else
  {
    v6 = *(_DWORD *)(a3 + 8);
    v7 = *(_DWORD *)(a3 + 4);
    if ( v7 == v6 )
    {
      v8 = 2 * v7;
      if ( !v7 )
        v8 = 1;
      if ( v6 < v8 )
      {
        if ( v8 )
          v9 = sub_9D4CE0(4 * v8, 16);
        else
          v9 = 0;
        v10 = *(_DWORD *)(a3 + 4);
        v11 = 0;
        v13 = v9;
        if ( v10 > 0 )
        {
          v12 = (_DWORD *)v9;
          do
          {
            if ( v12 )
              *v12 = *(_DWORD *)(*(_DWORD *)(a3 + 12) + 4 * v11);
            ++v11;
            ++v12;
          }
          while ( v11 < v10 );
        }
        if ( *(_DWORD *)(a3 + 12) )
        {
          if ( *(_BYTE *)(a3 + 16) )
            sub_9D4D50(*(_DWORD *)(a3 + 12));
          *(_DWORD *)(a3 + 12) = 0;
        }
        v4 = a2;
        *(_BYTE *)(a3 + 16) = 1;
        *(_DWORD *)(a3 + 12) = v13;
        *(_DWORD *)(a3 + 8) = v8;
      }
    }
    result = (_DWORD *)(*(_DWORD *)(a3 + 12) + 4 * *(_DWORD *)(a3 + 4));
    if ( result )
      *result = v4;
    ++*(_DWORD *)(a3 + 4);
  }
  return result;
}
