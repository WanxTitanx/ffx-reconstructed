// Function: sub_8F3300
// Address: 0x8f3300
int __cdecl sub_8F3300(int a1, int a2, int a3, int a4, char a5)
{
  int Region; // eax
  float v7; // [esp+4h] [ebp-14h]
  float v8; // [esp+14h] [ebp-4h]
  float v9; // [esp+2Ch] [ebp+14h]
  float v10; // [esp+2Ch] [ebp+14h]
  float v11; // [esp+2Ch] [ebp+14h]
  float v12; // [esp+2Ch] [ebp+14h]

  v8 = -3.0;
  Region = FFX_Game_GetRegion();
  if ( Region && (Region <= 8 || Region > 11) )
    v8 = -2.0;
  v9 = (float)a4;
  v10 = v9 + v8;
  v7 = v10;
  v11 = (float)a3;
  v12 = v11 + 4.0;
  sub_9055C0(a2, v12, v7, a5, 0.80000001, 0.0);
  return a1;
}
