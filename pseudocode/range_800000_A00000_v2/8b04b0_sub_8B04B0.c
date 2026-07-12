// Function: sub_8B04B0
// Address: 0x8b04b0
int sub_8B04B0()
{
  int v0; // eax
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int (__cdecl **CoreWorkPtr)(int); // eax

  switch ( *(_DWORD *)unk_1841CE8 )
  {
    case 0:
      nullsub_34();
      unk_1841CF0 = 1;
      *(_DWORD *)unk_1841CE8 = 1;
      break;
    case 1:
      *(_DWORD *)unk_1841CE8 = 2;
      break;
    case 2:
      v0 = sub_8AC740();
      sub_8ABA60(dword_C59564, 11, v0);
      *(_DWORD *)unk_1841CE8 = 3;
      break;
    case 3:
      if ( !sub_8ABAB0() )
        *(_DWORD *)unk_1841CE8 = 4;
      break;
    case 4:
      v1 = sub_8AC270();
      sub_8ABA60(dword_C59564, 10, v1);
      *(_DWORD *)unk_1841CE8 = 5;
      break;
    case 5:
      if ( !sub_8ABAB0() )
        *(_DWORD *)unk_1841CE8 = 6;
      break;
    case 6:
      v2 = sub_8ACEC0();
      sub_8ABA60(dword_C59564, 15, v2);
      *(_DWORD *)unk_1841CE8 = 7;
      break;
    case 7:
      if ( !sub_8ABAB0() )
        *(_DWORD *)unk_1841CE8 = 8;
      break;
    case 8:
      v3 = sub_8AC3A0();
      sub_8ABA60(dword_C59564, 14, v3);
      *(_DWORD *)unk_1841CE8 = 9;
      break;
    case 9:
      if ( !sub_8ABAB0() )
        *(_DWORD *)unk_1841CE8 = 10;
      break;
    case 0xA:
      v4 = sub_8AC280();
      sub_8ABA60(dword_C59564, 8, v4);
      *(_DWORD *)unk_1841CE8 = 11;
      break;
    case 0xB:
      if ( !sub_8ABAB0() )
        *(_DWORD *)unk_1841CE8 = 12;
      break;
    case 0xC:
      sub_8ABA60(dword_C59564, 6, &unk_25D0D20);
      *(_DWORD *)unk_1841CE8 = 13;
      break;
    case 0xD:
      if ( !sub_8ABAB0() )
        *(_DWORD *)unk_1841CE8 = 14;
      break;
    case 0xE:
      v5 = sub_906B20();
      sub_8ABA60(dword_C59564, 5, v5);
      *(_DWORD *)unk_1841CE8 = 15;
      break;
    case 0xF:
      if ( !sub_8ABAB0() )
        *(_DWORD *)unk_1841CE8 = 16;
      break;
    case 0x10:
      sub_8ABA60(dword_C59564, 7, &unk_25D0DC0);
      *(_DWORD *)unk_1841CE8 = 17;
      break;
    case 0x11:
      if ( !sub_8ABAB0() )
        *(_DWORD *)unk_1841CE8 = 18;
      break;
    case 0x12:
      sub_8AE550(2);
      *(_DWORD *)unk_1841CE8 = 19;
      goto LABEL_29;
    case 0x13:
LABEL_29:
      sub_8ABA60(dword_C59564, 22, &unk_1841DD0);
      *(_DWORD *)unk_1841CE8 = 20;
      break;
    case 0x14:
      if ( !sub_8ABAB0() )
        *(_DWORD *)unk_1841CE8 = 21;
      break;
    case 0x15:
      sub_A7C7F0(2, &unk_1841DD0);
      sub_8AE6A0();
      *(_DWORD *)unk_1841CE8 = 22;
      break;
    case 0x16:
      *(_DWORD *)unk_1841CF4 = 0;
      *(_DWORD *)unk_1841CE8 = 23;
      break;
    case 0x17:
      *(_DWORD *)unk_1841CE8 = sub_782150(*(_DWORD *)unk_1841CF4) != 0 ? 24 : 26;
      break;
    case 0x18:
      CoreWorkPtr = (int (__cdecl **)(int))FFX_Btl_GetCoreWorkPtr();
      if ( !CoreWorkPtr[2](1) )
        *(_DWORD *)unk_1841CE8 = 25;
      break;
    case 0x19:
      ++*(_DWORD *)unk_1841CF4;
      *(_DWORD *)unk_1841CE8 = 23;
      break;
    case 0x1A:
      *(_DWORD *)unk_1841CE8 = 27;
      break;
    case 0x1B:
      *(_DWORD *)unk_1841CE8 = 28;
      break;
    case 0x1C:
      unk_1841CEC = 1;
      unk_1841CF0 = 0;
      nullsub_34();
      break;
    default:
      break;
  }
  if ( unk_1841D03 )
  {
    sub_89DDA0(30, 30);
    sub_89DD50("READ:%d\n", *(_DWORD *)unk_1841CE8);
    sub_89DD50("COUNT:%d\n", *(_DWORD *)unk_1841CF4);
  }
  return unk_1841CEC;
}
