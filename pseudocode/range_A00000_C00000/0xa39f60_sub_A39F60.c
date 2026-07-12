// Function: sub_A39F60
// Address: 0xa39f60
// Size: 0x59
// Prototype: 

_DWORD *__cdecl sub_A39F60(int a1)
{
  _DWORD *result; // eax
  int v2; // esi
  int v3; // ecx

  for ( result = *(_DWORD **)(a1 + 156); result != (_DWORD *)(a1 + 128); result = *(_DWORD **)(a1 + 156) )
  {
    v2 = result[6];
    *(_DWORD *)(result[8] + 28) = result[7];
    *(_DWORD *)(result[7] + 32) = result[8];
    v2 += 72;
    result[7] = v2;
    v3 = *(_DWORD *)(v2 + 32);
    result[8] = v3;
    *(_DWORD *)(v3 + 28) = result;
    *(_DWORD *)(result[7] + 32) = result;
    result[12] = result[12] & 0xFFFFFFF | 0x10000000;
  }
  return result;
}

