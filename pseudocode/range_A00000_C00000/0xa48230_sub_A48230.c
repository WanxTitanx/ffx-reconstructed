// Function: sub_A48230
// Address: 0xa48230
// Size: 0x4a
// Prototype: 

int sub_A48230()
{
  int result; // eax

  result = unk_1A86108;
  *(_BYTE *)(unk_1A86108 + 5859) = 0;
  *(_BYTE *)(result + 7523) = 1;
  *(_WORD *)(result + 9187) = 769;
  *(_BYTE *)(result + 9189) = 1;
  *(_WORD *)(result + 9984) = 11;
  *(_DWORD *)(result + 9988) = sub_A56160;
  *(_BYTE *)(result + 9188) |= 0xCu;
  *(_WORD *)(result + 9176) = 0;
  return result;
}

