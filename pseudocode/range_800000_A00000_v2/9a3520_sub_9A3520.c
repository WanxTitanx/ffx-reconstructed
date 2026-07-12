// Function: sub_9A3520
// Address: 0x9a3520
int __stdcall sub_9A3520(_DWORD *a1, _DWORD *a2, _DWORD *a3)
{
  int result; // eax

  *a2 = a1[4];
  a2[1] = a1[5];
  a2[2] = a1[6];
  a2[3] = a1[7];
  *a3 = a1[8];
  a3[1] = a1[9];
  a3[2] = a1[10];
  result = a1[11];
  a3[3] = result;
  return result;
}
