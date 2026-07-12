// Function: sub_A5A080
// Address: 0xa5a080
// Size: 0xe4
// Prototype: 

int __cdecl sub_A5A080(__int16 *a1)
{
  unsigned __int8 n4; // al
  int v2; // edi
  __int16 v3; // si
  int v4; // ecx
  __int16 v5; // dx
  int v6; // ecx
  int v7; // ecx
  int result; // eax

  n4 = ++*((_BYTE *)a1 + 50);
  if ( n4 < 4u )
  {
    v2 = (n4 << 16) / 4;
    v3 = *a1 + ((unsigned int)(v2 * (a1[21] - *a1)) >> 16);
    v4 = a1[23];
    a1[5] = a1[1] + ((unsigned int)(v2 * (a1[22] - a1[1])) >> 16);
    v5 = a1[3];
    a1[6] = a1[2] + ((unsigned int)(v2 * (v4 - a1[2])) >> 16);
    v6 = (v2 * (a1[24] - v5)) >> 16;
    a1[4] = v3;
    a1[7] = v5 + v6;
  }
  else
  {
    a1[4] = a1[21];
    a1[5] = a1[22];
    a1[6] = a1[23];
    a1[7] = a1[24];
    *((_DWORD *)a1 + 13) = 0;
  }
  v7 = a1[7];
  a1[10] = (a1[6] + 15) / 16;
  result = (v7 + 15) / 20;
  a1[11] = result;
  return result;
}

