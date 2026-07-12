// Function: sub_AA1830
// Address: 0xaa1830
// Size: 0x164
// Prototype: 

int *__cdecl sub_AA1830(int a1, int *a2, int a3)
{
  _DWORD *v3; // edi
  int v4; // ecx
  unsigned int v5; // eax
  int v6; // ecx
  unsigned int v7; // eax
  int v8; // edi
  _DWORD *v9; // ebx
  int *result; // eax
  int v11; // ebx
  _DWORD *v12; // edi
  int v13; // [esp+Ch] [ebp-4h]

  if ( *a2 <= 1 )
  {
    sub_42E350(a3, 0, 1);
  }
  else
  {
    sub_42E350(a3, 1, 1);
    sub_42E350(a3, *a2 - 1, 4);
  }
  if ( a2[289] <= 0 )
  {
    sub_42E350(a3, 0, 1);
  }
  else
  {
    sub_42E350(a3, 1, 1);
    sub_42E350(a3, a2[289] - 1, 8);
    v13 = 0;
    if ( a2[289] > 0 )
    {
      v3 = a2 + 546;
      do
      {
        v4 = 0;
        v5 = *(_DWORD *)(a1 + 4) - 1;
        if ( *(_DWORD *)(a1 + 4) != 1 )
        {
          do
          {
            ++v4;
            v5 >>= 1;
          }
          while ( v5 );
        }
        sub_42E350(a3, *(v3 - 256), v4);
        v6 = 0;
        v7 = *(_DWORD *)(a1 + 4) - 1;
        if ( *(_DWORD *)(a1 + 4) != 1 )
        {
          do
          {
            ++v6;
            v7 >>= 1;
          }
          while ( v7 );
        }
        sub_42E350(a3, *v3++, v6);
        ++v13;
      }
      while ( v13 < a2[289] );
    }
  }
  sub_42E350(a3, 0, 2);
  if ( *a2 > 1 )
  {
    v8 = 0;
    if ( *(int *)(a1 + 4) > 0 )
    {
      v9 = a2 + 1;
      do
      {
        sub_42E350(a3, *v9, 4);
        ++v8;
        ++v9;
      }
      while ( v8 < *(_DWORD *)(a1 + 4) );
    }
  }
  result = a2;
  v11 = 0;
  if ( *a2 > 0 )
  {
    v12 = a2 + 273;
    do
    {
      sub_42E350(a3, 0, 8);
      sub_42E350(a3, *(v12 - 16), 8);
      sub_42E350(a3, *v12, 8);
      result = a2;
      ++v11;
      ++v12;
    }
    while ( v11 < *a2 );
  }
  return result;
}

