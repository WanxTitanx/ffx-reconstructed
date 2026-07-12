// Function: sub_8E2930
// Address: 0x8e2930
int sub_8E2930()
{
  int result; // eax

  unk_23CC130 = 0;
  result = sub_8A9B40();
  if ( result )
    return (*(int (__cdecl **)(int (*)(), _DWORD, _DWORD))(result + 8))(sub_8E2910, 0, 0);
  return result;
}
