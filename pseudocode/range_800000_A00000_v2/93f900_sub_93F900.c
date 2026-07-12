// Function: sub_93F900
// Address: 0x93f900
int __cdecl sub_93F900(int a1, int a2, int a3)
{
  int result; // eax
  int n0xFFFF; // eax
  int n0xFFFF_1; // eax
  double v6; // st7
  int v7; // [esp+1Ch] [ebp-40h] BYREF
  int v8; // [esp+20h] [ebp-3Ch] BYREF
  int v9; // [esp+24h] [ebp-38h] BYREF
  float v10; // [esp+28h] [ebp-34h]
  float v11; // [esp+2Ch] [ebp-30h] BYREF
  float v12; // [esp+30h] [ebp-2Ch] BYREF
  float v13; // [esp+34h] [ebp-28h] BYREF
  int v14[4]; // [esp+38h] [ebp-24h] BYREF
  float v15[4]; // [esp+48h] [ebp-14h] BYREF

  switch ( a2 )
  {
    case 32769:
      sub_84B6A0(a1);
      sub_84A470(a1, 1, "PLAY", 8, 2, 64, 10);
      sub_84A470(a1, 2, "PLAY2", 8, 14, 70, 10);
      sub_84A470(a1, 3, "PLAY3", 8, 26, 70, 10);
      sub_84A470(a1, 4, "SPLINE CAM", 8, 38, 100, 10);
      unk_193C378 = 0;
      result = 0;
      break;
    case 32771:
      unk_25D5F30 = 0;
      result = 0;
      break;
    case 32774:
      switch ( a3 )
      {
        case 1:
          unk_193C378 = 1;
          unk_193C380 = 0.0;
          n2_16 = 0;
          unk_193C384 = 0.001;
          return 0;
        case 2:
          unk_193C378 = 1;
          unk_193C380 = 0.0;
          n2_16 = 1;
          unk_193C384 = 0.001;
          return 0;
        case 3:
          unk_193C378 = 1;
          unk_193C380 = 0.0;
          n2_16 = 2;
          unk_193C384 = 0.001;
          return 0;
        case 4:
          if ( !dword_25D5F4C[0] || !unk_25D5F50 )
            goto LABEL_25;
          unk_193C378 = 1;
          n2_16 = 3;
          n0xFFFF = sub_86C130();
          if ( n0xFFFF == 0xFFFF )
            goto LABEL_20;
          FFX_Field_GetActorPosition(n0xFFFF, &v13, &v11, &v12);
          *(_DWORD *)(dword_25D5F54[0] - 16) = dword_25D5F4C[0];
          *(_DWORD *)(dword_25D5F54[0] - 12) = 0;
          *(_DWORD *)(dword_25D5F54[0] - 8) = 0;
          *(_DWORD *)(dword_25D5F54[0] - 4) = 0;
          sub_A44420(dword_25D5F54[0] - 16, v13, v11, v12, unk_25D5F31);
          result = 0;
          break;
        default:
          goto LABEL_25;
      }
      break;
    case 32785:
      if ( unk_193C378 )
      {
        switch ( n2_16 )
        {
          case 0:
            sub_9402C0();
            return 0;
          case 1:
            sub_940380();
            return 0;
          case 2:
            sub_940480();
            return 0;
          case 3:
            if ( !dword_25D5F4C[0] || !unk_25D5F50 )
              goto LABEL_25;
            n0xFFFF_1 = sub_86C130();
            if ( n0xFFFF_1 == 0xFFFF )
            {
LABEL_20:
              nullsub_34();
              return 0;
            }
            FFX_Field_GetActorPosition(n0xFFFF_1, &v13, &v11, &v12);
            *(_DWORD *)(dword_25D5F54[0] - 16) = dword_25D5F4C[0];
            *(_DWORD *)(dword_25D5F54[0] - 12) = 0;
            *(_DWORD *)(dword_25D5F54[0] - 8) = 0;
            *(_DWORD *)(dword_25D5F54[0] - 4) = 0;
            v6 = v13;
            sub_A44120(dword_25D5F54[0] - 16, v13, v11, v12, (int)&v9, (int)&v8, (int)&v7, unk_25D5F31);
            v10 = v6;
            unk_193C174 = *(float *)&v9;
            v15[0] = *(float *)&v9;
            unk_193C388 = *(float *)&v8;
            v15[1] = *(float *)&v8;
            unk_193C38C = *(float *)&v7;
            v15[2] = *(float *)&v7;
            if ( unk_25D5F31 )
              sub_88A440((int)v14, unk_25D5F58, unk_25D5F50, v10);
            else
              sub_88A410((int)v14, unk_25D5F58, unk_25D5F50, v10);
            FFX_BtlPool_SetPositionParameter(SLODWORD(flt_25D5EE0), *(float *)&v14[3]);
            FFX_BtlPool_WriteEntryTransform(SLODWORD(flt_25D5EE0), 0, (int)v15);
            FFX_BtlPool_WriteEntryTransform(SLODWORD(flt_25D5EE0), 1, (int)v14);
            break;
          default:
            goto LABEL_25;
        }
      }
      goto LABEL_25;
    default:
LABEL_25:
      result = 0;
      break;
  }
  return result;
}
