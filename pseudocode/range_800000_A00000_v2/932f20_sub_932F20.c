// Function: sub_932F20
// Address: 0x932f20
void __cdecl sub_932F20(int a1, int a2, int a3)
{
  int v3; // ecx
  double v4; // st7
  double v6; // st7
  int v7; // eax
  int v8; // [esp+Ch] [ebp-6Ch]
  _DWORD *v9; // [esp+10h] [ebp-68h] BYREF
  int v10[16]; // [esp+14h] [ebp-64h] BYREF
  int v11[4]; // [esp+54h] [ebp-24h] BYREF
  char Buffer[16]; // [esp+64h] [ebp-14h] BYREF

  v3 = unk_193C0F0;
  if ( unk_193C0F0 )
  {
    switch ( a2 )
    {
      case 32769:
        sub_937780(a1, &unk_C5FAB0);
        *(float *)(unk_193C0F0 + 1636) = 1.0;
        *(float *)(unk_193C0F0 + 1632) = 1.0;
        *(float *)(unk_193C0F0 + 1628) = 1.0;
        break;
      case 32771:
LABEL_55:
        *(_DWORD *)(v3 + 52) = 0;
        break;
      case 32774:
        switch ( a3 )
        {
          case 120:
            ++*(_DWORD *)(unk_193C0F0 + 1580);
            break;
          case 121:
            ++*(_DWORD *)(unk_193C0F0 + 1584);
            if ( *(int *)(v3 + 1584) >= 4 )
              *(_DWORD *)(unk_193C0F0 + 1584) = 0;
            break;
          case 122:
            ++*(_DWORD *)(unk_193C0F0 + 1588);
            break;
          case 123:
            ++*(_DWORD *)(unk_193C0F0 + 1592);
            break;
          case 124:
            sub_93C2E0(unk_193C0F0 + 1688, unk_193C0F0 + 1596, 11, "FP Pos.X", a1);
            break;
          case 125:
            *(float *)(unk_193C0F0 + 1596) = *(float *)(unk_193C0F0 + 1596) + 10.0;
            break;
          case 126:
            sub_93C2E0(unk_193C0F0 + 1732, unk_193C0F0 + 1600, 11, "FP Pos.Y", a1);
            break;
          case 127:
            *(float *)(unk_193C0F0 + 1600) = *(float *)(unk_193C0F0 + 1600) + 10.0;
            break;
          case 128:
            sub_93C2E0(unk_193C0F0 + 1776, unk_193C0F0 + 1604, 11, "FP Pos.Z", a1);
            break;
          case 129:
            *(float *)(unk_193C0F0 + 1604) = *(float *)(unk_193C0F0 + 1604) + 10.0;
            break;
          case 130:
            sub_93C2E0(unk_193C0F0 + 1820, unk_193C0F0 + 1612, 11, "Part. Ang.X", a1);
            break;
          case 131:
            *(float *)(unk_193C0F0 + 1612) = *(float *)(unk_193C0F0 + 1612) + 10.0;
            break;
          case 132:
            sub_93C2E0(unk_193C0F0 + 1864, unk_193C0F0 + 1616, 11, "Part. Ang.Y", a1);
            break;
          case 133:
            *(float *)(unk_193C0F0 + 1616) = *(float *)(unk_193C0F0 + 1616) + 10.0;
            break;
          case 134:
            sub_93C2E0(unk_193C0F0 + 1908, unk_193C0F0 + 1620, 11, "Part. Ang.Z", a1);
            break;
          case 135:
            *(float *)(unk_193C0F0 + 1620) = *(float *)(unk_193C0F0 + 1620) + 10.0;
            break;
          case 136:
            sub_93C2E0(unk_193C0F0 + 1952, unk_193C0F0 + 1628, 11, "Part. Scl.X", a1);
            break;
          case 137:
            *(float *)(unk_193C0F0 + 1628) = *(float *)(unk_193C0F0 + 1628) + 0.05000000074505806;
            break;
          case 138:
            sub_93C2E0(unk_193C0F0 + 1996, unk_193C0F0 + 1632, 11, "Part. Scl.Y", a1);
            break;
          case 139:
            *(float *)(unk_193C0F0 + 1632) = *(float *)(unk_193C0F0 + 1632) + 0.05000000074505806;
            break;
          case 140:
            sub_93C2E0(unk_193C0F0 + 2040, unk_193C0F0 + 1636, 11, "Part. Scl.Z", a1);
            break;
          case 141:
            *(float *)(unk_193C0F0 + 1636) = *(float *)(unk_193C0F0 + 1636) + 0.05000000074505806;
            break;
          case 142:
            v9 = *(_DWORD **)(unk_193C0F0 + 1628);
            v4 = *(float *)&v9;
            *(float *)(unk_193C0F0 + 1636) = *(float *)&v9;
            *(float *)(unk_193C0F0 + 1632) = v4;
            break;
          default:
            return;
        }
        break;
      case 32778:
        switch ( a3 )
        {
          case 120:
            --*(_DWORD *)(unk_193C0F0 + 1580);
            *(_DWORD *)(unk_193C0F0 + 52) = 0;
            return;
          case 121:
            if ( --*(_DWORD *)(unk_193C0F0 + 1584) >= 0 )
              goto LABEL_54;
            *(_DWORD *)(unk_193C0F0 + 1584) = 3;
            *(_DWORD *)(unk_193C0F0 + 52) = 0;
            return;
          case 122:
            --*(_DWORD *)(unk_193C0F0 + 1588);
            *(_DWORD *)(unk_193C0F0 + 52) = 0;
            return;
          case 123:
            --*(_DWORD *)(unk_193C0F0 + 1592);
            *(_DWORD *)(unk_193C0F0 + 52) = 0;
            return;
          case 124:
            *(float *)(unk_193C0F0 + 1596) = 0.0;
            *(_DWORD *)(unk_193C0F0 + 52) = 0;
            return;
          case 125:
            *(float *)(unk_193C0F0 + 1596) = *(float *)(unk_193C0F0 + 1596) - 10.0;
            *(_DWORD *)(unk_193C0F0 + 52) = 0;
            return;
          case 126:
            *(float *)(unk_193C0F0 + 1600) = 0.0;
            *(_DWORD *)(unk_193C0F0 + 52) = 0;
            return;
          case 127:
            *(float *)(unk_193C0F0 + 1600) = *(float *)(unk_193C0F0 + 1600) - 10.0;
            *(_DWORD *)(unk_193C0F0 + 52) = 0;
            return;
          case 128:
            *(float *)(unk_193C0F0 + 1604) = 0.0;
            *(_DWORD *)(unk_193C0F0 + 52) = 0;
            return;
          case 129:
            *(float *)(unk_193C0F0 + 1604) = *(float *)(unk_193C0F0 + 1604) - 10.0;
            *(_DWORD *)(unk_193C0F0 + 52) = 0;
            return;
          case 130:
            *(float *)(unk_193C0F0 + 1612) = 0.0;
            *(_DWORD *)(unk_193C0F0 + 52) = 0;
            return;
          case 131:
            *(float *)(unk_193C0F0 + 1612) = *(float *)(unk_193C0F0 + 1612) - 10.0;
            *(_DWORD *)(unk_193C0F0 + 52) = 0;
            return;
          case 132:
            *(float *)(unk_193C0F0 + 1616) = 0.0;
            *(_DWORD *)(unk_193C0F0 + 52) = 0;
            return;
          case 133:
            *(float *)(unk_193C0F0 + 1616) = *(float *)(unk_193C0F0 + 1616) - 10.0;
            *(_DWORD *)(unk_193C0F0 + 52) = 0;
            return;
          case 134:
            *(float *)(unk_193C0F0 + 1620) = 0.0;
            *(_DWORD *)(unk_193C0F0 + 52) = 0;
            return;
          case 135:
            *(float *)(unk_193C0F0 + 1620) = *(float *)(unk_193C0F0 + 1620) - 10.0;
            *(_DWORD *)(unk_193C0F0 + 52) = 0;
            return;
          case 136:
            *(float *)(unk_193C0F0 + 1628) = 0.1;
            *(_DWORD *)(unk_193C0F0 + 52) = 0;
            return;
          case 137:
            *(float *)(unk_193C0F0 + 1628) = *(float *)(unk_193C0F0 + 1628) - 0.05000000074505806;
            *(_DWORD *)(unk_193C0F0 + 52) = 0;
            return;
          case 138:
            *(float *)(unk_193C0F0 + 1632) = 0.1;
            *(_DWORD *)(unk_193C0F0 + 52) = 0;
            return;
          case 139:
            *(float *)(unk_193C0F0 + 1632) = *(float *)(unk_193C0F0 + 1632) - 0.05000000074505806;
            *(_DWORD *)(unk_193C0F0 + 52) = 0;
            return;
          case 140:
            v6 = 0.1;
            goto LABEL_53;
          case 141:
            v6 = *(float *)(unk_193C0F0 + 1636) - 0.05000000074505806;
LABEL_53:
            *(float *)(unk_193C0F0 + 1636) = v6;
LABEL_54:
            v3 = unk_193C0F0;
            goto LABEL_55;
          default:
            goto LABEL_55;
        }
      case 32785:
        sub_7293E0(*(_DWORD *)(unk_193C0F0 + 1580), 0, &v9);
        if ( *(float *)&v9 != 0.0 )
        {
          sub_72A210(*(_DWORD *)(unk_193C0F0 + 1580));
          switch ( *(_DWORD *)(unk_193C0F0 + 1584) )
          {
            case 1:
              v8 = *(_DWORD *)(unk_193C0F0 + 1592);
              v7 = sub_795090(*(_DWORD *)(unk_193C0F0 + 1588));
              sub_72A620(*(_DWORD *)(unk_193C0F0 + 1580), v7, v8);
              break;
            case 2:
              sub_72A680(*(_DWORD *)(unk_193C0F0 + 1580), *(_DWORD *)(unk_193C0F0 + 1588));
              break;
            case 3:
              *v9 |= 4u;
              break;
          }
          *v9 |= 0x60u;
          sub_930F30((int)v11, unk_193C0F0 + 1612, 11.377778, (int)v9, v10[0], v10[1]);
          sub_6EDAE0(v10);
          sub_925820(v10, unk_193C0F0 + 1628);
          sub_7E9940(v9 + 3, v10, v11, unk_193C0F0 + 1596);
        }
        sprintf(Buffer, "%d", *(_DWORD *)(unk_193C0F0 + 1580));
        sub_84A710(a1, 120, Buffer);
        switch ( *(_DWORD *)(unk_193C0F0 + 1584) )
        {
          case 0:
            sub_84A710(a1, 121, "Norm.");
            break;
          case 1:
            sub_84A710(a1, 121, "Chr.");
            break;
          case 2:
            sub_84A710(a1, 121, "Map");
            break;
          case 3:
            sub_84A710(a1, 121, "Mat.");
            break;
          default:
            break;
        }
        sprintf(Buffer, "%d", *(_DWORD *)(unk_193C0F0 + 1588));
        sub_84A710(a1, 122, Buffer);
        sprintf(Buffer, "%d", *(_DWORD *)(unk_193C0F0 + 1592));
        sub_84A710(a1, 123, Buffer);
        sprintf(Buffer, "%.2f", *(float *)(unk_193C0F0 + 1596));
        sub_84A710(a1, 124, Buffer);
        sprintf(Buffer, "%.2f", *(float *)(unk_193C0F0 + 1600));
        sub_84A710(a1, 126, Buffer);
        sprintf(Buffer, "%.2f", *(float *)(unk_193C0F0 + 1604));
        sub_84A710(a1, 128, Buffer);
        sprintf(Buffer, "%.1f", *(float *)(unk_193C0F0 + 1612));
        sub_84A710(a1, 130, Buffer);
        sprintf(Buffer, "%.1f", *(float *)(unk_193C0F0 + 1616));
        sub_84A710(a1, 132, Buffer);
        sprintf(Buffer, "%.1f", *(float *)(unk_193C0F0 + 1620));
        sub_84A710(a1, 134, Buffer);
        sprintf(Buffer, "%.2f", *(float *)(unk_193C0F0 + 1628));
        sub_84A710(a1, 136, Buffer);
        sprintf(Buffer, "%.2f", *(float *)(unk_193C0F0 + 1632));
        sub_84A710(a1, 138, Buffer);
        sprintf(Buffer, "%.2f", *(float *)(unk_193C0F0 + 1636));
        sub_84A710(a1, 140, Buffer);
        break;
      default:
        return;
    }
  }
}
