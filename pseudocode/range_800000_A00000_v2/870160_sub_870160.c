// Function: sub_870160
// Address: 0x870160
int __cdecl sub_870160(int a1)
{
  char v1; // dl
  int result; // eax

  v1 = a1;
  if ( a1 )
    v1 = 1;
  result = (byte_1325B63[0] >> 6) & 1;
  byte_1325B63[0] ^= (byte_1325B63[0] ^ (v1 << 6)) & 0x40;
  return result;
}
