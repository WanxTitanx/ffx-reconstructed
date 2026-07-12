// Function: sub_9377E0
// Address: 0x9377e0
int __cdecl sub_9377E0(char *Str1)
{
  int v1; // edi
  int v2; // esi
  _BYTE v4[8]; // [esp+8h] [ebp-98h] BYREF
  _BYTE v5[4]; // [esp+10h] [ebp-90h] BYREF
  char *Str2; // [esp+14h] [ebp-8Ch]

  v1 = -1;
  sub_92B840(v4);
  if ( sub_92B880(v4, "host:/ffx/proj/map/master/info/mapid.csv") )
  {
    sub_92BF50(v5);
    sub_92C0A0(v5, v4);
    sub_92C0C0(v5, 1);
    sub_92C0F0(v5, ",");
    while ( !isdigit((unsigned __int8)*Str2) )
      sub_92B9B0(v5);
    if ( !sub_92BFB0(v5) )
    {
      while ( 1 )
      {
        v2 = sub_92BC50(v5);
        if ( !strncmp(Str1, Str2, 6u) )
          break;
        sub_92B9B0(v5);
        if ( sub_92BFB0(v5) )
        {
          v1 = -1;
          goto LABEL_9;
        }
      }
      v1 = v2;
    }
LABEL_9:
    nullsub_174(v5);
  }
  sub_92B7F0(v4);
  return v1;
}
