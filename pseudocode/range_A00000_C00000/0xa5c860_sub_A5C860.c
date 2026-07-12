// Function: sub_A5C860
// Address: 0xa5c860
// Size: 0x3d
// Prototype: 

int __cdecl sub_A5C860(int a1, int a2)
{
  int n100; // eax

  switch ( a1 )
  {
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
      n100 = a2 / 2;
      if ( !(a2 / 2) )
        n100 = 1;
      break;
    default:
      nullsub_34();
      n100 = 100;
      break;
  }
  return n100;
}

