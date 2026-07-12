// Function: sub_81CD30
// Address: 0x81cd30
int __cdecl sub_81CD30(int a1, int a2, int a3, int a4)
{
  int result; // eax

  while ( sub_A44760(&unk_12F4E08) )
    ;
  do
    result = sub_A44750(&unk_12F4E08, a1, 0, off_C4945C, 64, off_C49464, 64, a3, a4);
  while ( result < 0 );
  return result;
}
