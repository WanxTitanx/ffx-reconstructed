// Function: sub_892500
// Address: 0x892500
void __cdecl sub_892500(int a1)
{
  double v1; // st7
  double v2; // st7
  double v3; // st7
  int v4; // ebx
  double v5; // st7
  double v6; // st7
  int v7; // esi
  int v8; // edi
  double v9; // st7
  int v10; // [esp+10h] [ebp-28h]
  int v11; // [esp+14h] [ebp-24h] BYREF
  int v12; // [esp+18h] [ebp-20h]
  float v13; // [esp+24h] [ebp-14h] BYREF
  float v14; // [esp+28h] [ebp-10h]
  float v15; // [esp+2Ch] [ebp-Ch]
  float v16; // [esp+30h] [ebp-8h]

  sub_7950C0(a1, &flt_133FA28);
  v1 = unk_133FA3C;
  sub_4CEC00(unk_133FA3C);
  v13 = v1 * unk_133F9C8 + flt_133FA28;
  v14 = unk_133F9CC + unk_133FA2C;
  v2 = unk_133FA3C;
  sub_4CEBE0(unk_133FA3C);
  v15 = v2 * unk_133F9C8 + unk_133FA30;
  v16 = 1.0;
  if ( sub_642AA0(&v11, &v13) > 0.0 )
  {
    v3 = unk_133FA3C;
    v4 = v11;
    v10 = v12;
    sub_4CEC00(unk_133FA3C);
    v13 = v3 * unk_133F9D8 + flt_133FA28;
    v14 = unk_133F9DC + unk_133FA2C;
    v5 = unk_133FA3C;
    sub_4CEBE0(unk_133FA3C);
    v15 = v5 * unk_133F9D8 + unk_133FA30;
    v16 = 1.0;
    if ( sub_642AA0(&v11, &v13) > 0.0 )
    {
      v6 = unk_133FA3C;
      v7 = v11;
      v8 = v12;
      sub_4CEC00(unk_133FA3C);
      v13 = v6 * unk_133F9E8 + flt_133FA28;
      v14 = unk_133F9EC + unk_133FA2C;
      v9 = unk_133FA3C;
      sub_4CEBE0(unk_133FA3C);
      v15 = v9 * unk_133F9E8 + unk_133FA30;
      v16 = 1.0;
      if ( sub_642AA0(&v11, &v13) > 0.0 )
        sub_901190(v4, v10, v7, v8, v11, v12, unk_133F794, unk_133FA48);
    }
  }
}
