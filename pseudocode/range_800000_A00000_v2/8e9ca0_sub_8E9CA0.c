// Function: sub_8E9CA0
// Address: 0x8e9ca0
int __cdecl sub_8E9CA0(int a1, int a2, int a3, float a4, float a5, int a6)
{
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // esi
  unsigned __int8 n0x12; // al
  double v9; // st7
  double v10; // st6
  unsigned __int8 n0xE0; // al
  float v13; // [esp+0h] [ebp-1Ch]
  float v14; // [esp+4h] [ebp-18h]
  float v15; // [esp+18h] [ebp-4h]

  memset(&unk_1841D10, 0, 0x40u);
  v6 = (unsigned __int8 *)sub_8B6610(a1, a2);
  v7 = v6;
  if ( v6 )
  {
    n0x12 = *v6;
    if ( *v7 )
    {
      v9 = a5;
      v10 = a4;
      while ( 1 )
      {
        if ( n0x12 == 7 )
        {
          n0xE0 = v7[1];
          if ( n0xE0 >= 0xE0u && n0xE0 < 0xF0u )
          {
            v15 = (float)(n0xE0 - 224);
            *(float *)(a3 + 4) = v15 + *(float *)(a3 + 4);
          }
          v7 = (unsigned __int8 *)sub_8DFD70(v7);
        }
        else if ( n0x12 < 0x12u || n0x12 > 0x22u )
        {
          v7 = (unsigned __int8 *)sub_8B71F0(v7, &unk_1841D10);
          if ( a6 )
            sub_8FBAE0(a3, (int)&unk_1841D10, a4);
          else
            sub_8FAE40(a3, (int)&unk_1841D10, a4);
          sub_8FB940(a3, (int)&unk_1841D10, a4);
          sub_8E8ED0(a3, (int)&unk_1841D10, a4);
        }
        else
        {
          v14 = v9;
          v13 = v10;
          sub_8E9CA0(a1, (int)v7, a3, v13, v14, a6);
          v7 = (unsigned __int8 *)sub_8DFD70(v7);
        }
        n0x12 = *v7;
        if ( !*v7 )
          break;
        v10 = a4;
        v9 = a5;
      }
    }
  }
  return unk_187168C;
}
