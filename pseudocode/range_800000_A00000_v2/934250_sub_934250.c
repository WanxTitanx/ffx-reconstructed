// Function: sub_934250
// Address: 0x934250
int sub_934250()
{
  int v0; // eax
  _BYTE v2[8]; // [esp+0h] [ebp-98h] BYREF
  _BYTE v3[4]; // [esp+8h] [ebp-90h] BYREF
  LONG **p_C; // [esp+Ch] [ebp-8Ch]

  sub_92B840(v2);
  if ( sub_92B880(v2, "host:/ffx/proj/map/master/info/mapid.csv") )
  {
    sub_92BF50(v3);
    sub_92C0A0(v3, v2);
    sub_92C0C0(v3, 1);
    sub_92C0F0(v3, ",");
    while ( !isdigit(*p_C) )
      sub_92B9B0(v3);
    nullsub_171("---- Guide Map Data Convert START");
    while ( !sub_92BFB0(v3) )
    {
      v0 = sub_92BC50(v3);
      sub_938590(v0);
      sub_92B9B0(v3);
    }
    nullsub_171("---- Guide Map Data Convert END");
    nullsub_174(v3);
  }
  return sub_92B7F0(v2);
}
