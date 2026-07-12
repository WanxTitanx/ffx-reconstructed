// Function: sub_9B75E0
// Address: 0x9b75e0
void __thiscall sub_9B75E0(_DWORD *this, int a2)
{
  int v4; // ecx
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // ebx
  int v9; // edx
  _DWORD *v10; // ecx
  int *v11; // eax
  bool v12; // cl
  int v13; // [esp+8h] [ebp-4h]
  int v14; // [esp+14h] [ebp+8h]

  if ( (*(_BYTE *)(a2 + 216) & 3) == 0 && (*(_BYTE *)(a2 + 524) & 1) == 0 )
    sub_9B5C70(a2, (int)(this + 56));
  if ( *(_DWORD *)(a2 + 204) )
  {
    if ( (*(_BYTE *)(a2 + 216) & 1) != 0 )
    {
      sub_97A440(2);
    }
    else
    {
      v4 = *(this + 53);
      v5 = *(this + 52);
      if ( v5 == v4 )
      {
        v6 = v5 ? 2 * v5 : 1;
        v13 = v6;
        if ( v4 < v6 )
        {
          if ( v6 )
            v7 = sub_9D4CE0(4 * v6, 16);
          else
            v7 = 0;
          v8 = *(this + 52);
          v9 = 0;
          v14 = v7;
          if ( v8 > 0 )
          {
            v10 = (_DWORD *)v7;
            do
            {
              if ( v10 )
                *v10 = *(_DWORD *)(*(this + 54) + 4 * v9);
              ++v9;
              ++v10;
            }
            while ( v9 < v8 );
          }
          if ( *(this + 54) )
          {
            if ( *((_BYTE *)this + 220) )
              sub_9D4D50(*(this + 54));
            *(this + 54) = 0;
          }
          *(this + 54) = v14;
          *((_BYTE *)this + 220) = 1;
          *(this + 53) = v13;
        }
      }
      v11 = (int *)(*(this + 54) + 4 * *(this + 52));
      if ( v11 )
        *v11 = a2;
      ++*(this + 52);
    }
    v12 = (*(_BYTE *)(a2 + 216) & 1) == 0 && (*(_DWORD *)(a2 + 216) & 2) == 0;
    (*(void (__thiscall **)(_DWORD *, int, int, int))(*this + 28))(this, a2, !v12 + 1, 2 * v12 - 3);
  }
}
