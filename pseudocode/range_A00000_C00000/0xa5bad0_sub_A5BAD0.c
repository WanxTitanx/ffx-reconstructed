// Function: sub_A5BAD0
// Address: 0xa5bad0
// Size: 0x9b
// Prototype: int __cdecl(int, int n5, float, float, float, float, float, float, float, float, float)

int __cdecl sub_A5BAD0(
        int a1,
        int n5,
        float a3,
        float a4,
        float a5,
        float a6,
        float a7,
        float a8,
        float a9,
        float a10,
        float a11)
{
  int v11; // eax
  int result; // eax

  *(_DWORD *)off_C3A4C4 = dword_1A86034; /*0xa5bad9*/
  v11 = unknown_libname_741(*((_DWORD *)dword_2305800 + 4)); /*0xa5baeb*/
  sub_7124A0(a1, 4096, *(_DWORD *)(v11 + 4 * n5), 1); /*0xa5bb03*/
  *(_WORD *)(a1 + 30) = 1; /*0xa5bb10*/
  *(float *)(a1 + 64) = a3; /*0xa5bb14*/
  *(float *)(a1 + 68) = a4; /*0xa5bb1d*/
  *(float *)(a1 + 72) = a5; /*0xa5bb23*/
  *(float *)(a1 + 76) = 1.0; /*0xa5bb28*/
  *(_DWORD *)(a1 + 80) = (int)a6; /*0xa5bb36*/
  *(_DWORD *)(a1 + 84) = (int)a7; /*0xa5bb41*/
  result = (int)a8; /*0xa5bb44*/
  *(float *)(a1 + 96) = a9; /*0xa5bb4c*/
  *(_DWORD *)(a1 + 88) = result; /*0xa5bb4f*/
  *(_DWORD *)(a1 + 92) = 1; /*0xa5bb55*/
  *(float *)(a1 + 100) = a10; /*0xa5bb5c*/
  *(float *)(a1 + 104) = a11; /*0xa5bb62... [1077 chars total]