// Function: sub_8F08E0
// Address: 0x8f08e0
int __cdecl sub_8F08E0(int a1, unsigned __int8 *a2, int a3, int a4, float a5)
{
  int v6; // eax
  char *v8; // edi
  float v10; // [esp+4h] [ebp-1Ch]
  int v11; // [esp+2Ch] [ebp+Ch]
  float v12; // [esp+30h] [ebp+10h]
  float v13; // [esp+30h] [ebp+10h]
  int v14; // [esp+34h] [ebp+14h]

  v6 = sub_7852B0();
  v8 = (char *)sub_7A0C70(*(unsigned __int16 *)a2, a2[4], v6, 0);
  v11 = a4 + 1;
  v14 = sub_8EB240(a1, a3 + 12, a4 + 1, a2[5] + 2 * a2[4] + 1);
  v12 = (float)v11;
  v10 = v12;
  v13 = (float)(a3 + 29);
  FFX_Menu2D_DrawKernelString(v8, v13, v10, a5, 1.0);
  if ( a2[4] == a2[6] )
    return sub_8EB240(v14, a3 + 12, v11, 0x31u);
  else
    return v14;
}
