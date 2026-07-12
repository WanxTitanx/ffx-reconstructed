// Function: sub_A73740
// Address: 0xa73740
// Size: 0xce

int __cdecl sub_A73740(_DWORD *a1, int a2)
{
  int v3; // edi
  int v4; // eax
  int result; // eax
  float v6; // [esp+1Ch] [ebp+8h]

  v3 = 8 * (a1[1] % *a1); /*0xa7375e*/
  *(float *)&a1[v3 + 5] = *(float *)(a2 + 148); /*0xa73761*/
  *(float *)&a1[v3 + 4] = *(float *)(a2 + 64) * 0.00390625; /*0xa73772*/
  *(float *)&a1[v3 + 6] = *(float *)(a2 + 72) * 0.00390625; /*0xa7377b*/
  *(float *)&a1[v3 + 7] = *(float *)(a2 + 60) * 0.0625; /*0xa73788*/
  LOWORD(a1[v3 + 8]) = (int)*(float *)(a2 + 48); /*0xa73794*/
  v6 = (float)(int)*(float *)(a2 + 52); /*0xa737a7*/
  HIWORD(a1[v3 + 8]) = (int)(0.00390625 * v6); /*0xa737b2*/
  v4 = (int)*(float *)(a2 + 56); /*0xa737ba*/
  LOWORD(a1[v3 + 9]) = v4; /*0xa737bf*/
  if ( (double)(__int16)v4 < 0.0 ) /*0xa737dc*/
    LOWORD(a1[v3 + 9]) = 0; /*0xa737e0*/
  HIWORD(a1[v3 + 9]) = (int)*(float *)(a2 + 76) + 16; /*0xa737f0*/
  result = *(_DWORD *)(a2 + 200); /*0xa737f5*/
  a1[v3 + 10] = result; /*0xa737fb*/
  LOBYTE(a1[v3 + 11]) = 8; /*0xa737ff*/
  ++a1[1]... [1046 chars total]