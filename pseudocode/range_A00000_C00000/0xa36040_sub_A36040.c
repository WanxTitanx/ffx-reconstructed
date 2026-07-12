// Function: sub_A36040
// Address: 0xa36040
// Size: 0x4b

int __cdecl sub_A36040(int *a1, int a2, int a3)
{
  float v5; // [esp+4h] [ebp-Ch]
  float v6; // [esp+8h] [ebp-8h]
  float v7; // [esp+Ch] [ebp-4h]
  float v8; // [esp+18h] [ebp+8h]
  float v9; // [esp+18h] [ebp+8h]
  float v10; // [esp+18h] [ebp+8h]
  float v11; // [esp+18h] [ebp+8h]

  v8 = (float)a1[3]; /*0xa3604c*/
  v7 = v8; /*0xa36052*/
  v9 = (float)a1[2]; /*0xa36059*/
  v6 = v9; /*0xa3605f*/
  v10 = (float)a1[1]; /*0xa36066*/
  v5 = v10; /*0xa3606c*/
  v11 = (float)*a1; /*0xa36072*/
  return sub_A36090(a2, a3, v11, v5, v6, v7); /*0xa36089*/
}