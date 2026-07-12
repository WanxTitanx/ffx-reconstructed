// Function: sub_8060C0
// Address: 0x8060c0
void __cdecl sub_8060C0(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  char *v5; // eax
  unsigned __int8 v6; // bl
  int v7; // eax

  if ( a2 )
  {
    v4 = sub_7FE890(a2, 0, 0);
    if ( v4 >= 0 )
    {
      v5 = (char *)&unk_12A2280 + 32 * v4;
      if ( a4 )
      {
        v6 = v5[21];
        v5[21] = -1;
      }
      else
      {
        v6 = v5[20];
        v5[20] = -1;
      }
      sub_831440(a2, -1, -1);
      sub_831410(a2, -1, -1);
      if ( v6 != 0xFF )
      {
        v7 = sub_7E3720(a1, 4, v6);
        if ( v7 )
        {
          sub_7FF0F0(a3, v7);
          sub_7E37B0(a1, 4, v6, 0);
        }
      }
    }
  }
}
