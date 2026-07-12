// Function: sub_A5ADF0
// Address: 0xa5adf0
// Size: 0x4f
// Prototype: 

__int16 __cdecl sub_A5ADF0(int a1)
{
  int v1; // ebx
  unsigned int i; // esi
  int v3; // edi
  int v4; // eax
  __int16 result; // ax

  v1 = 0;
  for ( i = 63496; i < 0xF828; i += 4 )
  {
    v3 = dword_2305834[0];
    v4 = sub_7E3720(a1, 2, (unsigned __int8)byte_C86008[v1]);
    *(_WORD *)(v3 + i) = *(_WORD *)(v4 + 12);
    result = *(_WORD *)(v4 + 14);
    *(_WORD *)(v3 + i + 2) = result;
    ++v1;
  }
  return result;
}

