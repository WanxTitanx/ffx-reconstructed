// Function: sub_93A890
// Address: 0x93a890
int __cdecl sub_93A890(char *Buffer)
{
  int i_1; // eax
  int i_2; // edi
  int v3; // esi
  int i; // [esp+8h] [ebp-18h]
  char Buffera[16]; // [esp+Ch] [ebp-14h] BYREF

  sub_9219E0(131078);
  i_1 = sub_93A910(Buffer, "tex");
  i_2 = 0;
  for ( i = i_1; i_2 < i; ++i_2 )
  {
    v3 = sub_9220C0();
    sprintf(Buffera, "tex%d_", i_2);
    sub_93BEB0(v3, Buffer, Buffera, 2);
    i_1 = sub_9218C0(v3);
  }
  return i_1;
}
