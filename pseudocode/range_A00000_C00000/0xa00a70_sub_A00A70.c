// Function: sub_A00A70
// Address: 0xa00a70
// Size: 0x39d
// Prototype: int __thiscall(int this, int)

int __thiscall sub_A00A70(int this, int a2)
{
  int v3; // ecx
  int v4; // eax
  int v5; // edx
  int n16; // ebx
  double v7; // st7
  int v8; // ecx
  int v9; // eax
  int n16_1; // ebx
  double v11; // st7
  int v12; // ecx
  int v13; // eax
  int n16_2; // ebx
  double v15; // st7

  *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4); /*0xa00a81*/
  *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8); /*0xa00a87*/
  *(_DWORD *)(this + 12) = *(_DWORD *)(a2 + 12); /*0xa00a8d*/
  *(_BYTE *)(this + 16) = *(_BYTE *)(a2 + 16); /*0xa00a94*/
  *(_BYTE *)(this + 17) = *(_BYTE *)(a2 + 17); /*0xa00a9b*/
  sub_453420(a2 + 20); /*0xa00aa2*/
  sub_453420(a2 + 84); /*0xa00aae*/
  sub_453420(a2 + 148); /*0xa00ac0*/
  v3 = a2 + 240; /*0xa00ac7*/
  v4 = this + 232; /*0xa00acd*/
  v5 = a2 - this; /*0xa00ad3*/
  n16 = 16; /*0xa00ad5*/
  do /*0xa00b48*/
  {
    v7 = *(float *)(v3 - 28); /*0xa00ae0*/
    v3 += 64; /*0xa00ae3*/
    *(float *)(v4 - 20) = v7; /*0xa00ae6*/
    v4 += 64; /*0xa00ae9*/
    *(float *)(v4 - 8... [6797 chars total]