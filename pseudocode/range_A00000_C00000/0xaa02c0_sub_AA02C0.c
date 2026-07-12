// Function: sub_AA02C0
// Address: 0xaa02c0
// Size: 0xea
// Prototype: 

int __cdecl sub_AA02C0(_DWORD *a1, int a2)
{
  _DWORD *v2; // esi
  int v3; // ebx
  int result; // eax
  int *v5; // esi
  int v6; // edx
  unsigned int v7; // eax
  int n3; // ecx
  unsigned int v9; // eax
  int v10; // edx
  _DWORD *v11; // esi
  int v12; // [esp+Ch] [ebp-4h]

  v2 = a1;
  v3 = 0;
  sub_42E350(a2, *a1, 24);
  sub_42E350(a2, a1[1], 24);
  sub_42E350(a2, a1[2] - 1, 24);
  sub_42E350(a2, a1[3] - 1, 6);
  result = sub_42E350(a2, a1[5], 8);
  v12 = 0;
  if ( (int)a1[3] > 0 )
  {
    v5 = a1 + 6;
    do
    {
      v6 = *v5;
      v7 = *v5;
      n3 = 0;
      if ( !*v5 )
        goto LABEL_7;
      do
      {
        ++n3;
        v7 >>= 1;
      }
      while ( v7 );
      if ( n3 > 3 )
      {
        sub_42E350(a2, v6, 3);
        sub_42E350(a2, 1, 1);
        sub_42E350(a2, *v5 >> 3, 5);
      }
      else
      {
LABEL_7:
        sub_42E350(a2, v6, 4);
      }
      v9 = *v5;
      v10 = 0;
      if ( *v5 )
      {
        do
        {
          v10 += v9 & 1;
          v9 >>= 1;
        }
        while ( v9 );
      }
      result = v12 + 1;
      v3 += v10;
      ++v5;
      v12 = result;
    }
    while ( result < a1[3] );
    v2 = a1;
  }
  if ( v3 > 0 )
  {
    v11 = v2 + 70;
    do
    {
      result = sub_42E350(a2, *v11++, 8);
      --v3;
    }
    while ( v3 );
  }
  return result;
}

