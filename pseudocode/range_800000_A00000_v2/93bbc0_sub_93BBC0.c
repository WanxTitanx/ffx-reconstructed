// Function: sub_93BBC0
// Address: 0x93bbc0
int __cdecl sub_93BBC0(int n26, _DWORD *a2, int a3, _DWORD *a4, int a5)
{
  int *i; // esi
  int result; // eax
  char Buffer_1[256]; // [esp+14h] [ebp-114h] BYREF
  char Buffer[16]; // [esp+114h] [ebp-14h] BYREF

  if ( n26 >= 26 )
    sprintf(Buffer, "%s_%c", unk_193C0F0 + 636, n26 + 71);
  else
    sprintf(Buffer, "%s%c", unk_193C0F0 + 636, n26 + 97);
  sprintf(Buffer_1, "host:%s/2d/tex/%s/%spos.tm2", (const char *)(unk_193C0F0 + 372), Buffer, Buffer);
  i = (int *)sub_923B40();
  if ( sub_923800(i, (int)Buffer_1) )
  {
    result = sub_923660(i, a2, a3, a4, a5);
    if ( (*(_BYTE *)a2 & 1) != 0 || (*(_BYTE *)a4 & 1) != 0 )
    {
      nullsub_171("Error in %s, line %d: ", "..\\program\\src\\rcBg\\rcbgLoadText.c", 393);
      result = nullsub_171("Anime size,pos error!! w:%d x:%d", *a4, *a2);
    }
    if ( i )
      return sub_923450(i);
  }
  else
  {
    if ( i )
      sub_923450(i);
    nullsub_171("Error in %s, line %d: ", "..\\program\\src\\rcBg\\rcbgLoadText.c", 384);
    return nullsub_171("Anime pos file not found.");
  }
  return result;
}
