// Function: sub_850940
// Address: 0x850940
int __cdecl sub_850940(int a1)
{
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int result; // eax

  v1 = sub_844CF0(0);
  sub_84A710(a1, 26, v1);
  v2 = sub_844CF0(1);
  sub_84A710(a1, 10, v2);
  v3 = sub_844CD0();
  if ( v3 )
  {
    v4 = v3 - 1;
    if ( !v4 )
    {
      sub_84A710(a1, 38, "User");
      sub_84A710(a1, 27, "USER");
      return sub_84A710(a1, 9, "MAP");
    }
    result = v4 - 1;
    if ( result )
      return result;
    sub_84A710(a1, 38, "Battle");
  }
  else
  {
    sub_84A710(a1, 38, "Master");
  }
  sub_84A710(a1, 27, "MAP");
  return sub_84A710(a1, 9, "LOCALE");
}
