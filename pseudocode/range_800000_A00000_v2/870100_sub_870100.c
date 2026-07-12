// Function: sub_870100
// Address: 0x870100
int __cdecl sub_870100(int a1)
{
  char v1; // dl
  int result; // eax

  v1 = a1;
  if ( a1 )
    v1 = 1;
  result = (byte_1325B63[0] >> 3) & 1;
  byte_1325B63[0] ^= (byte_1325B63[0] ^ (8 * v1)) & 8;
  return result;
}
