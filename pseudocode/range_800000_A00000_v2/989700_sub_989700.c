// Function: sub_989700
// Address: 0x989700
int __cdecl sub_989700(_DWORD *this, int a2)
{
  int result; // eax

  if ( *(_DWORD *)(a2 + 40) )
  {
    sub_989700(this, *(_DWORD *)(a2 + 36));
    sub_989700(this, *(_DWORD *)(a2 + 40));
  }
  if ( a2 == *this )
    *this = 0;
  result = sub_9D4D50(*(this + 1));
  *(this + 1) = a2;
  return result;
}
