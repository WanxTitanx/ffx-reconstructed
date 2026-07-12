// Function: sub_911970
// Address: 0x911970
int __cdecl sub_911970(int a1)
{
  int result; // eax
  int n1024; // edx
  _DWORD *v3; // ecx

  result = a1;
  n1024 = 1024;
  v3 = (_DWORD *)(a1 + 8);
  do
  {
    v3[1] = 0;
    *v3 = 0;
    *(v3 - 1) = 0;
    *(v3 - 2) = 0;
    v3 += 4;
    --n1024;
  }
  while ( n1024 );
  *(_DWORD *)(a1 + 0x4000) = 0;
  *(_DWORD *)(a1 + 16392) = 0;
  *(_DWORD *)(a1 + 16468) = 0;
  *(_DWORD *)(a1 + 16464) = 0;
  *(_DWORD *)(a1 + 16460) = 0;
  *(_DWORD *)(a1 + 16456) = 0;
  *(_DWORD *)(a1 + 16484) = 0;
  *(_DWORD *)(a1 + 16480) = 0;
  *(_DWORD *)(a1 + 16476) = 0;
  *(_DWORD *)(a1 + 16472) = 0;
  *(_DWORD *)(a1 + 16500) = 0;
  *(_DWORD *)(a1 + 16504) = 0;
  *(_DWORD *)(a1 + 16492) = 0;
  *(_DWORD *)(a1 + 16496) = 0;
  *(_DWORD *)(a1 + 16508) = 0;
  *(_DWORD *)(a1 + 16512) = 0;
  *(_WORD *)(a1 + 16516) = 0;
  return result;
}
