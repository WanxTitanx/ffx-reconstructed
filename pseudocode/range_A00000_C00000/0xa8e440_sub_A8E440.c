// Function: sub_A8E440
// Address: 0xa8e440
// Size: 0xb3
// Prototype: 

int __stdcall sub_A8E440(int a1, int a2)
{
  int v2; // edx
  int i; // esi
  int v4; // eax
  int v5; // esi
  int v6; // edi
  int result; // eax
  int **v8; // esi
  int v9; // ecx

  v2 = 0;
  for ( i = 0; v2 < *(_DWORD *)(a1 + 8); *(_DWORD *)(v4 + 252) = 1065353216 )
  {
    v4 = *(_DWORD *)(*(_DWORD *)(a1 + 16) + 4 * v2);
    if ( (*(_BYTE *)(v4 + 216) & 3) == 0 )
      *(_DWORD *)(v4 + 220) = i++;
    ++v2;
    *(_DWORD *)(v4 + 224) = -1;
  }
  sub_A8EA20(i);
  v5 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a1 + 80) + 36))(*(_DWORD *)(a1 + 80));
  v6 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 32))(v5);
  result = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 20))(v5);
  v8 = (int **)result;
  if ( v6 > 0 )
  {
    do
    {
      v9 = **v8;
      result = *v8[1];
      if ( v9 && (*(_BYTE *)(v9 + 216) & 7) == 0 && result && (*(_BYTE *)(result + 216) & 7) == 0 )
        result = sub_9BC670(*(_DWORD *)(v9 + 220), *(_DWORD *)(result + 220));
      v8 += 4;
      --v6;
    }
    while ( v6 );
  }
  return result;
}

