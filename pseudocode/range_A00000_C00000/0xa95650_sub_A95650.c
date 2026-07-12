// Function: sub_A95650
// Address: 0xa95650
// Size: 0x82
// Prototype: _DWORD __cdecl(_DWORD, _DWORD, int n1000, signed int n16)

BOOL __usercall sub_A95650@<eax>(
        BOOL a1@<edx>,
        int a2@<ecx>,
        float a3@<xmm1>,
        float a4@<xmm2>,
        int a5,
        int a6,
        int n1000,
        signed int n16)
{
  BOOL result; // eax
  signed int n16_1; // esi
  int v12; // edx
  signed int n16_2; // ecx
  int v14; // edi
  float v15; // xmm2_4
  float v16; // xmm0_4
  double v17; // xmm1_8
  int v18; // [esp+Ch] [ebp-4h]
  int v19; // [esp+18h] [ebp+8h]

  result = a1;
  n16_1 = 0;
  if ( n16 > 0 )
  {
    v12 = a6;
    n16_2 = a2 - n1000;
    v14 = a5 - a6;
    v18 = result - a5;
    v19 = a5 - a6;
    do
    {
      if ( n16_1 < n16_2 )
        v15 = a3;
      else
        v15 = a4;
      v16 = *(float *)(v14 + v12);
      v17 = *(float *)(v14 + v12 + v18);
      v14 = v19;
      result = v15 <= (float)(fabs(v17) / v16);
      ++n16_1;
      v12 += 4;
      *(_DWORD *)(v12 - 4) = result;
    }
    while ( n16_1 < n16 );
  }
  return result;
}

