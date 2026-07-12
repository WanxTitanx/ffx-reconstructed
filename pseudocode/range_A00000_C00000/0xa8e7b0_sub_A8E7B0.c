// Function: sub_A8E7B0
// Address: 0xa8e7b0
// Size: 0xc7
// Prototype: 

void __thiscall sub_A8E7B0(int this, int a2)
{
  int v2; // ebx
  int v4; // esi
  int v5; // ecx
  int i_1; // eax
  _DWORD *v7; // edx
  int i; // ebx
  int v9; // ecx
  _DWORD *v10; // eax
  int i_2; // [esp+Ch] [ebp-8h]
  int v12; // [esp+10h] [ebp-4h]

  v2 = a2;
  v4 = *(_DWORD *)(this + 4);
  if ( a2 >= v4 )
  {
    if ( a2 > v4 && *(_DWORD *)(this + 8) < a2 )
    {
      if ( a2 )
      {
        v5 = sub_9D4CE0(8 * a2, 16);
        v12 = v5;
      }
      else
      {
        v5 = 0;
        v12 = 0;
      }
      i_1 = *(_DWORD *)(this + 4);
      i_2 = i_1;
      if ( i_1 > 0 )
      {
        v7 = (_DWORD *)v5;
        for ( i = 0; i < i_1; ++i )
        {
          if ( v7 )
          {
            v9 = *(_DWORD *)(this + 12);
            *v7 = *(_DWORD *)(v9 + 8 * i);
            v7[1] = *(_DWORD *)(v9 + 8 * i + 4);
            i_1 = i_2;
          }
          v7 += 2;
        }
        v2 = a2;
      }
      if ( *(_DWORD *)(this + 12) )
      {
        if ( *(_BYTE *)(this + 16) )
          sub_9D4D50(*(_DWORD *)(this + 12));
        *(_DWORD *)(this + 12) = 0;
      }
      *(_BYTE *)(this + 16) = 1;
      *(_DWORD *)(this + 12) = v12;
      *(_DWORD *)(this + 8) = v2;
    }
    for ( ; v4 < v2; ++v4 )
    {
      v10 = (_DWORD *)(*(_DWORD *)(this + 12) + 8 * v4);
      if ( v10 )
      {
        *v10 = 0;
        v10[1] = 0;
      }
    }
  }
  *(_DWORD *)(this + 4) = v2;
}

