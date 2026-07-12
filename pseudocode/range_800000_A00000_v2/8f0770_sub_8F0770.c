// Function: sub_8F0770
// Address: 0x8f0770
int __cdecl sub_8F0770(int a1, __int16 a2, int a3, int a4, float a5)
{
  char *MagicEntryById; // eax
  char *v6; // ebx
  int v7; // edi
  float v9; // [esp+4h] [ebp-20h]
  int v10; // [esp+20h] [ebp-4h] BYREF
  int v11; // [esp+38h] [ebp+14h]
  float v12; // [esp+38h] [ebp+14h]
  float v13; // [esp+38h] [ebp+14h]

  MagicEntryById = FFX_Battle_GetMagicEntryById(a2, &v10);
  v6 = (char *)(v10 + *(unsigned __int16 *)MagicEntryById);
  v11 = a4 + 1;
  v7 = sub_8EB240(a1, a3 + 12, v11, MagicEntryById[20]);
  v12 = (float)v11;
  v9 = v12;
  v13 = (float)(a3 + 29);
  FFX_Menu2D_DrawKernelString(v6, v13, v9, a5, 1.0);
  return v7;
}
