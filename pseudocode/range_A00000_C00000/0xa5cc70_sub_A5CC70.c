// Function: sub_A5CC70
// Address: 0xa5cc70
// Size: 0x23e
// Prototype: 

int __cdecl sub_A5CC70(int a1)
{
  int n35; // eax

  n35 = sub_79AEA0(5);
  switch ( a1 )
  {
    case 0:
    case 1:
    case 2:
    case 3:
      if ( n35 < 35 )
        return sub_89A260("1122333344444444");
      if ( n35 < 60 )
        return sub_89A260("1111222222233333");
      if ( n35 < 100 )
        return sub_89A260("1111122222222222");
      if ( n35 < 200 )
        return sub_89A260("1111111122222222");
      if ( n35 >= 255 )
        return sub_89A260("1111111111111111");
      return sub_89A260("1111111111111222");
    case 4:
    case 5:
    case 6:
    case 7:
      if ( n35 < 25 )
        return sub_89A260("1123444444445555");
      if ( n35 < 45 )
        return sub_89A260("1122333344444444");
      if ( n35 < 90 )
        return sub_89A260("1111222222233333");
      goto LABEL_13;
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
      if ( n35 < 40 )
        return sub_89A260("1123444444445555");
      if ( n35 < 75 )
        return sub_89A260("1122333344444444");
      if ( n35 < 100 )
        return sub_89A260("1111222222233333");
      if ( n35 < 200 )
        return sub_89A260("1111122222222222");
      return sub_89A260("1111111122222222");
    case 15:
    case 16:
      if ( n35 < 30 )
        return sub_89A260("1123334444445555");
      if ( n35 < 50 )
        return sub_89A260("1122333344444444");
      if ( n35 < 100 )
        return sub_89A260("1111222222233333");
LABEL_13:
      if ( n35 < 200 )
        return sub_89A260("1111122222222222");
      if ( n35 >= 255 )
        return sub_89A260("1111111111111111");
      return sub_89A260("1111111122222222");
    case 17:
      if ( n35 < 50 )
        return sub_89A260("1346666666666666");
      if ( n35 < 75 )
        return sub_89A260("1245555555555555");
      if ( n35 < 100 )
        return sub_89A260("1244445555555555");
      if ( n35 >= 255 )
        return sub_89A260("1122333344445555");
      return sub_89A260("1233334444555555");
    case 18:
      if ( n35 < 40 )
        return sub_89A260("1357777777777777");
      if ( n35 < 75 )
        return sub_89A260("1356666666666666");
      if ( n35 < 150 )
        return sub_89A260("1346666666666666");
      if ( n35 >= 255 )
        return sub_89A260("1344555666666666");
      return sub_89A260("1345566666666666");
    default:
      return n35;
  }
}

