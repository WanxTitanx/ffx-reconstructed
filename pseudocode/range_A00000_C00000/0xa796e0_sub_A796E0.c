// Function: sub_A796E0
// Address: 0xa796e0
// Size: 0xc9
// Prototype: 

int __cdecl sub_A796E0(int a1, int a2, int *a3)
{
  int v3; // ebx
  int v4; // esi
  int v5; // edi
  float *v6; // ebx
  float *v7; // esi
  int ActorByIndex; // eax
  int ChrPointer; // eax
  int v11; // [esp+Ch] [ebp-20h]
  int v12; // [esp+10h] [ebp-1Ch]
  float *v13; // [esp+14h] [ebp-18h]
  float v14[4]; // [esp+18h] [ebp-14h] BYREF

  v12 = FFX_FieldVM_PopOperand(a1, a3);
  v3 = FFX_FieldVM_PopOperand(a1, a3);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  v11 = FFX_FieldVM_PopOperand(a1, a3);
  v5 = FFX_FieldVM_PopOperand(a1, a3);
  v13 = (float *)sub_86C270(a1, v4);
  v6 = (float *)sub_86C270(a1, v3);
  v7 = (float *)sub_86C270(a1, v12);
  ActorByIndex = FFX_Field_GetActorByIndex(v5);
  ChrPointer = FFX_TK_GetChrPointer(ActorByIndex);
  if ( ChrPointer )
  {
    sub_833D90(ChrPointer, v11, 0, v14);
    if ( v13 )
      *v13 = v14[0];
    if ( v6 )
      *v6 = v14[1];
    if ( v7 )
      *v7 = v14[2];
  }
  return 0;
}

