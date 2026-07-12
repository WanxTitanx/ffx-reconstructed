// Function: sub_81E710
// Address: 0x81e710
void __cdecl sub_81E710(int a1, unsigned int n0x10)
{
  int i; // esi
  int v4; // ebx
  int v5; // ecx
  int v6; // eax
  FILE *v7; // eax
  FILE *v8; // eax
  FILE *v9; // eax
  FILE *v10; // eax
  int j; // edi

  if ( n0x10 - 1 > 0xFFFF )
  {
    if ( (unk_12F4108 & 1) != 0 )
      nullsub_34();
  }
  else
  {
    for ( i = 0; n0x10 > 0x10; n0x10 -= v4 )
    {
      v4 = *(_DWORD *)(a1 + 12);
      if ( *(_DWORD *)a1 != 1699964243 || *(_DWORD *)(a1 + 4) != 538976368 || v4 <= 0 || (v4 & 3) != 0 )
        break;
      v5 = *(unsigned __int8 *)(a1 + 17) + (*(unsigned __int8 *)(a1 + 18) << 8);
      v6 = 0;
      if ( i <= 0 )
      {
LABEL_10:
        if ( i < 256 )
        {
          dword_12FB380[i++] = v5;
          if ( i >= 256 )
          {
            v7 = __iob_func();
            fprintf(v7 + 2, "\x1B[4;31m");
            v8 = __iob_func();
            fprintf(v8 + 2, "Too many wave datat to be loaded at the same time!!\n");
            v9 = __iob_func();
            fprintf(v9 + 2, "\x1B[0m");
            v10 = __iob_func();
            fflush(v10 + 2);
          }
        }
      }
      else
      {
        while ( v5 != dword_12FB380[v6] )
        {
          if ( ++v6 >= i )
            goto LABEL_10;
        }
      }
      a1 += v4;
    }
    for ( j = 0; j < i; ++j )
      sub_67A510(dword_12FB380[j], 0);
    sub_81D700();
  }
}
