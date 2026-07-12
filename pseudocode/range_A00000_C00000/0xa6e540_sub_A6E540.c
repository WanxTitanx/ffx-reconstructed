// Function: sub_A6E540
// Address: 0xa6e540
// Size: 0x8f
// Prototype: 

char __cdecl sub_A6E540(unsigned int *a1, unsigned int a2)
{
  char result; // al
  unsigned int v3; // ebx
  _DWORD *i; // esi

  result = a2;
  v3 = 0;
  *a1 = a2;
  a1[1] = 0;
  for ( i = a1 + 4; v3 < *a1; i += 8 )
  {
    *i = unk_C8F508[0];
    i[1] = LODWORD(flt_C8F50C);
    i[2] = LODWORD(flt_C8F510);
    i[3] = LODWORD(flt_C8F514[0]);
    i[4] = unk_C8F508[0];
    i[5] = LODWORD(flt_C8F50C);
    i[6] = LODWORD(flt_C8F510);
    i[7] = LODWORD(flt_C8F514[0]);
    *((_WORD *)i + 14) = 32;
    *((_WORD *)i + 6) = -32640;
    *((_BYTE *)i + 15) = 0x80;
    result = sub_7E5C50(64) + 64;
    *((_BYTE *)i + 14) = result;
    ++v3;
  }
  return result;
}

