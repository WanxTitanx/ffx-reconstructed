// Function: sub_A8B059
// Address: 0xa8b059
// Size: 0x52
// Prototype: 

int __cdecl sub_A8B059(int a1, int a2, __m64 *a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // edi
  int v9; // eax
  int result; // eax

  do
  {
    v8 = (unsigned __int8)rand_0() + a2;
    v9 = 0;
    do
    {
      *(__m64 *)(a1 + v9) = _m_paddb(
                              _m_psubusb(_m_paddusb(_m_psubusb(*(__m64 *)(a1 + v9), (__m64)a3->m64_u64), a3[4]), a3[2]),
                              *(__m64 *)(v8 + v9));
      v9 += 8;
    }
    while ( v9 < a6 );
    result = a8;
    a1 += a8;
  }
  while ( a7-- > 1 );
  return result;
}

