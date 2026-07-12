// Function: sub_800CC0
// Address: 0x800cc0
char __cdecl sub_800CC0(int a1)
{
  char *v1; // edx
  int v2; // eax
  int v3; // ecx

  v1 = (char *)&unk_12A40C0 + 32 * *(unsigned __int16 *)(a1 + 20);
  v2 = *(_WORD *)(a1 + 26) & 7;
  v3 = (unsigned __int8)v1[8];
  if ( v2 >= v3 )
  {
    v2 = 0;
    if ( v1[8] )
    {
      while ( v1[v2 + 16] != *(_BYTE *)(a1 + 24) )
      {
        if ( ++v2 >= v3 )
          goto LABEL_5;
      }
    }
    else
    {
LABEL_5:
      LOBYTE(v2) = 0;
    }
  }
  return v2;
}
