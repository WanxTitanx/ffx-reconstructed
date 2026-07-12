// Function: sub_931050
// Address: 0x931050
void __cdecl sub_931050(int a1, int a2, int a3)
{
  int v3; // edx
  int v4; // ebx
  int n2; // ecx
  int v6; // eax
  int v7; // ecx
  int v8; // esi
  int n2_1; // ecx
  int v10; // esi
  int n2_2; // ecx
  int v12; // esi
  int n2_3; // ecx
  unsigned __int64 v14; // rdi
  int v15; // [esp+4h] [ebp-18h]
  char Buffer[16]; // [esp+8h] [ebp-14h] BYREF

  if ( unk_193C0F0 )
  {
    if ( unk_193BF80 )
    {
      if ( *(_DWORD *)unk_193BF80 )
      {
        v3 = *(_DWORD *)(*(_DWORD *)unk_193BF80 + 8);
        if ( *(int *)(v3 + 4) > 0 )
        {
          v4 = *(_DWORD *)(v3 + 8) + 192 * *(_DWORD *)(unk_193C0F0 + 648);
          switch ( a2 )
          {
            case 32769:
              sub_937780(a1, &unk_C5F1A8);
              break;
            case 32771:
              *(_DWORD *)(unk_193C0F0 + 28) = 0;
              break;
            case 32774:
              sub_93C050();
              switch ( a3 )
              {
                case '>':
                  n2 = (*(_DWORD *)(v4 + 56) & 3) + 1;
                  *(_DWORD *)(v4 + 56) &= 0xFFFFFFFC;
                  v6 = n2 > 2 ? 0 : n2;
                  v7 = *(_DWORD *)(v4 + 60);
                  *(_DWORD *)(v4 + 56) |= v6;
                  *(_DWORD *)(v4 + 60) = v7;
                  *(_DWORD *)(v4 + 60) |= v6 >> 31;
                  break;
                case '?':
                  v8 = *(_DWORD *)(v4 + 56);
                  n2_1 = ((*(_QWORD *)(v4 + 56) >> 2) & 3) + 1;
                  *(_DWORD *)(v4 + 60) = *(_DWORD *)(v4 + 60);
                  *(_DWORD *)(v4 + 56) = v8 & 0xFFFFFFF3;
                  *(_QWORD *)(v4 + 56) |= 4 * (n2_1 > 2 ? 0 : n2_1);
                  break;
                case '@':
                  v10 = *(_DWORD *)(v4 + 56);
                  n2_2 = ((*(_QWORD *)(v4 + 56) >> 4) & 3) + 1;
                  *(_DWORD *)(v4 + 60) = *(_DWORD *)(v4 + 60);
                  *(_DWORD *)(v4 + 56) = v10 & 0xFFFFFFCF;
                  *(_QWORD *)(v4 + 56) |= 16 * (n2_2 > 2 ? 0 : n2_2);
                  break;
                case 'A':
                  v12 = *(_DWORD *)(v4 + 56);
                  n2_3 = ((*(_QWORD *)(v4 + 56) >> 6) & 3) + 1;
                  *(_DWORD *)(v4 + 60) = *(_DWORD *)(v4 + 60);
                  *(_DWORD *)(v4 + 56) = v12 & 0xFFFFFF3F;
                  *(_QWORD *)(v4 + 56) |= (n2_3 > 2 ? 0 : n2_3) << 6;
                  break;
                case 'B':
                  *(_DWORD *)(unk_193C0F0 + 1032) = *(unsigned __int8 *)(v4 + 60);
                  sub_93C2E0(unk_193C0F0 + 988, unk_193C0F0 + 1032, 5, "Alpha Fix", a1);
                  break;
                case 'C':
                  *(_DWORD *)(v4 + 56) = 68;
                  *(_DWORD *)(v4 + 60) = 0;
                  break;
                case 'D':
                  *(_DWORD *)(v4 + 56) = 72;
                  *(_DWORD *)(v4 + 60) = 0;
                  break;
                case 'E':
                  *(_DWORD *)(v4 + 56) = 66;
                  *(_DWORD *)(v4 + 60) = 0;
                  break;
                case 'F':
                  *(_DWORD *)(v4 + 56) = 137;
                  *(_DWORD *)(v4 + 60) = 0;
                  break;
                default:
                  return;
              }
              break;
            case 32785:
              if ( sub_93C3D0(unk_193C0F0 + 988) )
              {
                *(_BYTE *)(v4 + 60) = 0;
                *(_DWORD *)(v4 + 60) |= *(_DWORD *)(unk_193C0F0 + 1032);
              }
              v14 = *(_QWORD *)(v4 + 56);
              v15 = *(_DWORD *)(v4 + 60);
              sub_84A710(a1, 62, off_C5E8A8[*(_DWORD *)(v4 + 56) & 3]);// "Cs"
              sub_84A710(a1, 63, off_C5E8A8[(v14 >> 2) & 3]);// "Cs"
              sub_84A710(a1, 64, off_C5E8B4[(v14 >> 4) & 3]);// "As"
              sub_84A710(a1, 65, off_C5E8A8[(v14 >> 6) & 3]);// "Cs"
              sprintf(Buffer, "%d", (unsigned __int8)v15);
              sub_84A710(a1, 66, Buffer);
              break;
            default:
              return;
          }
        }
      }
    }
  }
}
