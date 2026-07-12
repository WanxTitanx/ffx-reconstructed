// Function: sub_899E30
// Address: 0x899e30
int __cdecl sub_899E30(char *KernelString_Table0)
{
  char *KernelString_Table0_1; // esi
  char v2; // al
  int result; // eax

  KernelString_Table0_1 = KernelString_Table0;
  if ( KernelString_Table0 )
  {
    memset(&unk_133F4F8, 0, 0x80u);
    do
    {
      v2 = *KernelString_Table0_1;
      KernelString_Table0_1[&unk_133F4F8 - (_UNKNOWN *)KernelString_Table0] = *KernelString_Table0_1;
      ++KernelString_Table0_1;
    }
    while ( v2 );
    return sub_8B9600(0, &unk_133F4F8, &unk_133F4F4, &unk_133F4F0, 0, 0);
  }
  return result;
}
