// Function: sub_8997E0
// Address: 0x8997e0
int __cdecl sub_8997E0(int a1, int a2, int n12565)
{
  int n12565_1; // ecx
  int v4; // esi
  int n12565_2; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  __int16 n13; // ax
  int v10; // ecx
  char *v11; // esi

  n12565_1 = n12565;
  v4 = 240 * a1;
  n12565_2 = n12565;
  unk_133C912[240 * a1] = 0;
  v6 = n12565_2 - 254;
  if ( !v6 )
  {
    n13 = 0;
    goto LABEL_11;
  }
  v7 = v6 - 65280;
  if ( !v7 )
  {
    n13 = 13;
    goto LABEL_11;
  }
  if ( v7 == 1 )
  {
    n13 = 12;
LABEL_11:
    *(_WORD *)((char *)&unk_133C916 + v4) = n13;
    *(_WORD *)((char *)&unk_133C91A + v4) = 1;
    goto LABEL_12;
  }
  *(_WORD *)((char *)&unk_133C916 + v4) = *((unsigned __int8 *)FFX_Btl_LookupCommandDataById(n12565_1, &a1) + 23);
  v8 = 120 * unk_23CC092[0];
  *(_WORD *)((char *)&unk_133C91A + v4) = 1;
  if ( unk_133C91C[v8] == 12574 )
  {
    n256_0 = 256;
    *((_BYTE *)&unk_133C91A + v8 * 2) = 2;
  }
  if ( unk_133C91C[v8] == 12329 )
  {
    n256_0 = 0x10000;
    *(_WORD *)((char *)&unk_133C9B4 + v8 * 2) = 2;
  }
LABEL_12:
  v10 = *(__int16 *)((char *)&unk_133C916 + v4);
  v11 = (char *)&unk_133C910 + v4;
  *((_DWORD *)v11 + 8) = sub_89B510(*((__int16 *)v11 + 4), v10, v11 + 36);
  *((_DWORD *)v11 + 34) = nullsub_136;
  sub_8A1060(v11);
  return sub_8A0D70(v11);
}
