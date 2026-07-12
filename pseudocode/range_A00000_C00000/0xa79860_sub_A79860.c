// Function: sub_A79860
// Address: 0xa79860
// Size: 0x106
// Prototype: 

int __cdecl sub_A79860(int a1, int a2, int *a3)
{
  int v3; // ebx
  int v4; // edi
  int v5; // esi
  float *v6; // ebx
  float *v7; // edi
  int ActorByIndex; // eax
  int ChrPointer; // eax
  int v11; // [esp+Ch] [ebp-3Ch]
  float v12; // [esp+10h] [ebp-38h]
  float v13; // [esp+14h] [ebp-34h]
  int v14; // [esp+18h] [ebp-30h]
  float v15; // [esp+1Ch] [ebp-2Ch]
  float *v16; // [esp+20h] [ebp-28h]
  float v17[4]; // [esp+24h] [ebp-24h] BYREF
  float v18[4]; // [esp+34h] [ebp-14h] BYREF

  v11 = FFX_FieldVM_PopOperand(a1, a3);
  v3 = FFX_FieldVM_PopOperand(a1, a3);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  v12 = FFX_TK_PopStackFloat(a1, a3);
  v15 = FFX_TK_PopStackFloat(a1, a3);
  v13 = FFX_TK_PopStackFloat(a1, a3);
  v14 = FFX_FieldVM_PopOperand(a1, a3);
  v5 = FFX_FieldVM_PopOperand(a1, a3);
  v16 = (float *)sub_86C270(a1, v4);
  v6 = (float *)sub_86C270(a1, v3);
  v7 = (float *)sub_86C270(a1, v11);
  ActorByIndex = FFX_Field_GetActorByIndex(v5);
  ChrPointer = FFX_TK_GetChrPointer(ActorByIndex);
  if ( ChrPointer )
  {
    v18[0] = v13;
    v18[1] = v15;
    v18[2] = v12;
    v18[3] = 1.0;
    sub_833D90(ChrPointer, v14, v18, v17);
    if ( v16 )
      *v16 = v17[0];
    if ( v6 )
      *v6 = v17[1];
    if ( v7 )
      *v7 = v17[2];
  }
  return 0;
}

