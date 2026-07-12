// Function: sub_932A60
// Address: 0x932a60
void __cdecl sub_932A60(int a1, int a2, int a3)
{
  int v3; // ecx
  int v4; // edx
  float *v5; // ebx
  int v6; // eax
  int v7; // ecx
  float v8; // [esp+4h] [ebp-18h]
  float v9; // [esp+4h] [ebp-18h]
  float v10; // [esp+4h] [ebp-18h]
  float v11; // [esp+4h] [ebp-18h]
  char Buffer[16]; // [esp+8h] [ebp-14h] BYREF

  v3 = unk_193C0F0;
  if ( unk_193C0F0 )
  {
    if ( unk_193BF80 )
    {
      if ( *(_DWORD *)unk_193BF80 )
      {
        v4 = *(_DWORD *)(*(_DWORD *)unk_193BF80 + 8);
        if ( *(int *)(v4 + 4) > 0 )
        {
          v5 = (float *)(*(_DWORD *)(v4 + 8) + 192 * *(_DWORD *)(unk_193C0F0 + 648));
          switch ( a2 )
          {
            case 32769:
              sub_937780(a1, &unk_C5F0A8);
              *(float *)(unk_193C0F0 + 952) = v5[5];
              *(float *)(unk_193C0F0 + 956) = v5[7];
              *(float *)(unk_193C0F0 + 960) = v5[5];
              *(float *)(unk_193C0F0 + 964) = v5[6];
              break;
            case 32771:
              *(_DWORD *)(unk_193C0F0 + 24) = 0;
              break;
            case 32774:
              if ( !*(_DWORD *)(unk_193C0F0 + 920) )
              {
                *(float *)(unk_193C0F0 + 968) = v5[5];
                *(float *)(unk_193C0F0 + 972) = v5[6];
                *(float *)(unk_193C0F0 + 976) = v5[7];
                *(float *)(unk_193C0F0 + 980) = v5[8];
                switch ( a3 )
                {
                  case '6':
                  case '7':
                  case '8':
                  case '9':
                    v6 = (int)&v5[a3 - 49];
                    goto LABEL_12;
                  case ':':
                  case ';':
                  case '<':
                  case '=':
                    v6 = unk_193C0F0 + 4 * a3 + 720;
LABEL_12:
                    sub_93C670(v3 + 920, v6, "DepthZ", a1);
                    *(_DWORD *)(unk_193C0F0 + 984) = a3;
                    break;
                  default:
                    *(_DWORD *)(unk_193C0F0 + 984) = 0;
                    break;
                }
              }
              break;
            case 32785:
              if ( sub_93C840(unk_193C0F0 + 920) || sub_93C820(unk_193C0F0 + 920) )
              {
                v7 = unk_193C0F0;
                switch ( *(_DWORD *)(unk_193C0F0 + 984) )
                {
                  case ':':
                    v8 = *(float *)(unk_193C0F0 + 952);
                    v5[6] = v8;
                    v5[5] = v8;
                    goto LABEL_21;
                  case ';':
                    v9 = *(float *)(unk_193C0F0 + 956);
                    v5[8] = v9;
                    v5[7] = v9;
                    goto LABEL_21;
                  case '<':
                    v10 = *(float *)(unk_193C0F0 + 960);
                    v5[7] = v10;
                    v5[5] = v10;
                    goto LABEL_21;
                  case '=':
                    v11 = *(float *)(unk_193C0F0 + 964);
                    v5[8] = v11;
                    v5[6] = v11;
                    goto LABEL_21;
                  default:
                    break;
                }
              }
              else
              {
LABEL_21:
                v7 = unk_193C0F0;
              }
              if ( sub_93C800(v7 + 920) )
              {
                v5[5] = *(float *)(unk_193C0F0 + 968);
                v5[6] = *(float *)(unk_193C0F0 + 972);
                v5[7] = *(float *)(unk_193C0F0 + 976);
                v5[8] = *(float *)(unk_193C0F0 + 980);
              }
              sub_848530(a1);
              sub_848480(1);
              sub_8484C0(0, 0, 0, 0);
              sub_848680(61, 5);
              sub_848680(83, 5);
              sub_848680(104, 5);
              sub_848680(127, 5);
              sub_848680(61, 57);
              sub_848680(83, 57);
              sub_848680(104, 57);
              sub_848680(127, 57);
              sub_848680(30, 13);
              sub_848680(30, 25);
              sub_848680(30, 39);
              sub_848680(30, 51);
              sub_848680(158, 13);
              sub_848680(158, 25);
              sub_848680(158, 39);
              sub_848680(158, 51);
              sub_848460();
              sprintf(Buffer, "%d", (int)v5[5]);
              sub_84A710(a1, 54, Buffer);
              sprintf(Buffer, "%d", (int)v5[6]);
              sub_84A710(a1, 55, Buffer);
              sprintf(Buffer, "%d", (int)v5[7]);
              sub_84A710(a1, 56, Buffer);
              sprintf(Buffer, "%d", (int)v5[8]);
              sub_84A710(a1, 57, Buffer);
              break;
            default:
              return;
          }
        }
      }
    }
  }
}
