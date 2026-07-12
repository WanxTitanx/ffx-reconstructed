// Function: sub_813570
// Address: 0x813570
int __cdecl sub_813570(int a1, int a2)
{
  int v2; // edi
  int result; // eax

  v2 = *(_DWORD *)(a1 + 544);
  result = sub_813A30(
             *(__int16 **)(v2 + 188),
             (int)*(float *)(v2 + 68),
             *(_DWORD *)(a2 + 84),
             *(_DWORD *)(v2 + 200),
             *(_DWORD *)(v2 + 168),
             *(_WORD *)(v2 + 194));
  *(_DWORD *)(a2 + 84) = result;
  return result;
}
