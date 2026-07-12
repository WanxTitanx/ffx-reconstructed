// Function: sub_931910
// Address: 0x931910
void __cdecl sub_931910(int a1, int a2, int n50)
{
  float *v3; // edi
  int v4; // eax
  double v5; // st7
  _BYTE v6[4]; // [esp+14h] [ebp-20h] BYREF
  int v7; // [esp+18h] [ebp-1Ch] BYREF
  float v8; // [esp+1Ch] [ebp-18h]
  char Buffer[16]; // [esp+20h] [ebp-14h] BYREF

  if ( unk_193C0F0 && unk_193BF80 && *(_DWORD *)unk_193BF80 )
  {
    v3 = *(float **)(*(_DWORD *)unk_193BF80 + 8);
    switch ( a2 )
    {
      case 32769:
        sub_937780(a1, &unk_C5F350);
        sub_93C110();
        break;
      case 32771:
        *(_DWORD *)(unk_193C0F0 + 32) = 0;
        break;
      case 32774:
        switch ( n50 )
        {
          case 'G':
            sub_93C2E0(unk_193C0F0 + 1036, v3 + 26, 11, "Camera Pos.X", a1);
            break;
          case 'H':
            sub_93C2E0(unk_193C0F0 + 1080, v3 + 27, 11, "Camera Pos.Y", a1);
            break;
          case 'I':
            sub_93C2E0(unk_193C0F0 + 1124, v3 + 28, 11, "Camera Pos.Z", a1);
            break;
          case 'J':
            sub_93C2E0(unk_193C0F0 + 1168, v3 + 30, 11, "Camera Ref.X", a1);
            break;
          case 'K':
            sub_93C2E0(unk_193C0F0 + 1212, v3 + 31, 11, "Camera Ref.Y", a1);
            break;
          case 'L':
            sub_93C2E0(unk_193C0F0 + 1256, v3 + 32, 11, "Camera Ref.Z", a1);
            break;
          case 'M':
            sub_93C2E0(unk_193C0F0 + 1300, v3 + 42, 11, "Camera Angle", a1);
            break;
          case 'O':
            sub_93C2E0(unk_193C0F0 + 1344, v3 + 38, 11, "Camera Rot.X", a1);
            break;
          case 'P':
            sub_93C2E0(unk_193C0F0 + 1388, v3 + 39, 11, "Camera Rot.Y", a1);
            break;
          case 'Q':
            sub_93C2E0(unk_193C0F0 + 1432, v3 + 40, 11, "Camera Rot.Z", a1);
            break;
          case 'R':
            sub_93B110(v3);
            break;
          default:
            return;
        }
        break;
      case 32778:
        sub_93C050();
        break;
      case 32779:
        if ( (unsigned int)(n50 - 71) <= 6 )
          sub_93C150(a1, n50);
        break;
      case 32785:
        if ( sub_93C120(a1) )
        {
          sub_93C060(&v7, v6);
          v4 = sub_93C100();
          switch ( v4 )
          {
            case 'G':
            case 'H':
            case 'I':
              v8 = (float)v7;
              v3[v4 - 45] = v8 * 0.1000000014901161 + v3[v4 - 45];
              break;
            case 'J':
            case 'K':
            case 'L':
              v8 = (float)v7;
              v3[v4 - 44] = v8 * 0.1000000014901161 + v3[v4 - 44];
              break;
            case 'M':
              v8 = (float)v7;
              v3[42] = v8 * 0.1000000014901161 + v3[42];
              break;
            default:
              break;
          }
        }
        sprintf(Buffer, "%.2f", v3[26]);
        sub_84A710(a1, 71, Buffer);
        sprintf(Buffer, "%.2f", v3[27]);
        sub_84A710(a1, 72, Buffer);
        sprintf(Buffer, "%.2f", v3[28]);
        sub_84A710(a1, 73, Buffer);
        sprintf(Buffer, "%.2f", v3[30]);
        sub_84A710(a1, 74, Buffer);
        sprintf(Buffer, "%.2f", v3[31]);
        sub_84A710(a1, 75, Buffer);
        sprintf(Buffer, "%.2f", v3[32]);
        sub_84A710(a1, 76, Buffer);
        sprintf(Buffer, "%.2f", v3[42]);
        sub_84A710(a1, 77, Buffer);
        sub_848820(54);
        sub_848860(92);
        v5 = sub_7BCEA0() * 57.29578018188477;
        sub_848880("%d", (int)v5);
        sprintf(Buffer, "%.2f", v3[38]);
        sub_84A710(a1, 79, Buffer);
        sprintf(Buffer, "%.2f", v3[39]);
        sub_84A710(a1, 80, Buffer);
        sprintf(Buffer, "%.2f", v3[40]);
        sub_84A710(a1, 81, Buffer);
        break;
      default:
        return;
    }
  }
}
