// Function: sub_A598A0
// Address: 0xa598a0
// Size: 0xac
// Prototype: int(void)

int sub_A598A0()
{
  int v0; // ecx
  int buf; // esi
  int v2; // ebx
  __int16 v3; // dx
  int v4; // edi
  __int16 v6; // [esp+8h] [ebp-4h]

  v0 = dword_2305834[0];
  buf = buf;
  v2 = 0;
  if ( *(__int16 *)(buf + 6686) > 0 )
  {
    v3 = *(_WORD *)(dword_2305834[0] + 80 * *(unsigned __int8 *)(dword_2305834[0] + 71100) + 69836);
    v6 = v3;
    v4 = buf + 6724;
    while ( 1 )
    {
      *(_BYTE *)v4 = sub_A49310(*(unsigned __int8 *)(v0 + 71100), v3, (unsigned __int16)*(_DWORD *)(v4 + 4)) == 0;
      ++v2;
      v4 += 12;
      if ( v2 >= *(__int16 *)(buf + 6686) )
        break;
      v0 = dword_2305834[0];
      v3 = v6;
    }
    buf = buf;
  }
  *(_WORD *)(buf + 6691) = 769;
  *(_BYTE *)(buf + 6693) = 1;
  *(_WORD *)(buf + 9984) = 8;
  *(_DWORD *)(buf + 9988) = sub_A560D0;
  return 8;
}

