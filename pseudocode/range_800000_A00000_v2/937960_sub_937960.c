// Function: sub_937960
// Address: 0x937960
int __cdecl sub_937960(int a1, void *a2, int a3)
{
  int v3; // ebx
  const char *host:/ffx/proj/map/btlmaster/info/btlmap.csv; // esi
  size_t n8; // edi
  _BYTE v7[8]; // [esp+10h] [ebp-98h] BYREF
  _BYTE v8[4]; // [esp+18h] [ebp-90h] BYREF
  void *Src; // [esp+1Ch] [ebp-8Ch]

  v3 = 0;
  if ( a3 )
  {
    host:/ffx/proj/map/btlmaster/info/btlmap.csv = "host:/ffx/proj/map/btlmaster/info/btlmap.csv";
    n8 = 8;
  }
  else
  {
    host:/ffx/proj/map/btlmaster/info/btlmap.csv = "host:/ffx/proj/map/master/info/mapid.csv";
    n8 = 6;
  }
  sub_92B840(v7);
  if ( sub_92B880(v7, host:/ffx/proj/map/btlmaster/info/btlmap.csv) )
  {
    sub_92BF50(v8);
    sub_92C0A0(v8, v7);
    sub_92C0C0(v8, 1);
    sub_92C0F0(v8, ",");
    while ( !isdigit(*(unsigned __int8 *)Src) )
      sub_92B9B0(v8);
    if ( !sub_92BFB0(v8) )
    {
      while ( sub_92BC50(v8) != a1 )
      {
        sub_92B9B0(v8);
        if ( sub_92BFB0(v8) )
          goto LABEL_12;
      }
      memcpy(a2, Src, n8);
      *((_BYTE *)a2 + n8) = 0;
      v3 = 1;
    }
LABEL_12:
    nullsub_174(v8);
  }
  sub_92B7F0(v7);
  return v3;
}
