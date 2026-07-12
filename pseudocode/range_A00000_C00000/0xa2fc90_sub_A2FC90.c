// Function: sub_A2FC90
// Address: 0xa2fc90
// Size: 0x1ab

BOOL __cdecl sub_A2FC90(float *a1, float *a2, float *a3)
{
  bool v3; // al
  bool v4; // al
  bool v5; // al
  bool v6; // al
  bool v7; // al

  v3 = *a1 < (double)*a2 || a1[1] < (double)a2[1]; /*0xa2fdda*/
  v4 = v3 || a1[2] < (double)a2[2]; /*0xa2fdeb*/
  v5 = v4 || *a1 > (double)*a3; /*0xa2fdfd*/
  v6 = v5 || a1[1] > (double)a3[1]; /*0xa2fe0f*/
  v7 = v6 || a1[2] > (double)a3[2]; /*0xa2fe23*/
  return !v7; /*0xa2fe37*/
}