// Function: sub_A5ACA0
// Address: 0xa5aca0
// Size: 0x6d
// Prototype: int(void)

int sub_A5ACA0()
{
  int buf; // ebx
  int result; // eax
  int v2; // edi
  _BYTE *i; // esi
  int v4; // eax

  buf = buf;
  result = 0;
  v2 = 0;
  if ( *(__int16 *)(buf + 5854) > 0 )
  {
    for ( i = (_BYTE *)(buf + 5892); ; i += 12 )
    {
      *i = 0;
      if ( !v2 )
        break;
      if ( v2 == 1 )
      {
        sub_8C6700(3);
        v4 = sub_8C66D0();
        goto LABEL_7;
      }
LABEL_9:
      result = *(__int16 *)(buf + 5854);
      if ( ++v2 >= result )
        return result;
    }
    v4 = sub_7854A0(*(_BYTE *)(dword_2305834[0] + 71100));
LABEL_7:
    if ( !v4 )
      *i = 1;
    goto LABEL_9;
  }
  return result;
}

