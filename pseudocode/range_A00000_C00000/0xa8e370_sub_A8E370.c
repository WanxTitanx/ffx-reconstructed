// Function: sub_A8E370
// Address: 0xa8e370
// Size: 0xc3
// Prototype: 

int __thiscall sub_A8E370(_DWORD *this, int a2)
{
  int result; // eax
  int i_1; // edx
  _DWORD *this_1; // ebx
  int v5; // edi
  int v6; // eax
  int v7; // esi
  int i_2; // ecx
  int v9; // ebx
  _DWORD *v10; // edx
  int v11; // esi
  int i; // [esp+Ch] [ebp-Ch]

  result = a2;
  i_1 = 0;
  this_1 = this;
  v5 = 0;
  for ( i = 0; v5 < *(_DWORD *)(a2 + 8); ++v5 )
  {
    v6 = *(_DWORD *)(*(_DWORD *)(result + 16) + 4 * v5);
    if ( (*(_BYTE *)(v6 + 216) & 3) != 0 )
    {
      *(_DWORD *)(v6 + 220) = -1;
      *(_DWORD *)(v6 + 224) = -2;
    }
    else
    {
      v7 = this_1[4];
      i_2 = i_1;
      if ( i_1 != *(_DWORD *)(v7 + 8 * i_1) )
      {
        v9 = 8 * i_1;
        do
        {
          v10 = (_DWORD *)(v7 + 8 * *(_DWORD *)(v7 + v9));
          *(_DWORD *)(v7 + v9) = *v10;
          i_2 = *v10;
          v7 = *(this + 4);
          v9 = 8 * *v10;
        }
        while ( *v10 != *(_DWORD *)(v7 + v9) );
        i_1 = i;
        this_1 = this;
      }
      *(_DWORD *)(v6 + 220) = i_2;
      v11 = 8 * i_1++;
      *(_DWORD *)(this_1[4] + v11 + 4) = v5;
      *(_DWORD *)(v6 + 224) = -1;
      i = i_1;
    }
    result = a2;
  }
  return result;
}

