// Function: sub_935970
// Address: 0x935970
int __cdecl sub_935970(int a1, int a2, int a3)
{
  int v3; // ecx
  int result; // eax
  float v6; // [esp+10h] [ebp-18h]
  char Buffer[16]; // [esp+14h] [ebp-14h] BYREF

  v3 = unk_193C0F0;
  if ( unk_193C0F0 )
  {
    result = a2 - 32769;
    switch ( a2 )
    {
      case 32769:
        sub_937780(a1, dword_C601F0);
        *(float *)(unk_193C0F0 + 2380) = 0.1;
        *(float *)(unk_193C0F0 + 2376) = 0.1;
        result = unk_193C0F0;
        *(float *)(unk_193C0F0 + 2372) = 0.1;
        break;
      case 32771:
        *(_DWORD *)(unk_193C0F0 + 2332) = 0;
        result = unk_193C0F0;
        *(_DWORD *)(unk_193C0F0 + 68) = 0;
        break;
      case 32774:
        result = a3 - 160;
        switch ( a3 )
        {
          case 160:
            ++*(_DWORD *)(unk_193C0F0 + 2324);
            break;
          case 161:
            ++*(_DWORD *)(unk_193C0F0 + 2328);
            break;
          case 162:
            ++*(_DWORD *)(unk_193C0F0 + 2336);
            if ( *(int *)(v3 + 2336) >= 4 )
            {
              result = unk_193C0F0;
              *(_DWORD *)(unk_193C0F0 + 2336) = 0;
            }
            break;
          case 163:
            result = sub_936340(1);
            break;
          case 164:
            result = sub_93C2E0(unk_193C0F0 + 2388, unk_193C0F0 + 2340, 11, "Part. Pos.X", a1);
            break;
          case 165:
            *(float *)(unk_193C0F0 + 2340) = *(float *)(unk_193C0F0 + 2340) + 0.1000000014901161;
            break;
          case 166:
            result = sub_93C2E0(unk_193C0F0 + 2432, unk_193C0F0 + 2344, 11, "Part. Pos.Y", a1);
            break;
          case 167:
            *(float *)(unk_193C0F0 + 2344) = *(float *)(unk_193C0F0 + 2344) + 0.1000000014901161;
            break;
          case 168:
            result = sub_93C2E0(unk_193C0F0 + 2476, unk_193C0F0 + 2348, 11, "Part. Pos.Z", a1);
            break;
          case 169:
            *(float *)(unk_193C0F0 + 2348) = *(float *)(unk_193C0F0 + 2348) + 0.1000000014901161;
            break;
          case 170:
            result = sub_93C2E0(unk_193C0F0 + 2520, unk_193C0F0 + 2356, 11, "Part. Ang.X", a1);
            break;
          case 171:
            *(float *)(unk_193C0F0 + 2356) = *(float *)(unk_193C0F0 + 2356) + 10.0;
            break;
          case 172:
            result = sub_93C2E0(unk_193C0F0 + 2564, unk_193C0F0 + 2360, 11, "Part. Ang.Y", a1);
            break;
          case 173:
            *(float *)(unk_193C0F0 + 2360) = *(float *)(unk_193C0F0 + 2360) + 10.0;
            break;
          case 174:
            result = sub_93C2E0(unk_193C0F0 + 2608, unk_193C0F0 + 2364, 11, "Part. Ang.Z", a1);
            break;
          case 175:
            *(float *)(unk_193C0F0 + 2364) = *(float *)(unk_193C0F0 + 2364) + 10.0;
            break;
          case 176:
            result = sub_93C2E0(unk_193C0F0 + 2652, unk_193C0F0 + 2372, 11, "Part. Scl.X", a1);
            break;
          case 177:
            *(float *)(unk_193C0F0 + 2372) = *(float *)(unk_193C0F0 + 2372) + 0.05000000074505806;
            break;
          case 178:
            result = sub_93C2E0(unk_193C0F0 + 2696, unk_193C0F0 + 2376, 11, "Part. Scl.Y", a1);
            break;
          case 179:
            *(float *)(unk_193C0F0 + 2376) = *(float *)(unk_193C0F0 + 2376) + 0.05000000074505806;
            break;
          case 180:
            result = sub_93C2E0(unk_193C0F0 + 2740, unk_193C0F0 + 2380, 11, "Part. Scl.Z", a1);
            break;
          case 181:
            *(float *)(unk_193C0F0 + 2380) = *(float *)(unk_193C0F0 + 2380) + 0.05000000074505806;
            break;
          case 182:
            v6 = *(float *)(unk_193C0F0 + 2372);
            *(float *)(unk_193C0F0 + 2380) = v6;
            result = unk_193C0F0;
            *(float *)(unk_193C0F0 + 2376) = v6;
            break;
          default:
            return result;
        }
        break;
      case 32778:
        result = a3 - 160;
        switch ( a3 )
        {
          case 160:
            --*(_DWORD *)(unk_193C0F0 + 2324);
            break;
          case 161:
            --*(_DWORD *)(unk_193C0F0 + 2328);
            break;
          case 162:
            if ( --*(_DWORD *)(unk_193C0F0 + 2336) < 0 )
            {
              result = unk_193C0F0;
              *(_DWORD *)(unk_193C0F0 + 2336) = 3;
            }
            break;
          case 163:
            *(_DWORD *)(unk_193C0F0 + 2332) ^= 1u;
            break;
          case 164:
            *(float *)(unk_193C0F0 + 2340) = 0.0;
            break;
          case 165:
            *(float *)(unk_193C0F0 + 2340) = *(float *)(unk_193C0F0 + 2340) - 0.1000000014901161;
            break;
          case 166:
            *(float *)(unk_193C0F0 + 2344) = 0.0;
            break;
          case 167:
            *(float *)(unk_193C0F0 + 2344) = *(float *)(unk_193C0F0 + 2344) - 0.1000000014901161;
            break;
          case 168:
            *(float *)(unk_193C0F0 + 2348) = 0.0;
            break;
          case 169:
            *(float *)(unk_193C0F0 + 2348) = *(float *)(unk_193C0F0 + 2348) - 0.1000000014901161;
            break;
          case 170:
            *(float *)(unk_193C0F0 + 2356) = 0.0;
            break;
          case 171:
            *(float *)(unk_193C0F0 + 2356) = *(float *)(unk_193C0F0 + 2356) - 10.0;
            break;
          case 172:
            *(float *)(unk_193C0F0 + 2360) = 0.0;
            break;
          case 173:
            *(float *)(unk_193C0F0 + 2360) = *(float *)(unk_193C0F0 + 2360) - 10.0;
            break;
          case 174:
            *(float *)(unk_193C0F0 + 2364) = 0.0;
            break;
          case 175:
            *(float *)(unk_193C0F0 + 2364) = *(float *)(unk_193C0F0 + 2364) - 10.0;
            break;
          case 176:
            *(float *)(unk_193C0F0 + 2372) = 0.1;
            break;
          case 177:
            *(float *)(unk_193C0F0 + 2372) = *(float *)(unk_193C0F0 + 2372) - 0.05000000074505806;
            break;
          case 178:
            *(float *)(unk_193C0F0 + 2376) = 0.1;
            break;
          case 179:
            *(float *)(unk_193C0F0 + 2376) = *(float *)(unk_193C0F0 + 2376) - 0.05000000074505806;
            break;
          case 180:
            *(float *)(unk_193C0F0 + 2380) = 0.1;
            break;
          case 181:
            *(float *)(unk_193C0F0 + 2380) = *(float *)(unk_193C0F0 + 2380) - 0.05000000074505806;
            break;
          default:
            return result;
        }
        break;
      case 32785:
        if ( *(_DWORD *)(unk_193C0F0 + 2332) )
        {
          sub_936340(0);
          v3 = unk_193C0F0;
        }
        sprintf(Buffer, "%d", *(_DWORD *)(v3 + 2324));
        sub_84A710(a1, 160, Buffer);
        sprintf(Buffer, "%d", *(_DWORD *)(unk_193C0F0 + 2328));
        sub_84A710(a1, 161, Buffer);
        switch ( *(_DWORD *)(unk_193C0F0 + 2336) )
        {
          case 0:
            sprintf(Buffer, "Norm.");
            break;
          case 1:
            sprintf(Buffer, "Chr.Y");
            break;
          case 2:
            sprintf(Buffer, "Ang.Y");
            break;
          case 3:
            sprintf(Buffer, "Pos.");
            break;
          default:
            break;
        }
        sub_84A710(a1, 162, Buffer);
        sprintf(Buffer, "%.2f", *(float *)(unk_193C0F0 + 2340));
        sub_84A710(a1, 164, Buffer);
        sprintf(Buffer, "%.2f", *(float *)(unk_193C0F0 + 2344));
        sub_84A710(a1, 166, Buffer);
        sprintf(Buffer, "%.2f", *(float *)(unk_193C0F0 + 2348));
        sub_84A710(a1, 168, Buffer);
        sprintf(Buffer, "%.1f", *(float *)(unk_193C0F0 + 2356));
        sub_84A710(a1, 170, Buffer);
        sprintf(Buffer, "%.1f", *(float *)(unk_193C0F0 + 2360));
        sub_84A710(a1, 172, Buffer);
        sprintf(Buffer, "%.1f", *(float *)(unk_193C0F0 + 2364));
        sub_84A710(a1, 174, Buffer);
        sprintf(Buffer, "%.2f", *(float *)(unk_193C0F0 + 2372));
        sub_84A710(a1, 176, Buffer);
        sprintf(Buffer, "%.2f", *(float *)(unk_193C0F0 + 2376));
        sub_84A710(a1, 178, Buffer);
        sprintf(Buffer, "%.2f", *(float *)(unk_193C0F0 + 2380));
        result = sub_84A710(a1, 180, Buffer);
        break;
      default:
        return result;
    }
  }
  return result;
}
