// Function: sub_8C0BB0
// Address: 0x8c0bb0
unsigned int sub_8C0BB0()
{
  int v0; // esi
  int v1; // eax
  unsigned int result; // eax

  v0 = sub_8BEDC0();
  v1 = sub_8BEDD0();
  result = ((((v1 / 2) >> 31) & 0x3F) + v1 / 2) & 0xFFFFFFC0;
  if ( unk_186A204 == v0 )
    v0 += result;
  unk_186A1F8 = v0;
  unk_186A204 = v0;
  n128_0 = 128;
  n128_1 = 128;
  n128_2 = 128;
  n128_3 = 128;
  return result;
}
