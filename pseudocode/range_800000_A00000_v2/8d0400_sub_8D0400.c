// Function: sub_8D0400
// Address: 0x8d0400
int sub_8D0400()
{
  int n255; // eax

  n255 = LOWORD(MEMORY[0x1597730][*(__int16 *)(unk_186A5DC + 72)]);
  n255_4 = n255;
  if ( !(_WORD)n255 )
    n255_4 = 255;
  return n255;
}
