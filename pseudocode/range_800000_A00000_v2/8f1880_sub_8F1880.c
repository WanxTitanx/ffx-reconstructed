// Function: sub_8F1880
// Address: 0x8f1880
_DWORD *__cdecl sub_8F1880(_DWORD *a1, signed int n7, int a3, int a4, int a5, int a6, int a7, int a8)
{
  _DWORD *result; // eax
  int v9; // eax
  _DWORD *v10; // eax
  _DWORD *v11; // ecx
  int v12; // ebx
  _DWORD *v13; // eax
  _DWORD *v14; // eax
  _DWORD *v15; // eax

  result = a1;
  if ( (unsigned int)n7 <= 7 )
  {
    *a1 = 2;
    a1[1] = 0x10000000;
    a1[2] = 14;
    a1[3] = 0;
    v9 = sub_8EF970((int)(a1 + 4), 1, 7, 0, 0, 0, 0, 0, 0);
    v10 = (_DWORD *)sub_8EFA00(v9, 12544, 4, 19, 8, 7, 1, 0, 11992, 0, 0, 0, 2);
    *v10 = 32769;
    v10[1] = 1351565312;
    v10[2] = 275505;
    v10[3] = 0;
    v12 = (n7 / 4) << 6;
    v11 = sub_8EF8E0(v10 + 4, a5, a6, a7, a8);
    v13 = sub_8EFB90(v11, (n7 % 4) << 6, v12);
    v14 = sub_8EFBF0(v13, a3, a4);
    v15 = sub_8EFB90(v14, ((n7 % 4) << 6) + 64, v12 + 64);
    return sub_8EFBF0(v15, a3 + 64, a4 + 64);
  }
  return result;
}
