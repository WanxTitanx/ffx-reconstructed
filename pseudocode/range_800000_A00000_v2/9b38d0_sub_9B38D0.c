// Function: sub_9B38D0
// Address: 0x9b38d0
int __thiscall sub_9B38D0(int *this, _BYTE *a2)
{
  int result; // eax

  if ( *this >= 4 && (*a2 & 8) == 0 )
    result = sub_9B3930(3);
  if ( *this >= 3 && (*a2 & 4) == 0 )
    result = sub_9B3930(2);
  if ( *this >= 2 && (*a2 & 2) == 0 )
    result = sub_9B3930(1);
  if ( *this >= 1 && (*a2 & 1) == 0 )
    return sub_9B3930(0);
  return result;
}
