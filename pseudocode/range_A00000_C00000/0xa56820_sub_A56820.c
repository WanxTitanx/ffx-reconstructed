// Function: sub_A56820
// Address: 0xa56820
// Size: 0x30
// Prototype: double __fastcall(_DWORD)

double sub_A56820()
{
  double result; // st7

  switch ( *(_BYTE *)(dword_2305834[0] + 71116) )
  {
    case 1:
      result = 0.5;
      break;
    case 2:
      result = 0.25;
      break;
    case 3:
      result = 0.125;
      break;
    default:
      result = 1.0;
      break;
  }
  return result;
}

