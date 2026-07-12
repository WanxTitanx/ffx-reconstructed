// Function: sub_A7A140
// Address: 0xa7a140
// Size: 0xca
// Prototype: 

int __cdecl sub_A7A140(int a1, int a2, int *a3)
{
  int v3; // edi
  int v4; // ebx
  float *v5; // edi
  float *v6; // esi
  int ActorByIndex; // eax
  int ChrPointer; // eax
  int result; // eax
  int v10; // [esp-24h] [ebp-4Ch]
  int v11; // [esp+Ch] [ebp-1Ch]
  float *v12; // [esp+10h] [ebp-18h]
  float v13[4]; // [esp+14h] [ebp-14h] BYREF

  v11 = FFX_FieldVM_PopOperand(a1, a3);
  v3 = FFX_FieldVM_PopOperand(a1, a3);
  v10 = FFX_FieldVM_PopOperand(a1, a3);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  v12 = (float *)sub_86C270(a1, v10);
  v5 = (float *)sub_86C270(a1, v3);
  v6 = (float *)sub_86C270(a1, v11);
  ActorByIndex = FFX_Field_GetActorByIndex(v4);
  ChrPointer = FFX_TK_GetChrPointer(ActorByIndex);
  if ( !ChrPointer )
    return 0;
  sub_835570(ChrPointer, 0, v13);
  if ( v12 )
    *v12 = v13[0];
  if ( v5 )
    *v5 = v13[1];
  result = 0;
  if ( v6 )
    *v6 = v13[2];
  return result;
}

