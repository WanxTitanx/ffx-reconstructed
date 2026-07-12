// Function: sub_A8F4C0
// Address: 0xa8f4c0
// Size: 0xa3
// Prototype: 

int __fastcall sub_A8F4C0(int a1, _DWORD *a2)
{
  int v4; // eax
  int v5; // esi

  sub_42E350(a1, 3, 8);
  sub_A90540(6);
  sub_42E350(a1, 44, 32);
  sub_A90540(44);
  sub_42E350(a1, a2[2], 32);
  v4 = a2[2];
  if ( v4 )
  {
    v5 = 0;
    if ( v4 > 0 )
    {
      do
      {
        if ( *(_DWORD *)(*a2 + 4 * v5) )
        {
          sub_42E350(a1, *(_DWORD *)(a2[1] + 4 * v5), 32);
          sub_A90540(*(_DWORD *)(a2[1] + 4 * v5));
        }
        else
        {
          sub_42E350(a1, 0, 32);
        }
        ++v5;
      }
      while ( v5 < a2[2] );
    }
  }
  sub_42E350(a1, 1, 1);
  return 0;
}

