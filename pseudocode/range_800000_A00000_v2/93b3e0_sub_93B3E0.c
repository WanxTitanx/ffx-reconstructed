// Function: sub_93B3E0
// Address: 0x93b3e0
int __cdecl sub_93B3E0(float *a1)
{
  _BYTE v2[8]; // [esp+8h] [ebp-198h] BYREF
  char v3[140]; // [esp+10h] [ebp-190h] BYREF
  char Buffer[256]; // [esp+9Ch] [ebp-104h] BYREF

  sprintf(Buffer, "host:%s/txt/%s.2d", (const char *)(unk_193C0F0 + 372), (const char *)(unk_193C0F0 + 636));
  if ( !sub_93B590(a1, Buffer) )
  {
    sprintf(Buffer, "host:%s/txt/%s.txt", (const char *)(unk_193C0F0 + 372), (const char *)(unk_193C0F0 + 636));
    sub_93B590(a1, Buffer);
  }
  sub_92B840(v2);
  sub_92BF50(v3);
  sub_92C0C0(v3, 1);
  sprintf(Buffer, "host:%s/txt/%scam.txt", (const char *)(unk_193C0F0 + 372), (const char *)(unk_193C0F0 + 636));
  if ( sub_92B880(v2, Buffer)
    || (sprintf(Buffer, "host:%s/txt/camera.txt", (const char *)(unk_193C0F0 + 372)), sub_92B880(v2, Buffer))
    || (sprintf(Buffer, "host:%s/txt/%s", (const char *)(unk_193C0F0 + 372), (const char *)(unk_193C0F0 + 636)),
        sub_92B880(v2, Buffer)) )
  {
    sub_92C0A0(v3, v2);
    sub_93AF60(a1, (int)v3);
  }
  sub_92B7F0(v2);
  return nullsub_174(v3);
}
