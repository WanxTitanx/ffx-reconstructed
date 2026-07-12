// Function: sub_9B7740
// Address: 0x9b7740
void __thiscall sub_9B7740(_DWORD *this, int a2, int a3, int a4)
{
  int v6; // ecx
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // ebx
  int v11; // edx
  _DWORD *v12; // ecx
  int *v13; // eax
  int v14; // [esp+8h] [ebp-4h]
  int v15; // [esp+14h] [ebp+8h]

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
      v6 = *(this + 53);
      v7 = *(this + 52);
      if ( v7 == v6 )
      {
        v8 = v7 ? 2 * v7 : 1;
        v14 = v8;
        if ( v6 < v8 )
        {
          if ( v8 )
            v9 = sub_9D4CE0(4 * v8, 16);
          else
            v9 = 0;
          v10 = *(this + 52);
          v11 = 0;
          v15 = v9;
          if ( v10 > 0 )
          {
            v12 = (_DWORD *)v9;
            do
            {
              if ( v12 )
                *v12 = *(_DWORD *)(*(this + 54) + 4 * v11);
              ++v11;
              ++v12;
            }
            while ( v11 < v10 );
          }
          if ( *(this + 54) )
          {
            if ( *((_BYTE *)this + 220) )
              sub_9D4D50(*(this + 54));
            *(this + 54) = 0;
          }
          *(this + 54) = v15;
          *((_BYTE *)this + 220) = 1;
          *(this + 53) = v14;
        }
      }
      v13 = (int *)(*(this + 54) + 4 * *(this + 52));
      if ( v13 )
        *v13 = a2;
      ++*(this + 52);
    }
    (*(void (__thiscall **)(_DWORD *, int, int, int))(*this + 28))(this, a2, a3, a4);
  }
}
