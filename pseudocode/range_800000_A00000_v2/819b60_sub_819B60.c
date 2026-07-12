// Function: sub_819B60
// Address: 0x819b60
int __cdecl sub_819B60(int a1, int a2)
{
  float *v2; // edx
  __int16 v3; // cx
  float *v4; // eax
  int result; // eax
  __int16 v6; // [esp+14h] [ebp+8h]

  v2 = *(float **)(a1 + 544);
  v3 = *(_WORD *)(a1 + 538);
  v6 = *(_WORD *)(a2 + 2) & 0x8000;
  v4 = (float *)((char *)v2 + word_C49388[*(_WORD *)(a2 + 2) & 0xF]);
  if ( (v3 & 0x1000) != 0 )
    *v4 = 0.0 - *v4;
  if ( (v3 & 0x2000) != 0 )
    v4[1] = 0.0 - v4[1];
  if ( (v3 & 0x4000) != 0 )
    v4[2] = 0.0 - v4[2];
  if ( v3 < 0 )
    v4[3] = 0.0 - v4[3];
  if ( !v6 )
    return a2 + 4;
  if ( (v3 & 0x1000) != 0 )
    v2[36] = 0.0 - v2[36];
  if ( (v3 & 0x2000) != 0 )
    v2[37] = 0.0 - v2[37];
  result = a2 + 4;
  if ( (v3 & 0x4000) != 0 )
    v2[38] = 0.0 - v2[38];
  return result;
}
