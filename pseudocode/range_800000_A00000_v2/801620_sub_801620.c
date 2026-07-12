// Function: sub_801620
// Address: 0x801620
__int16 __cdecl sub_801620(int a1, int a2)
{
  int v2; // edx
  int v3; // ebx
  int v4; // edi
  __int16 v5; // si
  int v6; // eax
  __int16 v8; // di
  int v9; // eax
  int v10; // [esp+18h] [ebp+Ch]

  v2 = a1;
  v3 = (unsigned __int16)(*(_WORD *)(a1 + 52) - 1);
  v4 = *(_DWORD *)(a1 + 4 * a2 + 16);
  v5 = 0;
  v10 = v4;
  if ( *(_WORD *)(a1 + 52) == 1 )
    return -1;
  v6 = 0;
  while ( *(__int16 *)(v4 + 2 * v6) >= 0 )
  {
    v6 = ++v5;
    if ( v5 >= v3 )
      return -1;
  }
  v8 = 0;
  v9 = 0;
  while ( !sub_A446A0(*(_DWORD *)(*(_DWORD *)(v2 + 32) + (v9 << 8))) )
  {
    v2 = a1;
    v9 = ++v8;
    if ( v8 >= v3 )
      return -1;
  }
  *(_WORD *)(v10 + 2 * v5) = v8;
  ++*(_WORD *)(a1 + 56);
  return v8;
}
