// Function: sub_890290
// Address: 0x890290
int __cdecl sub_890290(int n3_1, int n255_1, int n255_3, int n255_5, int n255_7)
{
  int n3; // ecx
  int n255; // edx
  int n255_2; // ebx
  int n255_4; // esi
  int n255_6; // eax
  int result; // eax

  if ( n3_1 <= 3 )
    n3 = n3_1 < 0 ? 0 : n3_1;
  else
    n3 = 3;
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
  dword_133C8A4[n3] = result;
  return result;
}
