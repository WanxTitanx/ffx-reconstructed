// Function: sub_A9FA20
// Address: 0xa9fa20
// Size: 0x8c
// Prototype: 

int __cdecl sub_A9FA20(int a1, int a2, int a3, int *a4)
{
  int v6; // esi
  int v7; // eax
  int v8; // ecx
  int result; // eax
  bool v10; // zf
  int v11; // [esp+8h] [ebp-8h]
  int v12; // [esp+Ch] [ebp-4h]
  int v13; // [esp+24h] [ebp+14h]

  v12 = 0;
  v11 = *a4;
  v13 = a3 / *a4;
  if ( v13 <= 0 )
    return 0;
  do
  {
    v6 = sub_A9FAB0(a4, a2);
    if ( v6 < 0 || (v7 = a4[3], v6 >= *(_DWORD *)(v7 + 4)) )
    {
      v8 = 0;
    }
    else
    {
      sub_42E350(a1, *(_DWORD *)(a4[5] + 4 * v6), *(char *)(*(_DWORD *)(v7 + 8) + v6));
      v8 = *(char *)(*(_DWORD *)(a4[3] + 8) + v6);
    }
    result = v8 + v12;
    a2 += 4 * v11;
    v10 = v13-- == 1;
    v12 += v8;
  }
  while ( !v10 );
  return result;
}

