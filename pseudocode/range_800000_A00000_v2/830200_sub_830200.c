// Function: sub_830200
// Address: 0x830200
void __cdecl sub_830200(int a1)
{
  int v1; // eax
  _BYTE *v2; // esi
  int v3; // edi
  char n2; // al
  int v5; // eax

  if ( a1 )
  {
    v1 = sub_843220();
    v2 = unk_23C44E4;
    v3 = v1;
    if ( unk_23C44E4 != (char *)unk_23C44E4 + 2176 * unk_23C44E0 )
    {
      do
      {
        if ( v2[2] )
        {
          if ( (v2[408] & 0x10) != 0 && !sub_830420(v2) )
          {
            n2 = v2[390];
            if ( n2 != 2 && n2 != 3 )
            {
              if ( unk_1300875 )
                v5 = unk_1300875 - 1;
              else
                v5 = (char)v2[387];
              if ( v5 == 1 )
              {
                if ( sub_831800(*(unsigned __int16 *)v2) )
                  sub_82E460(v2, v2 + 276, v3);
              }
            }
          }
        }
        v2 += 2176;
      }
      while ( v2 != (char *)unk_23C44E4 + 2176 * unk_23C44E0 );
    }
  }
}
