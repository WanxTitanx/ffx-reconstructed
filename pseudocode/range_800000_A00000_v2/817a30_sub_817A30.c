// Function: sub_817A30
// Address: 0x817a30
__int16 *__cdecl sub_817A30(int a1, __int16 *a2)
{
  __int16 *v2; // ecx
  int v3; // esi
  char *v4; // edx

  v2 = a2;
  v3 = a2[1] | (a2[2] << 16);
  v4 = (char *)&unk_12A40C0 + 32 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 544) + 20);
  switch ( (*(__int16 *)(a1 + 538) >> 12) & 7 )
  {
    case 0:
      *((_DWORD *)v4 + 3) |= v3;
      return a2 + 3;
    case 1:
      *((_DWORD *)v4 + 3) &= ~v3;
      return a2 + 3;
    case 2:
      if ( (v3 & *((_DWORD *)v4 + 3)) == 0 )
        return a2 + 4;
      return (__int16 *)((char *)a2 + a2[3]);
    case 3:
      if ( (v3 & *((_DWORD *)v4 + 3)) != 0 )
        return a2 + 4;
      else
        return (__int16 *)((char *)a2 + a2[3]);
    case 4:
      if ( (v3 & *((_DWORD *)v4 + 3)) == 0 )
        return a2 + 3;
      *(_BYTE *)(a1 + 528) = 1;
      return a2;
    case 5:
      if ( (v3 & *((_DWORD *)v4 + 3)) != 0 )
      {
        return a2 + 3;
      }
      else
      {
        *(_BYTE *)(a1 + 528) = 1;
        return a2;
      }
    default:
      return v2;
  }
}
