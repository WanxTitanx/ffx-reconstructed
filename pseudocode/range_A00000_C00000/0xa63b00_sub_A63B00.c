// Function: sub_A63B00
// Address: 0xa63b00
// Size: 0x43e
// Prototype: 

int sub_A63B00()
{
  char v0; // bl
  const char *v1; // eax
  int i; // eax
  char lpBuffer[8192]; // [esp+4h] [ebp-2104h] BYREF
  char Buffer[256]; // [esp+2004h] [ebp-104h] BYREF

  v0 = unk_2322790;
  memset(&unk_2321540, 0, 0xF00u);
  n512_0 = 512;
  v1 = (const char *)sub_820720();
  if ( !v1 || !*v1 )
    return 0;
  sprintf(Buffer, "host0:/home/%s/ffxprog/lib/effect.rg", v1);
  unk_2322790 = 1;
  if ( !sub_7E5BE0(Buffer) )
  {
    nullsub_34();
    unk_2322790 = v0;
    return 0;
  }
  sub_7E5BB0((int)Buffer, lpBuffer);
  unk_2322790 = v0;
  unk_2322664 = 0;
  for ( i = sub_A63620(lpBuffer, (int)&Buffer_6); i >= 0; i = sub_A63620(Buffer_6, (int)&Buffer_6) )
  {
    switch ( i )
    {
      case 2:
        unk_2322790 = *(_DWORD *)byte_2322668 != 0;
        break;
      case 3:
        unk_2321582 = *(_WORD *)byte_2322668;
        break;
      case 4:
        unk_2321580 = *(_WORD *)byte_2322668;
        break;
      case 5:
        unk_2321549 = byte_2322668[0];
        break;
      case 6:
        unk_2321541 = byte_2322668[0];
        break;
      case 7:
        sub_A63AD0(byte_2322140, byte_2322450);
        break;
      case 8:
        sub_A63AD0(byte_2322040, byte_2322450);
        break;
      case 9:
        unk_23215DC = *(LPVOID *)byte_2322668;
        break;
      case 10:
        unk_23215D8 = *(LPVOID *)byte_2322668;
        break;
      case 11:
        unk_23215FC = *(_DWORD *)byte_2322668;
        break;
      case 12:
        sub_A63AD0(byte_2321740, byte_2322450);
        break;
      case 13:
        sub_A63AD0(byte_2321640, byte_2322450);
        break;
      case 14:
        unk_23215C4 = *(LPVOID *)byte_2322668;
        break;
      case 15:
        unk_23215C0 = *(LPVOID *)byte_2322668;
        break;
      case 16:
        MEMORY[0x23215F0] = *(_DWORD *)byte_2322668;
        break;
      case 17:
        sub_A63AD0(byte_2321940, byte_2322450);
        break;
      case 18:
        sub_A63AD0(byte_2321840, byte_2322450);
        break;
      case 19:
        unk_23215CC = *(LPVOID *)byte_2322668;
        break;
      case 20:
        unk_23215C8 = *(LPVOID *)byte_2322668;
        break;
      case 21:
        MEMORY[0x23215F4] = *(_DWORD *)byte_2322668;
        break;
      case 22:
        sub_A63AD0(byte_2321B40, byte_2322450);
        break;
      case 23:
        sub_A63AD0(byte_2321A40, byte_2322450);
        break;
      case 24:
        unk_23215D4 = *(LPVOID *)byte_2322668;
        break;
      case 25:
        unk_23215D0 = *(LPVOID *)byte_2322668;
        break;
      case 26:
        MEMORY[0x23215F8] = *(_DWORD *)byte_2322668;
        break;
      case 27:
        sub_A63AD0(byte_2321C40, byte_2322450);
        break;
      case 28:
        unk_23215E0 = *(_DWORD *)byte_2322668;
        break;
      case 29:
        unk_2321600 = *(_DWORD *)byte_2322668;
        break;
      case 30:
        sub_A63AD0(byte_2321F40, byte_2322450);
        break;
      case 31:
        sub_A63AD0(byte_2321E40, byte_2322450);
        break;
      case 32:
        unk_23215EC = *(LPVOID *)byte_2322668;
        break;
      case 33:
        unk_23215E8 = *(LPVOID *)byte_2322668;
        break;
      case 34:
        unk_2321542 = byte_2322668[0];
        sub_7E6350(byte_2322668[0]);
        break;
      case 35:
        unk_2321543 = byte_2322668[0];
        break;
      case 36:
        unk_2321544 = byte_2322668[0];
        break;
      case 37:
        unk_232278C = ((byte_2322668[0] & 1) != 0) - 1;
        unk_232278E = -((byte_2322668[0] & 2) != 0);
        break;
      case 38:
        unk_2321545 = byte_2322668[0];
        break;
      case 39:
        unk_2321546 = byte_2322668[0];
        break;
      case 40:
        unk_2321547 = byte_2322668[0];
        break;
      case 41:
        unk_2321548 = byte_2322668[0];
        break;
      case 42:
        unk_232154B = byte_2322668[0];
        break;
      case 43:
        n512_0 = *(_WORD *)byte_2322668;
        break;
      case 44:
        unk_232154A = byte_2322668[0];
        break;
      default:
        continue;
    }
  }
  nullsub_34();
  nullsub_34();
  return unk_2322790;
}

