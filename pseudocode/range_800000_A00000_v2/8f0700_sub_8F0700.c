// Function: sub_8F0700
// Address: 0x8f0700
int __cdecl sub_8F0700(int a1, __int16 a2, int a3, int a4, char a5)
{
  char *MagicEntryById; // eax
  char *v6; // ebx
  int v7; // eax
  int v9; // [esp+Ch] [ebp-4h] BYREF

  MagicEntryById = FFX_Battle_GetMagicEntryById(a2, &v9);
  v6 = (char *)(v9 + *(unsigned __int16 *)MagicEntryById);
  v7 = sub_8EB240(a1, a3 + 12, a4 + 1, MagicEntryById[20]);
  return sub_8E8FB0(v7, -1, v6, a3 + 26, a4 + 1, a5, 0, 128, 128, 128, 128, 0);
}
