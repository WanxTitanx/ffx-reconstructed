// Function: sub_9B3580
// Address: 0x9b3580
char __thiscall sub_9B3580(float *this, float *a2)
{
  char v3; // cl
  int v4; // edx
  float *v5; // ecx
  char result; // al
  float v7; // [esp-30h] [ebp-3Ch]
  float v8; // [esp-2Ch] [ebp-38h]
  float v9; // [esp-28h] [ebp-34h]
  float v10; // [esp-14h] [ebp-20h]
  char v11; // [esp-1h] [ebp-Dh]

  v3 = 0;
  v4 = *(_DWORD *)this;
  v11 = 0;
  if ( *(int *)this > 0 )
  {
    v5 = this + 6;
    do
    {
      v7 = *a2 - *(v5 - 2);
      v8 = a2[1] - *(v5 - 1);
      v9 = a2[2] - *v5;
      v10 = v7 * v7 + v8 * v8 + v9 * v9;
      if ( *(this + 80) >= (double)v10 )
        v11 = 1;
      v5 += 4;
      --v4;
    }
    while ( v4 );
    v3 = v11;
  }
  if ( a2[3] != *(this + 79) )
    return v3;
  if ( a2[2] != *(this + 78) )
    return v3;
  if ( a2[1] != *(this + 77) )
    return v3;
  result = 1;
  if ( *a2 != *(this + 76) )
    return v3;
  return result;
}
