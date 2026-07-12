// Function: sub_8FA570
// Address: 0x8fa570
double __cdecl sub_8FA570(char n3)
{
  float v2; // [esp+0h] [ebp-Ch] BYREF
  float v3; // [esp+4h] [ebp-8h]
  int v4; // [esp+8h] [ebp-4h] BYREF

  if ( 0.0 == unk_1871674 )
  {
    if ( unk_1871668 == 0.0 )
    {
      sub_640F60(&v4, &v2);
      v3 = (float)v4;
      unk_1871668 = v3 * 0.001953125;
      v3 = (float)SLODWORD(v2);
      unk_187166C = v3 / 416.0;
    }
    if ( FFX_Game_GetRegion() <= 0 || FFX_Game_GetRegion() >= 9 )
    {
      v3 = (float)(int)(unk_1871668 * 0.5 + 0.5);
      unk_1871674 = v3 / unk_1871668;
      v3 = (float)(int)(unk_1871668 * 0.699999988079071 + 0.5);
      unk_1871678 = v3 / unk_1871668;
    }
    else
    {
      v3 = (float)(int)(unk_1871668 * 0.699999988079071 + 0.5);
      v2 = v3 / unk_1871668;
      unk_1871674 = v2;
      unk_1871678 = v2;
    }
  }
  if ( n3 == 3 || n3 == 1 )
    return unk_1871678;
  else
    return unk_1871674;
}
