// Function: sub_A46120
// Address: 0xa46120
// Size: 0x84

void __cdecl sub_A46120(__int16 a1, __int16 a2, __int16 a3, int a4, int a5, int a6)
{
  int v6; // edi
  __int16 v7; // bx
  __int16 v8; // cx
  __int16 v9; // ax
  int v10; // [esp-10h] [ebp-1Ch]
  int v11; // [esp-8h] [ebp-14h]
  int v12; // [esp+18h] [ebp+Ch]
  int v13; // [esp+1Ch] [ebp+10h]

  v6 = (__int16)(a3 - 4); /*0xa4612f*/
  v7 = a2 + 1; /*0xa46136*/
  v11 = v6 + (__int16)(a2 + 1); /*0xa46145*/
  v10 = (__int16)(a2 + 1); /*0xa46147*/
  v13 = a1 + 3; /*0xa46149*/
  v12 = a1 + 1; /*0xa4614c*/
  sub_A45E30(v12, v10, v13, v11, 0); /*0xa4614f*/
  v8 = v7 + a4 * v6 / a5; /*0xa46176*/
  v9 = v7 + v6 * (a4 + a6) / a5; /*0xa4617d*/
  if ( v9 <= v8 ) /*0xa46184*/
    v9 = v8 + 1; /*0xa46189*/
  sub_A45E30(v12, v8, v13, v9, 1); /*0xa4619a*/
}