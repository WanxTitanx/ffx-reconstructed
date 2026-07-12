// Function: sub_93CD20
// Address: 0x93cd20
int __cdecl sub_93CD20(int a1, float *a2, float a3, float a4)
{
  double v5; // st6
  double v6; // st7
  float v8[4]; // [esp+0h] [ebp-10h] BYREF
  float v9; // [esp+1Ch] [ebp+Ch]
  float v10; // [esp+1Ch] [ebp+Ch]
  float v11; // [esp+1Ch] [ebp+Ch]
  float v12; // [esp+1Ch] [ebp+Ch]

  if ( a3 <= (double)*a2 )
  {
    if ( *a2 <= (double)a4 )
      v9 = *a2;
    else
      v9 = a4;
    v5 = a3;
    v6 = a4;
  }
  else
  {
    v5 = a3;
    v6 = a4;
    v9 = a3;
  }
  v8[0] = v9;
  if ( a2[1] >= v5 )
  {
    if ( a2[1] <= v6 )
      v10 = a2[1];
    else
      v10 = v6;
  }
  else
  {
    v10 = v5;
  }
  v8[1] = v10;
  if ( a2[2] >= v5 )
  {
    if ( a2[2] <= v6 )
      v11 = a2[2];
    else
      v11 = v6;
  }
  else
  {
    v11 = v5;
  }
  v8[2] = v11;
  if ( a2[3] >= v5 )
  {
    if ( a2[3] <= v6 )
      v6 = a2[3];
  }
  else
  {
    v6 = v5;
  }
  v12 = v6;
  v8[3] = v12;
  return sub_93CE50(a1, v8);
}
