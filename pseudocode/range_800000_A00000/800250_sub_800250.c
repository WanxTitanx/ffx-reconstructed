// Function: sub_800250
// Address: 0x800250
// Size: 0x5c

unsigned __int16 sub_800250()
{
  unsigned __int16 result; // ax

  while ( 1 ) /*0x800250*/
  {
    if ( unk_23C3648 ) /*0x800257*/
    {
      if ( unk_23C3648 != -1 || sub_885E40(0) ) /*0x800260*/
        goto LABEL_10; /*0x80026a*/
      unk_23C3648 = 0; /*0x80026c*/
    }
    if ( !unk_23C364C ) /*0x800278*/
      goto LABEL_9; /*0x800278*/
    if ( unk_23C364C == -1 && !sub_885E40(0) ) /*0x800281*/
      break; /*0x800281*/
LABEL_10:
    FFX_Magic_ProcessPendingQueue_structural(); /*0x8002a4*/
  }
  unk_23C364C = 0; /*0x80028d*/
LABEL_9:
  result = word_23C3642; /*0x800292*/
  if ( word_23C3642 ) /*0x80029b*/
    goto LABEL_10; /*0x80029b*/
  return result; /*0x8002ab*/
}
