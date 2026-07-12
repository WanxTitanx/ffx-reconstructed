// Function: sub_937F50
// Address: 0x937f50
int __cdecl sub_937F50(_DWORD *a1)
{
  int result; // eax

  result = *a1;
  if ( *a1 )
  {
    result = sub_84AB80(*a1);
    *a1 = 0;
  }
  return result;
}
