// Function: sub_9CA880
// Address: 0x9ca880
double __thiscall sub_9CA880(float *this, int a2, int n6)
{
  double result; // st7
  float v4; // [esp+0h] [ebp-4h]

  v4 = 0.0;
  switch ( a2 )
  {
    case 1:
    case 2:
      if ( n6 < 0 )
        goto LABEL_12;
      if ( n6 >= 3 )
      {
        if ( n6 >= 6 )
          goto LABEL_12;
        result = *(this + 117);
      }
      else
      {
        result = *(this + 166);
      }
      break;
    case 3:
    case 4:
      if ( n6 < 0 )
        goto LABEL_12;
      if ( n6 >= 3 )
      {
        if ( n6 < 6 )
          v4 = *(this + 167);
        goto LABEL_12;
      }
      result = *(this + 165);
      break;
    default:
LABEL_12:
      result = v4;
      break;
  }
  return result;
}
