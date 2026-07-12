// Function: sub_93B590
// Address: 0x93b590
int __cdecl sub_93B590(float *a1, char *Buffer)
{
  int v2; // ebx
  int v3; // esi
  int v4; // eax
  _BYTE v6[8]; // [esp+Ch] [ebp-98h] BYREF
  _BYTE v7[140]; // [esp+14h] [ebp-90h] BYREF

  v2 = 0;
  sub_92B840(v6);
  sub_92BF50(v7);
  sub_92C0C0(v7, 1);
  if ( sub_92B880(v6, Buffer) )
  {
    v3 = 0;
    sub_92C0A0(v7, v6);
    while ( !sub_92BFB0(v7) )
    {
      v4 = sub_92BE40(v7, off_C60E38); // "BG"
      if ( v4 )
      {
        if ( v4 == 1 && v3 < *((_DWORD *)a1 + 1) )
        {
          sub_93AB80(v2 + *((_DWORD *)a1 + 2), (int)v7);
          ++v3;
          v2 += 192;
        }
      }
      else
      {
        sub_93AEE0(a1, (int)v7);
      }
    }
    v2 = 1;
  }
  sub_92B7F0(v6);
  nullsub_174(v7);
  return v2;
}
