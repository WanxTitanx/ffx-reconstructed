// Function: sub_81CCE0
// Address: 0x81cce0
int __cdecl sub_81CCE0(int a1)
{
  int result; // eax

  while ( sub_A44760(&unk_12F4DE0) )
    ;
  do
    result = sub_A44750(&unk_12F4DE0, a1, 0, off_C49458, 64, off_C49460, 1024, 0, 0);
  while ( result < 0 );
  return result;
}
