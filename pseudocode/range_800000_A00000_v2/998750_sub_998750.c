// Function: sub_998750
// Address: 0x998750
void __thiscall sub_998750(_DWORD *this, int a2)
{
  _DWORD *this_1; // ebx
  int v4; // edx
  int v5; // eax
  int v6; // edi
  int v7; // eax
  int v8; // ebx
  int v9; // edx
  _DWORD *v10; // ecx
  _DWORD *v11; // ecx
  int v13; // [esp+10h] [ebp+8h]

  this_1 = this;
  if ( *(this + 21) )
  {
    v4 = *(_DWORD *)(a2 + 8);
    v5 = *(_DWORD *)(a2 + 4);
    if ( v5 == v4 )
    {
      v6 = 2 * v5;
      if ( !v5 )
        v6 = 1;
      if ( v4 < v6 )
      {
        if ( v6 )
          v7 = sub_9D4CE0(4 * v6, 16);
        else
          v7 = 0;
        v8 = *(_DWORD *)(a2 + 4);
        v9 = 0;
        v13 = v7;
        if ( v8 > 0 )
        {
          v10 = (_DWORD *)v7;
          do
          {
            if ( v10 )
              *v10 = *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v9);
            ++v9;
            ++v10;
          }
          while ( v9 < v8 );
        }
        if ( *(_DWORD *)(a2 + 12) )
        {
          if ( *(_BYTE *)(a2 + 16) )
            sub_9D4D50(*(_DWORD *)(a2 + 12));
          *(_DWORD *)(a2 + 12) = 0;
        }
        this_1 = this;
        *(_BYTE *)(a2 + 16) = 1;
        *(_DWORD *)(a2 + 12) = v13;
        *(_DWORD *)(a2 + 8) = v6;
      }
    }
    v11 = (_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * *(_DWORD *)(a2 + 4));
    if ( v11 )
      *v11 = this_1[21];
    ++*(_DWORD *)(a2 + 4);
  }
}
