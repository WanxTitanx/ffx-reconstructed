// Function: sub_939480
// Address: 0x939480
int __cdecl sub_939480(int a1, int *a2)
{
  int v2; // ebx
  int v3; // edi
  int v4; // esi
  char */2dpack.txt; // ecx
  _BYTE v8[8]; // [esp+Ch] [ebp-1A4h] BYREF
  int v9; // [esp+14h] [ebp-19Ch]
  int *v10; // [esp+18h] [ebp-198h]
  int v11; // [esp+1Ch] [ebp-194h]
  char v12[4]; // [esp+20h] [ebp-190h] BYREF
  char *Str2; // [esp+24h] [ebp-18Ch]
  char v14; // [esp+ABh] [ebp-105h] BYREF
  char Buffer[256]; // [esp+ACh] [ebp-104h] BYREF

  v9 = a1;
  v10 = a2;
  v2 = -1;
  v3 = 0;
  v4 = 0;
  v11 = -1;
  sprintf(Buffer, "host:%s", (const char *)(unk_193C0F0 + 372));
  *strrchr(Buffer, 47) = 0;
  /2dpack.txt = &v14;
  while ( *++/2dpack.txt )
    ;
  strcpy(/2dpack.txt, "/2dpack.txt");
  sub_92B840(v8);
  if ( sub_92B880(v8, Buffer) )
  {
    sub_92BF50(v12);
    sub_92C0A0(v12, v8);
    if ( !sub_92BFB0(v12) )
    {
      do
      {
        if ( *Str2 == 91 )
        {
          if ( v3 )
            break;
          v4 = 0;
          v11 = (unsigned __int8)Str2[6] + 10 * (unsigned __int8)Str2[5] - 528;
        }
        else if ( !strncmp((const char *)(unk_193C0F0 + 636), Str2, 4u) )
        {
          if ( !strncmp((const char *)(unk_193C0F0 + 636), Str2, 6u) )
            v3 = 1;
          ++v4;
          *(_BYTE *)(v9 + v4 - 1) = Str2[5] + 10 * (Str2[4] - 48) - 48;
        }
        sub_92B9B0(v12);
      }
      while ( !sub_92BFB0(v12) );
      v2 = v11;
    }
    nullsub_174(v12);
  }
  sub_92B7F0(v8);
  if ( !v3 )
    return 0;
  *v10 = v2;
  return v4;
}
