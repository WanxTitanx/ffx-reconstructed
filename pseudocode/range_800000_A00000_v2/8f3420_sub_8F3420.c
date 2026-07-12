// Function: sub_8F3420
// Address: 0x8f3420
int __cdecl sub_8F3420(int a1, int a2, int a3, int a4, char a5)
{
  int Region; // eax
  float v7; // [esp+4h] [ebp-18h]
  float v8; // [esp+14h] [ebp-8h]
  float v9; // [esp+18h] [ebp-4h]
  float v10; // [esp+30h] [ebp+14h]
  float v11; // [esp+30h] [ebp+14h]
  float v12; // [esp+30h] [ebp+14h]
  float v13; // [esp+30h] [ebp+14h]

  v8 = 0.80000001;
  v9 = -5.5;
  Region = FFX_Game_GetRegion();
  if ( Region )
  {
    if ( Region == 9 )
      v9 = -6.0;
    else
      v9 = -5.0;
  }
  else
  {
    v8 = 0.76999998;
  }
  v10 = (float)a4;
  v11 = v10 + v9;
  v7 = v11;
  v12 = (float)a3;
  v13 = v12 + 0.0;
  sub_9055C0(a2, v13, v7, a5, v8, 0.0);
  return a1;
}
