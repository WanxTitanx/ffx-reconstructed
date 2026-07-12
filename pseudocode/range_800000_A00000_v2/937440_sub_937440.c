// Function: sub_937440
// Address: 0x937440
int __cdecl sub_937440(int a1, int a2)
{
  double v2; // st7
  double v3; // st6
  double v4; // st6
  double v5; // st4
  float v7; // [esp+24h] [ebp-8h]
  float v8; // [esp+28h] [ebp-4h]
  float v9; // [esp+28h] [ebp-4h]
  float v10; // [esp+28h] [ebp-4h]
  float v11; // [esp+28h] [ebp-4h]
  float v12; // [esp+28h] [ebp-4h]

  v8 = (float)a1;
  v2 = v8;
  v9 = (float)unk_193C130;
  v7 = v2 / v9 * 100.0;
  v10 = (float)a2;
  v3 = v10;
  v11 = (float)unk_193C13C;
  v12 = 100.0 * (v3 / v11);
  v4 = unk_193C134;
  if ( unk_193C134 < (double)v7 )
  {
    unk_193C134 = v7;
    v4 = v7;
  }
  v5 = unk_193C140;
  if ( unk_193C140 < (double)v12 )
  {
    unk_193C140 = v12;
    v5 = v12;
  }
  return nullsub_171("Heap %x[%.1f/%.1f] : Packet %x[%.1f/%.1f]", a1, v7, v4, a2, v12, v5);
}
