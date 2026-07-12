// Function: sub_800250
// Address: 0x800250
unsigned __int16 sub_800250()
{
  unsigned __int16 result; // ax

  while ( 1 )
  {
    if ( unk_23C3648 )
    {
      if ( unk_23C3648 != -1 || sub_885E40(0) )
        goto LABEL_10;
      unk_23C3648 = 0;
    }
    if ( !unk_23C364C )
      goto LABEL_9;
    if ( unk_23C364C == -1 && !sub_885E40(0) )
      break;
LABEL_10:
    FFX_Magic_ProcessPendingQueue_structural();
  }
  unk_23C364C = 0;
LABEL_9:
  result = word_23C3642;
  if ( word_23C3642 )
    goto LABEL_10;
  return result;
}
