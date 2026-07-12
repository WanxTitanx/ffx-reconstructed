// Function: sub_A5A170
// Address: 0xa5a170
// Size: 0xf9
// Prototype: 

int __cdecl sub_A5A170(__int16 *a1)
{
  unsigned __int8 n4; // al
  int result; // eax
  int v3; // edi
  __int16 v4; // si
  __int16 v5; // dx
  int v6; // ecx
  __int16 v7; // si

  n4 = ++*((_BYTE *)a1 + 50);
  if ( n4 < 4u )
  {
    v3 = ((3 - n4) << 16) / 4;
    v4 = *a1 + ((unsigned int)(v3 * (a1[21] - *a1)) >> 16);
    a1[5] = a1[1] + ((unsigned int)(v3 * (a1[22] - a1[1])) >> 16);
    v5 = a1[2];
    v6 = a1[24];
    a1[4] = v4;
    v7 = v5 + ((unsigned int)(v3 * (a1[23] - v5)) >> 16);
    LOWORD(v6) = a1[3] + ((unsigned int)(v3 * (v6 - a1[3])) >> 16);
    a1[7] = v6;
    a1[10] = (v7 + 15) / 16;
    a1[6] = v7;
    result = ((__int16)v6 + 15) / 20;
  }
  else
  {
    a1[4] = *a1;
    a1[5] = a1[1];
    a1[6] = a1[2];
    a1[7] = a1[3];
    a1[10] = a1[8];
    result = (unsigned __int16)a1[9];
    *((_DWORD *)a1 + 13) = 0;
  }
  a1[11] = result;
  return result;
}

