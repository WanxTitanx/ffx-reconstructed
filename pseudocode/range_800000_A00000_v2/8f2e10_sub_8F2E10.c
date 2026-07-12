// Function: sub_8F2E10
// Address: 0x8f2e10
_DWORD *__cdecl sub_8F2E10(_DWORD *a1, int a2, int a3, int a4, int a5, int a6)
{
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  _DWORD *v10; // eax
  _DWORD *v11; // eax
  _DWORD *v12; // eax
  _DWORD *v13; // eax
  _DWORD *v14; // eax
  _DWORD *v15; // eax
  _DWORD *v16; // eax
  _DWORD *v17; // eax

  *a1 = 32769;
  a1[1] = -259112960;
  a1[2] = 826482414;
  a1[3] = 70337300;
  a1[4] = 68;
  a1[5] = 128;
  a1[6] = 66;
  a1[7] = 0;
  a1[8] = 15;
  a1[9] = 0;
  a1[10] = 71;
  a1[11] = 0;
  v6 = (_DWORD *)sub_8EFA00((int)(a1 + 12), a2, 8, 0, 9, 7, 1, 0, 0, 0, 0, 0, 2);
  v7 = sub_8EF8E0(v6, 128, 128, 128, 128);
  v8 = sub_8EFB90(v7, 0, 0);
  v9 = sub_8EFBF0(v8, a3, a4);
  v10 = sub_8EF8E0(v9, 128, 128, 128, 128);
  v11 = sub_8EFB90(v10, 512, 0);
  v12 = sub_8EFBF0(v11, a3 + a5, a4);
  v13 = sub_8EF8E0(v12, 128, 128, 128, 128);
  v14 = sub_8EFB90(v13, 0, 128);
  v15 = sub_8EFBF0(v14, a3, a6 + a4);
  v16 = sub_8EF8E0(v15, 128, 128, 128, 128);
  v17 = sub_8EFB90(v16, 512, 128);
  return sub_8EFBF0(v17, a3 + a5, a6 + a4);
}
