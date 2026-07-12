// Function: sub_890640
// Address: 0x890640
int __cdecl sub_890640(int n2_1, int n255_1, int n255_3, int n255_5, int n255_7)
{
  int n2; // ecx
  int n255; // edx
  int n255_2; // ebx
  int n255_4; // esi
  int n255_6; // eax
  int result; // eax

  if ( n2_1 <= 2 )
    n2 = n2_1 < 0 ? 0 : n2_1;
  else
    n2 = 2;
  if ( n255_1 <= 255 )
    n255 = n255_1 < 0 ? 0 : n255_1;
  else
    n255 = 255;
  if ( n255_3 <= 255 )
    n255_2 = n255_3 < 0 ? 0 : n255_3;
  else
    n255_2 = 255;
  if ( n255_5 <= 255 )
    n255_4 = n255_5 < 0 ? 0 : n255_5;
  else
    n255_4 = 255;
  if ( n255_7 <= 255 )
    n255_6 = n255_7 < 0 ? 0 : n255_7;
  else
    n255_6 = 255;
  result = n255 | ((n255_2 | ((n255_4 | (n255_6 << 8)) << 8)) << 8);
  *((_DWORD *)&unk_133C8C4 + n2) = result;
  return result;
}
