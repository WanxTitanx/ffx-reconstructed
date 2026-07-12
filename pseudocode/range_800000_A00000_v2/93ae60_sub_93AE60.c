// Function: sub_93AE60
// Address: 0x93ae60
int sub_93AE60()
{
  _DWORD *v0; // edi
  void *v1; // eax
  int v2; // esi

  sub_921770();
  if ( unk_193BF80 )
    v0 = *(_DWORD **)unk_193BF80;
  else
    v0 = 0;
  *v0 = 1;
  v1 = (void *)sub_9258A0(272);
  v0[1] = v1;
  sub_9209E0(v1);
  v2 = v0[1];
  v0[2] = v2;
  sub_93B6B0(v2);
  sub_93B3E0(v2);
  return sub_92B400(v2);
}
