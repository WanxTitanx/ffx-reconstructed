// Function: sub_81E860
// Address: 0x81e860
int __cdecl sub_81E860(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  _DWORD *v8; // ecx

  v8 = off_C49458;
  *(_DWORD *)off_C49458 = a1;
  v8[1] = a2;
  v8[2] = a3;
  v8[3] = a4;
  v8[4] = a5;
  v8[5] = a6;
  v8[6] = a7;
  v8[7] = a8;
  v8[8] = -1;
  sub_67A630((int)v8);
  return sub_67A680();
}
