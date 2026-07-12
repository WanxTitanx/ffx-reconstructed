// Function: sub_81F270
// Address: 0x81f270
int sub_81F270()
{
  int v0; // edx
  int n3; // esi

  v0 = unk_12F4E50;
  unk_12F4EB8 = 0;
  dword_12F4E94 = unk_12F4E50;
  if ( (unk_12F4108 & 2) != 0 )
  {
    nullsub_34();
    v0 = dword_12F4E94;
  }
  n3 = n3_15;
  unk_12F4EA0 = v0;
  if ( !unk_12F4E9C )
    return n3;
  if ( unk_12F4F00 != v0 && ((1 << (v0 & 1)) & n3_15) != 0 )
    unk_12F4EB8 = 1;
  unk_12F4F00 = v0;
  n3 = (1 << (v0 & 1)) | n3_15;
  n3_15 = n3;
  if ( unk_12F4E9C )
    return n3 & ~(1 << (v0 & 1));
  else
    return n3;
}
