// Function: sub_93C2E0
// Address: 0x93c2e0
char __cdecl sub_93C2E0(_DWORD *a1, unsigned __int8 *a2, int n11, __int64 a4)
{
  const char *v4; // esi
  int v5; // eax
  char *v6; // ecx
  char result; // al
  unsigned int v8; // ecx
  int v9; // eax

  sub_937EF0(a1, 8, 8, 152, 78, 6, (int)sub_93C3F0, a4, SHIDWORD(a4));
  sub_84B560(*a1, a1);
  a1[1] = a2;
  a1[2] = n11;
  v4 = (const char *)(a1 + 3);
  if ( n11 == 11 )
  {
    sprintf((char *const)a1 + 12, "%f", *(float *)a2);
    *((_BYTE *)a1 + 22) = 0;
    v8 = strlen((const char *)a1 + 12);
    a1[7] = v8;
    v9 = v8 - 1;
    if ( (int)(v8 - 1) >= 0 )
    {
      while ( v4[v9] == 48 )
      {
        v4[v9--] = 0;
        if ( v9 < 0 )
          goto LABEL_9;
      }
      if ( *((_BYTE *)a1 + v9 + 12) == 46 )
        *((_BYTE *)a1 + v9 + 12) = 0;
    }
LABEL_9:
    v6 = (char *)a1 + 13;
    do
      result = *v4++;
    while ( result );
  }
  else
  {
    v5 = sub_93C210(a2, n11);
    sprintf((char *const)a1 + 12, "%d", v5);
    v6 = (char *)a1 + 13;
    v4 += strlen(v4) + 1;
  }
  a1[7] = v4 - v6;
  a1[8] = 1;
  a1[9] = 0;
  a1[10] = 0;
  return result;
}
