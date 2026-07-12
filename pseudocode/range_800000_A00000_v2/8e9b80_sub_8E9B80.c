// Function: sub_8E9B80
// Address: 0x8e9b80
int __cdecl sub_8E9B80(int a1, int a2, int a3)
{
  unsigned __int8 *v3; // eax
  unsigned __int8 *v4; // esi
  unsigned __int8 i; // al
  unsigned __int8 n0xE0; // al
  double v7; // st7
  float v9; // [esp+0h] [ebp-14h]
  float v10; // [esp+10h] [ebp-4h]

  memset(&unk_1841D10, 0, 0x40u);
  v3 = (unsigned __int8 *)sub_8B6610(a1, a2);
  v4 = v3;
  if ( v3 )
  {
    for ( i = *v3; *v4; i = *v4 )
    {
      if ( i == 7 )
      {
        n0xE0 = v4[1];
        if ( n0xE0 >= 0xE0u && n0xE0 < 0xF0u )
        {
          v10 = (float)(n0xE0 - 224);
          *(float *)(a3 + 4) = v10 + *(float *)(a3 + 4);
        }
        v4 = (unsigned __int8 *)sub_8DFD70(v4);
      }
      else if ( i < 0x12u || i > 0x22u )
      {
        v4 = (unsigned __int8 *)sub_8B71F0(v4, &unk_1841D10);
        if ( *(_BYTE *)(a3 + 26) == 1 )
        {
          sub_906260(a3, &unk_1841D10);
          sub_906270(a3, &unk_1841D10);
          v7 = flt_C5D784;
        }
        else
        {
          sub_8FCCA0(a3, &unk_1841D10, 0);
          sub_8FCAD0(a3, &unk_1841D10, 0);
          v7 = 0.77999997;
        }
        v9 = v7;
        sub_8E8ED0(a3, (int)&unk_1841D10, v9);
      }
      else
      {
        sub_8E9B80(a1, v4, a3);
        v4 = (unsigned __int8 *)sub_8DFD70(v4);
      }
    }
  }
  return unk_187168C;
}
