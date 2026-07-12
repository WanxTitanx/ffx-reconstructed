// Function: sub_8B03F0
// Address: 0x8b03f0
int sub_8B03F0()
{
  int result; // eax

  switch ( n2_12 )
  {
    case 0:
      nullsub_34();
      n2_12 = 1;
      result = unk_1841CFC;
      break;
    case 1:
      n2_12 = 2;
      result = unk_1841CFC;
      break;
    case 2:
      sub_8ABA60(dword_C59978, 13, &unk_157F0F0);
      n2_12 = 3;
      result = unk_1841CFC;
      break;
    case 3:
      if ( sub_8ABAB0() )
        goto LABEL_8;
      n2_12 = 6;
      result = unk_1841CFC;
      break;
    case 6:
      unk_1841CFC = 1;
      nullsub_34();
      goto LABEL_8;
    default:
LABEL_8:
      result = unk_1841CFC;
      break;
  }
  return result;
}
