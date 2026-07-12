// Function: sub_8F0830
// Address: 0x8f0830
int __cdecl sub_8F0830(int a1, int a2, int a3, int a4, float a5)
{
  _BYTE *v5; // ebx
  char *v7; // edi
  float v9; // [esp+4h] [ebp-20h]
  _BYTE v10[4]; // [esp+20h] [ebp-4h] BYREF
  float v11; // [esp+2Ch] [ebp+8h]
  float v12; // [esp+2Ch] [ebp+8h]
  int v13; // [esp+34h] [ebp+10h]
  int v14; // [esp+38h] [ebp+14h]

  v5 = (_BYTE *)sub_7ABBF0(a2, v10);
  v7 = (char *)sub_7ABE10(a2);
  v14 = a4 + 1;
  v13 = sub_8EB240(a1, a3 + 12, v14, v5[5] + 2 * v5[4] + 1);
  v11 = (float)v14;
  v9 = v11;
  v12 = (float)(a3 + 29);
  FFX_Menu2D_DrawKernelString(v7, v12, v9, a5, 1.0);
  if ( v5[4] == v5[6] )
    return sub_8EB240(v13, a3 + 12, v14, 0x31u);
  else
    return v13;
}
