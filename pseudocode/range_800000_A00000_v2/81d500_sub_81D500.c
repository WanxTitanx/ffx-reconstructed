// Function: sub_81D500
// Address: 0x81d500
int __cdecl sub_81D500(int a1, int a2, int a3)
{
  int v3; // esi
  int result; // eax

  if ( !unk_12F4100 )
  {
    if ( a1 )
    {
      v3 = unk_12F4F48;
      nullsub_33(0);
      unk_12F4DC0 = a1;
      unk_12F4DC4 = v3;
      n2048 = 20480;
      unk_12F4DCC = 0;
      unk_12F4E90 = 0;
      sub_81F000(1, 1);
    }
    *(_DWORD *)off_C49458 = a3;
    return sub_81CCE0(4);
  }
  return result;
}
