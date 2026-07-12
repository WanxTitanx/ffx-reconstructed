// Function: FFX_Btl_SubmenuContextCommandDisplay
// Address: 0x891250
void FFX_Btl_SubmenuContextCommandDisplay()
{
  unsigned int v0; // esi
  char v1; // al
  unsigned int n12330; // eax
  unsigned int n34; // eax
  int v4; // ecx
  int KernelString_Table0; // eax
  __int16 n255; // ax
  float *v7; // eax
  int v8; // [esp+4h] [ebp-4h] BYREF

  if ( unk_23CC088[0] != 255 )
  {
    if ( (word_25D09D4 & 0x100) != 0 )
    {
      if ( (*(_DWORD *)sub_785350() & 0x400) != 0 )
        v0 = *(_DWORD *)sub_785350() & 0xFFFFFBFF;
      else
        v0 = *(_DWORD *)sub_785350() | 0x400;
      *(_DWORD *)sub_785350() = v0;
    }
    v1 = unk_133C912[240 * unk_23CC092[0]];
    if ( !v1 )
    {
      n12330 = unk_133C91C[120 * unk_23CC092[0]];
      if ( n12330 <= 0x302A )
      {
        if ( n12330 == 12330 )
          goto LABEL_17;
        n34 = n12330 - 12290;
        if ( n34 )
        {
          if ( n34 != 34 )
            goto LABEL_12;
LABEL_17:
          KernelString_Table0 = FFX_Btl_GetKernelString_Table0(12308, 0);
          sub_899E30(KernelString_Table0);
          unk_133C8FC = 1;
          return;
        }
LABEL_18:
        n255 = *(_WORD *)(*((_DWORD *)&unk_133C930 + 60 * unk_23CC092[0])
                        + 2 * *((__int16 *)&unk_133C952 + 120 * unk_23CC092[0]));
        if ( n255 != 255 )
        {
          sub_899730(n255);
          unk_133C8FC = 1;
          return;
        }
        goto LABEL_27;
      }
      if ( unk_133C91C[120 * unk_23CC092[0]] >= 0x3117u )
      {
        if ( unk_133C91C[120 * unk_23CC092[0]] <= 0x3118u )
          goto LABEL_18;
        if ( n12330 == 12579 )
          goto LABEL_17;
      }
LABEL_12:
      v4 = *((__int16 *)&unk_133C952 + 120 * unk_23CC092[0]);
      if ( *(_WORD *)(*((_DWORD *)&unk_133C930 + 60 * unk_23CC092[0]) + 2 * v4) != 255 )
      {
        sub_8998E0(*(_WORD *)(*((_DWORD *)&unk_133C930 + 60 * unk_23CC092[0]) + 2 * v4));
        unk_133C8FC = 1;
        return;
      }
      goto LABEL_27;
    }
    if ( v1 == 1 )
    {
      if ( unk_133C91C[120 * unk_23CC092[0]] == 12374 )
      {
        if ( (unk_133D138 & 0x38000) != 0 )
        {
          v7 = FFX_Btl_LookupCommandDataById(12543, &v8);
          sub_899E30(v8 + *(unsigned __int16 *)v7);
          unk_133C8FC = 1;
          return;
        }
        goto LABEL_24;
      }
      if ( !MEMORY[0x133D0A0] || MEMORY[0x133D0A0] == 3 )
      {
LABEL_24:
        sub_89A820(unk_133D1B4);
        unk_133C8FC = 1;
        return;
      }
    }
  }
LABEL_27:
  unk_133C8FC = 0;
}
