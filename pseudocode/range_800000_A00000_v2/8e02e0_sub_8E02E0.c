// Function: sub_8E02E0
// Address: 0x8e02e0
char *__cdecl sub_8E02E0(int a1, int n14)
{
  char *U; // esi
  char *result; // eax

  unk_18714F4 = 0;
  U = aU_2; // "U"
  do
  {
    result = strstr(unk_23CBC60, U - 12);
    if ( result )
    {
      result = (char *)unk_1325A80;
      if ( unk_1325A80 == *(_DWORD *)U && n14 == 14 )
        unk_18714F4 = 1;
    }
    U += 16;
  }
  while ( (int)U < (int)&off_C5B2BC );
  return result;
}
