// Function: sub_A34B10
// Address: 0xa34b10
// Size: 0xa9
// Prototype: 

bool __cdecl sub_A34B10(unsigned int a1)
{
  _DWORD *v1; // esi
  unsigned int v2; // edi
  _DWORD *v3; // esi
  int n0x2000; // ebx
  int v5; // eax
  bool v6; // zf

  v1 = (_DWORD *)unk_1A858B4;
  v2 = (3 * a1) >> 2;
  v1[614] = sub_A35A70(a1, 1);
  v1[615] = a1;
  v1[616] = 0;
  v1[617] = 0;
  v3 = (_DWORD *)unk_1A858B4;
  n0x2000 = a1 >> 4;
  v3[618] = sub_A35A70(v2, 2);
  v3[619] = v2;
  v3[620] = 0;
  v3[621] = 0;
  if ( a1 >> 4 >= 0x2000 )
    n0x2000 = 0x2000;
  v5 = unk_1A858B4;
  v6 = *(_DWORD *)(unk_1A858B4 + 2456) == 0;
  *(_DWORD *)(unk_1A858B4 + 2496) = n0x2000 & 0xFFFFFFFC;
  return !v6 && *(_DWORD *)(v5 + 2472);
}

