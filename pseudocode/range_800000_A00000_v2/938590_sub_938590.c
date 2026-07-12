// Function: sub_938590
// Address: 0x938590
int __cdecl sub_938590(int a1)
{
  int result; // eax
  int v2; // edi
  int i; // ebx
  int v4; // eax
  int i_1; // edx
  float v6; // esi
  float v7; // eax
  float *v8; // ecx
  float v9; // edx
  float v10; // esi
  int i_2; // ecx
  float v12; // edi
  float *v13; // eax
  int v14; // edi
  float v15; // edi
  int i_3; // eax
  int v17; // esi
  size_t Size; // edi
  signed int v19; // eax
  int v20; // esi
  int v21; // esi
  float v22; // eax
  int v23; // eax
  int v24; // [esp-24h] [ebp-3D4h]
  _DWORD v25[16]; // [esp+4h] [ebp-3ACh] BYREF
  int v26; // [esp+44h] [ebp-36Ch]
  float v27; // [esp+48h] [ebp-368h]
  int v28; // [esp+4Ch] [ebp-364h]
  float v29; // [esp+50h] [ebp-360h]
  float v30; // [esp+54h] [ebp-35Ch]
  int v31; // [esp+58h] [ebp-358h]
  int v32; // [esp+5Ch] [ebp-354h]
  float v33; // [esp+60h] [ebp-350h]
  _DWORD v34[4]; // [esp+64h] [ebp-34Ch] BYREF
  int v35; // [esp+74h] [ebp-33Ch] BYREF
  int v36; // [esp+78h] [ebp-338h]
  int v37; // [esp+7Ch] [ebp-334h]
  int v38; // [esp+80h] [ebp-330h]
  char v39[256]; // [esp+84h] [ebp-32Ch] BYREF
  char Buffer[5]; // [esp+184h] [ebp-22Ch] BYREF
  char v41[251]; // [esp+189h] [ebp-227h] BYREF
  char Buffer_1[256]; // [esp+284h] [ebp-12Ch] BYREF
  float v43; // [esp+384h] [ebp-2Ch]
  float v44; // [esp+38Ch] [ebp-24h]
  float v45[2]; // [esp+394h] [ebp-1Ch] BYREF
  float v46; // [esp+39Ch] [ebp-14h]
  char v47[8]; // [esp+3A4h] [ebp-Ch] BYREF

  result = unk_193BF80;
  if ( unk_193BF80 )
  {
    if ( *(_DWORD *)unk_193BF80 )
    {
      result = sub_937940(a1, (int)v47);
      if ( result )
      {
        sprintf(Buffer, "host:/ffx/proj/map/master/%c%c%c%c/%s/bin/gmobjdata.bin", v47[0], v47[1], v47[2], v47[3], v47);
        v2 = sub_62FBE0(Buffer, 2);
        v31 = v2;
        if ( v2 == -1 )
        {
          nullsub_171("Error in %s, line %d: ", "..\\program\\src\\rcBg\\rcbgSave.c", 764);
          return nullsub_171("Save(Guide Map) Failed.");
        }
        else
        {
          memset(v34, 0, sizeof(v34));
          v34[0] = *(_DWORD *)std::_Get_future_error_what(0);
          sub_62FF70(v2, v34);
          memset(v25, 0, sizeof(v25));
          for ( i = 0; i < 16; ++i )
          {
            v4 = sub_938080(a1, i);
            v25[i] = v4;
            if ( !v4 )
              break;
          }
          if ( i > 1 )
          {
            i_1 = 1;
            n964689920 = *(_QWORD *)(v25[0] + 144);
            flt_C8F988 = *(float *)(v25[0] + 152);
            flt_C8F98C[0] = *(float *)(v25[0] + 156);
            v33 = *(float *)(v25[0] + 144);
            v43 = v33;
            v26 = *(_DWORD *)(v25[0] + 148);
            v29 = *(float *)(v25[0] + 152);
            v44 = v29;
            v32 = *(_DWORD *)(v25[0] + 156);
            n964689920 = *(_QWORD *)(v25[0] + 160);
            flt_C8F988 = *(float *)(v25[0] + 168);
            flt_C8F98C[0] = *(float *)(v25[0] + 172);
            v6 = *(float *)(v25[0] + 160);
            v28 = *(_DWORD *)(v25[0] + 164);
            v27 = *(float *)(v25[0] + 168);
            v46 = v27;
            v7 = *(float *)(v25[0] + 172);
            v45[0] = v6;
            v30 = v7;
            do
            {
              v8 = (float *)(v25[i_1] + 144);
              if ( *v8 < (double)v43 )
                v43 = *v8;
              if ( v8[2] < (double)v44 )
                v44 = v8[2];
              if ( v8[4] > (double)v45[0] )
                v45[0] = v8[4];
              if ( v8[6] > (double)v46 )
                v46 = v8[6];
              ++i_1;
            }
            while ( i_1 < i );
            v9 = v46;
            v10 = v45[0];
            v29 = v44;
            i_2 = 0;
            v33 = v43;
            v12 = v43;
            do
            {
              v13 = (float *)(v25[i_2++] + 144);
              *v13 = v12;
              *((_DWORD *)v13 + 1) = v26;
              v13[2] = v29;
              *((_DWORD *)v13 + 3) = v32;
              HIDWORD(n964689920) = v28;
              flt_C8F98C[0] = v30;
              v14 = v28;
              *(float *)&n964689920 = v10;
              flt_C8F988 = v9;
              v13[4] = v10;
              *((_DWORD *)v13 + 5) = v14;
              v15 = v30;
              v13[6] = v9;
              v13[7] = v15;
              v12 = v33;
            }
            while ( i_2 < i );
            v2 = v31;
          }
          *(float *)&i_3 = 0.0;
          v33 = 0.0;
          if ( i > 0 )
          {
            do
            {
              v32 = v25[i_3];
              v17 = sub_928270(v32) + 296;
              Size = sub_92B2C0(v17);
              v37 = 0;
              v35 = 0;
              v36 = 0;
              v38 = 0;
              v35 = *(_DWORD *)std::_Get_future_error_what(11);
              v19 = Size + v17;
              v20 = v31;
              v36 = v19 / 16;
              sub_62FF70(v31, &v35);
              v24 = v20;
              v21 = v32;
              sub_938E70(v32, v24);
              memset(v45, 0, Size);
              v2 = v31;
              sub_62FF70(v31, v45);
              if ( v21 )
              {
                sub_928000(v21);
                v22 = v33;
                v25[LODWORD(v33)] = 0;
              }
              else
              {
                v22 = v33;
              }
              i_3 = LODWORD(v22) + 1;
              v33 = *(float *)&i_3;
            }
            while ( i_3 < i );
          }
          v34[0] = *(_DWORD *)std::_Get_future_error_what(12);
          sub_62FF70(v2, v34);
          FFX_FileIO_IopDevice_Close(v2);
          sprintf(Buffer_1, "chmod 666 %s", v41);
          v23 = sub_84EDE0((int)Buffer_1, v39);
          return nullsub_171("system %s ret:%d", Buffer_1, v23);
        }
      }
    }
  }
  return result;
}
