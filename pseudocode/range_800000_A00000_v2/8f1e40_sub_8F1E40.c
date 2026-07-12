// Function: sub_8F1E40
// Address: 0x8f1e40
int __cdecl sub_8F1E40(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v11; // [esp+Ch] [ebp-4h]

  v11 = sub_8FA4F0(200) + 4;
  v7 = sub_8F2FE0(a1, 200, a2, a3, 0, 0, a6, a6);
  v8 = sub_8F2FE0(v7, 201, *(unsigned __int16 *)(v11 + 4) + a2, a3, a4 - *(unsigned __int16 *)(v11 + 4), 0, a6, a7);
  v9 = sub_8F2FE0(v8, 202, a2, *(unsigned __int16 *)(v11 + 6) + a3, 0, a5 - *(unsigned __int16 *)(v11 + 6), a6, a6);
  return sub_8F2FE0(
           v9,
           203,
           *(unsigned __int16 *)(v11 + 4) + a2,
           *(unsigned __int16 *)(v11 + 6) + a3,
           a4 - *(unsigned __int16 *)(v11 + 4),
           a5 - *(unsigned __int16 *)(v11 + 6),
           a6,
           a7);
}
