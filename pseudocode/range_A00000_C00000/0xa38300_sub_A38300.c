// Function: sub_A38300
// Address: 0xa38300
// Size: 0x7e
// Prototype: 

int __cdecl sub_A38300(int a1, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // eax
  bool v6; // cf
  _DWORD *v7; // ecx
  _BYTE v9[4]; // [esp+0h] [ebp-14h] BYREF
  int n6; // [esp+4h] [ebp-10h]

  v5 = dword_1A858B4;
  if ( dword_1A858B4[686] )
  {
    v6 = __CFADD__(dword_1A858B4[688]++, 1);
    v5[686] = 0;
    v5[689] += v6;
  }
  (*(void (__stdcall **)(int, _BYTE *))(*(_DWORD *)a1 + 32))(a1, v9);
  v7 = dword_1A858B4;
  dword_1A858B4[483] = a3;
  v7[480] = a1;
  v7[484] = n6 == 6;
  v7[481] = a2;
  v7[434] = a4;
  v7[435] = a5;
  return a5;
}

