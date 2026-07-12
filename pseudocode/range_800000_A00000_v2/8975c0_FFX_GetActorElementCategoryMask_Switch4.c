// Function: FFX_GetActorElementCategoryMask_Switch4
// Address: 0x8975c0
char __cdecl FFX_GetActorElementCategoryMask_Switch4(unsigned __int8 a1, int n2)
{
  char result; // al

  switch ( n2 )
  {
    case 0:
      result = FFX_GetActorElemWeak_5DD(a1);
      break;
    case 1:
      result = FFX_GetActorElemAbsorb_5DA(a1);
      break;
    case 2:
      result = FFX_GetActorElemIgnore_5DB(a1);
      break;
    case 3:
      result = FFX_GetActorElemResist_5DC(a1);
      break;
    default:
      result = HIBYTE(n2);
      break;
  }
  return result;
}
