// Function: sub_8F0590
// Address: 0x8f0590
int __cdecl sub_8F0590(int a1, int a2, int a3, int a4, char a5)
{
  float *v5; // eax
  char *v6; // ebx
  int v7; // eax
  int v9; // [esp+Ch] [ebp-4h] BYREF

  v5 = FFX_Btl_LookupCommandDataById(a2, &v9);
  v6 = (char *)(v9 + *(unsigned __int16 *)v5);
  v7 = sub_8EB240(a1, a3 + 12, a4 + 1, *((_BYTE *)v5 + 20));
  return sub_8E8FB0(v7, -1, v6, a3 + 26, a4 + 1, a5, 0, 128, 128, 128, 128, 0);
}
