// Function: sub_860220
// Address: 0x860220
int __cdecl sub_860220(unsigned __int8 **a1, int a2, int *a3)
{
  float *v4; // ebx
  int n3; // eax
  float v7; // [esp+Ch] [ebp-8h]
  float v8; // [esp+10h] [ebp-4h]
  float v9; // [esp+1Ch] [ebp+8h]

  v4 = (float *)sub_86C240(a1);
  v7 = FFX_TK_PopStackFloat((int)a1, a3);
  v8 = FFX_TK_PopStackFloat((int)a1, a3);
  v9 = FFX_TK_PopStackFloat((int)a1, a3);
  n3 = **a1;
  if ( n3 != 3 && n3 != 6 )
    return 0;
  *v4 = v9;
  v4[1] = v8;
  v4[2] = v7;
  *((_WORD *)a1 + 26) |= 0x80u;
  *((_WORD *)a1 + 27) |= 1u;
  return 1;
}
