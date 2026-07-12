// Function: sub_A39A30
// Address: 0xa39a30
// Size: 0x56
// Prototype: 

_DWORD *__cdecl sub_A39A30(int a1)
{
  _DWORD *v1; // esi
  int v2; // edx
  int v3; // eax

  v1 = *(_DWORD **)(a1 + 44);
  if ( v1 == (_DWORD *)(a1 + 16) )
    return 0;
  v2 = v1[6];
  *(_DWORD *)(v1[8] + 28) = v1[7];
  *(_DWORD *)(v1[7] + 32) = v1[8];
  v2 += 352;
  v1[7] = v2;
  v3 = *(_DWORD *)(v2 + 32);
  v1[8] = v3;
  *(_DWORD *)(v3 + 28) = v1;
  *(_DWORD *)(v1[7] + 32) = v1;
  v1[12] = 1610612736;
  v1[5] = 0;
  return v1;
}

