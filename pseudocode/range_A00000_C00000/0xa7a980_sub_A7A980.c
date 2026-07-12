// Function: sub_A7A980
// Address: 0xa7a980
// Size: 0x113

int __cdecl sub_A7A980(int a1, int a2, int *a3, int n2)
{
  int v4; // esi
  float *v5; // ebx
  int ActorByIndex; // eax
  int ChrPointer; // eax
  int v9; // [esp+Ch] [ebp-24h]
  int v10; // [esp+10h] [ebp-20h]
  int v11; // [esp+14h] [ebp-1Ch]
  float *v12; // [esp+14h] [ebp-1Ch]
  int v13; // [esp+18h] [ebp-18h]
  float *v14; // [esp+18h] [ebp-18h]
  float v15; // [esp+1Ch] [ebp-14h] BYREF
  float v16; // [esp+20h] [ebp-10h]
  float v17; // [esp+24h] [ebp-Ch]
  int v18; // [esp+28h] [ebp-8h]

  v9 = FFX_FieldVM_PopOperand(a1, a3); /*0xa7a9a2*/
  v13 = FFX_FieldVM_PopOperand(a1, a3); /*0xa7a9ac*/
  v11 = FFX_FieldVM_PopOperand(a1, a3); /*0xa7a9ba*/
  v10 = 0; /*0xa7a9bd*/
  if ( !n2 ) /*0xa7a9c6*/
    v10 = FFX_FieldVM_PopOperand(a1, a3); /*0xa7a9d2*/
  v4 = FFX_FieldVM_PopOperand(a1, a3); /*0xa7a9df*/
  v12 = (float *)sub_86C270(a1, v11); /*0xa7a9ea*/
  v14 = (float *)sub_86C270(a1, v13); /*0xa7a9f6*/
  v5 = (float *)sub_86C270(a1, v9); /*0xa7aa00*/
  ActorByIndex = FFX_Field_GetAc... [1841 chars total]