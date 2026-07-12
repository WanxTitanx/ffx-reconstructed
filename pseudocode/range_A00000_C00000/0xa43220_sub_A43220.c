// Function: sub_A43220
// Address: 0xa43220
// Size: 0x75
// Prototype: 

int __cdecl sub_A43220(int a1, int a2)
{
  int n16; // esi

  n16 = 0;
  while ( dword_1A85BB0[n16] )
  {
    if ( !dword_1A85BB4[n16] )
    {
      ++n16;
      break;
    }
    if ( !dword_1A85BB8[n16] )
    {
      n16 += 2;
      break;
    }
    if ( !dword_1A85BBC[n16] )
    {
      n16 += 3;
      break;
    }
    n16 += 4;
    if ( n16 >= 16 )
      break;
  }
  if ( n16 == 16 )
    sub_76F0B0("i!=FILE_NAME_CHG_TBL_CNT", "..\\program\\lib\\src\\read_debug.c", 126);
  dword_1A85BB0[n16] = a1;
  dword_1A85BF0[n16] = a2;
  return n16;
}

