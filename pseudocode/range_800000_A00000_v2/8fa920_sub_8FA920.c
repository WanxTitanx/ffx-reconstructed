// Function: sub_8FA920
// Address: 0x8fa920
double __cdecl sub_8FA920(int a1, int a2, float a3, float a4)
{
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // esi
  unsigned __int8 n0x12; // al
  double v8; // st7
  double v9; // st6
  unsigned __int8 n0xE0; // al
  float v11; // [esp+0h] [ebp-18h]
  float v12; // [esp+4h] [ebp-14h]
  float v13; // [esp+10h] [ebp-8h]
  float v14; // [esp+14h] [ebp-4h]

  memset(&unk_1841D10, 0, 0x40u);
  v14 = 0.0;
  v4 = (unsigned __int8 *)sub_8B6610(a1, a2);
  v5 = v4;
  if ( !v4 )
    return 0.0;
  n0x12 = *v4;
  if ( *v5 )
  {
    v8 = a4;
    v9 = a3;
    while ( 1 )
    {
      if ( n0x12 == 7 )
      {
        n0xE0 = v5[1];
        if ( n0xE0 >= 0xE0u && n0xE0 < 0xF0u )
        {
          v13 = (float)(n0xE0 - 224);
          v14 = v13 + v14;
        }
        v5 = (unsigned __int8 *)sub_8DFD70(v5);
      }
      else if ( n0x12 < 0x12u || n0x12 > 0x22u )
      {
        v5 = (unsigned __int8 *)sub_8B71F0(v5, &unk_1841D10);
        v14 = sub_8FA740(0, (int)&unk_1841D10, a3) + v14;
      }
      else
      {
        v12 = v8;
        v11 = v9;
        sub_8FA920(a1, (int)v5, v11, v12);
        v14 = v9 + v14;
        v5 = (unsigned __int8 *)sub_8DFD70(v5);
      }
      n0x12 = *v5;
      if ( !*v5 )
        break;
      v9 = a3;
      v8 = a4;
    }
  }
  return v14;
}
