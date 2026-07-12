// Function: sub_8F0680
// Address: 0x8f0680
int __cdecl sub_8F0680(int a1, __int16 a2, int a3, int a4, float a5)
{
  char *EntryWithMask; // eax
  char *v6; // ebx
  int v7; // edi
  float v9; // [esp+4h] [ebp-20h]
  int v10; // [esp+20h] [ebp-4h] BYREF
  int v11; // [esp+38h] [ebp+14h]
  float v12; // [esp+38h] [ebp+14h]
  float v13; // [esp+38h] [ebp+14h]

  EntryWithMask = FFX_BtlEdge_TableGetEntryWithMask(a2, &v10);
  v6 = (char *)(v10 + *(unsigned __int16 *)EntryWithMask);
  v11 = a4 + 1;
  v7 = sub_8EB240(a1, a3 + 12, v11, EntryWithMask[18]);
  v12 = (float)v11;
  v9 = v12;
  v13 = (float)(a3 + 29);
  FFX_Menu2D_DrawKernelString(v6, v13, v9, a5, 0.77999997);
  return v7;
}
