// Function: sub_A26480
// Address: 0xa26480
// Size: 0x86

int __thiscall sub_A26480(int *this, _DWORD *a2, _DWORD *a3)
{
  int v3; // edi
  int v6; // eax
  _DWORD *v7; // esi
  _DWORD *v8; // ecx
  int v9; // edi
  _DWORD *v10; // edx
  _DWORD *v11; // ecx
  int v12; // [esp+8h] [ebp-4h]

  v3 = (int)a2; /*0xa26486*/
  if ( !a2 ) /*0xa2648d*/
    return 13; /*0xa2648f*/
  v6 = *this & 0x7FFFFFFF; /*0xa2649c*/
  v7 = (_DWORD *)*(this + 1); /*0xa264a2*/
  v12 = v6; /*0xa264a5*/
  v8 = a2; /*0xa264a8*/
  if ( v6 ) /*0xa264aa*/
  {
    v9 = v6; /*0xa264ac*/
    do /*0xa264c1*/
    {
      v10 = v8++; /*0xa264b0*/
      if ( v10 ) /*0xa264b7*/
        *v10 = *v7++; /*0xa264bb*/
      --v9; /*0xa264c0*/
    }
    while ( v9 ); /*0xa264c1*/
    v3 = (int)a2; /*0xa264c3*/
  }
  v11 = (_DWORD *)(v3 + 4 * v6); /*0xa264c9*/
  if ( v11 ) /*0xa264cf*/
    *v11 = *a3; /*0xa264d6*/
  if ( *(this + 1) != v3 && *this >= 0 ) /*0xa264e8*/
    Phyre_Memory_AlignedFree(*(this + 1)); /*0xa264eb*/
  *(this + 1) = v3; /*0xa264f6*/
  *this = v12 + 1; /*0xa264fa*/
  ... [1024 chars total]