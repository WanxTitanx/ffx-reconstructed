// Function: sub_81E370
// Address: 0x81e370
int sub_81E370()
{
  if ( unk_12F410C != unk_12F4110 && off_C4946C > off_C49468 )
    sub_81D700();
  ++unk_12F410C;
  *(_DWORD *)off_C4945C = 1;
  *((_DWORD *)off_C4945C + 1) = unk_12F410C;
  return sub_81CD30(0, 0, (int)sub_81FDC0, 0);
}
