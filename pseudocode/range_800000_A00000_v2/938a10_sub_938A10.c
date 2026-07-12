// Function: sub_938A10
// Address: 0x938a10
void __cdecl sub_938A10(int a1)
{
  int *v1; // ebx
  int v2; // edi
  int v3; // edx
  int v4; // ecx
  int v5; // eax
  int v6; // ecx
  _DWORD *v7; // esi
  int v8; // edi
  size_t Size; // ebx
  signed int v10; // eax
  int v11; // eax
  int v12; // [esp+4h] [ebp-358h]
  int v13; // [esp+8h] [ebp-354h]
  int v14; // [esp+Ch] [ebp-350h]
  int *v15; // [esp+10h] [ebp-34Ch]
  int v16; // [esp+14h] [ebp-348h]
  int v17; // [esp+18h] [ebp-344h]
  int v18; // [esp+1Ch] [ebp-340h]
  _DWORD v19[4]; // [esp+20h] [ebp-33Ch] BYREF
  int v20; // [esp+30h] [ebp-32Ch] BYREF
  int v21; // [esp+34h] [ebp-328h]
  __int16 v22; // [esp+38h] [ebp-324h]
  __int16 v23; // [esp+3Ah] [ebp-322h]
  int v24; // [esp+3Ch] [ebp-320h]
  char v25[256]; // [esp+40h] [ebp-31Ch] BYREF
  char Buffer[5]; // [esp+140h] [ebp-21Ch] BYREF
  char v27[251]; // [esp+145h] [ebp-217h] BYREF
  char Buffer_1[256]; // [esp+240h] [ebp-11Ch] BYREF
  _BYTE v29[16]; // [esp+340h] [ebp-1Ch] BYREF
  char v30[8]; // [esp+350h] [ebp-Ch] BYREF

  if ( unk_193BF80 )
  {
    v1 = *(int **)unk_193BF80;
    v15 = *(int **)unk_193BF80;
    if ( *(_DWORD *)unk_193BF80 )
    {
      if ( sub_937940(a1, (int)v30) )
      {
        sprintf(Buffer, "host:/ffx/proj/map/master/%c%c%c%c/%s/bin/gmobjdata.bin", v30[0], v30[1], v30[2], v30[3], v30);
        v2 = sub_62FBE0(Buffer, 2);
        v14 = v2;
        if ( v2 == -1 )
        {
          nullsub_171("Error in %s, line %d: ", "..\\program\\src\\rcBg\\rcbgSave.c", 856);
          nullsub_171("Save(Guide Map) Failed.");
        }
        else
        {
          memset(v19, 0, sizeof(v19));
          v19[0] = *(_DWORD *)std::_Get_future_error_what(0);
          sub_62FF70(v2, v19);
          v3 = 0;
          v18 = 0;
          if ( *v1 > 0 )
          {
            v4 = 0;
            v17 = 0;
            do
            {
              v5 = v4 + v1[1];
              v6 = 0;
              v13 = v5;
              v16 = 0;
              if ( *(__int16 *)(v5 + 24) > 0 )
              {
                v7 = (_DWORD *)(v5 + 28);
                do
                {
                  v12 = *v7;
                  if ( *v7 )
                  {
                    v8 = sub_928270(*v7) + 296;
                    Size = sub_92B2C0(v8);
                    v22 = 0;
                    v20 = 0;
                    v21 = 0;
                    v24 = 0;
                    v23 = v18;
                    v20 = *(_DWORD *)std::_Get_future_error_what(11);
                    v10 = Size + v8;
                    v2 = v14;
                    v21 = v10 / 16;
                    sub_62FF70(v14, &v20);
                    sub_938E70(v12, v14);
                    memset(v29, 0, Size);
                    sub_62FF70(v14, v29);
                    v6 = v16;
                  }
                  ++v6;
                  ++v7;
                  v16 = v6;
                }
                while ( v6 < *(__int16 *)(v13 + 24) );
                v3 = v18;
                v1 = v15;
              }
              ++v3;
              v4 = v17 + 272;
              v18 = v3;
              v17 += 272;
            }
            while ( v3 < *v1 );
          }
          v19[0] = *(_DWORD *)std::_Get_future_error_what(12);
          sub_62FF70(v2, v19);
          FFX_FileIO_IopDevice_Close(v2);
          sprintf(Buffer_1, "chmod 666 %s", v27);
          v11 = sub_84EDE0((int)Buffer_1, v25);
          nullsub_171("system %s ret:%d", Buffer_1, v11);
        }
      }
    }
  }
}
