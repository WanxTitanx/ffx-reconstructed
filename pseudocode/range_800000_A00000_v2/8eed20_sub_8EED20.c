// Function: sub_8EED20
// Address: 0x8eed20
_DWORD *__cdecl sub_8EED20(_DWORD *a1, char *a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v9; // ebx
  int v10; // edi
  int v11; // eax
  _DWORD *v12; // eax
  _DWORD *v13; // eax
  _DWORD *v14; // eax
  _DWORD *v15; // eax
  int v16; // esi
  _DWORD *v17; // eax
  _DWORD *v18; // eax
  int v19; // eax
  _DWORD *v20; // eax
  _DWORD *v21; // eax
  _DWORD *v22; // eax
  _DWORD *v23; // eax
  _DWORD *v24; // eax
  int v26; // [esp+Ch] [ebp-8h]

  v9 = *a2 - 32;
  *a1 = 32769;
  a1[1] = -525647872;
  a1[2] = -466341394;
  a1[3] = 4408094;
  v10 = 8 * (v9 % 32 / 2);
  v26 = v10;
  v11 = sub_8EFA00((int)(a1 + 4), 15744, 2, 19, 7, 8, 1, 0, 11964, 0, 0, 0, 1);
  v12 = (_DWORD *)sub_8EFA00(v11, 15744, 2, 20, 7, 8, 1, 0, 11964, 0, 0, (v9 & 1) + 2 * ((a5 >> 4) & 0xF), 0);
  v13 = sub_8EF8E0(v12, a6, a7, a8, a9);
  v14 = sub_8EFB90(v13, v10, 8 * (v9 / 32) + 240);
  v15 = sub_8EFBF0(v14, a3 + 1, a4 + 1);
  v16 = 8 * (v9 / 32) + 248;
  v10 += 8;
  v17 = sub_8EFB90(v15, v10, v16);
  v18 = sub_8EFBF0(v17, a3 + 9, a4 + 9);
  v19 = sub_8EFA00((int)v18, 15744, 2, 19, 7, 8, 1, 0, 11960, 0, 0, 0, 1);
  v20 = (_DWORD *)sub_8EFA00(v19, 15744, 2, 20, 7, 8, 1, 0, 11960, 0, 0, (v9 & 1) + 2 * (a5 & 0xF), 0);
  v21 = sub_8EF8E0(v20, a6, a7, a8, a9);
  v22 = sub_8EFB90(v21, v26, 8 * (v9 / 32) + 240);
  v23 = sub_8EFBF0(v22, a3, a4);
  v24 = sub_8EFB90(v23, v10, v16);
  return sub_8EFBF0(v24, a3 + 8, a4 + 8);
}
