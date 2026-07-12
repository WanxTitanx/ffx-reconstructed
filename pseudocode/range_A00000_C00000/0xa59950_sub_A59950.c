// Function: sub_A59950
// Address: 0xa59950
// Size: 0x38
// Prototype: int(void)

int sub_A59950()
{
  int buf; // eax

  sub_A5ACA0();
  buf = buf;
  *(_WORD *)(buf + 5859) = 769;
  *(_BYTE *)(buf + 5861) = 1;
  *(_WORD *)(buf + 9984) = 7;
  *(_DWORD *)(buf + 9988) = sub_A56330;
  *(_BYTE *)(buf + 5860) |= 8u;
  return buf;
}

