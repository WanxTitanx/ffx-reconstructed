// Function: sub_870130
// Address: 0x870130
int __cdecl sub_870130(int a1)
{
  char v1; // dl
  int result; // eax

  v1 = a1;
  if ( a1 )
    v1 = 1;
  result = (byte_1325B63[0] >> 5) & 1;
  byte_1325B63[0] ^= (byte_1325B63[0] ^ (32 * v1)) & 0x20;
  return result;
}
