// Function: sub_9CC4E0
// Address: 0x9cc4e0
int __thiscall sub_9CC4E0(_DWORD *this, int a2, int a3, unsigned int n2)
{
  int result; // eax

  result = a2 - 1;
  switch ( a2 )
  {
    case 1:
    case 2:
      if ( n2 > 2 )
      {
        *(this + 117) = a3;
      }
      else
      {
        *(this + 166) = a3;
        *(this + 164) |= 2u;
      }
      break;
    case 3:
    case 4:
      if ( n2 > 2 )
      {
        *(this + 164) |= 4u;
        *(this + 167) = a3;
      }
      else
      {
        *(this + 165) = a3;
        *(this + 164) |= 1u;
      }
      break;
    default:
      return result;
  }
  return result;
}
