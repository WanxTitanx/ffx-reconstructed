// Function: sub_93EE10
// Address: 0x93ee10
int __usercall sub_93EE10@<eax>(int a1@<ebx>, int a2, int a3, int n15)
{
  int v4; // edi
  _DWORD *v5; // eax
  size_t Size; // edi
  void *v7; // esi
  _DWORD *v8; // ebx
  size_t v9; // edi
  int v10; // esi
  int v11; // eax
  float *v12; // esi
  int v13; // eax
  int result; // eax
  int v15; // esi
  int v16; // edi
  int v17; // edx
  int v18; // ecx
  _BYTE *j; // eax
  int v20; // esi
  int v21; // edi
  int v22; // edx
  int v23; // ecx
  _BYTE *i; // eax
  int v25; // eax
  char InitReadyMask; // al
  int v27; // eax
  int v28; // [esp-40h] [ebp-254h]
  int v29; // [esp-3Ch] [ebp-250h]
  int v30; // [esp-38h] [ebp-24Ch]
  int v31; // [esp-28h] [ebp-23Ch]
  int v32; // [esp-28h] [ebp-23Ch]
  int v33; // [esp-24h] [ebp-238h]
  int v34; // [esp-20h] [ebp-234h]
  int v35; // [esp-1Ch] [ebp-230h]
  int v36; // [esp-18h] [ebp-22Ch]
  int v37; // [esp-18h] [ebp-22Ch]
  int v38; // [esp-14h] [ebp-228h]
  int v39; // [esp-Ch] [ebp-220h]
  _DWORD *v41; // [esp+Ch] [ebp-208h]
  float v42; // [esp+Ch] [ebp-208h]
  float v43; // [esp+Ch] [ebp-208h]
  float v44; // [esp+Ch] [ebp-208h]
  float v45; // [esp+Ch] [ebp-208h]
  char Buffer[512]; // [esp+10h] [ebp-204h] BYREF

  v4 = sub_84AEC0(a2);
  switch ( a3 )
  {
    case 32769:
      sub_88E9A0(0);
      unk_193C150 = 1;
      sub_83F700(0);
      dword_25D5F4C[0] = 5;
      unk_25D5F50 = 0;
      unk_25D5F29 = 0;
      n256_2 = 256;
      v5 = (_DWORD *)FFX_Memory_Alloc(0xCu, v39);
      *v5 = 0;
      v5[1] = 0;
      v41 = v5;
      v5[2] = 0;
      sub_84B560(a2, v5);
      Size = 12 * n256_2;
      v7 = (void *)FFX_Memory_Alloc(12 * n256_2, v36);
      memset(v7, 0, Size);
      dword_25D5F48 = (int)v7;
      v8 = (_DWORD *)FFX_Memory_Alloc(Size, v31);
      memset(v8, 0, Size);
      v9 = 16 * n256_2 + 16;
      dword_25D5F44[0] = v8;
      dword_25D5F64[0] = 0;
      unk_25D5F68 = 0;
      unk_25D5F6C = 0;
      unk_25D5F70 = 0;
      dword_25D5F74[0] = 0;
      unk_25D5F78 = 0;
      v10 = FFX_Memory_Alloc(v9, v30);
      v11 = FFX_Memory_Alloc(v9, v29);
      unk_25D5F58 = v10 + 16;
      unk_25D5F60 = v11 + 16;
      v12 = (float *)(FFX_Memory_Alloc(v9, v28) + 16);
      v13 = FFX_Memory_Alloc(v9, a1);
      dword_25D5F54[0] = (int)v12;
      unk_25D5F98 = 0;
      unk_25D5F9C = 0;
      dword_25D5F5C[0] = v13 + 16;
      *v8 = 1;
      *v12 = 10.0;
      v12[1] = 0.0;
      v12[2] = 0.0;
      v12[3] = 0.0;
      v8[3] = 1;
      v12[4] = 0.0;
      v12[5] = 0.0;
      v12[6] = 0.0;
      v12[7] = 0.0;
      v8[6] = 1;
      v12[8] = -10.0;
      v12[9] = 0.0;
      v12[10] = 0.0;
      v12[11] = 0.0;
      v8[9] = 1;
      v12[12] = -20.0;
      v12[13] = 0.0;
      v12[14] = 0.0;
      v12[15] = 0.0;
      v8[12] = 1;
      v12[16] = -30.0;
      v12[17] = 0.0;
      v12[18] = 0.0;
      v12[19] = 0.0;
      sub_84B6A0(a2);
      sub_7BD3F0(0, &flt_25D5EF4);
      sub_7BD3F0(1, &flt_25D5EE4);
      LODWORD(flt_25D5EE0) = sub_7BA700(10, 3, 0);
      sub_84A470(a2, 1, "PUT 2D", 2, 0, 56, 10);
      sub_84A470(a2, 3, "SELECT CLEAR", 2, 12, 110, 10);
      sub_84A470(a2, 2, "NEW", 2, 24, 40, 10);
      sub_84A470(a2, 8, "DEL", 48, 24, 40, 10);
      sub_84A470(a2, 9, "POINT MODE", 94, 24, 94, 10);
      sub_84A470(a2, 10, "REF", 198, 24, 32, 10);
      sub_84A470(a2, 5, "PUT Num", 64, 0, 66, 10);
      sub_84A470(a2, 4, "SAME Y", 154, 0, 64, 10);
      sub_84A470(a2, 6, "ZOOM POINT", 130, 12, 94, 10);
      sub_84A470(a2, 7, "OVER POINT", 110, 36, 94, 10);
      sub_84A470(a2, 16, "LOAD", 2, 36, 42, 10);
      sub_84A470(a2, 17, "SAVE", 48, 36, 42, 10);
      sub_84A470(a2, 18, "TEST", 184, 48, 42, 10);
      sub_84A470(a2, 19, "MAIGO", 124, 48, 54, 10);
      sub_84A470(a2, 20, "2ji", 2, 48, 36, 10);
      sub_84A470(a2, 11, "NEW LINE", 44, 48, 76, 10);
      sub_84A470(a2, 12, "DEL LINE", 2, 60, 76, 10);
      sub_84A470(a2, 13, "PUT XYZW", 100, 60, 76, 10);
      sub_84A470(a2, 14, "<", 52, 72, 16, 10);
      sub_84A470(a2, 15, ">", 72, 72, 16, 10);
      sub_76F200(1);
      v41[129] = 0;
      return 0;
    case 32771:
      sub_76F200(0);
      sub_7BA650(0, 0);
      nullsub_34();
      FFX_Memory_Delete(dword_25D5F44[0], (int)"Gui_SasaCameraProc Free\n");
      FFX_Memory_Delete(dword_25D5F48, v38);
      FFX_Memory_Delete(dword_25D5F54[0] - 16, v37);
      FFX_Memory_Delete(unk_25D5F58 - 16, v35);
      FFX_Memory_Delete(dword_25D5F5C[0] - 16, v34);
      FFX_Memory_Delete(unk_25D5F60 - 16, v33);
      FFX_Memory_Delete(v4, v32);
      unk_193C150 = 0;
      sub_83F700(1);
      sub_88E9A0(1);
      return 0;
    case 32773:
      if ( n15 == 14 )
      {
        unk_25D5F7C = -1;
        v20 = dword_25D5F44[unk_25D5F90];
        v21 = dword_25D5F54[unk_25D5F90];
        if ( !v20 )
          return 0;
        if ( !v21 )
          return 0;
        v22 = dword_25D5F4C[unk_25D5F90];
        v23 = 0;
        if ( v22 <= 0 )
          return 0;
        for ( i = (_BYTE *)dword_25D5F44[unk_25D5F90]; (*i & 2) == 0; i += 12 )
        {
          if ( ++v23 >= v22 )
            return 0;
        }
        v44 = (float)(int)++*(_DWORD *)(v20 + 12 * v23 + 8);
        v45 = v44 * 3.141592025756836 / 180.0;
        *(float *)(v21 + 16 * v23 + 12) = v45;
        unk_25D5F7C = v23;
        return 0;
      }
      else
      {
        if ( n15 != 15 )
          return 0;
        unk_25D5F7C = -1;
        v15 = dword_25D5F44[unk_25D5F90];
        v16 = dword_25D5F54[unk_25D5F90];
        if ( !v15 )
          return 0;
        if ( !v16 )
          return 0;
        v17 = dword_25D5F4C[unk_25D5F90];
        v18 = 0;
        if ( v17 <= 0 )
          return 0;
        for ( j = (_BYTE *)dword_25D5F44[unk_25D5F90]; (*j & 2) == 0; j += 12 )
        {
          if ( ++v18 >= v17 )
            return 0;
        }
        v42 = (float)(int)--*(_DWORD *)(v15 + 12 * v18 + 8);
        v43 = v42 * 3.141592025756836 / 180.0;
        *(float *)(v16 + 16 * v18 + 12) = v43;
        unk_25D5F7C = v18;
        return 0;
      }
    case 32775:
      switch ( n15 )
      {
        case 1:
          unk_25D5F2C ^= 1u;
          unk_25D5F2E = 1;
          return 0;
        case 2:
          sub_9401C0();
          unk_25D5F2E = 1;
          return 0;
        case 3:
          sub_942320();
          unk_25D5F2E = 1;
          return 0;
        case 4:
          sub_942060();
          unk_25D5F2E = 1;
          return 0;
        case 5:
          unk_25D5F2D ^= 1u;
          unk_25D5F2E = 1;
          return 0;
        case 6:
          goto LABEL_41;
        case 7:
          sub_941A30();
LABEL_41:
          sub_942520();
          unk_25D5F2E = 1;
          return 0;
        case 8:
          sub_9410E0();
          unk_25D5F2E = 1;
          return 0;
        case 9:
          unk_25D5F8C = (unk_25D5F8C + 1) % 2;
          if ( unk_25D5F8C )
          {
            if ( unk_25D5F8C != 1 )
              return 0;
            sub_84A710(a2, 9, "LINE  MODE");
            return 0;
          }
          else
          {
            sub_84A710(a2, 9, "POINT MODE");
            return 0;
          }
        case 10:
          v25 = unk_25D5F90 ^ 1;
          unk_25D5F90 = v25;
          if ( v25 )
          {
            if ( v25 != 1 )
              return 0;
            sub_84A710(a2, 10, "CAM");
            result = 0;
          }
          else
          {
            sub_84A710(a2, 10, "REF");
            result = 0;
          }
          break;
        case 11:
          sub_941980();
          return 0;
        case 12:
          dword_25D5F4C[unk_25D5F90] = 0;
          return 0;
        case 13:
          sub_941AE0();
          return 0;
        case 16:
          unk_25D5F2F = 0;
          goto LABEL_43;
        case 17:
          unk_25D5F2F = 1;
LABEL_43:
          unk_25D5F98 = sub_84A920(100, 64, 280, 128, 14, sub_93E570);
          return 0;
        case 18:
          if ( unk_25D5F30 )
            return 0;
          unk_25D5F30 = 1;
          sub_84A920(100, 64, 120, 80, 14, sub_93F900);
          return 0;
        case 19:
          sub_940580();
          return 0;
        case 20:
          unk_25D5F31 ^= 1u;
          if ( unk_25D5F31 )
            sub_84A710(a2, 20, "3ji");
          else
            sub_84A710(a2, 20, "2ji");
          return 0;
        default:
          return 0;
      }
      return result;
    case 32785:
      if ( unk_25D5F31 != unk_25D5F32 )
      {
        unk_25D5F32 = unk_25D5F31;
        if ( unk_25D5F31 )
          sub_84A710(a2, 20, "3ji");
        else
          sub_84A710(a2, 20, "2ji");
      }
      if ( unk_25D5F9C )
      {
        unk_25D5F9C = 0;
        sub_84A580(unk_25D5F98);
        if ( unk_25D5F2F )
          sub_942140();
        else
          sub_941460();
      }
      if ( !sub_84B200(a2) )
      {
        if ( !unk_25D5F2E )
        {
          InitReadyMask = FFX_Battle_GetInitReadyMask(1, 0, 0);
          sub_940660(InitReadyMask);
        }
        unk_25D5F2E = 0;
      }
      sub_848820(2);
      sub_848860(84);
      sub_848880(byte_25D60B6);
      sub_848820(8);
      sub_848860(74);
      sub_848880("ROLL");
      sub_848820(108);
      sub_848860(74);
      sprintf(Buffer, "---");
      if ( unk_25D5F7C != -1 )
      {
        v27 = dword_25D5F44[unk_25D5F90] + 12 * unk_25D5F7C;
        if ( v27 )
        {
          if ( (*(_BYTE *)v27 & 2) != 0 )
            sprintf(Buffer, "%d", *(_DWORD *)(v27 + 8));
        }
      }
      sub_848880(Buffer);
      return 0;
    default:
      return 0;
  }
}
