// Function: sub_A30600
// Address: 0xa30600
// Size: 0x138

void __thiscall sub_A30600(LONG *this, float *a2, float *a3, float *a4)
{
  LONG *p_Comperand; // edi
  LONG Comperand; // esi
  unsigned int Exchange; // eax
  float *v8; // esi
  float v9; // [esp+4h] [ebp-24h]
  float v10; // [esp+4h] [ebp-24h]
  float v11; // [esp+8h] [ebp-20h]
  float v12; // [esp+8h] [ebp-20h]
  float v13; // [esp+Ch] [ebp-1Ch]
  float v14; // [esp+Ch] [ebp-1Ch]
  float v15; // [esp+Ch] [ebp-1Ch]
  float v16; // [esp+18h] [ebp-10h]
  float v17; // [esp+18h] [ebp-10h]
  float v18; // [esp+18h] [ebp-10h]
  float v19; // [esp+1Ch] [ebp-Ch]
  float v20; // [esp+1Ch] [ebp-Ch]
  float v21; // [esp+1Ch] [ebp-Ch]
  float v22; // [esp+24h] [ebp-4h]
  float v23; // [esp+30h] [ebp+8h]
  float v24; // [esp+34h] [ebp+Ch]

  if ( *this ) /*0xa30609*/
  {
    p_Comperand = this + 1; /*0xa30613*/
    while ( 1 ) /*0xa30617*/
    {
      Comperand = *p_Comperand; /*0xa30617*/
      Exchange = *p_Comperand + 4; /*0xa30619*/
      if ( Exchange >= *(this + 2) ) /*0xa3061f*/
       ... [2369 chars total]