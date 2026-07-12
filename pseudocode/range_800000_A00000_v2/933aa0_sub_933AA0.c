// Function: sub_933AA0
// Address: 0x933aa0
int __cdecl sub_933AA0(int a1, int n32785)
{
  int result; // eax
  int v3; // edi
  int v4; // eax
  int v5; // esi
  int v6; // [esp+Ch] [ebp-14h]
  float v7; // [esp+Ch] [ebp-14h]
  int v8; // [esp+10h] [ebp-10h]
  float v9; // [esp+10h] [ebp-10h]
  float v10; // [esp+10h] [ebp-10h]
  int v11; // [esp+14h] [ebp-Ch]
  float v12; // [esp+14h] [ebp-Ch]
  int v13; // [esp+18h] [ebp-8h]
  float v14; // [esp+18h] [ebp-8h]
  float v15; // [esp+18h] [ebp-8h]
  int v16; // [esp+1Ch] [ebp-4h]
  int v17; // [esp+2Ch] [ebp+Ch]
  float v18; // [esp+2Ch] [ebp+Ch]
  float v19; // [esp+2Ch] [ebp+Ch]
  float v20; // [esp+2Ch] [ebp+Ch]
  float v21; // [esp+2Ch] [ebp+Ch]

  result = n32785 - 32771;
  if ( n32785 == 32771 )
  {
    unk_193C0F8 = 0;
  }
  else
  {
    result = n32785 - 32785;
    if ( n32785 == 32785 )
    {
      v13 = sub_7293C0();
      v11 = sub_729370();
      v3 = sub_729380();
      v17 = v3;
      v8 = sub_7294E0();
      v6 = sub_7294C0();
      v4 = sub_7294D0();
      v5 = v4;
      v16 = v4;
      if ( !v3 )
      {
        v3 = 1;
        v17 = 1;
      }
      if ( !v4 )
      {
        v5 = 1;
        v16 = 1;
      }
      sub_848820(0);
      sub_848860(0);
      sub_848880("H:");
      sub_848820(18);
      v18 = (float)v17;
      v14 = (float)v13;
      v15 = v14 / v18 * 100.0;
      sub_930BA0(v15);
      sub_848820(45);
      sub_848880(":");
      sub_848820(54);
      v12 = (float)v11;
      v19 = v12 / v18 * 100.0;
      sub_930BA0(v19);
      sub_848820(81);
      sub_848880(":%dk", v3 / 1024);
      sub_848820(0);
      sub_848860(9);
      sub_848880("P:");
      sub_848820(18);
      v20 = (float)v16;
      v9 = (float)v8;
      v10 = v9 / v20 * 100.0;
      sub_930BA0(v10);
      sub_848820(45);
      sub_848880(":");
      sub_848820(54);
      v7 = (float)v6;
      v21 = v7 / v20 * 100.0;
      sub_930BA0(v21);
      sub_848820(81);
      return sub_848880(":%dk", v5 / 1024);
    }
  }
  return result;
}
