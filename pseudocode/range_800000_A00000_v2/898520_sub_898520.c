// Function: sub_898520
// Address: 0x898520
int sub_898520()
{
  int v0; // ebx
  int v1; // esi
  int v2; // edx
  int v3; // eax
  int v4; // eax
  int v5; // edx
  int v6; // edi
  int v7; // eax

  v0 = MEMORY[0x133F098];
  v1 = unk_133D094;
  v2 = 0;
  if ( MEMORY[0x133F098] > 0 )
  {
    do
    {
      v3 = 1 << LOBYTE(unk_133F09C[v2++]);
      v1 |= v3;
    }
    while ( v2 < MEMORY[0x133F098] );
    unk_133D094 = v1;
  }
  v4 = MEMORY[0x133F0AC];
  v5 = unk_133D098;
  v6 = 0;
  if ( MEMORY[0x133F0AC] > 0 )
  {
    do
    {
      v7 = 1 << LOBYTE(unk_133F0B0[v6++]);
      v5 |= v7;
    }
    while ( v6 < MEMORY[0x133F0AC] );
    v0 = MEMORY[0x133F098];
    v4 = MEMORY[0x133F0AC];
    unk_133D098 = v5;
  }
  unk_133D09C = v1 | v5;
  return v0 + v4;
}
