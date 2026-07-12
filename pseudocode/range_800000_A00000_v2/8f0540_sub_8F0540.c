// Function: sub_8F0540
// Address: 0x8f0540
int __cdecl sub_8F0540(int a1, int a2, int a3, int a4, char a5)
{
  unsigned __int16 *v5; // eax
  char *v6; // ebx
  int v7; // eax
  int v9; // [esp+Ch] [ebp-4h] BYREF

  v5 = (unsigned __int16 *)sub_7909C0(a2, &v9);
  v6 = (char *)(v9 + *v5);
  v7 = sub_8EB240(a1, a3 + 12, a4 + 1, *((_BYTE *)v5 + 104));
  return sub_8ED0A0(v7, v6, a3 + 29, a4 + 1, a5);
}
