// Function: sub_898400
// Address: 0x898400
int sub_898400()
{
  float *v0; // esi
  int result; // eax
  _DWORD *v2; // ecx
  int n20; // edi
  int v4; // esi
  int n20_1; // edi
  int n0x100000; // esi
  int v7; // [esp+4h] [ebp-4h] BYREF

  v0 = FFX_Btl_LookupCommandDataById(n255_3, &v7);
  memset(dword_133D0A4, 0, 0x70u);
  result = (*((unsigned __int16 *)v0 + 13) >> 2) & 3;
  MEMORY[0x133D0A0] = result;
  switch ( result )
  {
    case 0:
      result = 1;
      v2 = dword_133D0A4;
      do
      {
        if ( (result & unk_133D09C) != 0 )
          *v2 = result;
        result = __ROL4__(result, 1);
        ++v2;
      }
      while ( (int)v2 < (int)&dword_133D114 );
      break;
    case 1:
      n20 = 0;
      v4 = 1;
      do
      {
        if ( (v4 & unk_133D094) != 0 )
        {
          result = (int)&dword_133D0A4[sub_795050(n20)];
          *(_DWORD *)result |= v4;
        }
        v4 = __ROL4__(v4, 1);
        ++n20;
      }
      while ( n20 < 20 );
      n20_1 = 20;
      n0x100000 = 0x100000;
      do
      {
        if ( (n0x100000 & unk_133D098) != 0 )
        {
          result = (int)&dword_133D0F4[sub_795050(n20_1)];
          *(_DWORD *)result |= n0x100000;
        }
        n0x100000 = __ROL4__(n0x100000, 1);
        ++n20_1;
      }
      while ( n20_1 < 28 );
      break;
    case 2:
      dword_133D0A4[0] = unk_133D094;
      dword_133D0F4[0] = unk_133D098;
      result = unk_133D098;
      break;
    case 3:
      result = 1 << MEMORY[0x133D090];
      dword_133D0A4[MEMORY[0x133D090]] = 1 << MEMORY[0x133D090];
      break;
  }
  return result;
}
